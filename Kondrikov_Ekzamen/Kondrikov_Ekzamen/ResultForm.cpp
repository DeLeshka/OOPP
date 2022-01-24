#include "ResultForm.h"

System::Void KondrikovEkzamen::ResultForm::ResultForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	std::string stri = msclr::interop::marshal_as<std::string>(Convert::ToString(this->permutatedString));
	std::sort(stri.begin(), stri.end());
	int i = 0;
	do
	{
		System::String^ nextPermutation = gcnew String(stri.c_str());
		this->listBox1->Items->Insert(i++, msclr::interop::marshal_as <System::String^>(stri.c_str()));
	} while (std::next_permutation(stri.begin(), stri.end()));
	this->label1->Text = "Кол-во перестановок = " + Convert::ToString(stri.size()) + "! = " + Convert::ToString(i);
}

System::Void KondrikovEkzamen::ResultForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    return System::Void();
}

System::Void KondrikovEkzamen::ResultForm::setPermutatedString(System::String^ str)
{
	this->permutatedString = str;
}

System::Void KondrikovEkzamen::ResultForm::ResultForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	Application::Exit();
}
