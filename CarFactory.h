//
// Created by Ewelina Szeliga on 28.11.2021.
//

#ifndef FABRYKA_CARFACTORY_H
#define FABRYKA_CARFACTORY_H


#include <vector>
#include "Car.h"

class CarFactory {
    std::vector <Car> inventory;
public:
    CarFactory();

    void createCar(const CarSpecification carSpecification);

    Car* leaveFactory(const CarSpecification carSpecification);

};

/*todo: 1. Usunąć produced cars z car factory
        2. Inventory powinno zawierać cars zamiast specyfikacji (klasa SalesDepartment)
        3. Dodać pole id do samochodu typu string
        4. Dodać nazwę fabryki do carfactory jako pole
        5. Dodać pole które tzryma ostatnie nadane id
        6. Id samochodu to zlepek nazwy fabryki i liczba, ma być nadawany w metodzie createcar

*/
#endif //FABRYKA_CARFACTORY_H
