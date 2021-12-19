
// KondrikovLR.h : main header file for the KondrikovLR application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CKondrikovLRApp:
// See KondrikovLR.cpp for the implementation of this class
//

class CKondrikovLRApp : public CWinApp
{
public:
	CKondrikovLRApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CKondrikovLRApp theApp;
