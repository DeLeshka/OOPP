#include "employee.h"
#include "Staff.h"
#include <iostream>
#include <fstream>

using namespace std;

Staff::Staff()
{
	cout << "Staff()\n";
}

Staff::~Staff()
{
	for (Employee* employeePtr : staff)
	{
		delete employeePtr;
	}
	cout << "~Staff()\n";
}

void Staff::addEmployee()
{
	Employee* employeePtr = new Employee;
	employeePtr->setEmployeeInfo();
	staff.push_back(employeePtr);
}


void Staff::printStaff()
{

	for (int i = 0; i < staff.size(); ++i)
	{
		staff[i]->getEmployeeInfoInConsole();
	}

}

void Staff::writeToFile(ofstream& outFile)
{
	for (int i = 0; i < staff.size(); ++i)
	{
		staff[i]->writeInFile(outFile);
	}
}