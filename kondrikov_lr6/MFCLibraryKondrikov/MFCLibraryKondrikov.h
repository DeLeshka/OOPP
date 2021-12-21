// MFCLibraryKondrikov.h: основной файл заголовка для библиотеки DLL MFCLibraryKondrikov
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCLibraryKondrikovApp
// Реализацию этого класса см. в файле MFCLibraryKondrikov.cpp
//

class CMFCLibraryKondrikovApp : public CWinApp
{
public:
	CMFCLibraryKondrikovApp();

// Переопределение
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
