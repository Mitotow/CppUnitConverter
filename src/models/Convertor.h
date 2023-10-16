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
    double convert(double dval, const std::string& dtype, const std::string& etype);
private:
    const std::vector<std::string> metrics = {"km", "hm", "dam", "m", "dm", "cm", "mm", "um", "nm"};
    const std::vector<std::string> imperials = {"mile", "yard", "feet", "inch"};
    std::tuple<int, bool> getTypeIndex(const std::string& type);
    static double kmToMi(double km);
    static double miToKm(double mi);
    static double miToLower(double mi, int tindex);
    static double lowerToMi(double lower, int tindex);
};


#endif
