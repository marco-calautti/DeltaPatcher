//Copyright (C) 2010+ Phoenix. 

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


#ifndef __DP_COMMON__
#define __DP_COMMON__

#include <common/COPYING.h>

#ifdef 	__DP_DECODE_ONLY__
	#define __DP_VERSION__ wxT("3.1.6 Lite")
#else 	
	#define __DP_VERSION__ wxT("3.1.6")
#endif

#define __DP_DISCLAIMER__ _("This program is free software: you can redistribute it\nand/or modify it under the terms of the GNU General\nPublic License as published by the Free Software Foundation,\nversion 2.0.")
static const wxString __DP_LICENSE__(rawLicense);
#define __DP_NAME__ wxT("Delta Patcher")
#define __DP_WEBSITE__ wxT("https://github.com/marco-calautti")
#define __DP_COPYRIGHT__ wxT("(C) 2010+ Phoenix\n<phoenix_87_c@hotmail.com>")
#endif
