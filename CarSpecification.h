//
// Created by Ewelina Szeliga on 27.11.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_CARSPECIFICATION_H
#define SZELIGAEWELINA_ETAP1_CARSPECIFICATION_H

#include <string>
#include <iostream>
#include "VehicleSpecification.h"

class CarSpecification : public VehicleSpecification {
    std::string brand;
    std::string model;
    Color color;
    double fuelConsumption;
    int bootCapacity;

public:
    CarSpecification(const std::string &brand, const std::string &model, Color color, double fuelConsumption,
                     int bootCapacity);

    const std::string &getBrand() const;

    const std::string &getModel() const;

    Color getColor() const;

    double getFuelConsumption() const;

    int getBootCapacity() const;

    friend std::ostream &operator<<(std::ostream &result, const CarSpecification carSpecification);

    std::string getDescribedObjectName() override;
};


#endif //SZELIGAEWELINA_ETAP1_CARSPECIFICATION_H
