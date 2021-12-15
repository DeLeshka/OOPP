// kondrikov_MyDialog.cpp: файл реализации
//

#include "pch.h"
#include "kondrikovOOPP.h"
#include "kondrikov_MyDialog.h"
#include "afxdialogex.h"

// Диалоговое окно MyDialog

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CkondrikovOOPPDoc* pDoc, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, editValueSurname(_T("Фамилия"))
	, editValueName(_T("Имя"))
	, editValueAge(0)
	, checkValueHasJournal(FALSE)
	, editValueScholarship(0)
{
	doc = pDoc;
}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, studentsList);
	DDX_Control(pDX, IDC_EDIT_SURNAME, editSurname);
	DDX_Control(pDX, IDC_EDIT_NAME, editName);
	DDX_Control(pDX, IDC_EDIT_AGE, editAge);
	DDX_Control(pDX, IDC_HAS_JOURNAL, checkHasJournal);
	DDX_Control(pDX, IDC_EDIT_SCHOLARSHIP, editScholarship);
	DDX_Text(pDX, IDC_EDIT_SURNAME, editValueSurname);
	DDX_Text(pDX, IDC_EDIT_NAME, editValueName);
	DDX_Text(pDX, IDC_EDIT_AGE, editValueAge);
	DDX_Check(pDX, IDC_HAS_JOURNAL, checkValueHasJournal);
	DDX_Text(pDX, IDC_EDIT_SCHOLARSHIP, editValueScholarship);
	DDX_Control(pDX, IDC_TEXT_SCHOLARSHIP, textScholarship);
	DDX_Control(pDX, IDCANCEL, textAge);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &MyDialog::OnLbnSelchangeList1)
	ON_EN_CHANGE(IDC_EDIT_SURNAME, &MyDialog::OnEnChangeEditSurname)
	ON_EN_CHANGE(IDC_EDIT_NAME, &MyDialog::OnEnChangeEditName)
	ON_EN_CHANGE(IDC_EDIT_AGE, &MyDialog::OnEnChangeEditAge)
	ON_EN_CHANGE(IDC_EDIT_SCHOLARSHIP, &MyDialog::OnEnChangeEditScholarship)
	ON_BN_CLICKED(IDC_ADD_STUDENT, &MyDialog::OnBnClickedAddStudent)
	ON_BN_CLICKED(IDC_ADD_HEADMAN, &MyDialog::OnBnClickedAddHeadman)
	ON_BN_CLICKED(IDC_DELETE_STUDENT, &MyDialog::OnBnClickedDeleteStudent)
	ON_BN_CLICKED(IDOK, &MyDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MyDialog::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_HAS_JOURNAL, &MyDialog::OnBnClickedHasJournal)
END_MESSAGE_MAP()


// Обработчики сообщений MyDialog
BOOL MyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	doc->group.InitListBox(studentsList);
	OnLbnSelchangeList1();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // Исключение: страница свойств OCX должна возвращать значение FALSE
}

void MyDialog::OnLbnSelchangeList1()
{
	doc->group.UpdateListBox(&studentsList);
	int ind = studentsList.GetCaretIndex();

	if (studentsList.GetTextLen(0) <= 0)
		return;

	doc->group.ShowStudentInDialog(*this, ind);
}


void MyDialog::OnEnChangeEditSurname()
{
	UpdateData(true);
	if (studentsList.GetTextLen(0) > 0)
		doc->group.Students[studentsList.GetCaretIndex()]->Surname = editValueSurname;
	doc->group.UpdateListBox(&studentsList);
}


void MyDialog::OnEnChangeEditName()
{
	UpdateData(true);
	if (studentsList.GetTextLen(0) > 0)
		doc->group.Students[studentsList.GetCaretIndex()]->Name = editValueName;
	doc->group.UpdateListBox(&studentsList);
}


void MyDialog::OnEnChangeEditAge()
{
	UpdateData(true);
	if (studentsList.GetTextLen(0) > 0)
		doc->group.Students[studentsList.GetCaretIndex()]->Age = editValueAge;
	doc->group.UpdateListBox(&studentsList);
}


void MyDialog::OnEnChangeEditScholarship()
{
	Headman* headman = dynamic_cast<Headman*>(doc->group.Students[studentsList.GetCaretIndex()].get());
	UpdateData(true);
	if (studentsList.GetTextLen(0) > 0)
		headman->Scholarship = editValueScholarship;
	doc->group.UpdateListBox(&studentsList);
}


void MyDialog::OnBnClickedAddStudent()
{
	UpdateData(true);
	int ind = studentsList.GetCount();
	studentsList.ResetContent();
	auto student = make_shared<Student>();
	doc->group.Students.push_back(student);
	studentsList.SetCaretIndex(ind);
	OnLbnSelchangeList1();
}


void MyDialog::OnBnClickedAddHeadman()
{
	UpdateData(true);
	int ind = studentsList.GetCount();
	studentsList.ResetContent();
	auto headman = make_shared<Headman>();
	doc->group.Students.push_back(headman);
	studentsList.SetCaretIndex(ind);
	OnLbnSelchangeList1();
}


void MyDialog::OnBnClickedDeleteStudent()
{
	if (studentsList.GetTextLen(0) <= 0) { return; }
	doc->group.Students.erase(doc->group.Students.begin() + studentsList.GetCaretIndex());
	int ind = (studentsList.GetCaretIndex() + 1 == studentsList.GetCount()) ?
		studentsList.GetCaretIndex() - 1 : studentsList.GetCaretIndex();
	studentsList.DeleteString(studentsList.GetCaretIndex());
	studentsList.SetCaretIndex(ind);
	OnLbnSelchangeList1();
	if (studentsList.GetTextLen(0) <= 0)
	{
		editSurname.ShowWindow(SW_HIDE);
		editName.ShowWindow(SW_HIDE);
		textAge.ShowWindow(SW_HIDE);
		editAge.ShowWindow(SW_HIDE);
		checkHasJournal.ShowWindow(SW_HIDE);
		textScholarship.ShowWindow(SW_HIDE);
		editScholarship.ShowWindow(SW_HIDE);
	}
}


void MyDialog::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}


void MyDialog::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnCancel();
}


void MyDialog::OnBnClickedHasJournal()
{
	Headman* headman = dynamic_cast<Headman*>(doc->group.Students[studentsList.GetCaretIndex()].get());
	UpdateData(true);
	if (studentsList.GetTextLen(0) > 0)
		headman->HasJournal = checkValueHasJournal;
	doc->group.UpdateListBox(&studentsList);
}
