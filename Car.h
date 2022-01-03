//
// Created by Ewelina Szeliga on 27.11.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_CAR_H
#define SZELIGAEWELINA_ETAP1_CAR_H


#include <string>
#include "CarSpecification.h"
#include <iostream>
#include <fstream>
#include "MotorVehicle.h"



//std::ostream & operator<<(std ::ostream & result ,const CarState &carState);

class Car: public MotorVehicle {

public:
    Car();

    Car(const std::string &brand,
        const std::string &model,
        Color color,
        double fuelConsumption,
        int bootCapacity,
        int amountOfFuel = 0,
        CarState state = CarState::STANDING,
        int mileage = 0);

    ~Car();

    int getCapacity() const override;

    void print(std ::ostream & result) const override;
    std::string shortString() const override;
    void writeToFile(std::ofstream &result) const override;
    void readFromFile(std::ifstream &result) override;
//    friend std::ofstream & operator << (std ::ofstream & result ,const Car &car);
//    friend std::ifstream & operator >> (std::ifstream &result, Car &car);

    bool isInstanceOf(VehicleSpecification *vehicleSpecification) override;

};


#endif //SZELIGAEWELINA_ETAP1_CAR_H
