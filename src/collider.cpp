#include "collider.h"

namespace rlm {
    Collider(glm::vec2 pos, glm::vec2 size) {
        _pos = pos;
        _size = size;
        _type = NON_SOLID;
    }

    Collider(glm::vec2 pos, glm::vec2 size, Collider type) {
        _pos = pos;
        _size = size;
        _type = type;
    }

    ~Collider() {

    }

    bool Collider::Overlaps(BoxCollider other) {
        if(other._pos.x + other._size.x > _pos.x + _size.x &&
            other._pos.x < _pos.x + _size.x &&
            other._pos.y + other._size.y > _pos.y &&
            other._pos.y < _pos.y + _size.y) {
            return true;
        } else {
            return false;
        }
    }

    bool Collider::Overlaps(glm::vec2 point) {
        if(point.x > _pos.x &&
            point.x < _pos.x + _size.x &&
            point.y > _pos.y &&
            point.y < _pos.y + _size.y) {
            return true;
        } else {
            return false;
        }
    }

    CollisionSides Collider::GetCollision(BoxCollision other) {
        return TOP;
    }

    glm::vec2 GetPos() {
        return _pos;
    }

    glm::vec2 GetSize() {
        return _size;
    }
}
