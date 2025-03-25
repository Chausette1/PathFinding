#include <iostream>
#include <vector>
#include <deque>
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
    bool InShortestPath;

public:
    Cellule() {};
    explicit Cellule(const std::tuple<int, int> &coordinateOfCellule, int baseNumber);

    bool getIsWall() const;
    std::tuple<int, int> getCoordinate() const; // Const car elle ne modifie pas l'objet
    int getNumber() const; // Const car elle ne modifie pas l'objet
    void setNumber(int newNumber);
    void Print() const;
    bool IsSameCellule(const Cellule& other) const;
    std::string coordinateToString() const;
    bool GetIsInShortestPath() const;
    void SetIsInShortestPath(bool newIsInShortestPath);
};


#endif //CELLULE_H
