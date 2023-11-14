
// NegrobovVAAS-21-05lab3.h : main header file for the NegrobovVAAS-21-05lab3 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CNegrobovVAAS2105lab3App:
// See NegrobovVAAS-21-05lab3.cpp for the implementation of this class
//

class CNegrobovVAAS2105lab3App : public CWinApp
{
public:
	CNegrobovVAAS2105lab3App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CNegrobovVAAS2105lab3App theApp;
