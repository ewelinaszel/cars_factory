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

    virtual int getCapacity() = 0;

    virtual void stop()=0;

    virtual void drive(double distance)=0;

    void setColor(Color color);

    const std::string &getBrand() const;

    const std::string &getModel() const;

    Color getColor() const;

    virtual bool isInstanceOf(VehicleSpecification *vehicleSpecification) = 0; //?czy const
};


#endif //SZELIGAEWELINA_ETAP1_VEHICLE_H
