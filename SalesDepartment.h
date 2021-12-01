//
// Created by Ewelina Szeliga on 30.11.2021.
//

#ifndef FABRYKA_SALESDEPARTMENT_H
#define FABRYKA_SALESDEPARTMENT_H


#include "CarSpecification.h"
#include "Car.h"
#include "CarFactory.h"
#include <vector>

class SalesDepartment {
    std::vector <CarSpecification> listOfAvailableModelsOfCars;
    CarFactory carFactory;
public:
    SalesDepartment(const std::vector<CarSpecification> &listOfAvailableModelsOfCars, const CarFactory &carFactory);

    SalesDepartment();

    const std::vector<CarSpecification> &getListOfAvailableModelsOfCars() const;

    void orderCar(CarSpecification carSpecification);

    Car sellCar(CarSpecification carSpecification);
};


#endif //FABRYKA_SALESDEPARTMENT_H
