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

void Cellule::setNumber(int newNumber) {
    number = newNumber;
}

bool Cellule::getIsWall() const {
    return isWall;
}

bool Cellule::IsSameCellule(const Cellule &other) const {
    auto [myX, myY] = this->coordinate;
    auto [otherX, otherY] = other.coordinate;
    bool Return = (myX == otherX) && (myY == otherY);
    return Return;
}

std::string Cellule::coordinateToString() const {
    auto [x, y] = coordinate;
    return std::format("{} {}", x, y);
}

bool Cellule::GetIsInShortestPath() const {
    return InShortestPath;
}

void Cellule::SetIsInShortestPath(bool newIsInShortestPath) {
    InShortestPath = newIsInShortestPath;
}