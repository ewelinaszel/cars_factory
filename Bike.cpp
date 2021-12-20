//
// Created by Ewelina Szeliga on 17.12.2021.
//

#include "Bike.h"

Bike::Bike(const std::string &brand, const std::string &model, Color color, CarState state,
           const BikeBasket &bikeBasket) : Vehicle(brand, model, color, state), bikeBasket(bikeBasket) {}

int Bike::getCapacity() {
    return bikeBasket.getBasketCapacity();
}
