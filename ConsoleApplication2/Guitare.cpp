#include "Guitare.hpp"
#include <iostream>

using namespace std;

void Guitare::jouerNote(const string& note, const string& rythme) const {
    cout << "Guitare joue la note " << note << " avec un rythme " << rythme << ".\n";
}
