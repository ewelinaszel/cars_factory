//
// Created by Ewelina Szeliga on 17.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_MOTORBIKE_H
#define SZELIGAEWELINA_ETAP1_MOTORBIKE_H

#include "MotorVehicle.h"
#include "MotorbikeSpecification.h"
#include <fstream>
#include <iostream>

class Motorbike: public MotorVehicle {

public:
    Motorbike();

    Motorbike(const std::string &brand,
              const std::string &model,
              Color color,
              double fuelConsumption,
              int capacity,
              CarState state = CarState::STANDING,
              int amountOfFuel = 0,
              int mileage = 0);

    void print(std ::ostream & result) const override;

    std::string shortString() const override;

    void writeToFile(std::ofstream &result) const override;

    void readFromFile(std::ifstream &result) override;

    int getCapacity() const override;

    bool isInstanceOf(VehicleSpecification *vehicleSpecification) override;
};


#endif //SZELIGAEWELINA_ETAP1_MOTORBIKE_H
