
#include "pch.h"
#include "CKondrikovWorker.h"


IMPLEMENT_SERIAL(CKondrikovWorker, CObject, 0);


int CKondrikovWorker::s_id = 1;

void CKondrikovWorker::resetId()
{
    CKondrikovWorker::s_id = 1;
    return;
}

// constructor
CKondrikovWorker::CKondrikovWorker() : CObject::CObject()
{

    this->m_workerId = CKondrikovWorker::s_id;
    this->m_age = 0;
    this->m_salary = 0.0;
    this->m_name = "";
    this->m_lastName = "";

    ++CKondrikovWorker::s_id;

}

std::string CKondrikovWorker::getName()
{
    std::stringstream ss;
    ss << "ID: " << this->m_workerId << " " << this->m_name;
    return ss.str();
}

int CKondrikovWorker::id() const
{
    return this->m_workerId;
}

double CKondrikovWorker::salary() const
{
    return this->m_salary;
}

int CKondrikovWorker::age() const
{
    return this->m_age;
}

std::string CKondrikovWorker::name() const
{
    return this->m_name;
}

std::string CKondrikovWorker::lastName() const
{
    return m_lastName;
}






// (f)io functions
std::ostream& CKondrikovWorker::print(std::ostream& strstr)
{
    return strstr << "ID: " << this->m_workerId << "\n"
        << "Name: " << this->m_name << "\n"
        << "Last name: " << this->m_lastName << "\n"
        << "Age: " << this->m_age << "\n"
        << "Salary: " << this->m_salary << "\n";
}



//void CKondrikovWorker::consoleGet()
//{
    //std::cout << "Enter name, please: ";
    //    std::cin >> this->name;

    //    std::cout << "Enter last name, please: ";
    //    std::cin >> this->lastName;

    //    std::cout << "Enter age, please: ";
    //    std::cin >> this->age;

    //    std::cout << "Enter salary, please: ";
    //    std::cin >> this->lastName;

    //++CKondrikovWorker::s_id;
    //this->workerId = CKondrikovWorker::s_id;
//
//    return;
//}






void CKondrikovWorker::Serialize(CArchive& ar)
{

    if (ar.IsStoring())
    {
        ar << CString(this->m_name.c_str(), this->m_name.length());
        ar << CString(this->m_lastName.c_str(), this->m_lastName.length());
        ar << this->m_age;
        ar << this->m_salary;
        ar << this->m_workerId;
    }
    else
    {   

        CString buf;

        ar >> buf;
        this->m_name = std::string(buf);

        ar >> buf;
        this->m_lastName = std::string(buf);

        ar >> this->m_age;
        ar >> this->m_salary;
        ar >> this->m_workerId;
    }

}

void CKondrikovWorker::setAge(int age)
{
    this->m_age = age;
    return;
}

void CKondrikovWorker::setName(std::string name)
{
    this->m_name = name;
    return;
}

void CKondrikovWorker::setSalary(double salary)
{
    this->m_salary = salary;
}

void CKondrikovWorker::setLastName(std::string lastName)
{
    this->m_lastName = lastName;
    return;
}

CKondrikovWorker& CKondrikovWorker::operator=(const CKondrikovWorker& Worker)
{
    this->m_age = Worker.m_age;
    this->m_name = Worker.m_name;
    this->m_lastName = Worker.m_lastName;
    this->m_salary = Worker.m_salary;
    this->m_workerId = Worker.m_workerId;
    return *this;
}


//
//
//void CKondrikovWorker::save(std::ofstream& fout)
//{
//	fout << this->name << std::endl
//    << this->lastName << std::endl
//    << this->age << std::endl
//    << this->salary << std::endl
//    << this->workerId << std::endl;
//    return;
//}
//
//
//
//
//
//void CKondrikovWorker::extract(std::ifstream& fin)
//{   
//    fin >> this->name;
//    fin >> this->lastName;
//    fin >> this->age;
//    fin >> this->salary;
//    fin >> this->workerId;
//    CKondrikovWorker::s_id = this->workerId; // prb should add it in the end of the fut cycle
//    return;
//}
//
//
//
