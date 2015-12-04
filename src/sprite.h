#ifndef SPRITE_H_
#define SPRITE_H_

#include <glm/glm.hpp>

#include "shape.h"
#include "rectangle.h"
#include "texture.h"

namespace rlm {
    class Sprite : Drawable {
    protected:
        Rectangle* rectangle;
        Texture* texture;
    public:
        Sprite();
        Sprite(glm::vec2 pos, glm::vec2 size, Texture texture);
        ~Sprite();
        void Draw();
    };
}

#endif
