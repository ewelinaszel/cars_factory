//
// Created by Ewelina Szeliga on 30.11.2021.
//

#include "SalesDepartment.h"
#include "CarFactory.h"

SalesDepartment::SalesDepartment() {}

SalesDepartment::SalesDepartment(const std::vector<CarSpecification> &listOfAvailableModelsOfCars,
                                 const CarFactory &carFactory) : listOfAvailableModelsOfCars(
        listOfAvailableModelsOfCars), carFactory(carFactory) {}


void SalesDepartment::orderCar(CarSpecification carspecification) {
     this -> carFactory.createCar(carspecification);
}

const std::vector<CarSpecification> &SalesDepartment::getListOfAvailableModelsOfCars() const {
    return listOfAvailableModelsOfCars;
}

//void SalesDepartment::sellcar(Car car) {
//
//}



