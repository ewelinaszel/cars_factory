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
    std::vector<UsedMotorVehicleDealer<MotorVehicle> *> usedMotorVehicleDealers;
    std::vector<UsedMotorVehicleDealer<Car> *> usedCarsDealers;

    MotorVehicle *currentMotorVehicle;
    Bike *currentBike;

    //Where we are:
    SalesDepartment *currentSalesDepartment = nullptr;
    UsedMotorVehicleDealer<MotorVehicle> *currentMotorVehiclesDealer = nullptr;
    UsedMotorVehicleDealer<Car> *currentCarsDealer = nullptr;
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
            "Salon samochodowy - G??adysz Tarn??w",
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


    UsedMotorVehicleDealer<MotorVehicle> *usedMotorVehicleDealer1 = new UsedMotorVehicleDealer<MotorVehicle>(
            "Komis Pojazd??w Silnikowych Kowalski",
            std::map<MotorVehicle *, double>(),
            0.2);

    UsedMotorVehicleDealer<Car> *usedCarsDealer1 = new UsedMotorVehicleDealer<Car>("Komis Samochod??w Nowak",
                                                                                   std::map<Car *, double>(),
                                                                                   0.2);

    UIContext uiContext;
    uiContext.salesDepartments.push_back(salesDepartment1);
    uiContext.salesDepartments.push_back(salesDepartment2);
    uiContext.salesDepartments.push_back(salesDepartment3);
    uiContext.salesDepartments.push_back(salesDepartment4);
    uiContext.usedMotorVehicleDealers.push_back(usedMotorVehicleDealer1);
    uiContext.usedCarsDealers.push_back(usedCarsDealer1);
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
        std::cout << LINE_PREFIX << "Salon nie posiada obecnie ??adnych modeli mo??liwych do zam??wienia" << std::endl;
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
        std::cerr << LINE_PREFIX << "Niepoprawny numer specyfikacji " << i
                  << ". Index powinien mie??ci?? si?? w zakresie [1, " << n << "]" << std::endl;
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
}

