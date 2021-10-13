#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#pragma region MFC Serialization
#include <string>
#include <fstream>
#include "pch.h"
#include "framework.h"

using namespace std;

class EmployeeKondrikov: public CObject
{
private:

	static int idGenerator;
	int m_id;
	string m_name;
	string m_surname;
	short m_age;
	double m_salary;

public:
	DECLARE_SERIAL(EmployeeKondrikov);

	EmployeeKondrikov(string name = "unknown", string surname = "unknown", short age = 0, double salary = 0.0);
	~EmployeeKondrikov();

	//�������������� ���������� ����/�����, ����� ������� �� ��������� �� ������������ ����� �������� ���� ������ 
	virtual void printInfo();
	virtual void setEmployeeInfo();
	virtual void Serialize(CArchive& ar);
};



#endif


