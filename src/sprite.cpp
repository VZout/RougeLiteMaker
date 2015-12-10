#include "sprite.h"

namespace rlm {
    Sprite::Sprite() {
        rectangle = new Rectangle();
        texture = NULL;
    }

    Sprite::Sprite(glm::vec2 pos, glm::vec2 size, Texture* texture) {
        shader = new Shader("res/basicTextureShader");
        transform.setPos(glm::vec3(pos.x, pos.y, 0));
        rectangle = new Rectangle(pos, size);
        this->texture = texture;
    }

    Sprite::~Sprite() {
        delete rectangle;
        delete texture;
    }

    void Sprite::Draw() {
        shader->bind();
        shader->update(transform, Game::camera);
        texture->bind(0);
        rectangle->Draw();
    }

    void Sprite::SetPos(glm::vec2 pos) {
        transform.setPos(glm::vec3(pos.x, pos.y, 0));
    }
    void Sprite::SetSize(glm::vec2 size) {

    }
}
