#ifndef GUITARE_HPP
#define GUITARE_HPP

#include "Instrument.hpp"

// D�finition de la classe Guitare, qui h�rite de la classe Instrument
class Guitare : public Instrument {
public:
    Guitare(); // Constructeur de la classe Guitare

    // Red�finition de la m�thode pour jouer une note sp�cifique
    void jouerNote(const string& note, const string& rythme) override;

    // Red�finition de la m�thode pour jouer une partition � partir d'un fichier
    void jouerPartition(const string& cheminFichier, const string& rythme) override;
};

#endif // GUITARE_HPP
