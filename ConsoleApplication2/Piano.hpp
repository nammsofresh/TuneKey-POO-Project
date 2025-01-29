#ifndef PIANO_HPP
#define PIANO_HPP

#include "Instrument.hpp"

// La classe Piano hérite publiquement de Instrument, ce qui signifie qu'elle doit implémenter les méthodes virtuelles de Instrument.
class Piano : public Instrument {
public:
    Piano(); // Constructeur par défaut qui initialise un objet Piano

    // Implémentation des méthodes virtuelles de la classe Instrument
    void jouerNote(const string& note, const string& rythme) override; // Joue une note spécifique avec un rythme donné
    void jouerPartition(const string& cheminFichier, const string& rythme) override; // Joue une partition à partir d'un fichier donné avec un rythme donné
};

#endif // PIANO_HPP