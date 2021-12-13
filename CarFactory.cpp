//
// Created by Ewelina Szeliga on 28.11.2021.
//

#include "CarFactory.h"
#include "SalesDepartment.h"

CarFactory::CarFactory() {}

void CarFactory::createCar(CarSpecification carSpecification) {

    Car newCar = Car(
            carSpecification.getBrand(),
            carSpecification.getModel(),
            carSpecification.getColor()
    );

     inventory.push_back(newCar);
}

//usuwanie zakupionego samochodu o danej specyfikacji z inwentarza samochodów dostępnych w fabryce
Car* CarFactory::leaveFactory(CarSpecification carSpecification) {
    Car *carPointer = nullptr;
    for(std::vector<Car>::iterator it = inventory.begin(); it != inventory.end(); ++it){
        if ((*it).isInstanceOf(carSpecification)){
            carPointer = &(*it);
            inventory.erase(it);
            return carPointer;
        }
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &result, const CarFactory &carFactory) {

    if (carFactory.inventory.empty()){
        std::cout<<"Brak samochodów w fabryce"<<std::endl;
    }
    else{
        for (Car car: carFactory.inventory) {
            result<<car<<'\n';
        }
    }
    return result;
}

std::ofstream &operator<<(std::ofstream &result, const CarFactory &carFactory){
    result << carFactory.inventory.size() << "\n";
    for (Car car: carFactory.inventory) {
        result << car;
    }
    return result;
}

std::ifstream & operator >> (std::ifstream &result, CarFactory &carFactory){
    int size;
    result >> size;
    std::vector<Car> inventoryFromFile;
    for(int i=0; i<size; i++) {
        Car* car = new Car();
        result >> *car;
        inventoryFromFile.push_back(*car);
    }
    carFactory.inventory = inventoryFromFile;
    return result;
}

CarFactory::~CarFactory() {
    for(std::vector<Car>::iterator it = inventory.end(); it != inventory.begin(); --it) {
        Car* carPointer = &(*it);
        this->inventory.erase(it);
        delete carPointer;
    }
    delete &this->inventory;
}




