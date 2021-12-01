//
// Created by Ewelina Szeliga on 28.11.2021.
//

#include "CarFactory.h"
#include "SalesDepartment.h"

CarFactory::CarFactory() {}

Car CarFactory::createCar(CarSpecification carSpecification) {

    Car newCar = Car(
            carSpecification.getBrand(),
            carSpecification.getModel(),
            carSpecification.getColor()
    );

     inventory.push_back(newCar);
     return newCar;
}

void CarFactory::leaveFactory(CarSpecification carSpecification) {
    std::vector<Car>::iterator newit;
    for(std::vector<Car>::iterator it = inventory.begin(); it != inventory.end(); ++it){
        if (carSpecification.getBrand()== (*it).getBrand() && carSpecification.getColor() == (*it).getColor() && carSpecification.getModel()== (*it).getModel()){
            newit = it;
        }
        else{
            newit = inventory.end();
        }
    }
    if (newit != inventory.end()){
        std::cout << "Element znaleziony" << std::endl;
        inventory.erase(newit);
    }
    else{
        std::cout << "Brak samochodu w fabryce." << std::endl;
    }

}


