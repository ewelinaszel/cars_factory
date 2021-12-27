//
// Created by Ewelina Szeliga on 17.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_BIKE_H
#define SZELIGAEWELINA_ETAP1_BIKE_H

#include "Vehicle.h"
#include "BikeBasket.h"

class Bike: public Vehicle{
    BikeBasket* bikeBasket;
public:
    Bike(const std::string &brand, const std::string &model, Color color,
         BikeBasket *bikeBasket = nullptr, CarState state = CarState::STANDING);

    int getCapacity() override;

    void stop() override;

    void drive(double distance) override;

    bool isInstanceOf(VehicleSpecification *vehicleSpecification) override;
};


#endif //SZELIGAEWELINA_ETAP1_BIKE_H
