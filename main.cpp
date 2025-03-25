#include "raylib.h"
#include "Vue/Vue.h"
#include "modele/Labyrinth.h"

int main() {
    Vue vue = Vue(1000, 1000);
    Labyrinth labyrinth;
    labyrinth.GenerateMaze();

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_R)) {
            labyrinth.GenerateMaze();
        }

        if (IsKeyPressed(KEY_SPACE)) {
            labyrinth.PathFiding(vue);
            labyrinth.DiscoverShortestPath(vue);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        labyrinth.DrawMaze(vue);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}