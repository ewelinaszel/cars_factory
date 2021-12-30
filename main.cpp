#include <iostream>
#include <deque>
#include "Vehicle.h"
#include "SalesDepartment.h"
#include "SalesDepartment.cpp"
#include "VehicleFactory.h"
#include "VehicleSpecification.h"
#include "Car.h"
#include "CarSpecification.h"
#include "CarFactory.h"

std::string LINE_PREFIX = "  ";

void showMenu() {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Wybierz interesującą Cię opcje:" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "[0] Pokaż menu" << std::endl;
    std::cout << "[1] Wypisz listę modeli samochodów" << std::endl;
    std::cout << "[2] Wybierz samochód, który chcesz aby wyprodukowano" << std::endl;
    std::cout << "[3] Kup samochód" << std::endl;
    std::cout << "[4] Wypisz fabrykę" << std::endl;
    std::cout << "[5] Wypisz mój aktualny samochód" << std::endl;
    std::cout << "[6] Jedziemy!" << std::endl;
    std::cout << "[7] Zatrzymaj się!" << std::endl;
    std::cout << "[8] Tankuj!" << std::endl;
    std::cout << "[9] Zapisz fabrykę do pliku" << std::endl;
    std::cout << "[10] Zapisz mój samochód do pliku" << std::endl;
    std::cout << "[11] Wczytaj fabrykę z pliku" << std::endl;
    std::cout << "[12] Wczytaj mój samochód z pliku" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}

int getCommandFromConsole(std::istream* inputStream) {
    int i;
    std::cout << "Podaj numer opcji: ";
    *inputStream >> i;
    return i;
}

struct UIContext {
    SalesDepartment<Car, CarSpecification> salesDepartment;
    Car* currentCar;
};

bool checkIfCurrentCarNullptr(UIContext &uiContext) {
    if (uiContext.currentCar == nullptr) {
        std::cout << "Nie posiadasz aktualnie samochodu" << std::endl;
        return true;
    }
    return false;
}

void showCarList(UIContext &uiContext) {
    std::vector<CarSpecification> availableCarSpecifications = uiContext.salesDepartment.getListOfAvailableModels();
    int i = 0;
    for (std::vector<CarSpecification>::iterator it = availableCarSpecifications.begin();
        it != availableCarSpecifications.end(); ++it) {
        std::cout << LINE_PREFIX <<"[" << ++i << "] " << *it << std::endl;
    }
}

void produceCar(UIContext &uiContext, std::istream* inputStream) {
    std::cout << "Podaj index: ";
    int i;
    *inputStream >> i;

    try {
        CarSpecification chosenCarSpecification = uiContext.salesDepartment.getListOfAvailableModels().at(i - 1);
        uiContext.salesDepartment.orderCar(chosenCarSpecification);
    }
    catch (const std::out_of_range& oor) {
        int n = uiContext.salesDepartment.getListOfAvailableModels().size();
        std::cout << LINE_PREFIX <<"Niepoprawny numer specyfikacji " << i << ". Index powinien mieścić się w zakresie [1, " << n << "]" << std::endl;
    }
}

void buyCar(UIContext &uiContext, std::istream* inputStream) {
    std::cout << "Podaj index: ";
    int i;
    *inputStream >> i;

    try {
        CarSpecification chosenCarSpecification = uiContext.salesDepartment.getListOfAvailableModels().at(i - 1);
        uiContext.currentCar = uiContext.salesDepartment.sellCar(chosenCarSpecification);
    }
    catch (const std::out_of_range& oor) {
        int n = uiContext.salesDepartment.getListOfAvailableModels().size();
        std::cout << LINE_PREFIX <<"Niepoprawny numer specyfikacji " << i << ". Index powinien mieścić się w zakresie [1, " << n << "]" << std::endl;
    }
}

void showInventory(UIContext &uiContext) {
    std::cout << *uiContext.salesDepartment.getVehicleFactory();
}

void showMyCar(UIContext &uiContext){
    if(checkIfCurrentCarNullptr(uiContext)){ return; }
    std::cout << *uiContext.currentCar << std::endl;
}

void startMyCar(UIContext &uiContext, std::istream* inputStream){
    double distance;
    std:: cout<<"Podaj ilość kilometrów do przejechania: "<< std::endl;
    *inputStream >> distance;
    if(checkIfCurrentCarNullptr(uiContext)){ return; }
    uiContext.currentCar->drive(distance);
}

void stopMyCar(UIContext &uiContext){
    if(checkIfCurrentCarNullptr(uiContext)){ return; }
    uiContext.currentCar->stop();
}

void fillMyCar(UIContext &uiContext, std::istream* inputStream){
    if(checkIfCurrentCarNullptr(uiContext)){ return; }
    int amountOfFuel;
    std::cout << "Podaj ilość substancji napędowej:" << std::endl;
    *inputStream >> amountOfFuel;
    uiContext.currentCar->fill(amountOfFuel);
}

