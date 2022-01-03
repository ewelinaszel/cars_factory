//
// Created by Ewelina Szeliga on 27.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_VEHICLESPECIFICATION_H
#define SZELIGAEWELINA_ETAP1_VEHICLESPECIFICATION_H

#include <iostream>

enum class Color {
    BLACK=0,
    WHITE=1,
    GOLD=2,
    SILVER=3,
    RED=4

};

std::ostream &operator<<(std::ostream &result, const Color color);

std::istream &operator>>(std::istream &result, Color &color);

class VehicleSpecification {

public:
    virtual std::string getDescribedObjectName() = 0;
    virtual void shortPrint(std::ostream &result) const = 0;
    friend std::ostream &operator<<(std::ostream &result, const VehicleSpecification* vehicleSpecification);
};


#endif //SZELIGAEWELINA_ETAP1_VEHICLESPECIFICATION_H
