//
// Created by Ewelina Szeliga on 27.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_BIKESPECIFICATION_H
#define SZELIGAEWELINA_ETAP1_BIKESPECIFICATION_H


#include "VehicleSpecification.h"

class BikeSpecification: public VehicleSpecification{
    std::string brand;
    std::string model;
    Color color;
    int basketCapacity;
public:
    BikeSpecification(const std::string &brand, const std::string &model, Color color, int bikeBasket);

    const std::string &getBrand() const;

    const std::string &getModel() const;

    Color getColor() const;

    int getBasketCapacity() const;

    void shortPrint(std::ostream &result) const override;

    std::string getDescribedObjectName() override;

};


#endif //SZELIGAEWELINA_ETAP1_BIKESPECIFICATION_H
