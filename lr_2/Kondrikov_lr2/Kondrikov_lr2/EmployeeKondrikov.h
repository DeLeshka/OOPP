#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#pragma region MFC Serialization
#include "pch.h"
#include "framework.h"
#include <string> 


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
	/*~EmployeeKondrikov() { cout << "\n~Employee()\n" << endl; }*/

	//виртуализируем консольный ввод/вывод, чтобы потомки по указателю на родительский класс печатали свою версию 
	virtual void printInfo();
	virtual void setEmployeeInfo();
	virtual void Serialize(CArchive& ar);
};



#endif


