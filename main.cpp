#include <iostream>
#include <deque>
#include "SalesDepartment.h"
#include "Car.h"
#include "CarFactory.h"
#include "Bike.h"
#include "UsedMotorVehicleDealer.h"
#include "Sprayer.h"
#include "BikeFactory.h"
#include "Motorbike.h"
#include "MotorbikeFactory.h"
#include "BikeSpecification.h"

std::string LINE_PREFIX = "  ";


//****************************************************
//             CREATE UICONTEXT
//****************************************************

struct UIContext {
    std::vector<SalesDepartment *> salesDepartments;
    std::vector<UsedMotorVehicleDealer *> usedMotorVehicleDealers;

    MotorVehicle *currentMotorVehicle;
    Bike *currentBike;

    //Where we are:
    SalesDepartment *currentSalesDepartment = nullptr;
    UsedMotorVehicleDealer *currentMotorVehiclesDealer = nullptr;
};


UIContext createUIContext() {
    CarSpecification *specification1 = new CarSpecification{"BMW", "Seria-3", Color::BLACK, 12.0, 150};
    CarSpecification *specification2 = new CarSpecification{"Mercedes-Benz", "E-klasa", Color::WHITE, 12.5, 160};
    CarSpecification *specification3 = new CarSpecification{"Audi", "A4", Color::SILVER, 9.0, 155};
    CarSpecification *specification4 = new CarSpecification{"Chevrolet", "Captiva", Color::GOLD, 12.0, 360};
    MotorbikeSpecification *motorbikeSpecification1 = new MotorbikeSpecification{"Harley", "Davidson", Color::BLACK,
                                                                                 7.2, 2};
    MotorbikeSpecification *motorbikeSpecification2 = new MotorbikeSpecification{"Yamaha", "R1", Color::SILVER, 6.5, 1};
    MotorbikeSpecification *motorbikeSpecification3 = new MotorbikeSpecification{"BMW", "RT", Color::RED, 5.8, 3};
    BikeSpecification *bikeSpecification1 = new BikeSpecification{"Romet", "Orkan", Color::SILVER, 3};
    BikeSpecification *bikeSpecification2 = new BikeSpecification{"Cross", "Hexagon", Color::WHITE, 0};

    SalesDepartment *salesDepartment1 = new SalesDepartment{
            "Salon samochodowy -  Szeliga Motors Dealer",
            std::vector<VehicleSpecification *>{specification1, specification2, specification3, specification4},
            new CarFactory{}};
    SalesDepartment *salesDepartment2 = new SalesDepartment{
            "Salon samochodowy - Gładysz Tarnów",
            std::vector<VehicleSpecification *>{specification1, specification2, specification3, specification4},
            new CarFactory{}};
    SalesDepartment *salesDepartment3 = new SalesDepartment{
            "Salon rowerowy - MyBike Dealer",
            std::vector<VehicleSpecification *>{bikeSpecification1, bikeSpecification2},
            new BikeFactory{}};
    SalesDepartment *salesDepartment4 = new SalesDepartment{
            "Salon motocyklowy - MotoLand",
            std::vector<VehicleSpecification *>{motorbikeSpecification1, motorbikeSpecification2,
                                                motorbikeSpecification3},
            new MotorbikeFactory{}};


    UsedMotorVehicleDealer *usedMotorVehicleDealer1 = new UsedMotorVehicleDealer("KomisKowalski",
                                                                                 std::map<MotorVehicle *, double>(),
                                                                                 0.2);
    UIContext uiContext;
    uiContext.salesDepartments.push_back(salesDepartment1);
    uiContext.salesDepartments.push_back(salesDepartment2);
    uiContext.salesDepartments.push_back(salesDepartment3);
    uiContext.salesDepartments.push_back(salesDepartment4);
    uiContext.usedMotorVehicleDealers.push_back(usedMotorVehicleDealer1);
    uiContext.currentMotorVehicle = nullptr;
    uiContext.currentBike = nullptr;
    return uiContext;
}

//****************************************************
//             METHODS IMPLEMENTING UI LOGIC
//****************************************************

int getCommandFromConsole(std::istream *inputStream) {
    int i;
    std::cout << "\nPodaj numer opcji: ";
    *inputStream >> i;
    return i;
}

