
#include "pch.h"
#include "Client.h"

using namespace std;

bool ConfirmerIdentifiant(string id, string mdp) {
    //vector<string> IdentifiantPossible = {};

    map<string, string> IdentifiantsPossible = {
        {"Bob"   , "1234"},
        {"Robert", "147" }
    };

    
    if (mdp != IdentifiantsPossible[id]) {
        cout << "Mot de pass erron�" << endl;
        return false;
    }

    return true;
}


void ObtenirListEtiquettes(vector<Etiquette> *etiquettes) {
    etiquettes->clear();
    etiquettes->push_back(Etiquette("Lent"     ));
    etiquettes->push_back(Etiquette("Rapide"   ));
    etiquettes->push_back(Etiquette("Bleu"     ));
    etiquettes->push_back(Etiquette("Rouge"    ));
    etiquettes->push_back(Etiquette("Aquatique", "Pour les poissons, pas les mammif�res."));
}


void ObtenirListeEntrevues(vector<Entrevue> *entrevues) {
    entrevues->clear();

    Entrevue t_entrevue = Entrevue("Les tortues");
    
    // vector<string> paragraphes{ "Les tortues sont des mammif�res marins" , "Les tortues de mer quant � elles, pondent leur oeufs sur la plage." };
    // vector<string> paragraphes{ "Les tortues sont des mammif�res marins" , "Les tortues de mer quant � elles, pondent leur oeufs sur la plage." };

    AjouterEntrevue(entrevues, "Les tortues" , vector<string>{"Les tortues sont des mammif�res marins", "Les tortues de mer quant � elles, pondent leur oeufs sur la plage."});
    AjouterEntrevue(entrevues, "Les vaches"  , vector<string>{"Les vaches sont des mammif�re.", "Elles sont principalement utilis� par les humains pour leur lait."});
    AjouterEntrevue(entrevues, "Les cochons" , vector<string>{"Les cochons sont des mammif�re.", "Ils vivent sur des fermes.", "Ils sont tr�s propres malgr� l'id�e que l'on en a."});

    
}

void AjouterEntrevue(vector<Entrevue>* entrevues, string titre, vector<string> paragraphes) {
    Entrevue t_entrevue = Entrevue(titre);

    for (int i = 0; i < paragraphes.size(); ++i) {
        Paragraphe paragraphe1 = Paragraphe("P " + to_string(i), paragraphes[i]);

        t_entrevue.ajouterParagraphe(paragraphe1);
    }

    entrevues->push_back(t_entrevue);
}

