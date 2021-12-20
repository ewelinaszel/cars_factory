//
// Created by Ewelina Szeliga on 17.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_BIKE_H
#define SZELIGAEWELINA_ETAP1_BIKE_H

#include "Vehicle.h"
#include "BikeBasket.h"

class Bike: public Vehicle{
    BikeBasket bikeBasket;
public:
    Bike(const std::string &brand, const std::string &model, Color color, CarState state,
         const BikeBasket &bikeBasket);

    int getCapacity() override;
};


#endif //SZELIGAEWELINA_ETAP1_BIKE_H
