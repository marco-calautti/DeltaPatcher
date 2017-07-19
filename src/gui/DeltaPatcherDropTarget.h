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
//https://github.com/marco-calautti


#ifndef __DP_DROP_TARGET__
#define __DP_DROP_TARGET__

#include <wx/dnd.h>
#include "DeltaPatcherDropHandler.h"
#include <wx/wx.h>

class DeltaPatcherDropTarget : public wxFileDropTarget
{
public:
	DeltaPatcherDropTarget(DeltaPatcherDropHandler* handler);
	
	virtual bool OnDropFiles(wxCoord,wxCoord,const wxArrayString&);
	
private:
	DeltaPatcherDropHandler* handler;
};
#endif
