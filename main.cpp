#include "raylib.h"  // Inclure l'en-tête de Raylib
#include "Vue/Vue.h"
#include "modele/Labyrinth.h"
#include <vector>
#include <external/glad.h>

void DrawLabyrinth(Labyrinth labyrinth, int cellSize, Vue vue);
void PathFindings(Labyrinth labyrinth);

int main() {
    Labyrinth labyrinth;
    labyrinth.Print();
    Vue vue = Vue(1000, 1000);
    while (!WindowShouldClose()) {
        BeginDrawing();

        DrawLabyrinth(labyrinth, vue.GetScreenWidth(), vue);

        EndDrawing();
    }

    return 0; // Fin du programme
}

std::array <std :: tuple<int, int>, 4> GetNeighbor (Cellule maCellule, Labyrinth labyrinth)
{
    std::array <std :: tuple<int, int>, 4> ReturnNeighbor;
    std::tuple<int,int> coordinateOfmaCellule = maCellule.getCoordinate();
    auto [cellX, cellY] = coordinateOfmaCellule;
    int maxX = labyrinth.getCols();
    int maxY = labyrinth.getRows();
    int minX = 0;
    int minY = 0;
    std::tuple<int,int> UpNeighbor = std::tuple<int,int>(cellX , cellY+1);
    if (UpNeighbor > minY) {
       ReturnNeighbor[0] = UpNeighbor;
    }
    std::tuple<int,int> DownNeighbor = std::tuple<int,int>(cellX , cellY-1);
    std::tuple<int,int> LeftNeighbor = std::tuple<int,int>(cellX-1 , cellY);
    std::tuple<int,int> RightNeighbor = std::tuple<int,int>(cellX+1 , cellY);

}

void PathFindings(Labyrinth labyrinth) {
    void _BFS (std::vector<Cellule> visited, std::vector<Cellule> queue,Cellule end)
    {

    }

    std::vector<Cellule> visited;
    std::vector<Cellule> queue;

    Cellule start = labyrinth.GetStart();
    Cellule end = labyrinth.GetEnd();
    queue.push_back(start);
    
}


void GetColorByNumber(Color &backColor, Cellule const &cellule) {
    if (cellule.getNumber() == 0) {
        backColor = WHITE;
    } else if (cellule.getNumber() == -1) {
        backColor = GREEN;
    }
    else if (cellule.getNumber() == -2) {
        backColor = BLUE;
    }
    else {
        backColor = BLACK;
    }
}

void PrintNumber(int posY, int posX, Cellule const &cellule, Font const &fontChose, int const cellSize) {
    posX = posX + cellSize/2;
    posY = posY + cellSize/2;
    int const NumberToPrint = (48 + cellule.getNumber());
    Vector2 const Coord(static_cast<float>(posY), static_cast<float>(posX));
    DrawTextCodepoint(fontChose, NumberToPrint, Coord, 16, BLACK);

}

void DrawLabyrinth(Labyrinth const labyrinth, int cellSize, Vue const vue) {
    ClearBackground(RAYWHITE);

    std::tuple dimension = labyrinth.GetDimension();
    auto [TabSizeX, TabSizeY] = dimension;

    int decalage = static_cast<int>(cellSize * 0.125);
    cellSize = static_cast<int>(cellSize * 0.75);
    cellSize = cellSize / TabSizeX;

    for (int x = 0; x < TabSizeX; x++) {
        for (int y = 0; y < TabSizeY; y++) {
            int posX = (x * cellSize) + decalage;
            int posY = (y * cellSize) + decalage;

            Color backColor;
            Cellule cellule = labyrinth.GetCellule(x, y);
            GetColorByNumber(backColor, cellule);

            if (cellule.getNumber() == 1 || cellule.getNumber() == 0) {
                DrawRectangle(posY, posX, cellSize, cellSize, backColor);
            }
            else {
                posX = posX + cellSize/2;
                posY = posY + cellSize/2;
                DrawCircle(posY, posX, static_cast<char>(cellSize/2), backColor);
            }

            PrintNumber(posY, posX, cellule, vue.GetFont(), cellSize);
            //DrawRectangleLines(posX, posY, cellSize, cellSize, BLACK);
        }
    }
}
