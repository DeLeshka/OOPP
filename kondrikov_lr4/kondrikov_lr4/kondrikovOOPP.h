
// kondrikovOOPP.h: основной файл заголовка для приложения kondrikovOOPP
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CkondrikovOOPPApp:
// Сведения о реализации этого класса: kondrikovOOPP.cpp
//

class CkondrikovOOPPApp : public CWinApp
{
public:
	CkondrikovOOPPApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CkondrikovOOPPApp theApp;
