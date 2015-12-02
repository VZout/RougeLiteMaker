/*
* shape.h
*
*  Created on: 27 Nov 2015
*      @Author: Viktor Zoutman
*/

#ifndef SHAPE_H_
#define SHAPE_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace rlm {

    class Shape {
    private:
        // This will identify our vertex buffer

        static const unsigned int NUM_BUFFERS = 2;

        GLuint _vertexArrayID;
        GLuint _vertexbuffer;

        GLuint vertexArrayBuffers[NUM_BUFFERS];

    public:
        Shape();
        ~Shape();
        void Draw();
    };

    class Triangle : public Shape {
    public:
        Triangle();
        ~Triangle();
    };

    class Rectangle : public Shape {
        Rectangle();
        ~Rectangle();
    };
}

#endif
