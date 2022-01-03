//
// Created by Ewelina Szeliga on 27.12.2021.
//

#include "MotorbikeFactory.h"
#include "MotorbikeSpecification.h"
#include "Motorbike.h"

void MotorbikeFactory::createVehicle(VehicleSpecification *vehicleSpecification) {

    if(vehicleSpecification == nullptr) {
        throw std::invalid_argument("Vehicle specification cannot be nullptr");
    }

    MotorbikeSpecification* motorbikeSpecification = dynamic_cast<MotorbikeSpecification*>(vehicleSpecification);

    if(motorbikeSpecification == nullptr) {
        throw std::invalid_argument("Cannot create motorbike with given specification");
    }

    Motorbike* newMotorbike = new Motorbike(
            motorbikeSpecification->getBrand(),
            motorbikeSpecification->getModel(),
            motorbikeSpecification->getColor(),
            motorbikeSpecification->getFuelConsumption(),
            motorbikeSpecification->getBootCapacity()
    );

    inventory.push_back(newMotorbike);
}
