#pragma once
#include <msclr/marshal_cppstd.h>
#include "Admin_DisplayLoanRecord.h"
#include "Admin_DisplayEquipment.h"
#include "Admin_Update.h"
#include "FileHandler.h"

namespace grpProjectGUIver {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Admin_GUI
	/// </summary>
	public ref class Admin_GUI : public System::Windows::Forms::Form
	{
	public:
		Admin_GUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	public:
		Admin_GUI(System::Windows::Forms::Form ^ parentForm)
		{
			InitializeComponent();
			goback = parentForm;
		}
	public: System::Windows::Forms::Form ^ goback;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Admin_GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button4;
	protected:
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button_exit;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Admin_GUI::typeid));
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(208, 458);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(173, 90);
			this->button4->TabIndex = 17;
			this->button4->Text = L"Display Camp Equipment list";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Admin_GUI::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(27, 458);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(173, 90);
			this->button3->TabIndex = 16;
			this->button3->Text = L"Update Condition of Equipments";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Admin_GUI::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(206, 362);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(173, 90);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Display Loan Records";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Admin_GUI::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(27, 362);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(173, 90);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Import Current Status txt";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Admin_GUI::button1_Click);
			// 
			// button_exit
			// 
			this->button_exit->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button_exit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_exit->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button_exit->Font = (gcnew System::Drawing::Font(L"Gadugi", 12, System::Drawing::FontStyle::Bold));
			this->button_exit->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_exit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button_exit->Location = System::Drawing::Point(292, 52);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(89, 30);
			this->button_exit->TabIndex = 13;
			this->button_exit->Text = L"Logout";
			this->button_exit->UseVisualStyleBackColor = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &Admin_GUI::button_exit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::MintCream;
			this->label1->Location = System::Drawing::Point(19, 74);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 94);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Welcome!\r\nAdmin";
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(27, 266);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(173, 90);
			this->button5->TabIndex = 18;
			this->button5->Text = L"Import Camp Equipment txt";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Admin_GUI::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(206, 266);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(173, 90);
			this->button6->TabIndex = 19;
			this->button6->Text = L"Import User txt";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Admin_GUI::button6_Click);
			// 
			// Admin_GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(400, 600);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
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
			this->Name = L"Admin_GUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Admin_GUI";
			this->Load += gcnew System::EventHandler(this, &Admin_GUI::Admin_GUI_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Admin_GUI::Admin_GUI_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Admin_GUI::Admin_GUI_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Admin_GUI::Admin_GUI_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool dragging;
	private: Point offset;

	private: System::Void Admin_GUI_Load(System::Object^  sender, System::EventArgs^  e) {
		this->dragging = false;
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
		String ^ fileLocation;
		FileHandler txt;
		openFileDialog->InitialDirectory = "c:\\";
		openFileDialog->Filter = "txt files (*.txt)|*.txt";
		openFileDialog->FilterIndex = 1;
		openFileDialog->RestoreDirectory = true;
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			fileLocation = openFileDialog->FileName;
			msclr::interop::marshal_context fileLocation_converting;
			std::string fileLocation_converted = fileLocation_converting.marshal_as<std::string>(fileLocation);
			allEquipments.deque::erase(allEquipments.begin(), allEquipments.end());
			txt.clearCurrentStatus();
			txt.clearCampEquipment();
			txt.ReadEquipment(fileLocation_converted);
			txt.CurrentStatusChecking();
			txt.WriteEquipment();
		}
	}

	private: System::Void button_exit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		goback->Show();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		Admin_DisplayLoanRecord ^ adminForm = gcnew Admin_DisplayLoanRecord(this);
		this->Hide();
		adminForm->Show();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		Admin_Update ^ adminForm = gcnew Admin_Update(this);
		this->Hide();
		adminForm->Show();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		Admin_DisplayEquipment ^ adminForm = gcnew Admin_DisplayEquipment(this);
		this->Hide();
		adminForm->Show();
	}
	private: System::Void Admin_GUI_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->dragging = true;
		this->offset = Point(e->X, e->Y);
	}
	private: System::Void Admin_GUI_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (this->dragging) {
			Point currentScreenPos = PointToScreen(e->Location);
			Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
		}
	}
	private: System::Void Admin_GUI_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->dragging = false;
	}

	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
		String ^ fileLocation;
		FileHandler txt;
		openFileDialog->InitialDirectory = "c:\\";
		openFileDialog->Filter = "txt files (*.txt)|*.txt";
		openFileDialog->FilterIndex = 1;
		openFileDialog->RestoreDirectory = true;
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			fileLocation = openFileDialog->FileName;
			msclr::interop::marshal_context fileLocation_converting;
			std::string fileLocation_converted = fileLocation_converting.marshal_as<std::string>(fileLocation);
			allUsers.deque::erase(allUsers.begin(), allUsers.end());
			txt.ReadUser(fileLocation_converted);
			txt.writeUser();
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
		String ^ fileLocation;
		FileHandler txt;
		openFileDialog->InitialDirectory = "c:\\";
		openFileDialog->Filter = "txt files (*.txt)|*.txt";
		openFileDialog->FilterIndex = 1;
		openFileDialog->RestoreDirectory = true;
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			fileLocation = openFileDialog->FileName;
			msclr::interop::marshal_context fileLocation_converting;
			std::string fileLocation_converted = fileLocation_converting.marshal_as<std::string>(fileLocation);
			txt.clearCurrentStatus();
			txt.writeCurrentStatus(fileLocation_converted);
			txt.WriteEquipment();
		}
	}
};
}
