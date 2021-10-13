#ifndef STAFF_H
#define STAFF_H

#include <vector>
#include "EmployeeKondrikov.h"
#include "ProgrammerKondrikov.h"
#include <fstream>


class StaffKondrikov
{
private:
	vector<std::shared_ptr<EmployeeKondrikov>> staff;

public:

	StaffKondrikov();
	~StaffKondrikov();
	void addEmployee();
	void printStaff();
	void addProgrammer();
	void writeToFile();
	void readFromFile();
	void clear();
};

#endif
