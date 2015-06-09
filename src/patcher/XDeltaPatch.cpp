#include <patcher/XDeltaPatch.h>
#include <wx/utils.h>
#include <wx/arrstr.h>
#include <wx/file.h>

#include <wx/base64.h>

wxString XDeltaPatch::xdeltaEx=wxT("xdelta");
const int XDeltaConfig::SrcWindowSizes[]={8<<20,	//8 MB, etc...
											16<<20,
											32<<20,
											64<<20,
											128<<20,
											256<<20,
											512<<20,
											1024<<20};
											
XDeltaPatch::XDeltaPatch(const wxChar* input,PatchMode mode)
{
	patchName=input;
	wxFile file;
	
	if(mode!=Read)
		return;
		
	if(!file.Open(patchName))
		return;
	
	wxUint8 byte;
	size_t length=0;
	
	file.Seek(5);
	do
	{
		length<<=7;
		file.Read((void*)&byte,1);
		length|=byte&0x7F;
	}while(byte&0x80);
		
	if(length==0)
		return;
		
	char* temp=new char[length+1];
	
	file.Read((void*)temp,length);
	temp[length]=0;
	
	wxString tempDesc=wxString::FromAscii((const char*)temp);
	
	if(!tempDesc.StartsWith(wxT("^*")))
		return;
	
	wxString part=tempDesc.Mid(2);
	
	size_t decodedSize=wxBase64DecodedSize(part.Length());
	char* buf=new char[decodedSize];
	
	wxBase64Decode(buf,decodedSize,part);
	description=wxString::FromUTF8(buf,decodedSize);
	
	delete[] temp;
	delete[] buf;
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
	wxString checksum_flag=config.enableChecksum? wxT(" ") : wxT(" -n ");
	wxString overwrite_flag=config.overwriteOutput? wxT(" -f ") : wxT(" ");
	wxString compression_flag;
	wxString src_window_flag;
	wxString desc_flag;
	
	if(encode){
		wxString strLvl=wxString::Format(wxT("%i"),config.compressionLevel);
		compression_flag<<wxT(" -")<<strLvl<<wxT(" ");
		
		if(config.srcWindowSize!=XDeltaConfig::SRC_WINDOW_SIZE_AUTO)
			src_window_flag<<wxT(" -B ")<<config.srcWindowSize<<wxT(" ");
		
		wxString tempDesc=description;
		
		if(tempDesc.IsEmpty())
			tempDesc=wxT("Created with Delta Patcher");
			

		wxScopedCharBuffer utf8=tempDesc.ToUTF8();
			
		wxString base64=wxBase64Encode(utf8.data(),strlen(utf8.data()));
		desc_flag<<wxT("-A=\"^*")<<base64.ToAscii()<<wxT("\" ");
		
	}
	//end of configuration flags
	
	//MAKING COMMAND
	if(encode)
		command<<xdeltaEx<<wxT(" -e")<<compression_flag<<src_window_flag<<desc_flag<<overwrite_flag<<checksum_flag<<wxT("-s ")<<wxT(" \"")<<original<<wxT("\" \"")<<out<<wxT("\" \"")<<patch<<wxT("\"");
	else
		command<<xdeltaEx<<wxT(" -d")<<overwrite_flag<<checksum_flag<<wxT("-s ")<<wxT(" \"")<<original<<wxT("\" \"")<<patch<<wxT("\" \"")<<out<<wxT("\"");
	
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
