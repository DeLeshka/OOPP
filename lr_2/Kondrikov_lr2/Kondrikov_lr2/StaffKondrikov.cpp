#include "pch.h"
#include "StaffKondrikov.h"
#include "EmployeeKondrikov.h"
#include "ProgrammerKondrikov.h"
#include <iostream>

using namespace std;


StaffKondrikov::~StaffKondrikov()
{
	//больше не требуетс€: shared_ptr сам удалит объекты, когда все указатели на него выйдут из области видимости

	//for (EmployeeKondrikov* employeePtr : staff)
	//{
	//	delete employeePtr;
	//}
	cout << "~Staff()\n";
}

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
		staff[i]->printInfo();
	}

}

void StaffKondrikov::writeToFile()
{
	string fileName;
	cout << "Please enter the file name:" << endl;
	cin >> fileName;
	fileName = fileName + ".dat";
	CFile f(CString(fileName.c_str()), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&f, CArchive::store);
	ar << staff.size();
	for (auto& pObj : staff)
	{
		EmployeeKondrikov* tmpPtr = pObj.get();
		ar << tmpPtr;
	}
	staff.clear();
	cout << "\nSuccessfull writing\n\n";
}

void StaffKondrikov::readFromFile()
{
	string fileName;
	cout << "Please enter the file name:" << endl;
	cin >> fileName;
	fileName = fileName + ".dat";
	CFile f(CString(fileName.c_str()), CFile::modeRead);
	CArchive ar(&f, CArchive::load);
	int sizeOfList;
	ar >> sizeOfList;
	for (int i = 0; i < sizeOfList; i++)
	{
		EmployeeKondrikov* tmpPtr;
		ar >> tmpPtr;
		shared_ptr<EmployeeKondrikov> tmpShared(tmpPtr);
		staff.push_back(tmpShared);
	}
	cout << "\nSuccessfull reading\n\n";
}

void StaffKondrikov::clear()
{
	int length = staff.size();

	//больше не требуетс€: shared_ptr сам удалит объекты, когда все указатели на него выйдут из области видимости
	/*for (int i = 0; i < length; ++i)
	{
		delete staff[i];
	}*/

	staff.clear();
	cout << "\nContainer cleansed. " << length << " objects have been deleted from dynamic memory.\n\n";
}