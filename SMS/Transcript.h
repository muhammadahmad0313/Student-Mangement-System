#include<iostream>
#include<string>
#include<fstream>
#include<msclr/marshal_cppstd.h>
namespace SMS {
using namespace System;
using namespace System::IO;
	public ref class Transcript
	{
		int Students;
		System::String^ rollNumber;
		double OOP_Total_Quiz_Marks = 0;
		double ISE_Total_Quiz_Marks = 0;
		double DS_Total_Quiz_Marks = 0;
		double MVC_Total_Quiz_Marks = 0;
		double DLD_Total_Quiz_Marks = 0;

		double OOP_Total_Assignment_Marks = 0;
		double ISE_Total_Assignment_Marks = 0;
		double DS_Total_Assignment_Marks = 0;
		double MVC_Total_Assignment_Marks = 0;
		double DLD_Total_Assignment_Marks = 0;

		double OOP_Total_Midterm_Marks = 0;
		double ISE_Total_Midterm_Marks = 0;
		double DS_Total_Midterm_Marks = 0;
		double MVC_Total_Midterm_Marks = 0;
		double DLD_Total_Midterm_Marks = 0;

		double OOP_Total_Final_Marks = 0;
		double ISE_Total_Final_Marks = 0;
		double DS_Total_Final_Marks = 0;
		double MVC_Total_Final_Marks = 0;
		double DLD_Total_Final_Marks = 0;

		double OOP_Gained_Credit_Hours = 0;
		double ISE_Gained_Credit_Hours = 0;
		double DS_Gained_Credit_Hours = 0;
		double MVC_Gained_Credit_Hours = 0;
		double DLD_Gained_Credit_Hours = 0;

		double OOP_Credit_Hours = 3;
		double ISE_Credit_Hours = 3;
		double DS_Credit_Hours = 3;
		double MVC_Credit_Hours = 3;
		double DLD_Credit_Hours = 3;

		double gpa = 0;


		System::String^ OOP_Grade;
		System::String^ ISE_Grade;
		System::String^ DS_Grade;
		System::String^ MVC_Grade;
		System::String^ DLD_Grade;

	public:
		Transcript() {
			SetRollNumber();
			ReadStudents();
			ReadQuizMarks();
			ReadAssignmentMarks();
			ReadMidtermMarks();
			ReadFinalMarks();
			CalculateGrades();
		}	

		void IncrementStudents() {
			Students++;
		}
		int GetStudents() {
			return Students;
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

		void SetRollNumber() {
			System::String^ rollNum;
			System::String^ activeFile = "Active.txt";
			if (System::IO::File::Exists(activeFile))
			{
				System::IO::StreamReader^ active = gcnew System::IO::StreamReader(activeFile);
				System::String^ activeContent;
				activeContent = active->ReadLine();
				array<System::String^>^ activeLines = activeContent->Split('\n');
				for each (System::String ^ line in activeLines)
				{
					if (line->StartsWith("Roll Number"))
					{
						rollNum = line->Split(',')[1]->Trim();
						break;
					}
				}
				active->Close();
			}
			
			rollNumber= rollNum;
		}

		void ReadQuizMarks()
		{
			System::String^ fileName = "Quiz.txt";
			if (System::IO::File::Exists(fileName))
			{
				System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(fileName);
				System::String^ line;

				while ((line = sr->ReadLine()) != nullptr)
				{
					System::String^ subjectName = line->Trim();
					int studentsCount = 0;

					while (studentsCount < GetStudents())
					{
						line = sr->ReadLine();
						studentsCount++;
						if (line != nullptr && line != "")
						{
							array<System::String^>^ parts = line->Split(',');  
							if (parts->Length == 3)
							{
								System::String^ rollNum = parts[1]->Trim();
								System::String^ marksStr = parts[2]->Trim();

								double marks = System::Double::Parse(marksStr);

								if (rollNum->Equals(rollNumber))
								{
									if (subjectName->Equals("OOP"))
									{
										OOP_Total_Quiz_Marks += marks;
									}
									else if (subjectName->Equals("ISE"))
									{
										ISE_Total_Quiz_Marks += marks;
									}
									else if (subjectName->Equals("DS"))
									{
										DS_Total_Quiz_Marks += marks;
									}
									else if (subjectName->Equals("MVC"))
									{
										MVC_Total_Quiz_Marks += marks;
									}
									else if (subjectName->Equals("DLD"))
									{
										DLD_Total_Quiz_Marks += marks;
									}
									
									
								}
							}
						}
					}
				}
				sr->Close();
			}
		}
		//------------------------------------------------------------------------------------------------------------

		void ReadAssignmentMarks()
		{
			//String^ rollNo = Transcript::GetRollNumber();

			System::String^ fileName = "Assignment.txt";
			if (System::IO::File::Exists(fileName))
			{
				System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(fileName);
				System::String^ line;

				while ((line = sr->ReadLine()) != nullptr)
				{
					System::String^ subjectName = line->Trim(); 
					int studentsCount = 1;

					while (studentsCount <= GetStudents())
					{
						line = sr->ReadLine();
						studentsCount++;
						if (line != nullptr && line != "")
						{
							array<System::String^>^ parts = line->Split(',');  
							if (parts->Length == 3)
							{
								System::String^ name = parts[0]->Trim();
								System::String^ rollNum = parts[1]->Trim();
								System::String^ marksStr = parts[2]->Trim();

								double marks = System::Double::Parse(marksStr);

								if (rollNum->Equals(rollNumber))
								{
									if (subjectName->Equals("OOP"))
									{
										OOP_Total_Assignment_Marks += marks;
									}
									else if (subjectName->Equals("ISE"))
									{
										ISE_Total_Assignment_Marks += marks;
									}
									else if (subjectName->Equals("DS"))
									{
										DS_Total_Assignment_Marks += marks;
									}
									else if (subjectName->Equals("MVC"))
									{
										MVC_Total_Assignment_Marks += marks;
									}
									else if (subjectName->Equals("DLD"))
									{
										DLD_Total_Assignment_Marks += marks;
									}
									

									
								}
							}
						}
					}
				}
				sr->Close();
			}
		}
		//------------------------------------------------------------------------------------------------------------

		void ReadMidtermMarks()
		{
			//String^ rollNo = Transcript::GetRollNumber();


			System::String^ fileName = "Mid.txt";
			if (System::IO::File::Exists(fileName))
			{
				System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(fileName);
				System::String^ line;

				while ((line = sr->ReadLine()) != nullptr)
				{
					System::String^ subjectName = line->Trim();  
					int studentsCount = 0;

					while (studentsCount < GetStudents())
					{
						line = sr->ReadLine();
									studentsCount++;
						if (line != nullptr && line != "")
						{
							array<System::String^>^ parts = line->Split(',');  
							if (parts->Length == 3)
							{
								System::String^ name = parts[0]->Trim();
								System::String^ rollNum = parts[1]->Trim();
								System::String^ marksStr = parts[2]->Trim();

								double marks = System::Double::Parse(marksStr);

								if (rollNum->Equals(rollNumber))
								{
									if (subjectName->Equals("OOP"))
									{
										OOP_Total_Midterm_Marks += marks;
									}
									else if (subjectName->Equals("ISE"))
									{
										ISE_Total_Midterm_Marks += marks;
									}
									else if (subjectName->Equals("DS"))
									{
										DS_Total_Midterm_Marks += marks;
									}
									else if (subjectName->Equals("MVC"))
									{
										MVC_Total_Midterm_Marks += marks;
									}
									else if (subjectName->Equals("DLD"))
									{
										DLD_Total_Midterm_Marks += marks;
									}
								

									
								}
							}
						}
					}
				}
				sr->Close();
			}
		}

		//------------------------------------------------------------------------------------------------------------
		void ReadFinalMarks()
		{
			//String^ rollNo = Transcript::GetRollNumber();


			System::String^ fileName = "Final.txt";
			if (System::IO::File::Exists(fileName))
			{
				System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(fileName);
				System::String^ line;

				while ((line = sr->ReadLine()) != nullptr)
				{
					System::String^ subjectName = line->Trim();  
					int studentsCount = 0;

					while (studentsCount < GetStudents())
					{
						line = sr->ReadLine();
									studentsCount++;
						if (line != nullptr && line != "")
						{
							array<System::String^>^ parts = line->Split(',');  
							if (parts->Length == 3)
							{
								System::String^ name = parts[0]->Trim();
								System::String^ rollNum = parts[1]->Trim();
								System::String^ marksStr = parts[2]->Trim();

								double marks = System::Double::Parse(marksStr);

								if (rollNum->Equals(rollNumber))
								{
									if (subjectName->Equals("OOP"))
									{
										OOP_Total_Final_Marks += marks;
									}
									else if (subjectName->Equals("ISE"))
									{
										ISE_Total_Final_Marks += marks;
									}
									else if (subjectName->Equals("DS"))
									{
										DS_Total_Final_Marks += marks;
									}
									else if (subjectName->Equals("MVC"))
									{
										MVC_Total_Final_Marks += marks;
									}
									else if (subjectName->Equals("DLD"))
									{
										DLD_Total_Final_Marks += marks;
									}
								

									
								}
							}
						}
					}
				}
				sr->Close();
			}
		}

		//------------------------------------------------------------------------------------------------------------

	

		void CalculateGrades() {
			double OOP_Weighted_Average = ((OOP_Total_Quiz_Marks / 100) * 0.1) + ((OOP_Total_Assignment_Marks / 100) * 0.1) + ((OOP_Total_Midterm_Marks / 100) * 0.3) + ((OOP_Total_Final_Marks / 100) * 0.5);
			double ISE_Weighted_Average = ((ISE_Total_Quiz_Marks / 100) * 0.1) + ((ISE_Total_Assignment_Marks / 100) * 0.1) + ((ISE_Total_Midterm_Marks / 100) * 0.3) + ((ISE_Total_Final_Marks / 100) * 0.5);
			double DS_Weighted_Average = ((DS_Total_Quiz_Marks / 100) * 0.1) + ((DS_Total_Assignment_Marks / 100) * 0.1) + ((DS_Total_Midterm_Marks / 100) * 0.3) + ((DS_Total_Final_Marks / 100) * 0.5);
			double MVC_Weighted_Average = ((MVC_Total_Quiz_Marks / 100) * 0.1) + ((MVC_Total_Assignment_Marks / 100) * 0.1) + ((MVC_Total_Midterm_Marks / 100) * 0.3) + ((MVC_Total_Final_Marks / 100) * 0.5);
			double DLD_Weighted_Average = ((DLD_Total_Quiz_Marks / 100) * 0.1) + ((DLD_Total_Assignment_Marks / 100) * 0.1) + ((DLD_Total_Midterm_Marks / 100) * 0.3) + ((DLD_Total_Final_Marks / 100) * 0.5);

			OOP_Gained_Credit_Hours = OOP_Credit_Hours * OOP_Weighted_Average;
			ISE_Gained_Credit_Hours = ISE_Credit_Hours * ISE_Weighted_Average;
			DS_Gained_Credit_Hours = DS_Credit_Hours * DS_Weighted_Average;
			MVC_Gained_Credit_Hours = MVC_Credit_Hours * MVC_Weighted_Average;
			DLD_Gained_Credit_Hours = DLD_Credit_Hours * DLD_Weighted_Average;

			gpa= (OOP_Gained_Credit_Hours + ISE_Gained_Credit_Hours + DS_Gained_Credit_Hours + MVC_Gained_Credit_Hours + DLD_Gained_Credit_Hours) / (OOP_Credit_Hours + ISE_Credit_Hours + DS_Credit_Hours + MVC_Credit_Hours + DLD_Credit_Hours);


			OOP_Grade = GetGrade(OOP_Weighted_Average);
			ISE_Grade = GetGrade(ISE_Weighted_Average);
			DS_Grade = GetGrade(DS_Weighted_Average);
			MVC_Grade = GetGrade(MVC_Weighted_Average);
			DLD_Grade = GetGrade(DLD_Weighted_Average);

		}

		System::String^ GetGrade(double percentage) {
			if (percentage >= 0.90) return "A+";
			else if (percentage >= 0.85) return "A";
			else if (percentage >= 0.80) return "A-";
			else if (percentage >= 0.75) return "B+";
			else if (percentage >= 0.70) return "B";
			else if (percentage >= 0.65) return "B-";
			else if (percentage >= 0.60) return "C";
			else if (percentage >= 0.50) return "D";
			else return "F";
		}

		System::String^ getOOPGrade() {
			if (OOP_Total_Final_Marks != 0) {
				return OOP_Grade;
			}
			else
			{
				return "-";
			}
		}
		System::String^ getISEGrade() {
			if (ISE_Total_Final_Marks != 0) {
				return ISE_Grade;
			}
			else
			{
				return "-";
			}
		}
		System::String^ getDSGrade() {
			if (DS_Total_Final_Marks != 0) {
				return DS_Grade;
			}
			else
			{
				return "-";
			}
		}
		System::String^ getMVCGrade() {
			if (MVC_Total_Final_Marks != 0) {
				return MVC_Grade;
			}
			else
			{
				return "-";
			}
		}
		System::String^ getDLDGrade() {
			if (DLD_Total_Final_Marks != 0) {
				return DLD_Grade;
			}
			else
			{
				return "-";
			}
		}

		String^ getGPA() {
			gpa *= 4;
			gpa= Math::Round(gpa, 2);
		 String ^ myString = gpa.ToString();
		 return myString;
		}



		/*bool isFound() {
			if (rollNumber != nullptr) {
			return true;
			}
			else {
				return false;
			}
	;
		}*/

	};
}