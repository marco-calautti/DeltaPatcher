#include <patcher/XDeltaPatch.h>
#include <wx/utils.h>
#include <wx/arrstr.h>
#include <wx/file.h>

#include <vector>
#include <sstream>
#include <iostream>

#include <utils/base64.h>
#include <xdelta3_wrapper.h>

static size_t DecodeVarLength(wxFile& file)
{
	size_t length = 0;
	wxUint8 byte = 0;
	do
	{
		length <<= 7;
		file.Read((void*)&byte, 1);
		length |= byte & 0x7F;
	} while (byte & 0x80);

	return length;
}

static std::string native_path(const wxString& path){
	#ifdef __WXMSW__
		return path.ToStdString();
	#else
		return path.utf8_string();
	#endif 
}

static std::vector<std::string> SplitMessageByLine(const std::string& str)
{
    std::vector<std::string> tokens;
 
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, '\n')) {
        tokens.push_back(token);
    }
 
    return tokens;
}

const int XDeltaConfig::SrcWindowSizes[]={8<<20,	//8 MB, etc...
											16<<20,
											32<<20,
											64<<20,
											128<<20,
											256<<20,
											512<<20,
											1024<<20};
											
const char* XDeltaConfig::SecondaryCompressions[] = {
														"lzma",
														"djw",
														"fgk",
														"none"
};

XDeltaPatch::XDeltaPatch(const wxChar* input, PatchMode mode)
{
	if(!input)
		return;
		
	patchName=input;
	
	if(mode!=Read)
		return;
		
	DecodeDescription();
}

void XDeltaPatch::DecodeDescription()
{
	wxFile file;
	
	if(!file.Open(patchName))
		return;
	
	wxUint8 magic[3];

	file.Read(magic, 3);

	if (magic[0] != 0xD6 || magic[1] != 0xC3 || magic[2] != 0xC4) 
	{
		return;
	}
	
	wxUint8 version = 0;
	file.Read((void*)&version, 1);

	if (version != 0)
		return;

	//read flags
	wxUint8 flags = 0;
	file.Read((void*)&flags, 1);

	//No app data present at all
	if (!(flags & 0x04))
	{
		return;
	}

	// Secondary compression enabled
	if (flags & 0x01)
	{
		//Skip compression type byte
		file.Seek(1, wxFromCurrent);
	}

	//Code table data present (xdelta should never write this data in patches)
	if (flags & 0x02)
	{
		//Get length of code table
		size_t length = DecodeVarLength(file);
		
		//Skip code table
		file.Seek(length, wxFromCurrent);
	}
	
	//We read the length of the app data
	size_t length = DecodeVarLength(file);
	
	if(length<2)
		return;
	
	char* temp=new char[length+1];

	file.Read((void*)temp,length);
	temp[length]=0;
	
	if (temp[0] != '^' || temp[1] != '*') {
                delete[] temp;
		return;
	}

	wxString tempDesc=wxString::FromUTF8((const char*)temp);
	
	delete[] temp;
	
	wxString part=tempDesc.Mid(2);
	
	std::string strPart=std::string(part.mb_str());
	
	std::string buf=base64_decode(strPart);
	
	description=wxString::FromUTF8(buf.c_str(),buf.length());

	//Uniform new lines to \n
	description.Replace("\r\n","\n");
	description.Replace("\r","\n");

	//On Windows, use \r\n
#if defined(__WXMSW__)
	description.Replace("\n","\r\n");
#endif
}

wxString XDeltaPatch::EncodeDescription()
{
	wxString result;
	if(description.IsEmpty())
		result=wxT("Created with Delta Patcher.");
	else
	{
		wxScopedCharBuffer utf8=description.ToUTF8();
				
		result=wxT("^*");
		result<<base64_encode((unsigned const char*)utf8.data(),strlen(utf8.data()));
	}
	return result;
}

wxString XDeltaPatch::GetDescription()
{
	return description;
}

void XDeltaPatch::SetDescription(const wxString& description)
{
	this->description=description;
}

int XDeltaPatch::Process(const wxString& original,const wxString& out,const wxString& patch,wxString& message,bool encode)
{
	
	std::vector<std::string> params=MakeCommand(original,out,patch,encode);

	//running xdelta with parameters
	int ret = xd3_main_exec(params);
	std::string messages = xd3_messages();
	std::vector<std::string> outArray = SplitMessageByLine(messages);

	if(outArray.size()>0) //got some message
		message=outArray[0];
		
	return ret;
}

int XDeltaPatch::Decode(const wxChar* original,const wxChar*out, wxString& message)
{

	return Process(original,out,patchName,message,false);
}

int XDeltaPatch::Encode(const wxChar* original,const wxChar* modified,wxString& message)
{
		
	return Process(original,modified,patchName,message,true);
}

std::vector<std::string> XDeltaPatch::MakeCommand(const wxString& original,const wxString& out,const wxString& patch,bool encode)
{
	std::vector<std::string> params;
	
	if(encode){
		params.push_back("-e");
	}else{
		params.push_back("-d");
	}

	//preparing configuration flags
	if(!config.enableChecksum)
		params.push_back("-n");
	
	if(config.overwriteOutput)
		params.push_back("-f");

	if(encode){
		std::string compression_flag = "-";
		compression_flag+=std::to_string(config.compressionLevel);
		params.push_back(compression_flag);
		
		params.push_back("-S");
		params.push_back(XDeltaConfig::SecondaryCompressions[config.secondaryCompression]);
		
		if(config.srcWindowSize!=XDeltaConfig::SRC_WINDOW_SIZE_AUTO){
			params.push_back("-B");
			params.push_back(std::to_string(config.srcWindowSize));
		}

		wxString base64=EncodeDescription();
		
		std::string desc_str = "-A=";
		desc_str+=base64.ToAscii();
		params.push_back(desc_str);
	}
	//end of configuration flags

	params.push_back("-s");
	params.push_back(native_path(original));
	
	if(encode){
		params.push_back(native_path(out));
		params.push_back(native_path(patch));
	}else{
		params.push_back(native_path(patch));
		params.push_back(native_path(out));
	}

	return params;
}

void XDeltaPatch::SetConfig(const XDeltaConfig& config)
{
	this->config=config;
}

XDeltaConfig& XDeltaPatch::GetConfig()
{
	return config;
}
