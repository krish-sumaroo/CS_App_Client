#include "pch.h"

#include "Fonctions.h"

using namespace std;

string StringGererAStd(System::String^ StrGere) {
    return msclr::interop::marshal_as<std::string>(StrGere);
    //return "Hola";
}


