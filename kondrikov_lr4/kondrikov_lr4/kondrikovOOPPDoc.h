
// kondrikovOOPPDoc.h: интерфейс класса CkondrikovOOPPDoc 
//


#pragma once
#include "Group_kondrikov.h"
#include "kondrikov_MyDialog.h"

class CkondrikovOOPPDoc : public CDocument
{
protected: // создать только из сериализации
	CkondrikovOOPPDoc() noexcept;
	DECLARE_DYNCREATE(CkondrikovOOPPDoc)

// Атрибуты
public:
	Group group;
// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CkondrikovOOPPDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnEditData();
};
