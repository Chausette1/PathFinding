#include "raylib.h"
#include "Vue/Vue.h"
#include "modele/Labyrinth.h"

int main()
{
    Vue vue = Vue(1000, 1000);
    InitWindow(vue.GetScreenWidth(), vue.GetScreenHeight(), vue.GetName());
    Labyrinth labyrinth = Labyrinth(true);
    labyrinth.PathFiding(vue);
    while (!WindowShouldClose())
    {
        labyrinth.DrawLabyrinth(vue);

        if (IsKeyPressed(KEY_SPACE))
        {
            labyrinth.PathFiding(vue);
            std::cout << "aled?" << std::endl;
        }
        if (IsKeyPressed(KEY_R))
        {
            labyrinth = Labyrinth(true);
            std::cout << "aled?" << std::endl;
        }
        if (IsKeyPressed(KEY_Q))
        {
            labyrinth = Labyrinth(false);
            std::cout << "aled?" << std::endl;
        }
    }

    CloseWindow();
    return 0;
}