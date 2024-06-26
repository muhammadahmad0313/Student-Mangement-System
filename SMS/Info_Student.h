#pragma once
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>
namespace SMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for Info_Student
	/// </summary>
	public ref class Info_Student : public System::Windows::Forms::Form
	{
	public:
		Info_Student(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Info_Student()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private: System::Windows::Forms::Label^ Name_label;
	private: System::Windows::Forms::TextBox^ name_textBox;



	private: System::Windows::Forms::Panel^ Logo_WHO;
	private: System::Windows::Forms::Label^ label_paanel_WHO_2;
	private: System::Windows::Forms::Label^ label_panel_WHO_1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ TITLE;
	private: System::Windows::Forms::TextBox^ mobile_num_textBox;

	private: System::Windows::Forms::TextBox^ cnic_textBox;


	private: System::Windows::Forms::TextBox^ gender_textBox;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ section_textBox;
	private: System::Windows::Forms::TextBox^ campus_textBox;
	private: System::Windows::Forms::TextBox^ batch_textBox;




	private: System::Windows::Forms::TextBox^ rollno_textBox;

	private: System::Windows::Forms::Label^ mobileno_label;

	private: System::Windows::Forms::Label^ cnic_label;
	private: System::Windows::Forms::Label^ dob_label;


	private: System::Windows::Forms::Label^ gender_label;




	private: System::Windows::Forms::Label^ section_label;
	private: System::Windows::Forms::Label^ batch_label;


	private: System::Windows::Forms::Label^ campus__label;

	private: System::Windows::Forms::Label^ rollno_label;

	private: System::Windows::Forms::Button^ EXIT_button;
	private: System::Windows::Forms::TextBox^ textBox1;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Info_Student::typeid));
			this->Name_label = (gcnew System::Windows::Forms::Label());
			this->name_textBox = (gcnew System::Windows::Forms::TextBox());
			this->Logo_WHO = (gcnew System::Windows::Forms::Panel());
			this->label_paanel_WHO_2 = (gcnew System::Windows::Forms::Label());
			this->label_panel_WHO_1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->TITLE = (gcnew System::Windows::Forms::Label());
			this->mobile_num_textBox = (gcnew System::Windows::Forms::TextBox());
			this->cnic_textBox = (gcnew System::Windows::Forms::TextBox());
			this->gender_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->section_textBox = (gcnew System::Windows::Forms::TextBox());
			this->campus_textBox = (gcnew System::Windows::Forms::TextBox());
			this->batch_textBox = (gcnew System::Windows::Forms::TextBox());
			this->rollno_textBox = (gcnew System::Windows::Forms::TextBox());
			this->mobileno_label = (gcnew System::Windows::Forms::Label());
			this->cnic_label = (gcnew System::Windows::Forms::Label());
			this->dob_label = (gcnew System::Windows::Forms::Label());
			this->gender_label = (gcnew System::Windows::Forms::Label());
			this->section_label = (gcnew System::Windows::Forms::Label());
			this->batch_label = (gcnew System::Windows::Forms::Label());
			this->campus__label = (gcnew System::Windows::Forms::Label());
			this->rollno_label = (gcnew System::Windows::Forms::Label());
			this->EXIT_button = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Logo_WHO->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// Name_label
			// 
			this->Name_label->AutoSize = true;
			this->Name_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->Name_label->Location = System::Drawing::Point(351, 117);
			this->Name_label->Name = L"Name_label";
			this->Name_label->Size = System::Drawing::Size(71, 26);
			this->Name_label->TabIndex = 11;
			this->Name_label->Text = L"Name";
			// 
			// name_textBox
			// 
			this->name_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name_textBox->Location = System::Drawing::Point(530, 117);
			this->name_textBox->Name = L"name_textBox";
			this->name_textBox->ReadOnly = true;
			this->name_textBox->Size = System::Drawing::Size(468, 26);
			this->name_textBox->TabIndex = 10;
			this->name_textBox->TextChanged += gcnew System::EventHandler(this, &Info_Student::name_textBox_TextChanged);
			// 
			// Logo_WHO
			// 
			this->Logo_WHO->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->Logo_WHO->Controls->Add(this->label_paanel_WHO_2);
			this->Logo_WHO->Controls->Add(this->label_panel_WHO_1);
			this->Logo_WHO->Controls->Add(this->pictureBox1);
			this->Logo_WHO->Location = System::Drawing::Point(-1, -2);
			this->Logo_WHO->Name = L"Logo_WHO";
			this->Logo_WHO->Size = System::Drawing::Size(235, 715);
			this->Logo_WHO->TabIndex = 9;
			// 
			// label_paanel_WHO_2
			// 
			this->label_paanel_WHO_2->AutoSize = true;
			this->label_paanel_WHO_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label_paanel_WHO_2->ForeColor = System::Drawing::Color::White;
			this->label_paanel_WHO_2->Location = System::Drawing::Point(56, 438);
			this->label_paanel_WHO_2->Name = L"label_paanel_WHO_2";
			this->label_paanel_WHO_2->Size = System::Drawing::Size(109, 40);
			this->label_paanel_WHO_2->TabIndex = 2;
			this->label_paanel_WHO_2->Text = L"Wave";
			// 
			// label_panel_WHO_1
			// 
			this->label_panel_WHO_1->AutoSize = true;
			this->label_panel_WHO_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label_panel_WHO_1->ForeColor = System::Drawing::Color::White;
			this->label_panel_WHO_1->Location = System::Drawing::Point(44, 395);
			this->label_panel_WHO_1->Name = L"label_panel_WHO_1";
			this->label_panel_WHO_1->Size = System::Drawing::Size(141, 40);
			this->label_panel_WHO_1->TabIndex = 1;
			this->label_panel_WHO_1->Text = L"Student";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(13, 176);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(212, 205);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// TITLE
			// 
			this->TITLE->AutoSize = true;
			this->TITLE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32));
			this->TITLE->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->TITLE->Location = System::Drawing::Point(287, 26);
			this->TITLE->Name = L"TITLE";
			this->TITLE->Size = System::Drawing::Size(847, 73);
			this->TITLE->TabIndex = 15;
			this->TITLE->Text = L"PERSONAL INFORMATION";
			// 
			// mobile_num_textBox
			// 
			this->mobile_num_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mobile_num_textBox->Location = System::Drawing::Point(530, 286);
			this->mobile_num_textBox->Name = L"mobile_num_textBox";
			this->mobile_num_textBox->ReadOnly = true;
			this->mobile_num_textBox->Size = System::Drawing::Size(468, 26);
			this->mobile_num_textBox->TabIndex = 22;
			// 
			// cnic_textBox
			// 
			this->cnic_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cnic_textBox->Location = System::Drawing::Point(530, 197);
			this->cnic_textBox->Name = L"cnic_textBox";
			this->cnic_textBox->ReadOnly = true;
			this->cnic_textBox->Size = System::Drawing::Size(468, 26);
			this->cnic_textBox->TabIndex = 24;
			this->cnic_textBox->TextChanged += gcnew System::EventHandler(this, &Info_Student::cnic_textBox_TextChanged);
			// 
			// gender_textBox
			// 
			this->gender_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->gender_textBox->Location = System::Drawing::Point(530, 154);
			this->gender_textBox->Name = L"gender_textBox";
			this->gender_textBox->ReadOnly = true;
			this->gender_textBox->Size = System::Drawing::Size(468, 26);
			this->gender_textBox->TabIndex = 25;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->label1->Location = System::Drawing::Point(289, 347);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(835, 73);
			this->label1->TabIndex = 26;
			this->label1->Text = L"ACADEMIC INFORMATION";
			// 
			// section_textBox
			// 
			this->section_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->section_textBox->Location = System::Drawing::Point(530, 491);
			this->section_textBox->Name = L"section_textBox";
			this->section_textBox->ReadOnly = true;
			this->section_textBox->Size = System::Drawing::Size(468, 26);
			this->section_textBox->TabIndex = 30;
			// 
			// campus_textBox
			// 
			this->campus_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->campus_textBox->Location = System::Drawing::Point(530, 534);
			this->campus_textBox->Name = L"campus_textBox";
			this->campus_textBox->ReadOnly = true;
			this->campus_textBox->Size = System::Drawing::Size(468, 26);
			this->campus_textBox->TabIndex = 29;
			// 
			// batch_textBox
			// 
			this->batch_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->batch_textBox->Location = System::Drawing::Point(530, 576);
			this->batch_textBox->Name = L"batch_textBox";
			this->batch_textBox->ReadOnly = true;
			this->batch_textBox->Size = System::Drawing::Size(468, 26);
			this->batch_textBox->TabIndex = 28;
			// 
			// rollno_textBox
			// 
			this->rollno_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno_textBox->Location = System::Drawing::Point(530, 454);
			this->rollno_textBox->Name = L"rollno_textBox";
			this->rollno_textBox->ReadOnly = true;
			this->rollno_textBox->Size = System::Drawing::Size(468, 26);
			this->rollno_textBox->TabIndex = 27;
			// 
			// mobileno_label
			// 
			this->mobileno_label->AutoSize = true;
			this->mobileno_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->mobileno_label->Location = System::Drawing::Point(348, 284);
			this->mobileno_label->Name = L"mobileno_label";
			this->mobileno_label->Size = System::Drawing::Size(160, 26);
			this->mobileno_label->TabIndex = 31;
			this->mobileno_label->Text = L"Mobile Number";
			this->mobileno_label->Click += gcnew System::EventHandler(this, &Info_Student::label2_Click);
			// 
			// cnic_label
			// 
			this->cnic_label->AutoSize = true;
			this->cnic_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->cnic_label->Location = System::Drawing::Point(349, 197);
			this->cnic_label->Name = L"cnic_label";
			this->cnic_label->Size = System::Drawing::Size(66, 26);
			this->cnic_label->TabIndex = 32;
			this->cnic_label->Text = L"CNIC";
			// 
			// dob_label
			// 
			this->dob_label->AutoSize = true;
			this->dob_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->dob_label->Location = System::Drawing::Point(350, 237);
			this->dob_label->Name = L"dob_label";
			this->dob_label->Size = System::Drawing::Size(133, 26);
			this->dob_label->TabIndex = 33;
			this->dob_label->Text = L"Date of Birth";
			// 
			// gender_label
			// 
			this->gender_label->AutoSize = true;
			this->gender_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->gender_label->Location = System::Drawing::Point(347, 154);
			this->gender_label->Name = L"gender_label";
			this->gender_label->Size = System::Drawing::Size(84, 26);
			this->gender_label->TabIndex = 34;
			this->gender_label->Text = L"Gender";
			// 
			// section_label
			// 
			this->section_label->AutoSize = true;
			this->section_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->section_label->Location = System::Drawing::Point(374, 489);
			this->section_label->Name = L"section_label";
			this->section_label->Size = System::Drawing::Size(85, 26);
			this->section_label->TabIndex = 39;
			this->section_label->Text = L"Section";
			// 
			// batch_label
			// 
			this->batch_label->AutoSize = true;
			this->batch_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->batch_label->Location = System::Drawing::Point(377, 572);
			this->batch_label->Name = L"batch_label";
			this->batch_label->Size = System::Drawing::Size(68, 26);
			this->batch_label->TabIndex = 38;
			this->batch_label->Text = L"Batch";
			// 
			// campus__label
			// 
			this->campus__label->AutoSize = true;
			this->campus__label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->campus__label->Location = System::Drawing::Point(376, 532);
			this->campus__label->Name = L"campus__label";
			this->campus__label->Size = System::Drawing::Size(94, 26);
			this->campus__label->TabIndex = 37;
			this->campus__label->Text = L"Campus";
			// 
			// rollno_label
			// 
			this->rollno_label->AutoSize = true;
			this->rollno_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->rollno_label->Location = System::Drawing::Point(374, 448);
			this->rollno_label->Name = L"rollno_label";
			this->rollno_label->Size = System::Drawing::Size(134, 26);
			this->rollno_label->TabIndex = 36;
			this->rollno_label->Text = L"Roll Number";
			this->rollno_label->Click += gcnew System::EventHandler(this, &Info_Student::label9_Click);
			// 
			// EXIT_button
			// 
			this->EXIT_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->EXIT_button->ForeColor = System::Drawing::Color::White;
			this->EXIT_button->Location = System::Drawing::Point(955, 628);
			this->EXIT_button->Name = L"EXIT_button";
			this->EXIT_button->Size = System::Drawing::Size(179, 57);
			this->EXIT_button->TabIndex = 14;
			this->EXIT_button->Text = L"EXIT";
			this->EXIT_button->UseVisualStyleBackColor = false;
			this->EXIT_button->Click += gcnew System::EventHandler(this, &Info_Student::EXIT_button_Click);
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(530, 240);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(468, 26);
			this->textBox1->TabIndex = 40;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Info_Student::textBox1_TextChanged);
			// 
			// Info_Student
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1185, 713);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->section_label);
			this->Controls->Add(this->batch_label);
			this->Controls->Add(this->campus__label);
			this->Controls->Add(this->rollno_label);
			this->Controls->Add(this->gender_label);
			this->Controls->Add(this->dob_label);
			this->Controls->Add(this->cnic_label);
			this->Controls->Add(this->mobileno_label);
			this->Controls->Add(this->section_textBox);
			this->Controls->Add(this->campus_textBox);
			this->Controls->Add(this->batch_textBox);
			this->Controls->Add(this->rollno_textBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->gender_textBox);
			this->Controls->Add(this->cnic_textBox);
			this->Controls->Add(this->mobile_num_textBox);
			this->Controls->Add(this->TITLE);
			this->Controls->Add(this->EXIT_button);
			this->Controls->Add(this->Name_label);
			this->Controls->Add(this->name_textBox);
			this->Controls->Add(this->Logo_WHO);
			this->MaximumSize = System::Drawing::Size(1207, 769);
			this->MinimumSize = System::Drawing::Size(1207, 769);
			this->Name = L"Info_Student";
			this->Text = L"Info_Student";
			this->Load += gcnew System::EventHandler(this, &Info_Student::Info_Student_Load);
			this->Logo_WHO->ResumeLayout(false);
			this->Logo_WHO->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Info_Student_Load(System::Object^ sender, System::EventArgs^ e) {
		// Open index.txt to get the index
		std::ifstream indexFile("index.txt");
		int index;
		if (indexFile >> index) {
			// Open students.txt to get the student data
			std::ifstream studentFile("stdAtten.txt");
			if (studentFile.is_open()) {
				std::string line;
				// Loop through the lines in students.txt until reaching the desired index
				for (int i = 0; i < index; ++i) {
					if (!std::getline(studentFile, line)) {
						// Index out of bounds or error in reading file
						// Handle this case as needed (e.g., show an error message)
						return;
					}
				}
				// Split the line by commas
				size_t pos = 0;
				int i = 0;
				std::string token;
				// Tokenize the line and extract data
				while ((pos = line.find(',')) != std::string::npos) {
					token = line.substr(0, pos);
					// Set each token to corresponding textBox
					switch (i) {
					case 0:
						rollno_textBox->Text = gcnew System::String(token.c_str());
						break;
					case 1:
						name_textBox->Text = gcnew System::String(token.c_str());
						break;
					case 2:
						gender_textBox->Text = gcnew System::String(token.c_str());
						break;
					case 3:
						cnic_textBox->Text = gcnew System::String(token.c_str());
						break;
					case 4:
						mobile_num_textBox->Text = gcnew System::String(token.c_str());
						break;
					case 5:
						section_textBox->Text = gcnew System::String(token.c_str());
						break;
					case 6:
						campus_textBox->Text = gcnew System::String(token.c_str());
						break;
					case 7:
						batch_textBox->Text = gcnew System::String(token.c_str());
						break;
					default:
						break;
					}
					// Update the position and index
					line.erase(0, pos + 1);
					i++;
				}
				// Handle the last token (batch)
				batch_textBox->Text = gcnew System::String(token.c_str());
				textBox1->Text = gcnew System::String(line.c_str());

			}
			else {
				// Error opening students.txt
				// Handle this case as needed (e.g., show an error message)
				return;
			}
		}
		else {
			// Error reading index from index.txt
			// Handle this case as needed (e.g., show an error message)
			return;
		}
	}
	private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void EXIT_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void Back_button_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void name_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void cnic_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
