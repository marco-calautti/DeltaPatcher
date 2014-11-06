#include <patcher/XDeltaPatch.h>
#include <wx/utils.h>
#include <wx/arrstr.h>

wxString XDeltaPatch::xdeltaEx=wxT("xdelta");

XDeltaPatch::XDeltaPatch(const wxChar* input)
{
	patchName=input;
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

	if(encode){
		wxString strLvl=wxString::Format(wxT("%i"),config.compressionLevel);
		compression_flag<<wxT(" -")<<strLvl<<wxT(" ");
	}
	//end of configuration flags
	
	//MAKING COMMAND
	if(encode)
		command<<xdeltaEx<<wxT(" -e")<<compression_flag<<overwrite_flag<<checksum_flag<<wxT("-s ")<<wxT(" \"")<<original<<wxT("\" \"")<<out<<wxT("\" \"")<<patch<<wxT("\"");
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
