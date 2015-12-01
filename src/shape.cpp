#include "shape.h"
#include "util.h"

namespace rlm {
    Shape::Shape() {
        glGenVertexArrays(1, &_vertexArrayID);
        glBindVertexArray(_vertexArrayID);

        static const GLfloat g_vertex_buffer_data[] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f,
        };

        // pos Buffer
        glGenBuffers(1, &_vertexbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

        //texture Buffer
		glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
	    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	    glEnableVertexAttribArray(1);
	    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    }

    Shape::~Shape() {

    }

    void Shape::Draw() {
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
        glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            0,
            (void*)0
        );

        glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
        glDisableVertexAttribArray(0);
    }

    Triangle::Triangle() {

    }

    Triangle::~Triangle() {

    }
}
