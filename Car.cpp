//
// Created by Ewelina Szeliga on 27.11.2021.
//

#include <iostream>
#include "Car.h"
#include "CarSpecification.h"

//przeładowanie operatora wypisywania na ekran dla enum carState
//std::ostream &operator<<(std::ostream &result, const CarState &carState) {
//    switch (carState) {
//        case CarState::STANDING:
//            result << "Standing";
//            break;
//        case CarState::DRIVING:
//            result << "Driving";
//            break;
//    }
//    return result;
//}

//std::istream &operator>>(std::istream &result, CarState &carState) {
//    std::string stateString;
//    result >> stateString;
//    if (stateString == "Standing") {
//        carState = CarState::STANDING;
//    } else if (stateString == "Driving") {
//        carState = CarState::DRIVING;
//    }
//    return result;
//}

//sprawdzenie czy istnieje samochód o danej specyfikacji
bool Car::isInstanceOf(const CarSpecification &carSpecification) {
    return this->brand == carSpecification.getBrand() &&
           this->model == carSpecification.getModel() &&
           this->color == carSpecification.getColor() &&
           this->fuelConsumption == carSpecification.getFuelConsumption() &&
           this->bootCapacity == carSpecification.getBootCapacity();
}

//przeładowanie operatora wyświetlania na ekran
std::ostream &operator<<(std::ostream &result, const Car &car) {
    result << "Marka samochodu to:";
    result << car.brand;
    result << "\nKolor:";
    result << car.color;
    result << "\nModel samochodu:";
    result << car.model;
    result << "\nAktualna ilość paliwa wynosi:";
    result << car.amountOfFuel;
    if (car.state == CarState::DRIVING) {
        result << "\nSamochód jest w ruchu.";
    } else {
        result << "\nSamochód stoi.";
    }
    result << "\nSpalanie samochodu wynosi: ";
    result << car.fuelConsumption;
    result << "\nPojemność bagażnika wynosi:";
    result << car.bootCapacity;
    result << "\nPrzebieg samochodu wynosi:";
    result << car.mileage;
    result << "\nAktaulna ilość paliwa wynosi:";
    result << car.amountOfFuel;
    return result;

}

//przeładowania operatorów zapisu do pliku i czytania z pliku
std::ofstream &operator<<(std::ofstream &result, const Car &car) {
    result << car.brand << "\n";
    result << car.model << "\n";
    result << car.color << "\n";
    result << car.state << "\n";
    result << car.amountOfFuel << "\n";
    result << car.fuelConsumption << "\n";
    result << car.bootCapacity << "\n";
    result << car.mileage << "\n";
    return result;
}

std::ifstream &operator>>(std::ifstream &result, Car &car) {
    result >> car.brand;
    result >> car.model;
    result >> car.color;
    result >> car.state;
    result >> car.amountOfFuel;
    result >> car.fuelConsumption;
    result >> car.bootCapacity;
    result >> car.mileage;
    return result;
    }

Car::Car() {}

Car::Car(const std::string &brand,
         const std::string &model,
         Color color,
         double fuelConsumption,
         int bootCapacity,
         int amountOfFuel,
         CarState state,
         int mileage) :
            MotorVehicle(brand, model,color, fuelConsumption, bootCapacity, state,amountOfFuel,mileage) {}

int Car::getCapacity() {
    return bootCapacity;
}




