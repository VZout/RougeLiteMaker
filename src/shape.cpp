#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include "shape.h"
#include "util.h"
#include "game.h"
#include "color.h"

namespace rlm {
    Shape::Shape() : Drawable() {
        shader = new rlm::Shader("res/basicShader");
    }

    void Shape::InitializeShape(Vertex* vertices) {
        IndexedModel model;

		for(unsigned int i = 0; i < numVertices; i++) {
			model.positions.push_back(*vertices[i].GetPos());
			model.texCoords.push_back(*vertices[i].GetTexCoord());
            model.colors.push_back(*vertices[i].GetColor());
		}

        glGenVertexArrays(1, &_vertexArrayID);
        glBindVertexArray(_vertexArrayID);
        glGenBuffers(NUM_BUFFERS, vertexArrayBuffers); // 3 buffers

        // pos Buffer
        glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_VB]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(model.positions[0]) * model.positions.size(), &model.positions[0], GL_STATIC_DRAW);

        //texture Buffer
		glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[TEXCOORD_VB]);
	    glBufferData(GL_ARRAY_BUFFER, sizeof(model.texCoords[1]) * model.texCoords.size(), &model.texCoords[0], GL_STATIC_DRAW);

        //color Buffer
        glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[COLOR_VB]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(model.colors[0]) * model.colors.size(), &model.colors[0], GL_STATIC_DRAW);
    }

    Shape::Shape(glm::vec2 pos) {
        transform.setPos(glm::vec3(pos,0));
    }

    Shape::~Shape() {
    }

    void Shape::Draw() {
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);

        glBindVertexArray(_vertexArrayID);
        glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_VB]);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[TEXCOORD_VB]);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[COLOR_VB]);
        glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        //shader->bind();
        //shader->update(transform, Game::camera); TODO triangles should have a shader possibly.
        glDrawArrays(GL_TRIANGLES, 0, numVertices); // Starting from vertex 0; 3 vertices total -> 1 triangle

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);
    }

    Triangle::Triangle() {
        Vertex vertices[] = {
                Vertex(glm::vec3(0.0, 0.0, 0), glm::vec2(0.0, 1.0), glm::vec4(1,1,0,1)),
                Vertex(glm::vec3(0.0, 500.0, 0), glm::vec2(0.0, 0.0), glm::vec4(0,1,0,1)),
                Vertex(glm::vec3(500.0, 500.0, 0), glm::vec2(1.0, 0.0), glm::vec4(0,1,1,1)),
        };

        numVertices = sizeof(vertices)/sizeof(vertices[0]);
        InitializeShape(vertices);
    }

    Triangle::Triangle(glm::vec2 pos, glm::vec2 size) {
        transform.setPos(glm::vec3(pos, 0));

        Vertex vertices[] = {
                Vertex(glm::vec3(0, size.y, 0), glm::vec2(0.0, 1.0), Color::GREEN),
                Vertex(glm::vec3(size.x / 2, 0, 0), glm::vec2(0.5, 1.0), Color::RED),
                Vertex(glm::vec3(size.x, size.y, 0), glm::vec2(0.0, 0.0), Color::BLUE),
        };

        numVertices = sizeof(vertices)/sizeof(vertices[0]);
        InitializeShape(vertices);
    }

    Triangle::~Triangle() {

    }

    Rectangle::Rectangle() {
        Vertex vertices[] = {
                Vertex(glm::vec3(0.0, 0.0, 0), glm::vec2(0.0, 1.0), glm::vec4(1,1,0,1)),
                Vertex(glm::vec3(0.0, 100.0, 0), glm::vec2(0.0, 0.0), glm::vec4(1,1,0,1)),
                Vertex(glm::vec3(100.0, 100.0, 0), glm::vec2(1.0, 0.0), glm::vec4(1,1,0,1)),

                Vertex(glm::vec3(0.0, 0.0, 0), glm::vec2(0.0, 1.0), glm::vec4(1,1,0,1)),
                Vertex(glm::vec3(100.0, 0.0, 0), glm::vec2(1.0, 1.0), glm::vec4(1,1,0,1)),
                Vertex(glm::vec3(100.0, 100.0, 0), glm::vec2(1.0, 0.0), glm::vec4(1,1,0,1)),
        };

        numVertices = sizeof(vertices)/sizeof(vertices[0]);
        InitializeShape(vertices);
    }

    Rectangle::Rectangle(glm::vec2 pos, glm::vec2 size) : Shape(pos) {
        Vertex vertices[] = {
                Vertex(glm::vec3(pos.x, pos.y, 0), glm::vec2(0.0, 1.0), glm::vec4(1,1,0,1)),
                Vertex(glm::vec3(pos.x, pos.y + size.y, 0), glm::vec2(0.0, 0.0), glm::vec4(1,1,0,1)),
                Vertex(glm::vec3(pos.x + size.x, pos.y + size.y, 0), glm::vec2(1.0, 0.0), glm::vec4(1,1,0,1)),

                Vertex(glm::vec3(pos.x, pos.y, 0), glm::vec2(0.0, 1.0), glm::vec4(1,1,0,1)),
                Vertex(glm::vec3(pos.x + size.x, pos.y, 0), glm::vec2(1.0, 1.0), glm::vec4(1,1,0,1)),
                Vertex(glm::vec3(pos.x + size.x, pos.y + size.y, 0), glm::vec2(1.0, 0.0), glm::vec4(1,1,0,1)),
        };

        numVertices = sizeof(vertices)/sizeof(vertices[0]);
        InitializeShape(vertices);
    }

    glm::vec2 Rectangle::GetCenter() {
        //Can't do this without a pivot setup.
    }

    Rectangle::~Rectangle() {

    }
}
