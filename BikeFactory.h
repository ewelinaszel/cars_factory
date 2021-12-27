//
// Created by Ewelina Szeliga on 27.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_BIKEFACTORY_H
#define SZELIGAEWELINA_ETAP1_BIKEFACTORY_H


#include "VehicleFactory.h"

class BikeFactory : public VehicleFactory{

public:
    BikeFactory();

    void createVehicle(VehicleSpecification *vehicleSpecification) override;
};


#endif //SZELIGAEWELINA_ETAP1_BIKEFACTORY_H
