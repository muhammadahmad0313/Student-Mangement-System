#pragma once
#include "AddAdmin.h"
#include <msclr\marshal_cppstd.h>
#include <string>
#include <iostream>
#include <fstream>
namespace SMS {

	using namespace System;
	using namespace msclr::interop;
	//using namespace SMS;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Edit_Teacher
	/// </summary>
	public ref class Edit_Teacher : public System::Windows::Forms::Form
	{

	
	public:
		String^ userID;
		String^ name;
		String^ gender;
		String^ cnic;
		String^ dob;
		String^ mobileNumber;
		String^ degree;
		String^ campus;
		String^ depart;
		int Counter;

		bool found;

		void SetRollNo(String^ title)
		{
			this->userID = title;
		}

		String^ ReturnRollNo()
		{
			return userID;
		}
		
		void RemoveLineFromFile(std::string& contentToRemove) {
			std::string fileName = "tuserPwd.txt";
			std::ifstream inFile(fileName);
			if (!inFile) {
				std::cerr << "Error: Unable to open file " << fileName << std::endl;
				return;
			}

			std::ofstream tempFile("temp.txt");
			if (!tempFile) {
				std::cerr << "Error: Unable to create temporary file" << std::endl;
				inFile.close(); 
				return;
			}

			std::string line;

			while (std::getline(inFile, line)) {
				if (line.find(contentToRemove) == std::string::npos) {
					tempFile << line << std::endl;
				}
			}

			inFile.close();
			tempFile.close();

			std::remove(fileName.c_str());

			std::rename("temp.txt", fileName.c_str());

		}


		void RemoveTheTeacher(String^ managedUserID) {
			String^ managedFileName = "teachersDetail.txt";
			String^ tempFileName = "temp.txt";


			String^ filePath = Path::Combine(Environment::CurrentDirectory, managedFileName);
			String^ tempFilePath = Path::Combine(Environment::CurrentDirectory, tempFileName);

			StreamReader^ reader = gcnew StreamReader(filePath);
			StreamWriter^ writer = gcnew StreamWriter(tempFilePath);

			String^ line;
			bool found = false;

			while ((line = reader->ReadLine()) != nullptr) {
				if (!line->Contains(managedUserID)) {
					writer->WriteLine(line);
				}
				else {
					found = true;
				}
			}

			reader->Close();
			writer->Close();

			File::Delete(filePath);

			File::Move(tempFilePath, filePath);

			if (found) {
				Console::WriteLine("Student with roll number " + managedUserID + " removed successfully.");
			}
			else {
				Console::WriteLine("Student with roll number " + managedUserID + " not found.");
			}
		}


		void GetRollNumber(String^% title)
		{
			String^ fileName = "Search_Teacher.txt";
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
						SetRollNo(key);
					}
				}
				sr->Close();
			}
		}

		void Counter_Increament() {
			Counter++;
		}

		int Counter_Return() {
			return Counter;
		}

		void FillTeacherDetails(String^ userid, String^% nameTextBox, String^% genderComboBox, String^% cnicTextBox,
			String^% dobDateTimePicker, String^% mobileTextBox, String^% degreeTextBox,
			String^% campusTextBox, String^% departTextBox)
		{
			String^ user;

			int counter = 0;
			String^ fileName = "admin_teacher.txt";
			if (IO::File::Exists(fileName))
			{
				IO::StreamReader^ sr = gcnew IO::StreamReader(fileName);
				String^ line;
				Boolean isStudentFound = false;

				while ((line = sr->ReadLine()) != nullptr)
				{
					array<String^>^ parts = line->Split(',');
					if (parts->Length == 2)
					{
						String^ key = parts[0]->Trim();
						String^ value = parts[1]->Trim();

						if (key == "User ID" && value == ReturnRollNo())
						{
							isStudentFound = true;
							user = value;
							break; 
						}

						if (key == "Name")
						{
							Counter_Increament();
						}
					}
				}
				sr->Close();

				if (isStudentFound && Counter_Return() > 0)
				{

					sr = gcnew IO::StreamReader(fileName);

					while ((line = sr->ReadLine()) != nullptr)
					{
						//counter++;
						array<String^>^ parts = line->Split(',');
						if (parts->Length == 2)
						{
							String^ key = parts[0]->Trim();
							String^ value = parts[1]->Trim();

							if (key == "Name")
							{
								counter++;
								if (Counter_Return() == counter)
								{
									//Counter_Increament();
									nameTextBox = value;
									continue; 
								}
							}

							if (Counter_Return() == counter)
							{
								if (key == "Gender")
								{
									genderComboBox = value;
								}
								else if (key == "CNIC")
								{
									cnicTextBox = value;
								}
								else if (key == "Date of Birth")
								{
									dobDateTimePicker = value;
								}
								else if (key == "Mobile Number")
								{
									mobileTextBox = value;
								}
								else if (key == "Degree")
								{
									degreeTextBox = value;
								}
								else if (key == "Campus")
								{
									campusTextBox = value;
								}
								else if (key == "Department")
								{
									departTextBox = value;
								}
							}
						}
					}
					sr->Close();
				}
			}
			if (nameTextBox == nullptr) {
				name = "N/A";
			}
			if (user == nullptr)
			{
				userID = "N/A";
				found = false;
			}

			if (cnicTextBox == nullptr) {
				cnic = "N/A";
			}

			if (mobileTextBox == nullptr) {
				mobileNumber = "N/A";
			}
			if (degreeTextBox == nullptr) {
				degree = "N/A";
			}
			if (campusTextBox == nullptr) {
				campus = "N/A";
			}
			if (departTextBox == nullptr) {
				depart = "N/A";
			}

		}

		void RemoveThatTeacher()
		{
			int current = 0;

			String^ fileName = "admin_teacher.txt";
			String^ tempFile = "temp.txt";

			if (IO::File::Exists(fileName))
			{
				IO::StreamReader^ sr = gcnew IO::StreamReader(fileName);
				IO::StreamWriter^ sw = gcnew IO::StreamWriter(tempFile);
				String^ line;
				Boolean isStudentFound = false;

				while ((line = sr->ReadLine()) != nullptr)
				{
					array<String^>^ parts = line->Split(',');
					if (parts->Length == 2)
					{
						String^ key = parts[0]->Trim();
						String^ value = parts[1]->Trim();

						if (key == "Name")
						{
							current++;
						}

						if (key == "Name" && value == name && current == Counter_Return())
						{
							isStudentFound = true;
							continue; 
						}
						else if (key == "User ID" && value == userID && current == Counter_Return())
						{
							isStudentFound = true;
							continue;
						}
						else if (key == "Gender" && current == Counter_Return()) {
							isStudentFound = true;
							continue;
						}

						else if (key == "CNIC" && value == cnic && current == Counter_Return()) {
							isStudentFound = true;
							continue;
						}
						else if (key == "Date of Birth" && value == dob && current == Counter_Return()) {
							isStudentFound = true;
							continue;
						}
						else if (key == "Mobile Number" && value == mobileNumber && current == Counter_Return()) {
							isStudentFound = true;
							continue;
						}
						else if (key == "Degree" && value == degree && current == Counter_Return()) {
							isStudentFound = true;
							continue;
						}
						else if (key == "Campus" && value == campus && current == Counter_Return()) {
							isStudentFound = true;
							continue;
						}
						else if (key == "Department" && value == depart && current == Counter_Return()) {
							isStudentFound = true;
							continue;
						}
						else if (key == "" && current == Counter_Return())
						{
							isStudentFound = true;
							continue;
						}

					}
					sw->WriteLine(line); 

				}

				sr->Close();
				sw->Close();
				IO::File::Delete(fileName);
				IO::File::Move(tempFile, fileName);

			}
			else
			{
				MessageBox::Show("File not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}




		Edit_Teacher(void)
		{
			found = true;
			Counter = 0;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Edit_Teacher()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ GendercomboBox;
	protected:
	private: System::Windows::Forms::Button^ add_button;
	private: System::Windows::Forms::Label^ degree_label;
	private: System::Windows::Forms::Label^ department_label;
	private: System::Windows::Forms::Label^ campus__label;
	private: System::Windows::Forms::Label^ userID_label;
	private: System::Windows::Forms::DateTimePicker^ dob_dateTimePicker;
	private: System::Windows::Forms::Label^ gender_label;
	private: System::Windows::Forms::Label^ dob_label;
	private: System::Windows::Forms::Label^ cnic_label;
	private: System::Windows::Forms::Label^ mobileno_label;
	private: System::Windows::Forms::TextBox^ degree_textBox;
	private: System::Windows::Forms::TextBox^ campus_textBox;
	private: System::Windows::Forms::TextBox^ department_textBox;
	private: System::Windows::Forms::TextBox^ user_id_textBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ cnic_textBox;
	private: System::Windows::Forms::TextBox^ mobile_textBox;
	private: System::Windows::Forms::Label^ TITLE;
	private: System::Windows::Forms::Button^ EXIT_button;
	private: System::Windows::Forms::Label^ Name_label;
	private: System::Windows::Forms::TextBox^ name_textBox;
	private: System::Windows::Forms::Panel^ Logo_WHO;
	private: System::Windows::Forms::Label^ label_paanel_WHO_2;
	private: System::Windows::Forms::Label^ label_panel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Edit_Teacher::typeid));
			this->GendercomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->degree_label = (gcnew System::Windows::Forms::Label());
			this->department_label = (gcnew System::Windows::Forms::Label());
			this->campus__label = (gcnew System::Windows::Forms::Label());
			this->userID_label = (gcnew System::Windows::Forms::Label());
			this->dob_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->gender_label = (gcnew System::Windows::Forms::Label());
			this->dob_label = (gcnew System::Windows::Forms::Label());
			this->cnic_label = (gcnew System::Windows::Forms::Label());
			this->mobileno_label = (gcnew System::Windows::Forms::Label());
			this->degree_textBox = (gcnew System::Windows::Forms::TextBox());
			this->campus_textBox = (gcnew System::Windows::Forms::TextBox());
			this->department_textBox = (gcnew System::Windows::Forms::TextBox());
			this->user_id_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cnic_textBox = (gcnew System::Windows::Forms::TextBox());
			this->mobile_textBox = (gcnew System::Windows::Forms::TextBox());
			this->TITLE = (gcnew System::Windows::Forms::Label());
			this->EXIT_button = (gcnew System::Windows::Forms::Button());
			this->Name_label = (gcnew System::Windows::Forms::Label());
			this->name_textBox = (gcnew System::Windows::Forms::TextBox());
			this->Logo_WHO = (gcnew System::Windows::Forms::Panel());
			this->label_paanel_WHO_2 = (gcnew System::Windows::Forms::Label());
			this->label_panel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Logo_WHO->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// GendercomboBox
			// 
			this->GendercomboBox->FormattingEnabled = true;
			this->GendercomboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Male", L"Female" });
			this->GendercomboBox->Location = System::Drawing::Point(530, 157);
			this->GendercomboBox->Name = L"GendercomboBox";
			this->GendercomboBox->Size = System::Drawing::Size(468, 28);
			this->GendercomboBox->TabIndex = 110;
			// 
			// add_button
			// 
			this->add_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->add_button->ForeColor = System::Drawing::Color::White;
			this->add_button->Location = System::Drawing::Point(470, 632);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(179, 57);
			this->add_button->TabIndex = 109;
			this->add_button->Text = L"EDIT";
			this->add_button->UseVisualStyleBackColor = false;
			this->add_button->Click += gcnew System::EventHandler(this, &Edit_Teacher::add_button_Click);
			// 
			// degree_label
			// 
			this->degree_label->AutoSize = true;
			this->degree_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->degree_label->Location = System::Drawing::Point(371, 490);
			this->degree_label->Name = L"degree_label";
			this->degree_label->Size = System::Drawing::Size(83, 26);
			this->degree_label->TabIndex = 108;
			this->degree_label->Text = L"Degree";
			// 
			// department_label
			// 
			this->department_label->AutoSize = true;
			this->department_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->department_label->Location = System::Drawing::Point(372, 573);
			this->department_label->Name = L"department_label";
			this->department_label->Size = System::Drawing::Size(126, 26);
			this->department_label->TabIndex = 107;
			this->department_label->Text = L"Department";
			// 
			// campus__label
			// 
			this->campus__label->AutoSize = true;
			this->campus__label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->campus__label->Location = System::Drawing::Point(371, 533);
			this->campus__label->Name = L"campus__label";
			this->campus__label->Size = System::Drawing::Size(94, 26);
			this->campus__label->TabIndex = 106;
			this->campus__label->Text = L"Campus";
			// 
			// userID_label
			// 
			this->userID_label->AutoSize = true;
			this->userID_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->userID_label->Location = System::Drawing::Point(372, 449);
			this->userID_label->Name = L"userID_label";
			this->userID_label->Size = System::Drawing::Size(86, 26);
			this->userID_label->TabIndex = 105;
			this->userID_label->Text = L"User ID";
			// 
			// dob_dateTimePicker
			// 
			this->dob_dateTimePicker->Location = System::Drawing::Point(531, 242);
			this->dob_dateTimePicker->Name = L"dob_dateTimePicker";
			this->dob_dateTimePicker->Size = System::Drawing::Size(467, 26);
			this->dob_dateTimePicker->TabIndex = 104;
			// 
			// gender_label
			// 
			this->gender_label->AutoSize = true;
			this->gender_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->gender_label->Location = System::Drawing::Point(347, 155);
			this->gender_label->Name = L"gender_label";
			this->gender_label->Size = System::Drawing::Size(84, 26);
			this->gender_label->TabIndex = 103;
			this->gender_label->Text = L"Gender";
			// 
			// dob_label
			// 
			this->dob_label->AutoSize = true;
			this->dob_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->dob_label->Location = System::Drawing::Point(350, 238);
			this->dob_label->Name = L"dob_label";
			this->dob_label->Size = System::Drawing::Size(133, 26);
			this->dob_label->TabIndex = 102;
			this->dob_label->Text = L"Date of Birth";
			// 
			// cnic_label
			// 
			this->cnic_label->AutoSize = true;
			this->cnic_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->cnic_label->Location = System::Drawing::Point(349, 198);
			this->cnic_label->Name = L"cnic_label";
			this->cnic_label->Size = System::Drawing::Size(66, 26);
			this->cnic_label->TabIndex = 101;
			this->cnic_label->Text = L"CNIC";
			// 
			// mobileno_label
			// 
			this->mobileno_label->AutoSize = true;
			this->mobileno_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->mobileno_label->Location = System::Drawing::Point(348, 285);
			this->mobileno_label->Name = L"mobileno_label";
			this->mobileno_label->Size = System::Drawing::Size(160, 26);
			this->mobileno_label->TabIndex = 100;
			this->mobileno_label->Text = L"Mobile Number";
			// 
			// degree_textBox
			// 
			this->degree_textBox->Location = System::Drawing::Point(530, 492);
			this->degree_textBox->Name = L"degree_textBox";
			this->degree_textBox->Size = System::Drawing::Size(468, 26);
			this->degree_textBox->TabIndex = 99;
			// 
			// campus_textBox
			// 
			this->campus_textBox->Location = System::Drawing::Point(530, 535);
			this->campus_textBox->Name = L"campus_textBox";
			this->campus_textBox->Size = System::Drawing::Size(468, 26);
			this->campus_textBox->TabIndex = 98;
			// 
			// department_textBox
			// 
			this->department_textBox->Location = System::Drawing::Point(530, 577);
			this->department_textBox->Name = L"department_textBox";
			this->department_textBox->Size = System::Drawing::Size(468, 26);
			this->department_textBox->TabIndex = 97;
			// 
			// user_id_textBox
			// 
			this->user_id_textBox->Location = System::Drawing::Point(530, 455);
			this->user_id_textBox->Name = L"user_id_textBox";
			this->user_id_textBox->Size = System::Drawing::Size(468, 26);
			this->user_id_textBox->TabIndex = 96;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->label1->Location = System::Drawing::Point(289, 348);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(835, 73);
			this->label1->TabIndex = 95;
			this->label1->Text = L"ACADEMIC INFORMATION";
			// 
			// cnic_textBox
			// 
			this->cnic_textBox->Location = System::Drawing::Point(530, 198);
			this->cnic_textBox->Name = L"cnic_textBox";
			this->cnic_textBox->Size = System::Drawing::Size(468, 26);
			this->cnic_textBox->TabIndex = 94;
			// 
			// mobile_textBox
			// 
			this->mobile_textBox->Location = System::Drawing::Point(530, 287);
			this->mobile_textBox->Name = L"mobile_textBox";
			this->mobile_textBox->Size = System::Drawing::Size(468, 26);
			this->mobile_textBox->TabIndex = 93;
			// 
			// TITLE
			// 
			this->TITLE->AutoSize = true;
			this->TITLE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32));
			this->TITLE->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->TITLE->Location = System::Drawing::Point(287, 27);
			this->TITLE->Name = L"TITLE";
			this->TITLE->Size = System::Drawing::Size(847, 73);
			this->TITLE->TabIndex = 92;
			this->TITLE->Text = L"PERSONAL INFORMATION";
			// 
			// EXIT_button
			// 
			this->EXIT_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->EXIT_button->ForeColor = System::Drawing::Color::White;
			this->EXIT_button->Location = System::Drawing::Point(755, 632);
			this->EXIT_button->Name = L"EXIT_button";
			this->EXIT_button->Size = System::Drawing::Size(179, 57);
			this->EXIT_button->TabIndex = 91;
			this->EXIT_button->Text = L"EXIT";
			this->EXIT_button->UseVisualStyleBackColor = false;
			this->EXIT_button->Click += gcnew System::EventHandler(this, &Edit_Teacher::EXIT_button_Click);
			// 
			// Name_label
			// 
			this->Name_label->AutoSize = true;
			this->Name_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->Name_label->Location = System::Drawing::Point(351, 118);
			this->Name_label->Name = L"Name_label";
			this->Name_label->Size = System::Drawing::Size(71, 26);
			this->Name_label->TabIndex = 90;
			this->Name_label->Text = L"Name";
			// 
			// name_textBox
			// 
			this->name_textBox->Location = System::Drawing::Point(530, 118);
			this->name_textBox->Name = L"name_textBox";
			this->name_textBox->Size = System::Drawing::Size(468, 26);
			this->name_textBox->TabIndex = 89;
			// 
			// Logo_WHO
			// 
			this->Logo_WHO->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->Logo_WHO->Controls->Add(this->label_paanel_WHO_2);
			this->Logo_WHO->Controls->Add(this->label_panel);
			this->Logo_WHO->Controls->Add(this->pictureBox1);
			this->Logo_WHO->Location = System::Drawing::Point(-1, -1);
			this->Logo_WHO->Name = L"Logo_WHO";
			this->Logo_WHO->Size = System::Drawing::Size(235, 715);
			this->Logo_WHO->TabIndex = 88;
			// 
			// label_paanel_WHO_2
			// 
			this->label_paanel_WHO_2->AutoSize = true;
			this->label_paanel_WHO_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label_paanel_WHO_2->ForeColor = System::Drawing::Color::White;
			this->label_paanel_WHO_2->Location = System::Drawing::Point(60, 438);
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
			this->label_panel->Location = System::Drawing::Point(42, 395);
			this->label_panel->Name = L"label_panel";
			this->label_panel->Size = System::Drawing::Size(149, 40);
			this->label_panel->TabIndex = 1;
			this->label_panel->Text = L"Teacher";
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
			// Edit_Teacher
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1185, 713);
			this->Controls->Add(this->GendercomboBox);
			this->Controls->Add(this->add_button);
			this->Controls->Add(this->degree_label);
			this->Controls->Add(this->department_label);
			this->Controls->Add(this->campus__label);
			this->Controls->Add(this->userID_label);
			this->Controls->Add(this->dob_dateTimePicker);
			this->Controls->Add(this->gender_label);
			this->Controls->Add(this->dob_label);
			this->Controls->Add(this->cnic_label);
			this->Controls->Add(this->mobileno_label);
			this->Controls->Add(this->degree_textBox);
			this->Controls->Add(this->campus_textBox);
			this->Controls->Add(this->department_textBox);
			this->Controls->Add(this->user_id_textBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cnic_textBox);
			this->Controls->Add(this->mobile_textBox);
			this->Controls->Add(this->TITLE);
			this->Controls->Add(this->EXIT_button);
			this->Controls->Add(this->Name_label);
			this->Controls->Add(this->name_textBox);
			this->Controls->Add(this->Logo_WHO);
			this->MaximumSize = System::Drawing::Size(1207, 769);
			this->MinimumSize = System::Drawing::Size(1207, 769);
			this->Name = L"Edit_Teacher";
			this->Text = L"Edit_Teacher";
			this->Load += gcnew System::EventHandler(this, &Edit_Teacher::Edit_Teacher_Load);
			this->Logo_WHO->ResumeLayout(false);
			this->Logo_WHO->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Edit_Teacher_Load(System::Object^ sender, System::EventArgs^ e) {
		String^ activeFile = "Search_Teacher.txt";
		if (IO::File::Exists(activeFile))
		{
			IO::StreamReader^ active = gcnew IO::StreamReader(activeFile);
			String^ activeContent;
			activeContent = active->ReadLine();
			array<String^>^ activeLines = activeContent->Split('\n');
			for each (String ^ line in activeLines)
			{
				if (line->StartsWith("Roll Number"))
				{
					userID = line->Split(',')[1]->Trim();
					break;
				}
			}
			active->Close();
		}



			FillTeacherDetails(userID, name, gender, cnic, dob, mobileNumber, degree, campus, depart);
		if (found) {

			name_textBox->Text = name;
			cnic_textBox->Text = cnic;
			dob_dateTimePicker->Value = DateTime::Parse(dob);
			mobile_textBox->Text = mobileNumber;
			degree_textBox->Text = degree;
			campus_textBox->Text = campus;
			department_textBox->Text = depart;
			user_id_textBox->Text = userID;
			GendercomboBox->Text = gender;
	}
		else {

			MessageBox::Show("Teacher not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			//name_textBox->Text = "N/A";
			//cnic_textBox->Text = "N/A";
			////dob_dateTimePicker->Value = DateTime::Parse(dob);
			//mobile_textBox->Text = "N/A";
			//degree_textBox->Text = "N/A";
			//campus_textBox->Text = "N/A";
			//department_textBox->Text = "N/A";
			//user_id_textBox->Text = "N/A";
			//GendercomboBox->Text = "N/A";
			this->Close();

		}


	}
private: System::Void add_button_Click(System::Object^ sender, System::EventArgs^ e) {
	RemoveThatTeacher();
	RemoveTheTeacher(userID);
	String^ tname = name;
	std::string name_temp = marshal_as<std::string>(tname);
	for (int i = 0; name_temp[i] != '\0'; ++i) {
		if (name_temp[i] == ' ')
			name_temp[i] = '.';
	}
	name_temp += "@lhr.nu.edu.pk";

	
	RemoveLineFromFile(name_temp);

	AddAdmin^ addAdmin = gcnew AddAdmin();
	bool addedSuccessfully = addAdmin->addTeacher(name_textBox->Text, GendercomboBox->SelectedItem->ToString(), cnic_textBox->Text, dob_dateTimePicker->Value.ToShortDateString(), mobile_textBox->Text, user_id_textBox->Text, degree_textBox->Text, campus_textBox->Text, department_textBox->Text);

	if (!addedSuccessfully) {
		MessageBox::Show("An error occurred while adding the student. Please try again.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return; 
	}
	else {
		MessageBox::Show("Teacher edited successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
private: System::Void EXIT_button_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
