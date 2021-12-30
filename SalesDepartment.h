//
// Created by Ewelina Szeliga on 30.11.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_SALESDEPARTMENT_H
#define SZELIGAEWELINA_ETAP1_SALESDEPARTMENT_H

#include "VehicleFactory.h"
#include <vector>

template <class T, class S>
class SalesDepartment {
    std::vector <S> listOfAvailableModels;
    VehicleFactory* vehicleFactory;
public:

    SalesDepartment();

    SalesDepartment(const std::vector<S> &listOfAvailableModels, VehicleFactory *vehicleFactory);

    const std::vector<S> &getListOfAvailableModels() const;

    void orderCar(S vehicleSpecification);

    T* sellCar(S vehicleSpecification);

    VehicleFactory *getVehicleFactory() const;

    void setVehicleFactory(VehicleFactory *vehicleFactory);
};


#endif //SZELIGAEWELINA_ETAP1_SALESDEPARTMENT_H
