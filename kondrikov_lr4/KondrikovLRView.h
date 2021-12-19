
// KondrikovLRView.h : interface of the CKondrikovLRView class
//

#pragma once


class CKondrikovLRView : public CScrollView
{
protected: // create from serialization only
	CKondrikovLRView() noexcept;
	DECLARE_DYNCREATE(CKondrikovLRView)

// Attributes
public:
	CKondrikovLRDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CKondrikovLRView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in KondrikovLRView.cpp
inline CKondrikovLRDoc* CKondrikovLRView::GetDocument() const
   { return reinterpret_cast<CKondrikovLRDoc*>(m_pDocument); }
#endif

