//
// Created by thomas on 9/23/23.
//

#ifndef CONVERTOR_H
#define CONVERTOR_H

#include <iostream>
#include <tuple>
#include <vector>

class Convertor {
public:
    double convert(double dval, std::string dtype, std::string etype);
private:
    const std::vector<std::string> metrics = {"km", "hm", "dam", "m", "dm", "cm", "mm", "um", "nm"};
    const std::vector<std::string> imperials = {"mile", "yard", "feet", "inch"};
    const double MITOKM = 1.609344;
    const double KMTOMI = 0.62137119;
    std::tuple<int, bool> getTypeIndex(std::string type);
    double kmToMi(const double km);
    double miToKm(const double mi);
    double miToLower(const double mi, const int tindex);
    double lowerToMi(const double lower, const int tindex);
};


#endif
