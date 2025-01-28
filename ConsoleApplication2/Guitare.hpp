#ifndef GUITARE_HPP
#define GUITARE_HPP

#include "Instrument.hpp"

class Guitare : public Instrument {
public:
    Guitare();
    void jouer_note(string note, string rythme) override;
};

#endif // GUITARE_HPP