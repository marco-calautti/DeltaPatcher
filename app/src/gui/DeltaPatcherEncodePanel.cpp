#include <wx/filename.h>
#include <wx/filedlg.h>
#include <gui/DeltaPatcherEncodePanel.h>
#include <gui/DeltaPatcherDropHandler.h>
#include <gui/DeltaPatcherDropTarget.h>

#include <gui/icons/open.xpm>
#include <gui/icons/save.xpm>
#include <gui/icons/config.xpm>

class EncodePanelDropHandler : public DeltaPatcherDropHandler
{
private:
	DeltaPatcherEncodePanel* panel;
	bool original;
public:
	EncodePanelDropHandler(DeltaPatcherEncodePanel* encodePanel, bool dropOnOriginal) :
		panel(encodePanel), original(dropOnOriginal)
	{
	}

	virtual bool HandleFileDrop(const wxArrayString& filenames)
	{
		if (filenames.GetCount()>1) return false;
		wxString file = filenames[0];

		if (original)
			panel->SetOriginalFile(file);
		else
			panel->SetModifiedFile(file);

		return true;
	}
};

DeltaPatcherEncodePanel::DeltaPatcherEncodePanel( wxWindow* parent, Logger* l )
:
EncodePanel( parent ), logger( l )
{
	Bind(wxEVT_THREAD, &DeltaPatcherEncodePanel::OnThreadUpdate, this);

	EncodePanelDropHandler* originalDropHandler = new EncodePanelDropHandler(this, true);
	EncodePanelDropHandler* modifiedDropHandler = new EncodePanelDropHandler(this, false);
	originalField->SetDropTarget(new DeltaPatcherDropTarget(originalDropHandler));
	modifiedField->SetDropTarget(new DeltaPatcherDropTarget(modifiedDropHandler));

	wxBitmap openBitmap;
	openBitmap.CopyFromIcon(wxIcon(open_xpm));
	originalButton->SetBitmap(openBitmap);
	modifiedButton->SetBitmap(openBitmap);
	
	wxBitmap saveBitmap;
	saveBitmap.CopyFromIcon(wxIcon(save_xpm));
	patchButton->SetBitmap(saveBitmap);
	
	wxBitmap configBitmap;
	configBitmap.CopyFromIcon(wxIcon(config_xpm));
	encodeOptionsButton->SetBitmap(configBitmap);
	
	createOptionsMenu = new wxMenu();
	compressionMenu = new wxMenu();
	for(int level=XDeltaConfig::MIN_COMPRESSION_LEVEL;level<=XDeltaConfig::MAX_COMPRESSION_LEVEL;level++){
		wxMenuItem* levelItem=new wxMenuItem(compressionMenu,wxID_ANY,wxString::Format("%d",level),wxEmptyString,wxITEM_RADIO);
		compressionMenu->Append(levelItem);
		if(level==XDeltaConfig::DEFAULT_COMPRESSION_LEVEL)
			levelItem->Check();
	}
	
	createOptionsMenu->Append( -1, _("Main compression level"), compressionMenu );

	secondaryCompressionMenu = new wxMenu();
	for (int i = 0; i < XDeltaConfig::SECONDARY_COMP_LENGTH;i++) {
		wxMenuItem* levelItem = new wxMenuItem(secondaryCompressionMenu, wxID_ANY, XDeltaConfig::SecondaryCompressions[i], wxEmptyString, wxITEM_RADIO);
		secondaryCompressionMenu->Append(levelItem);
		if (i == XDeltaConfig::DEFAULT_SECONDARY_COMPRESSION)
			levelItem->Check();
	}

	createOptionsMenu->Append(-1, _("Secondary compression"), secondaryCompressionMenu);

	windowSizeMenu = new wxMenu();
	wxMenuItem* windowItem=new wxMenuItem(windowSizeMenu,wxID_ANY,_T("Auto"),wxEmptyString,wxITEM_RADIO);
	windowSizeMenu->Append(windowItem);
	windowItem->Check();
	
	for(int i=0;i<XDeltaConfig::SRC_WINDOW_SIZE_LENGTH;i++){
		windowItem=new wxMenuItem(windowSizeMenu,wxID_ANY,wxString::Format("%d MB",XDeltaConfig::SrcWindowSizes[i]>>20),wxEmptyString,wxITEM_RADIO);
		windowSizeMenu->Append(windowItem);
	}
	
	createOptionsMenu->Append( -1, _("Src Window Size"), windowSizeMenu );
	
	checksumCheck = new wxMenuItem( createOptionsMenu, wxID_ANY, wxString( _("Add Checksum to patch") ) , wxEmptyString, wxITEM_CHECK );
	createOptionsMenu->Append( checksumCheck );
	checksumCheck->Check( true );
}

void DeltaPatcherEncodePanel::OnEncodeOptionsClicked(wxCommandEvent& event)
{
	PopupMenu(createOptionsMenu);
}

void DeltaPatcherEncodePanel::OnOpenOriginal( wxCommandEvent& event )
{
	wxFileDialog* dlg=new wxFileDialog(this);
	int ret=dlg->ShowModal();
	
	if(ret!=wxID_OK)
		return;
		
	wxString filePath=dlg->GetPath();
	
	SetOriginalFile(filePath);
}

void DeltaPatcherEncodePanel::OnOpenModified( wxCommandEvent& event )
{
	wxFileDialog* dlg=new wxFileDialog(this);
	int ret=dlg->ShowModal();
	
	if(ret!=wxID_OK)
		return;
		
	wxString filePath=dlg->GetPath();
	
	SetModifiedFile(filePath);
}

