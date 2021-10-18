#include "pch.h"
#include "ProgrammerKondrikov.h"
#include "EmployeeKondrikov.h"
#include <iostream>

IMPLEMENT_SERIAL(ProgrammerKondrikov, EmployeeKondrikov, 0)

void ProgrammerKondrikov::printInfo()
{
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
	std::cin >> m_language;
}

void::ProgrammerKondrikov::Serialize(CArchive& ar)
{
	EmployeeKondrikov::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << m_workExperience;
		ar << CString(m_language.c_str());
	}
	else
	{
		CString tmp;
		ar >> m_workExperience;
		ar >> tmp;
		m_language = tmp;
	}
}