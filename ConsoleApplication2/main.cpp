#include "App.hpp"

// Fonction principale du programme
int main() {
    // Création d'un objet app de type App
    App app;  // L'objet app est une instance de la classe App, représentant l'application entière

    // Appel de la méthode executer() sur l'objet app
    // Cette méthode est responsable de l'exécution des opérations principales de l'application
    app.executer();

    // Retour de la valeur 0 pour indiquer que l'exécution s'est terminée correctement
    return 0;
}
