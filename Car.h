//
// Created by Ewelina Szeliga on 27.11.2021.
//

#ifndef FABRYKA_CAR_H
#define FABRYKA_CAR_H


#include <string>
#include "CarSpecification.h"
enum class State{
    ON,
    OFF
};
class Car {
    std:: string brand;
    std:: string model;
    Color color;
    State state;
public:
    Car(const std::string &brand, const std::string &model, Color color, State state);
    void fill(int AmountOfFuel);
    void drive();
    void stop();
};


#endif //FABRYKA_CAR_H