bool checkIfCurrentMotorVehicleNullptr(UIContext &uiContext) {
    if (uiContext.currentMotorVehicle == nullptr) {
        std::cout << "Nie posiadasz aktualnie pojazdu silnikowego" << std::endl;
        return true;
    }
    return false;
}

void showVehicleList(SalesDepartment *currentSalesDepartment) {
    std::vector<VehicleSpecification *> availableCarSpecifications = currentSalesDepartment->getListOfAvailableModels();

    if (availableCarSpecifications.empty()) {
        std::cout << LINE_PREFIX << "Salon nie posiada obecnie żadnych modeli możliwych do zamówienia" << std::endl;
        return;
    }
    int i = 0;
    for (std::vector<VehicleSpecification *>::iterator it = availableCarSpecifications.begin();
         it != availableCarSpecifications.end(); ++it) {
        std::cout << LINE_PREFIX << "[" << ++i << "] " << *it << std::endl;
    }
}

void produceVehicle(SalesDepartment *currentSalesDepartment, std::istream *inputStream) {
    std::cout << "Podaj index: ";
    int i;
    *inputStream >> i;

    try {
        VehicleSpecification *chosenVehicleSpecification = currentSalesDepartment->getListOfAvailableModels().at(i - 1);
        currentSalesDepartment->orderVehicle(chosenVehicleSpecification);
    }
    catch (const std::out_of_range &oor) {
        int n = currentSalesDepartment->getListOfAvailableModels().size();
        std::cout << LINE_PREFIX << "Niepoprawny numer specyfikacji " << i
                  << ". Index powinien mieścić się w zakresie [1, " << n << "]" << std::endl;
    }
}

void buyVehicle(UIContext &uiContext, std::istream *inputStream) {
    std::cout << "Podaj index: ";
    int i;
    *inputStream >> i;

    try {
        VehicleSpecification *chosenVehicleSpecification = uiContext.currentSalesDepartment->getListOfAvailableModels().at(
                i - 1);
        Vehicle *producedVehicle = uiContext.currentSalesDepartment->sellVehicle(chosenVehicleSpecification);
        //na pewno wyprodukowany pojazd jest Rowerem albo Pojazdem silnikowym - jedna z konwersji zwróci nullptr
        uiContext.currentMotorVehicle = dynamic_cast<MotorVehicle *>(producedVehicle);
        uiContext.currentBike = dynamic_cast<Bike *>(producedVehicle);
    }
    catch (const std::out_of_range &oor) {
        int n = uiContext.currentSalesDepartment->getListOfAvailableModels().size();
        std::cout << LINE_PREFIX << "Niepoprawny numer specyfikacji " << i
                  << ". Index powinien mieścić się w zakresie [1, " << n << "]" << std::endl;
    }
}

void startMyVehicle(Vehicle *vehicle, std::istream *inputStream) {
    double distance;
    std::cout << "Podaj ilość kilometrów do przejechania: " << std::endl;
    *inputStream >> distance;
    if (vehicle == nullptr) {
        std::cout << "Nie posiadasz aktualnie pojazdu" << std::endl;
    }
    try {
        vehicle->drive(distance);
    }
    catch (std::runtime_error &re) {
        std::cout << re.what() << std::endl;
    }
}

void stopMyVehicle(Vehicle *vehicle) {
    if (vehicle == nullptr) {
        std::cout << "Nie posiadasz aktualnie pojazdu" << std::endl;
    }
    try {
        vehicle->stop();
    }
    catch (std::runtime_error &re) {
        std::cout << re.what() << std::endl;
    }
}

void fillMyMotorVehicle(MotorVehicle *motorVehicle, std::istream *inputStream) {
    if (motorVehicle == nullptr) {
        std::cout << "Nie posiadasz aktualnie pojazdu silnikowego" << std::endl;
    }
    int amountOfFuel;
    std::cout << "Podaj ilość substancji napędowej:" << std::endl;
    *inputStream >> amountOfFuel;
    try {
        motorVehicle->fill(amountOfFuel);
    }
    catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
}

void saveMyVehicleToFile(Vehicle *vehicle, std::istream *inputStream) {
    if (vehicle == nullptr) { return; }//dopisac

    std::string fileName;
    std::cout << "Podaj nazwę pliku" << std::endl;
    *inputStream >> fileName;

    std::ofstream file;
    file.open(fileName, std::ofstream::out);
    file << *vehicle;
    file.close();
}

