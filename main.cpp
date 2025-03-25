#include "raylib.h"  // Inclure l'en-tête de Raylib
#include "Vue/Vue.h"
#include "modele/Labyrinth.h"
#include <format>

int main() {
    Labyrinth labyrinth;
    labyrinth.Print();
    Vue vue = Vue(1400, 1000);
    labyrinth.PathFiding(vue);
    labyrinth.DiscoverShortestPath(vue);
    while (!WindowShouldClose()) {
        labyrinth.DrawLabyrinth(vue);
    }

    return 0; // Fin du programme
}
