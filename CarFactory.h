//
// Created by Ewelina Szeliga on 28.11.2021.
//

#ifndef FABRYKA_CARFACTORY_H
#define FABRYKA_CARFACTORY_H


#include <vector>
#include "Car.h"

class CarFactory {
    std::vector<Car> producedCars;
public:
    CarFactory();

    Car createCar(CarSpecification carSpecification);

};


#endif //FABRYKA_CARFACTORY_H
