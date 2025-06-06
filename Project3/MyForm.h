#pragma once

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2; // N
	private: System::Windows::Forms::TextBox^ textBox3; // M
	private: System::Windows::Forms::TextBox^ textBox4; // a
	private: System::Windows::Forms::TextBox^ textBox5; // b
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;

	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();

			   // textBox2 - N
			   this->textBox2->Location = System::Drawing::Point(50, 50);
			   this->textBox2->Size = System::Drawing::Size(100, 22);

			   // textBox3 - M
			   this->textBox3->Location = System::Drawing::Point(200, 50);
			   this->textBox3->Size = System::Drawing::Size(100, 22);

			   // textBox4 - a
			   this->textBox4->Location = System::Drawing::Point(50, 100);
			   this->textBox4->Size = System::Drawing::Size(100, 22);

			   // textBox5 - b
			   this->textBox5->Location = System::Drawing::Point(200, 100);
			   this->textBox5->Size = System::Drawing::Size(100, 22);

			   // button1
			   this->button1->Location = System::Drawing::Point(150, 140);
			   this->button1->Size = System::Drawing::Size(130, 30);
			   this->button1->Text = L"Massivni Toldirish";
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);

			   // label1
			   this->label1->Location = System::Drawing::Point(50, 180);
			   this->label1->AutoSize = true;

			   // label2
			   this->label2->Location = System::Drawing::Point(50, 30);
			   this->label2->Text = L"N (qatorlar):";

			   // label3
			   this->label3->Location = System::Drawing::Point(200, 30);
			   this->label3->Text = L"M (ustunlar):";

			   // label4
			   this->label4->Location = System::Drawing::Point(50, 80);
			   this->label4->Text = L"a (boshi):";

			   // label5
			   this->label5->Location = System::Drawing::Point(200, 80);
			   this->label5->Text = L"b (oxiri):";

			   // dataGridView1
			   this->dataGridView1->Location = System::Drawing::Point(50, 210);
			   this->dataGridView1->Size = System::Drawing::Size(400, 250);

			   // MyForm
			   this->ClientSize = System::Drawing::Size(550, 500);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->textBox3);
			   this->Controls->Add(this->textBox4);
			   this->Controls->Add(this->textBox5);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->dataGridView1);
			   this->Text = L"MyForm";
			   this->ResumeLayout(false);
			   this->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
		   }
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			int N = Convert::ToInt32(textBox2->Text);
			int M = Convert::ToInt32(textBox3->Text);
			int a = Convert::ToInt32(textBox4->Text);
			int b = Convert::ToInt32(textBox5->Text);

			dataGridView1->Rows->Clear();
			dataGridView1->Columns->Clear();

			for (int j = 0; j < M; j++) {
				String^ columnName = "Ustun " + (j + 1).ToString();
				dataGridView1->Columns->Add(columnName, columnName);
			}

			Random^ rand = gcnew Random();
			int count = 0;

			for (int i = 0; i < N; i++) {
				dataGridView1->Rows->Add();
				for (int j = 0; j < M; j++) {
					int value = rand->Next(-500, 1001);
					dataGridView1->Rows[i]->Cells[j]->Value = value;

					if (value >= a && value <= b) {
						count++;
					}
				}
			}

			label1->Text = "Intervalda [" + a + "; " + b + "] " + count.ToString() + " ta son bor.";
		}
		catch (FormatException^) {
			MessageBox::Show("Iltimos, barcha maydonlarga to'g'ri raqamlar kiriting!", "Xato", MessageBoxButtons::OK);
		}
	}
	};
}
