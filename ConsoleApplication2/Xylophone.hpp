#ifndef XYLOPHONE_HPP
#define XYLOPHONE_HPP

#include "Instrument.hpp"

class Xylophone : public Instrument {
public:
    void jouerNote(const string& note, const string& rythme) const override;
};

#endif
