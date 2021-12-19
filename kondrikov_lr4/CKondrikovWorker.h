#pragma once
#include "framework.h"



// this class describes a worker
class CKondrikovWorker : public CObject
{

    
    

    private:
   // values
        double m_salary;
        int m_age;
        std::string m_name;
        std::string m_lastName;
        int m_workerId;

        static int s_id;


    public:
        DECLARE_SERIAL(CKondrikovWorker);


   // constructor
        CKondrikovWorker();

        //getters
        std::string getName();
        int id() const;
        double salary() const;
        int age() const;
        std::string name() const;
        std::string lastName() const;


   // (f)io functions
        virtual std::ostream& print(std::ostream& strstr);
        virtual void Serialize(CArchive& ar);
        

        virtual void setAge(int age);
        virtual void setName(std::string name);
        virtual void setSalary(double salary);
        virtual void setLastName(std::string lastName);


        virtual CKondrikovWorker& operator=(const CKondrikovWorker&);


        static void resetId();
};

