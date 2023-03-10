//
// Created by Ewelina Szeliga on 27.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP2_VEHICLEFACTORY_H
#define SZELIGAEWELINA_ETAP2_VEHICLEFACTORY_H


#include <vector>
#include "Vehicle.h"
#include <iostream>
#include <fstream>

class VehicleFactory {
protected:
    std::vector<Vehicle *> inventory;
    virtual Vehicle* createDummyVehicle() = 0;
    virtual std::string getType() const = 0;
public:

    VehicleFactory();

    virtual ~VehicleFactory();

    virtual void createVehicle(VehicleSpecification *vehicleSpecification) = 0;

    virtual Vehicle *leaveFactory(VehicleSpecification *vehicleSpecification);

    friend std::ostream &operator<<(std::ostream &result, const VehicleFactory &carFactory);

    friend std::ofstream &operator<<(std::ofstream &result, const VehicleFactory &carFactory);

    friend std::ifstream & operator >> (std::ifstream &result, VehicleFactory &carFactory);

};


#endif //SZELIGAEWELINA_ETAP2_VEHICLEFACTORY_H
