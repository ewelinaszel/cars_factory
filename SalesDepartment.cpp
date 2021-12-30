//
// Created by Ewelina Szeliga on 30.11.2021.
//

#include "SalesDepartment.h"
#include "CarFactory.h"

template <class T, class S>
SalesDepartment<T, S>::SalesDepartment() {}

template <class T, class S>
SalesDepartment<T, S>::SalesDepartment(const std::vector<S> &listOfAvailableModels,
                                    VehicleFactory *vehicleFactory):listOfAvailableModels(listOfAvailableModels),
                                                                    vehicleFactory(vehicleFactory) {}


template <class T, class S>
void SalesDepartment<T, S>::orderCar(S vehicleSpecification) {
     this -> vehicleFactory -> createVehicle(&vehicleSpecification);
}

template <class T, class S>
const std::vector<S> &SalesDepartment<T, S>::getListOfAvailableModels() const {
    return listOfAvailableModels;
}

template <class T, class S>
T* SalesDepartment<T, S>::sellCar(S vehicleSpecification) {
    Vehicle* vehicle = this -> vehicleFactory -> leaveFactory(&vehicleSpecification);
    if (vehicle == nullptr) {
        this->vehicleFactory -> createVehicle(&vehicleSpecification);
        vehicle = this->vehicleFactory -> leaveFactory(&vehicleSpecification);
    }
    T* result = dynamic_cast<T*>(vehicle);
    return result;
}

template <class T, class S>
VehicleFactory *SalesDepartment<T, S>::getVehicleFactory() const {
    return vehicleFactory;
}

template<class T, class S>
void SalesDepartment<T, S>::setVehicleFactory(VehicleFactory *vehicleFactory) {
    SalesDepartment::vehicleFactory = vehicleFactory;
}




