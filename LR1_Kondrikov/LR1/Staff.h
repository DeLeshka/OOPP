#ifndef STAFF_H
#define STAFF_H

#include <vector>
#include "employee.h"
#include <fstream>

using namespace std;

class Staff
{
private:
	vector<Employee*> staff;

public:

	Staff();
	~Staff();
	void addEmployee();
	void printStaff();
	void writeToFile(ofstream& outFile);
	void readFromFile(ifstream& inFile);
};

#endif