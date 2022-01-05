//
// Created by Ewelina Szeliga on 27.11.2021.
//

#include <iostream>
#include "Car.h"
#include "CarSpecification.h"

//przeładowanie operatora wyświetlania na ekran
void Car::print(std::ostream &result) const {
    result << "Marka samochodu to:";
    result << this -> brand;
    result << "\nKolor:";
    result << this -> color;
    result << "\nModel samochodu:";
    result << this -> model;
    result << "\nAktualna ilość paliwa wynosi:";
    result << this -> amountOfFuel;
    if (this -> state == VehicleState::DRIVING) {
        result << "\nSamochód jest w ruchu.";
    } else {
        result << "\nSamochód stoi.";
    }
    result << "\nSpalanie samochodu wynosi: ";
    result << this -> fuelConsumption;
    result << "\nPojemność bagażnika wynosi:";
    result << this -> bootCapacity;
    result << "\nPrzebieg samochodu wynosi:";
    result << this -> mileage;
    result << "\nAktaulna ilość paliwa wynosi:";
    result << this -> amountOfFuel;
    result << '\n';
}

Car::Car() {}

Car::Car(const std::string &brand,
         const std::string &model,
         Color color,
         double fuelConsumption,
         int bootCapacity,
         int amountOfFuel,
         VehicleState state,
         int mileage) :
            MotorVehicle(brand, model,color, fuelConsumption, bootCapacity, state,amountOfFuel,mileage) {}

int Car::getCapacity() const {
    return bootCapacity;
}

Car::~Car() {
}

bool Car::isInstanceOf(VehicleSpecification *vehicleSpecification) {
    CarSpecification* carSpecification = dynamic_cast<CarSpecification*>(vehicleSpecification);
    if(carSpecification == nullptr) return false;
    return this->brand == carSpecification->getBrand() &&
           this->model == carSpecification->getModel() &&
           this->color == carSpecification->getColor() &&
           this->fuelConsumption == carSpecification->getFuelConsumption() &&
           this->bootCapacity == carSpecification->getBootCapacity();
}

std::string Car::shortString() const {
    return "Samochód: " + this->brand + ", " + this->model;
}

void Car::writeToFile(std::ofstream &result) const {
    result << "Samochód:"<< "\n";
    result << this -> brand << "\n";
    result << this ->model << "\n";
    result << this ->color << "\n";
    result << this ->state << "\n";
    result << this ->amountOfFuel << "\n";
    result << this ->fuelConsumption << "\n";
    result << this ->bootCapacity << "\n";
    result << this ->mileage << "\n";
}

void Car::readFromFile(std::ifstream &result)  {
    result >> this -> brand;
    result >> this ->model;
    result >> this ->color;
    result >> this ->state;
    result >> this ->amountOfFuel;
    result >> this ->fuelConsumption;
    result >> this ->bootCapacity;
    result >> this ->mileage;
}



