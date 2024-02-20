#pragma once

namespace Project13 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->checkInput = gcnew array <String^>{
					"X5",
					"X10",
					"Xcoff",
					"Xchoc",
					"Xplus",
					"Xminus",
					"Xchange",
			};
			this->currentState = State::S0;
		}
		

		
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   int count = 0;
		   String^ oneInput;
		   enum class State { S0, S5, S10, S15, S20, S25, S30, S35, S40, S45, S50, Sopr };
		   array<String^>^ input;
		   array<String^>^ checkInput;
		   State currentState;
		  
	protected:

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(798, 388);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(973, 480);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 57);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Пошаговый режим";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(823, 480);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(144, 57);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Автоматический режим";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(973, 552);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(137, 52);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Отчистить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(814, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(296, 388);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->Text = resources->GetString(L"richTextBox1.Text");
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(10, 452);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(798, 152);
			this->dataGridView1->TabIndex = 7;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(868, 436);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(203, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 436);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Результат";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(865, 420);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(116, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Ввод X через пробел ";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1122, 616);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"Коффейный автомат";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text->Length == 0) {
			button1->Enabled = false;
			button2->Enabled = false;
		}
	}
		 

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { //реализация кнопки "Отчистить"
	currentState = State::S0;
	dataGridView1->Rows->Clear(); 
	dataGridView1->Columns->Clear();
	textBox1->Clear();
	button1->Show();
	button2->Show();
	count = 0;
}


