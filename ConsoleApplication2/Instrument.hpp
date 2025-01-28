#ifndef INSTRUMENT_HPP
#define INSTRUMENT_HPP

#include <string>
using namespace std;

class Instrument {
public:
    virtual ~Instrument() = default;
    virtual void jouerNote(const string& note, const string& rythme) const = 0;
};

#endif // INSTRUMENT_HPP
