//
// Created by Ewelina Szeliga on 17.12.2021.
//

#include "Vehicle.h"

void Vehicle::drive(double distance) {

}

void Vehicle::stop() {

}

int Vehicle::getCapacity() const {
    return capacity;
}

Vehicle::Vehicle(int capacity, Color color, CarState state = CarState::STANDING) : capacity(capacity), color(color), state(state) {}

Vehicle::Vehicle() {}

CarState Vehicle::getState() const {
    return state;
}
