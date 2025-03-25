#include "raylib.h"  // Inclure l'en-tête de Raylib
#include "Vue/Vue.h"
#include "modele/Labyrinth.h"
#include "Labyrinth.h"

#include <vector>
#include <deque>

void DrawLabyrinth(Labyrinth labyrinth, int cellSize, Vue vue);

int main() {
    Labyrinth lab(25,25);
    Labyrinth labyrinth;
    labyrinth.Print();
    Vue vue = Vue(1000, 1000);
    std::cout << std::endl << std::endl;
    labyrinth.PathFiding();
    while (!WindowShouldClose()) {
        BeginDrawing();

    lab.DrawMaze();

        EndDrawing();
    }

    return 0; // Fin du programme
}


void GetColorByNumber(Color &backColor, Cellule const &cellule) {
    if (cellule.getIsWall()) {
        backColor = BLACK;
    } else if (cellule.getNumber() == -1) {
        backColor = GREEN;
    } else if (cellule.getNumber() == -2) {
        backColor = BLUE;
    } else {
        backColor = WHITE;
    }
}

void PrintNumber(int posY, int posX, Cellule const &cellule, Font const &fontChose, int const cellSize) {
    posX = posX + cellSize / 2;
    posY = posY + cellSize / 2;
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
            Cellule cellule = *labyrinth.GetCellule(x, y);
            GetColorByNumber(backColor, cellule);

            if (cellule.getNumber() == 1 || cellule.getNumber() == 0) {
                DrawRectangle(posY, posX, cellSize, cellSize, backColor);
            } else {
                posX = posX + cellSize / 2;
                posY = posY + cellSize / 2;
                DrawCircle(posY, posX, static_cast<char>(cellSize / 2), backColor);
            }

            PrintNumber(posY, posX, cellule, vue.GetFont(), cellSize);
            //DrawRectangleLines(posX, posY, cellSize, cellSize, BLACK);
        }
    }

}
