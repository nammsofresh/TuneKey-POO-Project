#ifndef PIANO_HPP
#define PIANO_HPP

#include "Instrument.hpp"

class Piano : public Instrument {
public:
    Piano();
    void jouer_note(string note, string rythme) override;
};

#endif // PIANO_HPP