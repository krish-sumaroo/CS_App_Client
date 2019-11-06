#pragma once

#include <vector>
#include <string>
#include "Paragraphe.h"

using namespace std;

class Entrevue {
    string nom;
    vector<Paragraphe> ListeParagraphes;

public:
    Entrevue(string tnom) : nom(tnom){}
    ~Entrevue() = default;
    
    void ajouterParagraphe(string nom, string text) {
        ListeParagraphes.push_back(Paragraphe(nom, text));
    }

    void ajouterParagraphe(Paragraphe paragraphe) {
        ListeParagraphes.push_back(paragraphe);
    }
};



