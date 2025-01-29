#include "Guitare.hpp"
#include <iostream>
#include <map>
#include <windows.h> // Pour utiliser la fonction Beep sous Windows
using namespace std;

// Constructeur de la classe Guitare
Guitare::Guitare() : Instrument("Guitare") {}

// Méthode pour jouer une note sur la guitare
void Guitare::jouerNote(const string& note, const string& rythme) {
    // Tableau associatif qui relie chaque note à sa fréquence en Hertz
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

    // Tableau associatif qui définit la durée de chaque rythme
    map<string, float> rythmeMap = {
        {"lent", 2.0},   // Un rythme lent dure 2 fois plus longtemps
        {"normal", 1.0}, // Un rythme normal a une durée standard
        {"rapide", 0.5}  // Un rythme rapide dure la moitié du temps normal
    };

    // Vérification si la note existe dans le tableau noteVersFrequence
    if (noteVersFrequence.find(note) != noteVersFrequence.end()) {
        // Affichage de la note jouée avec son rythme
        cout << "[Guitare - " << rythme << "] : " << note << "\n";

        // Calcul de la durée de la note en millisecondes en fonction du rythme choisi
        DWORD duration = static_cast<DWORD>(1000 * rythmeMap[rythme]);

        // Utilisation de la fonction Beep pour jouer la note avec la fréquence correspondante
        Beep(noteVersFrequence[note], duration);
    }
    else {
        // Affichage d'un message d'erreur si la note n'est pas reconnue
        cout << "Note inconnue : " << note << "\n";
    }
}

// Méthode pour jouer une partition
void Guitare::jouerPartition(const string& cheminFichier, const string& rythme) {
    cout << "[Guitare] Jouer la partition depuis le fichier : " << cheminFichier << " avec le rythme : " << rythme << "\n";

    // Appel de la méthode de la classe mère Instrument pour lire et jouer la partition
    Instrument::jouerPartition(cheminFichier, rythme);
}
