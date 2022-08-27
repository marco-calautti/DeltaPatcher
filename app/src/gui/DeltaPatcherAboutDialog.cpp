#include <gui/DeltaPatcherAboutDialog.h>
#include <gui/icons/about.xpm>
#include <common/common.h>

DeltaPatcherAboutDialog::DeltaPatcherAboutDialog( wxWindow* parent )
:
AboutDialog( parent )
{
	wxImage img(about_xpm);
	wxBitmap logo(img);
	aboutLogo->SetBitmap(logo);
	
	wxString name=wxString::Format(wxT("%s %s"),__DP_NAME__,__DP_VERSION__);
	nameAndVerText->SetLabel(name);
	
	copyrightText->SetLabel(__DP_COPYRIGHT__);
	siteText->SetLabel(__DP_WEBSITE__);
	siteText->SetURL(__DP_WEBSITE__);
	
	disclaimerText->SetLabel(__DP_DISCLAIMER__);
	licenseText->SetEditable(false);
	licenseText->SetValue(__DP_LICENSE__);
	
	Fit();
}

void DeltaPatcherAboutDialog::OnClickClose( wxCloseEvent& event )
{
	Destroy();
}

void DeltaPatcherAboutDialog::OnClickOk( wxCommandEvent& event )
{
	Destroy();
}
