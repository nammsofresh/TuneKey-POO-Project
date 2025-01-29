#ifndef GUITARE_HPP
#define GUITARE_HPP

#include "Instrument.hpp"

// Définition de la classe Guitare, qui hérite de la classe Instrument
class Guitare : public Instrument {
public:
    Guitare(); // Constructeur de la classe Guitare

    // Redéfinition de la méthode pour jouer une note spécifique
    void jouerNote(const string& note, const string& rythme) override;

    // Redéfinition de la méthode pour jouer une partition à partir d'un fichier
    void jouerPartition(const string& cheminFichier, const string& rythme) override;
};

#endif // GUITARE_HPP
