//
// Created by Ewelina Szeliga on 30.11.2021.
//

#include "SalesDepartment.h"


SalesDepartment::SalesDepartment(const std::string &name, const std::vector<VehicleSpecification*> &listOfAvailableModels,
                                       VehicleFactory *vehicleFactory):name(name),
                                                                       listOfAvailableModels(listOfAvailableModels),
                                                                       vehicleFactory(vehicleFactory) {}

void SalesDepartment::orderVehicle(VehicleSpecification* vehicleSpecification) {
    this->vehicleFactory->createVehicle(vehicleSpecification);
}

Vehicle* SalesDepartment::sellVehicle(VehicleSpecification* vehicleSpecification) {
    Vehicle* vehicle = this -> vehicleFactory -> leaveFactory(vehicleSpecification);
    if (vehicle == nullptr) {
        this->vehicleFactory->createVehicle(vehicleSpecification);
        vehicle = this->vehicleFactory -> leaveFactory(vehicleSpecification);
    }
    return vehicle;
}

VehicleFactory *SalesDepartment::getVehicleFactory() const {
    return vehicleFactory;
}

void SalesDepartment::setVehicleFactory(VehicleFactory *vehicleFactory) {
    SalesDepartment::vehicleFactory = vehicleFactory;
}

const std::string &SalesDepartment::getName() const {
    return name;
}

const std::vector<VehicleSpecification *> &SalesDepartment::getListOfAvailableModels() const {
    return listOfAvailableModels;
}




