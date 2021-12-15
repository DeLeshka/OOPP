#include "pch.h"
#include "Student_kondrikov.h"
#include "kondrikov_MyDialog.h"

IMPLEMENT_SERIAL(Student, CObject, 1);

void Student::Serialize(CArchive& archive)
{
	CObject::Serialize(archive);
	
	if (archive.IsStoring())
		archive << Surname << Name << Age;
	else
		archive >> Surname >> Name >> Age;
}

CString Student::GetSurname() const
{
	return Surname;
}

void Student::ShowInDialog(MyDialog& dialog)
{
	dialog.editSurname.ShowWindow(SW_SHOW);
	dialog.editName.ShowWindow(SW_SHOW);
	dialog.textAge.ShowWindow(SW_SHOW);
	dialog.editAge.ShowWindow(SW_SHOW);
	dialog.editSurname.SetWindowTextA(Surname);
	dialog.editName.SetWindowTextA(Name);
	dialog.editAge.SetWindowTextA(to_string(Age).c_str());
	dialog.checkHasJournal.ShowWindow(SW_HIDE);
	dialog.textScholarship.ShowWindow(SW_HIDE);
	dialog.editScholarship.ShowWindow(SW_HIDE);
}

void Student::ConsoleWrite(CDC* pDC, int& h)
{
	CString str1 = _T("Студент: ") + Surname + _T(' ') + Name + _T(" - возраст: ") + to_string(Age).c_str();
	pDC->TextOut(0, h, str1);
	h += 40;
}

Student::Student()
{
	Surname = "Фамилия";
	Name = "Имя";
	Age = 0;
}

Student::Student(const string& name, const string& surname, const int& age)
{
	Surname = CString(name.c_str());
	Name = CString(surname.c_str());
	Age = age;
}

Student::~Student()
{
}