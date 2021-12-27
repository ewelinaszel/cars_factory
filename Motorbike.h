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
    Motorbike(const std::string &brand,
              const std::string &model,
              Color color,
              double fuelConsumption,
              int capacity,
              CarState state = CarState::STANDING,
              int amountOfFuel = 0,
              int mileage = 0);

    friend std::ostream & operator << (std ::ostream & result ,const Motorbike &motorbike);
    friend std::ofstream & operator << (std ::ofstream & result ,const Motorbike &motorbike);
    friend std::ifstream & operator >> (std::ifstream &result, Motorbike &motorbike);

    int getCapacity() override;

    bool isInstanceOf(VehicleSpecification *vehicleSpecification) override;
};


#endif //SZELIGAEWELINA_ETAP1_MOTORBIKE_H
