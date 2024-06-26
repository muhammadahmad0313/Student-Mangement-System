#pragma once
#include "AddAdmin.h"
#include <iostream>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <vcclr.h>
#include <vector>

namespace SMS {

	using namespace System;
	using namespace msclr::interop;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Edit_Student
	/// </summary>
	public ref class Edit_Student : public System::Windows::Forms::Form
	{
	private:
		String^ rollNo;
		String^ name;
		String^ gender;
		String^ cnic;
		String^ dob;
		String^ mobileNumber;
		String^ section;
		String^ campus;
		String^ batch;
		int Counter;
		bool found;
       
	public:
		void SetRollNo(String^ title)
		{
			this->rollNo = title;
		}

		String^ ReturnRollNo()
		{
			return rollNo;
		}

		void RemoveStudentFromFileStudents(const std::string& rollNo) {
			std::string fileName = "students.txt";
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
			std::vector<std::string> names;
			std::vector<std::string> rolls;
			bool studentFound = false;

			while (std::getline(inFile, line)) {
				if (line.find("Name,") != std::string::npos) {
					names.push_back(line.substr(line.find(",") + 1)); 
					std::getline(inFile, line); 
					rolls.push_back(line.substr(line.find(",") + 1)); 
				}
			}

			auto it = std::find(rolls.begin(), rolls.end(), rollNo);
			if (it != rolls.end()) {
				size_t index = it - rolls.begin();
				names.erase(names.begin() + index); 
				rolls.erase(rolls.begin() + index); 
				studentFound = true; 
			}

			for (size_t i = 0; i < names.size(); ++i) {
				tempFile << "Name," << names[i] << std::endl;
				tempFile << "Roll Number," << rolls[i] << std::endl;
			}

			inFile.close();
			tempFile.close();

			if (studentFound) {
				std::remove(fileName.c_str());
				std::rename("temp.txt", fileName.c_str());
				std::cout << "Student removed successfully." << std::endl;
			}
			else {
				std::remove("temp.txt"); 
				std::cout << "Student not found." << std::endl;
			}
		}



		void RemoveStudentFromFileStudent(const std::string& fileName, const std::string& rollNo) {
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
				std::string currentRoll = line.substr(0, line.find(' ')); 
				if (currentRoll != rollNo) {
					tempFile << line << std::endl; 
				}
			}

			inFile.close();
			tempFile.close();

			std::remove(fileName.c_str());
			std::rename("temp.txt", fileName.c_str());
			std::cout << "Student removed successfully." << std::endl;
		}


