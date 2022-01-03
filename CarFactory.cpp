//
// Created by Ewelina Szeliga on 28.11.2021.
//

#include "CarFactory.h"

CarFactory::CarFactory() : VehicleFactory() {}

void CarFactory::createVehicle(VehicleSpecification *vehicleSpecification) {

    if(vehicleSpecification == nullptr) {
        throw std::invalid_argument("Vehicle specification cannot be nullptr");
    }

    CarSpecification* carSpecification = dynamic_cast<CarSpecification*>(vehicleSpecification);

    if(carSpecification == nullptr) {
        throw std::invalid_argument("Cannot create car with given specification");
    }

    Car* newCar = new Car(
            carSpecification->getBrand(),
            carSpecification->getModel(),
            carSpecification->getColor(),
            carSpecification->getFuelConsumption(),
            carSpecification->getBootCapacity()
    );

    inventory.push_back(newCar);
}




