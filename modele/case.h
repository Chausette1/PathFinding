#include <iostream>
//
// Created by Chausette on 20-03-25.
//



#ifndef CELLULE_H
#define CELLULE_H


class Cellule {
private:
    std::tuple<int, int> coordinate;
    bool isWall;
    int number;

public:
    Cellule() {};
    explicit Cellule(const std::tuple<int, int> &coordinateOfCellule, int baseNumber);

    bool getIsWall() const;
    std::tuple<int, int> getCoordinate() const; // Const car elle ne modifie pas l'objet
    int getNumber() const; // Const car elle ne modifie pas l'objet
    void Print() const;
};


#endif //CELLULE_H
