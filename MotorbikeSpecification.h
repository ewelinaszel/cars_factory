//
// Created by Ewelina Szeliga on 27.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP2_MOTORBIKESPECIFICATION_H
#define SZELIGAEWELINA_ETAP2_MOTORBIKESPECIFICATION_H


#include <string>
#include "VehicleSpecification.h"

class MotorbikeSpecification: public VehicleSpecification{
    std::string brand;
    std::string model;
    Color color;
    double fuelConsumption;
    int bootCapacity;

public:
    MotorbikeSpecification(const std::string &brand, const std::string &model, Color color, double fuelConsumption,
                     int bootCapacity);

    const std::string &getBrand() const;

    const std::string &getModel() const;

    Color getColor() const;

    double getFuelConsumption() const;

    int getBootCapacity() const;

    void shortPrint(std::ostream &result) const override;

    std::string getDescribedObjectName() override;
};


#endif //SZELIGAEWELINA_ETAP2_MOTORBIKESPECIFICATION_H
