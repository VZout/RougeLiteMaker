/*
* class.cpp
*
*  Created on: 1 Jan 2015
*      @Author: Viktor Zoutman
*/

#include "display.h"

#include <stdio.h>
#include <vector>

namespace rlm {
    void Display::Create(Game* game, float width, float height, const char* title) {
        this->width = width;
        this->height = height;
        this->title = title;

        if (!glfwInit()) {
            printerr("Error initializing GLFW");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, "RLMexample", NULL, NULL);
        if (!window) {
            printerr("Failed to create window. Does your GPU support the requested context version?");
            game->Quit();
        }

        glfwMakeContextCurrent(window);
        glewExperimental=true; // Needed in core profile
        if (glewInit() != GLEW_OK) {
            printerr("Failed to initialize GLEW");
            game->Quit();
        }

        std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

        game->InitGame();

        while(!glfwWindowShouldClose(window)) {
    		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(0, 0, 0, 1);

            game->GameLoop();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwTerminate();
    }

}
