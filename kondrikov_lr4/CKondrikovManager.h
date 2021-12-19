#pragma once
#include "framework.h"
#include "CKondrikovWorker.h"

class CKondrikovManager : public CKondrikovWorker
{
    DECLARE_SERIAL(CKondrikovManager);

    private:
        int currentTasksNum;
        std::string m_slogan;
    

    public:

        CKondrikovManager();
        virtual ~CKondrikovManager();

        virtual std::ostream& print(std::ostream& strstr);


        virtual void Serialize(CArchive& ar);

        virtual int tasks() const;
        virtual std::string slogan() const;

        virtual CKondrikovManager& operator=(const CKondrikovManager&);

        virtual void setTasks(int tasks);
        virtual void setSlogan(std::string slogan);

        

};