#include <gui/dpgui.h>

BEGIN_EVENT_TABLE( MainDialog, wxDialog )
	EVT_ACTIVATE( MainDialog::_wxFB_OnActivate )
	EVT_CLOSE( MainDialog::_wxFB_OnMainDialogClose )
	EVT_SHOW( MainDialog::_wxFB_OnMainDialogShow )
	EVT_BUTTON( wxID_ABOUT, MainDialog::_wxFB_OnClickAbout )
	EVT_BUTTON( wxID_OPERATION_BUTTON, MainDialog::_wxFB_OnOperationSelected )
	EVT_BUTTON( wxID_SHOW_IDE_LOG, MainDialog::_wxFB_OnShowHideLog )
END_EVENT_TABLE()

MainDialog::MainDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	mainSizer = new wxBoxSizer( wxHORIZONTAL );
	
	leftSizer = new wxBoxSizer( wxVERTICAL );
	
	panelSizer = new wxBoxSizer( wxVERTICAL );
	
	nullPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	panelSizer->Add( nullPanel, 1, wxEXPAND | wxALL, 5 );
	
	
	leftSizer->Add( panelSizer, 1, wxEXPAND, 1 );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );
	
	aboutButton = new wxButton( this, wxID_ABOUT, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBU_EXACTFIT | wxBU_NOTEXT );
	aboutButton->SetToolTip( _("Shows information about this program.") );
	
	bSizer22->Add( aboutButton, 0, wxALIGN_LEFT|wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 0 );
	
	
	bSizer20->Add( bSizer22, 1, wxEXPAND|wxLEFT, 5 );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );
	
	operationButton = new wxButton( this, wxID_OPERATION_BUTTON, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBU_EXACTFIT | wxBU_NOTEXT );
	operationButton->SetToolTip( _("Switches between patch creation and patch application modes.") );
	
	bSizer21->Add( operationButton, 0, wxBOTTOM|wxEXPAND, 0 );
	bSizer21->AddSpacer(7);

	showHideLog = new wxButton( this, wxID_SHOW_IDE_LOG, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBU_EXACTFIT | wxBU_NOTEXT );
	showHideLog->SetToolTip( _("Hides/Shows the log window.") );
	
	bSizer21->Add( showHideLog, 0, wxBOTTOM|wxEXPAND, 0 );
	
	bSizer20->Add( bSizer21, 0, wxEXPAND|wxRIGHT, 5 );
	
	
	leftSizer->Add( bSizer20, 0, wxEXPAND, 5 );
	
	
	mainSizer->Add( leftSizer, 0, wxBOTTOM|wxEXPAND, 5 );
	
	logBox = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Log:") ), wxVERTICAL );
	
	logCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE|wxTE_WORDWRAP );
	logBox->Add( logCtrl, 1, wxALL|wxEXPAND, 5 );
	
	
	mainSizer->Add( logBox, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( mainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}

MainDialog::~MainDialog()
{
}

BEGIN_EVENT_TABLE( DecodePanel, wxPanel )
	EVT_BUTTON( wxID_DECODE_ORIGINAL_OPEN, DecodePanel::_wxFB_OnOpenOriginal )
	EVT_BUTTON( wxID_DECODE_PATCH_OPEN, DecodePanel::_wxFB_OnOpenPatch )
	EVT_BUTTON( wxID_DECODE_APPLY, DecodePanel::_wxFB_OnApplyPatch )
	EVT_BUTTON( wxID_DECODE_OPTIONS_BUTTON, DecodePanel::_wxFB_OnDecodeOptionsClicked )
END_EVENT_TABLE()

DecodePanel::DecodePanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	decodeMainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Original file:") ), wxHORIZONTAL );
	
	originalField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	originalField->SetMaxLength( 0 ); 
	sbSizer1->Add( originalField, 1, wxALL|wxEXPAND, 7 );
	
	originalButton = new wxButton( this, wxID_DECODE_ORIGINAL_OPEN, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBU_EXACTFIT | wxBU_NOTEXT );
	originalButton->SetToolTip( _("Choose the file to patch.") );
	
	sbSizer1->Add( originalButton, 0, wxALL, 5 );
	
	
	decodeMainSizer->Add( sbSizer1, 0, wxBOTTOM|wxEXPAND, 2 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("XDelta patch:") ), wxHORIZONTAL );
	
	patchField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	patchField->SetMaxLength( 0 ); 
	sbSizer3->Add( patchField, 1, wxALL|wxEXPAND, 7 );
	
	patchButton = new wxButton( this, wxID_DECODE_PATCH_OPEN, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBU_EXACTFIT | wxBU_NOTEXT );
	patchButton->SetToolTip( _("Choose the patch to be applied to the selected file.") );
	
	sbSizer3->Add( patchButton, 0, wxALL, 5 );
	
	
	decodeMainSizer->Add( sbSizer3, 0, wxBOTTOM|wxEXPAND|wxTOP, 2 );
	
	wxBoxSizer* decodeBottomSizer;
	decodeBottomSizer = new wxBoxSizer( wxHORIZONTAL );
	
	applyButton = new wxButton( this, wxID_DECODE_APPLY, _("Apply patch"), wxDefaultPosition, wxDefaultSize, 0 );
	applyButton->SetDefault(); 
	applyButton->SetToolTip( _("Applies the selected patch to the given file.") );
	
	decodeBottomSizer->Add( applyButton, 1, wxTOP|wxBOTTOM|wxEXPAND, 0 );
	decodeBottomSizer->AddSpacer(7);

	decodeOptionsButton = new wxButton( this, wxID_DECODE_OPTIONS_BUTTON, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBU_EXACTFIT | wxBU_NOTEXT );
	decodeOptionsButton->SetToolTip( _("Changes settings for patch application.") );
	
	decodeBottomSizer->Add( decodeOptionsButton, 0, wxBOTTOM|wxTOP|wxEXPAND, 0 );
	
	
	decodeMainSizer->Add( decodeBottomSizer, 0, wxEXPAND|wxTOP, 4 );
	
	
	this->SetSizer( decodeMainSizer );
	this->Layout();
}

