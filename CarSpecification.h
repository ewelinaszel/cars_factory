//
// Created by Ewelina Szeliga on 27.11.2021.
//

#ifndef FABRYKA_CARSPECIFICATION_H
#define FABRYKA_CARSPECIFICATION_H


class CarSpecification {
    std:: string brand;
    std:: string model;

public:
    CarSpecification(const std::string &brand, const std::string &model);

    const std::string &getBrand() const;

    const std::string &getModel() const;

};


#endif //FABRYKA_CARSPECIFICATION_H