private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	input = textBox1->Text->Split(gcnew array<String^>{" "},
		StringSplitOptions::RemoveEmptyEntries);

	bool flag = false;
	for (int i = 0; i < input->Length; i++)
		for (int j = 0; j < checkInput->Length; j++) {
			if (input[i] == checkInput[j]) {
				flag = true;
				break;
			}
			else
				flag = false;
		}

	if (textBox1->Text->Length == 0) {
		button1->Enabled = false;
		button2->Enabled = false;
	}
	else {
		button1->Enabled = flag;
		button2->Enabled = flag;
	}
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // реализация автоматического режима
	button1->Hide();
	currentState = State::S0;
	dataGridView1->Columns->Clear();
	dataGridView1->Columns->Add("", "");
	dataGridView1->Rows->Add(3);
	dataGridView1->Rows[0]->Cells[0]->Value = "t";
	dataGridView1->Rows[1]->Cells[0]->Value = "X";
	dataGridView1->Rows[2]->Cells[0]->Value = "S";
	dataGridView1->Rows[3]->Cells[0]->Value = "Y";
	for (int i = 0; i <= input->Length; i++) {
		dataGridView1->Columns->Add("", "");
		dataGridView1->Rows[0]->Cells[i+1]->Value = i;

	}
	dataGridView1->Rows[2]->Cells[1]->Value = currentState;
	
	currentState = State::S0;
	for (int i = 0; i < input->Length; i++) {
		bool flag1 = true;
		String^ X = input[i];
		String^ Y;
		switch (currentState) {
		case State::S0:
			if (X == "X5") {
				currentState = State::S5;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S10;
				Y = "Y10";
			}
			else flag1 = false;
			break;
		case State::S5:
			if (X == "X5") {
				currentState = State::S10;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S15;
				Y = "Y10";
			}
			else flag1 = false;
			break;
		case State::S10:
			if (X == "X5") {
				currentState = State::S15;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S20;
				Y = "Y10";
			}
			else flag1 = false;
			break;
		case State::S15:
			if (X == "X5") {
				currentState = State::S20;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S25;
				Y = "Y10";
			}
			else flag1 = false;
			break;
		case State::S20:
			if (X == "X5") {
				currentState = State::S25;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S30;
				Y = "Y10";
			}
			else flag1 = false;
			break;
		case State::S25:
			if (X == "X5") {
				currentState = State::S30;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S35;
				Y = "Y10";
			}
			else flag1 = false;
			break;
		case State::S30:
			if (X == "X5") {
				currentState = State::S35;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S40;
				Y = "Y10";
			}
			else flag1 = false;
			break;
		case State::S35:
			if (X == "X5") {
				currentState = State::S40;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S45;
				Y = "Y10";
			}
			else flag1 = false;
			break;
		case State::S40:
			if (X == "X5") {
				currentState = State::S45;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S50;
				Y = "Y10";
			}
			else if (X == "Xcoff") {
				currentState = State::Sopr;
				Y = "Y1";
			}
			else if (X == "Xchoc") {
				currentState = State::Sopr;
				Y = "Y2";
			}
			else flag1 = false;
			break;
		case State::S45:
			if (X == "X5") {
				currentState = State::S50;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S0;
				Y = "Ychange";
			}
			else if (X == "Xcoff") {
				currentState = State::Sopr;
				Y = "Y1";
			}
			else if (X == "Xchoc") {
				currentState = State::Sopr;
				Y = "Y2";
			}
			else flag1 = false;
			break;
		case State::S50:
			if (X == "X5") {
				currentState = State::S0;
				Y = "Ychange";
			}
			else if (X == "X10") {
				currentState = State::S0;
				Y = "Ychange";
			}
			else if (X == "Xcoff") {
				currentState = State::Sopr;
				Y = "Y1";
			}
			else if (X == "Xchoc") {
				currentState = State::Sopr;
				Y = "Y2";
			}
			else flag1 = false;
			break;
		case State::Sopr:
			if (X == "Xplus") {
				currentState = State::Sopr;
				Y = "Yplus";
			}
			else if (X == "Xminus") {
				currentState = State::Sopr;
				Y = "Yminus";
			}
			else if (X == "Xchange") {
				currentState = State::S0;
				Y = "Y3";
			}
			else flag1 = false;
			break;
		}
		dataGridView1->Rows[1]->Cells[i + 1]->Value = X;
		if (flag1) {
			dataGridView1->Rows[2]->Cells[i + 2]->Value = currentState;
			dataGridView1->Rows[3]->Cells[i + 1]->Value = Y;
		}
		else {
			dataGridView1->Rows[2]->Cells[i + 2]->Value = currentState;
			dataGridView1->Rows[3]->Cells[i + 1]->Value = "-";
		}
	}
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // реализация пошагового режима
		if (count == 0) {
			button2->Hide();
			currentState = State::S0;
			dataGridView1->Columns->Clear();
			dataGridView1->Columns->Add("", "");
			dataGridView1->Rows->Add(3);
			dataGridView1->Rows[0]->Cells[0]->Value = "t";
			dataGridView1->Rows[1]->Cells[0]->Value = "x";
			dataGridView1->Rows[2]->Cells[0]->Value = "S";
			dataGridView1->Rows[3]->Cells[0]->Value = "y";
			for (int i = 0; i <= 1; i++) {
				dataGridView1->Columns->Add("", "");
				dataGridView1->Rows[0]->Cells[i + 1]->Value = i;
			}
			dataGridView1->Rows[2]->Cells[count + 1]->Value = "S0";
		}
		else {
			dataGridView1->Columns->Add("", "");
			dataGridView1->Rows[0]->Cells[count + 2]->Value = count + 1;
		}

		oneInput = textBox1->Text;
		dataGridView1->Rows[1]->Cells[count + 1]->Value = oneInput;


		bool flag = true;
		String^ X = oneInput;
		String^ Y;
		switch (currentState) {
		case State::S0:
			if (X == "X5") {
				currentState = State::S5;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S10;
				Y = "Y10";
			}
			else flag = false;
			break;
		case State::S5:
			if (X == "X5") {
				currentState = State::S10;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S15;
				Y = "Y10";
			}
			else flag = false;
			break;
		case State::S10:
			if (X == "X5") {
				currentState = State::S15;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S20;
				Y = "Y10";
			}
			else flag = false;
			break;
		case State::S15:
			if (X == "X5") {
				currentState = State::S20;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S25;
				Y = "Y10";
			}
			else flag = false;
			break;
		case State::S20:
			if (X == "X5") {
				currentState = State::S25;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S30;
				Y = "Y10";
			}
			else flag = false;
			break;
		case State::S25:
			if (X == "X5") {
				currentState = State::S30;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S35;
				Y = "Y10";
			}
			else flag = false;
			break;
		case State::S30:
			if (X == "X5") {
				currentState = State::S35;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S40;
				Y = "Y10";
			}
			else flag = false;
			break;
		case State::S35:
			if (X == "X5") {
				currentState = State::S40;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S45;
				Y = "Y10";
			}
			else flag = false;
			break;
		case State::S40:
			if (X == "X5") {
				currentState = State::S45;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S50;
				Y = "Y10";
			}
			else if (X == "Xcoff") {
				currentState = State::Sopr;
				Y = "Y1";
			}
			else if (X == "Xchoc") {
				currentState = State::Sopr;
				Y = "Y2";
			}
			else flag = false;
			break;
		case State::S45:
			if (X == "X5") {
				currentState = State::S50;
				Y = "Y5";
			}
			else if (X == "X10") {
				currentState = State::S0;
				Y = "Ychange";
			}
			else if (X == "Xcoff") {
				currentState = State::Sopr;
				Y = "Y1";
			}
			else if (X == "Xchoc") {
				currentState = State::Sopr;
				Y = "Y2";
			}
			else flag = false;
			break;
		case State::S50:
			if (X == "X5") {
				currentState = State::S0;
				Y = "Ychange";
			}
			else if (X == "X10") {
				currentState = State::S0;
				Y = "Ychange";
			}
			else if (X == "Xcoff") {
				currentState = State::Sopr;
				Y = "Y1";
			}
			else if (X == "Xchoc") {
				currentState = State::Sopr;
				Y = "Y2";
			}
			else flag = false;
			break;
		case State::Sopr:
			if (X == "Xplus") {
				currentState = State::Sopr;
				Y = "Yplus";
			}
			else if (X == "Xminus") {
				currentState = State::Sopr;
				Y = "Yminus";
			}
			else if (X == "Xchange") {
				currentState = State::S0;
				Y = "Y3";
			}
			else flag = false;
			break;
		}
		dataGridView1->Rows[1]->Cells[count + 1]->Value = X;
		if (flag) {
			dataGridView1->Rows[2]->Cells[count + 2]->Value = currentState;
			dataGridView1->Rows[3]->Cells[count + 1]->Value = Y;
		}
		else {
			dataGridView1->Rows[2]->Cells[count + 2]->Value = currentState;
			dataGridView1->Rows[3]->Cells[count + 1]->Value = "-";
		}
		textBox1->Text = "";
		count += 1;
	}
};
}
