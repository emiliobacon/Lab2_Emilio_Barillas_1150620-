#pragma once
#include <iostream>;
#include <stdlib.h>;


namespace Lab3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	

	int posLiebre = 0, posTortuga = 0;//variable para almacenar la posición de los animales al inicio. 
	int* dirLiebre = &posLiebre;
	int* dirTortuga = &posTortuga; //crea los apuntadores

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
	private: System::Windows::Forms::Label^ lblPista;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lblstatus;
	private: System::Windows::Forms::RichTextBox^ richTextBoxPista;
	private: System::Windows::Forms::Button^ btnstart;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblpremio;
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
			this->lblPista = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblstatus = (gcnew System::Windows::Forms::Label());
			this->richTextBoxPista = (gcnew System::Windows::Forms::RichTextBox());
			this->btnstart = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblpremio = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblPista
			// 
			this->lblPista->AutoSize = true;
			this->lblPista->Location = System::Drawing::Point(30, 24);
			this->lblPista->Name = L"lblPista";
			this->lblPista->Size = System::Drawing::Size(0, 13);
			this->lblPista->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// lblstatus
			// 
			this->lblstatus->AutoSize = true;
			this->lblstatus->Location = System::Drawing::Point(12, 269);
			this->lblstatus->Name = L"lblstatus";
			this->lblstatus->Size = System::Drawing::Size(69, 13);
			this->lblstatus->TabIndex = 1;
			this->lblstatus->Text = L"Resultados...";
			// 
			// richTextBoxPista
			// 
			this->richTextBoxPista->Location = System::Drawing::Point(15, 12);
			this->richTextBoxPista->Name = L"richTextBoxPista";
			this->richTextBoxPista->Size = System::Drawing::Size(597, 238);
			this->richTextBoxPista->TabIndex = 2;
			this->richTextBoxPista->Text = L"";
			// 
			// btnstart
			// 
			this->btnstart->Location = System::Drawing::Point(461, 256);
			this->btnstart->Name = L"btnstart";
			this->btnstart->Size = System::Drawing::Size(151, 38);
			this->btnstart->TabIndex = 3;
			this->btnstart->Text = L"Inicio";
			this->btnstart->UseVisualStyleBackColor = true;
			this->btnstart->Click += gcnew System::EventHandler(this, &MyForm::btnstart_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 290);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(202, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"El cubo de lechuga y zanahorias es para:";
			// 
			// lblpremio
			// 
			this->lblpremio->AutoSize = true;
			this->lblpremio->Location = System::Drawing::Point(217, 292);
			this->lblpremio->Name = L"lblpremio";
			this->lblpremio->Size = System::Drawing::Size(0, 13);
			this->lblpremio->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(626, 312);
			this->Controls->Add(this->lblpremio);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnstart);
			this->Controls->Add(this->richTextBoxPista);
			this->Controls->Add(this->lblstatus);
			this->Controls->Add(this->lblPista);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Carrera";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		array<String^>^ pista = gcnew array<String^>(70); //crea un vector para las posiciones

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
		 
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) { //timer que actualiza los datos cada seundo
		liebre(*dirLiebre);
		tortuga(*dirTortuga);

		turnos(*dirLiebre, *dirTortuga);
		

	}
	
	void liebre(int &dirLiebre) {
		Random^ NumRandom = gcnew Random();
		int movimiento = NumRandom->Next(1, 10);

		if (movimiento >= 1 && movimiento <= 2) { //se duerme
			dirLiebre = dirLiebre;
		}
		else if (movimiento >=3 && movimiento <= 4) { //gran salto
			dirLiebre += 9;
		}
		else if (movimiento == 5) { //gran resbalón
			dirLiebre -= 12;
		}
		else if (movimiento >= 6 && movimiento <= 8) { //salto pequeño
			dirLiebre += 1;
		}
		else {
			dirLiebre -= 2; 
		}

		if (dirLiebre < 0) { //mínima posición
			dirLiebre = 0;
		}

		if (dirLiebre > 69) { //máxima posición
			dirLiebre = 69;
		}
	}

	//hacer método tortuga 

	void tortuga(int &dirTortuga) {
		Random^ NumRandom = gcnew Random();
		int movimiento = NumRandom->Next(1, 10); //genera números random

		if (movimiento >= 1 && movimiento <= 5) {
			dirTortuga += 3; //paso veloz
		}
		else if (movimiento >= 6 && movimiento <= 7) {
			dirTortuga -= 6; //resbalón 
		}
		else {
			dirTortuga += 1; //paso lento 
		}

		if (dirTortuga < 0) { //mínima posición
			dirTortuga = 0;
		}

		if (dirTortuga > 69) { //máxima posición
			dirTortuga = 69;
		}

	}
	

	void turnos(int &posL, int &posT) { //si se encuentran y la muerde 
		

		for (int i = 0; i < 70; i++)
		{
			pista[i] = "";
		}

		if (posL == posT) {
			pista[posL] = "OUCH!";
		}
		else {
			pista[posL] = "H";
			pista[posT] = "T";
		}
		if (posL == 69 && posT == 69) {
			lblstatus->Text = "Es un empate xD";
			timer1->Enabled = false;
		}
		else if (posL == 69) {
			lblstatus->Text = "La liebre gana. Ni hablar";
			lblpremio->Text = "La Liebre.";
			timer1->Enabled = false;
		}
		else if (posT == 69) {
			lblstatus->Text = "¡LA TORTUGA GANA! ¡BRAVO! ";
			lblpremio->Text = "La Tortuga.";
			timer1->Enabled = false;
		}

		String^ linea; //con string no se pone línea 

		for (int i = 0; i < 70; i++)
		{
			if (pista[i] == "") {
				linea += " ";
			}
			else {
				linea += pista[i]; 
			}

		}
		richTextBoxPista->Text += linea + "\n";

	}
	private: System::Void btnstart_Click(System::Object^ sender, System::EventArgs^ e) {
		*dirLiebre = 0; 
		*dirTortuga = 0;
		richTextBoxPista->Text = "";
		richTextBoxPista->Text="¡BANG!"+" \n"+ "¡Y ARRANCAN!"+"\n"; 
		lblstatus->Text = "Resultados...";
		lblpremio->Text = "";
		

		timer1->Enabled = true;

	}
};

}

