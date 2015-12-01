#include "shape.h"
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glew.h>
#include "util.h"
#include "vertex.h"

namespace rlm {
    Shape::Shape() {
        //Vertex manipulation
        Vertex vertices[] = {
                Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
                Vertex(glm::vec3(-0, 0.5, 0), glm::vec2(0.5, 1.0)),
                Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)),
        };

        unsigned int numVertices = sizeof(vertices)/sizeof(vertices[0]);

        IndexedModel model;

		for(unsigned int i = 0; i < numVertices; i++) {
			model.positions.push_back(*vertices[i].GetPos());
			model.texCoords.push_back(*vertices[i].GetTexCoord());
		}
        //end vertex manipulation

        glGenVertexArrays(1, &_vertexArrayID);
        glBindVertexArray(_vertexArrayID);
        glGenBuffers(2, &_vertexbuffer); // 2 buffers

        // pos Buffer
        glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(model.positions[0]) * model.positions.size(), &model.positions[0], GL_STATIC_DRAW);

        //texture Buffer
		glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
	    glBufferData(GL_ARRAY_BUFFER, sizeof(model.texCoords[0]) * model.texCoords.size(), &model.texCoords[0], GL_STATIC_DRAW);
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
