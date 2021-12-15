
// kondrikovOOPPView.cpp: реализация класса CkondrikovOOPPView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "kondrikovOOPP.h"
#endif

#include "kondrikovOOPPDoc.h"
#include "kondrikovOOPPView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Student_kondrikov.h"


// CkondrikovOOPPView

IMPLEMENT_DYNCREATE(CkondrikovOOPPView, CScrollView)

BEGIN_MESSAGE_MAP(CkondrikovOOPPView, CScrollView)
END_MESSAGE_MAP()

// Создание или уничтожение CkondrikovOOPPView

CkondrikovOOPPView::CkondrikovOOPPView() noexcept
{
	// TODO: добавьте код создания

}

CkondrikovOOPPView::~CkondrikovOOPPView()
{
}

BOOL CkondrikovOOPPView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// Рисование CkondrikovOOPPView

void CkondrikovOOPPView::OnDraw(CDC* pDC)
{
	CkondrikovOOPPDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	int h = 10;
	pDoc->group.ConsoleWrite(pDC, h);

	CSize sizeTotal;
	sizeTotal.cx = 100;
	sizeTotal.cy = h;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CkondrikovOOPPView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Диагностика CkondrikovOOPPView

#ifdef _DEBUG
void CkondrikovOOPPView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CkondrikovOOPPView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CkondrikovOOPPDoc* CkondrikovOOPPView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CkondrikovOOPPDoc)));
	return (CkondrikovOOPPDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CkondrikovOOPPView
