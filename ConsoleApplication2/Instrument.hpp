#ifndef INSTRUMENT_HPP
#define INSTRUMENT_HPP

#include <string>
#include <iostream>
using namespace std;

class Instrument {
private:
    string nom;
public:
    Instrument(string n);

    virtual void jouer_note(string note, string rythme);
    virtual void jouer_part(string part, string rythme, string instrument);

    string get_nom();
};

#endif // INSTRUMENT_HPP
