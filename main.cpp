#include <iostream>
#include <deque>
#include "Car.h"
#include "SalesDepartment.h"

std::string LINE_PREFIX = "  ";

void showMenu() {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Wybierz interesującą Cię opcje:" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
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

int getCommandFromConsole() {
    int i;
    std::cout << "Podaj numer opcji: ";
    std::cin >> i;
    return i;
}

struct UIContext {
    SalesDepartment salesDepartment;
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
    std::vector<CarSpecification> availableCarSpecifications = uiContext.salesDepartment.getListOfAvailableModelsOfCars();
    int i = 0;
    for (std::vector<CarSpecification>::iterator it = availableCarSpecifications.begin();
        it != availableCarSpecifications.end(); ++it) {
        std::cout << LINE_PREFIX <<"[" << ++i << "] " << *it << std::endl;
    }
}

void produceCar(UIContext &uiContext) {
    std::cout << "Podaj index: ";
    int i;
    std::cin >> i;

    try {
        CarSpecification chosenCarSpecification = uiContext.salesDepartment.getListOfAvailableModelsOfCars().at(i-1);
        uiContext.salesDepartment.orderCar(chosenCarSpecification);
    }
    catch (const std::out_of_range& oor) {
        int n = uiContext.salesDepartment.getListOfAvailableModelsOfCars().size();
        std::cout << LINE_PREFIX <<"Niepoprawny numer specyfikacji " << i << ". Index powinien mieścić się w zakresie [1, " << n << "]" << std::endl;
    }
}

void buyCar(UIContext &uiContext) {
    std::cout << "Podaj index: ";
    int i;
    std::cin >> i;

    try {
        CarSpecification chosenCarSpecification = uiContext.salesDepartment.getListOfAvailableModelsOfCars().at(i-1);
        uiContext.currentCar = uiContext.salesDepartment.sellCar(chosenCarSpecification);
    }
    catch (const std::out_of_range& oor) {
        int n = uiContext.salesDepartment.getListOfAvailableModelsOfCars().size();
        std::cout << LINE_PREFIX <<"Niepoprawny numer specyfikacji " << i << ". Index powinien mieścić się w zakresie [1, " << n << "]" << std::endl;
    }
}

void showInventory(UIContext &uiContext) {
    std::cout << uiContext.salesDepartment.getCarFactory();
}

void showMyCar(UIContext &uiContext){
    if(checkIfCurrentCarNullptr(uiContext)){ return; }
    std::cout << *uiContext.currentCar << std::endl;
}

void startMyCar(UIContext &uiContext){
    double distance;
    std:: cout<<"Podaj ilość kilometrów do przejechania: "<< std::endl;
    std::cin>>distance;
    if(checkIfCurrentCarNullptr(uiContext)){ return; }
    uiContext.currentCar->drive(distance);
}

void stopMyCar(UIContext &uiContext){
    if(checkIfCurrentCarNullptr(uiContext)){ return; }
    uiContext.currentCar->stop();
}

void fillMyCar(UIContext &uiContext){
    if(checkIfCurrentCarNullptr(uiContext)){ return; }
    int amountOfFuel;
    std::cout << "Podaj ilość substancji napędowej:" << std::endl;
    std::cin >> amountOfFuel;
    uiContext.currentCar->fill(amountOfFuel);
}

void saveMyFactoryToFile(UIContext &uiContext){
    std::string fileName;
    std::cout << "Podaj nazwę pliku" << std::endl;
    std::cin >> fileName;

    std::ofstream file;
    file.open (fileName, std::ofstream::out);

    file << uiContext.salesDepartment.getCarFactory();
    file.close();
    std::cout << "Zapis zakończony powodzeniem" << std::endl;
}

void saveMyCarToFile(UIContext &uiContext){
    if(checkIfCurrentCarNullptr(uiContext)){ return; }

    std::string fileName;
    std::cout << "Podaj nazwę pliku" << std::endl;
    std::cin >> fileName;

    std::ofstream file;
    file.open (fileName, std::ofstream::out);
    file << *uiContext.currentCar;
    file.close();
}

void readMyFactoryFromFile(UIContext &uiContext){
    std::string fileName;
    std::cout << "Podaj nazwę pliku" << std::endl;
    std::cin >> fileName;

    std::ifstream file;
    file.open(fileName, std::ofstream::in);

    if(!file) {
        std::cout << "Plik nie istnieje. Nie można wczytać fabryki." << std::endl;
        return;
    }

    CarFactory *carFactoryFromFile = new CarFactory();
    file >> *carFactoryFromFile;
    file.close();

    uiContext.salesDepartment.setCarFactory(*carFactoryFromFile);
}

void readMyCarFromFile(UIContext &uiContext){
    std::string fileName;
    std::cout << "Podaj nazwę pliku" << std::endl;
    std::cin >> fileName;

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

int main() {

    CarSpecification specification1{"BMW", "Seria-3", Color::BLACK, 12.0, 150};
    CarSpecification specification2{"Mercedes-Benz", "E-klasa", Color::WHITE, 12.5, 160};
    CarSpecification specification3{"Audi", "A4", Color::SILVER, 9.0, 155};
    CarSpecification specification4{"Chevrolet", "Captiva", Color::GOLD, 12.0, 360};

    CarFactory carFactory;
    SalesDepartment salesDepartment{
            std::vector<CarSpecification>{specification1, specification2, specification3, specification4}, carFactory};

    Car *currentCar = nullptr;

    UIContext uiContext;
    uiContext.salesDepartment = salesDepartment;
    uiContext.currentCar = currentCar;

    std::cout << "Witaj w fabryce samochodów SzeligaMotors!" << std::endl;
    while (true) {
        showMenu();
        int commandNumber = getCommandFromConsole();
        switch (commandNumber) {
            case 1:
                showCarList(uiContext);
                break;
            case 2:
                produceCar(uiContext);
                break;
            case 3:
                buyCar(uiContext);
                break;
            case 4:
                showInventory(uiContext);
                break;
            case 5:
                showMyCar(uiContext);
                break;
            case 6:
                startMyCar(uiContext);
                break;
            case 7:
                stopMyCar(uiContext);
                break;
            case 8:
                fillMyCar(uiContext);
                break;
            case 9:
                saveMyFactoryToFile(uiContext);
                break;
            case 10:
                saveMyCarToFile(uiContext);
                break;
            case 11:
                readMyFactoryFromFile(uiContext);
                break;
            case 12:
                readMyCarFromFile(uiContext);
                break;
            default:
                std::cout << "Opcja o podanym numerze nie istnieje" << std::endl;
        }
    }
    return 0;
}
