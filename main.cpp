#include "raylib.h"  // Inclure l'en-tête de Raylib
#include "modele/Labyrinth.h"

int main() {
    Labyrinth labyrinth;
    labyrinth.Print();
    // Initialisation de la fenêtre avec une résolution de 800x450 (ratio 16:9)
    InitWindow(800, 450, "Raylib - PathFinding");
    SetWindowTitle("hello");
    SetTargetFPS(60);  // Limiter le taux de rafraîchissement à 60 FPS

    // Boucle principale du programme
    while (!WindowShouldClose()) {  // Continuer tant que la fenêtre n'est pas fermée
        // Début du dessin
        BeginDrawing();

        // Effacer l'arrière-plan avec une couleur (bleu ciel)
        ClearBackground(SKYBLUE);

        // Ajouter ici vos dessins ou logiques de jeu
        // Exemple : Dessiner un texte au centre de l'écran
        DrawText("Hello, PathFinding!", 250, 200, 30, DARKGRAY);

        // Fin du dessin
        EndDrawing();
    }

    // Fermer la fenêtre et libérer les ressources
    CloseWindow();

    return 0;  // Fin du programme
}