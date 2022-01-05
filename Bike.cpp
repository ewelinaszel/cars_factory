//
// Created by Ewelina Szeliga on 17.12.2021.
//

#include "Bike.h"
#include "BikeSpecification.h"

Bike::Bike(const std::string &brand, const std::string &model, Color color, BikeBasket *bikeBasket, VehicleState state)
        : Vehicle(brand, model, color, state), bikeBasket(bikeBasket) {}


int Bike::getCapacity() const {
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
    if (this->state == VehicleState::STANDING) {
        throw std::runtime_error("Rower już stoi w miejscu.");
    }
    this->state = VehicleState::STANDING;
}

void Bike::drive(double distance) {
    if (this->state == VehicleState::DRIVING) {
        throw std::runtime_error("Rower jest już w ruchu");
    }
    this->state = VehicleState::DRIVING;
}

void Bike::print(std::ostream &result) const {
    result << "Marka roweru to:";
    result << this -> brand;
    result << "\nKolor:";
    result << this -> color;
    result << "\nModel roweru:";
    result << this -> model;
    if (this -> state == VehicleState::DRIVING) {
        result << "\nRower jest w ruchu.";
    } else {
        result << "\nRower stoi.";
    }
    if(this -> bikeBasket== nullptr){
        result<<"\nBrak koszyka.";
    }
    else{
        result<<"\nPojemność koszyka wynosi:";
        result<< this ->bikeBasket->getBasketCapacity();
    }
    result << '\n';
}

std::string Bike::shortString() const {
    return "Rower: " + this->brand + ", " + this->model;
}

void Bike::writeToFile(std::ofstream &result) const {
    result << "Rower:"<< "\n";
    result << this -> brand << "\n";
    result << this ->model << "\n";
    result << this ->color << "\n";
    result << this ->state << "\n";
    result << this ->getCapacity() << "\n";
}

void Bike::readFromFile(std::ifstream &result) {
    result >> this -> brand;
    result >> this ->model;
    result >> this ->color;
    result >> this ->state;
    int capacity;
    result >> capacity;
    if(capacity == 0 ){
        this ->bikeBasket = nullptr;
    }
    else{
        this ->bikeBasket = new BikeBasket(capacity);
    }
}

Bike::Bike() {}


