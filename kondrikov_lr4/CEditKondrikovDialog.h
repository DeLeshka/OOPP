#pragma once
#include "KondrikovLRDoc.h"
#include "CAddKondrikovDialog.h"



// CAdderKondrikovDialog dialog
class CEditKondrikovDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CEditKondrikovDialog)

	CKondrikovLRDoc* pDoc;


public:
	CEditKondrikovDialog(CKondrikovLRDoc* pDoc, CWnd* pParent = nullptr);   // standard constructor
	virtual ~CEditKondrikovDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = ID_ADD_WORKER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	BOOL OnInitDialog();
	int getWorkerIdFromLB();
	void setWorkersDataToEdit(std::shared_ptr<CKondrikovWorker>);
	void setLBData();

public:

	CListBox listWorker;


	CEdit editTasks;
	CEdit editSlogan;
	CEdit editName;
	CEdit editLastName;
	CEdit editID;
	CEdit editAge;
	CEdit editSalary;


	CStatic staticSlogan;
	CStatic staticTasks;


	afx_msg void OnBnClickedEditButton();
	afx_msg void OnLbnSelchangeListbox();
	afx_msg void OnBnClickedAddWorkerButton();
	afx_msg void OnBnClickedDeleteButton();
};
