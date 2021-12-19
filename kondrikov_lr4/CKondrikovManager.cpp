
#include "pch.h"
#include "CKondrikovManager.h"




IMPLEMENT_SERIAL(CKondrikovManager, CKondrikovWorker, VERSIONABLE_SCHEMA | 0);

CKondrikovManager::CKondrikovManager() : CKondrikovWorker::CKondrikovWorker()
{

	this->currentTasksNum = 0;
	this->m_slogan = "";

}

CKondrikovManager::~CKondrikovManager()
{
}




std::ostream& CKondrikovManager::print(std::ostream& strstr)
{

	return this->CKondrikovWorker::print(strstr)
		<< "Current task's number: " << this->currentTasksNum << "\n"
		<< "Slogan: " << this->m_slogan << "\n" 
		<< "This worker is manager! \n";

}




//void CKondrikovManager::consoleGet()
//{
//
//	this->CKondrikovWorker::consoleGet();
//	std::cout << "Please, enter number of tasks: ";
//	input(this->currentTasksNum);
//	std::cout << "Please, enter slogan: ";
//	input(this->m_slogan);
//	return;
//
//}

void CKondrikovManager::Serialize(CArchive& ar)
{

	CKondrikovWorker::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << this->currentTasksNum;
		ar << CString(this->m_slogan.c_str(), this->m_slogan.length());
	}
	else
	{
		ar >> this->currentTasksNum;

		CString buf;
		ar >> buf;
		this->m_slogan = std::string(buf);
		
	}
	return;
}

int CKondrikovManager::tasks() const
{
	return this->currentTasksNum;
}

std::string CKondrikovManager::slogan() const
{
	return this->m_slogan;
}

CKondrikovManager& CKondrikovManager::operator=(const CKondrikovManager& Manager)
{
	CKondrikovWorker::operator=(Manager);
	this->m_slogan = Manager.m_slogan;
	this->currentTasksNum = Manager.currentTasksNum;
	return *this;
}

void CKondrikovManager::setTasks(int tasks)
{
	this->currentTasksNum = tasks;
	return;
}

void CKondrikovManager::setSlogan(std::string slogan)
{
	this->m_slogan = slogan;
}


//
//void CKondrikovManager::save(std::ofstream& fout)
//{
//	this->CKondrikovWorker::save(fout);
//	fout << this->currentTasksNum << std::endl << this->m_slogan << std::endl;
//	return;
//}
//
//
//void CKondrikovManager::extract(std::ifstream& fin)
//{
//
//	this->CKondrikovWorker::extract(fin);
//	fin >> this->currentTasksNum;
//	fin >> this->m_slogan;
//	return;
//
//
//}