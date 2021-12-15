using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kondrikov_lr5
{
    [Serializable]
    class ProgrammerKondrikov: EmployeeKondrikov
    {
        byte _workExperience;
        string _preferedLanguage;

        public override void SetInfo()
        {
            base.SetInfo();
            Console.Write("Work experience: ");
            _workExperience = byte.Parse(Console.ReadLine());
            Console.Write("Prefered language: ");
            _preferedLanguage = Console.ReadLine();
        }

        public override void PrintInfo()
        {
            base.PrintInfo();
            Console.WriteLine($"Work experience: {_workExperience}\nPrefered langeage: {_preferedLanguage}");
        }

    }
}
