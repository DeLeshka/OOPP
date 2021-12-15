#pragma once

#include "kondrikovOOPPDoc.h"
class CkondrikovOOPPDoc;

// Диалоговое окно MyDialog

class MyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog)

public:
	MyDialog(CkondrikovOOPPDoc*, CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~MyDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CkondrikovOOPPDoc* doc;
	virtual BOOL OnInitDialog();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnEnChangeEditSurname();
	afx_msg void OnEnChangeEditName();
	afx_msg void OnEnChangeEditAge();
	afx_msg void OnEnChangeEditScholarship();
	afx_msg void OnBnClickedAddStudent();
	afx_msg void OnBnClickedAddHeadman();
	afx_msg void OnBnClickedDeleteStudent();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CListBox studentsList;
	afx_msg void OnBnClickedHasJournal();
	CEdit editSurname;
	CEdit editName;
	CEdit editAge;
	CButton checkHasJournal;
	CEdit editScholarship;
	CString editValueSurname;
	CString editValueName;
	float editValueAge;
	BOOL checkValueHasJournal;
	float editValueScholarship;
	CStatic textScholarship;
	CButton textAge;
};
