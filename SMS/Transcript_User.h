//#ifndef TRANSCRIPT_USER_H
//#define TRANSCRIPT_USER_H

#pragma once
#include <iostream> 
#include <string>
#include <fstream>  
#include <sstream>  
#include <msclr\marshal_cppstd.h>
#include "Transcript.h"

namespace SMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Transcript_User
	/// </summary>
	public ref class Transcript_User : public System::Windows::Forms::Form
	{
	public:
		String^ rollNumber; 
		/*void SomeMethod() {
			Transcript^ t = gcnew Transcript;
			t->FillFormFromActiveFile("Active.txt", "admin_student.txt", this);
		}*/

void ReadStudentInfo(String^% rollNumber, String^% section, String^% degree, String^% campus, String^% batch)
{
	String^ activeFile = "Active.txt";
	if(IO::File::Exists(activeFile))
	{
		IO::StreamReader^ active = gcnew IO::StreamReader(activeFile);
		String^ activeContent;
		activeContent = active->ReadLine();
		array<String^>^ activeLines = activeContent->Split('\n');
		for each (String^ line in activeLines)
		{
			if (line->StartsWith("Roll Number"))
			{
				rollNumber = line->Split(',')[1]->Trim();
				break;
			}
		}
		active->Close();
	}



	String^ fileName = "admin_student.txt";
	if (IO::File::Exists(fileName))
	{
		IO::StreamReader^ sr = gcnew IO::StreamReader(fileName);
		String^ line;
		Int32 lineNumber = 0;
		Boolean isStudentFound = false;
		while ((line = sr->ReadLine()) != nullptr)
		{
			array<String^>^ parts = line->Split(',');
			if (parts->Length == 2)
			{
				String^ key = parts[0]->Trim();
				String^ value = parts[1]->Trim();
				
				
				if (key == "Roll Number" && value == rollNumber)
				{
					isStudentFound = true;
				}
				if (isStudentFound) {

					if (key == "Section")
					{
						section = value;
						if (value == "se" || value == "SE" || value == "bsse" || value == "BSSE") {
							degree = "BSSE";
						}
						else if (value == "cs" || value == "CS" || value == "bscs" || value == "BSCS") {
							degree = "BSCS";
						}
						else if (value == "it" || value == "IT" || value == "bsit" || value == "BSIT") {
							degree = "BSIT";
						}
						
						else if (value == "ds" || value == "DS" || value == "bsds" || value == "BSDS") {
							degree = "BSDS";
						}

						
					}
					else if (key == "Campus")
					{
						campus = value;
					}
					else if (key == "Batch")
					{
						batch = value;
					}
					

				}
			}
		}
		sr->Close();
	}
}


		Transcript_User(void)
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
		~Transcript_User()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ degree_label;

	private: System::Windows::Forms::Label^ campus__label;
	private: System::Windows::Forms::Label^ OOP_label;

	private: System::Windows::Forms::Label^ section_label;
	private: System::Windows::Forms::Label^ batch_label;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ section_textBox;
	private: System::Windows::Forms::TextBox^ degree_textBox;
	private: System::Windows::Forms::TextBox^ batch_textBox;




	private: System::Windows::Forms::Label^ TITLE;

	private: System::Windows::Forms::Label^ rollno_label;
	private: System::Windows::Forms::TextBox^ rollno_textBox;

	private: System::Windows::Forms::Panel^ Logo_WHO;
	private: System::Windows::Forms::Label^ label_paanel_WHO_2;
	private: System::Windows::Forms::Label^ label_panel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ campus_textBox;
	private: System::Windows::Forms::TextBox^ oop_textBox;
	private: System::Windows::Forms::TextBox^ mvc_textBox;



	private: System::Windows::Forms::TextBox^ ds_textBox;

	private: System::Windows::Forms::TextBox^ ise_textBox;
	private: System::Windows::Forms::TextBox^ dld_textBox;


	private: System::Windows::Forms::Label^ DLDlabel;
	private: System::Windows::Forms::Label^ MVClabel;
	private: System::Windows::Forms::Label^ DSlabel;
	private: System::Windows::Forms::Label^ ISElabel;
	private: System::Windows::Forms::Button^ EXIT_button;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::TextBox^ textBox1;









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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Transcript_User::typeid));
			this->degree_label = (gcnew System::Windows::Forms::Label());
			this->campus__label = (gcnew System::Windows::Forms::Label());
			this->OOP_label = (gcnew System::Windows::Forms::Label());
			this->section_label = (gcnew System::Windows::Forms::Label());
			this->batch_label = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->section_textBox = (gcnew System::Windows::Forms::TextBox());
			this->degree_textBox = (gcnew System::Windows::Forms::TextBox());
			this->batch_textBox = (gcnew System::Windows::Forms::TextBox());
			this->TITLE = (gcnew System::Windows::Forms::Label());
			this->rollno_label = (gcnew System::Windows::Forms::Label());
			this->rollno_textBox = (gcnew System::Windows::Forms::TextBox());
			this->Logo_WHO = (gcnew System::Windows::Forms::Panel());
			this->label_paanel_WHO_2 = (gcnew System::Windows::Forms::Label());
			this->label_panel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->campus_textBox = (gcnew System::Windows::Forms::TextBox());
			this->oop_textBox = (gcnew System::Windows::Forms::TextBox());
			this->mvc_textBox = (gcnew System::Windows::Forms::TextBox());
			this->ds_textBox = (gcnew System::Windows::Forms::TextBox());
			this->ise_textBox = (gcnew System::Windows::Forms::TextBox());
			this->dld_textBox = (gcnew System::Windows::Forms::TextBox());
			this->DLDlabel = (gcnew System::Windows::Forms::Label());
			this->MVClabel = (gcnew System::Windows::Forms::Label());
			this->DSlabel = (gcnew System::Windows::Forms::Label());
			this->ISElabel = (gcnew System::Windows::Forms::Label());
			this->EXIT_button = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Logo_WHO->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// degree_label
			// 
			this->degree_label->AutoSize = true;
			this->degree_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->degree_label->Location = System::Drawing::Point(348, 173);
			this->degree_label->Name = L"degree_label";
			this->degree_label->Size = System::Drawing::Size(83, 26);
			this->degree_label->TabIndex = 85;
			this->degree_label->Text = L"Degree";
			// 
			// campus__label
			// 
			this->campus__label->AutoSize = true;
			this->campus__label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->campus__label->Location = System::Drawing::Point(348, 216);
			this->campus__label->Name = L"campus__label";
			this->campus__label->Size = System::Drawing::Size(94, 26);
			this->campus__label->TabIndex = 83;
			this->campus__label->Text = L"Campus";
			// 
			// OOP_label
			// 
			this->OOP_label->AutoSize = true;
			this->OOP_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->OOP_label->Location = System::Drawing::Point(372, 409);
			this->OOP_label->Name = L"OOP_label";
			this->OOP_label->Size = System::Drawing::Size(61, 26);
			this->OOP_label->TabIndex = 82;
			this->OOP_label->Text = L"OOP";
			// 
			// section_label
			// 
			this->section_label->AutoSize = true;
			this->section_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->section_label->Location = System::Drawing::Point(347, 132);
			this->section_label->Name = L"section_label";
			this->section_label->Size = System::Drawing::Size(85, 26);
			this->section_label->TabIndex = 80;
			this->section_label->Text = L"Section";
			// 
			// batch_label
			// 
			this->batch_label->AutoSize = true;
			this->batch_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->batch_label->Location = System::Drawing::Point(348, 262);
			this->batch_label->Name = L"batch_label";
			this->batch_label->Size = System::Drawing::Size(68, 26);
			this->batch_label->TabIndex = 77;
			this->batch_label->Text = L"Batch";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->label1->Location = System::Drawing::Point(462, 329);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(360, 59);
			this->label1->TabIndex = 72;
			this->label1->Text = L"TRANSCRIPT";
			// 
			// section_textBox
			// 
			this->section_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->section_textBox->Location = System::Drawing::Point(530, 132);
			this->section_textBox->Name = L"section_textBox";
			this->section_textBox->ReadOnly = true;
			this->section_textBox->Size = System::Drawing::Size(223, 26);
			this->section_textBox->TabIndex = 71;
			// 
			// degree_textBox
			// 
			this->degree_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->degree_textBox->Location = System::Drawing::Point(530, 175);
			this->degree_textBox->Name = L"degree_textBox";
			this->degree_textBox->ReadOnly = true;
			this->degree_textBox->Size = System::Drawing::Size(223, 26);
			this->degree_textBox->TabIndex = 70;
			// 
			// batch_textBox
			// 
			this->batch_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->batch_textBox->Location = System::Drawing::Point(530, 264);
			this->batch_textBox->Name = L"batch_textBox";
			this->batch_textBox->ReadOnly = true;
			this->batch_textBox->Size = System::Drawing::Size(223, 26);
			this->batch_textBox->TabIndex = 69;
			// 
			// TITLE
			// 
			this->TITLE->AutoSize = true;
			this->TITLE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26));
			this->TITLE->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->TITLE->Location = System::Drawing::Point(289, 12);
			this->TITLE->Name = L"TITLE";
			this->TITLE->Size = System::Drawing::Size(688, 59);
			this->TITLE->TabIndex = 68;
			this->TITLE->Text = L"PERSONAL INFORMATION";
			// 
			// rollno_label
			// 
			this->rollno_label->AutoSize = true;
			this->rollno_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->rollno_label->Location = System::Drawing::Point(348, 95);
			this->rollno_label->Name = L"rollno_label";
			this->rollno_label->Size = System::Drawing::Size(134, 26);
			this->rollno_label->TabIndex = 66;
			this->rollno_label->Text = L"Roll Number";
			// 
			// rollno_textBox
			// 
			this->rollno_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollno_textBox->Location = System::Drawing::Point(530, 95);
			this->rollno_textBox->Name = L"rollno_textBox";
			this->rollno_textBox->ReadOnly = true;
			this->rollno_textBox->Size = System::Drawing::Size(223, 26);
			this->rollno_textBox->TabIndex = 65;
			this->rollno_textBox->TextChanged += gcnew System::EventHandler(this, &Transcript_User::rollno_textBox_TextChanged);
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
			this->Logo_WHO->Size = System::Drawing::Size(235, 828);
			this->Logo_WHO->TabIndex = 64;
			this->Logo_WHO->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Transcript_User::Logo_WHO_Paint);
			// 
			// label_paanel_WHO_2
			// 
			this->label_paanel_WHO_2->AutoSize = true;
			this->label_paanel_WHO_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label_paanel_WHO_2->ForeColor = System::Drawing::Color::White;
			this->label_paanel_WHO_2->Location = System::Drawing::Point(62, 456);
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
			this->label_panel->Location = System::Drawing::Point(46, 413);
			this->label_panel->Name = L"label_panel";
			this->label_panel->Size = System::Drawing::Size(141, 40);
			this->label_panel->TabIndex = 1;
			this->label_panel->Text = L"Student";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(13, 194);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(212, 205);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// campus_textBox
			// 
			this->campus_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->campus_textBox->Location = System::Drawing::Point(530, 218);
			this->campus_textBox->Name = L"campus_textBox";
			this->campus_textBox->ReadOnly = true;
			this->campus_textBox->Size = System::Drawing::Size(223, 26);
			this->campus_textBox->TabIndex = 87;
			// 
			// oop_textBox
			// 
			this->oop_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->oop_textBox->Location = System::Drawing::Point(530, 415);
			this->oop_textBox->Name = L"oop_textBox";
			this->oop_textBox->ReadOnly = true;
			this->oop_textBox->Size = System::Drawing::Size(223, 26);
			this->oop_textBox->TabIndex = 73;
			this->oop_textBox->TextChanged += gcnew System::EventHandler(this, &Transcript_User::textBox4_TextChanged);
			// 
			// mvc_textBox
			// 
			this->mvc_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mvc_textBox->Location = System::Drawing::Point(530, 537);
			this->mvc_textBox->Name = L"mvc_textBox";
			this->mvc_textBox->ReadOnly = true;
			this->mvc_textBox->Size = System::Drawing::Size(223, 26);
			this->mvc_textBox->TabIndex = 74;
			// 
			// ds_textBox
			// 
			this->ds_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ds_textBox->Location = System::Drawing::Point(530, 495);
			this->ds_textBox->Name = L"ds_textBox";
			this->ds_textBox->ReadOnly = true;
			this->ds_textBox->Size = System::Drawing::Size(223, 26);
			this->ds_textBox->TabIndex = 75;
			// 
			// ise_textBox
			// 
			this->ise_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ise_textBox->Location = System::Drawing::Point(530, 452);
			this->ise_textBox->Name = L"ise_textBox";
			this->ise_textBox->ReadOnly = true;
			this->ise_textBox->Size = System::Drawing::Size(223, 26);
			this->ise_textBox->TabIndex = 76;
			// 
			// dld_textBox
			// 
			this->dld_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dld_textBox->Location = System::Drawing::Point(530, 582);
			this->dld_textBox->Name = L"dld_textBox";
			this->dld_textBox->ReadOnly = true;
			this->dld_textBox->Size = System::Drawing::Size(223, 26);
			this->dld_textBox->TabIndex = 90;
			// 
			// DLDlabel
			// 
			this->DLDlabel->AutoSize = true;
			this->DLDlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->DLDlabel->Location = System::Drawing::Point(372, 580);
			this->DLDlabel->Name = L"DLDlabel";
			this->DLDlabel->Size = System::Drawing::Size(56, 26);
			this->DLDlabel->TabIndex = 91;
			this->DLDlabel->Text = L"DLD";
			// 
			// MVClabel
			// 
			this->MVClabel->AutoSize = true;
			this->MVClabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->MVClabel->Location = System::Drawing::Point(372, 537);
			this->MVClabel->Name = L"MVClabel";
			this->MVClabel->Size = System::Drawing::Size(61, 26);
			this->MVClabel->TabIndex = 92;
			this->MVClabel->Text = L"MVC";
			// 
			// DSlabel
			// 
			this->DSlabel->AutoSize = true;
			this->DSlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->DSlabel->Location = System::Drawing::Point(372, 493);
			this->DSlabel->Name = L"DSlabel";
			this->DSlabel->Size = System::Drawing::Size(43, 26);
			this->DSlabel->TabIndex = 93;
			this->DSlabel->Text = L"DS";
			// 
			// ISElabel
			// 
			this->ISElabel->AutoSize = true;
			this->ISElabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->ISElabel->Location = System::Drawing::Point(372, 450);
			this->ISElabel->Name = L"ISElabel";
			this->ISElabel->Size = System::Drawing::Size(48, 26);
			this->ISElabel->TabIndex = 94;
			this->ISElabel->Text = L"ISE";
			// 
			// EXIT_button
			// 
			this->EXIT_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->EXIT_button->ForeColor = System::Drawing::Color::White;
			this->EXIT_button->Location = System::Drawing::Point(828, 618);
			this->EXIT_button->Name = L"EXIT_button";
			this->EXIT_button->Size = System::Drawing::Size(179, 57);
			this->EXIT_button->TabIndex = 67;
			this->EXIT_button->Text = L"EXIT";
			this->EXIT_button->UseVisualStyleBackColor = false;
			this->EXIT_button->Click += gcnew System::EventHandler(this, &Transcript_User::EXIT_button_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label2->Location = System::Drawing::Point(372, 631);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 26);
			this->label2->TabIndex = 96;
			this->label2->Text = L"GPA";
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(530, 633);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(223, 26);
			this->textBox1->TabIndex = 95;
			// 
			// Transcript_User
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1049, 706);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->ISElabel);
			this->Controls->Add(this->DSlabel);
			this->Controls->Add(this->MVClabel);
			this->Controls->Add(this->DLDlabel);
			this->Controls->Add(this->dld_textBox);
			this->Controls->Add(this->campus_textBox);
			this->Controls->Add(this->degree_label);
			this->Controls->Add(this->campus__label);
			this->Controls->Add(this->OOP_label);
			this->Controls->Add(this->section_label);
			this->Controls->Add(this->batch_label);
			this->Controls->Add(this->ise_textBox);
			this->Controls->Add(this->ds_textBox);
			this->Controls->Add(this->mvc_textBox);
			this->Controls->Add(this->oop_textBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->section_textBox);
			this->Controls->Add(this->degree_textBox);
			this->Controls->Add(this->batch_textBox);
			this->Controls->Add(this->TITLE);
			this->Controls->Add(this->EXIT_button);
			this->Controls->Add(this->rollno_label);
			this->Controls->Add(this->rollno_textBox);
			this->Controls->Add(this->Logo_WHO);
			this->MaximumSize = System::Drawing::Size(1071, 762);
			this->MinimumSize = System::Drawing::Size(1071, 762);
			this->Name = L"Transcript_User";
			this->Text = L"Transcript_User";
			this->Load += gcnew System::EventHandler(this, &Transcript_User::Transcript_User_Load);
			this->Logo_WHO->ResumeLayout(false);
			this->Logo_WHO->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Logo_WHO_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void Transcript_User_Load(System::Object^ sender, System::EventArgs^ e) {

	String^ section;
	String^ degree;
	String^ campus;
	String^ batch;
	ReadStudentInfo(rollNumber, section, degree, campus, batch);
	Transcript^ transcriptInstance = gcnew Transcript();

	if (section==nullptr || degree==nullptr || batch==nullptr || campus==nullptr) {
		MessageBox::Show("No student is active");
		this->Close();

	}
	else {
		rollno_textBox->Text = rollNumber;
		section_textBox->Text = section;
		degree_textBox->Text = degree;
		campus_textBox->Text = campus;
		batch_textBox->Text = batch;
		oop_textBox->Text = transcriptInstance->getOOPGrade();
		ise_textBox->Text = transcriptInstance->getISEGrade();
		ds_textBox->Text = transcriptInstance->getDSGrade();
		mvc_textBox->Text = transcriptInstance->getMVCGrade();
		dld_textBox->Text = transcriptInstance->getDLDGrade();
		textBox1->Text = transcriptInstance->getGPA();
	}


}
private: System::Void EXIT_button_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void rollno_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void gpatext_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
//#endif