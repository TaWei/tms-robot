#pragma once
#include <vector>
#include <msclr/marshal_cppstd.h>

namespace RobotGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	typedef std::vector<double> double_vec_t;
	typedef std::vector<std::string> string_vec_t;
	double_vec_t xCoordList;
	double_vec_t yCoordList;
	double_vec_t zCoordList;
	string_vec_t stringCoordList;
	/// <summary>
	/// Summary for inputGUI
	// Takes as input 3D coordinates and passes the list to the robot.
	/// </summary>
	public ref class inputGUI : public System::Windows::Forms::Form
	{
	public:
		inputGUI(void)
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
		~inputGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  xText;
	private: System::Windows::Forms::TextBox^  yText;
	private: System::Windows::Forms::TextBox^  zText;
	private: System::Windows::Forms::Panel^  coordsPanel;
	protected:

	protected:



	private: System::Windows::Forms::Button^  addCoordsButton;

	private: System::Windows::Forms::Label^  coordsLabel;
	private: System::Windows::Forms::Label^  YLabel;
	private: System::Windows::Forms::Label^  ZLabel;
	private: System::Windows::Forms::Label^  XLabel;
	private: System::Windows::Forms::ListBox^  coordsList;
	private: System::Windows::Forms::VScrollBar^  coordsScrollBar;
	private: System::Windows::Forms::Button^  execButton;
	private: System::Windows::Forms::Label^  coordsListLabel;


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
			this->xText = (gcnew System::Windows::Forms::TextBox());
			this->yText = (gcnew System::Windows::Forms::TextBox());
			this->zText = (gcnew System::Windows::Forms::TextBox());
			this->coordsPanel = (gcnew System::Windows::Forms::Panel());
			this->addCoordsButton = (gcnew System::Windows::Forms::Button());
			this->coordsLabel = (gcnew System::Windows::Forms::Label());
			this->YLabel = (gcnew System::Windows::Forms::Label());
			this->ZLabel = (gcnew System::Windows::Forms::Label());
			this->XLabel = (gcnew System::Windows::Forms::Label());
			this->coordsList = (gcnew System::Windows::Forms::ListBox());
			this->coordsScrollBar = (gcnew System::Windows::Forms::VScrollBar());
			this->execButton = (gcnew System::Windows::Forms::Button());
			this->coordsListLabel = (gcnew System::Windows::Forms::Label());
			this->coordsPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// xText
			// 
			this->xText->Location = System::Drawing::Point(45, 45);
			this->xText->Name = L"xText";
			this->xText->Size = System::Drawing::Size(305, 22);
			this->xText->TabIndex = 0;
			this->xText->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &inputGUI::xText_KeyPress);
			// 
			// yText
			// 
			this->yText->Location = System::Drawing::Point(45, 73);
			this->yText->Name = L"yText";
			this->yText->Size = System::Drawing::Size(305, 22);
			this->yText->TabIndex = 1;
			this->yText->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &inputGUI::yText_KeyPress);
			// 
			// zText
			// 
			this->zText->Location = System::Drawing::Point(45, 101);
			this->zText->Name = L"zText";
			this->zText->Size = System::Drawing::Size(305, 22);
			this->zText->TabIndex = 2;
			this->zText->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &inputGUI::zText_KeyPress);
			// 
			// coordsPanel
			// 
			this->coordsPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->coordsPanel->Controls->Add(this->addCoordsButton);
			this->coordsPanel->Controls->Add(this->coordsLabel);
			this->coordsPanel->Controls->Add(this->YLabel);
			this->coordsPanel->Controls->Add(this->ZLabel);
			this->coordsPanel->Controls->Add(this->XLabel);
			this->coordsPanel->Controls->Add(this->xText);
			this->coordsPanel->Controls->Add(this->zText);
			this->coordsPanel->Controls->Add(this->yText);
			this->coordsPanel->Location = System::Drawing::Point(12, 12);
			this->coordsPanel->Name = L"coordsPanel";
			this->coordsPanel->Size = System::Drawing::Size(381, 208);
			this->coordsPanel->TabIndex = 3;
			// 
			// addCoordsButton
			// 
			this->addCoordsButton->Location = System::Drawing::Point(45, 140);
			this->addCoordsButton->Name = L"addCoordsButton";
			this->addCoordsButton->Size = System::Drawing::Size(136, 37);
			this->addCoordsButton->TabIndex = 7;
			this->addCoordsButton->Text = L"Add Coordinates";
			this->addCoordsButton->UseVisualStyleBackColor = true;
			this->addCoordsButton->Click += gcnew System::EventHandler(this, &inputGUI::addCoords_Click);
			// 
			// coordsLabel
			// 
			this->coordsLabel->AutoSize = true;
			this->coordsLabel->Cursor = System::Windows::Forms::Cursors::Default;
			this->coordsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->coordsLabel->Location = System::Drawing::Point(42, 12);
			this->coordsLabel->Name = L"coordsLabel";
			this->coordsLabel->Size = System::Drawing::Size(148, 17);
			this->coordsLabel->TabIndex = 6;
			this->coordsLabel->Text = L"Target Coordinates";
			// 
			// YLabel
			// 
			this->YLabel->AutoSize = true;
			this->YLabel->Location = System::Drawing::Point(22, 73);
			this->YLabel->Name = L"YLabel";
			this->YLabel->Size = System::Drawing::Size(17, 17);
			this->YLabel->TabIndex = 5;
			this->YLabel->Text = L"Y";
			// 
			// ZLabel
			// 
			this->ZLabel->AutoSize = true;
			this->ZLabel->Location = System::Drawing::Point(22, 101);
			this->ZLabel->Name = L"ZLabel";
			this->ZLabel->Size = System::Drawing::Size(17, 17);
			this->ZLabel->TabIndex = 4;
			this->ZLabel->Text = L"Z";
			// 
			// XLabel
			// 
			this->XLabel->AutoSize = true;
			this->XLabel->Location = System::Drawing::Point(22, 45);
			this->XLabel->Name = L"XLabel";
			this->XLabel->Size = System::Drawing::Size(17, 17);
			this->XLabel->TabIndex = 3;
			this->XLabel->Text = L"X";
			// 
			// coordsList
			// 
			this->coordsList->FormattingEnabled = true;
			this->coordsList->ItemHeight = 16;
			this->coordsList->Location = System::Drawing::Point(417, 45);
			this->coordsList->Name = L"coordsList";
			this->coordsList->Size = System::Drawing::Size(284, 452);
			this->coordsList->TabIndex = 4;
			// 
			// coordsScrollBar
			// 
			this->coordsScrollBar->Location = System::Drawing::Point(681, 45);
			this->coordsScrollBar->Name = L"coordsScrollBar";
			this->coordsScrollBar->Size = System::Drawing::Size(20, 452);
			this->coordsScrollBar->TabIndex = 5;
			this->coordsScrollBar->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &inputGUI::coordsScrollBar_Scroll);
			// 
			// execButton
			// 
			this->execButton->Location = System::Drawing::Point(12, 386);
			this->execButton->Name = L"execButton";
			this->execButton->Size = System::Drawing::Size(399, 114);
			this->execButton->TabIndex = 6;
			this->execButton->Text = L"Execute";
			this->execButton->UseVisualStyleBackColor = true;
			// 
			// coordsListLabel
			// 
			this->coordsListLabel->AutoSize = true;
			this->coordsListLabel->Location = System::Drawing::Point(417, 12);
			this->coordsListLabel->Name = L"coordsListLabel";
			this->coordsListLabel->Size = System::Drawing::Size(135, 17);
			this->coordsListLabel->TabIndex = 7;
			this->coordsListLabel->Text = L"Current Coordinates";
			// 
			// inputGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(743, 512);
			this->Controls->Add(this->coordsListLabel);
			this->Controls->Add(this->execButton);
			this->Controls->Add(this->coordsScrollBar);
			this->Controls->Add(this->coordsList);
			this->Controls->Add(this->coordsPanel);
			this->Name = L"inputGUI";
			this->Text = L"inputGUI";
			this->Load += gcnew System::EventHandler(this, &inputGUI::inputGUI_Load);
			this->coordsPanel->ResumeLayout(false);
			this->coordsPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	}

	private: System::Void inputGUI_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void xText_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	// Accept only digits and the Backspace character
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08 && e->KeyChar != '.' && e->KeyChar != '-')
	e->Handled = true;
}
private: System::Void yText_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	// Accept only digits and the Backspace character
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08 && e->KeyChar != '.' && e->KeyChar != '-')
		e->Handled = true;
}
private: System::Void zText_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	// Accept only digits and the Backspace character
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08 && e->KeyChar != '.' && e->KeyChar != '-')
		e->Handled = true;
}
private: System::Void addCoords_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ xInput = this->xText->Text;
	String^ yInput = this->yText->Text;
	String^ zInput = this->zText->Text;
	//Convert from String^ to std::string using Microsoft marshal libraries
	std::string x = msclr::interop::marshal_as< std::string >(xInput);
	std::string y = msclr::interop::marshal_as< std::string >(yInput);
	std::string z = msclr::interop::marshal_as< std::string >(zInput);
	if (x.compare("") && y.compare("") && z.compare("")) {
		double doubleX = std::stod(x);
		double doubleY = std::stod(y);
		double doubleZ = std::stod(z);
		xCoordList.push_back(doubleX);
		yCoordList.push_back(doubleY);
		zCoordList.push_back(doubleZ);
		std::string coordstring = x + ", " + y + ", " + z;
		stringCoordList.push_back(coordstring);
		this->coordsList->Items->Add(gcnew String(coordstring.c_str()));
		this->xText->Text = "";
		this->yText->Text = "";
		this->zText->Text = "";
	}
}
private: System::Void coordsScrollBar_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
}
};
}
