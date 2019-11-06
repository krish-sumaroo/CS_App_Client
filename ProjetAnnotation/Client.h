#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <string>

#include "Entrevue.h"

using namespace std;

//bool ConfirmerIdentifiant(System::String^ id, System::String^ mdp) {
bool ConfirmerIdentifiant (string, string);
void ObtenirListEtiquettes(vector<Etiquette>*);
void ObtenirListeEntrevues(vector<Entrevue>*);


