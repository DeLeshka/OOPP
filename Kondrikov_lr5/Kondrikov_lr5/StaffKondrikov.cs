using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace Kondrikov_lr5
{
    class StaffKondrikov
    {
        private List<EmployeeKondrikov> _employees;

        public StaffKondrikov(List<EmployeeKondrikov> employees)
        {
            _employees = employees;
        }

        public void AddEmployee()
        {
            EmployeeKondrikov new_emp = new EmployeeKondrikov();
            new_emp.SetInfo();
            _employees.Add(new_emp);
        }

        public void AddProgrammer()
        {
            ProgrammerKondrikov new_prog = new ProgrammerKondrikov();
            new_prog.SetInfo();
            _employees.Add(new_prog);
        }
        public void PrintStaff()
        {
            if (_employees.Count > 0)
                foreach (var employee in _employees)
                {
                    employee.PrintInfo();
                    Console.WriteLine();
                }
            else
                Console.WriteLine("Empty set");

        }

        public void Clear()
        {
            _employees.Clear();
        }

        public void SaveToFile()
        {
            Console.WriteLine("Enter the output file name: ");
            string filename = Console.ReadLine();
            BinaryFormatter bf = new BinaryFormatter();
            using (FileStream fout = new FileStream(filename, FileMode.OpenOrCreate))
            {
                bf.Serialize(fout, _employees);
            }
        }
        
        public void ReadFromFile()
        {
            Console.WriteLine("Enter the input file name: ");
            string filename = Console.ReadLine();
            BinaryFormatter bf = new BinaryFormatter();
            using (FileStream fin = new FileStream(filename, FileMode.Open))
            {
                _employees = bf.Deserialize(fin) as List<EmployeeKondrikov>;
            }
        }
    }
}
