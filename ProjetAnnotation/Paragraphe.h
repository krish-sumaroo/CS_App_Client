#pragma once



#include <string>
#include <vector>

#include "Etiquette.h"

using namespace std;

class Paragraphe {
    string nom;
    string texte;
    
    vector<string>     ListeNomEtiquettes;
    vector<Etiquette*> ListeEtiquettes   ;
    
public:
    Paragraphe(string tnom, string ttexte) : nom(tnom), texte(ttexte) {}
    ~Paragraphe() = default;
    
    // void ajouterEtiquette(Etiquette *etq) {
    //     bool esPresent;
    // 
    //     for (auto elem_etq : ListeEtiquettes) {
    //         // Autoriser seulement un élément
    //         if (elem_etq == etq) {
    //             return;
    //         }
    //     }
    // 
    //     ListeEtiquettes.push_back(etq);
    //     
    //     return;
    // }
    // 
    // void enleverEtiquette(Etiquette* etq) {
    //     for (auto elem_etq : ListeEtiquettes) {
    // 
    //     }
    // }
};


