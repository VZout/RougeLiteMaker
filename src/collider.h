#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "glm/glm.hpp"

namespace rlm {

    enum ColliderSide {
            TOP,
            BOTTOM,
            LEFT,
            RIGHT,
            NONE,
    };

    enum ColliderType {
        SOLID,
        NON_SOLID,
    };

    class BoxCollider {
    private:
        glm::vec2 _pos;
        glm::vec2 _size;
        ColliderType _type;
    public:
        BoxCollider(glm::vec2 pos, glm::vec2 size);
        BoxCollider(glm::vec2 pos, glm::vec2 size, ColliderType type);
        ~BoxCollider();

        bool Overlaps(BoxCollider other);
        bool Overlaps(glm::vec2 point);
        glm::vec2 GetPos();
        glm::vec2 GetSize();
        ColliderSide GetCollision(BoxCollider other);

    };
}

#endif
