#pragma once

#include <string>
#include "Entrevue.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace std;

class Etiquette {
public:
    string nom;
    string commentaire;
    //vector<Entrevue*> ListeEntrevuesDeEtiquette;
    //
public:
    Etiquette() = default;
    Etiquette(string tnom) : nom(tnom) {};
    Etiquette(string tnom, string tcommentaire) : nom(tnom), commentaire(tcommentaire) {};
    ~Etiquette() = default;
    
    string obtenirNom() {
        return nom;
    }
    //string ObtNom() { return nom; }
    //
    //void AjouterEntrevue(Entrevue *entrevue) {
    //    ListeEntrevuesDeEtiquette.push_back(entrevue);
    //}
};

public ref class Objet : Object {
public:
    Etiquette* etq;

    Objet(Etiquette* e) : etq(e) {};
    // ~Objet() = default;
};

