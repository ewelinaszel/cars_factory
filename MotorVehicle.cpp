//
// Created by Ewelina Szeliga on 17.12.2021.
//

#include "MotorVehicle.h"


void MotorVehicle::fill(int AmountOfFuel) {
    if (AmountOfFuel == 0) {
        std::cout << "Brak substancji napędowej." << std::endl;
    } else if (AmountOfFuel < 0) {
        std::cout << "Ilosc substancji napedowej nie moze byc ujemna" << std::endl;
    } else if (AmountOfFuel > 0) {
        this->amountOfFuel += AmountOfFuel;
    }
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
                           int bootCapacity,
                           CarState state,
                           int amountOfFuel,
                           int mileage) :
        Vehicle(brand, model, color, state),
        fuelConsumption(fuelConsumption),
        bootCapacity(bootCapacity),
        amountOfFuel(amountOfFuel),
        mileage(mileage) {}

MotorVehicle::~MotorVehicle() {

}