void showInventory(SalesDepartment *salesDepartment) {
    std::cout << *salesDepartment->getVehicleFactory();
}

void saveFactoryToFile(VehicleFactory *vehicleFactory, std::istream *inputStream) {
    std::string fileName;
    std::cout << "Podaj nazwę pliku" << std::endl;
    *inputStream >> fileName;

    std::ofstream file;
    file.open(fileName, std::ofstream::out);
    file << *vehicleFactory;
    file.close();
}

void readFactoryFromFile(SalesDepartment *salesDepartment, std::istream *inputStream) {
    std::string fileName;
    std::cout << "Podaj nazwę pliku" << std::endl;
    *inputStream >> fileName;

    std::ifstream file;
    file.open(fileName, std::ofstream::in);

    if (!file) {
        std::cout << "Plik nie istnieje. Nie można wczytać fabryki." << std::endl;
        return;
    }

    VehicleFactory *vehicleFactoryFromFile;
    std::string readLine;
    getline(file, readLine);
    if (readLine == "Fabryka samochodów:") {
        vehicleFactoryFromFile = new CarFactory();
    } else if (readLine == "Fabryka motorów:") {
        vehicleFactoryFromFile = new MotorbikeFactory();
    } else if (readLine == "Fabryka rowerów:") {
        vehicleFactoryFromFile = new BikeFactory();
    } else {
        std::cout << "Nieznany rodzaj fabryki" << std::endl;
        return;
    }

    file >> *vehicleFactoryFromFile;
    file.close();

    salesDepartment->setVehicleFactory(vehicleFactoryFromFile);
}

void readMyCarFromFile(UIContext &uiContext, std::istream *inputStream) {
    std::string fileName;
    std::cout << "Podaj nazwę pliku" << std::endl;
    *inputStream >> fileName;

    std::ifstream file;
    file.open(fileName, std::ofstream::in);

    if (!file) {
        std::cout << "Plik nie istnieje. Nie można wczytać samochodu." << std::endl;
        return;
    }
    std::string readLine;
    getline(file, readLine);
    if (readLine == "Samochód:") {
        Car *carFromFile = new Car();
        file >> *carFromFile;
        file.close();
        uiContext.currentMotorVehicle = carFromFile;
    } else if (readLine == "Motor:") {
        Motorbike *motorbikeFromFile = new Motorbike();
        file >> *motorbikeFromFile;
        file.close();
        uiContext.currentMotorVehicle = motorbikeFromFile;
    } else if (readLine == "Rower:") {
        Bike *bikeFromFile = new Bike();
        file >> *bikeFromFile;
        file.close();
        uiContext.currentBike = bikeFromFile;
    } else {
        std::cout << "Nie mozna odczytac z pliku" << std::endl;
    }

    file.close();
}

void estimatePriceOfMyVehicle(UIContext &uiContext, std::istream *inputStream) {
    if (checkIfCurrentMotorVehicleNullptr(uiContext)) { return; }
    int estimatedPrice = uiContext.currentMotorVehiclesDealer->estimatePrice(*uiContext.currentMotorVehicle);
    std::cout << "Oszacowana cena wynoi: " << estimatedPrice << "zł" << std::endl;
}

void sellMyMotorVehicle(UIContext &uiContext, std::istream *inputStream) {
    if (checkIfCurrentMotorVehicleNullptr(uiContext)) { return; }
    double soldPrice = uiContext.currentMotorVehiclesDealer->buyFromOwner(*uiContext.currentMotorVehicle);
    std::cout << "Twoj pojazd został sprzedany za: " << soldPrice << std::endl;
    uiContext.currentMotorVehicle = nullptr;
}

void showVehicleInDealerList(UsedMotorVehicleDealer *currentUsedMotorVehicleDealer) {
    std::map<MotorVehicle *, double> availableModels = currentUsedMotorVehicleDealer->getAvailableModels();

    if (availableModels.empty()) {
        std::cout << LINE_PREFIX << "Komis nie posiada obecnie żadnych modeli możliwych do kupienia" << std::endl;
        return;
    }
    int i = 0;
    for (std::map<MotorVehicle *, double>::iterator it = availableModels.begin();
         it != availableModels.end(); ++it) {

        std::cout << LINE_PREFIX << "[" << ++i << "] " << it->first->shortString() << " cena:" << it->second
                  << std::endl;
    }
}

