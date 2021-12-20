//
// Created by Ewelina Szeliga on 17.12.2021.
//

#include "Vehicle.h"

std::ostream &operator<<(std::ostream &result, const CarState &carState) {
    switch (carState) {
        case CarState::STANDING:
            result << "Standing";
            break;
        case CarState::DRIVING:
            result << "Driving";
            break;
    }
    return result;
}

std::istream &operator>>(std::istream &result, CarState &carState) {
    std::string stateString;
    result >> stateString;
    if (stateString == "Standing") {
        carState = CarState::STANDING;
    } else if (stateString == "Driving") {
        carState = CarState::DRIVING;
    }
    return result;
}

int Vehicle::getCapacity() const {
    return capacity;
}


Vehicle::Vehicle() {}

CarState Vehicle::getState() const {
    return state;
}

Vehicle::Vehicle(const std::string &brand, const std::string &model, int capacity, Color color, CarState state) : brand(
        brand), model(model), capacity(capacity), state(state), color(color) {}
