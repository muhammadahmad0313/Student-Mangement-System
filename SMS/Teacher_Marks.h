#pragma once
#include "Teacher_Marks2.h"
#include <fstream>
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>
//using namespace std;
namespace SMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Teacher_Marks
	/// </summary>
	public ref class Teacher_Marks : public System::Windows::Forms::Form
	{
	public:

		void WriteToFile(String^ data) {
			String^ filePath = "Teacher_Marks2.txt";
			System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(filePath, false); 
			sw->WriteLine(data);
			sw->Close();
		}



		Teacher_Marks(void)
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
		~Teacher_Marks()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ FINALbutton;
	private: System::Windows::Forms::Button^ EXIT_button;
	protected:


	private: System::Windows::Forms::Button^ MIDS_BUTTON;

	private: System::Windows::Forms::Button^ ASSIGNMENT_BUTTON;
	private: System::Windows::Forms::Button^ QUIZ_BUTTON;
	private: System::Windows::Forms::Label^ TITLE;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Teacher_Marks::typeid));
			this->FINALbutton = (gcnew System::Windows::Forms::Button());
			this->EXIT_button = (gcnew System::Windows::Forms::Button());
			this->MIDS_BUTTON = (gcnew System::Windows::Forms::Button());
			this->ASSIGNMENT_BUTTON = (gcnew System::Windows::Forms::Button());
			this->QUIZ_BUTTON = (gcnew System::Windows::Forms::Button());
			this->TITLE = (gcnew System::Windows::Forms::Label());
			this->Logo_WHO = (gcnew System::Windows::Forms::Panel());
			this->label_paanel_WHO_2 = (gcnew System::Windows::Forms::Label());
			this->label_panel_WHO_1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Logo_WHO->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// FINALbutton
			// 
			this->FINALbutton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->FINALbutton->ForeColor = System::Drawing::Color::White;
			this->FINALbutton->Location = System::Drawing::Point(312, 510);
			this->FINALbutton->Name = L"FINALbutton";
			this->FINALbutton->Size = System::Drawing::Size(394, 59);
			this->FINALbutton->TabIndex = 20;
			this->FINALbutton->Text = L"FINAL";
			this->FINALbutton->UseVisualStyleBackColor = false;
			this->FINALbutton->Click += gcnew System::EventHandler(this, &Teacher_Marks::MVCbutton_Click);
			// 
			// EXIT_button
			// 
			this->EXIT_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->EXIT_button->ForeColor = System::Drawing::Color::White;
			this->EXIT_button->Location = System::Drawing::Point(582, 605);
			this->EXIT_button->Name = L"EXIT_button";
			this->EXIT_button->Size = System::Drawing::Size(146, 68);
			this->EXIT_button->TabIndex = 19;
			this->EXIT_button->Text = L"EXIT";
			this->EXIT_button->UseVisualStyleBackColor = false;
			this->EXIT_button->Click += gcnew System::EventHandler(this, &Teacher_Marks::EXIT_Click);
			// 
			// MIDS_BUTTON
			// 
			this->MIDS_BUTTON->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->MIDS_BUTTON->ForeColor = System::Drawing::Color::White;
			this->MIDS_BUTTON->Location = System::Drawing::Point(311, 417);
			this->MIDS_BUTTON->Name = L"MIDS_BUTTON";
			this->MIDS_BUTTON->Size = System::Drawing::Size(394, 59);
			this->MIDS_BUTTON->TabIndex = 18;
			this->MIDS_BUTTON->Text = L"MID";
			this->MIDS_BUTTON->UseVisualStyleBackColor = false;
			this->MIDS_BUTTON->Click += gcnew System::EventHandler(this, &Teacher_Marks::MIDS_BUTTON_Click);
			// 
			// ASSIGNMENT_BUTTON
			// 
			this->ASSIGNMENT_BUTTON->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->ASSIGNMENT_BUTTON->ForeColor = System::Drawing::Color::White;
			this->ASSIGNMENT_BUTTON->Location = System::Drawing::Point(310, 306);
			this->ASSIGNMENT_BUTTON->Name = L"ASSIGNMENT_BUTTON";
			this->ASSIGNMENT_BUTTON->Size = System::Drawing::Size(394, 59);
			this->ASSIGNMENT_BUTTON->TabIndex = 17;
			this->ASSIGNMENT_BUTTON->Text = L"ASSIGNMENT";
			this->ASSIGNMENT_BUTTON->UseVisualStyleBackColor = false;
			this->ASSIGNMENT_BUTTON->Click += gcnew System::EventHandler(this, &Teacher_Marks::ASSIGNMENT_BUTTON_Click);
			// 
			// QUIZ_BUTTON
			// 
			this->QUIZ_BUTTON->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->QUIZ_BUTTON->ForeColor = System::Drawing::Color::White;
			this->QUIZ_BUTTON->Location = System::Drawing::Point(310, 201);
			this->QUIZ_BUTTON->Name = L"QUIZ_BUTTON";
			this->QUIZ_BUTTON->Size = System::Drawing::Size(394, 59);
			this->QUIZ_BUTTON->TabIndex = 16;
			this->QUIZ_BUTTON->Text = L"QUIZ";
			this->QUIZ_BUTTON->UseVisualStyleBackColor = false;
			this->QUIZ_BUTTON->Click += gcnew System::EventHandler(this, &Teacher_Marks::QUIZ_BUTTON_Click);
			// 
			// TITLE
			// 
			this->TITLE->AutoSize = true;
			this->TITLE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28));
			this->TITLE->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->TITLE->Location = System::Drawing::Point(331, 78);
			this->TITLE->Name = L"TITLE";
			this->TITLE->Size = System::Drawing::Size(321, 64);
			this->TITLE->TabIndex = 15;
			this->TITLE->Text = L"ACADEMIC";
			// 
			// Logo_WHO
			// 
			this->Logo_WHO->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->Logo_WHO->Controls->Add(this->label_paanel_WHO_2);
			this->Logo_WHO->Controls->Add(this->label_panel_WHO_1);
			this->Logo_WHO->Controls->Add(this->pictureBox1);
			this->Logo_WHO->Location = System::Drawing::Point(2, -4);
			this->Logo_WHO->Name = L"Logo_WHO";
			this->Logo_WHO->Size = System::Drawing::Size(239, 796);
			this->Logo_WHO->TabIndex = 14;
			// 
			// label_paanel_WHO_2
			// 
			this->label_paanel_WHO_2->AutoSize = true;
			this->label_paanel_WHO_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label_paanel_WHO_2->ForeColor = System::Drawing::Color::White;
			this->label_paanel_WHO_2->Location = System::Drawing::Point(58, 466);
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
			this->label_panel_WHO_1->Location = System::Drawing::Point(38, 426);
			this->label_panel_WHO_1->Name = L"label_panel_WHO_1";
			this->label_panel_WHO_1->Size = System::Drawing::Size(149, 40);
			this->label_panel_WHO_1->TabIndex = 1;
			this->label_panel_WHO_1->Text = L"Teacher";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-4, 201);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(234, 205);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// Teacher_Marks
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(780, 708);
			this->Controls->Add(this->FINALbutton);
			this->Controls->Add(this->EXIT_button);
			this->Controls->Add(this->MIDS_BUTTON);
			this->Controls->Add(this->ASSIGNMENT_BUTTON);
			this->Controls->Add(this->QUIZ_BUTTON);
			this->Controls->Add(this->TITLE);
			this->Controls->Add(this->Logo_WHO);
			this->MaximumSize = System::Drawing::Size(802, 764);
			this->MinimumSize = System::Drawing::Size(802, 764);
			this->Name = L"Teacher_Marks";
			this->Text = L"Teacher_Marks";
			this->Logo_WHO->ResumeLayout(false);
			this->Logo_WHO->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MVCbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		WriteToFile("FINAL");
		Teacher_Marks2 t3;
		t3.ShowDialog();
	}
private: System::Void QUIZ_BUTTON_Click(System::Object^ sender, System::EventArgs^ e) {
	WriteToFile("QUIZ");
	Teacher_Marks2 t;
	t.ShowDialog();
}
private: System::Void ASSIGNMENT_BUTTON_Click(System::Object^ sender, System::EventArgs^ e) {
	WriteToFile("ASSIGNMENT");
	Teacher_Marks2 t1;
	t1.ShowDialog();
}
private: System::Void MIDS_BUTTON_Click(System::Object^ sender, System::EventArgs^ e) {
	WriteToFile("MID");
	Teacher_Marks2 t2;
	t2.ShowDialog();
}
private: System::Void EXIT_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
