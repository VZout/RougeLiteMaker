/*
* display.h
*
*  Created on: 18 Nov 2015
*      @Author: Viktor Zoutman
*/

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "input.h"
#include <iostream>
#include <game.h>

#include "util.h"

namespace rlm {

class Game;

    class Display {
    private:
        GLFWwindow* window;
        float width;
        float height;
        const char* title;
    public:
        void Create(Game* game, float width, float height, const char* title);

        float GetWidth() { return width; }
        float GetHeight() { return height; }
        const char* GetTitle() { return title; }
    };
}

#endif
