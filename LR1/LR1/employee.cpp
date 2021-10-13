#include "employee.h"
#include <iostream>
#include <fstream>

using namespace std;


int EmployeeKondrikov::idGenerator = 1;

EmployeeKondrikov::EmployeeKondrikov(string name, string surname, short age, double salary)
	: m_name(name), m_surname(surname), m_age(age), m_salary(salary) 
{
	m_id = idGenerator++;
	cout << "\nEmployee()\n" << endl;
}

EmployeeKondrikov::~EmployeeKondrikov()
{
	cout << "\n~Employee()\n" << endl;
}

void EmployeeKondrikov::getEmployeeInfoInConsole()
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

void EmployeeKondrikov::writeInFile(ofstream& outFile)
{
	outFile << "Employee ID: " << m_id << endl <<
			   "Name: " << m_name << endl <<
			   "Surname: " << m_surname << endl <<
			   "Age: " << m_age << endl <<
			   "Salary: " << m_salary << endl << endl;
}

void EmployeeKondrikov::addFromFile(ifstream& inFile)
{
	inFile >> m_name >> m_surname >> m_age >> m_salary;
}