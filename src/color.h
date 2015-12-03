#ifndef COLOR_H_
#define COLOR_H_

#include <glm/glm.hpp>

namespace rlm {
    class Color {
    public:
        static const glm::vec4 WHITE;
        static const glm::vec4 BLACK;
        static const glm::vec4 TRANSPARANT;
        static const glm::vec4 GREY;
        static const glm::vec4 LIGHT_GREY;
        static const glm::vec4 DARK_GREY;
        static const glm::vec4 RED;
        static const glm::vec4 GREEN;
        static const glm::vec4 BLUE;
        static const glm::vec4 YELLOW;
        static const glm::vec4 ORANGE;
    };

    const glm::vec4 Color::WHITE = glm::vec4(1.0, 1.0, 1.0, 1.0);
    const glm::vec4 Color::BLACK = glm::vec4(0.0, 0.0, 0.0, 1.0);
    const glm::vec4 Color::TRANSPARANT = glm::vec4(0.0, 0.0, 0.0, 0.0);
    const glm::vec4 Color::GREY = glm::vec4(0.5, 0.5, 0.5, 1);
    const glm::vec4 Color::LIGHT_GREY = glm::vec4(0.8, 0.8, 0.8, 1);
    const glm::vec4 Color::DARK_GREY = glm::vec4(0.16, 0.16, 0.16, 1);
    const glm::vec4 Color::RED = glm::vec4(1.0, 0.0, 0.0, 1);
    const glm::vec4 Color::GREEN = glm::vec4(0.0, 1.0, 0.0, 1);
    const glm::vec4 Color::BLUE = glm::vec4(0.0, 0.0, 1.0, 1.0);
    const glm::vec4 Color::YELLOW = glm::vec4(1.0, 1.0, 0.0, 1);
    const glm::vec4 Color::ORANGE = glm::vec4(1.0, 0.5, 0.0, 1);
}

#endif
