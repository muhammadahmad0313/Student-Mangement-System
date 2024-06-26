#pragma once
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
	/// Summary for Remove_Student
	/// </summary>
	public ref class Remove_Student : public System::Windows::Forms::Form
	{
	private:
		String^ title;
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
		String^ userID;
		String^ degree;
		String^ depart;
		bool isStudentFound;
		bool isTeacherFound;

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


		void RemoveLineFromFileS(std::string& contentToRemove) {
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



		void GetTitle(String^% title)
		{
			String^ fileName = "SearchUser.txt";
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
		void WriteToFileStudent(String^ data) {
			String^ filePath = "SearchStudent.txt";
			System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(filePath, false); 
			sw->WriteLine("Roll Number," + data);
			sw->Close();
		}

		void WriteToFileTeacher(String^ data) {
			String^ filePath = "Search_Teacher.txt";
			System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(filePath, false); 
			sw->WriteLine("Roll Number," + data);
			sw->Close();
		}

	


		void SetTitle(String^ title)
		{
			this->title = title;
		}

		String^ ReturnTitle()
		{
			return title;
		}


		void Counter_Increament() {
			Counter++;
		}

		int Counter_Return() {
			return Counter;
		}

		void RemoveThatStudent()
		{
			int current = 0;
			//String^ activeFile = "Active.txt";

			String^ fileName = "admin_student.txt";
			String^ tempFile = "temp.txt";
			String^ line;

			if (IO::File::Exists(fileName))
			{
			IO::StreamReader^ sr = gcnew IO::StreamReader(fileName);
			IO::StreamWriter^ sw = gcnew IO::StreamWriter(tempFile);
			//Boolean isStudentFound = false;

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
							//isStudentFound = true;
							continue;
						}

						else if (key == "CNIC" && value == cnic && current == Counter_Return()) {
							isStudentFound = true;
							continue;
						}
						else if (key == "Date of Birth" && value == dob && current == Counter_Return()) {
							//isStudentFound = true;
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
							//isStudentFound = true;
							continue;
						}

					}
					sw->WriteLine(line); 

				}

				sr->Close();
				sw->Close();
				IO::File::Delete(fileName);
				IO::File::Move(tempFile, fileName);
				current = 0;

				if (isStudentFound) {
					if (IO::File::Exists(fileName))
					{
						StreamReader^ srr = gcnew StreamReader(fileName);


						StreamWriter^ sww = gcnew StreamWriter(tempFile);
						while ((line = srr->ReadLine()) != nullptr) {
							array<String^>^ parts = line->Split(',');
							if (parts->Length == 2)
							{
								String^ key = parts[0]->Trim();
								String^ value = parts[1]->Trim();

								if (!(key == "" && current + 1 == Counter_Return())) {
									sww->WriteLine(line);
								}
								if (key == "Name") {
									current++;
								}

							}
						}
						srr->Close();
						sww->Close();
						IO::File::Delete(fileName);
						IO::File::Move(tempFile, fileName);


						if (IO::File::Exists(fileName))
						{
							StreamReader^ srr = gcnew StreamReader(fileName);


							StreamWriter^ sww = gcnew StreamWriter(tempFile);
							while ((line = srr->ReadLine()) != nullptr) {
								array<String^>^ parts = line->Split(',');
								if (parts->Length == 2)
								{
									String^ key = parts[0]->Trim();
									String^ value = parts[1]->Trim();


									if (key == "Batch") {
										sww->WriteLine(line);
										sww->WriteLine("");
									}
									else {
										sww->WriteLine(line);
									}

								}
							}
							srr->Close();
							sww->Close();
							IO::File::Delete(fileName);
							IO::File::Move(tempFile, fileName);
						}
					}
				}

			}
			else
			{
				MessageBox::Show("File not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void FillStudentDetails(String^% rollNum, String^% nameTextBox, String^% genderComboBox, String^% cnicTextBox,
			String^% dobDateTimePicker, String^% mobileTextBox, String^% sectionTextBox,
			String^% campusTextBox, String^% batchTextBox)
		{

			int counter = 0;
			String^ fileName = "admin_student.txt";
			if (IO::File::Exists(fileName))
			{
				IO::StreamReader^ sr = gcnew IO::StreamReader(fileName);
				String^ line;
				//Boolean isStudentFound = false;

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
			if (rollNum == nullptr)
			{
				rollNo = "N/A";
				isStudentFound = false;
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



		//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		void GetUserID(String^% title)
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
						SetUserID(key);
					}
				}
				sr->Close();
			}
		}

		void SetUserID(String^ title)
		{
			this->userID = title;
		}

		String^ ReturnUserID()
		{
			return userID;
		}
	

		void FillTeacherDetails(String^% userid, String^% nameTextBox, String^% genderComboBox, String^% cnicTextBox,
			String^% dobDateTimePicker, String^% mobileTextBox, String^% degreeTextBox,
			String^% campusTextBox, String^% departTextBox)
		{

			int counter = 0;
			String^ fileName = "admin_teacher.txt";
			if (IO::File::Exists(fileName))
			{
				IO::StreamReader^ sr = gcnew IO::StreamReader(fileName);
				String^ line;
				//Boolean isStudentFound = false;

				while ((line = sr->ReadLine()) != nullptr)
				{
					array<String^>^ parts = line->Split(',');
					if (parts->Length == 2)
					{
						String^ key = parts[0]->Trim();
						String^ value = parts[1]->Trim();

						if (key == "User ID" && value == ReturnUserID())
						{
							isStudentFound = true;
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
			if (userid == nullptr)
			{
				userID = "N/A";
				isStudentFound = false;
			}

			if (cnicTextBox == nullptr) {
				cnic = "N/A";
			}

			if (mobileTextBox == nullptr) {
				mobileNumber = "N/A";
			}
			if (degreeTextBox == nullptr) {
				section = "N/A";
			}
			if (campusTextBox == nullptr) {
				campus = "N/A";
			}
			if (departTextBox == nullptr) {
				batch = "N/A";
			}
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


		void RemoveThatTeacher()
		{
			int current = 0;
			//String^ activeFile = "Active.txt";

			String^ fileName = "admin_teacher.txt";
			String^ tempFile = "temp.txt";

			if (IO::File::Exists(fileName))
			{
				IO::StreamReader^ sr = gcnew IO::StreamReader(fileName);
				IO::StreamWriter^ sw = gcnew IO::StreamWriter(tempFile);
				String^ line;
				//isStudentFound = false;

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
							isTeacherFound = true;
							continue; 
						}
						else if (key == "User ID" && value == userID && current == Counter_Return())
						{
							isTeacherFound = true;
							continue;
						}
						else if (key == "Gender" && current == Counter_Return()) {
							//isTeacherFound = true;
							continue;
						}

						else if (key == "CNIC" && value == cnic && current == Counter_Return()) {
							isTeacherFound = true;
							continue;
						}
						else if (key == "Date of Birth" && value == dob && current == Counter_Return()) {
							//isTeacherFound = true;
							continue;
						}
						else if (key == "Mobile Number" && value == mobileNumber && current == Counter_Return()) {
							isTeacherFound = true;
							continue;
						}
						else if (key == "Degree" && value == degree && current == Counter_Return()) {
							isTeacherFound = true;
							continue;
						}
						else if (key == "Campus" && value == campus && current == Counter_Return()) {
							isTeacherFound = true;
							continue;
						}
						else if (key == "Department" && value == depart && current == Counter_Return()) {
							isTeacherFound = true;
							continue;
						}
						else if (key == "" && current == Counter_Return())
						{
							//isTeacherFound = true;
							continue;
						}

					}
					sw->WriteLine(line); 

				}

				sr->Close();
				sw->Close();
				IO::File::Delete(fileName);
				IO::File::Move(tempFile, fileName);

				current = 0;

				if (isTeacherFound) {
					if (IO::File::Exists(fileName))
					{
						StreamReader^ srr = gcnew StreamReader(fileName);


						StreamWriter^ sww = gcnew StreamWriter(tempFile);
						while ((line = srr->ReadLine()) != nullptr) {
							array<String^>^ parts = line->Split(',');
							if (parts->Length == 2)
							{
								String^ key = parts[0]->Trim();
								String^ value = parts[1]->Trim();

								if (!(key == "" && current + 1 == Counter_Return())) {
									sww->WriteLine(line);
								}
								if (key == "Name") {
									current++;
								}

							}
						}
						srr->Close();
						sww->Close();
						IO::File::Delete(fileName);
						IO::File::Move(tempFile, fileName);


						if (IO::File::Exists(fileName))
						{
							StreamReader^ srr = gcnew StreamReader(fileName);


							StreamWriter^ sww = gcnew StreamWriter(tempFile);
							while ((line = srr->ReadLine()) != nullptr) {
								array<String^>^ parts = line->Split(',');
								if (parts->Length == 2)
								{
									String^ key = parts[0]->Trim();
									String^ value = parts[1]->Trim();


									if (key == "Department") {
										sww->WriteLine(line);
										sww->WriteLine("");
									}
									else {
										sww->WriteLine(line);
									}

								}
							}
							srr->Close();
							sww->Close();
							IO::File::Delete(fileName);
							IO::File::Move(tempFile, fileName);
						}
					}

				}

			}
			else
			{
				MessageBox::Show("File not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		Remove_Student(void)
		{
			isTeacherFound = false;
			isStudentFound = false;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Remove_Student()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ Username;
	private: System::Windows::Forms::TextBox^ username_textBox;
	private: System::Windows::Forms::Button^ EXIT_button;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Remove_Student::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->Username = (gcnew System::Windows::Forms::Label());
			this->username_textBox = (gcnew System::Windows::Forms::TextBox());
			this->EXIT_button = (gcnew System::Windows::Forms::Button());
			this->Logo_WHO = (gcnew System::Windows::Forms::Panel());
			this->label_paanel_WHO_2 = (gcnew System::Windows::Forms::Label());
			this->label_panel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->Logo_WHO->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(564, 288);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(146, 68);
			this->button1->TabIndex = 40;
			this->button1->Text = L"SEARCH";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Remove_Student::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->label1->Location = System::Drawing::Point(355, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(305, 55);
			this->label1->TabIndex = 39;
			this->label1->Text = L"Search User!";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(259, 169);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(81, 65);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 38;
			this->pictureBox2->TabStop = false;
			// 
			// Username
			// 
			this->Username->AutoSize = true;
			this->Username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->Username->Location = System::Drawing::Point(350, 188);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(132, 30);
			this->Username->TabIndex = 37;
			this->Username->Text = L"Username";
			// 
			// username_textBox
			// 
			this->username_textBox->Location = System::Drawing::Point(509, 193);
			this->username_textBox->Name = L"username_textBox";
			this->username_textBox->Size = System::Drawing::Size(259, 26);
			this->username_textBox->TabIndex = 36;
			// 
			// EXIT_button
			// 
			this->EXIT_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->EXIT_button->ForeColor = System::Drawing::Color::White;
			this->EXIT_button->Location = System::Drawing::Point(318, 288);
			this->EXIT_button->Name = L"EXIT_button";
			this->EXIT_button->Size = System::Drawing::Size(146, 68);
			this->EXIT_button->TabIndex = 35;
			this->EXIT_button->Text = L"EXIT";
			this->EXIT_button->UseVisualStyleBackColor = false;
			this->EXIT_button->Click += gcnew System::EventHandler(this, &Remove_Student::EXIT_button_Click);
			// 
			// Logo_WHO
			// 
			this->Logo_WHO->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->Logo_WHO->Controls->Add(this->label_paanel_WHO_2);
			this->Logo_WHO->Controls->Add(this->label_panel);
			this->Logo_WHO->Controls->Add(this->pictureBox1);
			this->Logo_WHO->Location = System::Drawing::Point(-2, -91);
			this->Logo_WHO->Name = L"Logo_WHO";
			this->Logo_WHO->Size = System::Drawing::Size(235, 643);
			this->Logo_WHO->TabIndex = 34;
			// 
			// label_paanel_WHO_2
			// 
			this->label_paanel_WHO_2->AutoSize = true;
			this->label_paanel_WHO_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label_paanel_WHO_2->ForeColor = System::Drawing::Color::White;
			this->label_paanel_WHO_2->Location = System::Drawing::Point(55, 429);
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
			this->label_panel->Location = System::Drawing::Point(51, 386);
			this->label_panel->Name = L"label_panel";
			this->label_panel->Size = System::Drawing::Size(119, 40);
			this->label_panel->TabIndex = 1;
			this->label_panel->Text = L"Admin";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-2, 164);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(234, 205);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// Remove_Student
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(797, 460);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->Username);
			this->Controls->Add(this->username_textBox);
			this->Controls->Add(this->EXIT_button);
			this->Controls->Add(this->Logo_WHO);
			this->MaximumSize = System::Drawing::Size(819, 516);
			this->MinimumSize = System::Drawing::Size(819, 516);
			this->Name = L"Remove_Student";
			this->Text = L"Remove_Student";
			this->Load += gcnew System::EventHandler(this, &Remove_Student::Remove_Student_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->Logo_WHO->ResumeLayout(false);
			this->Logo_WHO->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		GetTitle(title);
		String^ username = username_textBox->Text;
		if (ReturnTitle() == "STUDENT") {
			WriteToFileStudent(username);
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
				RemoveThatStudent();

				RemoveTheStudent(rollNo);
				String^ roll = rollNo;
				std::string roll_temp = marshal_as<std::string>(roll);
				std::string roll_temp1 = "l";

				int i = 0;
				for (; i < 2; ++i) {
					roll_temp1 += roll_temp[i];
				}
				i += 2;
				for (; roll_temp[i] != '\0'; ++i) {
					roll_temp1 += roll_temp[i];
				}

				roll_temp1 += "@lhr.nu.edu.pk";
				RemoveLineFromFileS(roll_temp1);

				String^ temproll = rollNo;
				std::string rollNumberr = marshal_as<std::string>(temproll);
				RemoveStudentFromFileStudents(rollNumberr);

				RemoveStudentFromFileStudent("student.txt", rollNumberr);
			if (isStudentFound) {
				MessageBox::Show("Student Removed Successfully!");
			}
			else {
				MessageBox::Show("User not found!");
			}

		}
		else if (ReturnTitle() == "TEACHER") {
			WriteToFileTeacher(username);
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


			if (isTeacherFound) {
				MessageBox::Show("Teacher Removed Successfully!");
			}
			else{
								MessageBox::Show("User not found!");
			}
		}

		else {
			MessageBox::Show("User not found!");
		}
	}
private: System::Void Remove_Student_Load(System::Object^ sender, System::EventArgs^ e) {
	

}
private: System::Void EXIT_button_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