void buyCarFromDealer(UIContext &uiContext, std::istream *inputStream) {
    std::cout << "Podaj index: ";
    int chosenIndex;
    *inputStream >> chosenIndex;
    std::cout << "Podaj kwotę za jąka chcesz dokonać zakupu:";
    double cost;
    *inputStream >> cost;

    std::map<MotorVehicle *, double>::const_iterator it = uiContext.currentMotorVehiclesDealer->getAvailableModels().begin();
    std::advance(it, chosenIndex - 1);
    MotorVehicle *motorVehicle = it->first;
    try {
        uiContext.currentMotorVehicle = uiContext.currentMotorVehiclesDealer->sellToClient(motorVehicle, cost);
    }
    catch (std::runtime_error &e) {
        std::cout << e.what();
    }
    catch (std::invalid_argument &e) {
        std::cout << e.what() << " Sprzedaż zakończona niepowodzeniem" << std::endl;
    }
}


void changeColorOfVehicle(UIContext &uiContext, std::istream *inputStream) {
    // zmienia kolor posiadanego pojazdu silnikowego
    std::cout << "Dostęne kolory to:" << std::endl;
    std::cout << "[0] Czarny" << std::endl;
    std::cout << "[1] Biały" << std::endl;
    std::cout << "[2] Złoty" << std::endl;
    std::cout << "[3] Srebrny" << std::endl;
    std::cout << "[4] Czerwony" << std::endl;
    int chosenNumber;
    std::cout << "Wybierz na jaki kolor polakierować pojazd:";
    *inputStream >> chosenNumber;
    if (chosenNumber >= 0 && chosenNumber < 4) {
        Color chosenColor = static_cast<Color>(chosenNumber);
        if (checkIfCurrentMotorVehicleNullptr(uiContext)) { return; }
        Sprayer::getInstance()->changeColor(*uiContext.currentMotorVehicle, chosenColor);
    } else {
        std::cout << "Liczba z poza zakresu 0 do 4" << std::endl;
    }

}

void createNewSalesDepartment(UIContext &uiContext, std::istream *inputStream) {
    CarSpecification *specification1 = new CarSpecification{"BMW", "Seria-3", Color::BLACK, 12.0, 150};
    CarSpecification *specification2 = new CarSpecification{"Mercedes-Benz", "E-klasa", Color::WHITE, 12.5, 160};
    MotorbikeSpecification *motorbikeSpecification2 = new MotorbikeSpecification{"Yamaha", "R1", Color::SILVER, 6.5, 1};
    MotorbikeSpecification *motorbikeSpecification3 = new MotorbikeSpecification{"BMW", "RT", Color::RED, 5.8, 3};
    BikeSpecification *bikeSpecification1 = new BikeSpecification{"Romet", "Orkan", Color::SILVER, 3};
    BikeSpecification *bikeSpecification2 = new BikeSpecification{"Cross", "Hexagon", Color::WHITE, 0};

    std::string salesDepartmentName;
    std::cout << "Podaj nazwę salonu:";
    *inputStream >> salesDepartmentName; //todo wpisywanie ze spacją
    std::cout << "Wybierz jaki typ pojazdów będzie dostępny w Twoim salonie:" << std::endl;
    std::cout << "[0] Samochody" << std::endl;
    std::cout << "[1] Motocykle" << std::endl;
    std::cout << "[2] Rowery" << std::endl;
    int commandNumber = getCommandFromConsole(inputStream);
    SalesDepartment *salesDepartmentFromUser;
    switch (commandNumber) {
        case 0:
            salesDepartmentFromUser = new SalesDepartment{salesDepartmentName,
                                                          std::vector<VehicleSpecification *>{specification1,
                                                                                              specification2},
                                                          new CarFactory{}};

            break;
        case 1:
            salesDepartmentFromUser = new SalesDepartment{salesDepartmentName,
                                                          std::vector<VehicleSpecification *>{motorbikeSpecification3,
                                                                                              motorbikeSpecification2},
                                                          new MotorbikeFactory{}};
            break;
        case 2:
            salesDepartmentFromUser = new SalesDepartment{salesDepartmentName,
                                                          std::vector<VehicleSpecification *>{bikeSpecification1,
                                                                                              bikeSpecification2},
                                                          new BikeFactory{}};
            break;
        default:
            std::cout << "Niepoprawny numer.";
            return;
    }
    uiContext.salesDepartments.push_back(salesDepartmentFromUser);

}

