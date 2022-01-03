//
// Created by Ewelina Szeliga on 27.12.2021.
//

#include "BikeSpecification.h"

BikeSpecification::BikeSpecification(const std::string &brand, const std::string &model, Color color, int bikeBasket)
        : brand(brand), model(model), color(color), basketCapacity(bikeBasket) {}

const std::string &BikeSpecification::getBrand() const {
    return brand;
}

const std::string &BikeSpecification::getModel() const {
    return model;
}

Color BikeSpecification::getColor() const {
    return color;
}

int BikeSpecification::getBasketCapacity() const {
    return basketCapacity;
}

void BikeSpecification::shortPrint(std::ostream &result) const {
    result << this -> getBrand() << ", "
           << this -> getModel() << ", "
           << this -> getColor() << ", "
           << this -> getBasketCapacity() << "l";
}

std::string BikeSpecification::getDescribedObjectName() {
    return "Bike";
}
