//Copyright (C) 2010 Phoenix. 

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


#ifndef __XDELTA_PATCH__
#define __XDELTA_PATCH__

#include <wx/wx.h>

typedef struct _XDeltaConfig{

	_XDeltaConfig(){
		compressionLevel=5;
		enableChecksum=true;
		overwriteOutput=true;
	}
	
	int compressionLevel;
	bool enableChecksum;
	bool overwriteOutput;
} XDeltaConfig;

class XDeltaPatch : public wxObject
{
public:
	
	/**
	 * Creates a patch with default config from specified patch file
	 * 
	 * */
	XDeltaPatch(const wxChar* patchName);
	
	
	/**
	 * Default destructor
	 * */
	virtual ~XDeltaPatch(){}
	
	void SetConfig(const XDeltaConfig& config);
	XDeltaConfig&  GetConfig();
	
	static void SetXDeltaExecutable(const wxChar* ex){ xdeltaEx=ex; }
	
	int Decode(const wxChar* original,const wxChar* out,wxString& message);
	int Encode(const wxChar* original,const wxChar* modified,wxString& message);
	
private:
	wxString patchName;
	XDeltaConfig config;
	
	static wxString xdeltaEx;
	
	int Process(const wxString& original,const wxString& out,const wxString& patch,wxString& message,bool encode);
	wxString MakeCommand(const wxString& original,const wxString& out,const wxString& patch,bool encode);
	
};
#endif
