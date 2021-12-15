#include "pch.h"
#include "StaffKondrikov.h"
#include "EmployeeKondrikov.h"
#include "ProgrammerKondrikov.h"
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;




void StaffKondrikov::addEmployee()
{
	shared_ptr<EmployeeKondrikov> employeePtr = make_shared<EmployeeKondrikov>();
	employeePtr->setEmployeeInfo();
	staff.push_back(employeePtr);
}


void StaffKondrikov::addProgrammer()
{
	shared_ptr<EmployeeKondrikov> employeePtr = make_shared<ProgrammerKondrikov>();;
	employeePtr->setEmployeeInfo();
	staff.push_back(employeePtr);
}

void StaffKondrikov::printStaff()
{
	int length = staff.size();
	if (length == 0)
	{
		cout << "\nEmpty set.\n\n";
		return;
	}
	for (int i = 0; i < length; ++i)
	{
		staff[i]->printInfo(out);
	}

}

CArchive& employeeToCArchive(CArchive& ar, std::shared_ptr<EmployeeKondrikov> ptr)
{
	return ar << ptr.get();
}

void StaffKondrikov::saveStaff(CArchive& ar)
{
	ar << this->staff.size();

	for_each(this->staff.begin(), this->staff.end(),
		std::bind(employeeToCArchive, ref(ar), std::placeholders::_1));
}

ostream& addEmployeeInfo(ostream& out, shared_ptr<EmployeeKondrikov> pEmployee)
{
	pEmployee->printInfo(out);
	out << '\n';
	return out;
}

int StaffKondrikov::getMaxLengthOfstr()
{


	std::stringstream strstr;
	std::for_each(this->staff.begin(), this->staff.end(), std::bind(addEmployeeInfo, std::ref(strstr), std::placeholders::_1));


	std::string line;
	int maxV(0);


	while (std::getline(strstr, line, '\n'))
	{
		if (maxV < line.length())    maxV = line.length();
	}

	return maxV;
}