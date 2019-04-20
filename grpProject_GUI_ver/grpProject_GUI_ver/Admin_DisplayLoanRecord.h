#pragma once

namespace grpProjectGUIver {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Admin_DisplayLoanRecord
	/// </summary>
	public ref class Admin_DisplayLoanRecord : public System::Windows::Forms::Form
	{
	public:
		Admin_DisplayLoanRecord(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	public:
		Admin_DisplayLoanRecord(System::Windows::Forms::Form ^ parentForm)
		{
			InitializeComponent();
			goback = parentForm;
		}
	public: System::Windows::Forms::Form ^ goback;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Admin_DisplayLoanRecord()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_exit;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Admin_DisplayLoanRecord::typeid));
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button_exit
			// 
			this->button_exit->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button_exit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_exit->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button_exit->Font = (gcnew System::Drawing::Font(L"Gadugi", 12, System::Drawing::FontStyle::Bold));
			this->button_exit->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_exit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button_exit->Location = System::Drawing::Point(699, 12);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(89, 30);
			this->button_exit->TabIndex = 23;
			this->button_exit->Text = L"Back";
			this->button_exit->UseVisualStyleBackColor = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &Admin_DisplayLoanRecord::button_exit_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::White;
			this->richTextBox1->Location = System::Drawing::Point(21, 78);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(766, 498);
			this->richTextBox1->TabIndex = 24;
			this->richTextBox1->Text = L"";
			// 
			// Admin_DisplayLoanRecord
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(800, 600);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button_exit);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(800, 600);
			this->MinimumSize = System::Drawing::Size(800, 600);
			this->Name = L"Admin_DisplayLoanRecord";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Admin_DisplayLoanRecord";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Admin_DisplayLoanRecord::Admin_DisplayLoanRecord_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Admin_DisplayLoanRecord::Admin_DisplayLoanRecord_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Admin_DisplayLoanRecord::Admin_DisplayLoanRecord_MouseUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: bool dragging = false;
	private: Point offset;
	private: System::Void button_exit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
		goback->Show();
	}
	private: System::Void Admin_DisplayLoanRecord_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->dragging = true;
		this->offset = Point(e->X, e->Y);
	}
	private: System::Void Admin_DisplayLoanRecord_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->dragging = false;
	}
	private: System::Void Admin_DisplayLoanRecord_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (this->dragging) {
			Point currentScreenPos = PointToScreen(e->Location);
			Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
		}
	}
};
}
