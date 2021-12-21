#include "pch.h"
#include "Group_Kondrikov.h"

void Group::ConsoleWrite(CDC* pDC, int& h)
{
    CString str1 = _T(" - Группа №");
    str1 += to_string(Number).c_str();
    pDC->TextOut(0, h, str1);
    h += 40;
    if (Students.empty())
        pDC->TextOut(0, h, _T("Группа пуста\n"));
    else
        // Это через bind
        for_each(Students.begin(), Students.end(), bind(&Student::ConsoleWrite, placeholders::_1, pDC, ref(h)));
}

void Group::LoadFromFile(CArchive& ar)
{
    ar >> Number;
    int groupSize;
    ar >> groupSize;
    Students.clear();
    Students.reserve(groupSize);
    for (int i = 0; i < groupSize; i++)
    {
        Student* student;
        ar >> student;
        Students.push_back(shared_ptr<Student>(student));
    }
}

void ArchiveStudent(CArchive& archive, shared_ptr<Student> student)
{
    archive << student.get();
}

void Group::SaveToFile(CArchive& ar)
{
    ar << Number;
    ar << Students.size();
    // Это через bind
    // for_each(Students.begin(), Students.end(), bind(ArchiveStudent, ref(ar), placeholders::_1));
    // Это через лямбда
    for_each(Students.begin(), Students.end(), [&ar](shared_ptr<Student> student) { ar << student.get(); });

}

Group::Group(const int& number, const vector<shared_ptr<Student>>& students)
{
    Number = number;
    Students = students;
}

Group::Group()
{
    Number = 0;
}

void Group::Clear()
{
    cout << "Вы действительно хотите удалить весь список группы? (введите 0 для подтверждения)\n";
    int input;
    if ((cin >> input).fail() || input != 0)
    {
        cout << "Отмена...\n";
        return;
    }
    else
    {
        Students.clear();
        cout << "Операция удаления прошла успешно\n";
    }
}

void Group::AddStudent()
{
    Student* student = new Student();
    //student->ConsoleRead(cin);
    Students.push_back(shared_ptr<Student>(student));
}

void Group::AddHeadman()
{
    Headman* headman = new Headman();
    //headman->ConsoleRead(cin);
    Students.push_back(shared_ptr<Headman>(headman));
}