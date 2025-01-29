#ifndef XYLOPHONE_HPP
#define XYLOPHONE_HPP

#include "Instrument.hpp"

// La classe Xylophone h�rite publiquement de Instrument, ce qui signifie qu'elle doit impl�menter les m�thodes virtuelles de Instrument.
class Xylophone : public Instrument {
public:
    Xylophone(); // Constructeur par d�faut qui initialise un objet Xylophone

    // Impl�mentation des m�thodes virtuelles de la classe Instrument
    void jouerNote(const string& note, const string& rythme) override; // Joue une note sp�cifique avec un rythme donn�
    void jouerPartition(const string& cheminFichier, const string& rythme) override; // Joue une partition � partir d'un fichier donn� avec un rythme donn�
};

#endif // XYLOPHONE_HPP