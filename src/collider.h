#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "glm/glm.hpp"

namespace rlm {
    class BoxCollider() {
    public:
        Collider(glm::vec2 pos, glm::vec2 size);
        ~Collider();
        glm::vec2 GetPos();
        glm::vec2 GetSize();
    };
}

#endif
