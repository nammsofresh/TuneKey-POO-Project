#include "TuneKey.hpp"

TuneKey::TuneKey() {
    initialiserNotes();
}

void TuneKey::initialiserNotes() {
    frequenceNotes = {
        {"DO4", 262}, {"RE4", 294}, {"MI4", 330}, {"FA4", 349},
        {"SOL4", 392}, {"LA4", 440}, {"SI4", 494}
    };
}

void TuneKey::afficherMenuPrincipal() const {
    cout << "\nBienvenue sur TuneKey !\n";
    cout << "1. Choisir un instrument\n";
    cout << "2. Jouer une note\n";
    cout << "3. Lire une partition\n";
    cout << "4. Quitter l'application\n";
    cout << "Votre choix : ";
}

void TuneKey::selectionnerInstrument() {
    vector<string> instruments = { "Piano", "Xylophone", "Guitare" };
    cout << "\nSelectionnez un instrument parmi les suivants :\n";

    for (size_t i = 0; i < instruments.size(); ++i) {
        cout << i + 1 << ". " << instruments[i] << "\n";
    }

    cout << "Votre choix : ";
    int choix;
    cin >> choix;

    if (choix > 0 && choix <= static_cast<int>(instruments.size())) {
        switch (choix) {
        case 1:
            instrumentSelectionne = make_unique<Piano>();
            break;
        case 2:
            instrumentSelectionne = make_unique<Xylophone>();
            break;
        case 3:
            instrumentSelectionne = make_unique<Guitare>();
            break;
        }
        cout << "Instrument choisi : " << instruments[choix - 1] << "\n";
    }
    else {
        cout << "Choix invalide. Aucun instrument n'a ete selectionne.\n";
        instrumentSelectionne.reset();
    }
}

void TuneKey::jouerUneNote() {
    if (!instrumentSelectionne) {
        cout << "Aucun instrument n'est actuellement selectionne. Veuillez en choisir un.\n";
        return;
    }

    string rythme;
    cout << "Indiquez la vitesse de lecture (lent, normal, rapide) : ";
    cin >> rythme;

    while (true) {
        string note;
        cout << "Entrez une note a jouer (ou 'stop' pour quitter) : ";
        cin >> note;

        if (note == "stop") {
            cout << "Arret de la lecture des notes.\n";
            break;
        }

        auto it = frequenceNotes.find(note);
        if (it != frequenceNotes.end()) {
            instrumentSelectionne->jouerNote(note, rythme);
        }
        else {
            cout << "Note invalide. Veuillez reessayer.\n";
        }
    }
}

void TuneKey::lireUnePartition() {
    if (!instrumentSelectionne) {
        cout << "Aucun instrument selectionne. Veuillez d'abord en choisir un.\n";
        return;
    }

    cout << "Entrez les notes de la partition separees par des espaces (ex : DO4 RE4 MI4).\n";
    cout << "Terminez par 'fin'.\n";

    vector<string> partition;
    string note;

    while (true) {
        cin >> note;
        if (note == "fin") {
            break;
        }
        partition.push_back(note);
    }

    string rythme;
    cout << "Indiquez le rythme de lecture (lent, normal, rapide) : ";
    cin >> rythme;

    for (const auto& n : partition) {
        instrumentSelectionne->jouerNote(n, rythme);
    }
}

void TuneKey::demarrerApplication() {
    bool enCours = true;

    while (enCours) {
        afficherMenuPrincipal();

        int action;
        cin >> action;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entree invalide. Veuillez entrer un nombre.\n";
            continue;
        }

        switch (action) {
        case 1:
            selectionnerInstrument();
            break;
        case 2:
            jouerUneNote();
            break;
        case 3:
            lireUnePartition();
            break;
        case 4:
            enCours = false;
            cout << "Merci d'avoir utilise TuneKey ! A bientot.\n";
            break;
        default:
            cout << "Option non reconnue. Reessayez.\n";
        }
    }
}
