#pragma once

namespace KondrikovEkzamen {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Dialog
	/// </summary>
	public ref class Dialog : public System::Windows::Forms::Form
	{
	public:
		Dialog(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Dialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox_string;
	private: System::Windows::Forms::Button^ button_showResult;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_string = (gcnew System::Windows::Forms::TextBox());
			this->button_showResult = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(52, 91);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(212, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"¬ведите строку символов:";
			// 
			// textBox_string
			// 
			this->textBox_string->Location = System::Drawing::Point(56, 127);
			this->textBox_string->Name = L"textBox_string";
			this->textBox_string->Size = System::Drawing::Size(229, 20);
			this->textBox_string->TabIndex = 1;
			// 
			// button_showResult
			// 
			this->button_showResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_showResult->Location = System::Drawing::Point(56, 191);
			this->button_showResult->Name = L"button_showResult";
			this->button_showResult->Size = System::Drawing::Size(229, 56);
			this->button_showResult->TabIndex = 2;
			this->button_showResult->TabStop = false;
			this->button_showResult->Text = L"¬ывести перестановки";
			this->button_showResult->UseVisualStyleBackColor = true;
			this->button_showResult->Click += gcnew System::EventHandler(this, &Dialog::button_showResult_Click);
			// 
			// Dialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(337, 341);
			this->Controls->Add(this->button_showResult);
			this->Controls->Add(this->textBox_string);
			this->Controls->Add(this->label1);
			this->Name = L"Dialog";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dialog";
			this->Activated += gcnew System::EventHandler(this, &Dialog::Dialog_Activated);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		private: System::Void button_showResult_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void Dialog_Activated(System::Object^ sender, System::EventArgs^ e);


};
}
