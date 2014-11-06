#include "DeltaPatcherDropTarget.h"
#include <wx/filename.h>
#include "DeltaPatcherDecodePanel.h"
#include <wx/filedlg.h>
#include <patcher/XDeltaPatch.h>

DeltaPatcherDecodePanel::DeltaPatcherDecodePanel( wxWindow* parent,Logger* l )
:
DecodePanel( parent )
{
	logger=l;
	SetDropTarget(new DeltaPatcherDropTarget(this));
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
	outFilename<<path<<wxFILE_SEP_PATH<<name<<wxT("NEW")<<wxT(".")<<ext;
	
	logger->Log(Logger::LOG_MESSAGE,_("Applying patch, please wait... (don't panic!)"));
	
	wxString message;
	int code=xdp.Decode(original,outFilename,message);
	
	if(code!=0){
		logger->Log(Logger::LOG_ERROR,message);
		wxMessageBox(_("An error has occurred!\nSee log for more information."),_("Warning"),wxICON_EXCLAMATION,this);
	}else{
		if(!keepOriginalCheck->IsChecked()){ //we must not keep the original file
			wxRemoveFile(original);
			wxRenameFile(outFilename,original);
		}
		logger->Log(Logger::LOG_MESSAGE,_("Patch successfully applied!"));
		wxMessageBox(_("Patch successfully applied!"),_("Notice"),wxICON_INFORMATION,this);
	}
}

void DeltaPatcherDecodePanel::SetPatchFile(const wxChar* patchPath)
{
	patchField->SetValue(patchPath);
	
	wxFileName fn(patchPath);
	wxString name=fn.GetFullName();
	wxString message;
	message=wxString::Format(_("Patch file \"%s\" selected."),name.GetData());
	
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


