#ifndef STAFF_H
#define STAFF_H

#include <vector>
#include "EmployeeKondrikov.h"
#include <memory>
#include <sstream>

class StaffKondrikov
{
private:
	vector<std::shared_ptr<EmployeeKondrikov>> staff;

public:
	void addEmployee();
	void addProgrammer();
	void saveStaff(CArchive& ar);
	void printStaff();
	int getMaxLengthOfstr();
};

#endif
