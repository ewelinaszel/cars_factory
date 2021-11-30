//
// Created by Ewelina Szeliga on 27.11.2021.
//

#ifndef FABRYKA_CARSPECIFICATION_H
#define FABRYKA_CARSPECIFICATION_H

#include <string>
#include <iostream>

enum class Color {
    BLACK,
    WHITE,
    GOLD,
    SILVER,
    RED
};

class CarSpecification {
    std:: string brand;
    std:: string model;
    Color color;

public:
    CarSpecification(const std::string &brand, const std::string &model, Color color);

    const std::string &getBrand() const;

    const std::string &getModel() const;

    Color getColor() const;

    friend inline std::ostream & operator<<(std ::ostream & result ,const Color color);
};


#endif //FABRYKA_CARSPECIFICATION_H