//****************************************************
//             SHOW MENU
//****************************************************

void showMainMenu() {
    std::cout << std::endl;
    std::cout << "Wybierz interesującą Cię opcje:" << std::endl;
    std::cout << "[0] Wyjdź" << std::endl;
    std::cout << "[1] Idź do ..." << std::endl;
    std::cout << "[2] Opcje administaracyjne" << std::endl;
    std::cout << std::endl;
}

void showSalesDepartmentMenu() {
    std::cout << std::endl;
    std::cout << "Wybierz interesującą Cię opcje:" << std::endl;
    std::cout << "[0] Wyjdź" << std::endl;
    std::cout << "[1] Wypisz listę modeli pojazdów" << std::endl;
    std::cout << "[2] Wybierz pojazd, który chcesz aby wyprodukowano" << std::endl;
    std::cout << "[3] Kup pojazd" << std::endl;
    std::cout << "[4] Wypisz stan fabryki" << std::endl;
    std::cout << "[5] Zapisz fabrykę do pliku" << std::endl;
    std::cout << "[6] Wczytaj fabrykę z pliku" << std::endl;
    std::cout << std::endl;
}

void showUsedMotorVehicleDealerMenu() {
    std::cout << std::endl;
    std::cout << "Wybierz interesującą Cię opcje:" << std::endl;
    std::cout << "[0] Wyjdź" << std::endl;
    std::cout << "[1] Wyceń mój pojazd (...silnikowy" << std::endl;
    std::cout << "[2] Sprzedaj mój pojazd silnikowy" << std::endl;
    std::cout << "[3] Wypisz listę dostęnych pojazdów silnikowych" << std::endl;
    std::cout << "[4] Kup pojazd silnikowy" << std::endl;
    std::cout << std::endl;
}

void showSprayerMenu() {
    std::cout << std::endl;
    std::cout << "Wybierz interesującą Cię opcje:" << std::endl;
    std::cout << "[0] Wyjdź" << std::endl;
    std::cout << "[1] Zmień kolor mojego pojazdu" << std::endl;
    std::cout << std::endl;
}

void showMotorVehicleMenu() {
    std::cout << std::endl;
    std::cout << "Wybierz interesującą Cię opcje:" << std::endl;
    std::cout << "[0] Wyjdź" << std::endl;
    std::cout << "[1] Wypisz aktualny stan" << std::endl;
    std::cout << "[2] Jedziemy! *" << std::endl;
    std::cout << "[3] Zatrzymaj się! *" << std::endl;
    std::cout << "[4] Tankuj! *" << std::endl;
    std::cout << std::endl;
}

void showBikeMenu() {
    std::cout << std::endl;
    std::cout << "Wybierz interesującą Cię opcje:" << std::endl;
    std::cout << "[0] Wyjdź" << std::endl;
    std::cout << "[1] Wypisz aktualny stan" << std::endl;
    std::cout << "[2] Jedziemy! *" << std::endl;
    std::cout << "[3] Zatrzymaj się! *" << std::endl;
    std::cout << std::endl;
}

void showAdministrationMenu() {
    std::cout << std::endl;
    std::cout << "Wybierz interesującą Cię opcje:" << std::endl;
    std::cout << "[0] Wyjdź" << std::endl;
    std::cout << "[1] Zapisz mój pojazd silnikowy do pliku" << std::endl;
    std::cout << "[2] Zapisz mój rower do pliku" << std::endl;
    std::cout << "[3] Wczytaj mój pojazd silnikowy z pliku" << std::endl;
    std::cout << "[4] Wczytaj mój rower z pliku" << std::endl;
    std::cout << "[5] Stworzyć nowy salon" << std::endl; //todo
    std::cout << "[6] Stworzyć nowy komis" << std::endl; //todo
    std::cout << std::endl;
}

//****************************************************
//             CONTEXT MENU LOGIC
//****************************************************

