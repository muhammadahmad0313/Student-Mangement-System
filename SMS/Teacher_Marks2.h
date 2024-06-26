#pragma once
#include "Quiz.h"
#include "Assignment.h"
#include "Mid.h"
#include "Final.h"
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <iostream>


namespace SMS {
	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Teacher_Marks2
	/// </summary>
	public ref class Teacher_Marks2 : public System::Windows::Forms::Form
	{
	private:
		String^ title;
		int Students;

	public:
		void ProcessInput(System::Windows::Forms::TextBox^ textBox) {
			bool isValid = true;

			std::string input = msclr::interop::marshal_as<std::string>(textBox->Text);

			for (char c : input) {
				if (!std::isdigit(c)) {
					isValid = false;
					break;
				}
			}

			if (isValid) {
				System::String^ validatedInput = gcnew System::String(input.c_str());
			}
			else {
				textBox->Clear();
				MessageBox::Show("Invalid input! Please enter numeric characters only.");
			}
		}


		void ReadStudentInfo(String^% name, String^% rollNumber, int studentNumber)
		{
			String^ fileName = "students.txt";
			if (File::Exists(fileName))
			{
				StreamReader^ sr = gcnew StreamReader(fileName);
				String^ line;
				Int32 lineNumber = 0;
				while ((line = sr->ReadLine()) != nullptr)
				{
					array<String^>^ parts = line->Split(',');
					if (parts->Length == 2)
					{
						String^ key = parts[0]->Trim();
						String^ value = parts[1]->Trim();
						if (key == "Name")
						{
							name = value;
						}
						else if (key == "Roll Number")
						{
							rollNumber = value;
						}
						lineNumber++;
						if (lineNumber >= studentNumber * 2)
						{
							break;
						}
					}
				}
				sr->Close();
			}
		}

		void ReadStudents()
		{
			String^ fileName = "students.txt";
			if (File::Exists(fileName))
			{
				StreamReader^ sr = gcnew StreamReader(fileName);
				String^ line;
				while ((line = sr->ReadLine()) != nullptr)
				{
					array<String^>^ parts = line->Split(',');
					if (parts->Length == 2)
					{
						String^ key = parts[0]->Trim();
						String^ value = parts[1]->Trim();
						if (key == "Name")
						{
							IncrementStudents();
						}
					}
				}
				sr->Close();
			}
		}
		
		void IncrementStudents() {
			Students++;
		}
		int GetStudents() {
			return Students;
		}


		void GetTitle(String^% title)
		{
			String^ fileName = "Teacher_Marks2.txt";
			if (File::Exists(fileName))
			{
				StreamReader^ sr = gcnew StreamReader(fileName);
				String^ line;
				Int32 lineNumber = 0;
				while ((line = sr->ReadLine()) != nullptr)
				{
					array<String^>^ parts = line->Split(',');
					if (parts->Length == 1)
					{
						String^ key = parts[0]->Trim();
						SetTitle(key);
					}
				}
				sr->Close();
			}
		}

		String^ ReturnTitle()
		{
			return title;
		}
		void SetTitle(String^ title)
		{
			this->title = title;
		}

		void FillStudentData(int studentNumber) {
			String^ name;
			String^ rollNumber;
			ReadStudentInfo(name, rollNumber, studentNumber); 
			TextBox^ nameTextBox = nullptr;
			TextBox^ rollNumberTextBox = nullptr;

			switch (studentNumber) {
			case 1:
				nameTextBox = name1_textBox;
				rollNumberTextBox = rollno1_textBox;
				if (nameTextBox != nullptr && rollNumberTextBox != nullptr) {
					nameTextBox->Text = name;
					rollNumberTextBox->Text = rollNumber;
				}
				break;
			case 2:
				nameTextBox = name2_textBox;
				rollNumberTextBox = rollno2_textBox;
				if (nameTextBox != nullptr && rollNumberTextBox != nullptr) {
					nameTextBox->Text = name;
					rollNumberTextBox->Text = rollNumber;
				}
				break;
			case 3:
				nameTextBox = name3_textBox;
				rollNumberTextBox = rollno3_textBox;
				if (nameTextBox != nullptr && rollNumberTextBox != nullptr) {
					nameTextBox->Text = name;
					rollNumberTextBox->Text = rollNumber;
				}
				break;
			case 4:
				nameTextBox = name4_textBox;
				rollNumberTextBox = rollno4_textBox;
				if (nameTextBox != nullptr && rollNumberTextBox != nullptr) {
					nameTextBox->Text = name;
					rollNumberTextBox->Text = rollNumber;
				}
				break;
			case 5:
				nameTextBox = name5_textBox;
				rollNumberTextBox = rollno5_textBox;
				if (nameTextBox != nullptr && rollNumberTextBox != nullptr) {
					nameTextBox->Text = name;
					rollNumberTextBox->Text = rollNumber;
				}
				break;
			case 6:
				nameTextBox = name6_textBox;
				rollNumberTextBox = rollno6_textBox;
				if (nameTextBox != nullptr && rollNumberTextBox != nullptr) {
					nameTextBox->Text = name;
					rollNumberTextBox->Text = rollNumber;
				}
				break;
			case 7:
				nameTextBox = name7_textBox;
				rollNumberTextBox = rollno7_textBox;
				if (nameTextBox != nullptr && rollNumberTextBox != nullptr) {
					nameTextBox->Text = name;
					rollNumberTextBox->Text = rollNumber;
				}
				break;


			}


		}

		Teacher_Marks2(void)
		{
			Students = 0;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Teacher_Marks2()
		{

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ rollno7_textBox;
	protected:

	private: System::Windows::Forms::TextBox^ rollno6_textBox;
	protected:

	private: System::Windows::Forms::TextBox^ rollno5_textBox;

	private: System::Windows::Forms::TextBox^ rollno4_textBox;

	private: System::Windows::Forms::TextBox^ rollno3_textBox;

	private: System::Windows::Forms::TextBox^ rollno2_textBox;

	private: System::Windows::Forms::TextBox^ rollno1_textBox;
	private: System::Windows::Forms::Button^ submit_button;


	private: System::Windows::Forms::TextBox^ name7_textBox;

	private: System::Windows::Forms::TextBox^ status7_textBox;
	private: System::Windows::Forms::TextBox^ name6_textBox;


	private: System::Windows::Forms::TextBox^ status6_textBox;
	private: System::Windows::Forms::TextBox^ name5_textBox;


	private: System::Windows::Forms::TextBox^ status5_textBox;
	private: System::Windows::Forms::TextBox^ name4_textBox;


	private: System::Windows::Forms::TextBox^ status4_textBox;
	private: System::Windows::Forms::TextBox^ name3_textBox;


	private: System::Windows::Forms::TextBox^ status3_textBox;
	private: System::Windows::Forms::TextBox^ name2_textBox;


	private: System::Windows::Forms::TextBox^ status2_textBox;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ Username;
	private: System::Windows::Forms::TextBox^ name1_textBox;

	private: System::Windows::Forms::Button^ EXIT_button;
	private: System::Windows::Forms::TextBox^ status1_textBox;

	private: System::Windows::Forms::Label^ ATTENDANCE_label;
	private: System::Windows::Forms::Panel^ Logo_WHO;
	private: System::Windows::Forms::Label^ label_paanel_WHO_2;
	private: System::Windows::Forms::Label^ label_panel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ subject_title_textBox;


	protected:


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Teacher_Marks2::typeid));
			this->rollno7_textBox = (gcnew System::Windows::Forms::TextBox());
			this->rollno6_textBox = (gcnew System::Windows::Forms::TextBox());
			this->rollno5_textBox = (gcnew System::Windows::Forms::TextBox());
			this->rollno4_textBox = (gcnew System::Windows::Forms::TextBox());
			this->rollno3_textBox = (gcnew System::Windows::Forms::TextBox());
			this->rollno2_textBox = (gcnew System::Windows::Forms::TextBox());
			this->rollno1_textBox = (gcnew System::Windows::Forms::TextBox());
			this->submit_button = (gcnew System::Windows::Forms::Button());
			this->name7_textBox = (gcnew System::Windows::Forms::TextBox());
			this->status7_textBox = (gcnew System::Windows::Forms::TextBox());
			this->name6_textBox = (gcnew System::Windows::Forms::TextBox());
			this->status6_textBox = (gcnew System::Windows::Forms::TextBox());
			this->name5_textBox = (gcnew System::Windows::Forms::TextBox());
			this->status5_textBox = (gcnew System::Windows::Forms::TextBox());
			this->name4_textBox = (gcnew System::Windows::Forms::TextBox());
			this->status4_textBox = (gcnew System::Windows::Forms::TextBox());
			this->name3_textBox = (gcnew System::Windows::Forms::TextBox());
			this->status3_textBox = (gcnew System::Windows::Forms::TextBox());
			this->name2_textBox = (gcnew System::Windows::Forms::TextBox());
			this->status2_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Username = (gcnew System::Windows::Forms::Label());
			this->name1_textBox = (gcnew System::Windows::Forms::TextBox());
			this->EXIT_button = (gcnew System::Windows::Forms::Button());
			this->status1_textBox = (gcnew System::Windows::Forms::TextBox());
			this->ATTENDANCE_label = (gcnew System::Windows::Forms::Label());
			this->Logo_WHO = (gcnew System::Windows::Forms::Panel());
			this->label_paanel_WHO_2 = (gcnew System::Windows::Forms::Label());
			this->label_panel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->subject_title_textBox = (gcnew System::Windows::Forms::TextBox());
			this->Logo_WHO->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// rollno7_textBox
			// 
			this->rollno7_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno7_textBox->Location = System::Drawing::Point(657, 574);
			this->rollno7_textBox->Name = L"rollno7_textBox";
			this->rollno7_textBox->ReadOnly = true;
			this->rollno7_textBox->Size = System::Drawing::Size(192, 26);
			this->rollno7_textBox->TabIndex = 148;
			this->rollno7_textBox->TextChanged += gcnew System::EventHandler(this, &Teacher_Marks2::rollno7_textBox_TextChanged);
			// 
			// rollno6_textBox
			// 
			this->rollno6_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno6_textBox->Location = System::Drawing::Point(655, 526);
			this->rollno6_textBox->Name = L"rollno6_textBox";
			this->rollno6_textBox->ReadOnly = true;
			this->rollno6_textBox->Size = System::Drawing::Size(192, 26);
			this->rollno6_textBox->TabIndex = 147;
			// 
			// rollno5_textBox
			// 
			this->rollno5_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno5_textBox->Location = System::Drawing::Point(657, 479);
			this->rollno5_textBox->Name = L"rollno5_textBox";
			this->rollno5_textBox->ReadOnly = true;
			this->rollno5_textBox->Size = System::Drawing::Size(192, 26);
			this->rollno5_textBox->TabIndex = 146;
			// 
			// rollno4_textBox
			// 
			this->rollno4_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno4_textBox->Location = System::Drawing::Point(655, 431);
			this->rollno4_textBox->Name = L"rollno4_textBox";
			this->rollno4_textBox->ReadOnly = true;
			this->rollno4_textBox->Size = System::Drawing::Size(192, 26);
			this->rollno4_textBox->TabIndex = 145;
			// 
			// rollno3_textBox
			// 
			this->rollno3_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno3_textBox->Location = System::Drawing::Point(656, 381);
			this->rollno3_textBox->Name = L"rollno3_textBox";
			this->rollno3_textBox->ReadOnly = true;
			this->rollno3_textBox->Size = System::Drawing::Size(192, 26);
			this->rollno3_textBox->TabIndex = 144;
			// 
			// rollno2_textBox
			// 
			this->rollno2_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno2_textBox->Location = System::Drawing::Point(656, 336);
			this->rollno2_textBox->Name = L"rollno2_textBox";
			this->rollno2_textBox->ReadOnly = true;
			this->rollno2_textBox->Size = System::Drawing::Size(192, 26);
			this->rollno2_textBox->TabIndex = 143;
			// 
			// rollno1_textBox
			// 
			this->rollno1_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno1_textBox->Location = System::Drawing::Point(656, 284);
			this->rollno1_textBox->Name = L"rollno1_textBox";
			this->rollno1_textBox->ReadOnly = true;
			this->rollno1_textBox->Size = System::Drawing::Size(192, 26);
			this->rollno1_textBox->TabIndex = 142;
			this->rollno1_textBox->TextChanged += gcnew System::EventHandler(this, &Teacher_Marks2::rollno1_textBox_TextChanged);
			// 
			// submit_button
			// 
			this->submit_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->submit_button->ForeColor = System::Drawing::Color::White;
			this->submit_button->Location = System::Drawing::Point(304, 629);
			this->submit_button->Name = L"submit_button";
			this->submit_button->Size = System::Drawing::Size(179, 57);
			this->submit_button->TabIndex = 141;
			this->submit_button->Text = L"SUBMIT";
			this->submit_button->UseVisualStyleBackColor = false;
			this->submit_button->Click += gcnew System::EventHandler(this, &Teacher_Marks2::submit_button_Click);
			// 
			// name7_textBox
			// 
			this->name7_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name7_textBox->Location = System::Drawing::Point(459, 574);
			this->name7_textBox->Name = L"name7_textBox";
			this->name7_textBox->ReadOnly = true;
			this->name7_textBox->Size = System::Drawing::Size(192, 26);
			this->name7_textBox->TabIndex = 140;
			// 
			// status7_textBox
			// 
			this->status7_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->status7_textBox->Location = System::Drawing::Point(261, 574);
			this->status7_textBox->Name = L"status7_textBox";
			this->status7_textBox->Size = System::Drawing::Size(192, 26);
			this->status7_textBox->TabIndex = 139;
			// 
			// name6_textBox
			// 
			this->name6_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name6_textBox->Location = System::Drawing::Point(457, 526);
			this->name6_textBox->Name = L"name6_textBox";
			this->name6_textBox->ReadOnly = true;
			this->name6_textBox->Size = System::Drawing::Size(192, 26);
			this->name6_textBox->TabIndex = 138;
			// 
			// status6_textBox
			// 
			this->status6_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->status6_textBox->Location = System::Drawing::Point(259, 526);
			this->status6_textBox->Name = L"status6_textBox";
			this->status6_textBox->Size = System::Drawing::Size(192, 26);
			this->status6_textBox->TabIndex = 137;
			// 
			// name5_textBox
			// 
			this->name5_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name5_textBox->Location = System::Drawing::Point(459, 479);
			this->name5_textBox->Name = L"name5_textBox";
			this->name5_textBox->ReadOnly = true;
			this->name5_textBox->Size = System::Drawing::Size(192, 26);
			this->name5_textBox->TabIndex = 136;
			// 
			// status5_textBox
			// 
			this->status5_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->status5_textBox->Location = System::Drawing::Point(261, 479);
			this->status5_textBox->Name = L"status5_textBox";
			this->status5_textBox->Size = System::Drawing::Size(192, 26);
			this->status5_textBox->TabIndex = 135;
			// 
			// name4_textBox
			// 
			this->name4_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name4_textBox->Location = System::Drawing::Point(457, 431);
			this->name4_textBox->Name = L"name4_textBox";
			this->name4_textBox->ReadOnly = true;
			this->name4_textBox->Size = System::Drawing::Size(192, 26);
			this->name4_textBox->TabIndex = 134;
			// 
			// status4_textBox
			// 
			this->status4_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->status4_textBox->Location = System::Drawing::Point(259, 431);
			this->status4_textBox->Name = L"status4_textBox";
			this->status4_textBox->Size = System::Drawing::Size(192, 26);
			this->status4_textBox->TabIndex = 133;
			// 
			// name3_textBox
			// 
			this->name3_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name3_textBox->Location = System::Drawing::Point(458, 381);
			this->name3_textBox->Name = L"name3_textBox";
			this->name3_textBox->ReadOnly = true;
			this->name3_textBox->Size = System::Drawing::Size(192, 26);
			this->name3_textBox->TabIndex = 132;
			// 
			// status3_textBox
			// 
			this->status3_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->status3_textBox->Location = System::Drawing::Point(260, 381);
			this->status3_textBox->Name = L"status3_textBox";
			this->status3_textBox->Size = System::Drawing::Size(192, 26);
			this->status3_textBox->TabIndex = 131;
			// 
			// name2_textBox
			// 
			this->name2_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name2_textBox->Location = System::Drawing::Point(458, 336);
			this->name2_textBox->Name = L"name2_textBox";
			this->name2_textBox->ReadOnly = true;
			this->name2_textBox->Size = System::Drawing::Size(192, 26);
			this->name2_textBox->TabIndex = 130;
			this->name2_textBox->TextChanged += gcnew System::EventHandler(this, &Teacher_Marks2::name2_textBox_TextChanged);
			// 
			// status2_textBox
			// 
			this->status2_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->status2_textBox->Location = System::Drawing::Point(260, 336);
			this->status2_textBox->Name = L"status2_textBox";
			this->status2_textBox->Size = System::Drawing::Size(192, 26);
			this->status2_textBox->TabIndex = 129;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->label2->Location = System::Drawing::Point(503, 241);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 30);
			this->label2->TabIndex = 128;
			this->label2->Text = L"Name";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->label1->Location = System::Drawing::Point(301, 242);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 30);
			this->label1->TabIndex = 127;
			this->label1->Text = L"Obtain %";
			// 
			// Username
			// 
			this->Username->AutoSize = true;
			this->Username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->Username->Location = System::Drawing::Point(669, 241);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(157, 30);
			this->Username->TabIndex = 126;
			this->Username->Text = L"Roll Number";
			// 
			// name1_textBox
			// 
			this->name1_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name1_textBox->Location = System::Drawing::Point(458, 284);
			this->name1_textBox->Name = L"name1_textBox";
			this->name1_textBox->ReadOnly = true;
			this->name1_textBox->Size = System::Drawing::Size(192, 26);
			this->name1_textBox->TabIndex = 125;
			this->name1_textBox->TextChanged += gcnew System::EventHandler(this, &Teacher_Marks2::name1_textBox_TextChanged);
			// 
			// EXIT_button
			// 
			this->EXIT_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->EXIT_button->ForeColor = System::Drawing::Color::White;
			this->EXIT_button->Location = System::Drawing::Point(612, 629);
			this->EXIT_button->Name = L"EXIT_button";
			this->EXIT_button->Size = System::Drawing::Size(179, 57);
			this->EXIT_button->TabIndex = 124;
			this->EXIT_button->Text = L"EXIT";
			this->EXIT_button->UseVisualStyleBackColor = false;
			this->EXIT_button->Click += gcnew System::EventHandler(this, &Teacher_Marks2::EXIT_button_Click);
			// 
			// status1_textBox
			// 
			this->status1_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->status1_textBox->Location = System::Drawing::Point(260, 284);
			this->status1_textBox->Name = L"status1_textBox";
			this->status1_textBox->Size = System::Drawing::Size(192, 26);
			this->status1_textBox->TabIndex = 123;
			this->status1_textBox->TextChanged += gcnew System::EventHandler(this, &Teacher_Marks2::status1_textBox_TextChanged);
			// 
			// ATTENDANCE_label
			// 
			this->ATTENDANCE_label->AutoSize = true;
			this->ATTENDANCE_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24));
			this->ATTENDANCE_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->ATTENDANCE_label->Location = System::Drawing::Point(426, 51);
			this->ATTENDANCE_label->Name = L"ATTENDANCE_label";
			this->ATTENDANCE_label->Size = System::Drawing::Size(243, 55);
			this->ATTENDANCE_label->TabIndex = 122;
			this->ATTENDANCE_label->Text = L"SUBJECT";
			// 
			// Logo_WHO
			// 
			this->Logo_WHO->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->Logo_WHO->Controls->Add(this->label_paanel_WHO_2);
			this->Logo_WHO->Controls->Add(this->label_panel);
			this->Logo_WHO->Controls->Add(this->pictureBox1);
			this->Logo_WHO->Location = System::Drawing::Point(-3, -2);
			this->Logo_WHO->Name = L"Logo_WHO";
			this->Logo_WHO->Size = System::Drawing::Size(235, 763);
			this->Logo_WHO->TabIndex = 121;
			// 
			// label_paanel_WHO_2
			// 
			this->label_paanel_WHO_2->AutoSize = true;
			this->label_paanel_WHO_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label_paanel_WHO_2->ForeColor = System::Drawing::Color::White;
			this->label_paanel_WHO_2->Location = System::Drawing::Point(60, 471);
			this->label_paanel_WHO_2->Name = L"label_paanel_WHO_2";
			this->label_paanel_WHO_2->Size = System::Drawing::Size(109, 40);
			this->label_paanel_WHO_2->TabIndex = 2;
			this->label_paanel_WHO_2->Text = L"Wave";
			// 
			// label_panel
			// 
			this->label_panel->AutoSize = true;
			this->label_panel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label_panel->ForeColor = System::Drawing::Color::White;
			this->label_panel->Location = System::Drawing::Point(39, 430);
			this->label_panel->Name = L"label_panel";
			this->label_panel->Size = System::Drawing::Size(149, 40);
			this->label_panel->TabIndex = 1;
			this->label_panel->Text = L"Teacher";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-2, 206);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(234, 205);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// subject_title_textBox
			// 
			this->subject_title_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->subject_title_textBox->Location = System::Drawing::Point(415, 134);
			this->subject_title_textBox->Name = L"subject_title_textBox";
			this->subject_title_textBox->Size = System::Drawing::Size(259, 26);
			this->subject_title_textBox->TabIndex = 120;
			this->subject_title_textBox->TextChanged += gcnew System::EventHandler(this, &Teacher_Marks2::subject_title_textBox_TextChanged);
			// 
			// Teacher_Marks2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(904, 758);
			this->Controls->Add(this->rollno7_textBox);
			this->Controls->Add(this->rollno6_textBox);
			this->Controls->Add(this->rollno5_textBox);
			this->Controls->Add(this->rollno4_textBox);
			this->Controls->Add(this->rollno3_textBox);
			this->Controls->Add(this->rollno2_textBox);
			this->Controls->Add(this->rollno1_textBox);
			this->Controls->Add(this->submit_button);
			this->Controls->Add(this->name7_textBox);
			this->Controls->Add(this->status7_textBox);
			this->Controls->Add(this->name6_textBox);
			this->Controls->Add(this->status6_textBox);
			this->Controls->Add(this->name5_textBox);
			this->Controls->Add(this->status5_textBox);
			this->Controls->Add(this->name4_textBox);
			this->Controls->Add(this->status4_textBox);
			this->Controls->Add(this->name3_textBox);
			this->Controls->Add(this->status3_textBox);
			this->Controls->Add(this->name2_textBox);
			this->Controls->Add(this->status2_textBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Username);
			this->Controls->Add(this->name1_textBox);
			this->Controls->Add(this->EXIT_button);
			this->Controls->Add(this->status1_textBox);
			this->Controls->Add(this->ATTENDANCE_label);
			this->Controls->Add(this->Logo_WHO);
			this->Controls->Add(this->subject_title_textBox);
			this->MaximumSize = System::Drawing::Size(926, 814);
			this->MinimumSize = System::Drawing::Size(926, 814);
			this->Name = L"Teacher_Marks2";
			this->Text = L"Teacher_Marks2";
			this->Load += gcnew System::EventHandler(this, &Teacher_Marks2::Teacher_Marks2_Load);
			this->Logo_WHO->ResumeLayout(false);
			this->Logo_WHO->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EXIT_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void status1_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void rollno7_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void name1_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void name2_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void rollno1_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void Teacher_Marks2_Load(System::Object^ sender, System::EventArgs^ e) {
		ReadStudents();
		for (int i = 1; i <= GetStudents(); ++i) {
			FillStudentData(i);
		}
		//FillTitle("Teacher_Marks2.txt");
	}
	private: System::Void subject_title_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void submit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		//String^ title;
		GetTitle(title);
		if (ReturnTitle() == "QUIZ") {
			Quiz quiz;
			bool data1 = false;
			bool data2 = false;
			bool data3 = false;
			bool data4 = false;
			bool data5 = false;
			bool data6 = false;
			bool data7 = false;

			ProcessInput(status1_textBox);
			ProcessInput(status2_textBox);
			ProcessInput(status3_textBox);
			ProcessInput(status4_textBox);
			ProcessInput(status5_textBox);
			ProcessInput(status6_textBox);
			ProcessInput(status7_textBox);

			if (name1_textBox == nullptr && status1_textBox != nullptr) {
				MessageBox::Show("Invalid Student Data");
				data1 = true;
				//status1_textBox->Clear();
			}
			else if (name2_textBox->Text == "" && status2_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data2 = true;
				//status2_textBox->Clear();
			}
			else if (name3_textBox->Text == "" && status3_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data3 = true;
				//status3_textBox->Clear();
			}
			else if (name4_textBox->Text == "" && status4_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data4 = true;
				//status4_textBox->Clear();
			}
			else if (name5_textBox->Text == "" && status5_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data5 = true;
				//status5_textBox->Clear();
			}
			else if (name6_textBox->Text == "" && status6_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data6 = true;
				//status6_textBox->Clear();
			}
			else if (name7_textBox->Text == "" && status7_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data7 = true;
				//status7_textBox->Clear();
			}
			else if (subject_title_textBox->Text == "") {
				MessageBox::Show("Invalid Subject Title");
				subject_title_textBox->Clear();
			}
			else if (rollno1_textBox->Text == "" && status1_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data1 = true;
				//status1_textBox->Clear();
			}
			else if (rollno2_textBox->Text == "" && status2_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data2 = true;
				//status2_textBox->Clear();

			}
			else if (rollno3_textBox->Text == "" && status3_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data3 = true;
				//status3_textBox->Clear();
			}
			else if (rollno4_textBox->Text == "" && status4_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data4 = true;
				//status4_textBox->Clear();

			}
			else if (rollno5_textBox->Text == "" && status5_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data5 = true;
				//status5_textBox->Clear();
			}
			else if (rollno6_textBox->Text == "" && status6_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data6 = true;
				//status6_textBox->Clear();
			}
			else if (rollno7_textBox->Text == "" && status7_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data7 = true;
				//status7_textBox->Clear();
			}
			else if (name1_textBox->Text != "" && rollno1_textBox->Text != "" && status1_textBox->Text == "") {
				MessageBox::Show("Invalid Student Data");
				data1 = true;
			}
			else if (name2_textBox->Text != "" && rollno2_textBox->Text != "" && status2_textBox->Text == "") {
				MessageBox::Show("Invalid Student Data");
				data2 = true;
			}
			else if (name3_textBox->Text != "" && rollno3_textBox->Text != "" && status3_textBox->Text == "") {
				MessageBox::Show("Invalid Student Data");
				data3 = true;
			}
			else if (name4_textBox->Text != "" && rollno4_textBox->Text != "" && status4_textBox->Text == "") {
				MessageBox::Show("Invalid Student Data");
				data4 = true;
			}
			else if (name5_textBox->Text != "" && rollno5_textBox->Text != "" && status5_textBox->Text == "") {
				MessageBox::Show("Invalid Student Data");
				data5 = true;
			}
			else if (name6_textBox->Text != "" && rollno6_textBox->Text != "" && status6_textBox->Text == "") {
				MessageBox::Show("Invalid Student Data");
				data6 = true;
			}
			else if (name7_textBox->Text != "" && rollno7_textBox->Text != "" && status7_textBox->Text == "") {
				MessageBox::Show("Invalid Student Data");
				data7 = true;
			}




			bool error = false;

			std::string validation1 = msclr::interop::marshal_as<std::string>(status1_textBox->Text);
			std::string validation2 = msclr::interop::marshal_as<std::string>(status2_textBox->Text);
			std::string validation3 = msclr::interop::marshal_as<std::string>(status3_textBox->Text);
			std::string validation4 = msclr::interop::marshal_as<std::string>(status4_textBox->Text);
			std::string validation5 = msclr::interop::marshal_as<std::string>(status5_textBox->Text);
			std::string validation6 = msclr::interop::marshal_as<std::string>(status6_textBox->Text);
			std::string validation7 = msclr::interop::marshal_as<std::string>(status7_textBox->Text);

			if (status1_textBox->Text != "") {
				if (!(validation1[0] >= '0' && validation1[0] <= '9')) {
					error = true;
				}
				for (int i = 1; validation1[i] != '\0'; ++i) {
					if (!(validation1[i] >= '0' && validation1[i] <= '9')) {
						error = true;
					}
				}
				int marks = std::stoi(validation1);
				if (marks <= 0 || marks > 100) {
					error = true;
				}
			}
			if (error) {
				MessageBox::Show("Invalid Student Data");
				data1 = true;
				//status1_textBox->Clear();
			}

			error = false;
			if (status2_textBox->Text != "") {
				if (!(validation2[0] >= '0' && validation2[0] <= '9')) {
					error = true;
				}
				for (int i = 1; validation2[i] != '\0'; ++i) {
					if (!(validation2[i] >= '0' && validation2[i] <= '9')) {
						error = true;
					}
				}
				int marks = std::stoi(validation2);
				if (marks <= 0 || marks > 100) {
					error = true;
				}
			}

			if (error) {
				MessageBox::Show("Invalid Student Data");
				data2 = true;
				//status2_textBox->Clear();
			}

			error = false;


			if (status3_textBox->Text != "") {
				if (!(validation3[0] >= '0' && validation3[0] <= '9')) {
					error = true;
				}
				for (int i = 1; validation3[i] != '\0'; ++i) {
					if (!(validation3[i] >= '0' && validation3[i] <= '9')) {
						error = true;
					}
				}
				int marks = std::stoi(validation3);
				if (marks <= 0 || marks > 100) {
					error = true;
				}
			}

			if (error) {
				MessageBox::Show("Invalid Student Data");
				data3 = true;
				//status3_textBox->Clear();
			}

			error = false;


			if (status4_textBox->Text != "") {
				if (!(validation4[0] >= '0' && validation4[0] <= '9')) {
					error = true;
				}
				for (int i = 1; validation4[i] != '\0'; ++i) {
					if (!(validation4[i] >= '0' && validation4[i] <= '9')) {
						error = true;
					}
				}
				int marks = std::stoi(validation4);
				if (marks <= 0 || marks > 100) {
					error = true;
				}
			}

			if (error) {
				MessageBox::Show("Invalid Student Data");
				data4 = true;
				//status4_textBox->Clear();
			}

			error = false;

			if (status5_textBox->Text != "") {
				if (!(validation5[0] >= '0' && validation5[0] <= '9')) {
					error = true;
				}
				for (int i = 1; validation5[i] != '\0'; ++i) {
					if (!(validation5[i] >= '0' && validation5[i] <= '9')) {
						error = true;
					}
				}
				int marks = std::stoi(validation5);
				if (marks <= 0 || marks > 100) {
					error = true;
				}
			}

			if (error) {
				MessageBox::Show("Invalid Student Data");
				data5 = true;
				//status5_textBox->Clear();
			}

			error = false;

			if (status6_textBox->Text != "") {
				if (!(validation6[0] >= '0' && validation6[0] <= '9')) {
					error = true;
				}
				for (int i = 1; validation6[i] != '\0'; ++i) {
					if (!(validation6[i] >= '0' && validation6[i] <= '9')) {
						error = true;
					}
				}
				int marks = std::stoi(validation6);
				if (marks <= 0 || marks > 100) {
					error = true;
				}
			}

			if (error) {
				MessageBox::Show("Invalid Student Data");
				data6 = true;
				//status6_textBox->Clear();
			}

			error = false;

			if (status7_textBox->Text != "") {
				if (!(validation7[0] >= '0' && validation7[0] <= '9')) {
					error = true;
				}
				for (int i = 1; validation7[i] != '\0'; ++i) {
					if (!(validation7[i] >= '0' && validation7[i] <= '9')) {
						error = true;
					}
				}
				int marks = std::stoi(validation7);
				if (marks <= 0 || marks > 100) {
					error = true;
				}
			}

			if (error) {
				MessageBox::Show("Invalid Student Data");
				data7 = true;
				//status7_textBox->Clear();
			}


			if (subject_title_textBox->Text != "OOP" && subject_title_textBox->Text != "ISE" && subject_title_textBox->Text != "DS" && subject_title_textBox->Text != "DLD" && subject_title_textBox->Text != "MVC") {
				MessageBox::Show("Invalid Subject Title");
				MessageBox::Show("Write OOP, DS, ISE, DLD, or MVC!");
				subject_title_textBox->Clear();
			}



			if (name1_textBox->Text != "" && rollno1_textBox->Text != "" && status1_textBox->Text != "") {
				data1 = false;
			}
			else if(name1_textBox->Text == "" && rollno1_textBox->Text == "" && status1_textBox->Text == "") {
				data1 = false;
			}
			else {
				data1 = true;
			}
			
			if (name2_textBox->Text != "" && rollno2_textBox->Text != "" && status2_textBox->Text != "") {
				data2 = false;
			}
			else if(name2_textBox->Text == "" && rollno2_textBox->Text == "" && status2_textBox->Text == "") {
				data2 = false;
			}
			else {
				data2 = true;
			}

			if (name3_textBox->Text != "" && rollno3_textBox->Text != "" && status3_textBox->Text != "") {
				data3 = false;
			}
			else if (name3_textBox->Text == "" && rollno3_textBox->Text == "" && status3_textBox->Text == "") {
				data3 = false;
			}
			else {
				data3 = true;
			}
			if (name4_textBox->Text != "" && rollno4_textBox->Text != "" && status4_textBox->Text != "") {
				data4 = false;
			}
			else if (name4_textBox->Text == "" && rollno4_textBox->Text == "" && status4_textBox->Text == "") {
				data4 = false;
			}
			else {
				data4 = true;
			}

			if (name5_textBox->Text != "" && rollno5_textBox->Text != "" && status5_textBox->Text != "") {
				data5 = false;
			}
			else if (name5_textBox->Text == "" && rollno5_textBox->Text == "" && status5_textBox->Text == "") {
				data5 = false;
			}
			else {
				data5 = true;
			}

			if (name6_textBox->Text != "" && rollno6_textBox->Text != "" && status6_textBox->Text != "") {
				data6 = false;
			}
			else if (name6_textBox->Text == "" && rollno6_textBox->Text == "" && status6_textBox->Text == "") {
				data6 = false;
			}
			else {
				data6 = true;
			}

			if (name7_textBox->Text != "" && rollno7_textBox->Text != "" && status7_textBox->Text != "") {
				data7 = false;
			}
			else if (name7_textBox->Text == "" && rollno7_textBox->Text == "" && status7_textBox->Text == "") {
				data7 = false;
			}
			else {
				data7 = true;
			}



			if (data1 == false && data2 == false && data3 == false && data4 == false && data5 == false && data6 == false && data7 == false) {
				ProcessInput(status1_textBox);
				ProcessInput(status2_textBox);
				ProcessInput(status3_textBox);
				ProcessInput(status4_textBox);
				ProcessInput(status5_textBox);
				ProcessInput(status6_textBox);
				ProcessInput(status7_textBox);
			}

			if (subject_title_textBox->Text != "" && data1 == false && data2 == false && data3 == false && data4 == false && data5 == false && data6 == false && data7 == false) {
				quiz.WriteMarks("Quiz.txt", subject_title_textBox->Text,
					status1_textBox->Text, name1_textBox->Text, rollno1_textBox->Text,
					status2_textBox->Text, name2_textBox->Text, rollno2_textBox->Text,
					status3_textBox->Text, name3_textBox->Text, rollno3_textBox->Text,
					status4_textBox->Text, name4_textBox->Text, rollno4_textBox->Text,
					status5_textBox->Text, name5_textBox->Text, rollno5_textBox->Text,
					status6_textBox->Text, name6_textBox->Text, rollno6_textBox->Text,
					status7_textBox->Text, name7_textBox->Text, rollno7_textBox->Text);
				MessageBox::Show("Marks Submitted");
			}

		}

		/////////////////////////////////////////////////////////////////////////////
		else if (ReturnTitle() == "ASSIGNMENT") {
			Quiz quiz;
			bool data1 = false;
			bool data2 = false;
			bool data3 = false;
			bool data4 = false;
			bool data5 = false;
			bool data6 = false;
			bool data7 = false;

			ProcessInput(status1_textBox);
			ProcessInput(status2_textBox);
			ProcessInput(status3_textBox);
			ProcessInput(status4_textBox);
			ProcessInput(status5_textBox);
			ProcessInput(status6_textBox);
			ProcessInput(status7_textBox);

			if (name1_textBox == nullptr && status1_textBox != nullptr) {
				MessageBox::Show("Invalid Student Data");
				data1 = true;
				//status1_textBox->Clear();
			}
			else if (name2_textBox->Text == "" && status2_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data2 = true;
				//status2_textBox->Clear();
			}
			else if (name3_textBox->Text == "" && status3_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data3 = true;
				//status3_textBox->Clear();
			}
			else if (name4_textBox->Text == "" && status4_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data4 = true;
				//status4_textBox->Clear();
			}
			else if (name5_textBox->Text == "" && status5_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data5 = true;
				//status5_textBox->Clear();
			}
			else if (name6_textBox->Text == "" && status6_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data6 = true;
				//status6_textBox->Clear();
			}
			else if (name7_textBox->Text == "" && status7_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data7 = true;
				//status7_textBox->Clear();
			}
			else if (subject_title_textBox->Text == "") {
				MessageBox::Show("Invalid Subject Title");
				subject_title_textBox->Clear();
			}
			else if (rollno1_textBox->Text == "" && status1_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data1 = true;
				//status1_textBox->Clear();
			}
			else if (rollno2_textBox->Text == "" && status2_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data2 = true;
				//status2_textBox->Clear();

			}
			else if (rollno3_textBox->Text == "" && status3_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data3 = true;
				//status3_textBox->Clear();
			}
			else if (rollno4_textBox->Text == "" && status4_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data4 = true;
				//status4_textBox->Clear();

			}
			else if (rollno5_textBox->Text == "" && status5_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data5 = true;
				//status5_textBox->Clear();
			}
			else if (rollno6_textBox->Text == "" && status6_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data6 = true;
				//status6_textBox->Clear();
			}
			else if (rollno7_textBox->Text == "" && status7_textBox->Text != "") {
				MessageBox::Show("Invalid Student Data");
				data7 = true;
				//status7_textBox->Clear();
			}
			else if (name1_textBox->Text != "" && rollno1_textBox->Text != "" && status1_textBox->Text == "") {
				MessageBox::Show("Invalid Student Data");
				data1 = true;
			}
			else if (name2_textBox->Text != "" && rollno2_textBox->Text != "" && status2_textBox->Text == "") {
				MessageBox::Show("Invalid Student Data");
				data2 = true;
			}
			else if (name3_textBox->Text != "" && rollno3_textBox->Text != "" && status3_textBox->Text == "") {
				MessageBox::Show("Invalid Student Data");
				data3 = true;
			}
			else if (name4_textBox->Text != "" && rollno4_textBox->Text != "" && status4_textBox->Text == "") {
				MessageBox::Show("Invalid Student Data");
				data4 = true;
			}
			else if (name5_textBox->Text != "" && rollno5_textBox->Text != "" && status5_textBox->Text == "") {
				MessageBox::Show("Invalid Student Data");
				data5 = true;
			}
			else if (name6_textBox->Text != "" && rollno6_textBox->Text != "" && status6_textBox->Text == "") {
				MessageBox::Show("Invalid Student Data");
				data6 = true;
			}
			else if (name7_textBox->Text != "" && rollno7_textBox->Text != "" && status7_textBox->Text == "") {
				MessageBox::Show("Invalid Student Data");
				data7 = true;
			}




			bool error = false;

			std::string validation1 = msclr::interop::marshal_as<std::string>(status1_textBox->Text);
			std::string validation2 = msclr::interop::marshal_as<std::string>(status2_textBox->Text);
			std::string validation3 = msclr::interop::marshal_as<std::string>(status3_textBox->Text);
			std::string validation4 = msclr::interop::marshal_as<std::string>(status4_textBox->Text);
			std::string validation5 = msclr::interop::marshal_as<std::string>(status5_textBox->Text);
			std::string validation6 = msclr::interop::marshal_as<std::string>(status6_textBox->Text);
			std::string validation7 = msclr::interop::marshal_as<std::string>(status7_textBox->Text);

			if (status1_textBox->Text != "") {
				if (!(validation1[0] >= '0' && validation1[0] <= '9')) {
					error = true;
				}
				for (int i = 1; validation1[i] != '\0'; ++i) {
					if (!(validation1[i] >= '0' && validation1[i] <= '9')) {
						error = true;
					}
				}
				int marks = std::stoi(validation1);
				if (marks <= 0 || marks > 100) {
					error = true;
				}
			}
			if (error) {
				MessageBox::Show("Invalid Student Data");
				data1 = true;
				//status1_textBox->Clear();
			}

			error = false;
			if (status2_textBox->Text != "") {
				if (!(validation2[0] >= '0' && validation2[0] <= '9')) {
					error = true;
				}
				for (int i = 1; validation2[i] != '\0'; ++i) {
					if (!(validation2[i] >= '0' && validation2[i] <= '9')) {
						error = true;
					}
				}
				int marks = std::stoi(validation2);
				if (marks <= 0 || marks > 100) {
					error = true;
				}
			}

			if (error) {
				MessageBox::Show("Invalid Student Data");
				data2 = true;
				//status2_textBox->Clear();
			}

			error = false;


			if (status3_textBox->Text != "") {
				if (!(validation3[0] >= '0' && validation3[0] <= '9')) {
					error = true;
				}
				for (int i = 1; validation3[i] != '\0'; ++i) {
					if (!(validation3[i] >= '0' && validation3[i] <= '9')) {
						error = true;
					}
				}
				int marks = std::stoi(validation3);
				if (marks <= 0 || marks > 100) {
					error = true;
				}
			}

			if (error) {
				MessageBox::Show("Invalid Student Data");
				data3 = true;
				//status3_textBox->Clear();
			}

			error = false;


			if (status4_textBox->Text != "") {
				if (!(validation4[0] >= '0' && validation4[0] <= '9')) {
					error = true;
				}
				for (int i = 1; validation4[i] != '\0'; ++i) {
					if (!(validation4[i] >= '0' && validation4[i] <= '9')) {
						error = true;
					}
				}
				int marks = std::stoi(validation4);
				if (marks <= 0 || marks > 100) {
					error = true;
				}
			}

			if (error) {
				MessageBox::Show("Invalid Student Data");
				data4 = true;
				//status4_textBox->Clear();
			}

			error = false;

			if (status5_textBox->Text != "") {
				if (!(validation5[0] >= '0' && validation5[0] <= '9')) {
					error = true;
				}
				for (int i = 1; validation5[i] != '\0'; ++i) {
					if (!(validation5[i] >= '0' && validation5[i] <= '9')) {
						error = true;
					}
				}
				int marks = std::stoi(validation5);
				if (marks <= 0 || marks > 100) {
					error = true;
				}
			}

			if (error) {
				MessageBox::Show("Invalid Student Data");
				data5 = true;
				//status5_textBox->Clear();
			}

			error = false;

			if (status6_textBox->Text != "") {
				if (!(validation6[0] >= '0' && validation6[0] <= '9')) {
					error = true;
				}
				for (int i = 1; validation6[i] != '\0'; ++i) {
					if (!(validation6[i] >= '0' && validation6[i] <= '9')) {
						error = true;
					}
				}
				int marks = std::stoi(validation6);
				if (marks <= 0 || marks > 100) {
					error = true;
				}
			}

			if (error) {
				MessageBox::Show("Invalid Student Data");
				data6 = true;
				//status6_textBox->Clear();
			}

			error = false;

			if (status7_textBox->Text != "") {
				if (!(validation7[0] >= '0' && validation7[0] <= '9')) {
					error = true;
				}
				for (int i = 1; validation7[i] != '\0'; ++i) {
					if (!(validation7[i] >= '0' && validation7[i] <= '9')) {
						error = true;
					}
				}
				int marks = std::stoi(validation7);
				if (marks <= 0 || marks > 100) {
					error = true;
				}
			}

			if (error) {
				MessageBox::Show("Invalid Student Data");
				data7 = true;
				//status7_textBox->Clear();
			}


			if (subject_title_textBox->Text != "OOP" && subject_title_textBox->Text != "ISE" && subject_title_textBox->Text != "DS" && subject_title_textBox->Text != "DLD" && subject_title_textBox->Text != "MVC") {
				MessageBox::Show("Invalid Subject Title");
				MessageBox::Show("Write OOP, DS, ISE, DLD, or MVC!");
				subject_title_textBox->Clear();
			}



			if (name1_textBox->Text != "" && rollno1_textBox->Text != "" && status1_textBox->Text != "") {
				data1 = false;
			}
			else if (name1_textBox->Text == "" && rollno1_textBox->Text == "" && status1_textBox->Text == "") {
				data1 = false;
			}
			else {
				data1 = true;
			}

			if (name2_textBox->Text != "" && rollno2_textBox->Text != "" && status2_textBox->Text != "") {
				data2 = false;
			}
			else if (name2_textBox->Text == "" && rollno2_textBox->Text == "" && status2_textBox->Text == "") {
				data2 = false;
			}
			else {
				data2 = true;
			}

			if (name3_textBox->Text != "" && rollno3_textBox->Text != "" && status3_textBox->Text != "") {
				data3 = false;
			}
			else if (name3_textBox->Text == "" && rollno3_textBox->Text == "" && status3_textBox->Text == "") {
				data3 = false;
			}
			else {
				data3 = true;
			}
			if (name4_textBox->Text != "" && rollno4_textBox->Text != "" && status4_textBox->Text != "") {
				data4 = false;
			}
			else if (name4_textBox->Text == "" && rollno4_textBox->Text == "" && status4_textBox->Text == "") {
				data4 = false;
			}
			else {
				data4 = true;
			}

			if (name5_textBox->Text != "" && rollno5_textBox->Text != "" && status5_textBox->Text != "") {
				data5 = false;
			}
			else if (name5_textBox->Text == "" && rollno5_textBox->Text == "" && status5_textBox->Text == "") {
				data5 = false;
			}
			else {
				data5 = true;
			}

			if (name6_textBox->Text != "" && rollno6_textBox->Text != "" && status6_textBox->Text != "") {
				data6 = false;
			}
			else if (name6_textBox->Text == "" && rollno6_textBox->Text == "" && status6_textBox->Text == "") {
				data6 = false;
			}
			else {
				data6 = true;
			}

			if (name7_textBox->Text != "" && rollno7_textBox->Text != "" && status7_textBox->Text != "") {
				data7 = false;
			}
			else if (name7_textBox->Text == "" && rollno7_textBox->Text == "" && status7_textBox->Text == "") {
				data7 = false;
			}
			else {
				data7 = true;
			}



			if (data1 == false && data2 == false && data3 == false && data4 == false && data5 == false && data6 == false && data7 == false) {
				ProcessInput(status1_textBox);
				ProcessInput(status2_textBox);
				ProcessInput(status3_textBox);
				ProcessInput(status4_textBox);
				ProcessInput(status5_textBox);
				ProcessInput(status6_textBox);
				ProcessInput(status7_textBox);
			}

			if (subject_title_textBox->Text != "" && data1 == false && data2 == false && data3 == false && data4 == false && data5 == false && data6 == false && data7 == false) {
				quiz.WriteMarks("Assignment.txt", subject_title_textBox->Text,
					status1_textBox->Text, name1_textBox->Text, rollno1_textBox->Text,
					status2_textBox->Text, name2_textBox->Text, rollno2_textBox->Text,
					status3_textBox->Text, name3_textBox->Text, rollno3_textBox->Text,
					status4_textBox->Text, name4_textBox->Text, rollno4_textBox->Text,
					status5_textBox->Text, name5_textBox->Text, rollno5_textBox->Text,
					status6_textBox->Text, name6_textBox->Text, rollno6_textBox->Text,
					status7_textBox->Text, name7_textBox->Text, rollno7_textBox->Text);
				MessageBox::Show("Marks Submitted");
			}

		}
		///////////////////////////////////////////////////////////////////////////
			else if (ReturnTitle() == "MID") {
				Quiz quiz;
				bool data1 = false;
				bool data2 = false;
				bool data3 = false;
				bool data4 = false;
				bool data5 = false;
				bool data6 = false;
				bool data7 = false;

				ProcessInput(status1_textBox);
				ProcessInput(status2_textBox);
				ProcessInput(status3_textBox);
				ProcessInput(status4_textBox);
				ProcessInput(status5_textBox);
				ProcessInput(status6_textBox);
				ProcessInput(status7_textBox);

				if (name1_textBox == nullptr && status1_textBox != nullptr) {
					MessageBox::Show("Invalid Student Data");
					data1 = true;
					//status1_textBox->Clear();
				}
				else if (name2_textBox->Text == "" && status2_textBox->Text != "") {
					MessageBox::Show("Invalid Student Data");
					data2 = true;
					//status2_textBox->Clear();
				}
				else if (name3_textBox->Text == "" && status3_textBox->Text != "") {
					MessageBox::Show("Invalid Student Data");
					data3 = true;
					//status3_textBox->Clear();
				}
				else if (name4_textBox->Text == "" && status4_textBox->Text != "") {
					MessageBox::Show("Invalid Student Data");
					data4 = true;
					//status4_textBox->Clear();
				}
				else if (name5_textBox->Text == "" && status5_textBox->Text != "") {
					MessageBox::Show("Invalid Student Data");
					data5 = true;
					//status5_textBox->Clear();
				}
				else if (name6_textBox->Text == "" && status6_textBox->Text != "") {
					MessageBox::Show("Invalid Student Data");
					data6 = true;
					//status6_textBox->Clear();
				}
				else if (name7_textBox->Text == "" && status7_textBox->Text != "") {
					MessageBox::Show("Invalid Student Data");
					data7 = true;
					//status7_textBox->Clear();
				}
				else if (subject_title_textBox->Text == "") {
					MessageBox::Show("Invalid Subject Title");
					subject_title_textBox->Clear();
				}
				else if (rollno1_textBox->Text == "" && status1_textBox->Text != "") {
					MessageBox::Show("Invalid Student Data");
					data1 = true;
					//status1_textBox->Clear();
				}
				else if (rollno2_textBox->Text == "" && status2_textBox->Text != "") {
					MessageBox::Show("Invalid Student Data");
					data2 = true;
					//status2_textBox->Clear();

				}
				else if (rollno3_textBox->Text == "" && status3_textBox->Text != "") {
					MessageBox::Show("Invalid Student Data");
					data3 = true;
					//status3_textBox->Clear();
				}
				else if (rollno4_textBox->Text == "" && status4_textBox->Text != "") {
					MessageBox::Show("Invalid Student Data");
					data4 = true;
					//status4_textBox->Clear();

				}
				else if (rollno5_textBox->Text == "" && status5_textBox->Text != "") {
					MessageBox::Show("Invalid Student Data");
					data5 = true;
					//status5_textBox->Clear();
				}
				else if (rollno6_textBox->Text == "" && status6_textBox->Text != "") {
					MessageBox::Show("Invalid Student Data");
					data6 = true;
					//status6_textBox->Clear();
				}
				else if (rollno7_textBox->Text == "" && status7_textBox->Text != "") {
					MessageBox::Show("Invalid Student Data");
					data7 = true;
					//status7_textBox->Clear();
				}
				else if (name1_textBox->Text != "" && rollno1_textBox->Text != "" && status1_textBox->Text == "") {
					MessageBox::Show("Invalid Student Data");
					data1 = true;
				}
				else if (name2_textBox->Text != "" && rollno2_textBox->Text != "" && status2_textBox->Text == "") {
					MessageBox::Show("Invalid Student Data");
					data2 = true;
				}
				else if (name3_textBox->Text != "" && rollno3_textBox->Text != "" && status3_textBox->Text == "") {
					MessageBox::Show("Invalid Student Data");
					data3 = true;
				}
				else if (name4_textBox->Text != "" && rollno4_textBox->Text != "" && status4_textBox->Text == "") {
					MessageBox::Show("Invalid Student Data");
					data4 = true;
				}
				else if (name5_textBox->Text != "" && rollno5_textBox->Text != "" && status5_textBox->Text == "") {
					MessageBox::Show("Invalid Student Data");
					data5 = true;
				}
				else if (name6_textBox->Text != "" && rollno6_textBox->Text != "" && status6_textBox->Text == "") {
					MessageBox::Show("Invalid Student Data");
					data6 = true;
				}
				else if (name7_textBox->Text != "" && rollno7_textBox->Text != "" && status7_textBox->Text == "") {
					MessageBox::Show("Invalid Student Data");
					data7 = true;
				}




				bool error = false;

				std::string validation1 = msclr::interop::marshal_as<std::string>(status1_textBox->Text);
				std::string validation2 = msclr::interop::marshal_as<std::string>(status2_textBox->Text);
				std::string validation3 = msclr::interop::marshal_as<std::string>(status3_textBox->Text);
				std::string validation4 = msclr::interop::marshal_as<std::string>(status4_textBox->Text);
				std::string validation5 = msclr::interop::marshal_as<std::string>(status5_textBox->Text);
				std::string validation6 = msclr::interop::marshal_as<std::string>(status6_textBox->Text);
				std::string validation7 = msclr::interop::marshal_as<std::string>(status7_textBox->Text);

				if (status1_textBox->Text != "") {
					if (!(validation1[0] >= '0' && validation1[0] <= '9')) {
						error = true;
					}
					for (int i = 1; validation1[i] != '\0'; ++i) {
						if (!(validation1[i] >= '0' && validation1[i] <= '9')) {
							error = true;
						}
					}
					int marks = std::stoi(validation1);
					if (marks <= 0 || marks > 100) {
						error = true;
					}
				}
				if (error) {
					MessageBox::Show("Invalid Student Data");
					data1 = true;
					//status1_textBox->Clear();
				}

				error = false;
				if (status2_textBox->Text != "") {
					if (!(validation2[0] >= '0' && validation2[0] <= '9')) {
						error = true;
					}
					for (int i = 1; validation2[i] != '\0'; ++i) {
						if (!(validation2[i] >= '0' && validation2[i] <= '9')) {
							error = true;
						}
					}
					int marks = std::stoi(validation2);
					if (marks <= 0 || marks > 100) {
						error = true;
					}
				}

				if (error) {
					MessageBox::Show("Invalid Student Data");
					data2 = true;
					//status2_textBox->Clear();
				}

				error = false;


				if (status3_textBox->Text != "") {
					if (!(validation3[0] >= '0' && validation3[0] <= '9')) {
						error = true;
					}
					for (int i = 1; validation3[i] != '\0'; ++i) {
						if (!(validation3[i] >= '0' && validation3[i] <= '9')) {
							error = true;
						}
					}
					int marks = std::stoi(validation3);
					if (marks <= 0 || marks > 100) {
						error = true;
					}
				}

				if (error) {
					MessageBox::Show("Invalid Student Data");
					data3 = true;
					//status3_textBox->Clear();
				}

				error = false;


				if (status4_textBox->Text != "") {
					if (!(validation4[0] >= '0' && validation4[0] <= '9')) {
						error = true;
					}
					for (int i = 1; validation4[i] != '\0'; ++i) {
						if (!(validation4[i] >= '0' && validation4[i] <= '9')) {
							error = true;
						}
					}
					int marks = std::stoi(validation4);
					if (marks <= 0 || marks > 100) {
						error = true;
					}
				}

				if (error) {
					MessageBox::Show("Invalid Student Data");
					data4 = true;
					//status4_textBox->Clear();
				}

				error = false;

				if (status5_textBox->Text != "") {
					if (!(validation5[0] >= '0' && validation5[0] <= '9')) {
						error = true;
					}
					for (int i = 1; validation5[i] != '\0'; ++i) {
						if (!(validation5[i] >= '0' && validation5[i] <= '9')) {
							error = true;
						}
					}
					int marks = std::stoi(validation5);
					if (marks <= 0 || marks > 100) {
						error = true;
					}
				}

				if (error) {
					MessageBox::Show("Invalid Student Data");
					data5 = true;
					//status5_textBox->Clear();
				}

				error = false;

				if (status6_textBox->Text != "") {
					if (!(validation6[0] >= '0' && validation6[0] <= '9')) {
						error = true;
					}
					for (int i = 1; validation6[i] != '\0'; ++i) {
						if (!(validation6[i] >= '0' && validation6[i] <= '9')) {
							error = true;
						}
					}
					int marks = std::stoi(validation6);
					if (marks <= 0 || marks > 100) {
						error = true;
					}
				}

				if (error) {
					MessageBox::Show("Invalid Student Data");
					data6 = true;
					//status6_textBox->Clear();
				}

				error = false;

				if (status7_textBox->Text != "") {
					if (!(validation7[0] >= '0' && validation7[0] <= '9')) {
						error = true;
					}
					for (int i = 1; validation7[i] != '\0'; ++i) {
						if (!(validation7[i] >= '0' && validation7[i] <= '9')) {
							error = true;
						}
					}
					int marks = std::stoi(validation7);
					if (marks <= 0 || marks > 100) {
						error = true;
					}
				}

				if (error) {
					MessageBox::Show("Invalid Student Data");
					data7 = true;
					//status7_textBox->Clear();
				}


				if (subject_title_textBox->Text != "OOP" && subject_title_textBox->Text != "ISE" && subject_title_textBox->Text != "DS" && subject_title_textBox->Text != "DLD" && subject_title_textBox->Text != "MVC") {
					MessageBox::Show("Invalid Subject Title");
					MessageBox::Show("Write OOP, DS, ISE, DLD, or MVC!");
					subject_title_textBox->Clear();
				}



				if (name1_textBox->Text != "" && rollno1_textBox->Text != "" && status1_textBox->Text != "") {
					data1 = false;
				}
				else if (name1_textBox->Text == "" && rollno1_textBox->Text == "" && status1_textBox->Text == "") {
					data1 = false;
				}
				else {
					data1 = true;
				}

				if (name2_textBox->Text != "" && rollno2_textBox->Text != "" && status2_textBox->Text != "") {
					data2 = false;
				}
				else if (name2_textBox->Text == "" && rollno2_textBox->Text == "" && status2_textBox->Text == "") {
					data2 = false;
				}
				else {
					data2 = true;
				}

				if (name3_textBox->Text != "" && rollno3_textBox->Text != "" && status3_textBox->Text != "") {
					data3 = false;
				}
				else if (name3_textBox->Text == "" && rollno3_textBox->Text == "" && status3_textBox->Text == "") {
					data3 = false;
				}
				else {
					data3 = true;
				}
				if (name4_textBox->Text != "" && rollno4_textBox->Text != "" && status4_textBox->Text != "") {
					data4 = false;
				}
				else if (name4_textBox->Text == "" && rollno4_textBox->Text == "" && status4_textBox->Text == "") {
					data4 = false;
				}
				else {
					data4 = true;
				}

				if (name5_textBox->Text != "" && rollno5_textBox->Text != "" && status5_textBox->Text != "") {
					data5 = false;
				}
				else if (name5_textBox->Text == "" && rollno5_textBox->Text == "" && status5_textBox->Text == "") {
					data5 = false;
				}
				else {
					data5 = true;
				}

				if (name6_textBox->Text != "" && rollno6_textBox->Text != "" && status6_textBox->Text != "") {
					data6 = false;
				}
				else if (name6_textBox->Text == "" && rollno6_textBox->Text == "" && status6_textBox->Text == "") {
					data6 = false;
				}
				else {
					data6 = true;
				}

				if (name7_textBox->Text != "" && rollno7_textBox->Text != "" && status7_textBox->Text != "") {
					data7 = false;
				}
				else if (name7_textBox->Text == "" && rollno7_textBox->Text == "" && status7_textBox->Text == "") {
					data7 = false;
				}
				else {
					data7 = true;
				}



				if (data1 == false && data2 == false && data3 == false && data4 == false && data5 == false && data6 == false && data7 == false) {
					ProcessInput(status1_textBox);
					ProcessInput(status2_textBox);
					ProcessInput(status3_textBox);
					ProcessInput(status4_textBox);
					ProcessInput(status5_textBox);
					ProcessInput(status6_textBox);
					ProcessInput(status7_textBox);
				}

				if (subject_title_textBox->Text != "" && data1 == false && data2 == false && data3 == false && data4 == false && data5 == false && data6 == false && data7 == false) {
					quiz.WriteMarks("Mid.txt", subject_title_textBox->Text,
						status1_textBox->Text, name1_textBox->Text, rollno1_textBox->Text,
						status2_textBox->Text, name2_textBox->Text, rollno2_textBox->Text,
						status3_textBox->Text, name3_textBox->Text, rollno3_textBox->Text,
						status4_textBox->Text, name4_textBox->Text, rollno4_textBox->Text,
						status5_textBox->Text, name5_textBox->Text, rollno5_textBox->Text,
						status6_textBox->Text, name6_textBox->Text, rollno6_textBox->Text,
						status7_textBox->Text, name7_textBox->Text, rollno7_textBox->Text);
					MessageBox::Show("Marks Submitted");
				}

				}

				////////////////////////////////////////////////////////////
					else if (ReturnTitle() == "FINAL") {
						Quiz quiz;
						bool data1 = false;
						bool data2 = false;
						bool data3 = false;
						bool data4 = false;
						bool data5 = false;
						bool data6 = false;
						bool data7 = false;

						ProcessInput(status1_textBox);
						ProcessInput(status2_textBox);
						ProcessInput(status3_textBox);
						ProcessInput(status4_textBox);
						ProcessInput(status5_textBox);
						ProcessInput(status6_textBox);
						ProcessInput(status7_textBox);

						if (name1_textBox == nullptr && status1_textBox != nullptr) {
							MessageBox::Show("Invalid Student Data");
							data1 = true;
							//status1_textBox->Clear();
						}
						else if (name2_textBox->Text == "" && status2_textBox->Text != "") {
							MessageBox::Show("Invalid Student Data");
							data2 = true;
							//status2_textBox->Clear();
						}
						else if (name3_textBox->Text == "" && status3_textBox->Text != "") {
							MessageBox::Show("Invalid Student Data");
							data3 = true;
							//status3_textBox->Clear();
						}
						else if (name4_textBox->Text == "" && status4_textBox->Text != "") {
							MessageBox::Show("Invalid Student Data");
							data4 = true;
							//status4_textBox->Clear();
						}
						else if (name5_textBox->Text == "" && status5_textBox->Text != "") {
							MessageBox::Show("Invalid Student Data");
							data5 = true;
							//status5_textBox->Clear();
						}
						else if (name6_textBox->Text == "" && status6_textBox->Text != "") {
							MessageBox::Show("Invalid Student Data");
							data6 = true;
							//status6_textBox->Clear();
						}
						else if (name7_textBox->Text == "" && status7_textBox->Text != "") {
							MessageBox::Show("Invalid Student Data");
							data7 = true;
							//status7_textBox->Clear();
						}
						else if (subject_title_textBox->Text == "") {
							MessageBox::Show("Invalid Subject Title");
							subject_title_textBox->Clear();
						}
						else if (rollno1_textBox->Text == "" && status1_textBox->Text != "") {
							MessageBox::Show("Invalid Student Data");
							data1 = true;
							//status1_textBox->Clear();
						}
						else if (rollno2_textBox->Text == "" && status2_textBox->Text != "") {
							MessageBox::Show("Invalid Student Data");
							data2 = true;
							//status2_textBox->Clear();

						}
						else if (rollno3_textBox->Text == "" && status3_textBox->Text != "") {
							MessageBox::Show("Invalid Student Data");
							data3 = true;
							//status3_textBox->Clear();
						}
						else if (rollno4_textBox->Text == "" && status4_textBox->Text != "") {
							MessageBox::Show("Invalid Student Data");
							data4 = true;
							//status4_textBox->Clear();

						}
						else if (rollno5_textBox->Text == "" && status5_textBox->Text != "") {
							MessageBox::Show("Invalid Student Data");
							data5 = true;
							//status5_textBox->Clear();
						}
						else if (rollno6_textBox->Text == "" && status6_textBox->Text != "") {
							MessageBox::Show("Invalid Student Data");
							data6 = true;
							//status6_textBox->Clear();
						}
						else if (rollno7_textBox->Text == "" && status7_textBox->Text != "") {
							MessageBox::Show("Invalid Student Data");
							data7 = true;
							//status7_textBox->Clear();
						}
						else if (name1_textBox->Text != "" && rollno1_textBox->Text != "" && status1_textBox->Text == "") {
							MessageBox::Show("Invalid Student Data");
							data1 = true;
						}
						else if (name2_textBox->Text != "" && rollno2_textBox->Text != "" && status2_textBox->Text == "") {
							MessageBox::Show("Invalid Student Data");
							data2 = true;
						}
						else if (name3_textBox->Text != "" && rollno3_textBox->Text != "" && status3_textBox->Text == "") {
							MessageBox::Show("Invalid Student Data");
							data3 = true;
						}
						else if (name4_textBox->Text != "" && rollno4_textBox->Text != "" && status4_textBox->Text == "") {
							MessageBox::Show("Invalid Student Data");
							data4 = true;
						}
						else if (name5_textBox->Text != "" && rollno5_textBox->Text != "" && status5_textBox->Text == "") {
							MessageBox::Show("Invalid Student Data");
							data5 = true;
						}
						else if (name6_textBox->Text != "" && rollno6_textBox->Text != "" && status6_textBox->Text == "") {
							MessageBox::Show("Invalid Student Data");
							data6 = true;
						}
						else if (name7_textBox->Text != "" && rollno7_textBox->Text != "" && status7_textBox->Text == "") {
							MessageBox::Show("Invalid Student Data");
							data7 = true;
						}




						bool error = false;

						std::string validation1 = msclr::interop::marshal_as<std::string>(status1_textBox->Text);
						std::string validation2 = msclr::interop::marshal_as<std::string>(status2_textBox->Text);
						std::string validation3 = msclr::interop::marshal_as<std::string>(status3_textBox->Text);
						std::string validation4 = msclr::interop::marshal_as<std::string>(status4_textBox->Text);
						std::string validation5 = msclr::interop::marshal_as<std::string>(status5_textBox->Text);
						std::string validation6 = msclr::interop::marshal_as<std::string>(status6_textBox->Text);
						std::string validation7 = msclr::interop::marshal_as<std::string>(status7_textBox->Text);

						if (status1_textBox->Text != "") {
							if (!(validation1[0] >= '0' && validation1[0] <= '9')) {
								error = true;
							}
							for (int i = 1; validation1[i] != '\0'; ++i) {
								if (!(validation1[i] >= '0' && validation1[i] <= '9')) {
									error = true;
								}
							}
							int marks = std::stoi(validation1);
							if (marks <= 0 || marks > 100) {
								error = true;
							}
						}
						if (error) {
							MessageBox::Show("Invalid Student Data");
							data1 = true;
							//status1_textBox->Clear();
						}

						error = false;
						if (status2_textBox->Text != "") {
							if (!(validation2[0] >= '0' && validation2[0] <= '9')) {
								error = true;
							}
							for (int i = 1; validation2[i] != '\0'; ++i) {
								if (!(validation2[i] >= '0' && validation2[i] <= '9')) {
									error = true;
								}
							}
							int marks = std::stoi(validation2);
							if (marks <= 0 || marks > 100) {
								error = true;
							}
						}

						if (error) {
							MessageBox::Show("Invalid Student Data");
							data2 = true;
							//status2_textBox->Clear();
						}

						error = false;


						if (status3_textBox->Text != "") {
							if (!(validation3[0] >= '0' && validation3[0] <= '9')) {
								error = true;
							}
							for (int i = 1; validation3[i] != '\0'; ++i) {
								if (!(validation3[i] >= '0' && validation3[i] <= '9')) {
									error = true;
								}
							}
							int marks = std::stoi(validation3);
							if (marks <= 0 || marks > 100) {
								error = true;
							}
						}

						if (error) {
							MessageBox::Show("Invalid Student Data");
							data3 = true;
							//status3_textBox->Clear();
						}

						error = false;


						if (status4_textBox->Text != "") {
							if (!(validation4[0] >= '0' && validation4[0] <= '9')) {
								error = true;
							}
							for (int i = 1; validation4[i] != '\0'; ++i) {
								if (!(validation4[i] >= '0' && validation4[i] <= '9')) {
									error = true;
								}
							}
							int marks = std::stoi(validation4);
							if (marks <= 0 || marks > 100) {
								error = true;
							}
						}

						if (error) {
							MessageBox::Show("Invalid Student Data");
							data4 = true;
							//status4_textBox->Clear();
						}

						error = false;

						if (status5_textBox->Text != "") {
							if (!(validation5[0] >= '0' && validation5[0] <= '9')) {
								error = true;
							}
							for (int i = 1; validation5[i] != '\0'; ++i) {
								if (!(validation5[i] >= '0' && validation5[i] <= '9')) {
									error = true;
								}
							}
							int marks = std::stoi(validation5);
							if (marks <= 0 || marks > 100) {
								error = true;
							}
						}

						if (error) {
							MessageBox::Show("Invalid Student Data");
							data5 = true;
							//status5_textBox->Clear();
						}

						error = false;

						if (status6_textBox->Text != "") {
							if (!(validation6[0] >= '0' && validation6[0] <= '9')) {
								error = true;
							}
							for (int i = 1; validation6[i] != '\0'; ++i) {
								if (!(validation6[i] >= '0' && validation6[i] <= '9')) {
									error = true;
								}
							}
							int marks = std::stoi(validation6);
							if (marks <= 0 || marks > 100) {
								error = true;
							}
						}

						if (error) {
							MessageBox::Show("Invalid Student Data");
							data6 = true;
							//status6_textBox->Clear();
						}

						error = false;

						if (status7_textBox->Text != "") {
							if (!(validation7[0] >= '0' && validation7[0] <= '9')) {
								error = true;
							}
							for (int i = 1; validation7[i] != '\0'; ++i) {
								if (!(validation7[i] >= '0' && validation7[i] <= '9')) {
									error = true;
								}
							}
							int marks = std::stoi(validation7);
							if (marks <= 0 || marks > 100) {
								error = true;
							}
						}

						if (error) {
							MessageBox::Show("Invalid Student Data");
							data7 = true;
							//status7_textBox->Clear();
						}


						if (subject_title_textBox->Text != "OOP" && subject_title_textBox->Text != "ISE" && subject_title_textBox->Text != "DS" && subject_title_textBox->Text != "DLD" && subject_title_textBox->Text != "MVC") {
							MessageBox::Show("Invalid Subject Title");
							MessageBox::Show("Write OOP, DS, ISE, DLD, or MVC!");
							subject_title_textBox->Clear();
						}



						if (name1_textBox->Text != "" && rollno1_textBox->Text != "" && status1_textBox->Text != "") {
							data1 = false;
						}
						else if (name1_textBox->Text == "" && rollno1_textBox->Text == "" && status1_textBox->Text == "") {
							data1 = false;
						}
						else {
							data1 = true;
						}

						if (name2_textBox->Text != "" && rollno2_textBox->Text != "" && status2_textBox->Text != "") {
							data2 = false;
						}
						else if (name2_textBox->Text == "" && rollno2_textBox->Text == "" && status2_textBox->Text == "") {
							data2 = false;
						}
						else {
							data2 = true;
						}

						if (name3_textBox->Text != "" && rollno3_textBox->Text != "" && status3_textBox->Text != "") {
							data3 = false;
						}
						else if (name3_textBox->Text == "" && rollno3_textBox->Text == "" && status3_textBox->Text == "") {
							data3 = false;
						}
						else {
							data3 = true;
						}
						if (name4_textBox->Text != "" && rollno4_textBox->Text != "" && status4_textBox->Text != "") {
							data4 = false;
						}
						else if (name4_textBox->Text == "" && rollno4_textBox->Text == "" && status4_textBox->Text == "") {
							data4 = false;
						}
						else {
							data4 = true;
						}

						if (name5_textBox->Text != "" && rollno5_textBox->Text != "" && status5_textBox->Text != "") {
							data5 = false;
						}
						else if (name5_textBox->Text == "" && rollno5_textBox->Text == "" && status5_textBox->Text == "") {
							data5 = false;
						}
						else {
							data5 = true;
						}

						if (name6_textBox->Text != "" && rollno6_textBox->Text != "" && status6_textBox->Text != "") {
							data6 = false;
						}
						else if (name6_textBox->Text == "" && rollno6_textBox->Text == "" && status6_textBox->Text == "") {
							data6 = false;
						}
						else {
							data6 = true;
						}

						if (name7_textBox->Text != "" && rollno7_textBox->Text != "" && status7_textBox->Text != "") {
							data7 = false;
						}
						else if (name7_textBox->Text == "" && rollno7_textBox->Text == "" && status7_textBox->Text == "") {
							data7 = false;
						}
						else {
							data7 = true;
						}



						if (data1 == false && data2 == false && data3 == false && data4 == false && data5 == false && data6 == false && data7 == false) {
							ProcessInput(status1_textBox);
							ProcessInput(status2_textBox);
							ProcessInput(status3_textBox);
							ProcessInput(status4_textBox);
							ProcessInput(status5_textBox);
							ProcessInput(status6_textBox);
							ProcessInput(status7_textBox);
						}

						if (subject_title_textBox->Text != "" && data1 == false && data2 == false && data3 == false && data4 == false && data5 == false && data6 == false && data7 == false) {
							quiz.WriteMarks("Final.txt", subject_title_textBox->Text,
								status1_textBox->Text, name1_textBox->Text, rollno1_textBox->Text,
								status2_textBox->Text, name2_textBox->Text, rollno2_textBox->Text,
								status3_textBox->Text, name3_textBox->Text, rollno3_textBox->Text,
								status4_textBox->Text, name4_textBox->Text, rollno4_textBox->Text,
								status5_textBox->Text, name5_textBox->Text, rollno5_textBox->Text,
								status6_textBox->Text, name6_textBox->Text, rollno6_textBox->Text,
								status7_textBox->Text, name7_textBox->Text, rollno7_textBox->Text);
							MessageBox::Show("Marks Submitted");
						}

						}
	}
};
}
