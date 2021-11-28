//
// Created by Ewelina Szeliga on 27.11.2021.
//

#include <iostream>
#include "Car.h"

void Car::fill(int AmountOfFuel) {
    if (AmountOfFuel == 0)std::cout << "Brak substancji napędowej.";
    else if (AmountOfFuel>0 && AmountOfFuel)
}

void Car::drive() {

}

void Car::stop() {

}

Car::Car(const std::string &brand, const std::string &model, Color color, State state) : brand(brand), model(model),
                                                                                         color(color), state(state) {}

