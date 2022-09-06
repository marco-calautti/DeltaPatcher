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
