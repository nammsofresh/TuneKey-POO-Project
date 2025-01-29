#ifndef XYLOPHONE_HPP
#define XYLOPHONE_HPP

#include "Instrument.hpp"
using namespace std;

class Xylophone : public Instrument {
public:
    Xylophone();
    void jouerNote(const string& note, const string& rythme) override;
    void jouerPartition(const string& note, const string& rythme) override;
};

#endif // XYLOPHONE_HPP