void enterSalesDepartmentMenu(UIContext &uiContext, std::istream *inputStream) {
    showSalesDepartmentMenu();
    bool running = true;
    while (running) {
        int commandNumber = getCommandFromConsole(inputStream);
        switch (commandNumber) {
            case 0:
                running = false;
                break;
            case 1:
                showVehicleList(uiContext.currentSalesDepartment);
                break;
            case 2:
                produceVehicle(uiContext.currentSalesDepartment, inputStream);
                break;
            case 3:
                buyVehicle(uiContext, inputStream);
                break;
            case 4:
                showInventory(uiContext.currentSalesDepartment);
                break;
            case 5:
                saveFactoryToFile(uiContext.currentSalesDepartment->getVehicleFactory(), inputStream);
                break;
            case 6:
                readFactoryFromFile(uiContext.currentSalesDepartment, inputStream);
                break;
            default:
                std::cout << "Opcja o podanym numerze nie istnieje" << std::endl;
        }
    }
}

void enterUsedMotorVehicleDealerMenu(UIContext &uiContext, std::istream *inputStream) {
    showUsedMotorVehicleDealerMenu();
    bool running = true;
    while (running) {
        int commandNumber = getCommandFromConsole(inputStream);
        switch (commandNumber) {
            case 0:
                running = false;
                break;
            case 1:
                estimatePriceOfMyVehicle(uiContext, inputStream);
                break;
            case 2:
                sellMyMotorVehicle(uiContext, inputStream);
                break;
            case 3:
                showVehicleInDealerList(uiContext.currentMotorVehiclesDealer);
                break;
            case 4:
                buyCarFromDealer(uiContext, inputStream);
                break;
            default:
                std::cout << "Opcja o podanym numerze nie istnieje" << std::endl;
        }
    }
}

void enterSprayerMenu(UIContext &uiContext, std::istream *inputStream) {
    showSprayerMenu();
    bool running = true;
    while (running) {
        int commandNumber = getCommandFromConsole(inputStream);
        switch (commandNumber) {
            case 0:
                running = false;
                break;
            case 1:
                changeColorOfVehicle(uiContext, inputStream);
                break;
            default:
                std::cout << "Opcja o podanym numerze nie istnieje" << std::endl;
        }
    }
}

void enterMotorVehicleMenu(UIContext &uiContext, std::istream *inputStream) {
    showMotorVehicleMenu();
    bool running = true;
    while (running) {
        int commandNumber = getCommandFromConsole(inputStream);
        switch (commandNumber) {
            case 0:
                running = false;
                break;
            case 1:
                std::cout << *uiContext.currentMotorVehicle;
                break;
            case 2:
                startMyVehicle(uiContext.currentMotorVehicle, inputStream);
                break;
            case 3:
                stopMyVehicle(uiContext.currentMotorVehicle);
                break;
            case 4:
                fillMyMotorVehicle(uiContext.currentMotorVehicle, inputStream);
                break;
            default:
                std::cout << "Opcja o podanym numerze nie istnieje" << std::endl;
        }
    }
}

void enterBikeMenu(UIContext &uiContext, std::istream *inputStream) {
    showBikeMenu();
    bool running = true;
    while (running) {
        int commandNumber = getCommandFromConsole(inputStream);
        switch (commandNumber) {
            case 0:
                running = false;
                break;
            case 1:
                std::cout << *uiContext.currentBike;
                break;
            case 2:
                startMyVehicle(uiContext.currentBike, inputStream);
                break;
            case 3:
                stopMyVehicle(uiContext.currentBike);
                break;
            default:
                std::cout << "Opcja o podanym numerze nie istnieje" << std::endl;
        }
    }
}

void enterAdministrationMenu(UIContext &uiContext, std::istream *inputStream) {
    showAdministrationMenu();
    bool running = true;
    while (running) {
        int commandNumber = getCommandFromConsole(inputStream);
        switch (commandNumber) {
            case 0:
                running = false;
                break;
            case 1:
                saveMyVehicleToFile(uiContext.currentMotorVehicle, inputStream);
                break;
            case 2:
                saveMyVehicleToFile(uiContext.currentBike, inputStream);
                break;
            case 3:
                readMyCarFromFile(uiContext, inputStream);
                break;
            case 4:
                readMyCarFromFile(uiContext, inputStream);
                break;
            case 5:
                createNewSalesDepartment(uiContext, inputStream);
                break;
            case 6:
                break;
            case 7:

                break;
            case 8:

                break;
            default:
                std::cout << "Opcja o podanym numerze nie istnieje" << std::endl;
        }
    }
}

