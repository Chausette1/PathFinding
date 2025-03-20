#include "case.h";
#include <iostream>;
#include <array>;
//
// Created by Chausette on 20-03-25.
//

#ifndef LABYRINTH_H
#define LABYRINTH_H



class Labyrinth {
private:
    Cellule** array;
    int rows;
    int cols;

public:
    Labyrinth();
    void Print() const;
};



#endif //LABYRINTH_H
