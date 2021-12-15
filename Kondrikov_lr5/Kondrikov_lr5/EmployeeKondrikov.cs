using System;


namespace Kondrikov_lr5
{
    [Serializable]
    public class EmployeeKondrikov
    {
       
        private string _name;
        private string _surname;
        private byte _age;
        private double _salary;

        public virtual void PrintInfo()
        {
            Console.Write(
                $"Name: {_name}\n" +
                $"Surname: {_surname}\n" +
                $"Age: {_age}\n" +
                $"Salary: {_salary}\n");
        }

        public virtual void SetInfo()
        {
            Console.Write("Name: ");
            _name = Console.ReadLine();
            Console.Write("Surname: ");
            _surname = Console.ReadLine();
            Console.Write("Age: ");
            _age = byte.Parse(Console.ReadLine());
            Console.Write("Salary: ");
            _salary = double.Parse(Console.ReadLine());
        }
            
    }
}
