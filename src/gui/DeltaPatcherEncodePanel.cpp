#include <patcher/XDeltaPatch.h>
#include <wx/filename.h>
#include <wx/filedlg.h>
#include "DeltaPatcherEncodePanel.h"

DeltaPatcherEncodePanel::DeltaPatcherEncodePanel( wxWindow* parent, Logger* l )
:
EncodePanel( parent )
{
	logger=l;
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
	
	XDeltaPatch xdp(patchName);
	
	//preparing config
	xdp.GetConfig().enableChecksum=checksumCheck->IsChecked();
	xdp.GetConfig().compressionLevel=choiceCompression->GetSelection();
	//end config
	
	logger->Log(Logger::LOG_MESSAGE,_("Creating patch, please wait... (don't panic!)"));
	
	wxString message;
	int code=xdp.Encode(original,modified,message);
	
	if(code!=0){
		logger->Log(Logger::LOG_ERROR,message);
		wxMessageBox(_("An error has occurred!\nSee log for more information."),_("Warning"),wxICON_EXCLAMATION,this);
	}else{
		logger->Log(Logger::LOG_MESSAGE,_("Patch successfully created!"));
		wxMessageBox(_("Patch successfully created!"),_("Notice"),wxICON_INFORMATION,this);
	}
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
