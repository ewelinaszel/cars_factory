//
// Created by Ewelina Szeliga on 17.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP2_MOTORVEHICLE_H
#define SZELIGAEWELINA_ETAP2_MOTORVEHICLE_H

#include <string>
#include "Vehicle.h"

class MotorVehicle: public Vehicle{

protected:

    int amountOfFuel;
    double fuelConsumption;
    int bootCapacity;
    int mileage;

public:
    explicit MotorVehicle(const std::string &brand,
                          const std::string &model,
                          Color color,
                          double fuelConsumption,
                          int bootCapacity,
                          VehicleState state,
                          int amountOfFuel,
                          int mileage);

    explicit MotorVehicle();

    virtual ~MotorVehicle();

    void fill(int AmountOfFuel);

    int getAmountOfFuel() const;

    double getFuelConsumption() const;

    int getMileage() const;

    void setMileage(int mileage);

    void stop() override;

    void drive(double distance) override;
};


#endif //SZELIGAEWELINA_ETAP2_MOTORVEHICLE_H
