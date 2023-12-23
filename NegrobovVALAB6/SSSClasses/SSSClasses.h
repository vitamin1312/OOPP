// SSSClasses.h : main header file for the SSSClasses DLL
//

#pragma once

#include "pch.h"

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSSSClassesApp
// See SSSClasses.cpp for the implementation of this class
//

class CSSSClassesApp : public CWinApp
{
public:
	CSSSClassesApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
