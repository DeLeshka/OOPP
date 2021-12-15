
// kondrikovOOPPView.h: интерфейс класса CkondrikovOOPPView
//

#pragma once


class CkondrikovOOPPView : public CScrollView
{
protected: // создать только из сериализации
	CkondrikovOOPPView() noexcept;
	DECLARE_DYNCREATE(CkondrikovOOPPView)

// Атрибуты
public:
	CkondrikovOOPPDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~CkondrikovOOPPView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в kondrikovOOPPView.cpp
inline CkondrikovOOPPDoc* CkondrikovOOPPView::GetDocument() const
   { return reinterpret_cast<CkondrikovOOPPDoc*>(m_pDocument); }
#endif

