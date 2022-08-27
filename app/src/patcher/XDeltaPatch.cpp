#include <patcher/XDeltaPatch.h>
#include <wx/utils.h>
#include <wx/arrstr.h>
#include <wx/file.h>

#include <utils/base64.h>

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

wxString XDeltaPatch::xdeltaEx=wxT("xdelta");
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
	
	if (temp[0] != '^' || temp[1] != '*')
		return;

	wxString tempDesc=wxString::FromUTF8((const char*)temp);
	
	delete[] temp;
	
	wxString part=tempDesc.Mid(2);
	
	std::string strPart=std::string(part.mb_str());
	
	std::string buf=base64_decode(strPart);
	
	description=wxString::FromUTF8(buf.c_str(),buf.length());
	
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
	wxString command;
	wxArrayString outArray,errorArray;
	command=MakeCommand(original,out,patch,encode);

	//running xdelta with parameters
	long exitcode=wxExecute(command, outArray,errorArray);
	if(errorArray.Count()>0) //got an error
		message=errorArray[0];
	else if(outArray.Count()>0) //got some message
		message=outArray[0];
		
	return exitcode;
}

int XDeltaPatch::Decode(const wxChar* original,const wxChar*out, wxString& message)
{

	return Process(original,out,patchName,message,false);
}

int XDeltaPatch::Encode(const wxChar* original,const wxChar* modified,wxString& message)
{
		
	return Process(original,modified,patchName,message,true);
}

wxString XDeltaPatch::MakeCommand(const wxString& original,const wxString& out,const wxString& patch,bool encode)
{
	wxString command;
	
	//preparing configuration flags
	wxString checksum_flag=config.enableChecksum? wxT(" ") : wxT("-n ");
	wxString overwrite_flag=config.overwriteOutput? wxT("-f ") : wxT(" ");
	wxString compression_flag;
	wxString secondary_compression_flag;
	wxString src_window_flag;
	wxString desc_flag;
	
	if(encode){
		wxString strLvl=wxString::Format(wxT("%i"),config.compressionLevel);
		compression_flag<<wxT("-")<<strLvl<<wxT(" ");
		
		secondary_compression_flag << wxT("-S ") << XDeltaConfig::SecondaryCompressions[config.secondaryCompression] << wxT(" ");
		
		if(config.srcWindowSize!=XDeltaConfig::SRC_WINDOW_SIZE_AUTO)
			src_window_flag<<wxT("-B ")<<config.srcWindowSize<<wxT(" ");

		wxString base64=EncodeDescription();
		
		desc_flag<<wxT("-A=\"")<<base64.ToAscii()<<wxT("\" ");
		
	}
	//end of configuration flags
	
	//MAKING COMMAND
	if(encode)
		command<<xdeltaEx<<wxT(" -e ")<<compression_flag<<secondary_compression_flag<<desc_flag<<overwrite_flag<<checksum_flag<<wxT("-s ")<<wxT(" \"")<<original<<wxT("\" \"")<<out<<wxT("\" \"")<<patch<<wxT("\"");
	else
		command<<xdeltaEx<<wxT(" -d ")<<overwrite_flag<<checksum_flag<<wxT("-s ")<<wxT(" \"")<<original<<wxT("\" \"")<<patch<<wxT("\" \"")<<out<<wxT("\"");
	
	return command;
}

void XDeltaPatch::SetConfig(const XDeltaConfig& config)
{
	this->config=config;
}

XDeltaConfig& XDeltaPatch::GetConfig()
{
	return config;
}
