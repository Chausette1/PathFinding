#include "labyrinth.h"
#include <iostream>
#include <stack>
#include <tuple>
#include <random>
#include <algorithm>
#include "raylib.h"
#include <stack>
Labyrinth::Labyrinth(int r, int c) : rows(r), cols(c) {
    GenerateMaze();
}

Labyrinth::Labyrinth() {
    constexpr int arraySize = 25;
    rows = arraySize;
    cols = arraySize;

    array.resize(arraySize, std::vector<std::shared_ptr<Cellule>>(arraySize));

    std::array<std::array<int, arraySize>, arraySize> intArray = {
        {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, -1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
  {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1},
  {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
  {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, -2, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
}
    };

    for (int i = 0; i < arraySize; i++) {
        array[i].resize(arraySize, std::shared_ptr<Cellule>());
        for (int j = 0; j < arraySize; j++) {
            Cellule cellule(std::tuple<int,int>(i,j), intArray[i][j]);
            array[i][j] = std::make_shared<Cellule>(cellule);
            if (cellule.getNumber() == -1) {
                Start = std::make_shared<Cellule>(cellule);
            }
            if (cellule.getNumber() == -2) {
                End = std::make_shared<Cellule>(cellule);
            }
        }
    }
}

std::tuple<int,int> Labyrinth::GetDimension() const {
    return std::make_tuple(this->rows, cols);
}

void Labyrinth::Print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j]->Print();
        }
        std::cout << std::endl;
    }
}

std::shared_ptr<Cellule>  Labyrinth::GetCellule(int x, int y) const {
    return array[x][y];
}

std::shared_ptr<Cellule>  Labyrinth::GetStart() const {
    return Start;
}

std::shared_ptr<Cellule>  Labyrinth::GetEnd() const {
    return End;
}

int Labyrinth::getCols() const {
    return cols;
}

int Labyrinth::getRows() const {
    return rows;
}

std::vector<std::shared_ptr<Cellule> > Labyrinth::GetNeighbor(std::shared_ptr<Cellule>  maCellule) {
    std::vector<std::shared_ptr<Cellule> > ReturnNeighbor;
    auto [cellX, cellY] = maCellule->getCoordinate();
    int maxX = cols - 1;
    int maxY = rows - 1;
    int minX = 0;
    int minY = 0;
    if (cellY - 1 > minY) {
        ReturnNeighbor.push_back(GetCellule((cellX), (cellY - 1)));
    }
    if (cellY + 1 < maxY) {
        ReturnNeighbor.push_back(GetCellule((cellX), (cellY + 1)));
    }
    if (cellX - 1 > minX) {
        ReturnNeighbor.push_back(GetCellule((cellX - 1), (cellY)));
    }
    if (cellX + 1 < maxX) {
        ReturnNeighbor.push_back(GetCellule((cellX + 1), (cellY)));
    }
    return ReturnNeighbor;
}

void Labyrinth::_BFS(std::vector<std::shared_ptr<Cellule> > &visited, std::deque<std::shared_ptr<Cellule> > &queue, std::shared_ptr<Cellule>  &end, int count) {
    std::shared_ptr<Cellule>  CurrentCellule = queue.front();
    queue.pop_front();
    visited.push_back(CurrentCellule);

    if (CurrentCellule->getNumber() == -2) {
        end = CurrentCellule;
        return;
    }

    std::vector<std::shared_ptr<Cellule> > Neighbors = GetNeighbor(CurrentCellule);
    for (std::shared_ptr<Cellule>  neighbor: Neighbors) {
        bool IsVisited = false;
        for (std::shared_ptr<Cellule>  vis: visited) {
            IsVisited = neighbor->IsSameCellule(*vis);
            if (IsVisited) break;
        }
        if (!neighbor->getIsWall() && !IsVisited) {
            queue.push_back(neighbor);
        }
    }

    CurrentCellule->setNumber(count);

    _BFS(visited, queue, end);
}

void Labyrinth::PathFiding() {
    std::vector<std::shared_ptr<Cellule> > visited;
    std::deque<std::shared_ptr<Cellule> > queue;
    queue.push_back(Start);
    _BFS(visited, queue, End);
}

void Labyrinth::GenerateMaze() {
    rows = 25;
    cols = 25;

    array.clear();
    array.resize(rows,std::vector<std::shared_ptr<Cellule>>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j]=std::make_shared<Cellule>(std::tuple<int,int>(i,j),1);
        }
    }
    std::random_device rd;
    std::mt19937 gen(rd());

    int startX = 1;
    int startY = 1;
    array[startX][startY]->setNumber(0);
    Start = array[startX][startY];

    std::stack<std::tuple<int, int>> stack;


    stack.push({startX,startY});

    std::vector<std::tuple<int,int>> directions = {{0, -2}, {0, 2}, {-2, 0}, {2, 0}};

    while (!stack.empty()) {
        auto[x,y] = stack.top();
        stack.pop();

        std::shuffle(directions.begin(),directions.end(),gen);

        for (auto [dx,dy] : directions) {
            int nx = x+dx;
            int ny = y+dy;

            if (nx > 0 && nx < rows - 1 && ny > 0 && ny < cols -1 && array [nx][ny]->getNumber()==1) {
                array[nx][ny]->setNumber(0);
                array[x + dx / 2][y + dy / 2]->setNumber(0);
                stack.push({nx, ny});

            }
        }
    }
    End = array[rows - 2][cols - 2];
    End->setNumber(-2);


}

void Labyrinth::DrawMaze() {
    int cellSize = GetScreenWidth() / cols;

    for (int i =0; i< rows; i++) {
        for (int j =0; j<cols;j++) {
            int x= j * cellSize;
            int y= i * cellSize;

            if (array[i][j]->getNumber() == 1) {
                DrawRectangle(x, y, cellSize, cellSize, BLACK);
            } else if (array[i][j]->getNumber() == -2) {
                DrawRectangle(x, y, cellSize, cellSize, RED);
            } else {
                DrawRectangle(x, y, cellSize, cellSize, WHITE);
            }
        }
    }
}

