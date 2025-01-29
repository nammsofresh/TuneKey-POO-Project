#ifndef PIANO_HPP
#define PIANO_HPP

#include "Instrument.hpp"
using namespace std;

class Piano : public Instrument {
public:
    Piano();
    void jouerNote(const string& note, const string& rythme) override;
    void jouerPartition(const string& note, const string& rythme) override;

};

#endif // PIANO_HPP