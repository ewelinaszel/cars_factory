//
// Created by Ewelina Szeliga on 17.12.2021.
//

#include "MotorVehicle.h"


void MotorVehicle::fill(int AmountOfFuel) {

}

const std::string &MotorVehicle::getBrand() const {
    return brand;
}

const std::string &MotorVehicle::getModel() const {
    return model;
}

int MotorVehicle::getAmountOfFuel() const {
    return amountOfFuel;
}

double MotorVehicle::getFuelConsumption() const {
    return fuelConsumption;
}

int MotorVehicle::getMileage() const {
    return mileage;
}

MotorVehicle::MotorVehicle() {}

MotorVehicle::MotorVehicle(const std::string &brand,
                           const std::string &model,
                           Color color,
                           double fuelConsumption,
                           int capacity,
                           CarState state,
                           int amountOfFuel,
                           int mileage) : Vehicle(
        capacity, color, state), brand(brand), model(model),fuelConsumption(
        fuelConsumption), amountOfFuel(amountOfFuel), mileage(mileage) {}

