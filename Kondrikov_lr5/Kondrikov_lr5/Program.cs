using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kondrikov_lr5
{
    class Program
    {
        static void ShowMenu()
        {
        Console.Write("\n1. Add an employee.\n" +
        "2. Show list of employees.\n" +
        "3. Read list of employees from file.\n" +
        "4. Write list of employees in file.\n" +
        "5. Clear list of employees.\n" +
        "6. Add a programmer\n" +
        "0. Exit.\n\n");
        }

        static void Main(string[] args)
        {
            int operation;
            StaffKondrikov staffKondrikov = new StaffKondrikov(new List<EmployeeKondrikov>());
            while (true)
            {
                ShowMenu();
                operation = Convert.ToInt32(Console.ReadLine());
                switch (operation)
                {
                    case 1:
                        staffKondrikov.AddEmployee();
                        break;
                    case 2:
                        staffKondrikov.PrintStaff();
                        break;
                    case 3:
                        staffKondrikov.ReadFromFile();
                        break;
                    case 4:
                        staffKondrikov.SaveToFile();
                        break;
                    case 5:
                        staffKondrikov.Clear();
                        break;
                    case 6:
                        staffKondrikov.AddProgrammer();
                        break;
                    case 0:
                        return;
                }
            }
        }
    }
}
