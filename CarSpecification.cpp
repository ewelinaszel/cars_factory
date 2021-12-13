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

//operator wypisywania na ekran dla typu enum
std::ostream &operator<<(std::ostream &result, const Color color) {
    switch (color) {
        case Color::WHITE: 
        result << "Biały";
        break;
        case Color::BLACK: result << "Czarny"; break;
        case Color::GOLD: result << "Złoty"; break;
        case Color::SILVER: result << "Srebrny"; break;
        case Color::RED: result << "Czerwony"; break;
    }
    return result;
}

std::istream & operator>>(std ::istream & result, Color &color) {
    std::string colorString;
    result >> colorString;
    if (colorString == "Biały") {
        color = Color::WHITE;
    } else if (colorString == "Czarny") {
        color = Color::BLACK;
    } else if (colorString == "Złoty") {
        color = Color::GOLD;
    } else if (colorString == "Srebrny") {
        color = Color::SILVER;
    } else if (colorString == "Czerwony") {
        color = Color::RED;
    } else {
        std::cout << "Cannot read color: " << colorString << std::endl;
    }
    return result;
}


std::ostream &operator<<(std::ostream &result, const CarSpecification carSpecification) {
    result << carSpecification.getBrand() << ", " << carSpecification.getModel() << ", " << carSpecification.getColor();
    return result;
}
