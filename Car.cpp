//
// Created by Ewelina Szeliga on 27.11.2021.
//

#include <iostream>
#include "Car.h"
#include "CarSpecification.h"

//przeładowanie operatora wypisywania na ekran dla enum carState
std::ostream & operator<<(std ::ostream & result ,const CarState &carState) {
    switch (carState) {
        case CarState::STANDING: 
            result << "Standing";
            break;
        case CarState::DRIVING: 
            result << "Driving";
            break;
    }
    return result;
}

std::istream & operator>>(std ::istream & result, CarState &carState) {
    std::string stateString;
    result >> stateString;
    if (stateString == "Standing") {
        carState = CarState::STANDING;
    } else if (stateString == "Driving") {
        carState = CarState::DRIVING;
    }
    return result;
}

//napełnia bak wpisaną przez użytkownika ilością paliwa
void Car::fill(int AmountOfFuel) {
    if (AmountOfFuel == 0) {
        std::cout << "Brak substancji napędowej." << std::endl;
    } else if (AmountOfFuel < 0) {
        std::cout << "Ilosc substancji napedowej nie moze byc ujemna" << std::endl;
    } else if (AmountOfFuel > 0) {
        this->amountOfFuel += AmountOfFuel;
    }
}

//jeżeli ilość paliwa jest większa niz 10 wywołuje sie metoda drive, gdzie przy każdym wywołaniu ilosc paliwa zmniejsza się o 10
void Car::drive() {
    int requiredAmountOfFuelToDrive = 10;
    if (this->state == CarState::DRIVING) {
        std::cout << "Pojazd juz jest w ruchu" << std::endl;
        return;
    }

    if (this->amountOfFuel < requiredAmountOfFuelToDrive) {
        std::cout << "Brak wystarczajacej ilosci substancji napedowej" << std::endl;
        return;
    }
    this->amountOfFuel -= requiredAmountOfFuelToDrive;
    this->state = CarState::DRIVING;
}

void Car::stop() {
    if (this->state == CarState::STANDING) {
        std::cout << "Pojazd juz jest zaparkowany" << std::endl;
        return;
    }
    this->state = CarState::STANDING;
}

Car::Car(const std::string &brand, const std::string &model, Color color, CarState state, int amountOfFuel) : brand(brand),
                                                                                                              model(model),
                                                                                                              color(color),
                                                                                                              state(state),
                                                                                                              amountOfFuel(amountOfFuel) {}
Car::Car() {}

const std::string &Car::getBrand() const {
    return brand;
}

Color Car::getColor() const {
    return color;
}

const std::string &Car::getModel() const {
    return model;
};

//sprawdzenie czy istnieje samochód o danej specyfikacji
bool Car::isInstanceOf(const CarSpecification &carSpecification) {
    return this->brand == carSpecification.getBrand() &&
           this->model == carSpecification.getModel() &&
           this->color == carSpecification.getColor();
}

//przeładowanie operatora wyświetlania na ekran
std::ostream &operator<<(std::ostream &result, const Car &car) {
    result << "Marka samochodu to:";
    result << car.brand;
    result << "\nKolor:";
    result << car.color;
    result << "\nModel samochodu:";
    result << car.model;
    result << "\nAktualna ilość paliwa wynosi:";
    result << car.amountOfFuel;
    if (car.state == CarState::DRIVING) {
        result << "\nSamochód jest w ruchu.\n";
    } else {
        result << "\nSamochód stoi.\n";
    }
    return result;
}

//przeładowania operatorów zapisu do pliku i czytania z pliku
std::ofstream &operator<<(std::ofstream &result, const Car &car) {
    result << car.brand << "\n";
    result << car.model << "\n";
    result << car.color << "\n";
    result << car.state << "\n";
    result << car.amountOfFuel << "\n";
    return result;
}

std::ifstream & operator >> (std::ifstream &result, Car &car){
    result>>car.brand;
    result>>car.model;
    result>>car.color;
    result>>car.state;
    result>>car.amountOfFuel;
    return result;
}


