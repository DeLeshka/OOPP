#include "pch.h"
#include "ProgrammerKondrikov.h"
#include "EmployeeKondrikov.h"
#include <iostream>

IMPLEMENT_SERIAL(ProgrammerKondrikov, EmployeeKondrikov, 0)

void ProgrammerKondrikov::printInfo()
{
	std::cout << "programmer\n";
	this->EmployeeKondrikov::printInfo();
	std::cout << "Work experience: " << m_workExperience << std::endl <<
		"Language: " << m_language << std::endl <<std::endl;
}

void ProgrammerKondrikov::setEmployeeInfo()
{
	this->EmployeeKondrikov::setEmployeeInfo();
	std::cout << "Enter work experience: ";
	std::cin >> m_workExperience;
	std::cout << "Enter prefered language: ";
	string tmp;
	cin >> tmp;
	m_language = CString(tmp.c_str());;
}

void::ProgrammerKondrikov::Serialize(CArchive& ar)
{
	this->EmployeeKondrikov::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << m_workExperience;
		ar << m_language;
	}
	else
	{
		ar >> m_workExperience;
		ar >>m_language;
	}
}