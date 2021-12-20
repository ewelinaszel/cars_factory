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
    std::string brand;
    std::string model;
    Color color;
    CarState state;
public:
    Vehicle();

    Vehicle(const std::string &brand, const std::string &model, Color color, CarState state);

    CarState getState() const;

    virtual int getCapacity() = 0;

};


#endif //SZELIGAEWELINA_ETAP1_VEHICLE_H
