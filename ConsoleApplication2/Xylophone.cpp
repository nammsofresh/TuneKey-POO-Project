#include "Xylophone.hpp"
#include <iostream>

using namespace std;

void Xylophone::jouerNote(const string& note, const string& rythme) const {
    cout << "Xylophone joue la note " << note << " avec un rythme " << rythme << ".\n";
}
