//
// Created by Ewelina Szeliga on 17.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_VEHICLE_H
#define SZELIGAEWELINA_ETAP1_VEHICLE_H

#include "CarSpecification.h"
enum class CarState {
    DRIVING,
    STANDING
};

class Vehicle {
protected:
    int capacity;
    CarState state;
    Color color;
public:
    Vehicle();

    explicit Vehicle(int capacity, Color color, CarState state);

    virtual void stop();

    virtual void drive(double distance);

    int getCapacity() const;

    CarState getState() const;
};


#endif //SZELIGAEWELINA_ETAP1_VEHICLE_H
