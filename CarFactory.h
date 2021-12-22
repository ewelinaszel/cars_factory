//
// Created by Ewelina Szeliga on 28.11.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_CARFACTORY_H
#define SZELIGAEWELINA_ETAP1_CARFACTORY_H


#include <vector>
#include "Car.h"

class CarFactory {
    std::vector <Car*> inventory;
public:
    CarFactory();

    ~CarFactory();

    void createCar(const CarSpecification carSpecification);

    Car* leaveFactory(const CarSpecification carSpecification);

    friend std::ostream &operator<<(std::ostream &result, const CarFactory &carFactory);
    friend std::ofstream &operator<<(std::ofstream &result, const CarFactory &carFactory);
    friend std::ifstream & operator >> (std::ifstream &result, CarFactory &carFactory);
};

#endif //SZELIGAEWELINA_ETAP1_CARFACTORY_H
