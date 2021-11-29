//
// Created by Ewelina Szeliga on 27.11.2021.
//

#ifndef FABRYKA_CAR_H
#define FABRYKA_CAR_H


#include <string>
#include "CarSpecification.h"

enum class CarState {
    DRIVING,
    STANDING
};

class Car {
    std::string brand;
    std::string model;
    Color color;

    CarState state;
    int amountOfFuel;
public:
    Car(const std::string &brand, const std::string &model, Color color, CarState state=CarState::STANDING, int amountOfFuel=0);

    void fill(int AmountOfFuel);

    void stop();

    void drive();
};


#endif //FABRYKA_CAR_H
