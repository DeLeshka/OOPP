#pragma once

class CEditKondrikovDialog;

// CAddKondrikovDialog dialog
class CAddKondrikovDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CAddKondrikovDialog)

public:
	CAddKondrikovDialog(CKondrikovLRDoc* pDoc, std::shared_ptr<CKondrikovWorker> pWorker = nullptr, CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddKondrikovDialog();


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = ID_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:


	BOOL OnInitDialog();

	std::shared_ptr<CKondrikovWorker> pWorker;
	CKondrikovLRDoc* pDoc;

	CEdit cEditName;
	CEdit cEditLastName;
	CEdit cEditAge;
	CEdit cEditSalary;
	CEdit cEditTasks;
	CEdit cEditSlogan;
	CStatic cStaticTasks;
	CStatic cStaticSlogan;
	CButton cRadioBtnManager;

	afx_msg void OnBnClickedRadioManager();
	afx_msg void OnBnClickedOk();

	void setValues(std::shared_ptr<CKondrikovWorker>);
};
