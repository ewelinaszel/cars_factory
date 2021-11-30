#include <iostream>
#include "Car.h"

void showMenu() {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Wybierz interesującą Cię opcje:" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "[1] Wypisz listę modeli samochodów" << std::endl;
    std::cout << "[2] Kup samochód" << std::endl;
    std::cout << "[3] Odbierz samochód" << std::endl;
    std::cout << "[4] Wypisz fabrykę (wypisz obecny stan fabryki - prawdopodobnie listę pojazdów wyprodukowanych)" << std::endl;
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

int main() {

    //trzeba zbudować całą strukturę obietków...
    // potrzebna jest zmienna przechowująca aktualny samochód
    //

    Car newcar = {"BMW", "A4", Color::BLACK};
    std::cout << "Witaj w fabryce samochodów SzeligaMotors!" << std::endl;
    while(true) {
        showMenu();
        int commandNumber = getCommandFromConsole();
        switch (commandNumber) {
            case 1:
                std::cout << "Wybrano: " << 1 << std::endl;
                std::cout<<newcar;
                break;
            case 2:
                std::cout << "Wybrano: " << 2 << std::endl;
                break;
            case 3:
                std::cout << "Wybrano: " << 3 << std::endl;
                break;
            case 4:
                std::cout << "Wybrano: " << 4 << std::endl;
                break;
            case 5:
                std::cout << "Wybrano: " << 5 << std::endl;
                break;
            case 6:
                std::cout << "Wybrano: " << 6 << std::endl;
                break;
            case 7:
                std::cout << "Wybrano: " << 7 << std::endl;
                break;
            case 8:
                std::cout << "Wybrano: " << 8 << std::endl;
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