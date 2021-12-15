
// kondrikov_lr3View.h: интерфейс класса Ckondrikovlr3View
//

#pragma once


class Ckondrikovlr3View : public CScrollView
{
protected: // создать только из сериализации
	Ckondrikovlr3View() noexcept;
	DECLARE_DYNCREATE(Ckondrikovlr3View)

// Атрибуты
public:
	Ckondrikovlr3Doc* GetDocument() const;

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
	virtual ~Ckondrikovlr3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в kondrikov_lr3View.cpp
inline Ckondrikovlr3Doc* Ckondrikovlr3View::GetDocument() const
   { return reinterpret_cast<Ckondrikovlr3Doc*>(m_pDocument); }
#endif

