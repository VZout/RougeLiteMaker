#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "glm/glm.hpp"

namespace rlm {

    enum CollisionSides {
            TOP,
            BOTTOM,
            LEFT,
            RIGHT,
    };

    class BoxCollider() {
    private:
        glm::vec2 _pos;
        glm::vec2 _size;
    public:
        Collider(glm::vec2 pos, glm::vec2 size);
        ~Collider();
        glm::vec2 GetPos();
        glm::vec2 GetSize();
        bool Overlaps(BoxCollider other);
        bool Overlaps(glm::vec2 point);
        glm::vec2 GetPos();
        glm::vec2 GetSize();
        CollisionSides HasCollision(BoxCollider other);

    };
}

#endif
