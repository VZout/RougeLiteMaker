#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include <glm/glm.hpp>

#include "shader.h"
#include "texture.h"
#include "transform.h"

namespace rlm {
    class Drawable {
    protected:
        Shader* shader;
        Transform transform;
    public:
        Drawable() {

        }
        ~Drawable() {
            delete shader;
        }
    };
}

#endif
