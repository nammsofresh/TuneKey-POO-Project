#ifndef APP_HPP
#define APP_HPP

#include <memory>
#include "Instrument.hpp"
using namespace std;

class App {
private:
    unique_ptr<Instrument> instrument;

    void afficherMenu() const;
    void choisirInstrument();
    void jouerNote();
    void jouerPartition();

public:
    App();
    void executer();
};

#endif // APP_HPP