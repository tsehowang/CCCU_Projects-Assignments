#pragma once
#include <msclr/marshal_cppstd.h>
#include "FileHandler.h"
#include "LoanControl.h"
#include "Admin.h"
#include "User_GUI.h"
#include "User_GUI2.h"
#include "Admin_GUI.h"


namespace grpProjectGUIver {

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
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^  textBox_userId;
	private: System::Windows::Forms::Label^  label_userId;
	private: System::Windows::Forms::Label^  label_password;
	private: System::Windows::Forms::TextBox^  textBox_password;
	private: System::Windows::Forms::Button^  button_login;
	private: System::Windows::Forms::Button^  button_exit;

	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label_userId = (gcnew System::Windows::Forms::Label());
			this->textBox_userId = (gcnew System::Windows::Forms::TextBox());
			this->label_password = (gcnew System::Windows::Forms::Label());
			this->textBox_password = (gcnew System::Windows::Forms::TextBox());
			this->button_login = (gcnew System::Windows::Forms::Button());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label_userId
			// 
			resources->ApplyResources(this->label_userId, L"label_userId");
			this->label_userId->BackColor = System::Drawing::Color::Transparent;
			this->label_userId->ForeColor = System::Drawing::Color::MistyRose;
			this->label_userId->Name = L"label_userId";
			// 
			// textBox_userId
			// 
			this->textBox_userId->BackColor = System::Drawing::Color::White;
			resources->ApplyResources(this->textBox_userId, L"textBox_userId");
			this->textBox_userId->Name = L"textBox_userId";
			// 
			// label_password
			// 
			resources->ApplyResources(this->label_password, L"label_password");
			this->label_password->BackColor = System::Drawing::Color::Transparent;
			this->label_password->ForeColor = System::Drawing::Color::MistyRose;
			this->label_password->Name = L"label_password";
			this->label_password->UseMnemonic = false;
			// 
			// textBox_password
			// 
			this->textBox_password->BackColor = System::Drawing::Color::White;
			resources->ApplyResources(this->textBox_password, L"textBox_password");
			this->textBox_password->Name = L"textBox_password";
			// 
			// button_login
			// 
			this->button_login->BackColor = System::Drawing::Color::WhiteSmoke;
			resources->ApplyResources(this->button_login, L"button_login");
			this->button_login->Name = L"button_login";
			this->button_login->UseVisualStyleBackColor = false;
			this->button_login->Click += gcnew System::EventHandler(this, &MyForm::button_login_Click);
			// 
			// button_exit
			// 
			this->button_exit->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button_exit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			resources->ApplyResources(this->button_exit, L"button_exit");
			this->button_exit->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_exit->Name = L"button_exit";
			this->button_exit->UseVisualStyleBackColor = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &MyForm::button_exit_Click);
			// 
			// MyForm
			// 
			this->AcceptButton = this->button_login;
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->CancelButton = this->button_exit;
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->button_login);
			this->Controls->Add(this->textBox_password);
			this->Controls->Add(this->label_password);
			this->Controls->Add(this->label_userId);
			this->Controls->Add(this->textBox_userId);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// function
	void loginSystem(String ^ loginId, String ^ password) {
	msclr::interop::marshal_context loginId_converting;
	std::string loginId_converted = loginId_converting.marshal_as<std::string>(loginId);
	msclr::interop::marshal_context password_converting;
	std::string password_converted = password_converting.marshal_as<std::string>(password);
	LoanControl Loan;
	FileHandler txt;
	Admin superUser;
	int admin = 0;
	int normalUser = 0;
		for (int i = 0; i < std::size(allUsers); i++) {
			if ((loginId_converted == allUsers[i]->getId()) && (password_converted == allUsers[i]->getDateOfBirth()) || (loginId_converted == superUser.getAdminId() && password_converted == superUser.getAdminPassword())) {
				if (loginId_converted == superUser.getAdminId() && password_converted == superUser.getAdminPassword()) {
					admin = 1;
					break;
				}
				else
					normalUser = 1;
				break;
			}
			else
				if (i == (std::size(allUsers) - 1))
					MessageBox::Show("Sorry, we can't verify your User ID or password. Please try again.");
		}
		if (admin == 1) {
			Admin_GUI ^ userForm = gcnew Admin_GUI(this);
			this->Hide();
			userForm->Show();
			textBox_password->Clear();
		}
		if (normalUser == 1) {
			if (txt.currentStatusHas(loginId_converted)) {
				User_GUI ^ userForm = gcnew User_GUI(this);
				this->Hide();
				userForm->Show();
				textBox_password->Clear();
			}
			else {
				User_GUI2 ^ userForm = gcnew User_GUI2(this);
				this->Hide();
				userForm->Show();
				textBox_password->Clear();

			}
		}
}

	private: bool dragging;
	private: Point offset;
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->dragging = false;
		FileHandler txt;
		txt.ReadUser("user.txt");
		txt.ReadEquipment("camp_equipment.txt");
		txt.CurrentStatusChecking();
		txt.WriteEquipment();
	}

	private: System::Void button_login_Click(System::Object^  sender, System::EventArgs^  e) {
		String ^ loginId = textBox_userId->Text;
		String ^ password = textBox_password->Text;
		loginSystem(loginId, password);
	}

	private: System::Void button_exit_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}

	private: System::Void MyForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->dragging = true;
		this->offset = Point(e->X, e->Y);
	}

	private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (this->dragging) {
			Point currentScreenPos = PointToScreen(e->Location);
			Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
		}
	}

	private: System::Void MyForm_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->dragging = false;
	}

};
}
