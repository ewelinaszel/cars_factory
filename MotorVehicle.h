//
// Created by Ewelina Szeliga on 17.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_MOTORVEHICLE_H
#define SZELIGAEWELINA_ETAP1_MOTORVEHICLE_H

#include <string>
#include "Vehicle.h"

class MotorVehicle: public Vehicle{

protected:

    int amountOfFuel;
    double fuelConsumption;
    int bootCapacity;
    int mileage;

public:
    MotorVehicle( const std::string &brand,
                  const std::string &model,
                  Color color,
                  double fuelConsumption,
                  int bootCapacity,
                  CarState state,
                  int amountOfFuel,
                  int mileage);

    MotorVehicle();

    void fill(int AmountOfFuel);

    void stop();

    void drive(double distance);

    const std::string &getBrand() const;

    const std::string &getModel() const;

    int getAmountOfFuel() const;

    double getFuelConsumption() const;

    int getMileage() const;
};


#endif //SZELIGAEWELINA_ETAP1_MOTORVEHICLE_H
