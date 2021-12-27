//
// Created by Ewelina Szeliga on 27.12.2021.
//

#include "MotorbikeFactory.h"
#include "MotorbikeSpecification.h"
#include "Motorbike.h"

void MotorbikeFactory::createVehicle(VehicleSpecification *vehicleSpecification) {

    if(vehicleSpecification == nullptr) {
        std:: cout << "Vehicle specification cannot be nullptr" << std::endl;
    }

    MotorbikeSpecification* motorbikeSpecification = dynamic_cast<MotorbikeSpecification*>(vehicleSpecification);

    if(motorbikeSpecification == nullptr) {
        std::cout << "Cannot create car with given specification" << std::endl;
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
