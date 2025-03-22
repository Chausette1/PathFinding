//
// Created by Chausette on 22-03-25.
//

#include "Vue.h"
#include <iostream>

Vue::Vue(const int Width, const int Height) {
    this->screenWidth = Width;
    this->screenHeight = Height;
    this->name = "PathFinding- RayLib";
    InitWindow(this->screenWidth, this->screenHeight, this->name);
	SetTargetFPS(60);

    this->font = LoadFont("_deps/raylib-src/examples/text/resources/fonts/pixelplay.png");
    std::cout << "font load";
}

int Vue::GetScreenWidth() const{
    return this->screenWidth;
}

int Vue::GetScreenHeight() const {
    return this->screenHeight;
}

Font Vue::GetFont() const {
    return this->font;
}