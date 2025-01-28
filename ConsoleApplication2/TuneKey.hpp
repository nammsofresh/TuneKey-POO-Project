#ifndef TUNEKEY_HPP
#define TUNEKEY_HPP

#include <memory>
#include "Instrument.hpp"

class TuneKey {
private:
    std::unique_ptr<Instrument> instrument;

public:
    TuneKey();

    void afficher_menu();
    void choisir_instrument();
    void jouer_note();
    void jouer_part();
    void run();
};

#endif // TUNEKEY_HPP
