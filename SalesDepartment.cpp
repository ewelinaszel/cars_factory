//
// Created by Ewelina Szeliga on 30.11.2021.
//

#include "SalesDepartment.h"
#include "CarFactory.h"

SalesDepartment::SalesDepartment() {}

SalesDepartment::SalesDepartment(const std::vector<CarSpecification> &listOfAvailableModelsOfCars,
                                 const CarFactory &carFactory) : listOfAvailableModelsOfCars(
        listOfAvailableModelsOfCars), carFactory(carFactory) {}


void SalesDepartment::orderCar(CarSpecification carSpecification) {
     this -> carFactory.createCar(carSpecification);
}

const std::vector<CarSpecification> &SalesDepartment::getListOfAvailableModelsOfCars() const {
    return listOfAvailableModelsOfCars;
}

Car* SalesDepartment::sellCar(CarSpecification carSpecification) {
    Car* car = this->carFactory.leaveFactory(carSpecification);
    if (car == nullptr) {
        this->carFactory.createCar(carSpecification);
        car = this->carFactory.leaveFactory(carSpecification);
    }
    return car;
}

const CarFactory &SalesDepartment::getCarFactory() const {
    return carFactory;
}

void SalesDepartment::setCarFactory(const CarFactory &carFactory) {
    SalesDepartment::carFactory = carFactory;
}




