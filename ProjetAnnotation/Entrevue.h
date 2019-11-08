#pragma once

#include <vector>
#include <string>
#include "Paragraphe.h"

using namespace std;

class Entrevue {
    string nom;

public:
    vector<Paragraphe> ListeParagraphes;

    Entrevue() = default;
    Entrevue(string tnom) : nom(tnom){}
    ~Entrevue() = default;
    
    void ajouterParagraphe(string nom, string text) {
        ListeParagraphes.push_back(Paragraphe(nom, text));
    }

    void ajouterParagraphe(Paragraphe paragraphe) {
        ListeParagraphes.push_back(paragraphe);
    }

    string ObtenirTitre() { return nom; };
};


// public ref class ObjetEnt : Object {
// public:
//     Entrevue* ent;
// 
//     ObjetEnt(Entrevue* e) : ent(e) {};
//     // ~Objet() = default;
// };



