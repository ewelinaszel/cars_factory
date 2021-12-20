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

Vehicle::Vehicle(int capacity, Color color, CarState state) : capacity(capacity), color(color), state(state) {}

Vehicle::Vehicle() {}

CarState Vehicle::getState() const {
    return state;
}
