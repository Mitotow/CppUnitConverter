//
// Created by thomas on 9/23/23.
//

#include <algorithm>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include "Convertor.h"

double Convertor::convert(double dval, const std::string& dtype, const std::string& etype) {
    std::tuple<int, bool> dtypeinfo = Convertor::getTypeIndex(dtype);
    std::tuple<int, bool> etypeinfo = Convertor::getTypeIndex(etype);

    bool isDMetrics = std::get<1>(dtypeinfo);
    bool isEMetrics = std::get<1>(etypeinfo);

    int dindex = std::get<0>(dtypeinfo);
    int eindex = std::get<0>(etypeinfo);

    if(dindex < 0 || eindex < 0) throw std::invalid_argument("Invalid argument");

    if(isDMetrics) {
        double val = dval/std::pow(10, dindex);
        if(!isEMetrics) {
            double emi = kmToMi(val);
            return miToLower(emi, eindex);
        }
        return val;
    }

    double val = lowerToMi(dval, dindex);
    if(isEMetrics) {
        double ekm = miToKm(val);
        return ekm*std::pow(10, eindex);
    }

    return val;
}

std::tuple<int, bool> Convertor::getTypeIndex(const std::string& stype) {
    int index = -1;
    bool isMetric = false;

    for(int i = 0; i < Convertor::imperials.size()-1; i++) {
        if(Convertor::imperials[i] == stype) {
            isMetric = false;
            index = i;
            break;
        }
    }

    if(index == -1) {
        for(int i = 0; i < Convertor::metrics.size()-1; i++) {
            if(Convertor::metrics[i] == stype) {
                isMetric = true;
                index = i;
                break;
            }
        }
    }

    return std::make_tuple(index, isMetric);
}

double Convertor::kmToMi(const double km) {
    return km*0.621371;
}

double Convertor::miToKm(const double mi) {
    return mi*1.60934;
}

double Convertor::miToLower(const double mi, const int tindex) {
    switch (tindex) {
        case 0:
            return mi;
        case 1:
            return mi*1760;
        case 2:
            return mi*(1760*3);
        case 3:
            return mi*(1760*36);
        default:
            return -1;
    }
}

double Convertor::lowerToMi(const double lower, const int tindex) {
    switch (tindex) {
        case 0:
            return lower;
        case 1:
            return lower/1760;
        case 2:
            return lower/(1760*3);
        case 3:
            return lower/(1760*36);
        default:
            return -1;
    }
}