void DeltaPatcherEncodePanel::OnSavePatch( wxCommandEvent& event )
{
	wxFileDialog* dlg=new wxFileDialog(this,
									   wxEmptyString,
									   wxEmptyString,
									   wxEmptyString,
									   _("xdelta patches (*.xdelta)|*.xdelta"),
									   wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	int ret=dlg->ShowModal();
	
	if(ret!=wxID_OK)
		return;
		
	wxString filePath=dlg->GetPath();
	
	SetPatchFile(filePath);
}

void DeltaPatcherEncodePanel::OnCreatePatch( wxCommandEvent& event )
{
	if(patchField->IsEmpty()||originalField->IsEmpty()||modifiedField->IsEmpty()){
		wxMessageBox(_("Fill all the textboxes first!"),_("Warning"),wxICON_EXCLAMATION,this);
		return;
	}
	
	wxString patchName=patchField->GetValue();
	wxString original=originalField->GetValue();
	wxString modified=modifiedField->GetValue();
	
	XDeltaPatch xdp(patchName,XDeltaPatch::Write);
	xdp.SetDescription(descriptionField->GetValue());
	
	//preparing config
	xdp.GetConfig().enableChecksum=checksumCheck->IsChecked();
	xdp.GetConfig().compressionLevel=GetCompressionLevel();
	xdp.GetConfig().secondaryCompression = GetSecondaryCompression();
	xdp.GetConfig().srcWindowSize=GetWindowSize();
	//end config
	
	logger->Log(Logger::LOG_MESSAGE,_("Creating patch, please wait... (don't panic!)"));
	
	threadOriginal = original;
	threadModified = modified;
	threadXDP = xdp;

	GetParent()->Disable();
	StartCreatePatch();
	
}

void DeltaPatcherEncodePanel::SetPatchFile(const wxChar* patchPath)
{
	patchField->SetValue(patchPath);
	
	wxFileName fn(patchPath);
	wxString name=fn.GetFullName();
	wxString message;
	message=wxString::Format(_("Patch file \"%s\" selected."),name.GetData());
	
	logger->Log(Logger::LOG_MESSAGE,message);
}

void DeltaPatcherEncodePanel::SetOriginalFile(const wxChar* filePath)
{
	originalField->SetValue(filePath);
	
	wxFileName fn(filePath);
	wxString name=fn.GetFullName();
	wxString message;
	message=wxString::Format(_("Original file \"%s\" selected."),name.GetData());
	
	logger->Log(Logger::LOG_MESSAGE,message);	
}

void DeltaPatcherEncodePanel::SetModifiedFile(const wxChar* filePath)
{
	modifiedField->SetValue(filePath);
	
	wxFileName fn(filePath);
	wxString name=fn.GetFullName();
	wxString message;
	message=wxString::Format(_("Modified file \"%s\" selected."),name.GetData());
	
	logger->Log(Logger::LOG_MESSAGE,message);	
}

int DeltaPatcherEncodePanel::GetCompressionLevel()
{
	for(size_t i=0;i<compressionMenu->GetMenuItemCount();i++){
		wxMenuItem* item=compressionMenu->FindItemByPosition(i);
		if(item->IsChecked())
			return i;
	}
	return XDeltaConfig::DEFAULT_COMPRESSION_LEVEL;
}

int DeltaPatcherEncodePanel::GetSecondaryCompression()
{
	for (size_t i = 0; i < secondaryCompressionMenu->GetMenuItemCount(); i++) {
		wxMenuItem* item = secondaryCompressionMenu->FindItemByPosition(i);
		if (item->IsChecked())
			return i;
	}
	return XDeltaConfig::DEFAULT_SECONDARY_COMPRESSION;
}

int DeltaPatcherEncodePanel::GetWindowSize()
{
	for(size_t i=0;i<windowSizeMenu->GetMenuItemCount();i++){
		wxMenuItem* item=windowSizeMenu->FindItemByPosition(i);
		if(item->IsChecked())
		{
			if(i==0)
				return XDeltaConfig::SRC_WINDOW_SIZE_AUTO;
			else
				return XDeltaConfig::SrcWindowSizes[i-1];
		}
			
	}
	return XDeltaConfig::SRC_WINDOW_SIZE_AUTO;
}

void DeltaPatcherEncodePanel::StartCreatePatch()
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

void DeltaPatcherEncodePanel::OnThreadUpdate(wxThreadEvent& evt)
{
	GetParent()->Enable();

	int code = evt.GetInt();
	wxString message = evt.GetString();

	if(code!=0){
		logger->Log(Logger::LOG_ERROR,message);
		wxMessageBox(_("An error has occurred!\nSee log for more information."),_("Warning"),wxICON_EXCLAMATION,this);
	}else{
		logger->Log(Logger::LOG_MESSAGE,_("Patch successfully created!"));
		wxMessageBox(_("Patch successfully created!"),_("Notice"),wxICON_INFORMATION,this);
	}
}

wxThread::ExitCode DeltaPatcherEncodePanel::Entry()
{
	wxString message;

	int code=threadXDP.Encode(threadOriginal,threadModified,message);
	
	wxThreadEvent* evt = new wxThreadEvent();
	evt->SetString(message);
	evt->SetInt(code);
	wxQueueEvent(GetEventHandler(), evt);

	return (wxThread::ExitCode)0;
}