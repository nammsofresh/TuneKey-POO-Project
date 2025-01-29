#ifndef INSTRUMENT_HPP
#define INSTRUMENT_HPP

#include <string>
using namespace std;

class Instrument {
protected:
    string nom;

public:
    Instrument(const string& n);
    virtual ~Instrument() = default;

    virtual void jouerNote(const string& note, const string& rythme) = 0;
    virtual void jouerPartition(const string& cheminFichier, const string& rythme) = 0;

    string getNom() const;
};

#endif // INSTRUMENT_HPP