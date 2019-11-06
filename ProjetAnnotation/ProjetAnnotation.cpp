#include "pch.h"
#include "PagePrincipal.h"
#include "PageConnexion.h"

using namespace System;
using namespace System::Windows::Forms;

//int main(array<System::String ^> ^args)

[STAThread]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    bool userOk = false;
    string id;
    string mdp;

    ProjetAnnotation::PageConnexion pageConnexion(&userOk, &id, &mdp);
    ProjetAnnotation::PagePrincipal pagePrincipal(&id, &mdp);

    Application::Run(% pageConnexion);

    // Afficher seulement la page principal si l'utilisateur est bon
    if (userOk) {
        Application::Run(% pagePrincipal);
    }
}
