//
// Created by Ewelina Szeliga on 17.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_VEHICLE_H
#define SZELIGAEWELINA_ETAP1_VEHICLE_H

#include "CarSpecification.h"

enum class CarState {
    DRIVING,
    STANDING
};
std::ostream & operator<<(std ::ostream & result ,const CarState &carState);
std::istream &operator>>(std::istream &result, CarState &carState);

class Vehicle {
protected:
    std::string brand;
    std::string model;
    Color color;
    CarState state;
public:
    explicit Vehicle();

    explicit Vehicle(const std::string &brand, const std::string &model, Color color, CarState state);

    virtual ~Vehicle();

    CarState getState() const;

    virtual int getCapacity() const = 0;

    virtual void stop()=0;

    virtual void drive(double distance)=0;

    void setColor(Color color);

    const std::string &getBrand() const;

    const std::string &getModel() const;

    Color getColor() const;

    virtual bool isInstanceOf(VehicleSpecification *vehicleSpecification) = 0; //?czy const

    virtual void print(std::ostream &result) const = 0;

    friend std::ostream & operator << (std ::ostream & result ,const Vehicle &vehicle);

    friend std::ofstream &operator << (std::ofstream & result, const Vehicle &vehicle);

    friend std::ifstream &operator >> (std::ifstream &result, Vehicle &vehicle);

    virtual void writeToFile(std::ofstream &result) const = 0;

    virtual void readFromFile(std::ifstream &result) = 0;

    virtual std::string shortString() const = 0;


};


#endif //SZELIGAEWELINA_ETAP1_VEHICLE_H
/*
-------------------------------------
[0] Pokaż menu
[1] Wypisz listę modeli samochodów
[2] Wybierz samochód, który chcesz aby wyprodukowano
[3] Kup samochód
[4] Wypisz fabrykę *
[5] Wypisz mój aktualny samochód
[6] Jedziemy! *
[7] Zatrzymaj się! *
[8] Tankuj! *
[9] Zapisz fabrykę do pliku
[10] Zapisz mój samochód do pliku
[11] Wczytaj fabrykę z pliku
[12] Wczytaj mój samochód z pliku

        Co może uzytkownik
1) Zobaczyć listę dostępnych modeli w danym salonie
2) Zlecić skonstruowanie nowego samochodu
3) Zakupić nowy samochód/motor/rower z salonu
4) Posiada własne autko, którym może się carnąć:
    ruszyć
        zatrzymać
    zatankować
5) Odsprzedać aktualnie posiadany samochód do wybranego komisu.
6) Kupić samochód z komisu.
7) Może przelakierować swój samochód.


Opcje administracyjne:
8 Wypisz fabrykę
9 Wypisz mój aktualny samochód
10 Zapisz fabrykę do pliku
11 Zapisz mój samochód do pliku
12 Wczytaj fabrykę z pliku
13 Wczytaj mój samochód z pliku
14 Stworzyć nową fabrykę
15 Stworzyć nowy komis
16 Wczytać całą konfiguracje z pliku :D (to byłoby ciekawe)


Może jakieś CLI wielopoziomowe?
Wejdź do fabryki/komisu/lakiernika/samochodu
*/



/*
 MENU GŁOWNE:
    [0] Wyjdź
    [1] Idź do ...  (możliwe przejscie do MENU SALONU, KOMISU, LAKIERNIKA, SAMOCHODU, MOTORU, ROWERU)
    [2] Opcje administaracyjne (admin mode)
    [_] Wypisz moje pojazdy (opcjonalne)

 Wybierz dokąd chcesz się udać:
     [1] Salon samochodowy SzeligaMotors
     [2] Salon Rowerów SuperBikes
     [3] Komis samochodowy KrecimPrzebiegi
     [4] Lakiernik JedynyWTymKraju
     [5] Mój samochód
     [6] Mój rower
     [7] Mój motor

 MENU SALONU:
    [0] Wyjdź
    [1] Wypisz listę modeli samochodów
    [2] Wybierz samochód, który chcesz aby wyprodukowano
    [3] Kup samochód
    [4] Wypisz stan fabryki
    [5] Zapisz fabrykę do pliku
    [6] Wczytaj fabrykę z pliku

 MENU KOMISU:
    [0] Wyjdź
    [1] Wyceń mój pojazd (...silnikowy
    [2] Sprzedaj mój pojazd silnikowy
    [3] Wypisz listę dostęnych pojazdów silnikowych
    [4] Kup pojazd silnikowy

 MENU LAKIERNIKA:
    [0] Wyjdź
    [1] Zmień kolor mojego pojazdu

 MENU SAMOCHODU:
    [0] Wyjdź
    [1] Wypisz aktualny stan
    [2] Jedziemy! *
    [3] Zatrzymaj się! *
    [4] Tankuj! *

 MENU MOTORU:
    [0] Wyjdź
    [1] Wypisz aktualny stan
    [2] Jedziemy! *
    [3] Zatrzymaj się! *
    [4] Tankuj! *

 MENU ROWERU:
    [0] Wyjdź
    [1] Wypisz aktualny stan
    [2] Jedziemy! *
    [3] Zatrzymaj się! *

 MENU ADMINISTRACYJNE:
    [0] Wyjdź
    [1] Zapisz mój samochód do pliku
    [2] Zapisz mój rower do pliku
    [3] Zapisz mój motor do pliku
    [4] Wczytaj mój samochód z pliku
    [5] Wczytaj mój rower z pliku
    [6] Wczytaj mój motor z pliku

    [7] Stworzyć nowy salon
    [8] Stworzyć nowy komis
    [9] Wczytać całą konfiguracje z pliku :D (to byłoby ciekawe)

    [10] Wypisz stan wszystkich fabryke (opcjonalne)
    [11] ...



*/