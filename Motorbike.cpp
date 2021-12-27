//
// Created by Ewelina Szeliga on 17.12.2021.
//

#include "Motorbike.h"
#include "MotorbikeSpecification.h"

Motorbike::Motorbike(const std::string &brand,
                     const std::string &model,
                     Color color,
                     double fuelConsumption,
                     int capacity,
                     CarState state,
                     int amountOfFuel,
                     int mileage) :
                        MotorVehicle(brand,
                                     model,
                                     color,
                                     fuelConsumption,
                                     capacity,
                                     state,
                                     amountOfFuel,
                                     mileage) {}

std::ostream &operator<<(std::ostream &result, const Motorbike &motorbike) {
    result << "Marka motocyklu to:";
    result << motorbike.brand;
    result << "\nKolor:";
    result << motorbike.color;
    result << "\nModel motocyklu to:";
    result << motorbike.model;
    result << "\nAktualna ilość paliwa wynosi:";
    result << motorbike.amountOfFuel;
    if (motorbike.state == CarState::DRIVING) {
        result << "\nMotocykl jest w ruchu.";
    } else {
        result << "\nMotocykl stoi.";
    }
    result << "\nSpalanie motocykla wynosi: ";
    result << motorbike.fuelConsumption;
    result << "\nPojemność bagażnika w motocyklu wynosi:";
    result << motorbike.bootCapacity;
    result << "\nPrzebieg motocykla wynosi:";
    result << motorbike.mileage;
    result << "\nAktaulna ilość paliwa wynosi:";
    result << motorbike.amountOfFuel;
    return result;

}

std::ofstream &operator<<(std::ofstream &result, const Motorbike &motorbike) {
    result << motorbike.brand << "\n";
    result << motorbike.model << "\n";
    result << motorbike.color << "\n";
    result << motorbike.state << "\n";
    result << motorbike.amountOfFuel << "\n";
    result << motorbike.fuelConsumption << "\n";
    result << motorbike.bootCapacity << "\n";
    result << motorbike.mileage << "\n";
    return result;
}

std::ifstream &operator>>(std::ifstream &result, Motorbike &motorbike) {
    result >> motorbike.brand;
    result >> motorbike.model;
    result >> motorbike.color;
    result >> motorbike.state;
    result >> motorbike.amountOfFuel;
    result >> motorbike.fuelConsumption;
    result >> motorbike.bootCapacity;
    result >> motorbike.mileage;
    return result;
}

int Motorbike::getCapacity() {
    return bootCapacity;
}

bool Motorbike::isInstanceOf(VehicleSpecification *vehicleSpecification) {
    MotorbikeSpecification* motorbikeSpecification = dynamic_cast<MotorbikeSpecification*>(vehicleSpecification);
    if(motorbikeSpecification == nullptr) return false;
    return this->brand == motorbikeSpecification->getBrand() &&
                  this->model == motorbikeSpecification->getModel() &&
                  this->color == motorbikeSpecification->getColor() &&
                  this->fuelConsumption == motorbikeSpecification->getFuelConsumption() &&
                  this->bootCapacity == motorbikeSpecification->getBootCapacity();
}
