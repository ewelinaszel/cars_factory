//
// Created by Ewelina Szeliga on 27.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_USEDMOTORVEHICLEDEALER_H
#define SZELIGAEWELINA_ETAP1_USEDMOTORVEHICLEDEALER_H


#include <map>
#include "MotorVehicle.h"

class UsedMotorVehicleDealer {
    std::map<MotorVehicle*, double> availableModels;
    double margin;
    void decreaseMileage(MotorVehicle &motorVehicle);
public:
    double estimatePrice(MotorVehicle& motorVehicle);

    double buyFromOwner(MotorVehicle& motorVehicle);

    MotorVehicle* sellToClient(MotorVehicle *motorVehicle, double price);

    const std::map<MotorVehicle *, double> &getAvailableModels() const;



};


#endif //SZELIGAEWELINA_ETAP1_USEDMOTORVEHICLEDEALER_H
