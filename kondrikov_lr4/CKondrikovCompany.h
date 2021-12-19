#pragma once
#include "framework.h"
#include "CKondrikovWorker.h"





class CKondrikovCompany
{
    

    public:
        CKondrikovCompany();
        ~CKondrikovCompany();
        void addWorker(std::shared_ptr<CKondrikovWorker> worker);
        void removeWorkers();
        std::vector<std::string> getShortData();
        void removeWorker(int id);


   // (f)io functions
        void saveCompany(CArchive& ar);
        void extractCompany(CArchive& ar);

        // block size methods
        void UpdateCompanyTextData();
        std::string printCompany();
        int getLineCount();
        int getMaxLengthOfStr();

        std::shared_ptr<CKondrikovWorker> getWorkerByID(int);

    private:
        std::vector< std::shared_ptr<CKondrikovWorker> > workers;

        std::string outputText;
        int lineCount;
        int maxLenghtOfStr;

};
