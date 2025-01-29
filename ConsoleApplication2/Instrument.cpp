#include "Instrument.hpp"
#include <iostream>
#include <fstream>  // Pour lire les fichiers
#include <sstream>  // Pour traiter les lignes du fichier
#include <map>      // Pour stocker les correspondances note-fréquence
#include <windows.h> // Pour utiliser Beep sous Windows
using namespace std;

// Constructeur de la classe Instrument
Instrument::Instrument(const string& n) : nom(n) {}

// Getter pour le nom de l'instrument
string Instrument::getNom() const {
    return nom;
}

// Méthode pour jouer une partition depuis un fichier
void Instrument::jouerPartition(const string& cheminFichier, const string& rythme) {
    // Tableau associatif reliant chaque note à sa fréquence en Hertz
    map<string, int> noteVersFrequence = {
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

    // Tableau associatif qui définit la durée des rythmes
    map<string, float> rythmeMap = {
        {"lent", 2.0},   // Un rythme lent double la durée des notes
        {"normal", 1.0}, // Rythme normal sans modification de durée
        {"rapide", 0.5}  // Un rythme rapide réduit la durée des notes de moitié
    };

    // Ouvrir le fichier contenant la partition
    ifstream fichier(cheminFichier);
    if (!fichier) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << cheminFichier << "\n";
        return;
    }

    // Lecture de la partition ligne par ligne
    string ligne;
    while (getline(fichier, ligne)) {
        istringstream iss(ligne);
        string note;
        double duree;

        // Extraire la note et sa durée depuis la ligne
        if (iss >> note >> duree) {
            // Ajuster la durée en fonction du rythme
            double dureeAjustee = duree * rythmeMap[rythme];

            // Durée minimale pour éviter que les notes soient trop courtes
            if (dureeAjustee < 0.1) {
                dureeAjustee = 0.1; // 100 ms minimum
            }

            if (note != "0") { // "0" représente un silence
                // Joue la note avec sa fréquence et sa durée ajustée
                cout << "[" << nom << "] Note : " << note << ", Durée : " << dureeAjustee << " secondes\n";
                Beep(noteVersFrequence[note], static_cast<DWORD>(dureeAjustee * 1000));
            }
            else {
                // Silence (pause entre les notes)
                cout << "[" << nom << "] Silence, Durée : " << dureeAjustee << " secondes\n";
                Sleep(static_cast<DWORD>(dureeAjustee * 1000));
            }
        }
        else {
            // Erreur si la ligne n'est pas au bon format
            cerr << "Erreur : Format invalide dans la ligne : " << ligne << "\n";
        }
    }
}
