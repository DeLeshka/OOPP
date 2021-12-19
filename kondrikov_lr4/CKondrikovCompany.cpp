#include "pch.h"
#include "CKondrikovCompany.h"




CKondrikovCompany::CKondrikovCompany()
{
    this->workers = {};
    this->lineCount = 0;
    this->maxLenghtOfStr = 0;
    this->outputText = "";
}

CKondrikovCompany::~CKondrikovCompany() {}



// adding
void CKondrikovCompany::addWorker(std::shared_ptr<CKondrikovWorker> worker)
{
   this->workers.push_back(worker);
   return;
}




// clearing
void CKondrikovCompany::removeWorkers()
{
    CKondrikovWorker::resetId(); 
    this->workers.clear();
    return;
}



std::vector<std::string> CKondrikovCompany::getShortData()
{
    std::vector<std::string> rtn;
    rtn.reserve(this->workers.size() );


    std::for_each(workers.begin(), workers.end(), [&rtn](std::shared_ptr<CKondrikovWorker> pWorker) {rtn.push_back( pWorker->getName() ); });
    return rtn;
}




void CKondrikovCompany::removeWorker(int id)
{
    this->workers.erase(std::find_if(this->workers.begin(), this->workers.end(), [&id](std::shared_ptr<CKondrikovWorker> pW) {return pW->id() == id; }));
}






// (f)io functions
void CKondrikovCompany::saveCompany(CArchive& ar)
{   

 
        ar << this->workers.size();

        std::for_each(this->workers.begin(), this->workers.end(),
            [&ar](std::shared_ptr<CKondrikovWorker> pWorker) { ar << pWorker.get(); });
 


    return;
}





void CKondrikovCompany::extractCompany(CArchive& ar)
{

    int number;
    ar >> number;
    this->workers.reserve(number);
    for (int i = 0; i < number; ++i) // in this cycle it's not itterations of container, we add new worker to container in every itteration
    {

        CKondrikovWorker* pWorker;
        ar >> pWorker;
        std::shared_ptr<CKondrikovWorker> spWorker(pWorker);
        this->workers.push_back(spWorker);

    }

    return;
}




void CKondrikovCompany::UpdateCompanyTextData()
{
    std::stringstream strstr;



    std::for_each(this->workers.begin(), this->workers.end(), 
        [&strstr](std::shared_ptr<CKondrikovWorker> pWorker) 
        { pWorker->print(strstr) << '\n'; } );



    std::string line;
    int count(0);
    unsigned int maxV(0);

    while (std::getline(strstr, line, '\n'))
    {
        if (maxV < line.length())    maxV = line.length();
        ++count;
    }
    
    this->lineCount = count;
    this->maxLenghtOfStr = maxV;
    this->outputText = strstr.str();


    return;
}




std::string CKondrikovCompany::printCompany()
{
    return this->outputText;
}



int CKondrikovCompany::getMaxLengthOfStr()
{
    return this->maxLenghtOfStr;
}


int CKondrikovCompany::getLineCount()
{
    return this->lineCount;
}



std::shared_ptr<CKondrikovWorker> CKondrikovCompany::getWorkerByID(int id)
{
    return *std::find_if(this->workers.begin(), this->workers.end(), [&id](std::shared_ptr<CKondrikovWorker> pWorker) { return pWorker->id() == id; });
}

