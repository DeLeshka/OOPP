#pragma once
#include "pch.h"

class Student : public CObject
{
public:
	CString Name;
	CString Surname;
	int Age;
	DECLARE_SERIAL(Student);
	virtual void ConsoleWrite(CDC* pDC, int& h);
	Student();
	Student(const string& name, const string& surname, const int& age);
	virtual ~Student();
	virtual void Serialize(CArchive& archive);
};