//****************************************************
//             TRAVERSING PLACES
//****************************************************

void enterSpecificPlace(UIContext &uiContext, std::istream *inputStream) {

    //todo wyświetlić opcje
    std::cout << "Dokąd chcesz się udać?" << std::endl;
    int i = 0;
    for (SalesDepartment *sd: uiContext.salesDepartments) {
        std::cout << "[" << i << "] " << sd->getName() << std::endl;
        i++;
    }
    for (UsedMotorVehicleDealer *vd: uiContext.usedMotorVehicleDealers) {
        std::cout << "[" << i << "] " << vd->getName() << std::endl;
        i++;
    }
    std::cout << "[" << i << "] " << "Lakiernik" << std::endl;
    i++;

    if (uiContext.currentMotorVehicle != nullptr) {
        std::cout << "[" << i << "] " << "Mój pojazd silnikowy" << std::endl;
        i++;
    }


    if (uiContext.currentBike != nullptr) {
        std::cout << "[" << i << "] " << "Mój rower" << std::endl;
        i++;
    }

    // poprosic o wybranie opcji
    int placeNumber = getCommandFromConsole(inputStream);


    i = 0;
    for (SalesDepartment *sd: uiContext.salesDepartments) {
        if (i == placeNumber) {
            uiContext.currentSalesDepartment = sd;
            enterSalesDepartmentMenu(uiContext, inputStream);
            uiContext.currentSalesDepartment = nullptr;
            return;
        }
        i++;
    }
    for (UsedMotorVehicleDealer *vd: uiContext.usedMotorVehicleDealers) {

        if (i == placeNumber) {
            uiContext.currentMotorVehiclesDealer = vd;
            enterUsedMotorVehicleDealerMenu(uiContext, inputStream);
            uiContext.currentMotorVehiclesDealer = nullptr;
            return;
        }
        i++;
    }

    //Lakiernik
    if (i == placeNumber) {
        enterSprayerMenu(uiContext, inputStream);
        return;
    }
    i++;

    if (uiContext.currentMotorVehicle != nullptr) {
        if (i == placeNumber) {
            enterMotorVehicleMenu(uiContext, inputStream);
            return;
        }
        i++;
    }

    if (uiContext.currentBike != nullptr) {
        if (i == placeNumber) {
            enterBikeMenu(uiContext, inputStream);
            return;
        }
        i++;
    }

    std::cout << "Niepoprawna opcja - brak miejsca o podanym indexie" << std::endl;
}

int main(int argc, char *argv[]) {

    std::string *inputFileName = nullptr;
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "-f" && i + 1 < argc) {
            inputFileName = new std::string(argv[i + 1]);
            // std::cout<<"Zanaleziono opcje -f " << *inputFileName << std::endl;
            break;
        }
    }

    std::istream *inputStream = &(std::cin);
    if (inputFileName != nullptr) {
        inputStream = new std::ifstream(inputFileName->c_str(), std::ifstream::in);
    }

    UIContext uiContext = createUIContext();

    bool running = true;
    while (running) {
        showMainMenu();
        int commandNumber = getCommandFromConsole(inputStream);
        switch (commandNumber) {
            case 0:
                running = false;
                std::cout << "\n\nPomyślnie zakończono działanie programu" << std::endl;
                break;
            case 1:
                enterSpecificPlace(uiContext, inputStream);
                break;
            case 2:
                enterAdministrationMenu(uiContext, inputStream);
                break;
            default:
                std::cout << "Opcja o podanym numerze nie istnieje" << std::endl;
        }
    }

    // todo posprzątać po sobie?
    return 0;
}

//todo opcje w admin menu do tworzenia salonów i komisów
//todo rozrzerzyć UIContext o predefiniowane listy modeli ora przykładowe salony (Rowerów, Motorów) DONE
//todo obsługa sytuacji wyjątkowych (wyjątki) DONE
//todo template w UsedMotorVehicleDealer
//todo zeby paliwa nie była nieskończona ilość