//
// Created by Ewelina Szeliga on 30.11.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_SALESDEPARTMENT_H
#define SZELIGAEWELINA_ETAP1_SALESDEPARTMENT_H

#include "VehicleFactory.h"
#include <vector>

class SalesDepartment {
    std::string name;
    std::vector <VehicleSpecification*> listOfAvailableModels;
    VehicleFactory* vehicleFactory;
public:

    const std::string &getName() const;

    SalesDepartment(const std::string &name, const std::vector<VehicleSpecification*> &listOfAvailableModels,
                    VehicleFactory *vehicleFactory);

    const std::vector<VehicleSpecification *> &getListOfAvailableModels() const;

    void orderVehicle(VehicleSpecification* vehicleSpecification);

    Vehicle* sellVehicle(VehicleSpecification* vehicleSpecification);

    VehicleFactory *getVehicleFactory() const;

    void setVehicleFactory(VehicleFactory *vehicleFactory);
};


#endif //SZELIGAEWELINA_ETAP1_SALESDEPARTMENT_H
