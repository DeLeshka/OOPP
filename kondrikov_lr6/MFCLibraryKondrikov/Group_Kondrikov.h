#pragma once
#include "pch.h"
#include "Student_Kondrikov.h"
#include "Headman_Kondrikov.h"

class Group
{
	int Number;

public:
	vector<shared_ptr<Student>> Students;
	void ConsoleWrite(CDC* pDC, int& h);
	void LoadFromFile(CArchive& ar);
	void SaveToFile(CArchive& ar);
	Group(const int& number, const vector<shared_ptr<Student>>& students);
	Group();
	void Clear();
	void AddStudent();
	void AddHeadman();
};