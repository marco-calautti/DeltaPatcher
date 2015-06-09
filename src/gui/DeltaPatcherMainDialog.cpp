#include <wx/filename.h>
#include <wx/datetime.h>
#include <wx/aboutdlg.h>
#include "DeltaPatcherMainDialog.h"
#include "DeltaPatcherAboutDialog.h"
#include <common/common.h>

#include <gui/icons/icon.xpm>
#include <gui/icons/about_button.xpm>
#include <gui/icons/switch.xpm>
#include <gui/icons/log.xpm>

#ifdef __WXMSW__
#include <wx/msw/registry.h>
#include <wx/stdpaths.h>
#endif

DeltaPatcherMainDialog::DeltaPatcherMainDialog( wxWindow* parent, const wxChar* patchName )
:
MainDialog( parent ), decodeMode(true)
{
	wxIcon icon(icon_xpm);
	SetIcon(icon);
	
	wxBitmap aboutBitmap;
	aboutBitmap.CopyFromIcon(wxIcon(about_button_xpm));
	aboutButton->SetImageLabel(aboutBitmap);
	
	wxBitmap modeBitmap;
	modeBitmap.CopyFromIcon(wxIcon(switch_xpm));
	operationButton->SetImageLabel(modeBitmap);
	
	wxBitmap logBitmap;
	logBitmap.CopyFromIcon(wxIcon(log_xpm));
	showHideLog->SetImageLabel(logBitmap);
	
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
	
	//checking release type
#ifdef __DP_DECODE_ONLY__
	operationButton->Show(false);
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


void DeltaPatcherMainDialog::OnOperationSelected( wxCommandEvent& event )
{
	
	if(decodeMode){ //create patch selected
		decodePanel->Show(false);
		encodePanel->Show();
		decodeMode=false;
	}else{ //apply patch selected
		encodePanel->Show(false);
		decodePanel->Show();
		decodeMode=true;
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





