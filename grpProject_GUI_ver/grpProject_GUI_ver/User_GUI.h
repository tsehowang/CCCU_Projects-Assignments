#pragma once
#include "User_displayEquipmentList.h"
#include "User_Loan.h"
#include "User_LoanRecord.h"
#include "User_Return.h"

namespace grpProjectGUIver {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for User_GUI
	/// </summary>
	public ref class User_GUI : public System::Windows::Forms::Form
	{
	public:
		User_GUI()
		{
			InitializeComponent();
		}
	public:
		User_GUI(System::Windows::Forms::Form ^ parentForm)
		{
			InitializeComponent();
			goback = parentForm;
		}
	public: System::Windows::Forms::Form ^ goback;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~User_GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button_exit;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(User_GUI::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DarkRed;
			this->label1->Location = System::Drawing::Point(26, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 47);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome!";
			// 
			// button_exit
			// 
			this->button_exit->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button_exit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_exit->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button_exit->Font = (gcnew System::Drawing::Font(L"Gadugi", 12, System::Drawing::FontStyle::Bold));
			this->button_exit->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_exit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button_exit->Location = System::Drawing::Point(299, 12);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(89, 30);
			this->button_exit->TabIndex = 7;
			this->button_exit->Text = L"Logout";
			this->button_exit->UseVisualStyleBackColor = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &User_GUI::button_exit_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(34, 216);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(146, 129);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Display List of Equipments";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &User_GUI::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(215, 216);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(146, 129);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Loan Items";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &User_GUI::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(34, 379);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(146, 129);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Display Your Loan Record";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &User_GUI::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(215, 379);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(146, 129);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Return Camp Equipments";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &User_GUI::button4_Click_1);
			// 
			// User_GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(400, 600);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(400, 600);
			this->MinimumSize = System::Drawing::Size(400, 600);
			this->Name = L"User_GUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"User_GUI";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &User_GUI::User_GUI_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &User_GUI::User_GUI_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &User_GUI::User_GUI_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_exit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
		goback->Show();
		
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		User_displayEquipmentList ^ userForm = gcnew User_displayEquipmentList(this);
		this->Hide();
		userForm->Show();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		User_Loan ^ userForm = gcnew User_Loan(this);
		this->Hide();
		userForm->Show();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		User_LoanRecord ^ userForm = gcnew User_LoanRecord(this);
		this->Hide();
		userForm->Show();
	}
	private: System::Void button4_Click_1(System::Object^  sender, System::EventArgs^  e) {
		User_Return ^ userForm = gcnew User_Return(this);
		this->Hide();
		userForm->Show();
	}
	private: bool dragging = false;
	private: Point offset;
	private: System::Void User_GUI_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (this->dragging) {
		Point currentScreenPos = PointToScreen(e->Location);
		Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
		}
	}

	private: System::Void User_GUI_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->dragging = true;
		this->offset = Point(e->X, e->Y);
	}
	private: System::Void User_GUI_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->dragging = false;
	}
};
}
