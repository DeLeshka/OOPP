#include "employee.h"
#include <iostream>
#include <fstream>

using namespace std;

int Employee::idGenerator = 1;

Employee::Employee(string name, string surname, short age, double salary)
	: m_name(name), m_surname(surname), m_age(age), m_salary(salary) 
{
	m_id = idGenerator++;
	cout << "\nEmployee()\n" << endl;
}

Employee::~Employee() 
{
	cout << "\n~Employee()\n" << endl;
}

void Employee::getEmployeeInfoInConsole()
{
	cout << "Employee ID: " << m_id << endl <<
				 "Name: " << m_name << endl <<
				 "Surname: " << m_surname << endl <<
				 "Age: " << m_age << endl <<
				 "Salary: " << m_salary << endl << endl;
}

void Employee::setEmployeeInfo()
{
	cout << "Name: ";
	cin >> m_name;
	cout << "Surname: ";
	cin >> m_surname;
	cout << "Age: ";
	cin >> m_age;
	cout << "Salary: ";
	cin >> m_salary;
	cout << endl;
}

void Employee::writeInFile(ofstream& outFile)
{
	outFile << "Employee ID: " << m_id << endl <<
			   "Name: " << m_name << endl <<
			   "Surname: " << m_surname << endl <<
			   "Age: " << m_age << endl <<
			   "Salary: " << m_salary << endl << endl;
}