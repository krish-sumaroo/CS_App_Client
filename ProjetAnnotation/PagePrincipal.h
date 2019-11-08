#pragma once


#include <string>

#include "PageConnexion.h"
#include "Fonctions.h"
#include "Entrevue.h"
#include "Etiquette.h"


namespace ProjetAnnotation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de PagePrincipal
	/// </summary>
	public ref class PagePrincipal : public System::Windows::Forms::Form
	{
    private:
        string* id ;
    private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
    private: System::Windows::Forms::MenuStrip^ menuStrip1;
    private: System::Windows::Forms::SplitContainer^ splitContainer1;
    private: System::Windows::Forms::TreeView^ ArbreListeEntrevues;


    private: System::Windows::Forms::SplitContainer^ splitContainer2;
    private: System::Windows::Forms::ListView^ ListeUnitesHermeneutiques;



    private:
        vector<Entrevue> *ListeEntrevues   = new vector<Entrevue>(0);
        vector<Etiquette> *ListeEtiquettes = new vector<Etiquette>(0);
        Entrevue* EntrevueSelectionnee;

        string* mdp;
        bool isDragging = false;
        int oldX;
        int oldY;
        int top;
        int left;
        int my_x_cord;
        int my_y_cord;
        int indexOfItemUnderMouseToDrag;
        int indexOfItemUnderMouseToDrop;
        ListViewItem^ ItemUnderMouseToDrop;
        System::Drawing::Rectangle dragBoxFromMouseDown;
        System::Drawing::Point screenOffset;
        System::Windows::Forms::Cursor^ MyNoDropCursor;
    private: System::Windows::Forms::SplitContainer^ splitContainer3;
    private: System::Windows::Forms::ListView^ ListeAnnotations;
    private: System::Windows::Forms::RichTextBox^ AfficheurEntrevue;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
           System::Windows::Forms::Cursor^ MyNormalCursor;


	public:
		PagePrincipal(string* t_id, string* t_mdp)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
            id  = t_id ;
            mdp = t_mdp;

            std::cout << "Allo" << std::endl;

            InitialiserLesDonnees();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~PagePrincipal()
		{
			if (components)
			{
				delete components;
			}
		}

    protected:


        void InitialiserLesDonnees() {
            ObtenirListEtiquettes(ListeEtiquettes);
            ObtenirListeEntrevues(ListeEntrevues );

            MettreAJourListeEtiquettes();
            MettreAJourListeEntrevues();
        }

        void MettreAJourListeEtiquettes() {
            ListeUnitesHermeneutiques->Clear();

            //for (auto uh : ListeEtiquettes) {
            for (int i = 0; i < ListeEtiquettes->size(); ++i) {
                //string temp = ListeEtiquettes->at(i).obtenirNom().c_str();

                //String^ nom = gcnew String(uh.obtenirNom().c_str());

                
                String^ nom = gcnew String(ListeEtiquettes->at(i).obtenirNom().c_str());
                ListViewItem^ listViewItem1 = (gcnew ListViewItem(nom));
                
                Etiquette* allo = &ListeEtiquettes->at(i);
                Objet<Etiquette> ^obj = gcnew Objet<Etiquette>(allo);

                String^ tooltiptexte = gcnew String(obj->obj->commentaire.c_str());

                listViewItem1->Tag = obj;
                listViewItem1->ToolTipText = tooltiptexte;

                ListeUnitesHermeneutiques->Items->Add(listViewItem1);

                // this->ListeUnitesHermeneutiques->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(4) {
                // listViewItem2,
                //     listViewItem3, listViewItem4, listViewItem5
                // });
            }
        }

        void MettreAJourListeEntrevues() {
            ArbreListeEntrevues->Nodes->Clear();

            TreeNode^ treeNodeRacine = (gcnew System::Windows::Forms::TreeNode(L"Liste d\'entrevues"));

            for (int i = 0; i < ListeEntrevues->size(); ++i) {
                String^ titre = gcnew String(ListeEntrevues->at(i).ObtenirTitre().c_str());
                
                TreeNode^ treeNode = (gcnew TreeNode(titre));

                Entrevue* allo = &ListeEntrevues->at(i);
                Objet<Entrevue>^ obj = gcnew Objet<Entrevue>(allo);

                treeNode->Tag = obj;

                treeNodeRacine->Nodes->Add(treeNode);

                //cout << "Voici titre à ajouter" << ListeEntrevues->at(i).ObtenirTitre() << endl;
            }

            ArbreListeEntrevues->Nodes->Add(treeNodeRacine);
            ArbreListeEntrevues->ExpandAll();
        }



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
            System::Windows::Forms::TreeNode^ treeNode1 = (gcnew System::Windows::Forms::TreeNode(L"Les bélugas"));
            System::Windows::Forms::TreeNode^ treeNode2 = (gcnew System::Windows::Forms::TreeNode(L"Requin"));
            System::Windows::Forms::TreeNode^ treeNode3 = (gcnew System::Windows::Forms::TreeNode(L"Liste d\'entrevues", gcnew cli::array< System::Windows::Forms::TreeNode^  >(2) {
                treeNode1,
                    treeNode2
            }));
            System::Windows::Forms::ListViewItem^ listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(L"Nihao"));
            System::Windows::Forms::ListViewGroup^ listViewGroup1 = (gcnew System::Windows::Forms::ListViewGroup(L"Hola", System::Windows::Forms::HorizontalAlignment::Left));
            System::Windows::Forms::ListViewItem^ listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"allo" },
                -1, System::Drawing::Color::Empty, System::Drawing::SystemColors::Window, nullptr));
            System::Windows::Forms::ListViewItem^ listViewItem3 = (gcnew System::Windows::Forms::ListViewItem(L"Hej"));
            System::Windows::Forms::ListViewItem^ listViewItem4 = (gcnew System::Windows::Forms::ListViewItem(L"Bonan"));
            System::Windows::Forms::ListViewItem^ listViewItem5 = (gcnew System::Windows::Forms::ListViewItem(L"Konnichiwa"));
            this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
            this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
            this->ArbreListeEntrevues = (gcnew System::Windows::Forms::TreeView());
            this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
            this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
            this->AfficheurEntrevue = (gcnew System::Windows::Forms::RichTextBox());
            this->ListeAnnotations = (gcnew System::Windows::Forms::ListView());
            this->ListeUnitesHermeneutiques = (gcnew System::Windows::Forms::ListView());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->menuStrip1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
            this->splitContainer1->Panel1->SuspendLayout();
            this->splitContainer1->Panel2->SuspendLayout();
            this->splitContainer1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
            this->splitContainer2->Panel1->SuspendLayout();
            this->splitContainer2->Panel2->SuspendLayout();
            this->splitContainer2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->BeginInit();
            this->splitContainer3->Panel1->SuspendLayout();
            this->splitContainer3->Panel2->SuspendLayout();
            this->splitContainer3->SuspendLayout();
            this->SuspendLayout();
            // 
            // toolStripMenuItem1
            // 
            this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
            this->toolStripMenuItem1->Size = System::Drawing::Size(54, 20);
            this->toolStripMenuItem1->Text = L"Fichier";
            this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &PagePrincipal::ToolStripMenuItem1_Click);
            // 
            // menuStrip1
            // 
            this->menuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
            this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripMenuItem1 });
            this->menuStrip1->Location = System::Drawing::Point(0, 0);
            this->menuStrip1->Name = L"menuStrip1";
            this->menuStrip1->Size = System::Drawing::Size(918, 24);
            this->menuStrip1->TabIndex = 0;
            this->menuStrip1->Text = L"menuStrip1";
            // 
            // splitContainer1
            // 
            this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->splitContainer1->Location = System::Drawing::Point(0, 24);
            this->splitContainer1->Name = L"splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this->splitContainer1->Panel1->Controls->Add(this->ArbreListeEntrevues);
            // 
            // splitContainer1.Panel2
            // 
            this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
            this->splitContainer1->Size = System::Drawing::Size(918, 487);
            this->splitContainer1->SplitterDistance = 251;
            this->splitContainer1->TabIndex = 1;
            // 
            // ArbreListeEntrevues
            // 
            this->ArbreListeEntrevues->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ArbreListeEntrevues->Location = System::Drawing::Point(0, 0);
            this->ArbreListeEntrevues->Name = L"ArbreListeEntrevues";
            treeNode1->Name = L"entrevue1";
            treeNode1->Text = L"Les bélugas";
            treeNode2->Name = L"Requin";
            treeNode2->Text = L"Requin";
            treeNode3->Name = L"ListeEntrevueRacine";
            treeNode3->Text = L"Liste d\'entrevues";
            this->ArbreListeEntrevues->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode3 });
            this->ArbreListeEntrevues->Size = System::Drawing::Size(251, 487);
            this->ArbreListeEntrevues->TabIndex = 0;
            this->ArbreListeEntrevues->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &PagePrincipal::ArbreListeEntrevues_AfterSelect);
            // 
            // splitContainer2
            // 
            this->splitContainer2->AllowDrop = true;
            this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->splitContainer2->Location = System::Drawing::Point(0, 0);
            this->splitContainer2->Name = L"splitContainer2";
            // 
            // splitContainer2.Panel1
            // 
            this->splitContainer2->Panel1->Controls->Add(this->splitContainer3);
            // 
            // splitContainer2.Panel2
            // 
            this->splitContainer2->Panel2->Controls->Add(this->ListeUnitesHermeneutiques);
            this->splitContainer2->Size = System::Drawing::Size(663, 487);
            this->splitContainer2->SplitterDistance = 428;
            this->splitContainer2->TabIndex = 0;
            // 
            // splitContainer3
            // 
            this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->splitContainer3->Location = System::Drawing::Point(0, 0);
            this->splitContainer3->Name = L"splitContainer3";
            // 
            // splitContainer3.Panel1
            // 
            this->splitContainer3->Panel1->Controls->Add(this->AfficheurEntrevue);
            // 
            // splitContainer3.Panel2
            // 
            this->splitContainer3->Panel2->Controls->Add(this->ListeAnnotations);
            this->splitContainer3->Size = System::Drawing::Size(428, 487);
            this->splitContainer3->SplitterDistance = 249;
            this->splitContainer3->TabIndex = 0;
            // 
            // AfficheurEntrevue
            // 
            this->AfficheurEntrevue->Dock = System::Windows::Forms::DockStyle::Fill;
            this->AfficheurEntrevue->Location = System::Drawing::Point(0, 0);
            this->AfficheurEntrevue->Name = L"AfficheurEntrevue";
            this->AfficheurEntrevue->Size = System::Drawing::Size(249, 487);
            this->AfficheurEntrevue->TabIndex = 0;
            this->AfficheurEntrevue->Text = L"";
            // 
            // ListeAnnotations
            // 
            this->ListeAnnotations->AllowColumnReorder = true;
            this->ListeAnnotations->AllowDrop = true;
            this->ListeAnnotations->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ListeAnnotations->HideSelection = false;
            this->ListeAnnotations->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(1) { listViewItem1 });
            this->ListeAnnotations->Location = System::Drawing::Point(0, 0);
            this->ListeAnnotations->Name = L"ListeAnnotations";
            this->ListeAnnotations->ShowItemToolTips = true;
            this->ListeAnnotations->Size = System::Drawing::Size(175, 487);
            this->ListeAnnotations->TabIndex = 0;
            this->ListeAnnotations->UseCompatibleStateImageBehavior = false;
            this->ListeAnnotations->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &PagePrincipal::ListeAnnotations_DragDrop);
            this->ListeAnnotations->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &PagePrincipal::ListeAnnotations_DragEnter);
            this->ListeAnnotations->DragOver += gcnew System::Windows::Forms::DragEventHandler(this, &PagePrincipal::ListeAnnotations_DragOver);
            this->ListeAnnotations->DragLeave += gcnew System::EventHandler(this, &PagePrincipal::ListeAnnotations_DragLeave);
            this->ListeAnnotations->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &PagePrincipal::ListeAnnotations_MouseClick);
            // 
            // ListeUnitesHermeneutiques
            // 
            this->ListeUnitesHermeneutiques->Dock = System::Windows::Forms::DockStyle::Fill;
            listViewGroup1->Header = L"Hola";
            listViewGroup1->Name = L"Hola";
            this->ListeUnitesHermeneutiques->Groups->AddRange(gcnew cli::array< System::Windows::Forms::ListViewGroup^  >(1) { listViewGroup1 });
            this->ListeUnitesHermeneutiques->HideSelection = false;
            listViewItem2->Group = listViewGroup1;
            listViewItem5->Group = listViewGroup1;
            this->ListeUnitesHermeneutiques->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(4) {
                listViewItem2,
                    listViewItem3, listViewItem4, listViewItem5
            });
            this->ListeUnitesHermeneutiques->Location = System::Drawing::Point(0, 0);
            this->ListeUnitesHermeneutiques->Name = L"ListeUnitesHermeneutiques";
            this->ListeUnitesHermeneutiques->ShowItemToolTips = true;
            this->ListeUnitesHermeneutiques->Size = System::Drawing::Size(231, 487);
            this->ListeUnitesHermeneutiques->TabIndex = 0;
            this->ListeUnitesHermeneutiques->UseCompatibleStateImageBehavior = false;
            this->ListeUnitesHermeneutiques->GiveFeedback += gcnew System::Windows::Forms::GiveFeedbackEventHandler(this, &PagePrincipal::ListeUnitesHermeneutiques_GiveFeedback);
            this->ListeUnitesHermeneutiques->QueryContinueDrag += gcnew System::Windows::Forms::QueryContinueDragEventHandler(this, &PagePrincipal::ListeUnitesHermeneutiques_QueryContinueDrag);
            this->ListeUnitesHermeneutiques->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &PagePrincipal::ListeUnitesHermeneutiques_MouseDoubleClick);
            this->ListeUnitesHermeneutiques->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &PagePrincipal::ListeUnitesHermeneutiques_MouseDown);
            this->ListeUnitesHermeneutiques->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &PagePrincipal::ListeUnitesHermeneutiques_MouseMove);
            this->ListeUnitesHermeneutiques->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &PagePrincipal::ListeUnitesHermeneutiques_MouseUp);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(567, 8);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(63, 13);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Annotations";
            this->label1->Click += gcnew System::EventHandler(this, &PagePrincipal::Label1_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(747, 8);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(110, 13);
            this->label2->TabIndex = 3;
            this->label2->Text = L"Unités herméneutique";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(344, 8);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(55, 13);
            this->label3->TabIndex = 4;
            this->label3->Text = L"Entrevues";
            // 
            // PagePrincipal
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(918, 511);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->splitContainer1);
            this->Controls->Add(this->menuStrip1);
            this->MainMenuStrip = this->menuStrip1;
            this->Name = L"PagePrincipal";
            this->Text = L"Annotateur 3000";
            this->menuStrip1->ResumeLayout(false);
            this->menuStrip1->PerformLayout();
            this->splitContainer1->Panel1->ResumeLayout(false);
            this->splitContainer1->Panel2->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
            this->splitContainer1->ResumeLayout(false);
            this->splitContainer2->Panel1->ResumeLayout(false);
            this->splitContainer2->Panel2->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
            this->splitContainer2->ResumeLayout(false);
            this->splitContainer3->Panel1->ResumeLayout(false);
            this->splitContainer3->Panel2->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->EndInit();
            this->splitContainer3->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void TreeView1_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
    }
