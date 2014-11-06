///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "dpgui.h"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( MainDialog, wxDialog )
	EVT_CLOSE( MainDialog::_wxFB_OnMainDialogClose )
	EVT_RADIOBOX( wxID_ANY, MainDialog::_wxFB_OnOperationSelected )
	EVT_BUTTON( wxID_ABOUT, MainDialog::_wxFB_OnClickAbout )
	EVT_BUTTON( wxID_SHOW_IDE_LOG, MainDialog::_wxFB_OnShowHideLog )
	EVT_CHECKBOX( wxID_ASSOCIATE_XDELTA, MainDialog::_wxFB_OnAssociateXDelta )
	EVT_BUTTON( wxID_EXIT, MainDialog::_wxFB_OnMainDialogCloseButton )
END_EVENT_TABLE()

MainDialog::MainDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	mainSizer = new wxBoxSizer( wxHORIZONTAL );
	
	leftSizer = new wxBoxSizer( wxVERTICAL );
	
	panelSizer = new wxBoxSizer( wxVERTICAL );
	
	nullPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	panelSizer->Add( nullPanel, 1, wxEXPAND | wxALL, 5 );
	
	leftSizer->Add( panelSizer, 1, wxEXPAND, 2 );
	
	wxString operationBoxChoices[] = { _("Apply xdelta patch"), _("Create xdelta patch") };
	int operationBoxNChoices = sizeof( operationBoxChoices ) / sizeof( wxString );
	operationBox = new wxRadioBox( this, wxID_ANY, _("Operations:"), wxDefaultPosition, wxDefaultSize, operationBoxNChoices, operationBoxChoices, 1, wxRA_SPECIFY_ROWS );
	operationBox->SetSelection( 0 );
	leftSizer->Add( operationBox, 0, wxALL|wxEXPAND, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 2, 2, 0, 0 );
	
	aboutButton = new wxButton( this, wxID_ABOUT, _("About"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( aboutButton, 1, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 3 );
	
	showHideLog = new wxButton( this, wxID_SHOW_IDE_LOG, _("<< Hide log"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( showHideLog, 1, wxEXPAND|wxRIGHT|wxTOP, 3 );
	
	associateCheck = new wxCheckBox( this, wxID_ASSOCIATE_XDELTA, _("Associate to xdelta files"), wxDefaultPosition, wxDefaultSize, 0 );
	
	gSizer1->Add( associateCheck, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 4 );
	
	exitButton = new wxButton( this, wxID_EXIT, _("Exit"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( exitButton, 1, wxBOTTOM|wxEXPAND|wxRIGHT|wxTOP, 3 );
	
	leftSizer->Add( gSizer1, 0, wxEXPAND, 5 );
	
	mainSizer->Add( leftSizer, 0, wxEXPAND, 5 );
	
	logBox = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Log:") ), wxVERTICAL );
	
	logCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 350,-1 ), wxHSCROLL|wxTE_MULTILINE|wxTE_WORDWRAP );
	logBox->Add( logCtrl, 1, wxALL|wxEXPAND, 2 );
	
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
END_EVENT_TABLE()

DecodePanel::DecodePanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Original file:") ), wxHORIZONTAL );
	
	originalField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( originalField, 1, wxALL|wxEXPAND, 3 );
	
	originalButton = new wxButton( this, wxID_DECODE_ORIGINAL_OPEN, _("Open..."), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( originalButton, 0, wxALL|wxEXPAND, 3 );
	
	bSizer1->Add( sbSizer1, 0, wxBOTTOM|wxEXPAND, 2 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("XDelta patch:") ), wxHORIZONTAL );
	
	patchField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( patchField, 1, wxALL|wxEXPAND, 3 );
	
	patchButton = new wxButton( this, wxID_DECODE_PATCH_OPEN, _("Open..."), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( patchButton, 0, wxALL|wxEXPAND, 3 );
	
	bSizer1->Add( sbSizer3, 0, wxBOTTOM|wxEXPAND|wxTOP, 2 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	applyButton = new wxButton( this, wxID_DECODE_APPLY, _("Apply patch"), wxDefaultPosition, wxDefaultSize, 0 );
	applyButton->SetDefault(); 
	bSizer4->Add( applyButton, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 12 );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Options:") ), wxVERTICAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	keepOriginalCheck = new wxCheckBox( this, wxID_ANY, _("Keep original file"), wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer6->Add( keepOriginalCheck, 1, wxALL, 2 );
	
	sbSizer5->Add( bSizer6, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	checksumCheck = new wxCheckBox( this, wxID_ANY, _("Checksum validation"), wxDefaultPosition, wxDefaultSize, 0 );
	checksumCheck->SetValue(true);
	
	bSizer7->Add( checksumCheck, 1, wxALL, 2 );
	
	sbSizer5->Add( bSizer7, 1, wxEXPAND, 5 );
	
	bSizer4->Add( sbSizer5, 1, 0, 0 );
	
	bSizer1->Add( bSizer4, 0, wxEXPAND|wxTOP, 2 );
	
	this->SetSizer( bSizer1 );
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
END_EVENT_TABLE()

EncodePanel::EncodePanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Original file:") ), wxHORIZONTAL );
	
	originalField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( originalField, 1, wxALL|wxEXPAND, 3 );
	
	originalButton = new wxButton( this, wxID_ENCODE_ORIGINAL_OPEN, _("Open..."), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( originalButton, 0, wxALL|wxEXPAND, 3 );
	
	bSizer1->Add( sbSizer1, 0, wxBOTTOM|wxEXPAND, 2 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Modified file:") ), wxHORIZONTAL );
	
	modifiedField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( modifiedField, 1, wxALL|wxEXPAND, 3 );
	
	modifiedButton = new wxButton( this, wxID_ENCODE_MODIFIED_OPEN, _("Open..."), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( modifiedButton, 0, wxALL|wxEXPAND, 3 );
	
	bSizer1->Add( sbSizer3, 0, wxBOTTOM|wxEXPAND|wxTOP, 2 );
	
	wxStaticBoxSizer* sbSizer31;
	sbSizer31 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("XDelta patch:") ), wxHORIZONTAL );
	
	patchField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer31->Add( patchField, 1, wxALL|wxEXPAND, 3 );
	
	patchButton = new wxButton( this, wxID_ENCODE_PATCH_SAVE, _("Save..."), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer31->Add( patchButton, 0, wxALL|wxEXPAND, 3 );
	
	bSizer1->Add( sbSizer31, 0, wxBOTTOM|wxEXPAND|wxTOP, 2 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	createButton = new wxButton( this, wxID_ENCODE_CREATE, _("Create patch"), wxDefaultPosition, wxDefaultSize, 0 );
	createButton->SetDefault(); 
	bSizer4->Add( createButton, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 12 );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Options:") ), wxVERTICAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Compression level:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer6->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 2 );
	
	wxString choiceCompressionChoices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int choiceCompressionNChoices = sizeof( choiceCompressionChoices ) / sizeof( wxString );
	choiceCompression = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiceCompressionNChoices, choiceCompressionChoices, 0 );
	choiceCompression->SetSelection( 5 );
	bSizer6->Add( choiceCompression, 0, wxALL, 2 );
	
	sbSizer5->Add( bSizer6, 1, 0, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	checksumCheck = new wxCheckBox( this, wxID_ANY, _("Add Checksum to patch"), wxDefaultPosition, wxDefaultSize, 0 );
	checksumCheck->SetValue(true);
	
	bSizer7->Add( checksumCheck, 1, wxALL, 2 );
	
	sbSizer5->Add( bSizer7, 1, 0, 5 );
	
	bSizer4->Add( sbSizer5, 1, 0, 0 );
	
	bSizer1->Add( bSizer4, 0, wxEXPAND|wxTOP, 2 );
	
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
	
	nameAndVerText = new wxStaticText( aboutPage, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	nameAndVerText->Wrap( -1 );
	nameAndVerText->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizer17->Add( nameAndVerText, 0, wxALIGN_CENTER|wxEXPAND|wxTOP, 5 );
	
	copyrightText = new wxStaticText( aboutPage, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	copyrightText->Wrap( -1 );
	bSizer17->Add( copyrightText, 0, wxALL|wxEXPAND, 5 );
	
	siteText = new wxHyperlinkCtrl( aboutPage, wxID_ANY, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer17->Add( siteText, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 2 );
	
	bSizer13->Add( bSizer17, 1, wxALIGN_CENTER, 5 );
	
	bSizer14->Add( bSizer13, 0, wxEXPAND, 5 );
	
	disclaimerText = new wxStaticText( aboutPage, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	disclaimerText->Wrap( -1 );
	bSizer14->Add( disclaimerText, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 3 );
	
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
