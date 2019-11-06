#pragma once

#include <string>
#include <iostream>
#include <msclr/marshal_cppstd.h>

#include "Client.h"
//#include "PagePrincipal.h"

namespace ProjetAnnotation {
    using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de PageConnexion
	/// </summary>
	public ref class PageConnexion : public System::Windows::Forms::Form
	{
	private:
        bool *utilisateurOk;
        string* id;
        string* mdp;

    public:
		PageConnexion(bool *ok, string *t_id, string *t_mdp)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//

            utilisateurOk = ok;
            id  = t_id ;
            mdp = t_mdp;

            //ProjetAnnotation::PagePrincipal pagePrincipal;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~PageConnexion()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::TextBox^ bt_identifiant;
    protected:


    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ bt_mdp;

    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Button^ button1;
    protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
            this->bt_identifiant = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->bt_mdp = (gcnew System::Windows::Forms::TextBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // bt_identifiant
            // 
            this->bt_identifiant->Location = System::Drawing::Point(398, 246);
            this->bt_identifiant->Name = L"bt_identifiant";
            this->bt_identifiant->Size = System::Drawing::Size(154, 20);
            this->bt_identifiant->TabIndex = 0;
            this->bt_identifiant->TextChanged += gcnew System::EventHandler(this, &PageConnexion::TextBox1_TextChanged);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(395, 230);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(53, 13);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Identifiant";
            this->label1->Click += gcnew System::EventHandler(this, &PageConnexion::Label1_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(395, 277);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(71, 13);
            this->label2->TabIndex = 4;
            this->label2->Text = L"Mot de passe";
            // 
            // bt_mdp
            // 
            this->bt_mdp->Location = System::Drawing::Point(398, 293);
            this->bt_mdp->Name = L"bt_mdp";
            this->bt_mdp->PasswordChar = '*';
            this->bt_mdp->Size = System::Drawing::Size(154, 20);
            this->bt_mdp->TabIndex = 3;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Elephant", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(285, 76);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(403, 35);
            this->label3->TabIndex = 5;
            this->label3->Text = L"Annotateur d\'entrevue 3000";
            // 
            // button1
            // 
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->Location = System::Drawing::Point(398, 330);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(154, 42);
            this->button1->TabIndex = 6;
            this->button1->Text = L"Connexion";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &PageConnexion::Button1_Click);
            // 
            // PageConnexion
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(956, 568);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->bt_mdp);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->bt_identifiant);
            this->Name = L"PageConnexion";
            this->Text = L"Page de connexion";
            this->Load += gcnew System::EventHandler(this, &PageConnexion::MyForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void TextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void Label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
        
        bool b_identifiantTrouve;
        
        string s_id  = msclr::interop::marshal_as<std::string>(bt_identifiant->Text);
        string s_mdp = msclr::interop::marshal_as<std::string>(bt_mdp        ->Text);

        // Valider les entrées
        if (s_id == "") {
            cout << "Veuillez entrer un identifiant" << endl;
        }

        if (s_mdp == "") {
            cout << "Veuillez entrer un mot de passe" << endl;
        }

        // Fonction pour confirmer l'identifiant
        *utilisateurOk = ConfirmerIdentifiant(s_id, s_mdp);

        // Si l'utilisateur est valide, on quitte la fenêtre de connexion pour ouvrir la page principale
        if (*utilisateurOk) {
            *id  = s_id ;
            *mdp = s_mdp;
            this->Close();
        }
    }
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
