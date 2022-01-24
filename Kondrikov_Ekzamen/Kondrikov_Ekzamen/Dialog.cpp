#include "Dialog.h"
#include "ResultForm.h"
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    KondrikovEkzamen::Dialog dialogForm;
    Application::Run(% dialogForm);
}

System::Void KondrikovEkzamen::Dialog::button_showResult_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ symbols = this->textBox_string->Text;
    if (symbols->Length == 0)
    {
        MessageBox::Show("Введите строку!", "Внимание!");
        return System::Void();
    }
    else
    {
        this->Hide();
        KondrikovEkzamen::ResultForm resultForm;
        resultForm.setPermutatedString(symbols);
        resultForm.ShowDialog();
        this->Show();
    }
}

System::Void KondrikovEkzamen::Dialog::Dialog_Activated(System::Object^ sender, System::EventArgs^ e)
{
    this->textBox_string->Text = "";
}