private: System::Void ListView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TreeView1_AfterSelect_1(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
}
private: System::Void TreeView1_MettreAJour() {
    
}
private: System::Void DataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void TableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void SplitContainer1_Panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void ListeUnitesHermeneutiques_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    ListViewItem ^item1 = ListeUnitesHermeneutiques->GetItemAt(e->X, e->Y);
    
    isDragging = true;

    //cout << "Dans MouseDown" << endl;

    if (item1 != nullptr) {
        indexOfItemUnderMouseToDrag = item1->Index;

        //cout << "Object trouve: " << StringGererAStd(item1->Text) << " : a index: " << indexOfItemUnderMouseToDrag << endl;

        if (indexOfItemUnderMouseToDrag != ListBox::NoMatches) {
            System::Drawing::Size dragSize = SystemInformation::DragSize;

            dragBoxFromMouseDown = System::Drawing::Rectangle(Point(e->X - (dragSize.Width / 2), e->Y - (dragSize.Height / 2)), dragSize);
        }
        else {
            dragBoxFromMouseDown = System::Drawing::Rectangle::Empty;
        }
    }
}
private: System::Void ListeUnitesHermeneutiques_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    dragBoxFromMouseDown = System::Drawing::Rectangle::Empty;
    isDragging = false;

    //cout << "Dans MouseUp" << endl;
}
private: System::Void ListeUnitesHermeneutiques_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    //cout << "Souris bouge" << endl;

    //cout << "Dans MouseMove" << endl;

    if ((e->Button & System::Windows::Forms::MouseButtons::Left) == System::Windows::Forms::MouseButtons::Left) {
        //cout << "Bouton OK" << endl;

        if (dragBoxFromMouseDown != System::Drawing::Rectangle::Empty && !dragBoxFromMouseDown.Contains(e->X, e->Y)) {
            //cout << "Area OK" << endl;

            screenOffset = SystemInformation::WorkingArea.Location;

            auto test1 = ListeUnitesHermeneutiques->Items[indexOfItemUnderMouseToDrag];

            DragDropEffects dropEffect = ListeUnitesHermeneutiques->DoDragDrop(ListeUnitesHermeneutiques->Items[indexOfItemUnderMouseToDrag], DragDropEffects::Copy);
        }
    }
}
private: System::Void ListeUnitesHermeneutiques_GiveFeedback(System::Object^ sender, System::Windows::Forms::GiveFeedbackEventArgs^ e) {

}
private: System::Void ListeAnnotations_DragOver(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
    
    //cout << "Dans DragOver" << endl;
    
    //if (!e->Data->GetDataPresent(System::String::typeid)) {
    //    e->Effect = DragDropEffects::None;
    //    cout << "Aucun chose à bouger" << endl;
    //    return;
    //}

    if ((e->KeyState & (8+32)) == (8+32) && (e->AllowedEffect & DragDropEffects::Link) == DragDropEffects::Link) {
        e->Effect = DragDropEffects::Link;
    }
    else if ((e->KeyState & 32) == 32 && (e->AllowedEffect & DragDropEffects::Link) == DragDropEffects::Link) {
        e->Effect = DragDropEffects::Link;
    }
    else if ((e->KeyState & 4) == 4 && (e->AllowedEffect & DragDropEffects::Move) == DragDropEffects::Move) {
        e->Effect = DragDropEffects::Move;
    }
    else if ((e->KeyState & 8) == 8 && (e->AllowedEffect & DragDropEffects::Copy) == DragDropEffects::Copy) {
        e->Effect = DragDropEffects::Copy;
    }
    else if ((e->AllowedEffect & DragDropEffects::Copy) == DragDropEffects::Copy) {
        e->Effect = DragDropEffects::Copy;
    }
    else {
        e->Effect = DragDropEffects::None;
    }

    //ListViewItem^ item1 = ListeUnitesHermeneutiques->GetItemAt(e->X, e->Y);

    cout << "Endroit du drop: " << e->X << ", " << e->Y << endl;

    try {
        ItemUnderMouseToDrop = ListeAnnotations->GetItemAt(e->X, e->Y);
        indexOfItemUnderMouseToDrop = ListeAnnotations->GetItemAt(e->X, e->Y)->Index;
    }
    catch (...) {
        indexOfItemUnderMouseToDrop = 0;
    }
    

    //if (indexOfItemUnderMouseToDrag != ListBox::NoMatches) {
    //    cout << "Mettre l'item au point #" << (indexOfItemUnderMouseToDrop + 1) << endl;
    //}
    //else {
    //    cout << "Mettre à la fin" << endl;
    //}


    // //if (indexOfItemUnderMouseToDrop != ListBox::NoMatches) {
    // if (item1 == nullptr) {
    //     cout << "Mettre l'item au point #" << (indexOfItemUnderMouseToDrop + 1) << endl;
    //     indexOfItemUnderMouseToDrop = 0;
    // }
    // else {
    //     cout << "Mettre à la fin" << endl;
    //     indexOfItemUnderMouseToDrop = ListeAnnotations->GetItemAt(e->X, e->Y)->Index;
    // }
}
private: System::Void ListeAnnotations_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
    //cout << "Dans DragDrop" << endl;
    
    System::Drawing::Point^ listviewPoint = ListeAnnotations->PointToClient(System::Windows::Forms::Cursor::Position);

    //if (e->Data->GetDataPresent(System::String::typeid)) {
    ListViewItem^ itemSource   = dynamic_cast<ListViewItem^>(e->Data->GetData(ListViewItem::typeid));
    ListViewItem^ itemEntrevue = (gcnew ListViewItem(itemSource->Text));

    itemEntrevue->Tag = itemSource->Tag;

    ListViewItem^ itemDest;

    itemDest = ListeAnnotations->FindNearestItem(SearchDirectionHint::Left, listviewPoint->X, listviewPoint->Y);
    ListViewItem^ itemDest5 = ListeAnnotations->GetItemAt(listviewPoint->X, listviewPoint->Y);

    if (itemDest == nullptr) {
        itemDest = ListeAnnotations->FindNearestItem(SearchDirectionHint::Right, listviewPoint->X, listviewPoint->Y);
    }
    if (itemDest == nullptr) {
        itemDest = ListeAnnotations->FindNearestItem(SearchDirectionHint::Down, listviewPoint->X, listviewPoint->Y);
    }
    if (itemDest == nullptr) {
        itemDest = ListeAnnotations->FindNearestItem(SearchDirectionHint::Up, listviewPoint->X, listviewPoint->Y);
    }
    if (itemDest == nullptr) {
        return;
    }

    //System::Windows::Forms::Cursor::Position = Point(0, 0);

    if (e->Effect == DragDropEffects::Copy ||
        e->Effect == DragDropEffects::Move) {

        // Mettre le même groupe
        itemEntrevue->Group = itemDest->Group;

        // Regarder s'il existe déjà dans ce groupe
        for (int i = 0; i < ListeAnnotations->Items->Count; ++i) {
            if ((ListeAnnotations->Items[i]->Text == itemEntrevue->Text) && (ListeAnnotations->Items[i]->Group == itemEntrevue->Group)) {
                cout << "Existe déjà" << endl;
                return;
            }
        }

        // Ajouter l'étiquette au bon paragraphe de l'entrevue
        Objet<Etiquette>^ obj = dynamic_cast<Objet<Etiquette>^>(itemEntrevue->Tag);
        Etiquette* etiquette = obj->obj;

        String^ nomGroupe = itemEntrevue->Group->Name;

        for (int i = 0; i < EntrevueSelectionnee->ListeParagraphes.size(); ++i) {
            string tempNomGroup = "P " + to_string(i);
            string tempNomPara = EntrevueSelectionnee->ListeParagraphes[i].ObtenirNom();

            // Si le bon paragraphe
            if (tempNomGroup == tempNomPara) {
                EntrevueSelectionnee->ListeParagraphes[i].ListeEtiquettes.push_back(etiquette);
            }
        }
        //EntrevueSelectionnee


        ListeAnnotations->Items->Insert(0, itemEntrevue);
        //ListeAnnotations->Items->Insert(indexOfItemUnderMouseToDrop, item2);

        // // Ajouter l'item
        // if (indexOfItemUnderMouseToDrop != ListBox::NoMatches) {
        //     ListeAnnotations->Items->Insert(indexOfItemUnderMouseToDrop, item2);
        // }
        // else {
        //     ListeAnnotations->Items->Add(item);
        // }
    }
    //}
    //cout << "Drop fait" << endl;
}
private: System::Void ListeUnitesHermeneutiques_QueryContinueDrag(System::Object^ sender, System::Windows::Forms::QueryContinueDragEventArgs^ e) {
    //cout << "Dans QueryContinueDrag" << endl;
    
    System::Windows::Forms::ListBox^ lb = dynamic_cast<System::Windows::Forms::ListBox^>(sender);

    if (lb != nullptr) {
        Form^ f = lb->FindForm();

        if (   ((Control::MousePosition.X - screenOffset.X) < f->DesktopBounds.Left)
            || ((Control::MousePosition.X - screenOffset.X) > f->DesktopBounds.Right)
            || ((Control::MousePosition.Y - screenOffset.Y) < f->DesktopBounds.Top)
            || ((Control::MousePosition.Y - screenOffset.Y) > f->DesktopBounds.Bottom)) {

            e->Action = DragAction::Cancel;
        }
    }
}
private: System::Void ListeAnnotations_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
    //cout << "Dans DragEnter" << endl;
}
private: System::Void ListeAnnotations_DragLeave(System::Object^ sender, System::EventArgs^ e) {
    //cout << "Dans DragLeave" << endl;
}
private: System::Void ListeUnitesHermeneutiques_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    ListViewItem^ item1 = ListeUnitesHermeneutiques->GetItemAt(e->X, e->Y);

    Objet<Etiquette>^ hola = dynamic_cast<Objet<Etiquette>^>(item1->Tag);
    
    Etiquette* hej = hola->obj;

    MessageBoxButtons buttons = MessageBoxButtons::YesNo;
    System::Windows::Forms::DialogResult resultat;

    String^ commentaire = gcnew String(hej->commentaire.c_str());

    resultat = MessageBox::Show(this, commentaire, "Commentaires", buttons);

}
private: System::Void Label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ArbreListeEntrevues_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
    
    if (e->Node->Level != 0) {
        Objet<Entrevue>^ hola = dynamic_cast<Objet<Entrevue>^>(e->Node->Tag);

        Entrevue* hej = hola->obj;

        // Variable global pour l'entrevue sélectionnée
        EntrevueSelectionnee = hej;

        AfficheurEntrevue->Clear();
        ListeAnnotations->Clear();

        String^ Texte = "";

        for (int i = 0; i < hej->ListeParagraphes.size(); ++i) {
            Texte += gcnew String(hej->ListeParagraphes[i].texte.c_str());
            Texte += "\n\n";

            //ListeAnnotations
            string   nomPar    = "Paragraphe " + to_string(i+1);
            String ^ nomParCli = gcnew String(nomPar.c_str());

            ListViewGroup^ listViewGroup1 = (gcnew ListViewGroup(nomParCli, HorizontalAlignment::Left));
            

            listViewGroup1->Header = nomParCli;
            listViewGroup1->Name   = nomParCli;

            // Ajouter un item vide pour afficher le groupe
            //string   nomMettre = "Mettre dans " + to_string(i + 1);
            //String^ nomMettreCli = gcnew String(nomMettre.c_str());
            //ListViewItem^ listViewItemVide = (gcnew ListViewItem(nomMettreCli));
            ListViewItem^ listViewItemVide = (gcnew ListViewItem(""));
            listViewItemVide->Group = listViewGroup1;
            ListeAnnotations->Items->Add(listViewItemVide);

            // Ajouter étiquettes
            vector<Etiquette*> ListeEtiquettes = hej->ListeParagraphes[i].ListeEtiquettes;

            for (int i_e = 0; i_e < ListeEtiquettes.size(); ++i_e) {


                // Etiquette* allo = &ListeEtiquettes->at(i);
                // Objet<Etiquette>^ obj = gcnew Objet<Etiquette>(allo);
                // 
                // String^ tooltiptexte = gcnew String(obj->obj->commentaire.c_str());
                // 
                // listViewItem1->Tag = obj;
                // listViewItem1->ToolTipText = tooltiptexte;
                // 
                // ListeUnitesHermeneutiques->Items->Add(listViewItem1);

                String^ nomEtqCli = gcnew String(ListeEtiquettes[i_e]->nom.c_str());

                ListViewItem^ listViewItem5 = (gcnew ListViewItem(nomEtqCli));

                Etiquette* allo = ListeEtiquettes[i_e];
                Objet<Etiquette>^ obj = gcnew Objet<Etiquette>(allo);

                String^ tooltiptexte = gcnew String(obj->obj->commentaire.c_str());

                listViewItem5->Tag = obj;
                listViewItem5->Group = listViewGroup1;
                listViewItem5->ToolTipText = tooltiptexte;

                ListeAnnotations->Items->Insert(0, listViewItem5);
            }
            
            // Ajouter un élément vide pour afficher le groupe
            // ListViewItem^ listViewItem = (gcnew ListViewItem("Allo"));
            // listViewItem->Group = listViewGroup1;
            // ListeAnnotations->Items->Add(listViewItem);

            ListeAnnotations->Groups->Add(listViewGroup1);

            //ListeAnnotations->Items->Add();

            // System::Windows::Forms::ListViewItem^ listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"allo" },
            //     -1, System::Drawing::Color::Empty, System::Drawing::SystemColors::Window, nullptr));
            // System::Windows::Forms::ListViewItem^ listViewItem3 = (gcnew System::Windows::Forms::ListViewItem(L"Hej"));
            // System::Windows::Forms::ListViewItem^ listViewItem4 = (gcnew System::Windows::Forms::ListViewItem(L"Bonan"));
            // System::Windows::Forms::ListViewItem^ listViewItem5 = (gcnew System::Windows::Forms::ListViewItem(L"Konnichiwa"));
            // 
            // listViewGroup1->Header = L"Hola";
            // listViewGroup1->Name = L"Hola";
            // this->ListeUnitesHermeneutiques->Groups->AddRange(gcnew cli::array< System::Windows::Forms::ListViewGroup^  >(1) { listViewGroup1 });
            // this->ListeUnitesHermeneutiques->HideSelection = false;
            // listViewItem2->Group = listViewGroup1;
            // listViewItem5->Group = listViewGroup1;
            // this->ListeUnitesHermeneutiques->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(4) {
            //     listViewItem2,
            //         listViewItem3, listViewItem4, listViewItem5
            // });
            // 
            // 
            // System::Windows::Forms::ListViewGroup^ listViewGroup1 = (gcnew System::Windows::Forms::ListViewGroup(L"Hola", System::Windows::Forms::HorizontalAlignment::Left));
            // System::Windows::Forms::ListViewItem^ listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"allo" },
            //     -1, System::Drawing::Color::Empty, System::Drawing::SystemColors::Window, nullptr));
            // System::Windows::Forms::ListViewItem^ listViewItem3 = (gcnew System::Windows::Forms::ListViewItem(L"Hej"));
            // System::Windows::Forms::ListViewItem^ listViewItem4 = (gcnew System::Windows::Forms::ListViewItem(L"Bonan"));
            // System::Windows::Forms::ListViewItem^ listViewItem5 = (gcnew System::Windows::Forms::ListViewItem(L"Konnichiwa"));
            // 
            // listViewGroup1->Header = L"Hola";
            // listViewGroup1->Name = L"Hola";
            // this->ListeUnitesHermeneutiques->Groups->AddRange(gcnew cli::array< System::Windows::Forms::ListViewGroup^  >(1) { listViewGroup1 });
            // this->ListeUnitesHermeneutiques->HideSelection = false;
            // listViewItem2->Group = listViewGroup1;
            // listViewItem5->Group = listViewGroup1;
            // this->ListeUnitesHermeneutiques->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(4) {
            //     listViewItem2,
            //         listViewItem3, listViewItem4, listViewItem5
            // });

        }

        ListeAnnotations->ShowGroups = true;
        

        AfficheurEntrevue->Text = Texte;
    }


}
private: System::Void ListeAnnotations_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    ListViewItem^ itemDest5 = ListeAnnotations->GetItemAt(e->X, e->Y);

    return;
}
};
}
