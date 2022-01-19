//
// Created by Ewelina Szeliga on 27.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP2_USEDMOTORVEHICLEDEALER_H
#define SZELIGAEWELINA_ETAP2_USEDMOTORVEHICLEDEALER_H


#include <map>
#include "MotorVehicle.h"

template<class T>
class UsedMotorVehicleDealer {
    std::string name;
    std::map<T*, double> availableModels;
    double margin;
    void decreaseMileage(T &motorVehicle);

public:
    UsedMotorVehicleDealer(const std::string &name, const std::map<T *, double> &availableModels,
                           double margin);

    double estimatePrice(MotorVehicle& motorVehicle);

    double buyFromOwner(MotorVehicle& motorVehicle);

    T* sellToClient(T *motorVehicle, double price);

    const std::map<T *, double> &getAvailableModels() const;

    const std::string &getName() const;

};


#endif //SZELIGAEWELINA_ETAP2_USEDMOTORVEHICLEDEALER_H
