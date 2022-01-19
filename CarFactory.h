//
// Created by Ewelina Szeliga on 28.11.2021.
//

#ifndef SZELIGAEWELINA_ETAP2_CARFACTORY_H
#define SZELIGAEWELINA_ETAP2_CARFACTORY_H


#include <vector>
#include "Car.h"
#include "VehicleFactory.h"
class CarFactory: public VehicleFactory{
protected:
    Vehicle* createDummyVehicle() override { return new Car(); };
    std::string getType() const override { return "Fabryka samochodów"; };

public:
    CarFactory();

    void createVehicle(VehicleSpecification *vehicleSpecification) override;
};

#endif //SZELIGAEWELINA_ETAP2_CARFACTORY_H
