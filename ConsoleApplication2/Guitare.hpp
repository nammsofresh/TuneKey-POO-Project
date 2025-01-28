#ifndef GUITARE_HPP
#define GUITARE_HPP

#include "Instrument.hpp"

class Guitare : public Instrument {
public:
    void jouerNote(const string& note, const string& rythme) const override;
};

#endif // GUITARE_HPP
