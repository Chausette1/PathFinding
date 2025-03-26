//
// Created by Chausette on 22-03-25.
//

#include "Vue.h"
#include <iostream>

Vue::Vue(const int Width, const int Height) {
    this->screenWidth = Width;
    this->screenHeight = Height;
    this->name = "PathFinding- RayLib";
	SetTargetFPS(60);
}

int Vue::GetScreenWidth() const{
    return this->screenWidth;
}

int Vue::GetScreenHeight() const {
    return this->screenHeight;
}

char* Vue::GetName() const {
    return this->name;
}