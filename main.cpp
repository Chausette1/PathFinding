#include "raylib.h"
#include "Vue/Vue.h"
#include "modele/Labyrinth.h"

int main()
{
    Vue vue = Vue(1000, 1000);
    InitWindow(vue.GetScreenWidth(), vue.GetScreenHeight(), vue.GetName());
    InitAudioDevice();
    SetMasterVolume(100);
    Sound music = LoadSound("musique.wav");
    Sound TATADA = LoadSound("TATADA.wav");
    Labyrinth labyrinth = Labyrinth(true);
    while (!WindowShouldClose())
    {
        labyrinth.DrawLabyrinth(vue);

        if (IsKeyPressed(KEY_SPACE))
        {
            PlaySound(music);
            labyrinth.PathFiding(vue);
            StopSound(music);
            PlaySound(TATADA);
        }
        if (IsKeyPressed(KEY_R))
        {
            labyrinth = Labyrinth(true);
        }
        if (IsKeyPressed(KEY_Q))
        {
            labyrinth = Labyrinth(false);
        }
    }

    CloseWindow();
    return 0;
}