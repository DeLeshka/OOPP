//об€зательно первыми include'ами, все до них игнорируетс€, выдава€ ошибку компил€ции
#include "pch.h"
#include "framework.h"
#include <iostream>
#include "EmployeeKondrikov.h"

using namespace std;

IMPLEMENT_SERIAL(EmployeeKondrikov, CObject, 0)

int EmployeeKondrikov::idGenerator = 1;

EmployeeKondrikov::EmployeeKondrikov(CString name, CString surname, short age, double salary)
	: m_name(name), m_surname(surname), m_age(age), m_salary(salary)
{
	m_id = idGenerator++;
}


void EmployeeKondrikov::printInfo(ostream& out)
{
	out << "\nEmployee ID: " << m_id << endl <<
		"Name: " << m_name << endl <<
		"Surname: " << m_surname << endl <<
		"Age: " << m_age << endl <<
		"Salary: " << m_salary << endl;
}

void EmployeeKondrikov::setEmployeeInfo()
{
	string tmp;
	cout << "\nName: ";
	cin >> tmp;
	m_name = CString(tmp.c_str());
	cout << "Surname: ";
	cin >> tmp;
	m_surname = CString(tmp.c_str());
	cout << "Age: ";
	cin >> m_age;
	cout << "Salary: ";
	cin >> m_salary;
}


void EmployeeKondrikov::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_id;
		ar << m_name;
		ar << m_surname;
		ar << m_age;
		ar << m_salary;
	}
	else
	{
		ar >> m_id;
		ar >> m_name;
		ar >> m_surname;
		ar >> m_age;
		ar >> m_salary;
	}
}