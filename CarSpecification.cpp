//
// Created by Ewelina Szeliga on 27.11.2021.
//

#include <string>
#include "CarSpecification.h"

CarSpecification::CarSpecification(const std::string &brand, const std::string &model, Color color) : brand(brand),
                                                                                                      model(model),
                                                                                                      color(color) {}

const std::string &CarSpecification::getBrand() const {
    return brand;
}

const std::string &CarSpecification::getModel() const {
    return model;
}

Color CarSpecification::getColor() const {
    return color;
}

