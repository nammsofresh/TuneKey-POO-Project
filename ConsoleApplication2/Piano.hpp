#ifndef PIANO_HPP
#define PIANO_HPP

#include "Instrument.hpp"

class Piano : public Instrument {
public:
    void jouerNote(const string& note, const string& rythme) const override;
};

#endif
