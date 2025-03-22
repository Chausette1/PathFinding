//
// Created by Chausette on 22-03-25.
//

#include "Vue.h"

Vue::Vue(const int Width, const int Height) {
    this->screenWidth = Width;
    this->screenHeight = Height;
    this->name = "PathFinding- RayLib";

    InitWindow(this->screenWidth, this->screenHeight, this->name);
}

int Vue::GetScreenWidth() const{
    return this->screenWidth;
}

int Vue::GetScreenHeight() const {
    return this->screenHeight;
}