DecodePanel::~DecodePanel()
{
}

BEGIN_EVENT_TABLE( EncodePanel, wxPanel )
	EVT_BUTTON( wxID_ENCODE_ORIGINAL_OPEN, EncodePanel::_wxFB_OnOpenOriginal )
	EVT_BUTTON( wxID_ENCODE_MODIFIED_OPEN, EncodePanel::_wxFB_OnOpenModified )
	EVT_BUTTON( wxID_ENCODE_PATCH_SAVE, EncodePanel::_wxFB_OnSavePatch )
	EVT_BUTTON( wxID_ENCODE_CREATE, EncodePanel::_wxFB_OnCreatePatch )
	EVT_BUTTON( wxID_ENCODE_OPTIONS_BUTTON, EncodePanel::_wxFB_OnEncodeOptionsClicked )
END_EVENT_TABLE()

EncodePanel::EncodePanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Original file:") ), wxHORIZONTAL );
	
	originalField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	originalField->SetMaxLength( 0 ); 
	sbSizer1->Add( originalField, 1, wxALL|wxEXPAND, 7 );
	
	originalButton = new wxButton( this, wxID_ENCODE_ORIGINAL_OPEN, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBU_EXACTFIT | wxBU_NOTEXT );
	originalButton->SetToolTip( _("Choose the original (untouched) file.") );
	
	sbSizer1->Add( originalButton, 0, wxALL, 5 );
	
	
	bSizer1->Add( sbSizer1, 0, wxBOTTOM|wxEXPAND, 2 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Modified file:") ), wxHORIZONTAL );
	
	modifiedField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	modifiedField->SetMaxLength( 0 ); 
	sbSizer3->Add( modifiedField, 1, wxALL|wxEXPAND, 7 );
	
	modifiedButton = new wxButton( this, wxID_ENCODE_MODIFIED_OPEN, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBU_EXACTFIT | wxBU_NOTEXT );
	modifiedButton->SetToolTip( _("Choose the modified file.") );
	
	sbSizer3->Add( modifiedButton, 0, wxALL, 5 );
	
	
	bSizer1->Add( sbSizer3, 0, wxBOTTOM|wxEXPAND|wxTOP, 2 );
	
	wxStaticBoxSizer* sbSizer31;
	sbSizer31 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("XDelta patch:") ), wxHORIZONTAL );
	
	patchField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	patchField->SetMaxLength( 0 ); 
	sbSizer31->Add( patchField, 1, wxALL|wxEXPAND, 7 );
	
	patchButton = new wxButton( this, wxID_ENCODE_PATCH_SAVE, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBU_EXACTFIT | wxBU_NOTEXT );
	patchButton->SetToolTip( _("Choose where to save the patch containing the differences between the original and the modified file.") );
	
	sbSizer31->Add( patchButton, 0, wxALL, 5 );
	
	
	bSizer1->Add( sbSizer31, 0, wxBOTTOM|wxEXPAND|wxTOP, 2 );
	
	wxStaticBoxSizer* sbSizer311;
	sbSizer311 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Description (optional):") ), wxHORIZONTAL );
	
	descriptionField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	sbSizer311->Add( descriptionField, 1, wxALL|wxEXPAND, 6 );
	
	
	bSizer1->Add( sbSizer311, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	createButton = new wxButton( this, wxID_ENCODE_CREATE, _("Create patch"), wxDefaultPosition, wxDefaultSize, 0 );
	createButton->SetDefault(); 
	createButton->SetToolTip( _("Creates a patch containing the differences between the original and the modified file.") );
	
	bSizer4->Add( createButton, 1, wxTOP|wxBOTTOM|wxEXPAND, 0 );
	bSizer4->AddSpacer(7);
	
	encodeOptionsButton = new wxButton( this, wxID_ENCODE_OPTIONS_BUTTON, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBU_EXACTFIT | wxBU_NOTEXT );
	encodeOptionsButton->SetToolTip( _("Changes settings for patch creation.") );
	
	bSizer4->Add( encodeOptionsButton, 0, wxBOTTOM|wxTOP|wxEXPAND, 0 );
	
	
	bSizer1->Add( bSizer4, 0, wxEXPAND|wxTOP, 4 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
}

EncodePanel::~EncodePanel()
{
}

BEGIN_EVENT_TABLE( AboutDialog, wxDialog )
	EVT_CLOSE( AboutDialog::_wxFB_OnClickClose )
	EVT_BUTTON( wxID_OK, AboutDialog::_wxFB_OnClickOk )
END_EVENT_TABLE()

AboutDialog::AboutDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	aboutNotebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	aboutPage = new wxPanel( aboutNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	aboutLogo = new wxStaticBitmap( aboutPage, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( aboutLogo, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	nameAndVerText = new wxStaticText( aboutPage, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	nameAndVerText->Wrap( -1 );
	nameAndVerText->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizer19->Add( nameAndVerText, 0, wxEXPAND|wxTOP, 5 );
	
	
	bSizer17->Add( bSizer19, 0, wxALIGN_CENTER, 5 );
	
	wxBoxSizer* bSizer181;
	bSizer181 = new wxBoxSizer( wxHORIZONTAL );
	
	copyrightText = new wxStaticText( aboutPage, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	copyrightText->Wrap( -1 );
	bSizer181->Add( copyrightText, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer17->Add( bSizer181, 0, wxALIGN_CENTER, 5 );
	
	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxHORIZONTAL );
	
	siteText = new wxHyperlinkCtrl( aboutPage, wxID_ANY, _("http://github.com/marco-calautti"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_ALIGN_CENTRE );
	bSizer171->Add( siteText, 0, wxALL|wxEXPAND, 2 );
	
	
	bSizer17->Add( bSizer171, 1, wxALIGN_CENTER, 5 );
	
	
	bSizer13->Add( bSizer17, 1, wxALIGN_CENTER, 5 );
	
	
	bSizer14->Add( bSizer13, 0, wxEXPAND, 5 );
	
	disclaimerText = new wxStaticText( aboutPage, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	disclaimerText->Wrap( -1 );
	bSizer14->Add( disclaimerText, 0, wxALL|wxEXPAND, 3 );
	
	
	aboutPage->SetSizer( bSizer14 );
	aboutPage->Layout();
	bSizer14->Fit( aboutPage );
	aboutNotebook->AddPage( aboutPage, _("About"), true );
	licensePage = new wxPanel( aboutNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );
	
	licenseText = new wxTextCtrl( licensePage, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE );
	bSizer18->Add( licenseText, 1, wxALL|wxEXPAND, 5 );
	
	
	licensePage->SetSizer( bSizer18 );
	licensePage->Layout();
	bSizer18->Fit( licensePage );
	aboutNotebook->AddPage( licensePage, _("License"), false );
	
	bSizer12->Add( aboutNotebook, 1, wxEXPAND | wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer12->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	okButton = new wxButton( this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( okButton, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	this->SetSizer( bSizer12 );
	this->Layout();
}

AboutDialog::~AboutDialog()
{
}
