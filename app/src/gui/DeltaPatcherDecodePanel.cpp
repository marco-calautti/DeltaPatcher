#include <gui/DeltaPatcherDropTarget.h>
#include <wx/filename.h>
#include <gui/DeltaPatcherDecodePanel.h>
#include <wx/filedlg.h>

#include <gui/icons/open.xpm>
#include <gui/icons/save.xpm>
#include <gui/icons/config.xpm>

DeltaPatcherDecodePanel::DeltaPatcherDecodePanel( wxWindow* parent,Logger* l )
:
DecodePanel( parent ), logger( l )
{
	Bind(wxEVT_THREAD, &DeltaPatcherDecodePanel::OnThreadUpdate, this);

	SetDropTarget(new DeltaPatcherDropTarget(this));
	
	wxBitmap openBitmap;
	openBitmap.CopyFromIcon(wxIcon(open_xpm));
	originalButton->SetBitmap(openBitmap);
	patchButton->SetBitmap(openBitmap);
	
	wxBitmap configBitmap;
	configBitmap.CopyFromIcon(wxIcon(config_xpm));
	decodeOptionsButton->SetBitmap(configBitmap);
	
	applyOptionsMenu = new wxMenu();
	keepOriginalCheck = new wxMenuItem( applyOptionsMenu, wxID_ANY, wxString( _("Backup original file") ) , wxEmptyString, wxITEM_CHECK );
	applyOptionsMenu->Append( keepOriginalCheck );
	
	checksumCheck = new wxMenuItem( applyOptionsMenu, wxID_ANY, wxString( _("Checksum validation") ) , wxEmptyString, wxITEM_CHECK );
	applyOptionsMenu->Append( checksumCheck );
	checksumCheck->Check( true );
	
}

void DeltaPatcherDecodePanel::OnDecodeOptionsClicked(wxCommandEvent& event)
{
	PopupMenu(applyOptionsMenu);
}

void DeltaPatcherDecodePanel::OnOpenOriginal( wxCommandEvent& event )
{
	wxFileDialog* dlg=new wxFileDialog(this);
	int ret=dlg->ShowModal();
	
	if(ret!=wxID_OK)
		return;
		
	wxString filePath=dlg->GetPath();
	
	SetOriginalFile(filePath);
}

void DeltaPatcherDecodePanel::OnOpenPatch( wxCommandEvent& event )
{
	wxFileDialog* dlg=new wxFileDialog(this);
	dlg->SetWildcard(_("xdelta patches (*.xdelta)|*.xdelta"));
	
	int ret=dlg->ShowModal();
	
	if(ret!=wxID_OK)
		return;
		
	wxString patchPath=dlg->GetPath();
	
	SetPatchFile(patchPath);
}

void DeltaPatcherDecodePanel::OnApplyPatch( wxCommandEvent& event )
{
	if(patchField->IsEmpty()||originalField->IsEmpty()){
		wxMessageBox(_("Fill all the textboxes first!"),_("Warning"),wxICON_EXCLAMATION,this);
		return;
	}
	
	wxString patchName=patchField->GetValue();
	wxString original=originalField->GetValue();
	
	XDeltaPatch xdp(patchName);
	
	//preparing config
	xdp.GetConfig().enableChecksum=checksumCheck->IsChecked();
	//end config
	
	wxString newFilename=originalField->GetValue();
	
	wxFileName fn(newFilename);
	
	wxString path=fn.GetPath();
	wxString ext=fn.GetExt();
	wxString name=fn.GetName();
	wxString outFilename;
	outFilename<<path<<wxFILE_SEP_PATH<<name<<wxT("PATCHED")<<wxT(".")<<ext;
	
	logger->Log(Logger::LOG_MESSAGE,_("Applying patch, please wait... (don't panic!)"));
	
	threadOriginal = original;
	threadModified = outFilename;
	threadXDP = xdp;

	GetParent()->Disable();
	StartApplyPatch();
}

void DeltaPatcherDecodePanel::SetPatchFile(const wxChar* patchPath)
{
	patchField->SetValue(patchPath);
	
	wxFileName fn(patchPath);
	wxString name=fn.GetFullName();
	wxString message;
	
	XDeltaPatch xdp(patchPath);
	
	message=wxString::Format(_("Patch file \"%s\" selected"),name.GetData());
	if(xdp.GetDescription().IsEmpty())
	{
		message<<wxT(".");
	}else
	{
		message<<wxString::Format(_(", description found:\n\n%s\n"),xdp.GetDescription());
	}
	
	logger->Log(Logger::LOG_MESSAGE,message);
}

void DeltaPatcherDecodePanel::SetOriginalFile(const wxChar* filePath)
{
	originalField->SetValue(filePath);
	
	wxFileName fn(filePath);
	wxString name=fn.GetFullName();
	wxString message;
	message=wxString::Format(_("Original file \"%s\" selected."),name.GetData());
	
	logger->Log(Logger::LOG_MESSAGE,message);	
}

bool DeltaPatcherDecodePanel::HandleFileDrop(const wxArrayString& filenames)
{
	
	if(filenames.GetCount()>1) return false;
	wxString file=filenames[0];
	wxFileName fn(file);
	
	if(fn.GetExt().CmpNoCase(wxT("xdelta"))==0) //got xdelta patch
		SetPatchFile(file);
	else
		SetOriginalFile(file);
	
	return true;
}

void DeltaPatcherDecodePanel::StartApplyPatch()
{
    if (CreateThread(wxTHREAD_JOINABLE) != wxTHREAD_NO_ERROR)
    {
		logger->Log(Logger::LOG_ERROR,_("Could not create the worker thread!"));
        return;
    }
 
    // go!
    if (GetThread()->Run() != wxTHREAD_NO_ERROR)
    {
		logger->Log(Logger::LOG_ERROR,_("Could not RUN the worker thread!"));
        return;
    }
}

void DeltaPatcherDecodePanel::OnThreadUpdate(wxThreadEvent& evt)
{
	GetParent()->Enable();
	
	int code = evt.GetInt();
	wxString message = evt.GetString();

	if(code!=0){
		logger->Log(Logger::LOG_ERROR,message);
		wxMessageBox(_("An error has occurred!\nSee log for more information."),_("Warning"),wxICON_EXCLAMATION,this);
	}else{
		if(!keepOriginalCheck->IsChecked()){ //we must not keep the original file
			wxRemoveFile(threadOriginal);
			wxRenameFile(threadModified,threadOriginal);
		}
		logger->Log(Logger::LOG_MESSAGE,_("Patch successfully applied!"));
		wxMessageBox(_("Patch successfully applied!"),_("Notice"),wxICON_INFORMATION,this);
	}
}

wxThread::ExitCode DeltaPatcherDecodePanel::Entry()
{
	
	wxString message;
	int code=threadXDP.Decode(threadOriginal,threadModified,message);
	
	wxThreadEvent* evt = new wxThreadEvent();
	evt->SetString(message);
	evt->SetInt(code);
	wxQueueEvent(GetEventHandler(), evt);

	return (wxThread::ExitCode)0;
}

	
	
