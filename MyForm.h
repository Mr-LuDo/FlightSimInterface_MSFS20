#pragma once

#ifndef MY_FORM
#define MY_FORM

#include "SharedData.h"
#include <Windows.h>
#include <process.h>

int MyUI(void* obj);

namespace FlightSimInterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		const SharedData* data_;
		//MyForm(void)
		MyForm(SharedData* data) : data_(data)	{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ UpdateButton;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;

	private: System::Windows::Forms::Timer^ timerUpdateData;


	private: System::Windows::Forms::CheckBox^ checkBox1;

	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->UpdateButton = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->timerUpdateData = (gcnew System::Windows::Forms::Timer(this->components));
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// UpdateButton
			// 
			this->UpdateButton->Location = System::Drawing::Point(65, 195);
			this->UpdateButton->Name = L"UpdateButton";
			this->UpdateButton->Size = System::Drawing::Size(77, 42);
			this->UpdateButton->TabIndex = 0;
			this->UpdateButton->Text = L"Show data";
			this->UpdateButton->UseVisualStyleBackColor = true;
			this->UpdateButton->Click += gcnew System::EventHandler(this, &MyForm::updatebutton_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(151, 195);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(77, 42);
			this->button2->TabIndex = 0;
			this->button2->Text = L"set Status";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(234, 195);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(49, 42);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Reset";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Location = System::Drawing::Point(157, 32);
			this->label1->MinimumSize = System::Drawing::Size(100, 2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Location = System::Drawing::Point(157, 61);
			this->label2->MinimumSize = System::Drawing::Size(100, 2);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"label2";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->Location = System::Drawing::Point(157, 90);
			this->label3->MinimumSize = System::Drawing::Size(100, 2);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 15);
			this->label3->TabIndex = 3;
			this->label3->Text = L"label3";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label4->Location = System::Drawing::Point(157, 119);
			this->label4->MinimumSize = System::Drawing::Size(100, 2);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 15);
			this->label4->TabIndex = 4;
			this->label4->Text = L"label4";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(95, 120);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Laltitude";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(97, 91);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(42, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Altitude";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(100, 62);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Pause";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(100, 33);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(37, 13);
			this->label8->TabIndex = 5;
			this->label8->Text = L"Status";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(90, 149);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(57, 13);
			this->label9->TabIndex = 9;
			this->label9->Text = L"Longtitude";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label10->Location = System::Drawing::Point(158, 148);
			this->label10->MinimumSize = System::Drawing::Size(100, 2);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(100, 15);
			this->label10->TabIndex = 10;
			this->label10->Text = L"label10";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timerUpdateData
			// 
			this->timerUpdateData->Enabled = true;
			this->timerUpdateData->Interval = 1000;
			this->timerUpdateData->Tick += gcnew System::EventHandler(this, &MyForm::timerUpdateData_Tick);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(203, 261);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 17);
			this->checkBox1->TabIndex = 11;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(371, 367);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->UpdateButton);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

		// ----------------------------------- Buttons -------------------------------------------------

		private: System::Void updatebutton_Click(System::Object^ sender, System::EventArgs^ e) {
			label1->Text = "" + (data_->UI_Status ? "ON": "OFF");	
			label2->Text = "" + data_->UI_PauseStatus;	
			label3->Text = "" + data_->UI_altitude;	
			label4->Text = "" + data_->UI_latitude;
			label10->Text = "" + data_->UI_longitude;
		}

		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			label1->Text = " button 2 clicked ";
		}

		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			label1->ResetText();
			label2->ResetText();
			label3->ResetText();
			label4->ResetText();
			label10->ResetText();
		}

		private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			timerUpdateData->Start();
		}

		// ------------------------------------- Others ----------------------------------------------
		
		private: System::Void timerUpdateData_Tick(System::Object^ sender, System::EventArgs^ e) {
			if (checkBox1->Checked)
				this->UpdateButton->PerformClick();
			else {
				timerUpdateData->Stop();
			}
		}


};
}


#endif //MY_FORM