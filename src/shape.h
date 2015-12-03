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
#include "vertex.h"
#include "shader.h"
#include "texture.h"
#include "drawable.h"

namespace rlm {

    class Shape : public Drawable {
    protected:
        void InitializeShape(Vertex* vertices);

        static const unsigned int NUM_BUFFERS = 3;
        unsigned int numVertices;
        GLuint _vertexArrayID;
        GLuint _vertexbuffer;
        GLuint vertexArrayBuffers[NUM_BUFFERS];

    public:
        Shape();
        Shape(glm::vec2 pos);
        ~Shape();
        void Draw();

    };

    class Triangle : public Shape {
    public:
        Triangle();
        Triangle(glm::vec2 pos, glm::vec2 size);
        ~Triangle();
    };

    class Rectangle : public Shape {
    private:
        glm::vec2 pos;
    public:
        Rectangle();
        Rectangle(glm::vec2 pos, glm::vec2 size);
        glm::vec2 GetCenter();
        ~Rectangle();
    };
}

#endif
