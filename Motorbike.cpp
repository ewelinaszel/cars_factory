//
// Created by Ewelina Szeliga on 17.12.2021.
//

#include "Motorbike.h"
#include "MotorbikeSpecification.h"

Motorbike::Motorbike() {}

Motorbike::Motorbike(const std::string &brand,
                     const std::string &model,
                     Color color,
                     double fuelConsumption,
                     int capacity,
                     VehicleState state,
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

void Motorbike::print(std::ostream &result) const{
    result << "Marka motocyklu to:";
    result << this -> brand;
    result << "\nKolor:";
    result << this -> color;
    result << "\nModel motocyklu to:";
    result << this -> model;
    result << "\nAktualna ilość paliwa wynosi:";
    result << this -> amountOfFuel;
    if (this -> state == VehicleState::DRIVING) {
        result << "\nMotocykl jest w ruchu.";
    } else {
        result << "\nMotocykl stoi.";
    }
    result << "\nSpalanie motocykla wynosi: ";
    result << this -> fuelConsumption;
    result << "\nPojemność bagażnika w motocyklu wynosi:";
    result << this -> bootCapacity;
    result << "\nPrzebieg motocykla wynosi:";
    result << this -> mileage;
    result << "\nAktaulna ilość paliwa wynosi:";
    result << this -> amountOfFuel;
    result << "\n";
}

int Motorbike::getCapacity() const {
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

std:: string Motorbike::shortString() const {
    return "Motor: " + this->brand + ", " + this->model;
}

void Motorbike::writeToFile(std::ofstream &result) const {
    result << "Motor:"<<"\n";
    result << this -> brand << "\n";
    result << this ->model << "\n";
    result << this ->color << "\n";
    result << this ->state << "\n";
    result << this ->amountOfFuel << "\n";
    result << this ->fuelConsumption << "\n";
    result << this ->bootCapacity << "\n";
    result << this ->mileage << "\n";
}

void Motorbike::readFromFile(std::ifstream &result)  {
    result >> this -> brand;
    result >> this ->model;
    result >> this ->color;
    result >> this ->state;
    result >> this ->amountOfFuel;
    result >> this ->fuelConsumption;
    result >> this ->bootCapacity;
    result >> this ->mileage;
}



