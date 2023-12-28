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


#ifndef __DP_LOGGER__
#define __DP_LOGGER__

class Logger
{
public:

	enum{
		LOG_ERROR,
		LOG_MESSAGE,
	};
	virtual ~Logger(){}
	virtual void Log(int type,const wxChar* msg)=0;
};

#endif
