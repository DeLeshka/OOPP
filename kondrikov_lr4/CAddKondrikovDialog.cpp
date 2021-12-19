// CAddKondrikovDialog.cpp : implementation file
//

#include "pch.h"
#include "KondrikovLR.h"
#include "CAddKondrikovDialog.h"
#include "afxdialogex.h"


// CAddKondrikovDialog dialog

IMPLEMENT_DYNAMIC(CAddKondrikovDialog, CDialogEx)

CAddKondrikovDialog::CAddKondrikovDialog(CKondrikovLRDoc* pDoc, std::shared_ptr<CKondrikovWorker> pWorker, CWnd* pParent)
	: CDialogEx(ID_ADD, pParent)
{
	this->pDoc = pDoc;
	this->pWorker = pWorker;
}

CAddKondrikovDialog::~CAddKondrikovDialog()
{
}

BOOL CAddKondrikovDialog::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	if (this->pWorker != nullptr)
	{
	
		// edit mode


		this->cRadioBtnManager.ShowWindow(SW_HIDE);


		this->cEditAge.SetWindowTextA(std::to_string(this->pWorker->age()).c_str());
		this->cEditLastName.SetWindowTextA(this->pWorker->lastName().c_str());
		this->cEditName.SetWindowTextA(this->pWorker->name().c_str());
		this->cEditSalary.SetWindowTextA(std::to_string(this->pWorker->salary()).c_str());

		std::shared_ptr<CKondrikovManager> pManager = std::dynamic_pointer_cast<CKondrikovManager>(this->pWorker);
		if ( pManager != nullptr)
		{


			this->cEditSlogan.SetWindowTextA(pManager->slogan().c_str());
			this->cEditTasks.SetWindowTextA(std::to_string(pManager->tasks()).c_str());

			this->cEditSlogan.ShowWindow(SW_SHOW);
			this->cEditTasks.ShowWindow(SW_SHOW);

			this->cStaticSlogan.ShowWindow(SW_SHOW);
			this->cStaticTasks.ShowWindow(SW_SHOW);


		}

	}


	return true;
}

void CAddKondrikovDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ID_EDIT_NAME, cEditName);
	DDX_Control(pDX, ID_EDIT_L_NAME, cEditLastName);
	DDX_Control(pDX, ID_EDIT_AGE, cEditAge);
	DDX_Control(pDX, ID_EDIT_SALARY, cEditSalary);
	DDX_Control(pDX, ID_EDIT_TASKS, cEditTasks);
	DDX_Control(pDX, ID_EDIT_SLOGAN, cEditSlogan);
	DDX_Control(pDX, ID_TASKS_STATIC, cStaticTasks);
	DDX_Control(pDX, ID_SLOGAN_STATIC, cStaticSlogan);
	DDX_Control(pDX, IDC_RADIO_MANAGER, cRadioBtnManager);
}


BEGIN_MESSAGE_MAP(CAddKondrikovDialog, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_MANAGER, &CAddKondrikovDialog::OnBnClickedRadioManager)
	ON_BN_CLICKED(IDOK, &CAddKondrikovDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddKondrikovDialog message handlers


void CAddKondrikovDialog::OnBnClickedRadioManager()
{
	
	this->cRadioBtnManager.SetCheck(!this->cRadioBtnManager.GetCheck());

	if (this->cRadioBtnManager.GetCheck())
	{

		this->cEditSlogan.ShowWindow(SW_SHOW);
		this->cEditTasks.ShowWindow(SW_SHOW);

		this->cStaticSlogan.ShowWindow(SW_SHOW);
		this->cStaticTasks.ShowWindow(SW_SHOW);

	}
	else
	{

		this->cEditSlogan.ShowWindow(SW_HIDE);
		this->cEditTasks.ShowWindow(SW_HIDE);

		this->cStaticSlogan.ShowWindow(SW_HIDE);
		this->cStaticTasks.ShowWindow(SW_HIDE);

	}

}



void CAddKondrikovDialog::setValues(std::shared_ptr<CKondrikovWorker> pWorker)
{
	CString buf;
	this->cEditAge.GetWindowTextA(buf);
	pWorker->setAge(_ttoi(buf));


	this->cEditName.GetWindowTextA(buf);
	pWorker->setName(std::string(buf));


	this->cEditLastName.GetWindowTextA(buf);
	pWorker->setLastName(std::string(buf));


	this->cEditSalary.GetWindowTextA(buf);
	pWorker->setSalary(_ttof(buf));

	std::shared_ptr<CKondrikovManager> pManager = std::dynamic_pointer_cast<CKondrikovManager>(pWorker);

	if ( pManager != nullptr)
	{

		this->cEditSlogan.GetWindowTextA(buf);
		pManager->setSlogan(std::string(buf));


		this->cEditTasks.GetWindowTextA(buf);
		pManager->setTasks(_ttoi(buf));

	}


	return;
}



void CAddKondrikovDialog::OnBnClickedOk()
{

	CDialogEx::OnOK();
	if (this->pWorker == nullptr)
	{
		// add mode
		if (this->cRadioBtnManager.GetCheck())
		{

			std::shared_ptr<CKondrikovManager> pManager = std::make_shared<CKondrikovManager>();
			this->setValues(pManager);
			this->pDoc->curCompany.addWorker(pManager);
		}
		else
		{

			std::shared_ptr<CKondrikovWorker> pWorker = std::make_shared<CKondrikovWorker>();
			this->setValues(pWorker);
			this->pDoc->curCompany.addWorker(pWorker);

		}
	}
	else
	{
		// edit mode
		this->setValues(this->pWorker);
	}


}
