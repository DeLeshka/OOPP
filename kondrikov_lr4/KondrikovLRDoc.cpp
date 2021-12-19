
// KondrikovLRDoc.cpp : implementation of the CKondrikovLRDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "KondrikovLR.h"
#endif

#include "KondrikovLRDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CEditKondrikovDialog.h"

// CKondrikovLRDoc

IMPLEMENT_DYNCREATE(CKondrikovLRDoc, CDocument)

BEGIN_MESSAGE_MAP(CKondrikovLRDoc, CDocument)
	
	ON_COMMAND(ID_FILE_CLEAR, &CKondrikovLRDoc::OnFileClear)
	ON_COMMAND(ID_EDITCOMPANY, &CKondrikovLRDoc::OnEditcompany)
END_MESSAGE_MAP()


// CKondrikovLRDoc construction/destruction

CKondrikovLRDoc::CKondrikovLRDoc() noexcept
{
	// TODO: add one-time construction code here
}









CKondrikovLRDoc::~CKondrikovLRDoc()
{
}











BOOL CKondrikovLRDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	this->curCompany.removeWorkers();

	return TRUE;
}










// CKondrikovLRDoc serialization

void CKondrikovLRDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		this->curCompany.saveCompany(ar);
	}
	else
	{
		this->curCompany.removeWorkers();
		this->curCompany.extractCompany(ar);

	}
}







#ifdef SHARED_HANDLERS

// Support for thumbnails
void CKondrikovLRDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
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

// Support for Search Handlers
void CKondrikovLRDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CKondrikovLRDoc::SetSearchContent(const CString& value)
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

// CKondrikovLRDoc diagnostics

#ifdef _DEBUG
void CKondrikovLRDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKondrikovLRDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


void CKondrikovLRDoc::OnFileClear()
{
	this->curCompany.removeWorkers();
	UpdateAllViews(NULL);
}


void CKondrikovLRDoc::OnEditcompany()
{
	CEditKondrikovDialog dlg(this);
	dlg.DoModal();
	UpdateAllViews(NULL);
}
