using System;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.IO;

namespace KondrikovOOPP6
{
    public partial class MainForm : Form
    {
        #region Header
        public bool isHeadman = false;
        [DllImport("MFCLibraryKondrikov.dll", CharSet = CharSet.Ansi)]
        private static extern int GetGroupSize();
        [DllImport("MFCLibraryKondrikov.dll", CharSet = CharSet.Ansi)]
        private static extern void CreateStudent();
        [DllImport("MFCLibraryKondrikov.dll", CharSet = CharSet.Ansi)]
        private static extern void GetStudent(ref Student student, int id);
        [DllImport("MFCLibraryKondrikov.dll", CharSet = CharSet.Ansi)]
        private static extern void SetStudent(ref Student student, int id);
        [DllImport("MFCLibraryKondrikov.dll", CharSet = CharSet.Ansi)]
        private static extern void CreateHeadman();
        [DllImport("MFCLibraryKondrikov.dll", CharSet = CharSet.Ansi)]
        private static extern void GetHeadman(ref Headman headman, int id);
        [DllImport("MFCLibraryKondrikov.dll", CharSet = CharSet.Ansi)]
        private static extern void SetHeadman(ref Headman headman, int id);
        [DllImport("MFCLibraryKondrikov.dll", CharSet = CharSet.Ansi)]
        private static extern bool IsHeadman(int id);
        [DllImport("MFCLibraryKondrikov.dll", CharSet = CharSet.Ansi)]
        private static extern void DeleteStudent(int id);
        [DllImport("MFCLibraryKondrikov.dll", CharSet = CharSet.Ansi)]
        private static extern void SaveToFile(StringBuilder filename);
        [DllImport("MFCLibraryKondrikov.dll", CharSet = CharSet.Ansi)]
        private static extern void LoadFromFile(StringBuilder filename);
        #endregion

        public MainForm()
        {
            InitializeComponent();
        }

        private void UpdateStudentInfo()
        {
            if (listBox1.SelectedIndex < 0)
                return;
            if (!IsHeadman(listBox1.SelectedIndex))
            {
                Student student = new Student();
                GetStudent(ref student, listBox1.SelectedIndex);
                textBox1.Text = student.surname;
                textBox2.Text = student.name;
                textBox3.Text = $"Возраст: {student.age}";
                textBox4.Text = "";
                textBox5.Text = "";
                textBox1.Enabled = true;
                textBox2.Enabled = true;
                textBox3.Enabled = true;
                textBox4.Enabled = false;
                textBox5.Enabled = false;
            }
            else
            {
                Headman headman = new Headman();
                GetHeadman(ref headman, listBox1.SelectedIndex);
                textBox1.Text = headman.surname;
                textBox2.Text = headman.name;
                textBox3.Text = $"Возраст: {headman.age}";
                textBox4.Text = headman.hasJournal ? "Журнал с собой" : "Без журнала";
                textBox5.Text = $"Стипендия: {headman.scholarship}";
                textBox1.Enabled = true;
                textBox2.Enabled = true;
                textBox3.Enabled = true;
                textBox4.Enabled = true;
                textBox5.Enabled = true;
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            UpdateStudentInfo();
        }

        private void AddButton_Click(object sender, EventArgs e)
        {
            AddDialog dialog = new AddDialog(ref listBox1, UpdateStudentInfo);
            dialog.ShowDialog();
        }

        private void EditButton_Click(object sender, EventArgs e)
        {
            if (GetGroupSize() != 0)
            {
                if (listBox1.SelectedIndex == -1)
                    listBox1.SelectedIndex = 0;
                AddDialog dialog = new AddDialog(ref listBox1, UpdateStudentInfo, true);
                dialog.ShowDialog();
            }
        }

        private void ClearButton_Click(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;

            if (listBox1.SelectedIndex >= 0)
            {
                DeleteStudent(index);
                listBox1.Items.RemoveAt(index);
                listBox1.SelectedIndex = (GetGroupSize() - 1 < index) ? index - 1 : index;
                if (GetGroupSize() == 0)
                {
                    textBox1.Enabled = false;
                    textBox1.Text = "";
                    textBox2.Enabled = false;
                    textBox2.Text = "";
                    textBox3.Enabled = false;
                    textBox3.Text = "";
                    textBox4.Enabled = false;
                    textBox4.Text = "";
                    textBox5.Enabled = false;
                    textBox5.Text = "";
                }
            }
        }

        private void SaveButton_Click(object sender, EventArgs e)
        {
            SaveFileDialog fileDialog = new SaveFileDialog
            {
                Filter = "Kondrikov OOPP files (*.mymfc*)|*.mymfc*",
                InitialDirectory = Directory.GetCurrentDirectory(),
                CreatePrompt = true
            };

            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                var fileName = new StringBuilder(fileDialog.FileName);
                SaveToFile(fileName);
            }
        }

        private void LoadButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog fileDialog = new OpenFileDialog
            {
                Filter = "Kondrikov OOPP files (*.mymfc*)|*.mymfc*",
                InitialDirectory = Directory.GetCurrentDirectory()
            };

            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                var fileName = new StringBuilder(fileDialog.FileName);
                LoadFromFile(fileName);
                listBox1.Items.Clear();
                for (int i = 0; i < GetGroupSize(); i++)
                {
                    if (IsHeadman(i))
                    {
                        Headman headman = new Headman();
                        GetHeadman(ref headman, i);
                        listBox1.Items.Add(headman.surname);
                    }
                    else
                    {
                        Student student = new Student();
                        GetStudent(ref student, i);
                        listBox1.Items.Add(student.surname);
                    }
                }
            }
            if (GetGroupSize() != 0)
                listBox1.SelectedIndex = 0;
        }
    }
}
