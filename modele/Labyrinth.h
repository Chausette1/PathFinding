//
// Created by Chausette on 20-03-25.
//

#ifndef LABYRINTH_H
#define LABYRINTH_H

#include "case.h"
#include "../vue/vue.h"
#include <memory>
#include <thread>
#include <iostream>
#include <array>
#include <random>
#include <algorithm>
#include <set>

class Labyrinth {
private:
    std::vector<std::vector<std::shared_ptr<Cellule> > > array;
    int rows;
    int cols;
    std::shared_ptr<Cellule> Start;
    std::shared_ptr<Cellule> End;

    void _BFS(std::set<std::tuple<int, int>> visited, std::deque<std::shared_ptr<Cellule> > &queue,
              std::shared_ptr<Cellule> &end, Vue vue);

    void GetColorByNumber(Color &backColor, Cellule const &cellule);

    void PrintNumber(int posY, int posX, Cellule const &cellule, Font const &fontChose, int const cellSize);

    std::vector<std::vector<int> > GenerateMaze();

    void _DFS(std::vector<std::vector<int> > &maze, std::tuple<int, int> coord,
                     std::vector<std::tuple<int, int> > &visited, std::vector<std::tuple<int, int> > &directions,
                     std::mt19937 &gen);

    void DoMess(std::vector<std::vector<int> > &maze);

public:
    Labyrinth(bool IsLab);

    void Print() const;

    std::tuple<int, int> GetDimension() const;

    std::shared_ptr<Cellule> GetCellule(int x, int y) const;

    std::shared_ptr<Cellule> GetStart() const;

    std::shared_ptr<Cellule> GetEnd() const;

    int getRows() const;

    int getCols() const;

    void PathFiding(Vue vue);

    std::vector<std::shared_ptr<Cellule> > GetNeighbor(std::shared_ptr<Cellule> maCellule);

    void DrawLabyrinth(Vue const vue);

    void DiscoverShortestPath(Vue vue);
};


#endif //LABYRINTH_H
