//об€зательно первыми include'ами, все до них игнорируетс€, выдава€ ошибку компил€ции
#include "pch.h"
#include "framework.h"

#include "EmployeeKondrikov.h"

using namespace std;

IMPLEMENT_SERIAL(EmployeeKondrikov, CObject, 0)

int EmployeeKondrikov::idGenerator = 1;

EmployeeKondrikov::EmployeeKondrikov(string name, string surname, short age, double salary)
	: m_name(name), m_surname(surname), m_age(age), m_salary(salary)
{
	m_id = idGenerator++;
	cout << "\nEmployee()\n" << endl;
}


void EmployeeKondrikov::printInfo()
{
	cout << "\nEmployee ID: " << m_id << endl <<
		"Name: " << m_name << endl <<
		"Surname: " << m_surname << endl <<
		"Age: " << m_age << endl <<
		"Salary: " << m_salary << endl << endl;
}

void EmployeeKondrikov::setEmployeeInfo()
{
	cout << "\nName: ";
	cin >> m_name;
	cout << "Surname: ";
	cin >> m_surname;
	cout << "Age: ";
	cin >> m_age;
	cout << "Salary: ";
	cin >> m_salary;
	cout << "\nEmployee added.\n" << endl;
}


void EmployeeKondrikov::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_id;
		ar << CString(m_name.c_str());
		ar << CString(m_surname.c_str());
		ar << m_age;
		ar << m_salary;
	}
	else
	{
		CString tmp;
		ar >> m_id;
		ar >> tmp;
		m_name = tmp;
		ar >> tmp;
		m_surname = tmp;


	}
}