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
std::ostream & operator<<(std ::ostream & result ,const CarState &carState);
std::istream &operator>>(std::istream &result, CarState &carState);

class Vehicle {
protected:
    int capacity;
    CarState state;
    Color color;
public:
    Vehicle();

    explicit Vehicle(int capacity, Color color, CarState state);

    int getCapacity() const;

    CarState getState() const;

};


#endif //SZELIGAEWELINA_ETAP1_VEHICLE_H
