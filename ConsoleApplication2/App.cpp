#include "App.hpp"
#include "Piano.hpp"
#include "Xylophone.hpp"
#include "Guitare.hpp"
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

App::App() : instrument(nullptr) {}

void App::afficherMenu() const {
    cout << "///Bienvenue sur TuneKey///\n";
    cout << "1. Choisir un instrument\n";
    cout << "2. Jouer une note\n";
    cout << "3. Jouer une partition\n";
    cout << "4. Quitter\n";
    cout << "Entrez votre choix : ";
}

void App::choisirInstrument() {
    cout << "/// Choisis Ton Instrument ///\n";
    cout << "1. Piano\n";
    cout << "2. Xylophone\n";
    cout << "3. Guitare\n";
    cout << "Entrez votre choix : ";

    int choix;
    cin >> choix;

    switch (choix) {
    case 1:
        instrument = make_unique<Piano>();
        cout << "Piano selectionne.\n";
        break;
    case 2:
        instrument = make_unique<Xylophone>();
        cout << "Xylophone selectionne.\n";
        break;
    case 3:
        instrument = make_unique<Guitare>();
        cout << "Guitare selectionnee.\n";
        break;
    default:
        cout << "Choix invalide. Aucun instrument selectionne.\n";
        instrument.reset();
        break;
    }
}

void App::jouerNote() {
    if (!instrument) {
        cout << "Veuillez d'abord choisir un instrument.\n";
        return;
    }

    // Afficher les notes disponibles
    cout << "=== Notes Disponibles ===\n";
    cout << "B0, C1, C#1, D1, D#1, E1, F1, F#1, G1, G#1, A1, A#1, B1,\n";
    cout << "C2, C#2, D2, D#2, E2, F2, F#2, G2, G#2, A2, A#2, B2,\n";
    cout << "C3, C#3, D3, D#3, E3, F3, F#3, G3, G#3, A3, A#3, B3,\n";
    cout << "C4, C#4, D4, D#4, E4, F4, F#4, G4, G#4, A4, A#4, B4,\n";
    cout << "C5, C#5, D5, D#5, E5, F5, F#5, G5, G#5, A5, A#5, B5,\n";
    cout << "C6, C#6, D6, D#6, E6, F6, F#6, G6, G#6, A6, A#6, B6,\n";
    cout << "C7, C#7, D7, D#7, E7, F7, F#7, G7, G#7, A7, A#7, B7,\n";
    cout << "C8, C#8, D8, D#8\n";

    string rythme;
    cout << "Entrez le rythme (lent, normal, rapide) : ";
    cin >> rythme;

    ofstream fichierSortie("notes_jouees.txt", ios::app);
    if (!fichierSortie) {
        cerr << "Erreur : Impossible d'ouvrir le fichier notes_jouees.txt\n";
        return;
    }

    string note;
    while (true) {
        cout << "Entrez une note (ex: C1) ou 'q' pour quitter : ";
        cin >> note;
        if (note == "q") break;

        instrument->jouerNote(note, rythme);
        fichierSortie << note << " " << rythme << "\n";
    }
}

void App::jouerPartition() {
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

    instrument->jouerPartition(cheminFichier, rythme);
}

void App::executer() {
    ofstream fichierSortie("notes_jouees.txt", ios::trunc);
    bool enFonctionnement = true;

    while (enFonctionnement) {
        afficherMenu();

        int choix;
        cin >> choix;

        switch (choix) {
        case 1:
            choisirInstrument();
            break;
        case 2:
            jouerNote();
            break;
        case 3:
            jouerPartition();
            break;
        case 4:
            enFonctionnement = false;
            cout << "/// Merci d'avoir utilise TuneKey ! ///\n";
            break;
        default:
            cout << "Choix invalide. Veuillez reessayer.\n";
            break;
        }
    }
}