//
// Created by Chausette on 20-03-25.
//

#ifndef LABYRINTH_H
#define LABYRINTH_H

#include "case.h"
#include <memory>
#include <vector>
#include <memory>
#include <stack>
#include <tuple>
#include <iostream>
#include <array>

class Labyrinth {
private:
    std::vector<std::vector<std::shared_ptr<Cellule>>> array;
    int rows;
    int cols;
    std::shared_ptr<Cellule>  Start;
    std::shared_ptr<Cellule>  End;
    void _BFS(std::vector<std::shared_ptr<Cellule> > &visited, std::deque<std::shared_ptr<Cellule> > &queue, std::shared_ptr<Cellule>  &end, int count = 1);
public:
    Labyrinth();
    void Print() const;
    std::tuple<int,int> GetDimension() const;
    std::shared_ptr<Cellule>  GetCellule(int x, int y) const;
    std::shared_ptr<Cellule>  GetStart() const;
    std::shared_ptr<Cellule>  GetEnd() const;
    int getRows() const;
    int getCols() const;
    void PathFiding();
    std::vector<std::shared_ptr<Cellule> > GetNeighbor(std::shared_ptr<Cellule>  maCellule);

    void GenerateMaze();
    void DrawMaze();
    Labyrinth(int rows, int cols);


};



#endif //LABYRINTH_H
