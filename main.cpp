#include "raylib.h"  // Inclure l'en-tête de Raylib
#include "Vue/Vue.h"
#include "modele/Labyrinth.h"
#include <format>

int main() {
    Vue vue = Vue(1000, 1000);
    Labyrinth labyrinth = Labyrinth(true);
    while (!WindowShouldClose()) {
        labyrinth.DrawLabyrinth(vue);
        if (IsKeyPressed(KEY_SPACE)) {
            labyrinth.PathFiding(vue);
            labyrinth.DiscoverShortestPath(vue);
        }
        if (IsKeyPressed(KEY_R)) {
            labyrinth = Labyrinth(true);
        }
        if (IsKeyPressed(KEY_Q)) {
            labyrinth = Labyrinth(false);
        }
    }

    return 0; // Fin du programme
}
