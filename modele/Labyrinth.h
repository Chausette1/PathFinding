//
// Created by Chausette on 20-03-25.
//

#ifndef LABYRINTH_H
#define LABYRINTH_H

#include "case.h"
#include <iostream>
#include <array>

class Labyrinth {
private:
    Cellule** array;
    int rows;
    int cols;

public:
    Labyrinth();
    void Print() const;
    std::tuple<int,int> GetDimension() const;
    Cellule GetCellule(int x, int y) const;
};



#endif //LABYRINTH_H
