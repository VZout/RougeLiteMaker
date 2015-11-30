//
// Created by bideb on 11/30/2015.
//

#include "camera.h"

namespace rlm {
	Camera::Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar) {
		this->perspective = glm::perspective(fov, aspect, zNear, zFar);
		this->position = pos;
		this->forward = glm::vec3(0, 0, 1);
		this->up = glm::vec3(0, 1, 0);
	}

	Camera::Camera(const glm::vec3& pos, glm::vec4 size, float zNear, float zFar) {
		this->perspective = glm::ortho(size.x, size.y, size.z, size.a, zNear, zFar);
		this->position = pos;
		this->forward = glm::vec3(0, 0, 1);
		this->up = glm::vec3(0, 1, 0);
	}

	Camera::~Camera() {
	}
}