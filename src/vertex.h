#ifndef VERTEX_H_
#define VERTEX_H_

#include "glm/glm.hpp"

namespace rlm {
    struct Vertex {
    public:
        Vertex(const glm::vec3& pos, const glm::vec2& texCoords) {
			this->pos = pos;
			this->texCoords = texCoords;
		}

		glm::vec3* GetPos() { return &pos; }
		glm::vec2* GetTexCoord() { return &texCoords; }

	private:
		glm::vec3 pos;
		glm::vec2 texCoords;
	};

	enum BufferPositions {
		POSITION_VB,
		TEXCOORD_VB,
	};
}

#endif
