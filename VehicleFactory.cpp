//
// Created by Ewelina Szeliga on 27.12.2021.
//

#include "VehicleFactory.h"

//usuwanie zakupionego pojazdu o danej specyfikacji z inwentarza samochodów dostępnych w fabryce
Vehicle *VehicleFactory::leaveFactory(VehicleSpecification *vehicleSpecification) {
    Vehicle *vehiclePointer = nullptr;
    for (std::vector<Vehicle *>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
        if ((*it)->isInstanceOf(vehicleSpecification)) {
            vehiclePointer = *it;
            inventory.erase(it);
            return vehiclePointer;
        }
    }
    return nullptr;
}

VehicleFactory::~VehicleFactory() {
    for (std::vector<Vehicle *>::iterator it = inventory.end(); it != inventory.begin(); --it) {
        Vehicle *vehiclePointer = *it;
        this->inventory.erase(it);
        delete vehiclePointer;
    }
    delete &this->inventory;
}

std::ostream &operator<<(std::ostream &result, const VehicleFactory &vehicleFactory) {
    if (vehicleFactory.inventory.empty()) {
        result << "Brak pojazdów w fabryce" << std::endl;
    } else {
        result << vehicleFactory.getType() << ":";
        for (Vehicle *vehicle: vehicleFactory.inventory) {
            result << '\n' << *vehicle;
        }
    }
    return result;
}

std::ofstream &operator<<(std::ofstream &result, const VehicleFactory &vehicleFactory) {
    result << vehicleFactory.getType() << ":\n";
    result << vehicleFactory.inventory.size() << "\n";
    for (Vehicle *vehicle: vehicleFactory.inventory) {
        result << *vehicle;
    }
    return result;
}

std::ifstream &operator>>(std::ifstream &result, VehicleFactory &vehicleFactory) {
    int size;
    result >> size;
    std::vector<Vehicle *> inventoryFromFile;
    for (int i = 0; i < size; i++) {
        Vehicle *vehicle = vehicleFactory.createDummyVehicle();
        //tmp exists only to skip vehicle type
        std::string tmp;
        result >> tmp;
        result >> *vehicle;
        inventoryFromFile.push_back(vehicle);
    }
    vehicleFactory.inventory = inventoryFromFile;
    return result;
}

VehicleFactory::VehicleFactory() {}
