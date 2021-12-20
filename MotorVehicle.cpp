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
                           int bootCapacity,
                           CarState state,
                           int amountOfFuel,
                           int mileage) :
        Vehicle(brand, model, color, state),
        fuelConsumption(fuelConsumption),
        bootCapacity(bootCapacity),
        amountOfFuel(amountOfFuel),
        mileage(mileage) {}

void MotorVehicle::stop() {
    if (this->state == CarState::STANDING) {
        std::cout << "Pojazd juz jest zaparkowany" << std::endl;
        return;
    }
    this->state = CarState::STANDING;
}

void MotorVehicle::drive(double distance) {
    int requiredAmountOfFuelToDrive = (this ->fuelConsumption * distance)/100;

    if (this->state == CarState::DRIVING) {
        std::cout << "Pojazd juz jest w ruchu" << std::endl;
        return;
    }

    if (this->amountOfFuel < requiredAmountOfFuelToDrive) {
        std::cout << "Brak wystarczajacej ilosci substancji napedowej" << std::endl;
        return;
    }
    this->amountOfFuel -= requiredAmountOfFuelToDrive;
    this->state = CarState::DRIVING;
    this->mileage += distance;
}

