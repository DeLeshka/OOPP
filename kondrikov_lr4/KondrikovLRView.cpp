
// KondrikovLRView.cpp : implementation of the CKondrikovLRView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "KondrikovLR.h"
#endif

#include "KondrikovLRDoc.h"
#include "KondrikovLRView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKondrikovLRView

IMPLEMENT_DYNCREATE(CKondrikovLRView, CScrollView)

BEGIN_MESSAGE_MAP(CKondrikovLRView, CScrollView)

END_MESSAGE_MAP()

// CKondrikovLRView construction/destruction

CKondrikovLRView::CKondrikovLRView() noexcept
{
	// TODO: add construction code here

}

CKondrikovLRView::~CKondrikovLRView()
{
}

BOOL CKondrikovLRView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CKondrikovLRView drawing

void CKondrikovLRView::OnDraw(CDC* pDC)
{
	CKondrikovLRDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// count sizes
	pDoc->curCompany.UpdateCompanyTextData();
	TEXTMETRIC tm; 
	pDC->GetTextMetrics(&tm);
	int weigth(pDoc->curCompany.getMaxLengthOfStr() * tm.tmAveCharWidth), height(pDoc->curCompany.getLineCount() * tm.tmHeight);


	RECT rc;
	SetRect(&rc, 2, 2, weigth + 2, height + 2);


	pDC->DrawText(pDoc->curCompany.printCompany().c_str(), &rc, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
	CSize sizeTotal;
	sizeTotal.cx = weigth + 2;
	sizeTotal.cy = height + 2;
	SetScrollSizes(MM_TEXT, sizeTotal);

}

void CKondrikovLRView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CKondrikovLRView diagnostics

#ifdef _DEBUG
void CKondrikovLRView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CKondrikovLRView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CKondrikovLRDoc* CKondrikovLRView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKondrikovLRDoc)));
	return (CKondrikovLRDoc*)m_pDocument;


}
#endif //_DEBUG

