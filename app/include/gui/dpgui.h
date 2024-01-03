///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 12 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DPGUI_H__
#define __DPGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/dialog.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/hyperlink.h>
#include <wx/notebook.h>
#include <wx/statline.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainDialog
///////////////////////////////////////////////////////////////////////////////
class MainDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnActivate( wxActivateEvent& event ){ OnActivate( event ); }
		void _wxFB_OnMainDialogClose( wxCloseEvent& event ){ OnMainDialogClose( event ); }
		void _wxFB_OnClickAbout( wxCommandEvent& event ){ OnClickAbout( event ); }
		void _wxFB_OnOperationSelected( wxCommandEvent& event ){ OnOperationSelected( event ); }
		void _wxFB_OnShowHideLog( wxCommandEvent& event ){ OnShowHideLog( event ); }
		void _wxFB_OnMainDialogShow( wxShowEvent& event ){ OnMainDialogShow( event ); }
	
	protected:
		enum
		{
			wxID_OPERATION_BUTTON = 1000,
			wxID_SHOW_IDE_LOG
		};
		
		wxBoxSizer* mainSizer;
		wxBoxSizer* leftSizer;
		wxBoxSizer* panelSizer;
		wxPanel* nullPanel;
		wxBitmapButton* aboutButton;
		wxBitmapButton* operationButton;
		wxBitmapButton* showHideLog;
		wxStaticBoxSizer* logBox;
		wxTextCtrl* logCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnActivate( wxActivateEvent& event ) { event.Skip(); }
		virtual void OnMainDialogClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnClickAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOperationSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnShowHideLog( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMainDialogShow( wxShowEvent& event ) { event.Skip(); }
	
	public:
		
		MainDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Delta Patcher"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 504,-1 ), long style = wxCAPTION|wxCLOSE_BOX|wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER ); 
		~MainDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DecodePanel
///////////////////////////////////////////////////////////////////////////////
class DecodePanel : public wxPanel 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnOpenOriginal( wxCommandEvent& event ){ OnOpenOriginal( event ); }
		void _wxFB_OnOpenPatch( wxCommandEvent& event ){ OnOpenPatch( event ); }
		void _wxFB_OnApplyPatch( wxCommandEvent& event ){ OnApplyPatch( event ); }
		void _wxFB_OnDecodeOptionsClicked( wxCommandEvent& event ){ OnDecodeOptionsClicked( event ); }
		
	
	protected:
		enum
		{
			wxID_DECODE_ORIGINAL_OPEN = 1000,
			wxID_DECODE_PATCH_OPEN,
			wxID_DECODE_APPLY,
			wxID_DECODE_OPTIONS_BUTTON
		};
		
		wxTextCtrl* originalField;
		wxBitmapButton* originalButton;
		wxTextCtrl* patchField;
		wxBitmapButton* patchButton;
		wxButton* applyButton;
		wxBitmapButton* decodeOptionsButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOpenOriginal( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenPatch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnApplyPatch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDecodeOptionsClicked( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxBoxSizer* decodeMainSizer;
		
		DecodePanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 260,184 ), long style = wxTAB_TRAVERSAL ); 
		~DecodePanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class EncodePanel
///////////////////////////////////////////////////////////////////////////////
class EncodePanel : public wxPanel 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnOpenOriginal( wxCommandEvent& event ){ OnOpenOriginal( event ); }
		void _wxFB_OnOpenModified( wxCommandEvent& event ){ OnOpenModified( event ); }
		void _wxFB_OnSavePatch( wxCommandEvent& event ){ OnSavePatch( event ); }
		void _wxFB_OnCreatePatch( wxCommandEvent& event ){ OnCreatePatch( event ); }
		void _wxFB_OnEncodeOptionsClicked( wxCommandEvent& event ){ OnEncodeOptionsClicked( event ); }
		
	
	protected:
		enum
		{
			wxID_ENCODE_ORIGINAL_OPEN = 1000,
			wxID_ENCODE_MODIFIED_OPEN,
			wxID_ENCODE_PATCH_SAVE,
			wxID_ENCODE_CREATE,
			wxID_ENCODE_OPTIONS_BUTTON
		};
		
		wxTextCtrl* originalField;
		wxBitmapButton* originalButton;
		wxTextCtrl* modifiedField;
		wxBitmapButton* modifiedButton;
		wxTextCtrl* patchField;
		wxBitmapButton* patchButton;
		wxTextCtrl* descriptionField;
		wxButton* createButton;
		wxBitmapButton* encodeOptionsButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOpenOriginal( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenModified( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSavePatch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCreatePatch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEncodeOptionsClicked( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		EncodePanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 320,407 ), long style = wxTAB_TRAVERSAL ); 
		~EncodePanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AboutDialog
///////////////////////////////////////////////////////////////////////////////
class AboutDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnClickClose( wxCloseEvent& event ){ OnClickClose( event ); }
		void _wxFB_OnClickOk( wxCommandEvent& event ){ OnClickOk( event ); }
		
	
	protected:
		wxNotebook* aboutNotebook;
		wxPanel* aboutPage;
		wxStaticBitmap* aboutLogo;
		wxStaticText* nameAndVerText;
		wxStaticText* copyrightText;
		wxHyperlinkCtrl* siteText;
		wxStaticText* disclaimerText;
		wxPanel* licensePage;
		wxTextCtrl* licenseText;
		wxStaticLine* m_staticline1;
		wxButton* okButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClickClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnClickOk( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AboutDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("About Delta Patcher"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 354,308 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~AboutDialog();
	
};

#endif //__DPGUI_H__
