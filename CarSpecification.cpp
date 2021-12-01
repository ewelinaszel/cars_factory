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

std::ostream &operator<<(std::ostream &result, const Color color) {
    switch (color) {
        case Color:: WHITE: return result << "Biały";
        case Color:: BLACK: return result << "Czarny";
        case Color:: GOLD: return result << "Złoty";
        case Color:: SILVER: return result << "Srebrny";
        case Color:: RED: return result << "Czerwony";
    }
}

std::ostream &operator<<(std::ostream &result, const CarSpecification carSpecification) {
    result << carSpecification.getBrand() << ", " << carSpecification.getModel() << ", " << carSpecification.getColor();
    return result;
}
