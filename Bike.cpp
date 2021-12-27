//
// Created by Ewelina Szeliga on 17.12.2021.
//

#include "Bike.h"
#include "BikeSpecification.h"

Bike::Bike(const std::string &brand, const std::string &model, Color color, BikeBasket *bikeBasket, CarState state)
        : Vehicle(brand, model, color, state), bikeBasket(bikeBasket) {}


int Bike::getCapacity() {
    if(bikeBasket == nullptr) return 0;
    return bikeBasket->getBasketCapacity();
}
bool Bike::isInstanceOf(VehicleSpecification *vehicleSpecification) {
    BikeSpecification* bikeSpecification = dynamic_cast<BikeSpecification*>(vehicleSpecification);
    if(bikeSpecification == nullptr) return false;
    return this->brand == bikeSpecification->getBrand() &&
           this->model == bikeSpecification->getModel() &&
           this->color == bikeSpecification->getColor() &&
           this->getCapacity() == bikeSpecification->getBasketCapacity();
}

void Bike::stop() {
    this->state = CarState::STANDING;
}

void Bike::drive(double distance) {
    this->state = CarState::DRIVING;
}

