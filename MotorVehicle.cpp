//
// Created by Ewelina Szeliga on 17.12.2021.
//

#include "MotorVehicle.h"


void MotorVehicle::fill(int AmountOfFuel) {
    if (AmountOfFuel == 0) {
        throw std::runtime_error("Brak substancji napędowej.");
    } else if (AmountOfFuel < 0) {
        throw std::invalid_argument("Ilość substancji napedowej nie może byc ujemna");
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
                           VehicleState state,
                           int amountOfFuel,
                           int mileage) :
        Vehicle(brand, model, color, state),
        fuelConsumption(fuelConsumption),
        bootCapacity(bootCapacity),
        amountOfFuel(amountOfFuel),
        mileage(mileage) {}

MotorVehicle::~MotorVehicle() {

}

void MotorVehicle::stop() {
    if (this->state == VehicleState::STANDING) {
        throw std::runtime_error("Pojazd już jest zaparkowany");
    }
    this->state = VehicleState::STANDING;
}

void MotorVehicle::drive(double distance) {
    int requiredAmountOfFuelToDrive = (this ->fuelConsumption * distance)/100;

    if (this->state == VehicleState::DRIVING) {
        throw std::runtime_error("Pojazd już jest w ruchu");
    }

    if (this->amountOfFuel < requiredAmountOfFuelToDrive) {
        throw std::runtime_error("Brak wystarczajacej ilosci substancji napedowej");
    }
    this->amountOfFuel -= requiredAmountOfFuelToDrive;
    this->state = VehicleState::DRIVING;
    this->mileage += distance;
}

void MotorVehicle::setMileage(int mileage) {
    MotorVehicle::mileage = mileage;
}

