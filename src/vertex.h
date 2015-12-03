#ifndef VERTEX_H_
#define VERTEX_H_

#include "glm/glm.hpp"

namespace rlm {
    struct Vertex {
    public:
        Vertex(const glm::vec3& pos, const glm::vec2& texCoords,const glm::vec4& color) {
			this->pos = pos;
			this->texCoords = texCoords;
            this->color= color;
		}

		glm::vec3* GetPos() { return &pos; }
		glm::vec2* GetTexCoord() { return &texCoords; }
        glm::vec4* GetColor() { return &color; }

	private:
		glm::vec3 pos;
		glm::vec2 texCoords;
        glm::vec4 color;
	};

	enum BufferPositions {
		POSITION_VB,
		TEXCOORD_VB,
        COLOR_VB,
	};
}

#endif
