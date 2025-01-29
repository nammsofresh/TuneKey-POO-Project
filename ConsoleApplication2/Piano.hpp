#ifndef PIANO_HPP
#define PIANO_HPP

#include "Instrument.hpp"

// La classe Piano h�rite publiquement de Instrument, ce qui signifie qu'elle doit impl�menter les m�thodes virtuelles de Instrument.
class Piano : public Instrument {
public:
    Piano(); // Constructeur par d�faut qui initialise un objet Piano

    // Impl�mentation des m�thodes virtuelles de la classe Instrument
    void jouerNote(const string& note, const string& rythme) override; // Joue une note sp�cifique avec un rythme donn�
    void jouerPartition(const string& cheminFichier, const string& rythme) override; // Joue une partition � partir d'un fichier donn� avec un rythme donn�
};

#endif // PIANO_HPP