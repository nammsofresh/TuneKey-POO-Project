#ifndef GUITARE_HPP
#define GUITARE_HPP

#include "Instrument.hpp"
using namespace std;

class Guitare : public Instrument {
public:
    Guitare();
    void jouerNote(const string& note, const string& rythme) override;
    void jouerPartition(const string& note, const string& rythme) override;
};

#endif // GUITARE_HPP