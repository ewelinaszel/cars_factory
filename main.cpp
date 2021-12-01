#include <iostream>
#include <deque>
#include "Car.h"
#include "SalesDepartment.h"
//
//std::ostream &operator<<(std::ostream &output_stream, Car car) {
//    output_stream << car.getBrand() << "" << car.getModel() << "" << car.getColor();
//    return output_stream;
//}
//
//std::istream &operator>>(std::istream &input_stream, Car car) {
//    input_stream >> car.getBrand() >> "" << car.getModel() >> "" << car.getColor();
//    return input_stream;
//}

void showMenu() {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Wybierz interesującą Cię opcje:" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "[1] Wypisz listę modeli samochodów" << std::endl;
    std::cout << "[2] Wybierz samochód, który chcesz aby wyprodukowano:" << std::endl;
    std::cout << "[3] Kup samochód" << std::endl;
    std::cout << "[4] Wypisz fabrykę (wypisz obecny stan fabryki - prawdopodobnie listę pojazdów wyprodukowanych)"
              << std::endl;
    std::cout << "[5] Wypisz mój aktualny samochód" << std::endl;
    std::cout << "[6] Jedziemy!" << std::endl;
    std::cout << "[7] Zatrzymaj się!" << std::endl;
    std::cout << "[8] Tankuj!" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}

int getCommandFromConsole() {
    int i;
    std::cout << "Podaj numer opcji: ";
    std::cin >> i;
//    todo check if get correct i (np. >0)
    return i;
}

void writeToFile(Car car);

int main() {

    //trzeba zbudować całą strukturę obietków...
    CarSpecification specification1{"BMW", "Seria 3", Color::BLACK};
    CarSpecification specification2{"Mercedes-Benz", "E klasa", Color::WHITE};
    CarSpecification specification3{"Audi", "A4", Color::SILVER};
    CarSpecification specification4{"Chevrolet", "Captiva", Color::GOLD};

    CarFactory carFactory;
    SalesDepartment salesDepartment{
            std::vector<CarSpecification>{specification1, specification2, specification3, specification4}, carFactory};

    Car *currentCar = nullptr;


    std::cout << "Witaj w fabryce samochodów SzeligaMotors!" << std::endl;
    while (true) {
        showMenu();
        int commandNumber = getCommandFromConsole();
        switch (commandNumber) {
            case 1: {
//                std::cout << "Wybrano: " << 1 << std::endl;
                std::vector<CarSpecification> availableCarSpecifications = salesDepartment.getListOfAvailableModelsOfCars();
                for (std::vector<CarSpecification>::iterator it = availableCarSpecifications.begin();
                     it != availableCarSpecifications.end(); ++it) {
                    std::cout << *it << std::endl;
                }
                break;
            }
            case 2: {
//                std::cout << "Wybrano: " << 2 << std::endl;
                std::cout << "Podaj index: ";
                int i;
                std::cin >> i;
                CarSpecification chosenCarSpecification = salesDepartment.getListOfAvailableModelsOfCars().at(i);
                salesDepartment.orderCar(chosenCarSpecification);
                break;
            }
            case 3: {
//                std::cout << "Wybrano: " << 2 << std::endl;
                std::cout << "Podaj index: ";
                int i;
                std::cin >> i;
                CarSpecification chosenCarSpecification = salesDepartment.getListOfAvailableModelsOfCars().at(i);
                *currentCar = salesDepartment.sellCar(chosenCarSpecification);
                break;
            }
            case 4:
                std::cout << "Wybrano: " << 4 << std::endl;
                break;
            case 5:
                std::cout << "Wybrano: " << 5 << std::endl;
                std::cout << currentCar;
                break;
            case 6:
                std::cout << "Wybrano: " << 6 << std::endl;
                if(currentCar == nullptr) {
                    std::cout << "Nie posiadasz samochodu!" << std::endl;
                }
                currentCar->drive();
                break;
            case 7:
                std::cout << "Wybrano: " << 7 << std::endl;
                if(currentCar == nullptr) {
                    std::cout << "Nie posiadasz samochodu!" << std::endl;
                }
                currentCar->stop();
                break;
            case 8:
                std::cout << "Wybrano: " << 8 << std::endl;
                if(currentCar == nullptr) {
                    std::cout << "Nie posiadasz samochodu!" << std::endl;
                }
                int amountofFuel;
                std::cout << "Podaj ilość substancji napędowej:" << std::endl;
                std::cin >> amountofFuel;
                currentCar->fill(amountofFuel);
                break;
            default:
                std::cout << "Opcja o podanym numerze nie istnieje" << std::endl;
        }
    }


    /*Wybierz opcje:
     * [1] Wypisz listę modeli samochodów
     *     1. Bmw seria 3 2.0 benzyna L +klima
     *     2. Audi A4 1.8T beznyna M
     *     3. Bentley Azuro 3.2 benzyna + LPG XXL +barek pełen procentów
     * [2] Kup samochód
     *     podaj numer: ___ 3
     *     xxx56
     * [3] Odbierz samochód
     *     podaj numer seryjny: ___  xxx56
     * [4] Wypisz fabrykę (wypisz obecny stan fabryki - prawdopodobnie listę pojazdów wyprodukowanych)
     * [5] Wypisz mój aktualny samochód
     * [6] Jedziemy!
     * [7] Zatrzymaj się!
     * [8] Tankuj!
     *
     * */


    return 0;
}
//
//void writeToFile(Car car) {
//    std::string nameOfFile{temptext.txt};
//    std::ofstream stream(nameOfFile);
//    if (!stream) {
//        std::cout << ("Blad otwarcia pliku do zapisu");
//    } else {
//        stream << car;
//
//    }
//
//};
