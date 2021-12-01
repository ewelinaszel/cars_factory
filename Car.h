//
// Created by Ewelina Szeliga on 27.11.2021.
//

#ifndef FABRYKA_CAR_H
#define FABRYKA_CAR_H


#include <string>
#include "CarSpecification.h"
#include<iostream>
#include <fstream>

enum class CarState {
    DRIVING,
    STANDING
};

class Car {
    std::string brand;
    std::string model;
    Color color;///dlaczego tak kazało mi zrobić ze static

    CarState state;
    int amountOfFuel;
public:
    Car(const std::string &brand, const std::string &model, Color color, CarState state = CarState::STANDING, int amountOfFuel =0);

    void fill(int AmountOfFuel);

    void stop();

    void drive();

    friend std::ostream & operator<<(std ::ostream & result ,const Car &car);

    const std::string &getBrand() const;

    const std::string &getModel() const;

    Color getColor() const;


};


#endif //FABRYKA_CAR_H
