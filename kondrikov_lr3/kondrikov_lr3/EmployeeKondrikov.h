#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#pragma region MFC Serialization
#include "pch.h"
#include "framework.h"
#include <string> 
#include <atlstr.h>
#include <sstream>

using namespace std;

class EmployeeKondrikov: public CObject
{
private:

	static int idGenerator;
	int m_id;
	CString m_name;
	CString m_surname;
	short m_age;
	double m_salary;

public:
	DECLARE_SERIAL(EmployeeKondrikov);

	//EmployeeKondrikov();
	EmployeeKondrikov(CString name = "unknown", CString surname = "unknown", short age = 0, double salary = 0.0);

	//виртуализируем консольный ввод/вывод, чтобы потомки по указателю на родительский класс печатали свою версию 
	virtual void printInfo(ostream& out);
	virtual void setEmployeeInfo();
	virtual void Serialize(CArchive& ar);
};



#endif


