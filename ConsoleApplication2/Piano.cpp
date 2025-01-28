#include "Piano.hpp"
#include <iostream>

using namespace std;

void Piano::jouerNote(const string& note, const string& rythme) const {
    cout << "Piano joue la note " << note << " avec un rythme " << rythme << ".\n";
}
