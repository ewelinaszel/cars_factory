//
// Created by Ewelina Szeliga on 17.12.2021.
//

#ifndef SZELIGAEWELINA_ETAP1_VEHICLE_H
#define SZELIGAEWELINA_ETAP1_VEHICLE_H

#include "CarSpecification.h"

enum class VehicleState {
    DRIVING,
    STANDING
};
std::ostream & operator<<(std ::ostream & result ,const VehicleState &carState);
std::istream &operator>>(std::istream &result, VehicleState &carState);

class Vehicle {
protected:
    std::string brand;
    std::string model;
    Color color;
    VehicleState state;
public:
    explicit Vehicle();

    explicit Vehicle(const std::string &brand, const std::string &model, Color color, VehicleState state);

    virtual ~Vehicle();

    VehicleState getState() const;

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
