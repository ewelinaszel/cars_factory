//
// Created by Ewelina Szeliga on 17.12.2021.
//

#include "Vehicle.h"

std::ostream &operator<<(std::ostream &result, const VehicleState &carState) {
    switch (carState) {
        case VehicleState::STANDING:
            result << "Standing";
            break;
        case VehicleState::DRIVING:
            result << "Driving";
            break;
    }
    return result;
}

std::istream &operator>>(std::istream &result, VehicleState &carState) {
    std::string stateString;
    result >> stateString;
    if (stateString == "Standing") {
        carState = VehicleState::STANDING;
    } else if (stateString == "Driving") {
        carState = VehicleState::DRIVING;
    }
    return result;
}


Vehicle::Vehicle() {}

VehicleState Vehicle::getState() const {
    return state;
}

Vehicle::Vehicle(const std::string &brand, const std::string &model, Color color, VehicleState state) : brand(
        brand), model(model), state(state), color(color) {}

Vehicle::~Vehicle() {

}

const std::string &Vehicle::getBrand() const {
    return brand;
}

const std::string &Vehicle::getModel() const {
    return model;
}

Color Vehicle::getColor() const {
    return color;
}

void Vehicle::setColor(Color color) {
    Vehicle::color = color;
}

std::ostream &operator << (std::ostream &result, const Vehicle &vehicle) {
    vehicle.print(result);
    return result;
}

std::ofstream &operator << (std::ofstream &result, const Vehicle &vehicle){
    vehicle.writeToFile(result);
    return result;
}

std::ifstream &operator >> (std::ifstream &result, Vehicle &vehicle){
    vehicle.readFromFile(result);
    return result;
}



