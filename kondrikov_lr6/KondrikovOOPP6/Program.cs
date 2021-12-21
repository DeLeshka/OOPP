using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace KondrikovOOPP6
{
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    struct Student
    {
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 255)]
        public string surname;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 255)]
        public string name;
        [MarshalAs(UnmanagedType.I4)]
        public int age;
    };

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    struct Headman
    {
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 255)]
        public string surname;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 255)]
        public string name;
        [MarshalAs(UnmanagedType.I4)]
        public int age;
        [MarshalAs(UnmanagedType.Bool)]
        public bool hasJournal;
        [MarshalAs(UnmanagedType.I4)]
        public int scholarship;
    };

    static class Program
    {
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm());
        }
    }
}
