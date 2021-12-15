#pragma once
#include "pch.h"
#include "Student_kondrikov.h"
#include "Headman_kondrikov.h"

class Group
{
	int Number;

public:
	vector<shared_ptr<Student>> Students;
	void ConsoleWrite(CDC* pDC, int& h);
	void InitListBox(CListBox& studentsList);
	void UpdateListBox(CListBox* studentsList);
	void ShowStudentInDialog(MyDialog& dialog, const int& index);
	void LoadFromFile(CArchive& ar);
	void SaveToFile(CArchive& ar);
	Group(const int& number, const vector<shared_ptr<Student>>& students);
	Group();
	void Clear();
	void AddStudent();
	void AddHeadman();
};