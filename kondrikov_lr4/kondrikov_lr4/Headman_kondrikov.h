#pragma once
#include "pch.h"
#include "Student_kondrikov.h"

class Headman :
	public Student
{
public:
	bool HasJournal = false;
	int Scholarship;
	DECLARE_SERIAL(Headman);
	void ShowInDialog(MyDialog& dialog);
	void ConsoleWrite(CDC* pDC, int& h);
	Headman();
	Headman(const string& name, const string& surname, const int& age, const bool& hasJournal, const int& scholarship);
	virtual ~Headman();
	void Serialize(CArchive& archive);
};