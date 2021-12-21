#include "pch.h"
#include "Headman_Kondrikov.h"

IMPLEMENT_SERIAL(Headman, Student, VERSIONABLE_SCHEMA | 0);

void Headman::ConsoleWrite(CDC* pDC, int& h)
{
	CString str1 = _T("Староста: ") + Surname + _T(' ') + Name + _T(" - возраст: ") + to_string(Age).c_str();
	pDC->TextOut(0, h, str1);
	h += 25;
	CString substr = HasJournal ? _T("с журналом, ") : _T("без журнала, ");
	CString str2 = _T("    ") + substr + _T("бонусная стипендия: ") + to_string(Scholarship).c_str();
	pDC->TextOut(0, h, str2);
	h += 40;
}

Headman::Headman()
{
	Surname = "Фамилия";
	Name = "Имя";
	Age = 0;
	HasJournal = false;
	Scholarship = 0;
}

Headman::Headman(const string& name, const string& surname, const int& age, const bool& hasJournal, const int& scholarship)
{
	Surname = CString(name.c_str());
	Name = CString(surname.c_str());
	Age = age;
	HasJournal = hasJournal;
	Scholarship = scholarship;
}

Headman::~Headman()
{
}

void Headman::Serialize(CArchive& archive)
{
	Student::Serialize(archive);

	if (archive.IsStoring())
		archive << HasJournal << Scholarship;
	else
		archive >> HasJournal >> Scholarship;
}