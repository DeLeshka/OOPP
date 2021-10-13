#ifndef PROGRAMMERKONDRIKOV_H
#define PROGRAMMERKONDRIKOV_H

#include <string>
#include "EmployeeKondrikov.h"
using namespace std;

class ProgrammerKondrikov : public EmployeeKondrikov
{
private:
	double m_workExperience;
	string m_language;

public:
	DECLARE_SERIAL(ProgrammerKondrikov);

	ProgrammerKondrikov(string name = "unknown", string surname = "unknown", short age = 0, double salary = 0.0, double workExperience = 0.0, string language = "unknown") :
		EmployeeKondrikov(name, surname, age, salary), m_workExperience(workExperience), m_language(language)
	{}

	virtual void printInfo() override;
	virtual void setEmployeeInfo() override;
	virtual void Serialize(CArchive& ar) override;
};

#endif
