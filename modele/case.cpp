//
// Created by Chausette on 20-03-25.
//

#include "case.h"
#include <format>

Cellule::Cellule(const std::tuple<int,int> &coordinateOfCellule,const int baseNumber) {
    number = baseNumber;
    coordinate = coordinateOfCellule;
    if (number == 1) {
        isWall = true;
    }
    else {
        isWall = false;
    }
}

void Cellule::Print() const {
    std::string ToPrint = std::format("{} ", number);
    std::cout << ToPrint;
}

std::tuple<int, int> Cellule::getCoordinate() const {
    return coordinate;
}

int Cellule::getNumber() const {
    return number;
}




