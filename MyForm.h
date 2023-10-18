#pragma once

#define CURL_STATICLIB
#include <iostream>
#include <curl/curl.h>
#include <string>

namespace ConverterApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	static size_t getResponseToString(void* contents, size_t size, size_t nmemb, void* userp)
	{
		((std::string*)userp)->append((char*)contents, size * nmemb);
		return size * nmemb;
	}
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
	private: System::Windows::Forms::Button^ RefreshButton;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		double Currency = 100;
		double Rubles = 0;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label6;
		   double Dollars = 0;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->RefreshButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// RefreshButton
			// 
			this->RefreshButton->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->RefreshButton->Location = System::Drawing::Point(426, 137);
			this->RefreshButton->Name = L"RefreshButton";
			this->RefreshButton->Size = System::Drawing::Size(166, 77);
			this->RefreshButton->TabIndex = 0;
			this->RefreshButton->Text = L"Refresh";
			this->RefreshButton->UseVisualStyleBackColor = false;
			this->RefreshButton->Click += gcnew System::EventHandler(this, &MyForm::RefreshButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Moonbeam", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 18);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Currency converter";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(45, 62);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(202, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(338, 62);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(183, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(272, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Rubles is";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(547, 68);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Dollars";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Moonbeam", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(194, 13);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(141, 18);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Rubles for 1 dollar: ";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(45, 101);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(202, 20);
			this->textBox3->TabIndex = 7;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(272, 108);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Dollars is";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(338, 101);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(183, 20);
			this->textBox4->TabIndex = 9;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(547, 108);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(40, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Rubles";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(604, 226);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->RefreshButton);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void RefreshButton_Click(System::Object^ sender, System::EventArgs^ e) {

	CURL* curl;
	CURLcode response;
	std::string str_response;
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, "https://www.cbr.ru/eng/currency_base/daily/");
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponseToString);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str_response);
	response = curl_easy_perform(curl);
	curl_easy_cleanup(curl);

	std::size_t found = str_response.find("<td>US Dollar</td>");

	std::string str2 = str_response.substr(found + 34, 7);

	Currency = stod(str2);

	Currency *= 10;
	Currency = round(Currency);
	Currency /= 10;

	this->label4->Text = L"Rubles for 1 dollar: " + Currency;
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if (this->textBox1->Text && this->textBox1->Text != "" ) { Rubles = Convert::ToDouble(this->textBox1->Text); }

	Rubles *= 100;
	Rubles = round(Rubles);
	Rubles /= 100;

	double temp2 = Rubles / Currency;

	temp2 *= 100;
	temp2 = round(temp2);
	temp2 /= 100;

	this->textBox2->Text = temp2.ToString();

}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if (this->textBox3->Text && this->textBox3->Text != "") { Dollars = Convert::ToDouble(this->textBox3->Text); }

	Dollars *= 100;
	Dollars = round(Dollars);
	Dollars /= 100;

	double temp2 = Dollars * Currency;

	temp2 *= 100;
	temp2 = round(temp2);
	temp2 /= 100;

	this->textBox4->Text = temp2.ToString();

}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
