#ifndef TUNEKEY_HPP
#define TUNEKEY_HPP

#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <vector>
#include "Instrument.hpp"
#include "Piano.hpp"
#include "Xylophone.hpp"
#include "Guitare.hpp"

using namespace std;

class TuneKey {
private:
    unique_ptr<Instrument> instrumentSelectionne;
    map<string, double> frequenceNotes;

    void afficherMenuPrincipal() const;
    void selectionnerInstrument();
    void jouerUneNote();
    void lireUnePartition();
    void initialiserNotes();

public:
    TuneKey();
    void demarrerApplication();
};

#endif
