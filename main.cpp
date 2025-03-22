#include "raylib.h"  // Inclure l'en-tête de Raylib
#include "Vue.h"
#include "modele/Labyrinth.h"

void DrawLabyrinth(Labyrinth labyrinth, int cellSize);

int main() {
    Labyrinth labyrinth;
    labyrinth.Print();
    Vue vue = Vue(1000, 1000);
    while (!WindowShouldClose()) {
        BeginDrawing();

        DrawLabyrinth(labyrinth, vue.GetScreenWidth());

        EndDrawing();
    }

    return 0; // Fin du programme
}

void DrawLabyrinth(Labyrinth labyrinth, int cellSize) {
    ClearBackground(RAYWHITE);

    std::tuple dimension = labyrinth.GetDimension();
    auto [TabSizeX, TabSizeY] = dimension;

    int decalage = cellSize * 0.125;
    cellSize = cellSize * 0.75;
    cellSize = cellSize / TabSizeX;

    for (int x = 0; x < TabSizeX; x++) {
        for (int y = 0; y < TabSizeY; y++) {
            int posX = (x * cellSize) + decalage;
            int posY = (y * cellSize) + decalage;

            Color backColor;
            Cellule cellule = labyrinth.GetCellule(x, y);
            if (cellule.getNumber() == 0) {
                backColor = {255, 255, 255, 255};
            } else if (cellule.getNumber() == -1) {
                backColor = GREEN;
            }
            else if (cellule.getNumber() == -2) {
                backColor = BLUE;
            }
            else {
                backColor = {0, 0, 0, 255};
            }
            DrawRectangle(posX, posY, cellSize, cellSize, backColor);
            //DrawRectangleLines(posX, posY, cellSize, cellSize, BLACK);
        }
    }
}
