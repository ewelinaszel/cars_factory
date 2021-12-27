//
// Created by Ewelina Szeliga on 27.12.2021.
//

#include "UsedMotorVehicleDealer.h"

const std::map<MotorVehicle *, double> &UsedMotorVehicleDealer::getAvailableModels() const {
    return availableModels;
}

MotorVehicle *UsedMotorVehicleDealer::sellToClient(MotorVehicle *motorVehicle, double price) {
    if (this->availableModels.find(motorVehicle) == this->availableModels.end()){
        std::cout<<"Brak modelu na stanie."<<std::endl;
    }

    double minimumSellPrice = this->availableModels[motorVehicle];
    if (price < minimumSellPrice) {
        //wyjątek nie można sprzedać poniżej ceny sprzedarzy (za mało piniążków)
        std::cout << "Nie sprzedamy Ci za tak mało pieniędzy, nasza cena to " << minimumSellPrice << std::endl;
    }
    this->availableModels.erase(motorVehicle);
    return motorVehicle;
}

double UsedMotorVehicleDealer::buyFromOwner(MotorVehicle &motorVehicle) {
    double estimatedPrice = this->estimatePrice(motorVehicle);
//    this->availableModels.insert(std::pair<MotorVehicle*, double>(&motorVehicle,estimatedPrice*(1+this->margin)));
    this->availableModels[&motorVehicle] = estimatedPrice * (1 + this->margin);
    if (motorVehicle.getBrand() == "BMW"){
        this->decreaseMileage(motorVehicle);
    }
    return estimatedPrice;
}

double UsedMotorVehicleDealer::estimatePrice(MotorVehicle &motorVehicle) {
    double estimatedPrice = 0;
    if (motorVehicle.getBrand() == "BMW") {
        estimatedPrice = 20000;
    } else if (motorVehicle.getBrand() == "Chevrolet") {
        estimatedPrice = 15000;
    } else {
        estimatedPrice = 10000;
    }

    estimatedPrice = estimatedPrice * (1 - (double) motorVehicle.getMileage() / 1000000);
    return estimatedPrice;
}

void UsedMotorVehicleDealer::decreaseMileage(MotorVehicle &motorVehicle) {
    motorVehicle.setMileage(motorVehicle.getMileage()/2);
}
