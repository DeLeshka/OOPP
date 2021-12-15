
// kondrikov_lr3.h: основной файл заголовка для приложения kondrikov_lr3
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// Ckondrikovlr3App:
// Сведения о реализации этого класса: kondrikov_lr3.cpp
//

class Ckondrikovlr3App : public CWinApp
{
public:
	Ckondrikovlr3App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ckondrikovlr3App theApp;
