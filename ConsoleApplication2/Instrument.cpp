#include "Instrument.hpp"

Instrument::Instrument() {
    // Initialisation explicite du buffer et du son
    if (!buffer.loadFromFile("path/to/soundfile.wav")) {
        throw std::runtime_error("Impossible de charger le fichier audio.");
    }
    sound.setBuffer(buffer);
}

void Instrument::jouerNote(const std::string& note, const std::string& rythme) const {
    // Cette m�thode pourrait impl�menter une logique pour jouer une note
    // Exemple simple : jouer la note d�s que le nom est pass�
    sound.play();
}

bool Instrument::estJouee() const {
    // Utilisation de la m�thode getStatus() pour v�rifier si le son est en train de jouer
    return sound.getStatus() == sf::Sound::Playing;
}

void Instrument::chargerBuffer(const std::string& note) const {
    // Par exemple, tu peux charger un fichier diff�rent selon la note
    if (!buffer.loadFromFile("path/to/" + note + ".wav")) {
        throw std::runtime_error("Impossible de charger le fichier de la note : " + note);
    }
    sound.setBuffer(buffer);
}
