//
// Created by Ewelina Szeliga on 28.11.2021.
//

#include "CarFactory.h"
#include "SalesDepartment.h"

CarFactory::CarFactory() : VehicleFactory() {}

void CarFactory::createVehicle(VehicleSpecification *vehicleSpecification) {

    if(vehicleSpecification == nullptr) {
        std:: cout << "Vehicle specification cannot be nullptr" << std::endl;
    }

    CarSpecification* carSpecification = dynamic_cast<CarSpecification*>(vehicleSpecification);

    if(carSpecification == nullptr) {
        std::cout << "Cannot create car with given specification" << std::endl;
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




