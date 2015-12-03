//
// Created by bideb on 11/30/2015.
//

#ifndef ROUGELITEMAKER_CAMERA_H
#define ROUGELITEMAKER_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

namespace rlm {
	class Camera {
	private:
		glm::mat4 perspective;
		glm::vec3 position;
		glm::vec3 forward;
		glm::vec3 up;
	public:
		Camera(const glm::vec3& pos, glm::vec4 size, float zNear, float zFar);
		virtual ~Camera();

		inline glm::mat4 getViewProjection() const {
			return perspective *  glm::lookAt(position, position + forward, up);
		}
	};
}

#endif //ROUGELITEMAKER_CAMERA_H
