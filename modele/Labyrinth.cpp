//
// Created by Chausette on 20-03-25.
//

#include "Labyrinth.h"
#include <random>
#include <algorithm>
#include <stack>
#include <array>

#include <format>

Labyrinth::Labyrinth(bool Islab) {
    constexpr int arraySize = 91;
    rows = arraySize;
    cols = arraySize;

    array.resize(arraySize, std::vector<std::shared_ptr<Cellule> >(arraySize));

    std::vector<std::vector<int> > intArray;
    if (Islab) {
        intArray = GenerateMaze();
    } else {
        intArray = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
            {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
            {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
            {1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 1},
            {1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, -2, 0, 0, 0, 1},
            {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };
        rows = 17;
        cols = 17;
    }

    for (int i = 0; i < rows; i++) {
        array[i].resize(rows, std::shared_ptr<Cellule>());
        for (int j = 0; j < cols; j++) {
            Cellule cellule(std::tuple<int, int>(i, j), intArray[i][j]);
            array[i][j] = std::make_shared<Cellule>(cellule);
            if (cellule.getNumber() == -1) {
                Start = std::make_shared<Cellule>(cellule);
            }
            if (cellule.getNumber() == -2) {
                End = std::make_shared<Cellule>(cellule);
            }
            cellule.SetIsInShortestPath(false);
        }
    }
}

std::tuple<int, int> Labyrinth::GetDimension() const {
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

std::shared_ptr<Cellule> Labyrinth::GetCellule(int x, int y) const {
    return array[x][y];
}

std::shared_ptr<Cellule> Labyrinth::GetStart() const {
    return Start;
}

std::shared_ptr<Cellule> Labyrinth::GetEnd() const {
    return End;
}

int Labyrinth::getCols() const {
    return cols;
}

int Labyrinth::getRows() const {
    return rows;
}

std::vector<std::shared_ptr<Cellule> > Labyrinth::GetNeighbor(std::shared_ptr<Cellule> maCellule) {
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

void Labyrinth::_BFS(std::set<std::tuple<int, int> > visited,
                     std::deque<std::shared_ptr<Cellule> > &queue,
                     std::shared_ptr<Cellule> &end, Vue vue) {
    int layerSize = 1, NextLayerSize = 0, layer = 0;
    while (!queue.empty()) {
        if (layerSize == 0) {
            layerSize = NextLayerSize;
            NextLayerSize = 0;
            layer++;
            this->DrawLabyrinth(vue);
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(10ms);
        }

        std::shared_ptr<Cellule> CurrentCellule = queue.front();
        queue.pop_front();
        visited.insert(CurrentCellule->getCoordinate());
        layerSize--;

        if (CurrentCellule->getNumber() == -2) {
            end = CurrentCellule;
            return;
        }

        std::vector<std::shared_ptr<Cellule> > Neighbors = GetNeighbor(CurrentCellule);

        for (std::shared_ptr<Cellule> neighbor: Neighbors) {
            bool IsVisited = false;
            auto it = std::find(visited.begin(), visited.end(), neighbor->getCoordinate());
            if (it != visited.end()) {
                IsVisited = true;
            } else {
                IsVisited = false;
            }
            if (!neighbor->getIsWall() && !IsVisited) {
                queue.push_back(neighbor);
                NextLayerSize++;
            }
        }
        CurrentCellule->setNumber(layer);
    }
}

void Labyrinth::PathFiding(Vue vue) {
    std::set<std::tuple<int, int> > visited;
    std::deque<std::shared_ptr<Cellule> > queue;
    queue.push_back(Start);
    _BFS(visited, queue, End, vue);
    DiscoverShortestPath(vue);
}

void Labyrinth::DiscoverShortestPath(Vue vue) {
    std::shared_ptr<Cellule> temp;
    std::vector<std::shared_ptr<Cellule> > neigbhors = GetNeighbor(End);
    temp = neigbhors[0];
    for (std::shared_ptr<Cellule> neighbor: neigbhors) {
        if (neighbor->getNumber() > temp->getNumber()) {
            temp = neighbor;
        }
    }
    std::shared_ptr<Cellule> currentCellule = temp;
    while (currentCellule->getNumber() != -1) {
        currentCellule->SetIsInShortestPath(true);
        this->DrawLabyrinth(vue);
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(10ms);
        std::vector<std::shared_ptr<Cellule> > neigbhors = GetNeighbor(currentCellule);
        for (std::shared_ptr<Cellule> neighbor: neigbhors) {
            if ((neighbor->getNumber() < currentCellule->getNumber()) && neighbor->getNumber() != -2 && !neighbor->
                getIsWall() && neighbor->getNumber() != 0) {
                currentCellule = neighbor;
            }
        }
        if (currentCellule->getNumber() == -1) {
            break;
        }
    }
}

void Labyrinth::GetColorByNumber(Color &backColor, Cellule const &cellule) {
    if (cellule.getIsWall()) {
        backColor = BLACK;
    } else if (cellule.GetIsInShortestPath()) {
        backColor = Color(255, 135, 237, 255);
        return;
    } else {
        int num = cellule.getNumber();
        if (num == 0 || num == -1 || num == -2) {
            backColor = WHITE;
            return;
        }
        int pas = 1;
        int R = 139, G = 255, B = 243, A = 255;
        bool done = false;
        while (!done) {
            if (num <= (255 / pas) * 1) {
                R = 255;
                G = 0 + num * pas;
                B = 0;
                done = true;
            } else if (num <= (255 / pas) * 2) {
                R = 255 - num * pas;
                G = 255;
                B = 0;
                done = true;
            } else if (num <= (255 / pas) * 3) {
                R = 0;
                G = 255;
                B = 0 + num * pas;
                done = true;
            } else if (num <= (255 / pas) * 4) {
                R = 0;
                G = 255 - num * pas;
                B = 255;
                done = true;
            } else if (num <= (255 / pas) * 5) {
                R = 0 + num * pas;
                G = 0;
                B = 255;
                done = true;
            } else if (num <= (255 / pas) * 6) {
                R = 255;
                G = 0;
                B = 255 - num * pas;
                done = true;
            } else {
                num = num - (255 / pas) * 6;
            }
        }
        backColor = Color(R, G, B, A);
    }
}

void Labyrinth::DrawLabyrinth(Vue const vue) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    std::tuple dimension = this->GetDimension();
    auto [TabSizeX, TabSizeY] = dimension;

    int cellSize = vue.GetScreenHeight();
    int decalage = static_cast<int>(cellSize * 0.125);
    cellSize = static_cast<int>(cellSize * 0.75);
    cellSize = cellSize / TabSizeX;

    for (int x = 0; x < TabSizeX; x++) {
        for (int y = 0; y < TabSizeY; y++) {
            int posX = (x * cellSize) + decalage;
            int posY = (y * cellSize) + decalage;

            Color backColor;
            const Cellule cellule = *this->GetCellule(x, y);
            GetColorByNumber(backColor, cellule);

            DrawRectangle(posY, posX, cellSize, cellSize, backColor);

            if (cellule.getNumber() == -1 || cellule.getNumber() == -2) {
                posX = posX + cellSize / 2;
                posY = posY + cellSize / 2;
                DrawCircle(posY, posX, static_cast<char>(cellSize / 2), GREEN);
                posX = posX - cellSize / 2;
                posY = posY - cellSize / 2;
            }

            // PrintNumber(posY, posX, cellule, vue.GetFont(), cellSize);
            // DrawRectangleLines(posX, posY, cellSize, cellSize, BLACK);
        }
    }
    EndDrawing();
}

void Labyrinth::PrintNumber(int posY, int posX, Cellule const &cellule, Font const &fontChose, int const cellSize) {
    posY = posY + cellSize / 4;
    posX = posX + cellSize / 4;
    std::string str = std::to_string(cellule.getNumber());
    const char *charToPrint = str.c_str();
    DrawText(charToPrint, posY, posX, 16, BLACK);
}

void draw(std::vector<std::vector<int> > maze) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    std::tuple dimension = std::make_tuple(static_cast<int>(maze.size()), static_cast<int>(maze[0].size()));
    auto [TabSizeX, TabSizeY] = dimension;

    int cellSize = 1000;
    int decalage = static_cast<int>(cellSize * 0.125);
    cellSize = static_cast<int>(cellSize * 0.75);
    cellSize = cellSize / TabSizeX;

    for (int x = 0; x < TabSizeX; x++) {
        for (int y = 0; y < TabSizeY; y++) {
            int posX = (x * cellSize) + decalage;
            int posY = (y * cellSize) + decalage;

            Color backColor;
            if (maze[y][x] == 0) {
                backColor = WHITE;
            } else {
                backColor = BLACK;
            }

            DrawRectangle(posX, posY, cellSize, cellSize, backColor);
        }
    }
    EndDrawing();
}

void Labyrinth::_DFS(std::vector<std::vector<int> > &maze, std::tuple<int, int> coord,
                     std::vector<std::tuple<int, int> > &visited, std::vector<std::tuple<int, int> > &directions,
                     std::mt19937 &gen) {
    draw(maze);

    auto [x, y] = coord;
    visited.push_back(std::make_tuple(x, y));

    std::shuffle(directions.begin(), directions.end(), gen);

    for (auto [dx, dy]: directions) {
        int nx = x + dx;
        int ny = y + dy;

        bool isVisited = false;

        isVisited = std::find(visited.begin(), visited.end(), std::make_tuple(nx, ny)) != visited.end();


        if (nx > 0 && nx < rows - 1 && ny > 0 && ny < cols - 1 && maze[nx][ny] == 0 && !isVisited) {
            maze[x + dx / 2][y + dy / 2] = 0;
            _DFS(maze, std::make_tuple(nx, ny), visited, directions, gen);
        }
    }
}

void Labyrinth::DoMess(std::vector<std::vector<int> > &maze) {
    int messCount = cols;
    std::random_device rd;
    std::uniform_int_distribution<int> distrib(1, cols - 2); // Entre 1 et 100
    std::mt19937 gen(rd());
    for (int i = messCount - 1; i >= 0; i--) {
        bool done = false;
        while (!done) {
            int x = distrib(gen);
            int y = distrib(gen);

            if (maze[x][y] == 1 && ((maze[x - 1][y] == 1 && maze[x + 1][y] == 1 && maze[x][y - 1] == 0 && maze[x][y + 1]
                                     == 0) || ((
                                        maze[x][y - 1] == 1 && maze[x][y - 1] == 1 && maze[x - 0][y] == 0 && maze[x + 1]
                                        [y] == 0)))) {
                done = true;
                maze[x][y] = 0;
            }
        }

        draw(maze);
    }
}

std::vector<std::vector<int> > Labyrinth::GenerateMaze() {
    std::vector<std::vector<int> > maze(cols, std::vector<int>(rows, 1));
    for (int y = 0; y < cols; y++) {
        for (int x = 0; x < rows; x++) {
            if (x % 2 == 1 && y % 2 == 1) {
                maze[y][x] = 0;
            }
        }
    }

    std::vector<std::tuple<int, int> > visited;
    std::vector<std::tuple<int, int> > directions = {{0, -2}, {0, 2}, {-2, 0}, {2, 0}};
    std::random_device rd;
    std::mt19937 gen(rd());


    _DFS(maze, std::make_tuple(1, 1), visited, directions, gen);
    DoMess(maze);
    maze[1][1] = -1;
    maze[rows - 2][cols - 2] = -2;

    return maze;
}
