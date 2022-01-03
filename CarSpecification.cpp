//
// Created by Ewelina Szeliga on 27.11.2021.
//

#include <string>
#include "CarSpecification.h"

const std::string &CarSpecification::getBrand() const {
    return brand;
}

const std::string &CarSpecification::getModel() const {
    return model;
}

Color CarSpecification::getColor() const {
    return color;
}

CarSpecification::CarSpecification(const std::string &brand, const std::string &model, Color color,
                                   double fuelConsumption, int bootCapacity) : brand(brand), model(model), color(color),
                                                                               fuelConsumption(fuelConsumption),
                                                                               bootCapacity(bootCapacity) {}

double CarSpecification::getFuelConsumption() const {
    return fuelConsumption;
}

int CarSpecification::getBootCapacity() const {
    return bootCapacity;
}

std::string CarSpecification::getDescribedObjectName() {
    return "Car";
}

void CarSpecification::shortPrint(std::ostream &result) const {
    result << this -> getBrand() << ", "
           << this -> getModel() << ", "
           << this -> getColor() << ", "
           << this -> getFuelConsumption() << "l/100km, "
           << this -> getBootCapacity() << "l";
}
