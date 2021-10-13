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
	Employee* employeePtr = new Employee();
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
	int lenFile;
	inFile >> lenFile;
	for (int i = 0; i < lenFile; ++i)
	{
		Employee* employeePtr = new Employee;
		employeePtr->addFromFile(inFile);
		staff.push_back(employeePtr);
	}
	cout << "\nReading was successfull." << endl << endl;
}

void Staff::clear()
{
	int length = staff.size();
	for (int i = 0; i < length; ++i)
	{
		delete staff[i];
	}
	staff.clear();
	cout << "\nContainer cleansed. " << length << " objects have been deleted from dynamic memory.\n\n";
}