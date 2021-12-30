//
// Created by Ewelina Szeliga on 27.12.2021.
//

#include "Sprayer.h"

Sprayer::Sprayer() {}

Sprayer::~Sprayer() {

}

Sprayer *Sprayer::getInstance() {
    if (_instance == nullptr) {
        _instance = new Sprayer;
    }
    return _instance;
}

void Sprayer::changeColor(Vehicle &vehicle, Color color) {
    vehicle.setColor(color);
}
