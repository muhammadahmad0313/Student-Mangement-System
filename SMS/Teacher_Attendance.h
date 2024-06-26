#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <msclr/marshal_cppstd.h>
namespace SMS {

	using namespace System;
	using namespace System::IO;
	using namespace msclr::interop;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Teacher_Attendance
	/// </summary>
	public ref class Teacher_Attendance : public System::Windows::Forms::Form
	{
	private:
		int Students;
	public:

		void storeAttendance(const std::string& rollNumber, const std::string& subjectTitle, const std::string& status) {
			try {
				std::string fileName = "Attendance.txt";
				std::ofstream outFile(fileName, std::ios::app); 

				if (!outFile.is_open()) {
					std::cerr << "Error: Could not open file for writing: " << fileName << std::endl;
					return;
				}

				outFile <<subjectTitle<<" "<< rollNumber << " " << status << std::endl;

				// Close the file
				outFile.close();
			}
			catch (const std::exception& ex) {
				std::cerr << "Error storing attendance: " << ex.what() << std::endl;
			}
		}
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


		Teacher_Attendance(void)
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
		~Teacher_Attendance()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ SUBMIT_button;
	protected:

	private: System::Windows::Forms::TextBox^ rollno1_textBox;
	protected:






	private: System::Windows::Forms::Label^ ATTENDANCE_label;

	private: System::Windows::Forms::Panel^ Logo_WHO;
	private: System::Windows::Forms::Label^ label_paanel_WHO_2;
	private: System::Windows::Forms::Label^ label_panel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ subject_title_textBox;
	private: System::Windows::Forms::TextBox^ name1_textBox;





	private: System::Windows::Forms::Label^ Username;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ name2_textBox;

	private: System::Windows::Forms::TextBox^ rollno2_textBox;
	private: System::Windows::Forms::TextBox^ name3_textBox;


	private: System::Windows::Forms::TextBox^ rollno3_textBox;
	private: System::Windows::Forms::TextBox^ name4_textBox;


	private: System::Windows::Forms::TextBox^ rollno4_textBox;
	private: System::Windows::Forms::TextBox^ name5_textBox;


	private: System::Windows::Forms::TextBox^ rollno5_textBox;
	private: System::Windows::Forms::TextBox^ name7_textBox;


	private: System::Windows::Forms::TextBox^ rollno7_textBox;
	private: System::Windows::Forms::TextBox^ name6_textBox;


	private: System::Windows::Forms::TextBox^ rollno6_textBox;
	private: System::Windows::Forms::TextBox^ status7_textBox;


	private: System::Windows::Forms::TextBox^ status6_textBox;

	private: System::Windows::Forms::TextBox^ status5_textBox;

	private: System::Windows::Forms::TextBox^ status4_textBox;

	private: System::Windows::Forms::TextBox^ status3_textBox;

	private: System::Windows::Forms::TextBox^ status2_textBox;

	private: System::Windows::Forms::TextBox^ status1_textBox;
	private: System::Windows::Forms::Button^ EXIT_button;




	protected:










	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Teacher_Attendance::typeid));
			this->SUBMIT_button = (gcnew System::Windows::Forms::Button());
			this->rollno1_textBox = (gcnew System::Windows::Forms::TextBox());
			this->ATTENDANCE_label = (gcnew System::Windows::Forms::Label());
			this->Logo_WHO = (gcnew System::Windows::Forms::Panel());
			this->label_paanel_WHO_2 = (gcnew System::Windows::Forms::Label());
			this->label_panel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->subject_title_textBox = (gcnew System::Windows::Forms::TextBox());
			this->name1_textBox = (gcnew System::Windows::Forms::TextBox());
			this->Username = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->name2_textBox = (gcnew System::Windows::Forms::TextBox());
			this->rollno2_textBox = (gcnew System::Windows::Forms::TextBox());
			this->name3_textBox = (gcnew System::Windows::Forms::TextBox());
			this->rollno3_textBox = (gcnew System::Windows::Forms::TextBox());
			this->name4_textBox = (gcnew System::Windows::Forms::TextBox());
			this->rollno4_textBox = (gcnew System::Windows::Forms::TextBox());
			this->name5_textBox = (gcnew System::Windows::Forms::TextBox());
			this->rollno5_textBox = (gcnew System::Windows::Forms::TextBox());
			this->name7_textBox = (gcnew System::Windows::Forms::TextBox());
			this->rollno7_textBox = (gcnew System::Windows::Forms::TextBox());
			this->name6_textBox = (gcnew System::Windows::Forms::TextBox());
			this->rollno6_textBox = (gcnew System::Windows::Forms::TextBox());
			this->status7_textBox = (gcnew System::Windows::Forms::TextBox());
			this->status6_textBox = (gcnew System::Windows::Forms::TextBox());
			this->status5_textBox = (gcnew System::Windows::Forms::TextBox());
			this->status4_textBox = (gcnew System::Windows::Forms::TextBox());
			this->status3_textBox = (gcnew System::Windows::Forms::TextBox());
			this->status2_textBox = (gcnew System::Windows::Forms::TextBox());
			this->status1_textBox = (gcnew System::Windows::Forms::TextBox());
			this->EXIT_button = (gcnew System::Windows::Forms::Button());
			this->Logo_WHO->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// SUBMIT_button
			// 
			this->SUBMIT_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->SUBMIT_button->ForeColor = System::Drawing::Color::White;
			this->SUBMIT_button->Location = System::Drawing::Point(668, 628);
			this->SUBMIT_button->Name = L"SUBMIT_button";
			this->SUBMIT_button->Size = System::Drawing::Size(179, 57);
			this->SUBMIT_button->TabIndex = 73;
			this->SUBMIT_button->Text = L"SUBMIT";
			this->SUBMIT_button->UseVisualStyleBackColor = false;
			this->SUBMIT_button->Click += gcnew System::EventHandler(this, &Teacher_Attendance::EXIT_button_Click);
			// 
			// rollno1_textBox
			// 
			this->rollno1_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno1_textBox->Location = System::Drawing::Point(261, 284);
			this->rollno1_textBox->Name = L"rollno1_textBox";
			this->rollno1_textBox->ReadOnly = true;
			this->rollno1_textBox->Size = System::Drawing::Size(192, 26);
			this->rollno1_textBox->TabIndex = 69;
			// 
			// ATTENDANCE_label
			// 
			this->ATTENDANCE_label->AutoSize = true;
			this->ATTENDANCE_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24));
			this->ATTENDANCE_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->ATTENDANCE_label->Location = System::Drawing::Point(391, 51);
			this->ATTENDANCE_label->Name = L"ATTENDANCE_label";
			this->ATTENDANCE_label->Size = System::Drawing::Size(350, 55);
			this->ATTENDANCE_label->TabIndex = 66;
			this->ATTENDANCE_label->Text = L"ATTENDANCE";
			// 
			// Logo_WHO
			// 
			this->Logo_WHO->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->Logo_WHO->Controls->Add(this->label_paanel_WHO_2);
			this->Logo_WHO->Controls->Add(this->label_panel);
			this->Logo_WHO->Controls->Add(this->pictureBox1);
			this->Logo_WHO->Location = System::Drawing::Point(-2, -2);
			this->Logo_WHO->Name = L"Logo_WHO";
			this->Logo_WHO->Size = System::Drawing::Size(235, 763);
			this->Logo_WHO->TabIndex = 64;
			// 
			// label_paanel_WHO_2
			// 
			this->label_paanel_WHO_2->AutoSize = true;
			this->label_paanel_WHO_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label_paanel_WHO_2->ForeColor = System::Drawing::Color::White;
			this->label_paanel_WHO_2->Location = System::Drawing::Point(58, 471);
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
			this->label_panel->Location = System::Drawing::Point(42, 431);
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
			this->subject_title_textBox->Location = System::Drawing::Point(425, 134);
			this->subject_title_textBox->Name = L"subject_title_textBox";
			this->subject_title_textBox->Size = System::Drawing::Size(259, 26);
			this->subject_title_textBox->TabIndex = 60;
			// 
			// name1_textBox
			// 
			this->name1_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name1_textBox->Location = System::Drawing::Point(459, 284);
			this->name1_textBox->Name = L"name1_textBox";
			this->name1_textBox->ReadOnly = true;
			this->name1_textBox->Size = System::Drawing::Size(192, 26);
			this->name1_textBox->TabIndex = 75;
			// 
			// Username
			// 
			this->Username->AutoSize = true;
			this->Username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->Username->Location = System::Drawing::Point(276, 241);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(157, 30);
			this->Username->TabIndex = 76;
			this->Username->Text = L"Roll Number";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->label1->Location = System::Drawing::Point(703, 241);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 30);
			this->label1->TabIndex = 77;
			this->label1->Text = L"Status";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->label2->Location = System::Drawing::Point(505, 241);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 30);
			this->label2->TabIndex = 78;
			this->label2->Text = L"Name";
			// 
			// name2_textBox
			// 
			this->name2_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name2_textBox->Location = System::Drawing::Point(459, 336);
			this->name2_textBox->Name = L"name2_textBox";
			this->name2_textBox->ReadOnly = true;
			this->name2_textBox->Size = System::Drawing::Size(192, 26);
			this->name2_textBox->TabIndex = 80;
			// 
			// rollno2_textBox
			// 
			this->rollno2_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno2_textBox->Location = System::Drawing::Point(261, 336);
			this->rollno2_textBox->Name = L"rollno2_textBox";
			this->rollno2_textBox->ReadOnly = true;
			this->rollno2_textBox->Size = System::Drawing::Size(192, 26);
			this->rollno2_textBox->TabIndex = 79;
			// 
			// name3_textBox
			// 
			this->name3_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name3_textBox->Location = System::Drawing::Point(459, 381);
			this->name3_textBox->Name = L"name3_textBox";
			this->name3_textBox->ReadOnly = true;
			this->name3_textBox->Size = System::Drawing::Size(192, 26);
			this->name3_textBox->TabIndex = 82;
			// 
			// rollno3_textBox
			// 
			this->rollno3_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno3_textBox->Location = System::Drawing::Point(261, 381);
			this->rollno3_textBox->Name = L"rollno3_textBox";
			this->rollno3_textBox->ReadOnly = true;
			this->rollno3_textBox->Size = System::Drawing::Size(192, 26);
			this->rollno3_textBox->TabIndex = 81;
			// 
			// name4_textBox
			// 
			this->name4_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name4_textBox->Location = System::Drawing::Point(458, 431);
			this->name4_textBox->Name = L"name4_textBox";
			this->name4_textBox->ReadOnly = true;
			this->name4_textBox->Size = System::Drawing::Size(192, 26);
			this->name4_textBox->TabIndex = 84;
			// 
			// rollno4_textBox
			// 
			this->rollno4_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno4_textBox->Location = System::Drawing::Point(260, 431);
			this->rollno4_textBox->Name = L"rollno4_textBox";
			this->rollno4_textBox->ReadOnly = true;
			this->rollno4_textBox->Size = System::Drawing::Size(192, 26);
			this->rollno4_textBox->TabIndex = 83;
			// 
			// name5_textBox
			// 
			this->name5_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name5_textBox->Location = System::Drawing::Point(460, 479);
			this->name5_textBox->Name = L"name5_textBox";
			this->name5_textBox->ReadOnly = true;
			this->name5_textBox->Size = System::Drawing::Size(192, 26);
			this->name5_textBox->TabIndex = 86;
			// 
			// rollno5_textBox
			// 
			this->rollno5_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno5_textBox->Location = System::Drawing::Point(262, 479);
			this->rollno5_textBox->Name = L"rollno5_textBox";
			this->rollno5_textBox->ReadOnly = true;
			this->rollno5_textBox->Size = System::Drawing::Size(192, 26);
			this->rollno5_textBox->TabIndex = 85;
			// 
			// name7_textBox
			// 
			this->name7_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name7_textBox->Location = System::Drawing::Point(460, 574);
			this->name7_textBox->Name = L"name7_textBox";
			this->name7_textBox->ReadOnly = true;
			this->name7_textBox->Size = System::Drawing::Size(192, 26);
			this->name7_textBox->TabIndex = 90;
			// 
			// rollno7_textBox
			// 
			this->rollno7_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno7_textBox->Location = System::Drawing::Point(262, 574);
			this->rollno7_textBox->Name = L"rollno7_textBox";
			this->rollno7_textBox->ReadOnly = true;
			this->rollno7_textBox->Size = System::Drawing::Size(192, 26);
			this->rollno7_textBox->TabIndex = 89;
			// 
			// name6_textBox
			// 
			this->name6_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name6_textBox->Location = System::Drawing::Point(458, 526);
			this->name6_textBox->Name = L"name6_textBox";
			this->name6_textBox->ReadOnly = true;
			this->name6_textBox->Size = System::Drawing::Size(192, 26);
			this->name6_textBox->TabIndex = 88;
			// 
			// rollno6_textBox
			// 
			this->rollno6_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno6_textBox->Location = System::Drawing::Point(260, 526);
			this->rollno6_textBox->Name = L"rollno6_textBox";
			this->rollno6_textBox->ReadOnly = true;
			this->rollno6_textBox->Size = System::Drawing::Size(192, 26);
			this->rollno6_textBox->TabIndex = 87;
			// 
			// status7_textBox
			// 
			this->status7_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->status7_textBox->Location = System::Drawing::Point(660, 573);
			this->status7_textBox->Name = L"status7_textBox";
			this->status7_textBox->Size = System::Drawing::Size(192, 26);
			this->status7_textBox->TabIndex = 97;
			// 
			// status6_textBox
			// 
			this->status6_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->status6_textBox->Location = System::Drawing::Point(658, 525);
			this->status6_textBox->Name = L"status6_textBox";
			this->status6_textBox->Size = System::Drawing::Size(192, 26);
			this->status6_textBox->TabIndex = 96;
			// 
			// status5_textBox
			// 
			this->status5_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->status5_textBox->Location = System::Drawing::Point(660, 478);
			this->status5_textBox->Name = L"status5_textBox";
			this->status5_textBox->Size = System::Drawing::Size(192, 26);
			this->status5_textBox->TabIndex = 95;
			// 
			// status4_textBox
			// 
			this->status4_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->status4_textBox->Location = System::Drawing::Point(658, 430);
			this->status4_textBox->Name = L"status4_textBox";
			this->status4_textBox->Size = System::Drawing::Size(192, 26);
			this->status4_textBox->TabIndex = 94;
			// 
			// status3_textBox
			// 
			this->status3_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->status3_textBox->Location = System::Drawing::Point(659, 380);
			this->status3_textBox->Name = L"status3_textBox";
			this->status3_textBox->Size = System::Drawing::Size(192, 26);
			this->status3_textBox->TabIndex = 93;
			// 
			// status2_textBox
			// 
			this->status2_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->status2_textBox->Location = System::Drawing::Point(659, 335);
			this->status2_textBox->Name = L"status2_textBox";
			this->status2_textBox->Size = System::Drawing::Size(192, 26);
			this->status2_textBox->TabIndex = 92;
			// 
			// status1_textBox
			// 
			this->status1_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->status1_textBox->Location = System::Drawing::Point(659, 283);
			this->status1_textBox->Name = L"status1_textBox";
			this->status1_textBox->Size = System::Drawing::Size(192, 26);
			this->status1_textBox->TabIndex = 91;
			// 
			// EXIT_button
			// 
			this->EXIT_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->EXIT_button->ForeColor = System::Drawing::Color::White;
			this->EXIT_button->Location = System::Drawing::Point(262, 628);
			this->EXIT_button->Name = L"EXIT_button";
			this->EXIT_button->Size = System::Drawing::Size(179, 57);
			this->EXIT_button->TabIndex = 98;
			this->EXIT_button->Text = L"EXIT";
			this->EXIT_button->UseVisualStyleBackColor = false;
			this->EXIT_button->Click += gcnew System::EventHandler(this, &Teacher_Attendance::EXIT_button_Click_1);
			// 
			// Teacher_Attendance
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(906, 715);
			this->Controls->Add(this->EXIT_button);
			this->Controls->Add(this->status7_textBox);
			this->Controls->Add(this->status6_textBox);
			this->Controls->Add(this->status5_textBox);
			this->Controls->Add(this->status4_textBox);
			this->Controls->Add(this->status3_textBox);
			this->Controls->Add(this->status2_textBox);
			this->Controls->Add(this->status1_textBox);
			this->Controls->Add(this->name7_textBox);
			this->Controls->Add(this->rollno7_textBox);
			this->Controls->Add(this->name6_textBox);
			this->Controls->Add(this->rollno6_textBox);
			this->Controls->Add(this->name5_textBox);
			this->Controls->Add(this->rollno5_textBox);
			this->Controls->Add(this->name4_textBox);
			this->Controls->Add(this->rollno4_textBox);
			this->Controls->Add(this->name3_textBox);
			this->Controls->Add(this->rollno3_textBox);
			this->Controls->Add(this->name2_textBox);
			this->Controls->Add(this->rollno2_textBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Username);
			this->Controls->Add(this->name1_textBox);
			this->Controls->Add(this->SUBMIT_button);
			this->Controls->Add(this->rollno1_textBox);
			this->Controls->Add(this->ATTENDANCE_label);
			this->Controls->Add(this->Logo_WHO);
			this->Controls->Add(this->subject_title_textBox);
			this->MaximumSize = System::Drawing::Size(928, 771);
			this->MinimumSize = System::Drawing::Size(928, 771);
			this->Name = L"Teacher_Attendance";
			this->Text = L"Teacher_Attendance";
			this->Load += gcnew System::EventHandler(this, &Teacher_Attendance::Teacher_Attendance_Load);
			this->Logo_WHO->ResumeLayout(false);
			this->Logo_WHO->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EXIT_button_Click(System::Object^ sender, System::EventArgs^ e) {
		
		int totalStudents = GetStudents();
		for (int i = 1; i <= totalStudents; ++i) {
			switch (i) {
			case 1: {
				String^ status = status1_textBox->Text;
				std::string status_temp = msclr::interop::marshal_as<std::string>(status);

				String^ rollnoo = rollno1_textBox->Text;
				std::string roll_temp = msclr::interop::marshal_as<std::string>(rollnoo);

				std::string subject = msclr::interop::marshal_as<std::string>(subject_title_textBox->Text);

				storeAttendance(roll_temp, subject, status_temp);
				break;
			}
			case 2: {
				String^ status = status2_textBox->Text;
				std::string status_temp = msclr::interop::marshal_as<std::string>(status);

				String^ rollnoo = rollno2_textBox->Text;
				std::string roll_temp = msclr::interop::marshal_as<std::string>(rollnoo);

				std::string subject = msclr::interop::marshal_as<std::string>(subject_title_textBox->Text);

				storeAttendance(roll_temp, subject, status_temp);
				break;
			}
			case 3: {
				String^ status = status3_textBox->Text;
				std::string status_temp = msclr::interop::marshal_as<std::string>(status);

				String^ rollnoo = rollno3_textBox->Text;
				std::string roll_temp = msclr::interop::marshal_as<std::string>(rollnoo);

				std::string subject = msclr::interop::marshal_as<std::string>(subject_title_textBox->Text);

				storeAttendance(roll_temp, subject, status_temp);
				break;
			}
			case 4: {
				String^ status = status4_textBox->Text;
				std::string status_temp = msclr::interop::marshal_as<std::string>(status);

				String^ rollnoo = rollno4_textBox->Text;
				std::string roll_temp = msclr::interop::marshal_as<std::string>(rollnoo);

				std::string subject = msclr::interop::marshal_as<std::string>(subject_title_textBox->Text);

				storeAttendance(roll_temp, subject, status_temp);
				break;
			}
			case 5: {
				String^ status = status5_textBox->Text;
				std::string status_temp = msclr::interop::marshal_as<std::string>(status);

				String^ rollnoo = rollno5_textBox->Text;
				std::string roll_temp = msclr::interop::marshal_as<std::string>(rollnoo);

				std::string subject = msclr::interop::marshal_as<std::string>(subject_title_textBox->Text);

				storeAttendance(roll_temp, subject, status_temp);
				break;
			}
			case 6: {
				String^ status = status6_textBox->Text;
				std::string status_temp = msclr::interop::marshal_as<std::string>(status);

				String^ rollnoo = rollno6_textBox->Text;
				std::string roll_temp = msclr::interop::marshal_as<std::string>(rollnoo);

				std::string subject = msclr::interop::marshal_as<std::string>(subject_title_textBox->Text);

				storeAttendance(roll_temp, subject, status_temp);
				break;
			}
			case 7: {
				String^ status = status7_textBox->Text;
				std::string status_temp = msclr::interop::marshal_as<std::string>(status);

				String^ rollnoo = rollno7_textBox->Text;
				std::string roll_temp = msclr::interop::marshal_as<std::string>(rollnoo);

				std::string subject = msclr::interop::marshal_as<std::string>(subject_title_textBox->Text);

				storeAttendance(roll_temp, subject, status_temp);
				break;
			}
			default:
				break;
			}
		}
	}
private: System::Void Teacher_Attendance_Load(System::Object^ sender, System::EventArgs^ e) {
	ReadStudents();
	for (int i = 1; i <= GetStudents(); ++i) {
		FillStudentData(i);
	}
}
private: System::Void EXIT_button_Click_1(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
