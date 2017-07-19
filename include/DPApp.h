//Copyright (C) 2017 Phoenix.

//This program is free software: you can redistribute it and/or modify 
//it under the terms of the GNU General Public License as published by 
//the Free Software Foundation, version 2.0. 

//This program is distributed in the hope that it will be useful, 
//but WITHOUT ANY WARRANTY; without even the implied warranty of 
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
//GNU General Public License 2.0 for more details. 

//A copy of the GPL 2.0 should have been included with the program. 
//If not, see http://www.gnu.org/licenses/ 

//Source code and contact information can be found at 
//http://www.sadnescity.it


#include <wx/wx.h>
#include <wx/intl.h>
#include <wx/cmdline.h>

class DPApp : public wxApp{

public:
	virtual bool OnInit();
	virtual bool OnCmdLineParsed(wxCmdLineParser& parser);
	virtual void OnInitCmdLine(wxCmdLineParser& parser);
private:
	wxLocale locale;
	wxString patchName;
	
};

static const wxCmdLineEntryDesc cmdLineDesc [] =
{
     { wxCMD_LINE_PARAM, NULL, NULL, NULL,wxCMD_LINE_VAL_STRING ,wxCMD_LINE_PARAM_OPTIONAL },
     { wxCMD_LINE_NONE }
};

DECLARE_APP(DPApp);
