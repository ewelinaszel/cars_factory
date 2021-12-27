//
// Created by Ewelina Szeliga on 27.12.2021.
//

#include "VehicleFactory.h"

//usuwanie zakupionego samochodu o danej specyfikacji z inwentarza samochodów dostępnych w fabryce
Vehicle* VehicleFactory::leaveFactory(VehicleSpecification *vehicleSpecification) {
    Vehicle *vehiclePointer = nullptr;
    for(std::vector<Vehicle*>::iterator it = inventory.begin(); it != inventory.end(); ++it){
        if ((*it)->isInstanceOf(vehicleSpecification)){
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

//todo przywrócić operatory zapisu i odczytu z pliku dla fabryki
std::ostream &operator<<(std::ostream &result, const VehicleFactory &carFactory) {

//    if (carFactory.inventory.empty()){
//        std::cout<<"Brak samochodów w fabryce"<<std::endl;
//    }
//    else{
//        for (Car* car: carFactory.inventory) {
//            result<<*car<<'\n';
//        }
//    }
    return result;
}

std::ofstream &operator<<(std::ofstream &result, const VehicleFactory &vehicleFactory){
//    result << vehicleFactory.inventory.size() << "\n";
//    for (Vehicle* car: vehicleFactory.inventory) {
//        result << car;
//    }
    return result;
}

std::ifstream & operator >> (std::ifstream &result, VehicleFactory &carFactory){
//    int size;
//    result >> size;
//    std::vector<Vehicle*> inventoryFromFile;
//    for(int i=0; i<size; i++) {
//        Vehicle* vehicle = new Vehicle();
//        result >> *vehicle;
//        inventoryFromFile.push_back(vehicle);
//    }
//    carFactory.inventory = inventoryFromFile;
    return result;
}

VehicleFactory::VehicleFactory() {}
