#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <fstream>

using namespace std;

class EmployeeKondrikov
{
private:

	static int idGenerator;
	int m_id;
	string m_name;
	string m_surname;
	short m_age;
	double m_salary;

public:

	EmployeeKondrikov(string name = "unknown", string surname = "unknown", short age = 0, double salary = 0.0);
	~EmployeeKondrikov();
	void getEmployeeInfoInConsole();
	void setEmployeeInfo();
	void writeInFile(ofstream& outFile);
	void addFromFile(ifstream& inFile);

};



#endif
