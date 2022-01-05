//
// Created by Ewelina Szeliga on 27.12.2021.
//

#include "UsedMotorVehicleDealer.h"
#include "Motorbike.h"
#include "Car.h"

template class UsedMotorVehicleDealer<MotorVehicle>;
template class UsedMotorVehicleDealer<Motorbike>;
template class UsedMotorVehicleDealer<Car>;

template<class T>
const std::map<T *, double> &UsedMotorVehicleDealer<T>::getAvailableModels() const {
    return availableModels;
}

template<class T>
T *UsedMotorVehicleDealer<T>::sellToClient(T *motorVehicle, double price) {
    if (this->availableModels.find(motorVehicle) == this->availableModels.end()){
        throw std::runtime_error("Brak modelu na stanie");
    }

    double minimumSellPrice = this->availableModels[motorVehicle];
    if (price < minimumSellPrice) {
        throw std::invalid_argument("Zbyt niska kwota.");
    }
    this->availableModels.erase(motorVehicle);
    return motorVehicle;
}

template<class T>
double UsedMotorVehicleDealer<T>::buyFromOwner(MotorVehicle &motorVehicle) {
    T* vehicle = dynamic_cast<T*>(&motorVehicle);
    if(vehicle == nullptr) {
        throw std::invalid_argument("Invalid type of vehicle.");
    }

    double estimatedPrice = this->estimatePrice(*vehicle);
    this->availableModels[vehicle] = estimatedPrice * (1 + this->margin);
    if (vehicle -> getBrand() == "BMW"){
        this->decreaseMileage(*vehicle);
    }
    return estimatedPrice;
}

template<class T>
double UsedMotorVehicleDealer<T>::estimatePrice(MotorVehicle &motorVehicle) {
    T* vehicle = dynamic_cast<T*>(&motorVehicle);
    if(vehicle == nullptr) {
        throw std::invalid_argument("Invalid type of vehicle.");
    }

    double estimatedPrice;
    if (vehicle -> getBrand() == "BMW") {
        estimatedPrice = 20000;
    } else if (vehicle -> getBrand() == "Chevrolet") {
        estimatedPrice = 15000;
    } else {
        estimatedPrice = 10000;
    }

    estimatedPrice = estimatedPrice * (1 - (double) motorVehicle.getMileage() / 1000000);
    return estimatedPrice;
}

template<class T>
void UsedMotorVehicleDealer<T>::decreaseMileage(T &motorVehicle) {
    motorVehicle.setMileage(motorVehicle.getMileage()/2);
}

template<class T>
UsedMotorVehicleDealer<T>::UsedMotorVehicleDealer(const std::string &name,
                                               const std::map<T *, double> &availableModels, double margin)
        : name(name), availableModels(availableModels), margin(margin) {}

template<class T>
const std::string &UsedMotorVehicleDealer<T>::getName() const {
    return name;
}
