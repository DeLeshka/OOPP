#include "pch.h"
#include "Student_Kondrikov.h"

IMPLEMENT_SERIAL(Student, CObject, 1);

void Student::Serialize(CArchive& archive)
{
	CObject::Serialize(archive);
	
	if (archive.IsStoring())
		archive << Surname << Name << Age;
	else
		archive >> Surname >> Name >> Age;
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