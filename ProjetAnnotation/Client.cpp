
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
        cout << "Mot de pass erroné" << endl;
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
    etiquettes->push_back(Etiquette("Aquatique", "Pour les poissons, pas les mammifères."));
}


void ObtenirListeEntrevues(vector<Entrevue> *entrevues) {
    //Entrevue t_entrevue = Entrevue("Les tortues");
    
    // //Paragraphe paragraphe1 = Paragraphe("P1", "blah blah blah");
    // //Paragraphe paragraphe2 = Paragraphe("P2", "salut allo comment");
    // 
    // 
    // t_entrevue.ajouterParagraphe("Les tortues: p1", "blah blah blah");
    // t_entrevue.ajouterParagraphe("Les tortues: p2", "salut allo comment");
    // 
    // entrevues->push_back(t_entrevue);


}



