/*
* class.cpp
*
*  Created on: 1 Jan 2015
*      @Author: Viktor Zoutman
*/

#include <stdio.h>
#include "display.h"

namespace rlm {
    void Display::Create(Game* parent) {

        if (!glfwInit()) {
            printerr("Error initializing GLFW");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(1280, 720, "RLMexample", NULL, NULL);
        if (!window) {
            printerr("Failed to create window. Does your GPU support opengl 3+?");
            glfwTerminate();
        }

        glfwMakeContextCurrent(window);
        glewExperimental=true; // Needed in core profile
        if (glewInit() != GLEW_OK) {
            fprintf(stderr, "Failed to initialize GLEW\n");
            //return -1; TODO: EXIT TO LAZY UGH.
        }

        std::cout << "Hello:" << glGetString(GL_VERSION) << std::endl;
        parent->InitGame();

        while(!glfwWindowShouldClose(window)) {
    		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(0, 0, 0, 1);

            parent->GameLoop();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwTerminate();
    }

}
