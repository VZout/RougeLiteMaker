#include "input.h"

namespace rlm {

    glm::vec2 Input::_mouse_pos;
    std::vector<int> Input::_held_keys;
    std::vector<int> Input::_down_keys;
    std::vector<int> Input::_up_keys;

    bool Input::GetKeyDown(int key) {
	       return std::find(_down_keys.begin(), _down_keys.end(), key) != _down_keys.end();
    }

    bool Input::GetKeyHeld(int key) {
	       return std::find(_held_keys.begin(), _held_keys.end(), key) != _held_keys.end();
    }

    bool Input::GetKeyUp(int key) {
	       return std::find(_up_keys.begin(), _up_keys.end(), key) != _up_keys.end();
    }

    void Input::AddDownKey(int key) {
        _held_keys.push_back(key);
    	_down_keys.push_back(key);
    }

    void Input::RemoveHeldKey(int key) {
        _held_keys.erase(std::remove(_held_keys.begin(), _held_keys.end(), key), _held_keys.end());
    }

    void Input::ClearInput() {
        _down_keys.clear();
    	_up_keys.clear();
    }

}
