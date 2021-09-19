#include "employee.h"
#include "Staff.h"
#include <iostream>
#include <fstream>
#include <cassert>

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


inline std::string getString(std::string message)
{
    cout << "Please, enter " << message << ": ";
    string key;
    cin.clear();
    cin.ignore(32767, '\n');
    getline(cin, key);
    if (key == "")
        key = getString(message);
    return key;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Staff staff;
    while (true)
    {
        showMenu();
        switch (getAnswer())
        {
        case 1:
        {
            staff.addEmployee();
            break;
        }

        case 2:
        {
            staff.printStaff();
            break;

        case 3:
        {
            std::string fileName{ getString("an intput file name (without \".txt\")") + ".txt" };
            std::ifstream inFile(fileName);
            assert(inFile && "Output file couldn't be opened");
            staff.readFromFile(inFile);
            inFile.close();
            break;
        }

        case 4:
        {
            std::string fileName{ getString("an output file name (without \".txt\")") + ".txt" };
            std::ofstream outFile(fileName);
            assert(outFile && "Output file couldn't be opened");
            staff.writeToFile(outFile);
            outFile.close();
            break;
        }
            
        case 5:
            staff.clear();
            break;
        }

        case 0:
            return 0;

        }
    }


}



