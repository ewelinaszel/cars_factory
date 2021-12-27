//
// Created by Ewelina Szeliga on 27.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_MOTORBIKEFACTORY_H
#define SZELIGAEWELINA_ETAP1_MOTORBIKEFACTORY_H


#include "VehicleFactory.h"

class MotorbikeFactory : public VehicleFactory {
public:
    void createVehicle(VehicleSpecification *vehicleSpecification) override;
};


#endif //SZELIGAEWELINA_ETAP1_MOTORBIKEFACTORY_H
