//
// Created by Ewelina Szeliga on 28.11.2021.
//

#include "CarFactory.h"

CarFactory::CarFactory() {}

Car CarFactory::createCar(CarSpecification carSpecification) {
    Car newCar = Car(
            carSpecification.getBrand(),
            carSpecification.getModel(),
            carSpecification.getColor()
    );
    this->producedCars.push_back(newCar);
    return newCar;
}
