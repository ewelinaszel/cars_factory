//
// Created by Ewelina Szeliga on 27.12.2021.
//

#include "VehicleSpecification.h"

//operator wypisywania na ekran dla typu enum
std::ostream &operator<<(std::ostream &result, const Color color) {
    switch (color) {
        case Color::WHITE:
            result << "Biały";
            break;
        case Color::BLACK:
            result << "Czarny";
            break;
        case Color::GOLD:
            result << "Złoty";
            break;
        case Color::SILVER:
            result << "Srebrny";
            break;
        case Color::RED:
            result << "Czerwony";
            break;
    }
    return result;
}

std::istream &operator>>(std::istream &result, Color &color) {
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

std::ostream &operator<<(std::ostream &result, const VehicleSpecification *vehicleSpecification) {
    vehicleSpecification -> shortPrint(result);
    return result;
}
