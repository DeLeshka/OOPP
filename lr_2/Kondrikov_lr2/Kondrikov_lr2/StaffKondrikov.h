#ifndef STAFF_H
#define STAFF_H

#include <vector>
#include "EmployeeKondrikov.h"


class StaffKondrikov
{
private:
	vector<std::shared_ptr<EmployeeKondrikov>> staff;

public:

	StaffKondrikov();
	~StaffKondrikov();
	void addEmployee();
	void addProgrammer();
	void printStaff();
	void writeToFile();
	void readFromFile();
	void clear();
};

#endif
