#ifndef GAME_H_
#define GAME_H_

#include "display.h"

#include <iostream>
#include <GLFW/glfw3.h>
#include <camera.h>
#include <resource_manager.h>

#include "util.h"

namespace rlm {

class Display;

    class Game {
    private:
        bool _has_init;
        bool _has_render;
        bool _has_update;

        void (*init)();
        void (*render)();
        void (*update)();

    public:
        Game();
        ~Game();

        void Start(float width, float height, const char* title);
        void GameLoop();
        void InitGame();

        void SetInitFunction(void (*init)());
        void SetRenderFunction(void (*render)());
        void SetUpdateFunction(void (*update)());

        void CleanUp();
        void Quit();

        static Display display;
        static Camera camera;
        static ResourceManager resource_manager;
    };
}

#endif
