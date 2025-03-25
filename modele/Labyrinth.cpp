//
// Created by Chausette on 20-03-25.
//

#include "Labyrinth.h"
#include <random>
#include <algorithm>
#include <stack>
#include <array>


Labyrinth::Labyrinth() {
    constexpr int arraySize = 25;
    rows = arraySize;
    cols = arraySize;

    array.resize(arraySize, std::vector<std::shared_ptr<Cellule> >(arraySize));

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
            {1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
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

void Labyrinth::_BFS(std::vector<std::shared_ptr<Cellule>>& visited,
                    std::deque<std::shared_ptr<Cellule>>& queue,
                    std::shared_ptr<Cellule>& end, Vue vue) {
    std:: unordered_map <std::shared_ptr<Cellule>, std::shared_ptr<Cellule>> parent;

    int layerSize = 1, NextLayerSize = 0, layer = 0;
    while (!queue.empty()) {
        if (layerSize == 0) {
            layerSize = NextLayerSize;
            NextLayerSize = 0;
            layer++;
            this->DrawLabyrinth(vue);
            std::this_thread::sleep_for(100ms);
        }

        std::shared_ptr<Cellule> CurrentCellule = queue.front();
        queue.pop_front();
        visited.push_back(CurrentCellule);
        layerSize--;

        if (CurrentCellule->getNumber() == -2) {
            end = CurrentCellule;
            return;
        }

        std::vector<std::shared_ptr<Cellule>> Neighbors = GetNeighbor(CurrentCellule);
        for (std::shared_ptr<Cellule> neighbor : Neighbors) {
            bool IsVisited = false;
            for (std::shared_ptr<Cellule> vis : visited) {
                IsVisited = neighbor->IsSameCellule(*vis);
                if (IsVisited) break;
            }
            if (!neighbor->getIsWall() && !IsVisited) {
                parent[neighbor] = CurrentCellule;
                queue.push_back(neighbor);
                NextLayerSize++;
                neighbor->setNumber(layer + 1);
            }
        }
    }
}

void Labyrinth::DiscoverShortestPath(Vue vue) {
    std::shared_ptr<Cellule> current = End;

    while (current != Start) {
        current->SetIsInShortestPath(true);
        this->DrawLabyrinth(vue);
        std::this_thread::sleep_for(100ms);

        std::vector<std::shared_ptr<Cellule>> neighbors = GetNeighbor(current);
        std::shared_ptr<Cellule> next = nullptr;
        int minValue = INT_MAX;

        for (auto neighbor : neighbors) {
            if (neighbor->getNumber() < minValue && !neighbor->getIsWall()) {
                minValue = neighbor->getNumber();
                next = neighbor;
            }
        }

        if (!next) break;
        current = next;
    }

    Start->SetIsInShortestPath(true);
    this->DrawLabyrinth(vue);
}

void Labyrinth::GetColorByNumber(Color& backColor, Cellule const& cellule) {
    if (cellule.getIsWall()) {
        backColor = BLACK;
    }
    else if (cellule.GetIsInShortestPath()) {
        backColor = RED;
    }
    else if (cellule.getNumber() == -1) {
        backColor = GREEN;
    }
    else if (cellule.getNumber() == -2) {
        backColor = BLUE;
    }
    else if (cellule.getNumber() > 0) {
        int intensity = std::min(200, cellule.getNumber() * 5);
        backColor = Color(100, 100, 255 - intensity, 150);
    }
    else {
        backColor = WHITE;
    }
}

void Labyrinth::PathFiding(Vue vue) {
    std::vector<std::shared_ptr<Cellule>> visited;
    std::deque<std::shared_ptr<Cellule>> queue;
    queue.push_back(Start);
    _BFS(visited, queue, End, vue);
    DiscoverShortestPath(vue);
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

            PrintNumber(posY, posX, cellule, vue.GetFont(), cellSize);
            //DrawRectangleLines(posX, posY, cellSize, cellSize, BLACK);
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

void Labyrinth::GenerateMaze(){
    rows=25;
    cols=25;

    array.clear();
    array.resize(rows,std::vector<std::shared_ptr<Cellule>>(cols));

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            array[i][j]=std::make_shared<Cellule>(std::tuple<int,int>(i,j),1);
        }
    }
    std::random_device rd;
    std:: mt19937 gen (rd());

    int startX=1;
    int startY=1;
    array[startX][startY]->setNumber(0);
    Start=array[startX][startY];

    std::stack<std::tuple<int,int>>stack;


    stack.push({startX,startY});

    std::vector<std::tuple<int,int>>directions={{0,-2},{0,2},{-2,0},{2,0}};

    while(!stack.empty()){
        auto[x,y]=stack.top();
        stack.pop();

        std::shuffle(directions.begin(),directions.end(),gen);

        for(auto[dx,dy]:directions){
            int nx=x+dx;
            int ny=y+dy;

            if(nx>0&&nx<rows-1&&ny>0&&ny<cols-1&&array[nx][ny]->getNumber()==1){
                array[nx][ny]->setNumber(0);
                array[x+dx/2][y+dy/2]->setNumber(0);
                stack.push({nx,ny});

            }
        }
    }
    End = array [rows-2][cols-2];
    End->setNumber(-2);


}



void Labyrinth :: DrawMaze(Vue vue){
    int cellSize=GetScreenWidth()/cols;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int x=j*cellSize;
            int y=i*cellSize;

            if(array[i][j]->getNumber()==1){
                DrawRectangle(x,y,cellSize,cellSize,BLACK);
            }else if(array[i][j]->getNumber()==-2){
                DrawRectangle(x,y,cellSize,cellSize,RED);
            }else{
                DrawRectangle(x,y,cellSize,cellSize,WHITE);
            }
        }
    }
}

