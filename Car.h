//
// Created by Ewelina Szeliga on 27.11.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_CAR_H
#define SZELIGAEWELINA_ETAP1_CAR_H


#include <string>
#include "CarSpecification.h"
#include<iostream>
#include <fstream>
#include "MotorVehicle.h"



std::ostream & operator<<(std ::ostream & result ,const CarState &carState);

class Car: public MotorVehicle {

public:
    Car();

    Car(const std::string &brand, const std::string &model, Color color, double fuelConsumption,int capacity, int amountOfFuel = 0,CarState state = CarState::STANDING,
        int mileage =0);

    void fill(int AmountOfFuel);

    void stop();

    void drive(double distance);

    const std::string &getBrand() const;

    const std::string &getModel() const;

    Color getColor() const;

    CarState getState() const;

    int getAmountOfFuel() const;

    double getFuelConsumption() const;

    int getBootCapacity() const;

    int getMileage() const;

    bool isInstanceOf(const CarSpecification &carSpecification);

    friend std::ostream & operator<<(std ::ostream & result ,const Car &car);
    friend std::ofstream & operator<<(std ::ofstream & result ,const Car &car);
    friend std::ifstream & operator >> (std::ifstream &result, Car &car);
};


#endif //SZELIGAEWELINA_ETAP1_CAR_H
