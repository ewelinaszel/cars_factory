//
// Created by Ewelina Szeliga on 27.11.2021.
//

#ifndef FABRYKA_CARSPECIFICATION_H
#define FABRYKA_CARSPECIFICATION_H

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
};


#endif //FABRYKA_CARSPECIFICATION_H
