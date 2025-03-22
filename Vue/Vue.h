//
// Created by Chausette on 22-03-25.
//

#ifndef VUE_H
#define VUE_H

#include <string>
#include "raylib.h"


class Vue {

private:
    int screenWidth;
    int screenHeight;
    char* name;
    Font font;


public:
    Vue(const int Width = 1200, const int Height = 1200);
    int GetScreenWidth() const;
    int GetScreenHeight() const;
    Font GetFont() const;
};



#endif //VUE_H