void buyVehicle(UIContext &uiContext, std::istream *inputStream) {
    std::cout << "Podaj index: ";
    int i;
    *inputStream >> i;

    VehicleSpecification *chosenVehicleSpecification;
    try {
        chosenVehicleSpecification = uiContext.currentSalesDepartment->getListOfAvailableModels().at(i - 1);
    }
    catch (const std::out_of_range &oor) {
        int n = uiContext.currentSalesDepartment->getListOfAvailableModels().size();
        std::cerr << LINE_PREFIX << "Niepoprawny numer specyfikacji " << i
                  << ". Index powinien mie??ci?? si?? w zakresie [1, " << n << "]" << std::endl;
        return;
    }
    Vehicle *producedVehicle;
    try {
        producedVehicle = uiContext.currentSalesDepartment->sellVehicle(chosenVehicleSpecification);
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    //na pewno wyprodukowany pojazd jest Rowerem albo Pojazdem silnikowym - jedna z konwersji zwr??ci nullptr
    uiContext.currentMotorVehicle = dynamic_cast<MotorVehicle *>(producedVehicle);
    uiContext.currentBike = dynamic_cast<Bike *>(producedVehicle);
}

void startMyVehicle(Vehicle *vehicle, std::istream *inputStream) {
    double distance;
    std::cout << "Podaj ilo???? kilometr??w do przejechania: " << std::endl;
    *inputStream >> distance;
    if (vehicle == nullptr) {
        std::cout << "Nie posiadasz aktualnie pojazdu" << std::endl;
    }
    try {
        vehicle->drive(distance);
    }
    catch (std::runtime_error &re) {
        std::cerr << re.what() << std::endl;
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
        std::cerr << re.what() << std::endl;
    }
}

void fillMyMotorVehicle(MotorVehicle *motorVehicle, std::istream *inputStream) {
    if (motorVehicle == nullptr) {
        std::cout << "Nie posiadasz aktualnie pojazdu silnikowego" << std::endl;
    }
    int amountOfFuel;
    std::cout << "Podaj ilo???? substancji nap??dowej:" << std::endl;
    *inputStream >> amountOfFuel;
    try {
        motorVehicle->fill(amountOfFuel);
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}

void saveMyVehicleToFile(Vehicle *vehicle, std::istream *inputStream) {
    if (vehicle == nullptr) {
        std::cout<<"Nie posiadasz pojazdu, ktory mozna zapisa?? do pliku."<<std::endl;
    }

    std::string fileName;
    std::cout << "Podaj nazw?? pliku" << std::endl;
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
    std::cout << "Podaj nazw?? pliku" << std::endl;
    *inputStream >> fileName;

    std::ofstream file;
    file.open(fileName, std::ofstream::out);
    file << *vehicleFactory;
    file.close();
}

void readFactoryFromFile(SalesDepartment *salesDepartment, std::istream *inputStream) {
    std::string fileName;
    std::cout << "Podaj nazw?? pliku" << std::endl;
    *inputStream >> fileName;

    std::ifstream file;
    file.open(fileName, std::ofstream::in);

    if (!file) {
        std::cout << "Plik nie istnieje. Nie mo??na wczyta?? fabryki." << std::endl;
        return;
    }

    VehicleFactory *vehicleFactoryFromFile;
    std::string readLine;
    getline(file, readLine);
    if (readLine == "Fabryka samochod??w:") {
        vehicleFactoryFromFile = new CarFactory();
    } else if (readLine == "Fabryka motor??w:") {
        vehicleFactoryFromFile = new MotorbikeFactory();
    } else if (readLine == "Fabryka rower??w:") {
        vehicleFactoryFromFile = new BikeFactory();
    } else {
        std::cout << "Nieznany rodzaj fabryki" << std::endl;
        return;
    }

    try {
        file >> *vehicleFactoryFromFile;
    } catch (std::ios_base::failure &f) {
        std::cerr << "Nie mo??na poprawnie wczyta?? fabryki z pliku." << std::endl << "Pow??d: " << f.what() << std::endl;
    }
    file.close();

    salesDepartment->setVehicleFactory(vehicleFactoryFromFile);
}

void readMyCarFromFile(UIContext &uiContext, std::istream *inputStream) {
    std::string fileName;
    std::cout << "Podaj nazw?? pliku" << std::endl;
    *inputStream >> fileName;

    std::ifstream file;
    file.open(fileName, std::ofstream::in);

    if (!file) {
        std::cout << "Plik nie istnieje. Nie mo??na wczyta?? samochodu." << std::endl;
        return;
    }
    std::string readLine;
    getline(file, readLine);
    if (readLine == "Samoch??d:") {
        Car *carFromFile = new Car();
        try {
            file >> *carFromFile;
        }
        catch (std::ios_base::failure &f) {
            std::cerr << "Nie mo??na poprawnie wczyta?? samochodu z pliku." << std::endl << "Pow??d: " << f.what()
                      << std::endl;
            return;
        }
        uiContext.currentMotorVehicle = carFromFile;
    } else if (readLine == "Motor:") {
        Motorbike *motorbikeFromFile = new Motorbike();
        try {
            file >> *motorbikeFromFile;
        }
        catch (std::ios_base::failure &f) {
            std::cerr << "Nie mo??na poprawnie wczyta?? motoru z pliku." << std::endl << "Pow??d: " << f.what()
                      << std::endl;
            return;
        }
        uiContext.currentMotorVehicle = motorbikeFromFile;
    } else if (readLine == "Rower:") {
        Bike *bikeFromFile = new Bike();
        try {
            file >> *bikeFromFile;
        }
        catch (std::ios_base::failure &f) {
            std::cerr << "Nie mo??na poprawnie wczyta?? roweru z pliku." << std::endl << "Pow??d: " << f.what()
                      << std::endl;
            return;
        }
        uiContext.currentBike = bikeFromFile;
    } else {
        std::cout << "Nie mozna odczytac z pliku" << std::endl;
    }

    file.close();
}

void estimatePriceOfMyVehicle(UIContext &uiContext, std::istream *inputStream) {
    if (checkIfCurrentMotorVehicleNullptr(uiContext)) { return; }
    int estimatedPrice;
    try {
        //tylko jeden mo??e by?? nie nullem w jednym czasie
        if (uiContext.currentMotorVehiclesDealer != nullptr) {
            estimatedPrice = uiContext.currentMotorVehiclesDealer->estimatePrice(*uiContext.currentMotorVehicle);
        } else {
            estimatedPrice = uiContext.currentCarsDealer->estimatePrice(*uiContext.currentMotorVehicle);
        }
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    std::cout << "Oszacowana cena wynoi: " << estimatedPrice << "z??" << std::endl;
}

void sellMyMotorVehicle(UIContext &uiContext, std::istream *inputStream) {
    if (checkIfCurrentMotorVehicleNullptr(uiContext)) { return; }
    double soldPrice;
    try {
        //tylko jeden mo??e by?? nie nullem w jednym czasie
        if (uiContext.currentMotorVehiclesDealer != nullptr) {
            soldPrice = uiContext.currentMotorVehiclesDealer->buyFromOwner(*uiContext.currentMotorVehicle);
        } else {
            soldPrice = uiContext.currentCarsDealer->buyFromOwner(*uiContext.currentMotorVehicle);
        }
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    std::cout << "Twoj pojazd zosta?? sprzedany za: " << soldPrice << std::endl;
    uiContext.currentMotorVehicle = nullptr;
}

template<class T>
void showVehicleInDealerList(UsedMotorVehicleDealer<T> *currentUsedMotorVehicleDealer) {
    std::map<T *, double> availableModels = currentUsedMotorVehicleDealer->getAvailableModels();

    if (availableModels.empty()) {
        std::cout << LINE_PREFIX << "Komis nie posiada obecnie ??adnych modeli mo??liwych do kupienia" << std::endl;
        return;
    }
    int i = 0;

    for (auto it = availableModels.begin(); it != availableModels.end(); ++it) {
        std::cout << LINE_PREFIX << "[" << ++i << "] " << it->first->shortString() << " cena:" << it->second
                  << std::endl;
    }
}

void showVehicleInDealerList(UIContext &uiContext) {
    //tylko jeden mo??e by?? nie nullem w jednym czasie
    if (uiContext.currentMotorVehiclesDealer != nullptr) {
        showVehicleInDealerList(uiContext.currentMotorVehiclesDealer);
    } else {
        showVehicleInDealerList(uiContext.currentCarsDealer);
    }
}

template <class T>
void buyCarFromDealer(UIContext &uiContext, std::istream *inputStream, UsedMotorVehicleDealer<T>* currentMotorVehiclesDealer) {
    std::cout << "Podaj index: ";
    int chosenIndex;
    *inputStream >> chosenIndex;
    std::cout << "Podaj kwot?? za j??ka chcesz dokona?? zakupu:";
    double cost;
    *inputStream >> cost;

    auto it = currentMotorVehiclesDealer->getAvailableModels().begin();
    std::advance(it, chosenIndex - 1);
    T *motorVehicle = it->first;
    try {
        uiContext.currentMotorVehicle = currentMotorVehiclesDealer->sellToClient(motorVehicle, cost);
    }
    catch (std::runtime_error &e) {
        std::cerr << e.what();
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << " Sprzeda?? zako??czona niepowodzeniem" << std::endl;
    }
}

void buyCarFromDealer(UIContext &uiContext, std::istream *inputStream) {
    //tylko jeden mo??e by?? nie nullem w jednym czasie
    if (uiContext.currentMotorVehiclesDealer != nullptr) {
        buyCarFromDealer(uiContext, inputStream, uiContext.currentMotorVehiclesDealer);
    } else {
        buyCarFromDealer(uiContext, inputStream, uiContext.currentCarsDealer);
    }
}

void changeColorOfVehicle(UIContext &uiContext, std::istream *inputStream) {
    // zmienia kolor posiadanego pojazdu silnikowego
    std::cout << "Dost??ne kolory to:" << std::endl;
    std::cout << "[0] Czarny" << std::endl;
    std::cout << "[1] Bia??y" << std::endl;
    std::cout << "[2] Z??oty" << std::endl;
    std::cout << "[3] Srebrny" << std::endl;
    std::cout << "[4] Czerwony" << std::endl;
    int chosenNumber;
    std::cout << "Wybierz na jaki kolor polakierowa?? pojazd:";
    *inputStream >> chosenNumber;
    if (chosenNumber >= 0 && chosenNumber <= 4) {
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
    std::cout << "Podaj nazw?? salonu:";
    std::getline(*inputStream >> std::ws, salesDepartmentName);
    std::cout << "Wybierz jaki typ pojazd??w b??dzie dost??pny w Twoim salonie:" << std::endl;
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

void createNewUsedMotorVehicleDealer(UIContext &uiContext, std::istream *inputStream) {

    std::string usedMotorVehicleDealerName;
    std::cout << "Podaj nazw?? komisu:";
    std::getline(*inputStream >> std::ws, usedMotorVehicleDealerName);

    double margin;
    std::cout << "Podaj mar???? (wyra??on?? jako u??amek o jaki powi??kszana jest cena z przedzia??u [0, 1]): " << std::endl;
    *inputStream >> margin;
    if (margin < 0 || margin > 1) {
        std::cerr << "Niepoprawna warto???? mar??y." << std::endl;
    }

    std::cout << "Wybierz jakim typ pojazd??w komis b??dzie handlowa??:" << std::endl;
    std::cout << "[0] Samochody" << std::endl;
    std::cout << "[1] Pojazdy silnikowe (Samochody + Motocykle)" << std::endl;
    int commandNumber = getCommandFromConsole(inputStream);
    UsedMotorVehicleDealer<Car> *usedCarsDealer;
    UsedMotorVehicleDealer<MotorVehicle> *usedMotorVehicleDealer;
    switch (commandNumber) {
        case 0:
            usedCarsDealer = new UsedMotorVehicleDealer<Car>(usedMotorVehicleDealerName,
                                                                                          std::map<Car*, double>(),
                                                                                                  margin);
            uiContext.usedCarsDealers.push_back(usedCarsDealer);
            break;
        case 1:
            usedMotorVehicleDealer = new UsedMotorVehicleDealer<MotorVehicle>(usedMotorVehicleDealerName,
                                                                                         std::map<MotorVehicle*, double>(),
                                                                                         margin);
            uiContext.usedMotorVehicleDealers.push_back(usedMotorVehicleDealer);
            break;
        default:
            std::cout << "Niepoprawny numer.";
            return;
    }
}

//****************************************************
//             SHOW MENU
//****************************************************

void showMainMenu() {
    std::cout << std::endl;
    std::cout << "Wybierz interesuj??c?? Ci?? opcje:" << std::endl;
    std::cout << "[0] Wyjd??" << std::endl;
    std::cout << "[1] Id?? do ..." << std::endl;
    std::cout << "[2] Opcje administaracyjne" << std::endl;
    std::cout << std::endl;
}

void showSalesDepartmentMenu() {
    std::cout << std::endl;
    std::cout << "Wybierz interesuj??c?? Ci?? opcje:" << std::endl;
    std::cout << "[0] Wyjd??" << std::endl;
    std::cout << "[1] Wypisz list?? modeli pojazd??w" << std::endl;
    std::cout << "[2] Wybierz pojazd, kt??ry chcesz aby wyprodukowano" << std::endl;
    std::cout << "[3] Kup pojazd" << std::endl;
    std::cout << "[4] Wypisz stan fabryki" << std::endl;
    std::cout << "[5] Zapisz fabryk?? do pliku" << std::endl;
    std::cout << "[6] Wczytaj fabryk?? z pliku" << std::endl;
    std::cout << std::endl;
}

void showUsedMotorVehicleDealerMenu() {
    std::cout << std::endl;
    std::cout << "Wybierz interesuj??c?? Ci?? opcje:" << std::endl;
    std::cout << "[0] Wyjd??" << std::endl;
    std::cout << "[1] Wyce?? m??j pojazd silnikowy" << std::endl;
    std::cout << "[2] Sprzedaj m??j pojazd silnikowy" << std::endl;
    std::cout << "[3] Wypisz list?? dost??nych pojazd??w silnikowych" << std::endl;
    std::cout << "[4] Kup pojazd silnikowy" << std::endl;
    std::cout << std::endl;
}

void showSprayerMenu() {
    std::cout << std::endl;
    std::cout << "Wybierz interesuj??c?? Ci?? opcje:" << std::endl;
    std::cout << "[0] Wyjd??" << std::endl;
    std::cout << "[1] Zmie?? kolor mojego pojazdu" << std::endl;
    std::cout << std::endl;
}

void showMotorVehicleMenu() {
    std::cout << std::endl;
    std::cout << "Wybierz interesuj??c?? Ci?? opcje:" << std::endl;
    std::cout << "[0] Wyjd??" << std::endl;
    std::cout << "[1] Wypisz aktualny stan" << std::endl;
    std::cout << "[2] Jedziemy! " << std::endl;
    std::cout << "[3] Zatrzymaj si??! " << std::endl;
    std::cout << "[4] Tankuj! " << std::endl;
    std::cout << std::endl;
}

void showBikeMenu() {
    std::cout << std::endl;
    std::cout << "Wybierz interesuj??c?? Ci?? opcje:" << std::endl;
    std::cout << "[0] Wyjd??" << std::endl;
    std::cout << "[1] Wypisz aktualny stan" << std::endl;
    std::cout << "[2] Jedziemy! *" << std::endl;
    std::cout << "[3] Zatrzymaj si??! *" << std::endl;
    std::cout << std::endl;
}

void showAdministrationMenu() {
    std::cout << std::endl;
    std::cout << "Wybierz interesuj??c?? Ci?? opcje:" << std::endl;
    std::cout << "[0] Wyjd??" << std::endl;
    std::cout << "[1] Zapisz m??j pojazd silnikowy do pliku" << std::endl;
    std::cout << "[2] Zapisz m??j rower do pliku" << std::endl;
    std::cout << "[3] Wczytaj m??j pojazd silnikowy z pliku" << std::endl;
    std::cout << "[4] Wczytaj m??j rower z pliku" << std::endl;
    std::cout << "[5] Stworzy?? nowy salon" << std::endl;
    std::cout << "[6] Stworzy?? nowy komis" << std::endl;
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
                showVehicleInDealerList(uiContext);
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
                createNewUsedMotorVehicleDealer(uiContext, inputStream);
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

    std::cout << "Dok??d chcesz si?? uda???" << std::endl;
    int i = 0;
    for (SalesDepartment *sd: uiContext.salesDepartments) {
        std::cout << "[" << i << "] " << sd->getName() << std::endl;
        i++;
    }
    for (UsedMotorVehicleDealer<MotorVehicle> *vd: uiContext.usedMotorVehicleDealers) {
        std::cout << "[" << i << "] " << vd->getName() << std::endl;
        i++;
    }

    for (UsedMotorVehicleDealer<Car> *vd: uiContext.usedCarsDealers) {
        std::cout << "[" << i << "] " << vd->getName() << std::endl;
        i++;
    }

    std::cout << "[" << i << "] " << "Lakiernik" << std::endl;
    i++;

    if (uiContext.currentMotorVehicle != nullptr) {
        std::cout << "[" << i << "] " << "M??j pojazd silnikowy" << std::endl;
        i++;
    }


    if (uiContext.currentBike != nullptr) {
        std::cout << "[" << i << "] " << "M??j rower" << std::endl;
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
    for (UsedMotorVehicleDealer<MotorVehicle> *vd: uiContext.usedMotorVehicleDealers) {

        if (i == placeNumber) {
            uiContext.currentMotorVehiclesDealer = vd;
            enterUsedMotorVehicleDealerMenu(uiContext, inputStream);
            uiContext.currentMotorVehiclesDealer = nullptr;
            return;
        }
        i++;
    }

    for (UsedMotorVehicleDealer<Car> *vd: uiContext.usedCarsDealers) {
        if (i == placeNumber) {
            uiContext.currentCarsDealer = vd;
            enterUsedMotorVehicleDealerMenu(uiContext, inputStream);
            uiContext.currentCarsDealer = nullptr;
            return;
        }
        i++;
    }

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
                std::cout << "\n\nPomy??lnie zako??czono dzia??anie programu" << std::endl;
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
    return 0;
}
