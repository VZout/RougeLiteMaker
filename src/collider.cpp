#include "collider.h"

namespace rlm {
    BoxCollider::BoxCollider(glm::vec2 pos, glm::vec2 size) {
        _pos = pos;
        _size = size;
        _type = NON_SOLID;
    }

    BoxCollider::BoxCollider(glm::vec2 pos, glm::vec2 size, ColliderType type) {
        _pos = pos;
        _size = size;
        _type = type;
    }

    BoxCollider::~BoxCollider() {

    }

    bool BoxCollider::Overlaps(BoxCollider other) {
        if(other._pos.x + other._size.x > _pos.x + _size.x &&
            other._pos.x < _pos.x + _size.x &&
            other._pos.y + other._size.y > _pos.y &&
            other._pos.y < _pos.y + _size.y) {
            return true;
        } else {
            return false;
        }
    }

    bool BoxCollider::Overlaps(glm::vec2 point) {
        if(point.x > _pos.x &&
            point.x < _pos.x + _size.x &&
            point.y > _pos.y &&
            point.y < _pos.y + _size.y) {
            return true;
        } else {
            return false;
        }
    }

    ColliderSide BoxCollider::GetCollision(BoxCollider other) {
        return TOP;
    }

    glm::vec2 BoxCollider::GetPos() {
        return _pos;
    }

    glm::vec2 BoxCollider::GetSize() {
        return _size;
    }
}
