//
// Created by Ewelina Szeliga on 27.12.2021.
//

#include "MotorbikeSpecification.h"

const std::string &MotorbikeSpecification::getBrand() const {
    return brand;
}

const std::string &MotorbikeSpecification::getModel() const {
    return model;
}

Color MotorbikeSpecification::getColor() const {
    return color;
}

void MotorbikeSpecification::shortPrint(std::ostream &result) const {
    result << this -> getBrand() << ", "
           << this -> getModel() << ", "
           << this -> getColor() << ", "
           << this -> getFuelConsumption() << "l/100km, "
           << this -> getBootCapacity() << "l";
    }

MotorbikeSpecification::MotorbikeSpecification(const std::string &brand, const std::string &model, Color color,
                                   double fuelConsumption, int bootCapacity) : brand(brand), model(model), color(color),
                                                                               fuelConsumption(fuelConsumption),
                                                                               bootCapacity(bootCapacity) {}

double MotorbikeSpecification::getFuelConsumption() const {
    return fuelConsumption;
}

int MotorbikeSpecification::getBootCapacity() const {
    return bootCapacity;
}

std::string MotorbikeSpecification::getDescribedObjectName() {
    return "Motorbike";
}
