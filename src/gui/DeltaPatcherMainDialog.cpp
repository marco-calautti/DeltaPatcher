#include <wx/filename.h>
#include <wx/datetime.h>
#include <wx/aboutdlg.h>
#include "DeltaPatcherMainDialog.h"
#include "DeltaPatcherAboutDialog.h"
#include <common/common.h>
#include "icon.xpm"

#ifdef __WXMSW__
#include <wx/msw/registry.h>
#include <wx/stdpaths.h>
#endif

DeltaPatcherMainDialog::DeltaPatcherMainDialog( wxWindow* parent, const wxChar* patchName )
:
MainDialog( parent )
{
	wxIcon icon(icon_xpm);
	SetIcon(icon);
	
#ifdef __DP_DECODE_ONLY__
	SetTitle(_("Delta Patcher Lite"));
#else
	SetTitle(_("Delta Patcher"));
#endif
	//preparing default panel
	decodePanel=new DeltaPatcherDecodePanel(this,this);
	if(!wxIsEmpty(patchName))
		decodePanel->SetPatchFile(patchName);
		
	nullPanel->Show(false);
	panelSizer->Add( decodePanel, 1, wxEXPAND | wxALL, 5 );
	decodePanel->Show();
	
	//preparing encode panel
	encodePanel=new DeltaPatcherEncodePanel(this,this);
	panelSizer->Add( encodePanel, 1, wxEXPAND | wxALL, 5 );
	encodePanel->Show(false);
	
	//preparing log area
	logCtrl->SetEditable(false);
	
	//checking file association support
#ifndef __WXMSW__
	associateCheck->Enable(false);
#endif

	associateCheck->SetValue(ExistKeys());
	//checking release type
#ifdef __DP_DECODE_ONLY__
	operationBox->Show(false);
#endif
	
	this->Fit();
}

void DeltaPatcherMainDialog::OnShowHideLog( wxCommandEvent& event )
{
	if(mainSizer->Detach(logBox)){ //hide log
		logBox->GetStaticBox()->Show(false);
		logCtrl->Show(false);
		showHideLog->SetLabel(_("Show log >>"));
	}else{ //show log
		mainSizer->Add( logBox, 1, wxEXPAND|wxALL, 5 );
		logBox->GetStaticBox()->Show();
		logCtrl->Show();
		showHideLog->SetLabel(_("<< Hide log"));
	}
	
	Update();
	Fit();
}

void DeltaPatcherMainDialog::OnMainDialogClose( wxCloseEvent& event )
{
	Destroy();
}

void DeltaPatcherMainDialog::OnMainDialogCloseButton( wxCommandEvent& event )
{
	Destroy();
}

void DeltaPatcherMainDialog::OnOperationSelected( wxCommandEvent& event )
{
	int selection=event.GetSelection();
	
	if(selection==1){ //create patch selected
		decodePanel->Show(false);
		encodePanel->Show();
	}else{ //apply patch selected
		encodePanel->Show(false);
		decodePanel->Show();
	}

	leftSizer->Layout();
	Fit();
		
}

void DeltaPatcherMainDialog::OnClickAbout( wxCommandEvent& event )
{
	/*
	wxAboutDialogInfo info;
	
	info.AddDeveloper(wxT("Phoenix (SadNES cITy Translations)"));
	info.SetLicense(__DP_LICENSE__);
	info.SetName(__DP_NAME__);
	info.SetVersion(__DP_VERSION__);
	info.SetWebSite(__DP_WEBSITE__);
	info.SetCopyright(__DP_COPYRIGHT__);
	
	wxAboutBox(info);*/
	
	DeltaPatcherAboutDialog* about=new DeltaPatcherAboutDialog(this);
	about->ShowModal();
}

void DeltaPatcherMainDialog::Log(int type,const wxChar* msg)
{
	wxDateTime now=wxDateTime::Now();
	wxString strTime=now.FormatTime();
	wxString message;
	if(type==Logger::LOG_MESSAGE)
		message=wxString::Format(wxT("[%s] %s\n"),strTime.GetData(),msg);
	else
		message=wxString::Format(_("[%s] An error has occurred: %s\n"),strTime.GetData(),msg);
	
	logCtrl->AppendText(message);
}

void DeltaPatcherMainDialog::OnAssociateXDelta( wxCommandEvent& event )
{
	if(event.IsChecked()) //want to associate xdelta files
		AddKeys();
	else
		DeleteKeys();

}

void DeltaPatcherMainDialog::AddKeys()
{
#ifdef __WXMSW__

	DeleteKeys();
	wxRegKey regExt(wxT("HKEY_CLASSES_ROOT\\.xdelta"));
		
	//creating registry keys
	regExt.Create();
	regExt.SetValue(wxEmptyString,wxT("xdeltafile"));
	regExt.Close();
		
	wxRegKey regIcon(wxT("HKEY_CLASSES_ROOT\\xdeltafile\\DefaultIcon"));
	regIcon.Create();
	
	wxString exePath=wxStandardPaths::Get().GetExecutablePath();
		
	regIcon.SetValue(wxEmptyString,exePath+wxT(",0"));
	regIcon.Close();
		
	wxRegKey regShell(wxT("HKEY_CLASSES_ROOT\\xdeltafile\\shell\\open\\command"));
	regShell.Create();
	regShell.SetValue(wxEmptyString,exePath+wxT(" \"%1\""));
	regShell.Close();
#endif
}

void DeltaPatcherMainDialog::DeleteKeys()
{
#ifdef __WXMSW__
	wxRegKey regExt(wxT("HKEY_CLASSES_ROOT\\.xdelta"));
	wxRegKey regAss(wxT("HKEY_CLASSES_ROOT\\xdeltafile"));
	
	if(regExt.Exists()) //cleaning registry
		regExt.DeleteSelf();
			
	if(regAss.Exists())
		regAss.DeleteSelf();
		
	regAss.Close();
	regExt.Close();
#endif
}

bool DeltaPatcherMainDialog::ExistKeys()
{
#ifdef __WXMSW__
	wxRegKey regAss(wxT("HKEY_CLASSES_ROOT\\xdeltafile"));
	
	bool ret=regAss.Exists();
	regAss.Close();
	
	return ret;
#endif
}




