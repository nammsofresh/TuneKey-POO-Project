#include "TuneKey.hpp"
#include "Piano.hpp"
#include "Xylophone.hpp"
#include "Guitare.hpp"
#include <iostream>
#include <memory>
#include <map>
#include <fstream>

TuneKey::TuneKey() : instrument(nullptr) {}

void TuneKey::afficher_menu() {
    cout << "=== Bienvenue dans l'application musicale ===\n";
    cout << "1. Choisir un instrument\n";
    cout << "2. Jouer une note\n";
    cout << "3. Jouer une partition\n";
    cout << "4. Quitter\n";
    cout << "Entrez votre choix : ";
}

void TuneKey::choisir_instrument() {
    cout << "=== Choisissez un instrument ===\n";
    cout << "1. Piano\n";
    cout << "2. Xylophone\n";
    cout << "3. Guitare\n";
    cout << "Entrez votre choix : ";

    int choix;
    cin >> choix;

    switch (choix) {
    case 1:
        instrument = make_unique<Piano>();
        cout << "Instrument choisi : Piano\n";
        break;
    case 2:
        instrument = make_unique<Xylophone>();
        cout << "Instrument choisi : Xylophone\n";
        break;
    case 3:
        instrument = make_unique<Guitare>();
        cout << "Instrument choisi : Guitare\n";
        break;
    default:
        cout << "Choix invalide. Aucun instrument sélectionné.\n";
        instrument.reset();
        break;
    }
}

void TuneKey::jouer_note() {
    if (!instrument) {
        cout << "Veuillez d'abord choisir un instrument.\n";
        return;
    }

    map<std::string, int> note_to_frequency = {
    {"B0", 31}, {"C1", 33}, {"C#1", 35}, {"D1", 37}, {"D#1", 39}, {"E1", 41}, {"F1", 44}, {"F#1", 46}, {"G1", 49}, {"G#1", 52},
    {"A1", 55}, {"A#1", 58}, {"B1", 62}, {"C2", 65}, {"C#2", 69}, {"D2", 73}, {"D#2", 78}, {"E2", 82}, {"F2", 87}, {"F#2", 93},
    {"G2", 98}, {"G#2", 104}, {"A2", 110}, {"A#2", 117}, {"B2", 123}, {"C3", 131}, {"C#3", 139}, {"D3", 147}, {"D#3", 156},
    {"E3", 165}, {"F3", 175}, {"F#3", 185}, {"G3", 196}, {"G#3", 208}, {"A3", 220}, {"A#3", 233}, {"B3", 247}, {"C4", 262},
    {"C#4", 277}, {"D4", 294}, {"D#4", 311}, {"E4", 330}, {"F4", 349}, {"F#4", 370}, {"G4", 392}, {"G#4", 415}, {"A4", 440},
    {"A#4", 466}, {"B4", 494}, {"C5", 523}, {"C#5", 554}, {"D5", 587}, {"D#5", 622}, {"E5", 659}, {"F5", 698}, {"F#5", 740},
    {"G5", 784}, {"G#5", 831}, {"A5", 880}, {"A#5", 932}, {"B5", 988}, {"C6", 1047}, {"C#6", 1109}, {"D6", 1175}, {"D#6", 1245},
    {"E6", 1319}, {"F6", 1397}, {"F#6", 1480}, {"G6", 1568}, {"G#6", 1661}, {"A6", 1760}, {"A#6", 1865}, {"B6", 1976},
    {"C7", 2093}, {"C#7", 2217}, {"D7", 2349}, {"D#7", 2489}, {"E7", 2637}, {"F7", 2794}, {"F#7", 2960}, {"G7", 3136},
    {"G#7", 3322}, {"A7", 3520}, {"A#7", 3729}, {"B7", 3951}, {"C8", 4186}, {"C#8", 4435}, {"D8", 4699}, {"D#8", 4978}
    };

    map<string, float> ryth_l = {
    { "lent", static_cast<float>(2.0) },
    { "normal", static_cast<float>(1.0) },
    { "rapide", static_cast<float>(0.5) }
    };

    ofstream outFile("notes_jouees.txt", ios::trunc);
    if (!outFile) {
        cerr << "Erreur : impossible d'ouvrir le fichier notes_jouees.txt\n";
        return;
    }

    string rythme;
    cout << "Entrez le rythme (lent, normal, rapide) : ";
    cin >> rythme;
    bool arret = false;
    while (!arret) {
        string note;
        cout << "Entrez la note à jouer (ex: C4) : ";
        cin >> note;
        if (note == "q") {
            return;
        }
        auto existe = note_to_frequency.find(note);
        if (existe != note_to_frequency.end()) {
            instrument->jouer_note(note, rythme);
            outFile << note << " " << ryth_l[rythme] << endl;
        }
        else {
            cout << "Cette note n'existe pas \n";
        }
    }
}

void TuneKey::jouer_part() {
    if (!instrument) {
        cout << "Veuillez d'abord choisir un instrument.\n";
        return;
    }

    string cheminFichier;
    cout << "Entrez le chemin du fichier de partition (ex: partition.txt) : ";
    cin >> cheminFichier;

    string rythme;
    cout << "Entrez le rythme (lent, normal, rapide) : ";
    cin >> rythme;

    instrument->jouer_part(cheminFichier, rythme, instrument->get_nom());
}

void TuneKey::run() {
    ofstream outFile("notes_jouees.txt", std::ios::trunc);
    bool arret = false;

    while (!arret) {
        afficher_menu();

        int choix;
        cin >> choix;

        switch (choix) {
        case 1:
            choisir_instrument();
            break;
        case 2:
            jouer_note();
            break;
        case 3:
            jouer_part();
            break;
        case 4:
            arret = true;
            cout << "Merci d'avoir utilisé l'application musicale !\n";
            break;
        default:
            cout << "Choix invalide. Veuillez réessayer.\n";
            break;
        }
    }
}