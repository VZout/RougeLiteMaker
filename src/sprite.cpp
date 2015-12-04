#include "sprite.h"

namespace rlm {
    Sprite::Sprite() {
        rectangle = new Rectangle();
        texture = NULL;
    }

    Sprite::Sprite(glm::vec2 pos, glm::vec2 size, Texture texture) {
        rectangle = new Rectangle();
        texture = texture;
    }

    ~Sprite::Sprite() {
        delete rectangle;
        delete texture;
    }

    void Sprite::Draw() {
        Rectangle->Draw();
        texture->bind();
    }
}
