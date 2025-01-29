#include "App.hpp"

// Fonction principale du programme
int main() {
    // Cr�ation d'un objet app de type App
    App app;  // L'objet app est une instance de la classe App, repr�sentant l'application enti�re

    // Appel de la m�thode executer() sur l'objet app
    // Cette m�thode est responsable de l'ex�cution des op�rations principales de l'application
    app.executer();

    // Retour de la valeur 0 pour indiquer que l'ex�cution s'est termin�e correctement
    return 0;
}
