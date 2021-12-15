
// kondrikovOOPPDoc.cpp: реализация класса CkondrikovOOPPDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "kondrikovOOPP.h"
#endif

#include "kondrikovOOPPDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CkondrikovOOPPDoc

IMPLEMENT_DYNCREATE(CkondrikovOOPPDoc, CDocument)

BEGIN_MESSAGE_MAP(CkondrikovOOPPDoc, CDocument)
	ON_COMMAND(ID_EDIT_DATA, &CkondrikovOOPPDoc::OnEditData)
END_MESSAGE_MAP()


// Создание или уничтожение CkondrikovOOPPDoc

CkondrikovOOPPDoc::CkondrikovOOPPDoc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора
}

CkondrikovOOPPDoc::~CkondrikovOOPPDoc()
{
}

BOOL CkondrikovOOPPDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	group = Group(0, vector<shared_ptr<Student>> {});

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}


 // Сериализация CkondrikovOOPPDoc

void CkondrikovOOPPDoc::Serialize(CArchive& ar)
{
	group = Group();
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
		group.SaveToFile(ar);
	}
	else
	{
		// TODO: добавьте код загрузки
		group.LoadFromFile(ar);
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CkondrikovOOPPDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CkondrikovOOPPDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CkondrikovOOPPDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CkondrikovOOPPDoc

#ifdef _DEBUG
void CkondrikovOOPPDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CkondrikovOOPPDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CkondrikovOOPPDoc


void CkondrikovOOPPDoc::OnEditData()
{
	// TODO: добавьте свой код обработчика команд
	MyDialog dlg(this);
	if (dlg.DoModal() == IDOK) {
		UpdateAllViews(NULL);
	}
	delete dlg;
}
