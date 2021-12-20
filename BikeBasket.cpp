//
// Created by Ewelina Szeliga on 20.12.2021.
//

#include "BikeBasket.h"

BikeBasket::BikeBasket(int basketCapacity) : basketCapacity(basketCapacity) {}

int BikeBasket::getBasketCapacity() const {
    return basketCapacity;
}
