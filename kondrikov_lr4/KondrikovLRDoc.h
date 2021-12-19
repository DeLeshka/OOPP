
// KondrikovLRDoc.h : interface of the CKondrikovLRDoc class
//


#pragma once


class CKondrikovLRDoc : public CDocument
{
protected: // create from serialization only
	CKondrikovLRDoc() noexcept;
	DECLARE_DYNCREATE(CKondrikovLRDoc)

// Attributes
public:


	// adding my container
	CKondrikovCompany curCompany;



public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CKondrikovLRDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnFileClear();
	afx_msg void OnEditcompany();
};
