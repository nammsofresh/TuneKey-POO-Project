#ifndef INSTRUMENT_HPP
#define INSTRUMENT_HPP

#include <string>
#include <map>

using namespace std;

// Classe de base abstraite représentant un instrument de musique
class Instrument {
protected:
    string nom; // Nom de l'instrument (ex: "Piano", "Guitare", etc.)

public:
    // Constructeur prenant un nom en paramètre
    Instrument(const string& n);

    // Destructeur virtuel pour assurer la destruction correcte des objets dérivés
    virtual ~Instrument() = default;

    // Méthodes virtuelles pures (rend la classe abstraite)
    virtual void jouerNote(const string& note, const string& rythme) = 0;  // Joue une note
    virtual void jouerPartition(const string& cheminFichier, const string& rythme) = 0;  // Joue une partition

    // Getter pour récupérer le nom de l'instrument
    string getNom() const;
};

#endif // INSTRUMENT_HPP
