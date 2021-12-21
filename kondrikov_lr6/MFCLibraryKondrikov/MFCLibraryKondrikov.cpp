// MFCLibraryKondrikov.cpp: определяет процедуры инициализации для библиотеки DLL.
//

#include "pch.h"
#include "framework.h"
#include "MFCLibraryKondrikov.h"
#include "Group_Kondrikov.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: если эта библиотека DLL динамически связана с библиотеками DLL MFC,
//		все функции, экспортированные из данной DLL-библиотеки, которые выполняют вызовы к
//		MFC, должны содержать макрос AFX_MANAGE_STATE в
//		самое начало функции.
//
//		Например:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// тело нормальной функции
//		}
//
//		Важно, чтобы данный макрос был представлен в каждой
//		функции до вызова MFC.  Это означает, что
//		должен стоять в качестве первого оператора в
//		функции и предшествовать даже любым объявлениям переменных объекта,
//		поскольку их конструкторы могут выполнять вызовы к MFC
//		DLL.
//
//		В Технических указаниях MFC 33 и 58 содержатся более
//		подробные сведения.
//

// CMFCLibraryKondrikovApp

BEGIN_MESSAGE_MAP(CMFCLibraryKondrikovApp, CWinApp)
END_MESSAGE_MAP()


// Создание CMFCLibraryKondrikovApp

CMFCLibraryKondrikovApp::CMFCLibraryKondrikovApp()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CMFCLibraryKondrikovApp

CMFCLibraryKondrikovApp theApp;


// Инициализация CMFCLibraryKondrikovApp

BOOL CMFCLibraryKondrikovApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

struct StudentStruct
{
	char surname[255];
	char name[255];
	int age;
};

struct HeadmanStruct
{
	char surname[255];
	char name[255];
	int age;
	bool hasJournal;
	int scholarship;
};

Group group;

extern "C" _declspec(dllexport) int __stdcall GetGroupSize()
{
	return group.Students.size();
}

extern "C" _declspec(dllexport) void __stdcall CreateStudent()
{
	auto student = make_shared<Student>();
	group.Students.push_back(student);
}

extern "C" _declspec(dllexport) void __stdcall DeleteStudent(int id)
{
	group.Students.erase(group.Students.begin() + id);
}

extern "C" _declspec(dllexport) void __stdcall CreateHeadman()
{
	auto headman = make_shared<Headman>();
	group.Students.push_back(headman);
}

extern "C" _declspec(dllexport) BOOL __stdcall IsHeadman(int id)
{
	Headman* headman = dynamic_cast<Headman*>(group.Students[id].get());
	return (headman) ? 1 : 0;
}

extern "C" _declspec(dllexport) void __stdcall GetStudent(StudentStruct& student, int id)
{
	strcpy_s(student.surname, group.Students[id]->Surname);
	strcpy_s(student.name, group.Students[id]->Name);
	student.age = group.Students[id]->Age;
}

extern "C" _declspec(dllexport) void __stdcall GetHeadman(HeadmanStruct& headman, int id)
{
	Headman* hd = dynamic_cast<Headman*>(group.Students[id].get());
	strcpy_s(headman.surname, hd->Surname);
	strcpy_s(headman.name, hd->Name);
	headman.age = hd->Age;
	headman.hasJournal = hd->HasJournal;
	headman.scholarship = hd->Scholarship;
}

extern "C" _declspec(dllexport) void __stdcall SetStudent(StudentStruct& student, int id)
{
	group.Students[id]->Surname = student.surname;
	group.Students[id]->Name = student.name;
	group.Students[id]->Age = student.age;
}

extern "C" _declspec(dllexport) void __stdcall SetHeadman(HeadmanStruct& headman, int id)
{
	Headman* hd = dynamic_cast<Headman*>(group.Students[id].get());
	hd->Surname = headman.surname;
	hd->Name = headman.name;
	hd->Age = headman.age;
	hd->HasJournal = headman.hasJournal;
	hd->Scholarship = headman.scholarship;
}

extern "C" _declspec(dllexport) void __stdcall SaveToFile(const char* filename)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CFile f(CString(filename), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&f, CArchive::store);
	group.SaveToFile(archive);
	archive.Close();
	f.Close();
}

extern "C" _declspec(dllexport) void __stdcall LoadFromFile(const char* filename)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CFile f(CString(filename), CFile::modeRead);
	CArchive archive(&f, CArchive::load);
	group.LoadFromFile(archive);
	archive.Close();
	f.Close();
}