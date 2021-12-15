
// kondrikov_lr3View.cpp: реализация класса Ckondrikovlr3View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "kondrikov_lr3.h"
#endif

#include "kondrikov_lr3Doc.h"
#include "kondrikov_lr3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ckondrikovlr3View

IMPLEMENT_DYNCREATE(Ckondrikovlr3View, CScrollView)

BEGIN_MESSAGE_MAP(Ckondrikovlr3View, CScrollView)
END_MESSAGE_MAP()

// Создание или уничтожение Ckondrikovlr3View

Ckondrikovlr3View::Ckondrikovlr3View() noexcept
{
	// TODO: добавьте код создания

}

Ckondrikovlr3View::~Ckondrikovlr3View()
{
}

BOOL Ckondrikovlr3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// Рисование Ckondrikovlr3View

void Ckondrikovlr3View::OnDraw(CDC* /*pDC*/)
{
	Ckondrikovlr3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
}

void Ckondrikovlr3View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Диагностика Ckondrikovlr3View

#ifdef _DEBUG
void Ckondrikovlr3View::AssertValid() const
{
	CScrollView::AssertValid();
}

void Ckondrikovlr3View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

Ckondrikovlr3Doc* Ckondrikovlr3View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ckondrikovlr3Doc)));
	return (Ckondrikovlr3Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений Ckondrikovlr3View
