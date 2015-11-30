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
#include <iostream>
#include <game.h>

#include "util.h"

namespace rlm {

class Game;

    class Display {
    public:
        void Create(Game* parent);

        GLFWwindow* window;
    };
}

#endif
