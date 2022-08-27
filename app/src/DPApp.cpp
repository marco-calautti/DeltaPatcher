#include <wx/stdpaths.h>
#include <patcher/XDeltaPatch.h>
#include <wx/filename.h>
#include <DPApp.h>
#include <gui/DeltaPatcherMainDialog.h>
#include <common/resource.h>

#ifdef __WXMSW__
#include <windows.h>
#endif

IMPLEMENT_APP(DPApp)

bool DPApp::OnInit(){

	if(!wxApp::OnInit())
		return false;
		
	if(locale.Init()){
#ifdef __WXMSW__
		wxString path;
		wxString exePath=wxStandardPaths::Get().GetExecutablePath();
		wxFileName fn(exePath);
		wxString dir=fn.GetPath();
		path << dir << wxFILE_SEP_PATH << wxT("resources");
		locale.AddCatalogLookupPathPrefix(path);
		
#elif defined(__WXGTK__)
        	// add locale search paths
        	locale.AddCatalogLookupPathPrefix(wxT("/usr/share/deltapatcher"));
        	locale.AddCatalogLookupPathPrefix(wxT("/usr/local/share/deltapatcher"));
        	wxStandardPaths* paths = (wxStandardPaths*) &wxStandardPaths::Get();
        	wxString prefix = paths->GetInstallPrefix();
        	locale.AddCatalogLookupPathPrefix( prefix );
#endif

		locale.AddCatalog(wxT("deltapatcher"));
	}
	
#ifdef __WXMSW__
	
	//Here we use the embedded xdelta executable
	HGLOBAL     res_handle = NULL;
	HRSRC       res;
	char *      res_data;
	DWORD       res_size;
	
	res = FindResource(GetModuleHandle(NULL),L"IDR_xdeltaexe",L"exe");
	if (!res)
        return false;
	res_handle = LoadResource(NULL, res);
	if (!res_handle)
        return false;
		
	res_data = (char*)LockResource(res_handle);
	res_size = SizeofResource(NULL, res);
	
	wxFile tempFile;
	wxString tempDir=wxStandardPaths::Get().GetTempDir();
	wxFileName fn(tempDir,wxT("dp_xdelta"));
	
	wxString fullPath=fn.GetFullPath();
	tempFile.Open(fullPath,wxFile::write);
	
	tempFile.Write(res_data,res_size);
	tempFile.Close();
	
	XDeltaPatch::SetXDeltaExecutable(fullPath);
#else
	XDeltaPatch::SetXDeltaExecutable(wxT("xdelta3"));
#endif

	DeltaPatcherMainDialog* dialog=new DeltaPatcherMainDialog(NULL,patchName);
	
	SetTopWindow(dialog);
	
	dialog->Show();
	
	return true;
}

bool DPApp::OnCmdLineParsed(wxCmdLineParser& parser)
{
	if(parser.GetParamCount()==1){
		wxString param=parser.GetParam(0);
		wxFileName fn(param);
		if(fn.GetExt().CmpNoCase(wxT("xdelta"))==0)
			patchName=param;
	}
	
	return true;
}

void DPApp::OnInitCmdLine(wxCmdLineParser& parser)
{
	parser.SetDesc(cmdLineDesc);
	
}


