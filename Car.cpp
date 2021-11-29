//
// Created by Ewelina Szeliga on 27.11.2021.
//

#include <iostream>
#include "Car.h"

void Car::fill(int AmountOfFuel) {
    //todo std::cout usage here is temporary - this method should not print anything to stdout
    if (AmountOfFuel == 0) {
        std::cout << "Brak substancji napędowej." << std::endl;
    } else if (AmountOfFuel < 0) {
        std::cout << "Ilosc substancji napedowej nie moze byc ujemna" << std::endl;
    }
    else if (AmountOfFuel > 0) {
        this->amountOfFuel += AmountOfFuel;
    }
}

void Car::drive() {
    //todo deal with hardcoded value
    int requiredAmountOfFuelToDrive = 10;
    if (this->state == CarState::DRIVING) {
        std::cout << "Pojazd juz jest w ruchu" << std::endl;
        return;
    }

    if (this->amountOfFuel < requiredAmountOfFuelToDrive) {
        std::cout << "Brak wystarczajacej ilosci substancji napedowej" << std::endl;
        return;
    }
    this->amountOfFuel -= requiredAmountOfFuelToDrive;
    this->state = CarState::DRIVING;
}

void Car::stop() {
    if (this->state == CarState::STANDING) {
        std::cout << "Pojazd juz jest zaparkowany" << std::endl;
        return;
    }
    this->state = CarState::STANDING;
}

//todo should I define default parameters values as it is in *.h file
Car::Car(const std::string &brand, const std::string &model, Color color, CarState state, int amountOfFuel) : brand(
        brand),
                                                                                                              model(model),
                                                                                                              color(color),
                                                                                                              state(state),
                                                                                                              amountOfFuel(
                                                                                                                      amountOfFuel) {}

