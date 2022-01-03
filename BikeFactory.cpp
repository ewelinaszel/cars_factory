//
// Created by Ewelina Szeliga on 27.12.2021.
//

#include "BikeFactory.h"
#include "BikeSpecification.h"
#include "Bike.h"

BikeFactory::BikeFactory() :VehicleFactory() {}

void BikeFactory::createVehicle(VehicleSpecification *vehicleSpecification) {

    if(vehicleSpecification == nullptr) {
        throw std::invalid_argument("Vehicle specification cannot be nullptr");
    }

    BikeSpecification* bikeSpecification = dynamic_cast<BikeSpecification*>(vehicleSpecification);

    if(bikeSpecification == nullptr) {
        throw std::invalid_argument("Cannot create bike with given specification");
    }

    Bike* newBike;
    if (bikeSpecification->getBasketCapacity() == 0) {
        newBike = new Bike(
                bikeSpecification->getBrand(),
                bikeSpecification->getModel(),
                bikeSpecification->getColor()
        );
    } else {
        BikeBasket* bikeBasket = new BikeBasket(bikeSpecification->getBasketCapacity());
        newBike = new Bike(
                bikeSpecification->getBrand(),
                bikeSpecification->getModel(),
                bikeSpecification->getColor(),
                bikeBasket
        );
    }

    inventory.push_back(newBike);
}
