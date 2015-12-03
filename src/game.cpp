/*
* game.cpp
*
*  Created on: 18 Nov 2015
*      @Author: Viktor Zoutman
*/

#include "game.h"

namespace rlm {

	Display Game::display;
	Camera Game::camera(glm::vec3(0, 0, 0), glm::vec4(0.f, -1280.f, 720.f, 0.f), -1, 1);;
	GLFWwindow* window;

	Game::Game() {
		_has_init = false;
		_has_update = false;
		_has_render = false;
	}

	Game::~Game() {
	}

	void Game::InitGame() {
		if(_has_init) {
			init();
		} else {
			print("No init function");
		}
	}

	void Game::GameLoop() {
		if(_has_render)
			render();
		else
			print("No render function");

		if(_has_update)
			update();
		else
			print("No update function");
	}

	void Game::Start() {
		display.Create(this);
	}

	void Game::SetInitFunction(void (*init)()) {
		this->init = init;
		_has_init = true;
	}

	void Game::SetRenderFunction(void (*render)()) {
		this->render = render;
		_has_render = true;
	}

	void Game::SetUpdateFunction(void (*update)()) {
		this->update = update;
		_has_update = true;
	}

}
