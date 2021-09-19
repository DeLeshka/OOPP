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
	int length = staff.size();
	if (length == 0)
	{
		cout << "\nEmpty set.\n\n";
		return;
	}
	for (int i = 0; i < length; ++i)
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

void Staff::readFromFile(ifstream& inFile)
{
	for (int i = 0; i < 3; ++i)
	{
		Employee* employeePtr = new Employee;
		employeePtr->addFromFile(inFile);
		staff.push_back(employeePtr);
	}
}

void Staff::clear()
{
	for (int i = 0; i < staff.size(); ++i)
	{
		delete staff[i];
	}
	staff.clear();
}