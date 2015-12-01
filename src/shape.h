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
        GLuint _vertexArrayID;
        GLuint _vertexbuffer;

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