void saveMyFactoryToFile(UIContext &uiContext, std::istream* inputStream){
    std::string fileName;
    std::cout << "Podaj nazwę pliku" << std::endl;
    *inputStream >> fileName;

    std::ofstream file;
    file.open (fileName, std::ofstream::out);

    file << *uiContext.salesDepartment.getVehicleFactory();
    file.close();
    std::cout << "Zapis zakończony powodzeniem" << std::endl;
}

void saveMyCarToFile(UIContext &uiContext, std::istream* inputStream){
    if(checkIfCurrentCarNullptr(uiContext)){ return; }

    std::string fileName;
    std::cout << "Podaj nazwę pliku" << std::endl;
    *inputStream >> fileName;

    std::ofstream file;
    file.open (fileName, std::ofstream::out);
    file << *uiContext.currentCar;
    file.close();
}

void readMyFactoryFromFile(UIContext &uiContext, std::istream* inputStream){
    std::string fileName;
    std::cout << "Podaj nazwę pliku" << std::endl;
    *inputStream >> fileName;

    std::ifstream file;
    file.open(fileName, std::ofstream::in);

    if(!file) {
        std::cout << "Plik nie istnieje. Nie można wczytać fabryki." << std::endl;
        return;
    }

    CarFactory *carFactoryFromFile = new CarFactory();
    file >> *carFactoryFromFile;
    file.close();

    uiContext.salesDepartment.setVehicleFactory(carFactoryFromFile);
}

void readMyCarFromFile(UIContext &uiContext, std::istream* inputStream){
    std::string fileName;
    std::cout << "Podaj nazwę pliku" << std::endl;
    *inputStream >> fileName;

    std::ifstream file;
    file.open(fileName, std::ofstream::in);

    if(!file) {
        std::cout << "Plik nie istnieje. Nie można wczytać samochodu." << std::endl;
        return;
    }

    Car* carFromFile = new Car();
    file >> *carFromFile;
    file.close();
    uiContext.currentCar = carFromFile;
}

UIContext createUIContext() {
    CarSpecification* specification1 = new CarSpecification{"BMW", "Seria-3", Color::BLACK, 12.0, 150};
    CarSpecification* specification2 = new CarSpecification{"Mercedes-Benz", "E-klasa", Color::WHITE, 12.5, 160};
    CarSpecification* specification3 = new CarSpecification{"Audi", "A4", Color::SILVER, 9.0, 155};
    CarSpecification* specification4 = new CarSpecification{"Chevrolet", "Captiva", Color::GOLD, 12.0, 360};

    CarFactory* carFactory = new CarFactory{};
    SalesDepartment<Car, CarSpecification>* salesDepartment = new SalesDepartment<Car, CarSpecification>{
            std::vector<CarSpecification>{*specification1, *specification2, *specification3, *specification4}, carFactory};

    Car *currentCar = nullptr;

    UIContext uiContext;
    uiContext.salesDepartment = *salesDepartment;
    uiContext.currentCar = currentCar;
    return uiContext;
}

int main(int argc, char* argv[]) {

    std::string* inputFileName = nullptr;
    for(int i=1; i<argc; i++) {
        if(std::string(argv[i]) == "-f" && i+1<argc) {
            inputFileName = new std::string(argv[i+1]);
            // std::cout<<"Zanaleziono opcje -f " << *inputFileName << std::endl;
            break;
        }
    }

    std::istream* inputStream = &(std::cin);
    if(inputFileName != nullptr) {
        inputStream = new std::ifstream(inputFileName->c_str(), std::ifstream::in);
    }

    UIContext uiContext = createUIContext();

    std::cout << "Witaj w fabryce samochodów SzeligaMotors!" << std::endl;
    showMenu();
    bool running = true;
    while (running) {
        int commandNumber = getCommandFromConsole(inputStream);
        switch (commandNumber) {
            case 0:
                showMenu();
                break;
            case 1:
                showCarList(uiContext);
                break;
            case 2:
                produceCar(uiContext, inputStream);
                break;
            case 3:
                buyCar(uiContext, inputStream);
                break;
            case 4:
                showInventory(uiContext);
                break;
            case 5:
                showMyCar(uiContext);
                break;
            case 6:
                startMyCar(uiContext, inputStream);
                break;
            case 7:
                stopMyCar(uiContext);
                break;
            case 8:
                fillMyCar(uiContext, inputStream);
                break;
            case 9:
                saveMyFactoryToFile(uiContext, inputStream);
                break;
            case 10:
                saveMyCarToFile(uiContext, inputStream);
                break;
            case 11:
                readMyFactoryFromFile(uiContext, inputStream);
                break;
            case 12:
                readMyCarFromFile(uiContext, inputStream);
                break;
            case 13:
                running = false;
                std::cout << "\n\nPomyślnie zakończono działanie programu" << std::endl;
                break;
            default:
                std::cout << "Opcja o podanym numerze nie istnieje" << std::endl;
        }
    }

    // todo posprzątać po sobie?
    return 0;
}
