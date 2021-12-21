using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace KondrikovOOPP6
{
    public partial class AddDialog : Form
    {
        #region Header
        public ListBox listBox;
        public bool isEditing;
        public bool isHeadman = false;
        public Action OnCloseDialog;

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

        public AddDialog()
        {
            InitializeComponent();
        }

        public AddDialog(ref ListBox listBox1, Action updateInfoMethod, bool isEditing = false)
        {
            this.isEditing = isEditing;
            listBox = listBox1;
            OnCloseDialog = updateInfoMethod;
            InitializeComponent();
            if (!isEditing)
            {
                surnameText.Text = "Фамилия";
                nameText.Text = "Имя";
                ageText.Text = "0";
                hasJournalCheck.Checked = false;
                scholarshipText.Text = "0";
                hasJournalCheck.Enabled = false;
                scholarshipText.Enabled = false;
                scholarshipLabel.Enabled = false;
            }
            else
            {
                isHeadmanCheck.Enabled = false;
                if (!IsHeadman(listBox1.SelectedIndex))
                {
                    Student student = new Student();
                    GetStudent(ref student, listBox1.SelectedIndex);
                    surnameText.Text = student.surname;
                    nameText.Text = student.name;
                    ageText.Text = student.age.ToString();
                    hasJournalCheck.Enabled = false;
                    scholarshipText.Enabled = false;
                    scholarshipLabel.Enabled = false;
                }
                else
                {
                    isHeadman = true;
                    Headman headman = new Headman();
                    GetHeadman(ref headman, listBox1.SelectedIndex);
                    surnameText.Text = headman.surname;
                    nameText.Text = headman.name;
                    ageText.Text = headman.age.ToString();
                    hasJournalCheck.Enabled = true;
                    scholarshipText.Enabled = true;
                    scholarshipLabel.Enabled = true;
                    hasJournalCheck.Checked = headman.hasJournal;
                    scholarshipText.Text = headman.scholarship.ToString();
                }
            }
        }

        private void isHeadmanCheck_CheckedChanged(object sender, EventArgs e)
        {
            isHeadman = !isHeadman;
            if (!isHeadman)
            {
                hasJournalCheck.Checked = false;
                scholarshipText.Text = "";
                hasJournalCheck.Enabled = false;
                scholarshipText.Enabled = false;
                scholarshipLabel.Enabled = false;
            }
            else
            {
                scholarshipText.Text = "0";
                hasJournalCheck.Enabled = true;
                scholarshipText.Enabled = true;
                scholarshipLabel.Enabled = true;
            }
        }
        private void EditStudent()
        {
            if (!isHeadman)
            {
                Student student = new Student();
                student.surname = surnameText.Text;
                student.name = nameText.Text;
                student.age = int.Parse(ageText.Text);
                SetStudent(ref student, listBox.SelectedIndex);
                int id = listBox.SelectedIndex;
                listBox.Items.Insert(listBox.SelectedIndex, student.surname);
                listBox.Items.RemoveAt(listBox.SelectedIndex);
                listBox.SelectedIndex = id;
            }
            else
            {
                Headman headman = new Headman();
                headman.surname = surnameText.Text;
                headman.name = nameText.Text;
                headman.age = int.Parse(ageText.Text);
                headman.hasJournal = hasJournalCheck.Checked;
                headman.scholarship = int.Parse(scholarshipText.Text);
                SetHeadman(ref headman, listBox.SelectedIndex);
                int id = listBox.SelectedIndex;
                listBox.Items.Insert(listBox.SelectedIndex, headman.surname);
                listBox.Items.RemoveAt(listBox.SelectedIndex);
                listBox.SelectedIndex = id;
            }
        }

        private void NewStudent()
        {
            if (!isHeadman)
            {
                CreateStudent();
                Student student = new Student();
                student.surname = surnameText.Text;
                student.name = nameText.Text;
                student.age = int.Parse(ageText.Text);
                SetStudent(ref student, GetGroupSize() - 1);
                listBox.Items.Add(student.surname);
            }
            else
            {
                CreateHeadman();
                Headman headman = new Headman();
                headman.surname = surnameText.Text;
                headman.name = nameText.Text;
                headman.age = int.Parse(ageText.Text);
                headman.hasJournal = hasJournalCheck.Checked;
                headman.scholarship = int.Parse(scholarshipText.Text);
                SetHeadman(ref headman, GetGroupSize() - 1);
                listBox.Items.Add(headman.surname);
            }
            listBox.SelectedIndex = GetGroupSize() - 1;
        }

        private void AddFinalButton_Click(object sender, EventArgs e)
        {
            if (isEditing)
                EditStudent();
            else
                NewStudent();

            OnCloseDialog?.Invoke();
            Close();
        }
    }
}
