//
// Created by bideb on 11/30/2015.
//

#ifndef ROUGELITEMAKER_SHADER_H
#define ROUGELITEMAKER_SHADER_H

#include <GL/glew.h>
#include <iostream>
#include <string>
#include <fstream>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glew.h>

#include "transform.h"
#include "camera.h"

namespace rlm {
	class Shader {
	private:
		static const unsigned int NUM_SHADERS = 2;
		static const unsigned int NUM_UNIFORMS = 1;

		GLuint shaders[NUM_SHADERS];
		GLuint uniforms[NUM_UNIFORMS];

		GLuint createShader(const std::string& text, GLenum shaderType);
		std::string loadShader(const std::string& fileName);
		void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);

	public:
		Shader(const std::string& fileName);
		virtual ~Shader();

		GLuint program; // Should be private. Temporary not due to Text2D.h
		void bind();
		void update(const Transform& transform, const Camera& camera);
	};
}


#endif //ROUGELITEMAKER_SHADER_H
