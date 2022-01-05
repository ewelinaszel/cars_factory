//
// Created by Ewelina Szeliga on 27.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_SPRAYER_H
#define SZELIGAEWELINA_ETAP1_SPRAYER_H


#include <fstream>
#include "Vehicle.h"

//Singleton
class Sprayer {
protected:
    static Sprayer *_instance;
    Sprayer();
    ~Sprayer();
public:
    Sprayer(Sprayer &other) = delete;

    void operator=(const Sprayer &) = delete;

    static Sprayer *getInstance();

    void changeColor(Vehicle &vehicle, Color color);

};


#endif //SZELIGAEWELINA_ETAP1_SPRAYER_H
