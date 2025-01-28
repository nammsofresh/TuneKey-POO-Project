#ifndef XYLOPHONE_HPP
#define XYLOPHONE_HPP

#include "Instrument.hpp"

class Xylophone : public Instrument {
public:
    Xylophone();
    void jouer_note(string note, string rythme) override;
};

#endif // XYLOPHONE_HPP
