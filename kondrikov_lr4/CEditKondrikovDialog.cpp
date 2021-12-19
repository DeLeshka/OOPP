// CAdderKondrikovDialog.cpp : implementation file
//

#include "pch.h"
#include "KondrikovLR.h"
#include "CEditKondrikovDialog.h"
#include "afxdialogex.h"


// CAdderKondrikovDialog dialog

IMPLEMENT_DYNAMIC(CEditKondrikovDialog, CDialogEx)

CEditKondrikovDialog::CEditKondrikovDialog(CKondrikovLRDoc* pDoc, CWnd* pParent)
	: CDialogEx(ID_ADD_WORKER, pParent)
	, editName()
	, editLastName()
	, editID()
	, editAge()
	, editSalary()
	, editTasks()
	, editSlogan()
{
	this->pDoc = pDoc;
}

CEditKondrikovDialog::~CEditKondrikovDialog()
{
}

void CEditKondrikovDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ID_LISTBOX, listWorker);
	DDX_Control(pDX, ID_EDIT_TASKS, editTasks);
	DDX_Control(pDX, ID_EDIT_SLOGAN, editSlogan);
	DDX_Control(pDX, ID_SLOGAN_STATIC, staticSlogan);
	DDX_Control(pDX, ID_TASKS_STATIC, staticTasks);
	DDX_Control(pDX, ID_EDIT_NAME, editName);
	DDX_Control(pDX, ID_EDIT_L_NAME, editLastName);
	DDX_Control(pDX, ID_EDIT_ID, editID);
	DDX_Control(pDX, ID_EDIT_AGE, editAge);
	DDX_Control(pDX, ID_EDIT_SALARY, editSalary);
}

BOOL CEditKondrikovDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	setLBData();
	this->editAge.SetWindowTextA("");
	this->editID.SetWindowTextA("");
	this->editLastName.SetWindowTextA("");
	this->editName.SetWindowTextA("");
	this->editSalary.SetWindowTextA("");

	this->editTasks.ShowWindow(SW_HIDE);
	this->editSlogan.ShowWindow(SW_HIDE);

	this->staticTasks.ShowWindow(SW_HIDE);
	this->staticSlogan.ShowWindow(SW_HIDE);


	return true;
}

int CEditKondrikovDialog::getWorkerIdFromLB()
{
	int currentNumber(this->listWorker.GetCurSel());
	CString workerData;
	this->listWorker.GetText(currentNumber, workerData);

	int tokenNum(4);

	
	return _ttoi(workerData.Tokenize(" ", tokenNum));
}

void CEditKondrikovDialog::setWorkersDataToEdit(std::shared_ptr<CKondrikovWorker> pWorker)
{


	this->editAge.SetWindowTextA(std::to_string(pWorker->age()).c_str());
	this->editID.SetWindowTextA(std::to_string(pWorker->id()).c_str());
	this->editLastName.SetWindowTextA(pWorker->lastName().c_str());
	this->editName.SetWindowTextA(pWorker->name().c_str());
	this->editSalary.SetWindowTextA(std::to_string(pWorker->salary()).c_str());

	std::shared_ptr<CKondrikovManager> pManager = std::dynamic_pointer_cast<CKondrikovManager>(pWorker);

	if (pManager != nullptr)
	{

		this->editTasks.ShowWindow(SW_SHOW);
		this->editSlogan.ShowWindow(SW_SHOW);

		this->staticTasks.ShowWindow(SW_SHOW);
		this->staticSlogan.ShowWindow(SW_SHOW);

		this->editSlogan.SetWindowTextA(pManager->slogan().c_str());
		this->editTasks.SetWindowTextA(std::to_string(pManager->tasks()).c_str());
		
	}
	else
	{
		this->editSlogan.SetWindowTextA("");
		this->editTasks.SetWindowTextA("");


		this->editTasks.ShowWindow(SW_HIDE);
		this->editSlogan.ShowWindow(SW_HIDE);

		this->staticTasks.ShowWindow(SW_HIDE);
		this->staticSlogan.ShowWindow(SW_HIDE);
	}

}

void CEditKondrikovDialog::setLBData()
{

	this->listWorker.ResetContent();
	std::vector<std::string> workersData(pDoc->curCompany.getShortData());
	std::for_each(workersData.begin(), workersData.end(), [this](std::string workerName) {this->listWorker.AddString(workerName.c_str()); });

	return;
}


BEGIN_MESSAGE_MAP(CEditKondrikovDialog, CDialogEx)
	ON_LBN_SELCHANGE(ID_LISTBOX, &CEditKondrikovDialog::OnLbnSelchangeListbox)
	ON_BN_CLICKED(ID_EDIT_BUTTON, &CEditKondrikovDialog::OnBnClickedEditButton)
	ON_BN_CLICKED(ID_ADD_WORKER_BUTTON, &CEditKondrikovDialog::OnBnClickedAddWorkerButton)
	ON_BN_CLICKED(ID_DELETE_BUTTON, &CEditKondrikovDialog::OnBnClickedDeleteButton)
END_MESSAGE_MAP()


// CAdderKondrikovDialog message handlers






void CEditKondrikovDialog::OnLbnSelchangeListbox()
{
	
	this->setWorkersDataToEdit(this->pDoc->curCompany.getWorkerByID(this->getWorkerIdFromLB()));

	UpdateData(FALSE);
}


//
void CEditKondrikovDialog::OnBnClickedEditButton()
{
	int curSel = this->listWorker.GetCurSel();

	if ( curSel < 0 )
	{
		return;
	}



	CAddKondrikovDialog dlg(this->pDoc, this->pDoc->curCompany.getWorkerByID(this->getWorkerIdFromLB()));

	dlg.DoModal();

	UpdateData();

	setLBData();

	this->listWorker.SetCurSel(curSel);

	this->setWorkersDataToEdit(this->pDoc->curCompany.getWorkerByID(this->getWorkerIdFromLB()));
}



//ok
void CEditKondrikovDialog::OnBnClickedAddWorkerButton()
{

	int curSel = this->listWorker.GetCurSel();

	CAddKondrikovDialog dlg(this->pDoc);

	int isAdded = dlg.DoModal();

	if (this->listWorker.GetCount() == 0)
	{
		return;
	}

	if (isAdded == 1)
	{
		UpdateData();

		setLBData();

		this->listWorker.SetCurSel(this->listWorker.GetCount() - 1);

		this->setWorkersDataToEdit(this->pDoc->curCompany.getWorkerByID(this->getWorkerIdFromLB()));
	}

	return;
}


void CEditKondrikovDialog::OnBnClickedDeleteButton()
{
	int curSel = this->listWorker.GetCurSel();

	if (curSel < 0)
	{
		return;
	}

	this->pDoc->curCompany.removeWorker(this->getWorkerIdFromLB());

	UpdateData();

	setLBData();

	if (this->listWorker.GetCount() == 0)
	{
		OnInitDialog();
		return;
	}
	if (curSel >= this->listWorker.GetCount() )
		curSel = this->listWorker.GetCount() - 1;

	this->listWorker.SetCurSel(curSel);

	this->setWorkersDataToEdit(this->pDoc->curCompany.getWorkerByID(this->getWorkerIdFromLB()));

	return;
}
