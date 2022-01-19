//
// Created by Ewelina Szeliga on 27.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP2_MOTORBIKEFACTORY_H
#define SZELIGAEWELINA_ETAP2_MOTORBIKEFACTORY_H


#include "VehicleFactory.h"
#include "Motorbike.h"

class MotorbikeFactory : public VehicleFactory {
protected:
    Vehicle* createDummyVehicle() override { return new Motorbike(); };
    std::string getType() const override { return "Fabryka motocykli"; };


public:
    void createVehicle(VehicleSpecification *vehicleSpecification) override;
};


#endif //SZELIGAEWELINA_ETAP2_MOTORBIKEFACTORY_H