		void RemoveLineFromFile(std::string& contentToRemove) {
			std::string fileName = "userPwd.txt";
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


		void RemoveTheStudent(String^ managedRollNo) {
			String^ managedFileName = "stdAtten.txt";
			String^ tempFileName = "temp.txt"; 

			
			String^ filePath = Path::Combine(Environment::CurrentDirectory, managedFileName);
			String^ tempFilePath = Path::Combine(Environment::CurrentDirectory, tempFileName);

			StreamReader^ reader = gcnew StreamReader(filePath);
			StreamWriter^ writer = gcnew StreamWriter(tempFilePath);

			String^ line;
			bool found = false;

			while ((line = reader->ReadLine()) != nullptr) {
				if (!line->Contains(managedRollNo)) {
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
				Console::WriteLine("Student with roll number " + managedRollNo + " removed successfully.");
			}
			else {
				Console::WriteLine("Student with roll number " + managedRollNo + " not found.");
			}
		}



		void GetRollNumber(String^% title)
		{
			String^ fileName = "SearchStudent.txt";
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

		void FillStudentDetails(String^ rollNum, String^% nameTextBox, String^% genderComboBox, String^% cnicTextBox,
			String^% dobDateTimePicker, String^% mobileTextBox, String^% sectionTextBox,
			String^% campusTextBox, String^% batchTextBox)
		{
			//////////////////////////////////////////////
			String^ rollNumber;
			/////////////////////////////////////////////
			int counter = 0;
			String^ fileName = "admin_student.txt";
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

						if (key == "Roll Number" && value == ReturnRollNo())
						{
							isStudentFound = true;
							/////////////////////////////////////////
							rollNumber = value;
							////////////////////////////////////////
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
								else if (key == "Section")
								{
									sectionTextBox = value;
								}
								else if (key == "Campus")
								{
									campusTextBox = value;
								}
								else if (key == "Batch")
								{
									batchTextBox = value;
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
			if (rollNumber == nullptr)
			{
				rollNo = "N/A";
				found = false;
			}

			if (cnicTextBox == nullptr) {
				cnic = "N/A";
			}

			if (mobileTextBox == nullptr) {
				mobileNumber = "N/A";
			}
			if (sectionTextBox == nullptr) {
				section = "N/A";
			}
			if (campusTextBox == nullptr) {
				campus = "N/A";
			}
			if (batchTextBox == nullptr) {
				batch = "N/A";
			}
			

		}

		void RemoveThatStudent()
		{
			int current = 0;

			String^ fileName = "admin_student.txt";
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
						else if (key == "Roll Number" && value == rollNo && current == Counter_Return())
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
						else if (key == "Section" && value == section && current == Counter_Return()) {
							isStudentFound = true;
							continue;
						}
						else if (key == "Campus" && value == campus && current == Counter_Return()) {
							isStudentFound = true;
							continue;
						}
						else if (key == "Batch" && value == batch && current == Counter_Return()) {
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

		
		Edit_Student()
		{
			Counter = 0;
			found = true;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Edit_Student()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ GendercomboBox;
	protected:
	private: System::Windows::Forms::Button^ add_button;
	private: System::Windows::Forms::Label^ section_label;
	private: System::Windows::Forms::Label^ batch_label;
	private: System::Windows::Forms::Label^ campus__label;
	private: System::Windows::Forms::Label^ rollno_label;
	private: System::Windows::Forms::DateTimePicker^ dob_dateTimePicker;
	private: System::Windows::Forms::Label^ gender_label;
	private: System::Windows::Forms::Label^ dob_label;
	private: System::Windows::Forms::Label^ cnic_label;
	private: System::Windows::Forms::Label^ mobileno_label;
	private: System::Windows::Forms::TextBox^ section_textBox;
	private: System::Windows::Forms::TextBox^ campus_textBox;
	private: System::Windows::Forms::TextBox^ batch_textBox;
	private: System::Windows::Forms::TextBox^ rollno_textBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ cnic_textBox;
	private: System::Windows::Forms::TextBox^ mobile_num_textBox;
	private: System::Windows::Forms::Label^ TITLE;
	private: System::Windows::Forms::Button^ EXIT_button;
	private: System::Windows::Forms::Label^ Name_label;
	private: System::Windows::Forms::TextBox^ name_textBox;
	private: System::Windows::Forms::Panel^ Logo_WHO;
	private: System::Windows::Forms::Label^ label_paanel_WHO_2;
	private: System::Windows::Forms::Label^ label_panel_WHO_1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Edit_Student::typeid));
			this->GendercomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->section_label = (gcnew System::Windows::Forms::Label());
			this->batch_label = (gcnew System::Windows::Forms::Label());
			this->campus__label = (gcnew System::Windows::Forms::Label());
			this->rollno_label = (gcnew System::Windows::Forms::Label());
			this->dob_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->gender_label = (gcnew System::Windows::Forms::Label());
			this->dob_label = (gcnew System::Windows::Forms::Label());
			this->cnic_label = (gcnew System::Windows::Forms::Label());
			this->mobileno_label = (gcnew System::Windows::Forms::Label());
			this->section_textBox = (gcnew System::Windows::Forms::TextBox());
			this->campus_textBox = (gcnew System::Windows::Forms::TextBox());
			this->batch_textBox = (gcnew System::Windows::Forms::TextBox());
			this->rollno_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cnic_textBox = (gcnew System::Windows::Forms::TextBox());
			this->mobile_num_textBox = (gcnew System::Windows::Forms::TextBox());
			this->TITLE = (gcnew System::Windows::Forms::Label());
			this->EXIT_button = (gcnew System::Windows::Forms::Button());
			this->Name_label = (gcnew System::Windows::Forms::Label());
			this->name_textBox = (gcnew System::Windows::Forms::TextBox());
			this->Logo_WHO = (gcnew System::Windows::Forms::Panel());
			this->label_paanel_WHO_2 = (gcnew System::Windows::Forms::Label());
			this->label_panel_WHO_1 = (gcnew System::Windows::Forms::Label());
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
			this->GendercomboBox->TabIndex = 89;
			// 
			// add_button
			// 
			this->add_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->add_button->ForeColor = System::Drawing::Color::White;
			this->add_button->Location = System::Drawing::Point(410, 633);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(179, 57);
			this->add_button->TabIndex = 88;
			this->add_button->Text = L"EDIT";
			this->add_button->UseVisualStyleBackColor = false;
			this->add_button->Click += gcnew System::EventHandler(this, &Edit_Student::add_button_Click);
			// 
			// section_label
			// 
			this->section_label->AutoSize = true;
			this->section_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->section_label->Location = System::Drawing::Point(374, 490);
			this->section_label->Name = L"section_label";
			this->section_label->Size = System::Drawing::Size(85, 26);
			this->section_label->TabIndex = 87;
			this->section_label->Text = L"Section";
			// 
			// batch_label
			// 
			this->batch_label->AutoSize = true;
			this->batch_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->batch_label->Location = System::Drawing::Point(377, 573);
			this->batch_label->Name = L"batch_label";
			this->batch_label->Size = System::Drawing::Size(68, 26);
			this->batch_label->TabIndex = 86;
			this->batch_label->Text = L"Batch";
			// 
			// campus__label
			// 
			this->campus__label->AutoSize = true;
			this->campus__label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->campus__label->Location = System::Drawing::Point(376, 533);
			this->campus__label->Name = L"campus__label";
			this->campus__label->Size = System::Drawing::Size(94, 26);
			this->campus__label->TabIndex = 85;
			this->campus__label->Text = L"Campus";
			// 
			// rollno_label
			// 
			this->rollno_label->AutoSize = true;
			this->rollno_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->rollno_label->Location = System::Drawing::Point(374, 449);
			this->rollno_label->Name = L"rollno_label";
			this->rollno_label->Size = System::Drawing::Size(134, 26);
			this->rollno_label->TabIndex = 84;
			this->rollno_label->Text = L"Roll Number";
			// 
			// dob_dateTimePicker
			// 
			this->dob_dateTimePicker->Location = System::Drawing::Point(531, 242);
			this->dob_dateTimePicker->Name = L"dob_dateTimePicker";
			this->dob_dateTimePicker->Size = System::Drawing::Size(467, 26);
			this->dob_dateTimePicker->TabIndex = 83;
			// 
			// gender_label
			// 
			this->gender_label->AutoSize = true;
			this->gender_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->gender_label->Location = System::Drawing::Point(347, 155);
			this->gender_label->Name = L"gender_label";
			this->gender_label->Size = System::Drawing::Size(84, 26);
			this->gender_label->TabIndex = 82;
			this->gender_label->Text = L"Gender";
			// 
			// dob_label
			// 
			this->dob_label->AutoSize = true;
			this->dob_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->dob_label->Location = System::Drawing::Point(350, 238);
			this->dob_label->Name = L"dob_label";
			this->dob_label->Size = System::Drawing::Size(133, 26);
			this->dob_label->TabIndex = 81;
			this->dob_label->Text = L"Date of Birth";
			// 
			// cnic_label
			// 
			this->cnic_label->AutoSize = true;
			this->cnic_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->cnic_label->Location = System::Drawing::Point(349, 198);
			this->cnic_label->Name = L"cnic_label";
			this->cnic_label->Size = System::Drawing::Size(66, 26);
			this->cnic_label->TabIndex = 80;
			this->cnic_label->Text = L"CNIC";
			// 
			// mobileno_label
			// 
			this->mobileno_label->AutoSize = true;
			this->mobileno_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->mobileno_label->Location = System::Drawing::Point(348, 285);
			this->mobileno_label->Name = L"mobileno_label";
			this->mobileno_label->Size = System::Drawing::Size(160, 26);
			this->mobileno_label->TabIndex = 79;
			this->mobileno_label->Text = L"Mobile Number";
			// 
			// section_textBox
			// 
			this->section_textBox->Location = System::Drawing::Point(530, 492);
			this->section_textBox->Name = L"section_textBox";
			this->section_textBox->Size = System::Drawing::Size(468, 26);
			this->section_textBox->TabIndex = 78;
			// 
			// campus_textBox
			// 
			this->campus_textBox->Location = System::Drawing::Point(530, 535);
			this->campus_textBox->Name = L"campus_textBox";
			this->campus_textBox->Size = System::Drawing::Size(468, 26);
			this->campus_textBox->TabIndex = 77;
			// 
			// batch_textBox
			// 
			this->batch_textBox->Location = System::Drawing::Point(530, 577);
			this->batch_textBox->Name = L"batch_textBox";
			this->batch_textBox->Size = System::Drawing::Size(468, 26);
			this->batch_textBox->TabIndex = 76;
			// 
			// rollno_textBox
			// 
			this->rollno_textBox->Location = System::Drawing::Point(530, 455);
			this->rollno_textBox->Name = L"rollno_textBox";
			this->rollno_textBox->Size = System::Drawing::Size(468, 26);
			this->rollno_textBox->TabIndex = 75;
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
			this->label1->TabIndex = 74;
			this->label1->Text = L"ACADEMIC INFORMATION";
			// 
			// cnic_textBox
			// 
			this->cnic_textBox->Location = System::Drawing::Point(530, 198);
			this->cnic_textBox->Name = L"cnic_textBox";
			this->cnic_textBox->Size = System::Drawing::Size(468, 26);
			this->cnic_textBox->TabIndex = 73;
			// 
			// mobile_num_textBox
			// 
			this->mobile_num_textBox->Location = System::Drawing::Point(530, 287);
			this->mobile_num_textBox->Name = L"mobile_num_textBox";
			this->mobile_num_textBox->Size = System::Drawing::Size(468, 26);
			this->mobile_num_textBox->TabIndex = 72;
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
			this->TITLE->TabIndex = 71;
			this->TITLE->Text = L"PERSONAL INFORMATION";
			// 
			// EXIT_button
			// 
			this->EXIT_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->EXIT_button->ForeColor = System::Drawing::Color::White;
			this->EXIT_button->Location = System::Drawing::Point(819, 633);
			this->EXIT_button->Name = L"EXIT_button";
			this->EXIT_button->Size = System::Drawing::Size(179, 57);
			this->EXIT_button->TabIndex = 70;
			this->EXIT_button->Text = L"EXIT";
			this->EXIT_button->UseVisualStyleBackColor = false;
			this->EXIT_button->Click += gcnew System::EventHandler(this, &Edit_Student::EXIT_button_Click);
			// 
			// Name_label
			// 
			this->Name_label->AutoSize = true;
			this->Name_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->Name_label->Location = System::Drawing::Point(351, 118);
			this->Name_label->Name = L"Name_label";
			this->Name_label->Size = System::Drawing::Size(71, 26);
			this->Name_label->TabIndex = 69;
			this->Name_label->Text = L"Name";
			// 
			// name_textBox
			// 
			this->name_textBox->Location = System::Drawing::Point(530, 118);
			this->name_textBox->Name = L"name_textBox";
			this->name_textBox->Size = System::Drawing::Size(468, 26);
			this->name_textBox->TabIndex = 68;
			// 
			// Logo_WHO
			// 
			this->Logo_WHO->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->Logo_WHO->Controls->Add(this->label_paanel_WHO_2);
			this->Logo_WHO->Controls->Add(this->label_panel_WHO_1);
			this->Logo_WHO->Controls->Add(this->pictureBox1);
			this->Logo_WHO->Location = System::Drawing::Point(-1, -1);
			this->Logo_WHO->Name = L"Logo_WHO";
			this->Logo_WHO->Size = System::Drawing::Size(235, 715);
			this->Logo_WHO->TabIndex = 67;
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
			// Edit_Student
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1185, 713);
			this->Controls->Add(this->GendercomboBox);
			this->Controls->Add(this->add_button);
			this->Controls->Add(this->section_label);
			this->Controls->Add(this->batch_label);
			this->Controls->Add(this->campus__label);
			this->Controls->Add(this->rollno_label);
			this->Controls->Add(this->dob_dateTimePicker);
			this->Controls->Add(this->gender_label);
			this->Controls->Add(this->dob_label);
			this->Controls->Add(this->cnic_label);
			this->Controls->Add(this->mobileno_label);
			this->Controls->Add(this->section_textBox);
			this->Controls->Add(this->campus_textBox);
			this->Controls->Add(this->batch_textBox);
			this->Controls->Add(this->rollno_textBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cnic_textBox);
			this->Controls->Add(this->mobile_num_textBox);
			this->Controls->Add(this->TITLE);
			this->Controls->Add(this->EXIT_button);
			this->Controls->Add(this->Name_label);
			this->Controls->Add(this->name_textBox);
			this->Controls->Add(this->Logo_WHO);
			this->MaximumSize = System::Drawing::Size(1207, 769);
			this->MinimumSize = System::Drawing::Size(1207, 769);
			this->Name = L"Edit_Student";
			this->Text = L"Edit_Student";
			this->Load += gcnew System::EventHandler(this, &Edit_Student::Edit_Student_Load);
			this->Logo_WHO->ResumeLayout(false);
			this->Logo_WHO->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Edit_Student_Load(System::Object^ sender, System::EventArgs^ e) {
		
		String^ activeFile = "SearchStudent.txt";
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
					rollNo = line->Split(',')[1]->Trim();
					break;
				}
			}
			active->Close();
		}


		

			FillStudentDetails(rollNo, name, gender, cnic, dob, mobileNumber, section, campus, batch);

		if (found) {
			name_textBox->Text = name;
			cnic_textBox->Text = cnic;
			dob_dateTimePicker->Value = DateTime::Parse(dob);
			mobile_num_textBox->Text = mobileNumber;
			section_textBox->Text = section;
			campus_textBox->Text = campus;
			batch_textBox->Text = batch;
			rollno_textBox->Text = rollNo;
			GendercomboBox->Text = gender;
		}
		else {
		MessageBox::Show("Student not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		//name_textBox->Text = "N/A";
		//cnic_textBox->Text = "N/A";
		////dob_dateTimePicker->Value = DateTime::Parse(dob);
		//mobile_num_textBox->Text = "N/A";
		//section_textBox->Text = "N/A";
		//campus_textBox->Text = "N/A";
		//batch_textBox->Text = "N/A";
		//rollno_textBox->Text = "N/A";
		//GendercomboBox->Text = "N/A";
		this->Close();
		}

	}
private: System::Void add_button_Click(System::Object^ sender, System::EventArgs^ e) {
	RemoveThatStudent();
	//std::string roll_temp = marshal_as<std::string>(rollNo);

	RemoveTheStudent(rollNo);
	String^ roll = rollNo;
	std::string roll_temp= marshal_as<std::string>(roll);
	std::string roll_temp1 = "l";

	int i = 0;
	for (; i < 2; ++i) {
		roll_temp1 += roll_temp[i];
	}
	i += 2;
	for (; roll_temp[i] != '\0'; ++i) {
		roll_temp1 += roll_temp[i];
	}

	roll_temp1+="@lhr.nu.edu.pk";
	RemoveLineFromFile(roll_temp1);

	String^ temproll= rollNo;
	std::string rollNumberr = marshal_as<std::string>(temproll);
	RemoveStudentFromFileStudents(rollNumberr);

	RemoveStudentFromFileStudent("student.txt", rollNumberr);
	AddAdmin^ addAdmin = gcnew AddAdmin();
	bool addedSuccessfully = addAdmin->AddStudent(name_textBox->Text, GendercomboBox->SelectedItem->ToString(), cnic_textBox->Text, dob_dateTimePicker->Value.ToShortDateString(), mobile_num_textBox->Text, rollno_textBox->Text, section_textBox->Text, campus_textBox->Text, batch_textBox->Text);

	if (!addedSuccessfully) {
		MessageBox::Show("An error occurred while adding the student. Please try again.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return; 
	}
	else {
		MessageBox::Show("Student edited successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
private: System::Void EXIT_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
}
};
}
