//
// Created by Ewelina Szeliga on 28.11.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_CARFACTORY_H
#define SZELIGAEWELINA_ETAP1_CARFACTORY_H


#include <vector>
#include "Car.h"
#include "VehicleFactory.h"
class CarFactory: public VehicleFactory{
public:
    CarFactory();

    void createVehicle(VehicleSpecification *vehicleSpecification) override;
};

#endif //SZELIGAEWELINA_ETAP1_CARFACTORY_H
