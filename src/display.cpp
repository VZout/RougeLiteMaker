/*
* class.cpp
*
*  Created on: 1 Jan 2015
*      @Author: Viktor Zoutman
*/

#include "display.h"

namespace rlm {

    void Display::Create(Game* parent) {

        if (!glfwInit()) {
            printerr("Error initializing GLFW");
        }

        window = glfwCreateWindow(640, 480, "RLMexample", NULL, NULL);
        if (!window) {
            printerr("Failed to create window. Does your GPU support opengl 3+?");
            glfwTerminate();
        }

        glfwMakeContextCurrent(window);

        std::cout << glGetString(GL_VERSION) << std::endl;

        parent->InitGame();

        while(!glfwWindowShouldClose(window)) {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            parent->GameLoop();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwTerminate();
    }

}
