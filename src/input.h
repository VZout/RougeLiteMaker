#ifndef INPUT_H_
#define INPUT_H_

#include <vector>
#include <glm/glm.hpp>

namespace rlm {
    class Input {
    protected:
        static std::vector<int> _held_keys;
        static std::vector<int> _down_keys;
        static std::vector<int> _up_keys;
        static glm::vec2 _mouse_pos

    public:
        static bool GetKeyDown(int key);
        static bool GetKeyHeld(int key);
        static bool GetKeyUp(int key);

        static void AddDownKey(int key);
        static void RemoveHeldKey(int key);
        static void ClearInput();

        static glm::vec2 GetMousePos();
    };
}

#endif
