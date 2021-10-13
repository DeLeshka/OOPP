// Kondrikov_lr2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "framework.h"
#include "Kondrikov_lr2.h"
#include "StaffKondrikov.h"
#include <cassert>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


using namespace std;

void showMenu()
{
    cout << "1. Add an employee.\n" <<
        "2. Show list of employees.\n" <<
        "3. Read list of employees from file.\n" <<
        "4. Write list of employees in file.\n" <<
        "5. Clear list of employees.\n" <<
        "0. Exit.\n\n" << endl;
}

int getAnswer()
{
    int answer;
    cout << "Select an operation: ";
    while ((cin >> answer).fail() || !(answer > 0 && answer < 6 || answer == 0))
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Please, input a valid answer: ";
    }
    return answer;
}



// Единственный объект приложения

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // инициализировать MFC, а также печать и сообщения об ошибках про сбое
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: вставьте сюда код для приложения.
            wprintf(L"Критическая ошибка: сбой при инициализации MFC\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: вставьте сюда код для приложения.
            setlocale(LC_ALL, "Russian");
            StaffKondrikov staff;
            while (true)
            {
                showMenu();
                switch (getAnswer())
                {
                case 1:
                    staff.addEmployee();
                    break;

                case 2:
                    staff.printStaff();
                    break;

                case 3:        
                    staff.readFromFile();
                    break;

                case 4:
                    staff.writeToFile();
                    break;

                case 5:
                    staff.clear();
                    break;

                case 6:
                    staff.addProgrammer();
                    break;

                case 0:
                    return 0;

                }
            }
        }
    }
    else
    {
        // TODO: измените код ошибки в соответствии с потребностями
        wprintf(L"Критическая ошибка: сбой GetModuleHandle\n");
        nRetCode = 1;
    }

    return nRetCode;
}
