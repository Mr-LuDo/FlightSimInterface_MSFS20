#pragma once

#ifndef MY_FORM_H
#define MY_FORM_H

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
	public ref class MyForm : public System::Windows::Forms::Form {

	public:
		SharedData* data_;
		String^ message_;
		
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
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TextBox^ Message_box;

	private: System::Windows::Forms::Label^ Serial_int1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;


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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->Serial_int1 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->Message_box = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// UpdateButton
			// 
			this->UpdateButton->Location = System::Drawing::Point(92, 267);
			this->UpdateButton->Name = L"UpdateButton";
			this->UpdateButton->Size = System::Drawing::Size(77, 42);
			this->UpdateButton->TabIndex = 0;
			this->UpdateButton->Text = L"Show data";
			this->UpdateButton->UseVisualStyleBackColor = true;
			this->UpdateButton->Click += gcnew System::EventHandler(this, &MyForm::updatebutton_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(178, 267);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(77, 42);
			this->button2->TabIndex = 0;
			this->button2->Text = L"set Status";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(261, 267);
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
			this->label1->Location = System::Drawing::Point(184, 104);
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
			this->label2->Location = System::Drawing::Point(184, 133);
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
			this->label3->Location = System::Drawing::Point(184, 162);
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
			this->label4->Location = System::Drawing::Point(184, 191);
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
			this->label5->Location = System::Drawing::Point(122, 192);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Laltitude";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(124, 163);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(42, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Altitude";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(127, 134);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Pause";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(127, 105);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(37, 13);
			this->label8->TabIndex = 5;
			this->label8->Text = L"Status";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(117, 221);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(57, 13);
			this->label9->TabIndex = 9;
			this->label9->Text = L"Longtitude";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label10->Location = System::Drawing::Point(185, 220);
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
			this->checkBox1->Location = System::Drawing::Point(230, 333);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 17);
			this->checkBox1->TabIndex = 11;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(458, 484);
			this->tabControl1->TabIndex = 12;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->Serial_int1);
			this->tabPage1->Controls->Add(this->progressBar1);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->checkBox1);
			this->tabPage1->Controls->Add(this->UpdateButton);
			this->tabPage1->Controls->Add(this->label10);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(450, 458);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// Serial_int1
			// 
			this->Serial_int1->AutoSize = true;
			this->Serial_int1->Location = System::Drawing::Point(117, 44);
			this->Serial_int1->Name = L"Serial_int1";
			this->Serial_int1->Size = System::Drawing::Size(56, 13);
			this->Serial_int1->TabIndex = 13;
			this->Serial_int1->Text = L"Serial_int1";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(184, 39);
			this->progressBar1->Maximum = 1000;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(100, 23);
			this->progressBar1->TabIndex = 12;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(450, 458);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// Message_box
			// 
			this->Message_box->Location = System::Drawing::Point(12, 512);
			this->Message_box->Multiline = true;
			this->Message_box->Name = L"Message_box";
			this->Message_box->ReadOnly = true;
			this->Message_box->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->Message_box->Size = System::Drawing::Size(458, 301);
			this->Message_box->TabIndex = 13;
			this->Message_box->Text = L"\r\n\r\n";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 840);
			this->Controls->Add(this->Message_box);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

		// ----------------------------------- Buttons -------------------------------------------------


	private: System::Void updatebutton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->label1->Text = "" + (data_->UI_Status ? "ON" : "OFF");
		this->label2->Text = "" + data_->UI_PauseStatus;
		this->label3->Text = "" + data_->UI_altitude;
		this->label4->Text = "" + data_->UI_latitude;
		this->label10->Text = "" + data_->UI_longitude;
		this->progressBar1->Value = data_->Serial_Knob_1;

		}

		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			label1->Text = " button 2 clicked ";
			data_->counter++;
			data_->updatedCounter = true;
		}

		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			label1->ResetText();
			label2->ResetText();
			label3->ResetText();
			label4->ResetText();
			label10->ResetText();
			Message_box->ResetText();
			this->progressBar1->Value = 0;
		}

		private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			timerUpdateData->Start();
		}

		// ------------------------------------- Others ----------------------------------------------
		
		private: System::Void timerUpdateData_Tick(System::Object^ sender, System::EventArgs^ e) {
			if (checkBox1->Checked)
				this->UpdateButton->PerformClick();
			else {
				//timerUpdateData->Stop();
			}

			message_ = "";
			for (auto it : data_->messageList) {
				String^ line = gcnew String(it);
				message_ = String::Join(message_, line, "\r\n");
			}
			this->Message_box->Text = message_;

		}


	};
}


#endif //MY_FORM_H