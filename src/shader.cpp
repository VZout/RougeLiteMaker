//
// Created by bideb on 11/30/2015.
//

#include "shader.h"

namespace rlm {
	Shader::Shader(const std::string& fileName) {
		program = glCreateProgram();
		shaders[0] = createShader(loadShader(fileName + ".vs"), GL_VERTEX_SHADER);
		shaders[1] = createShader(loadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

		for(unsigned int i = 0; i < NUM_SHADERS; i++)
			glAttachShader(program, shaders[i]);

		glBindAttribLocation(program, 0, "position");
		glBindAttribLocation(program, 1, "texCoord");
		//glBindAttribLocation(program, 2, "normal");

		glLinkProgram(program);
		checkShaderError(program, GL_LINK_STATUS, true, "Program linking failed: ");

		glValidateProgram(program);
		checkShaderError(program, GL_VALIDATE_STATUS, true, "Program is invalid: ");

		uniforms[0] = glGetUniformLocation(program, "MVP");
		//uniforms[1] = glGetUniformLocation(program, "Normal");
		//uniforms[2] = glGetUniformLocation(program, "lightDirection");
	}

	Shader::~Shader() {
		for(unsigned int i = 0; i < NUM_SHADERS; i++) {
			glDetachShader(program, shaders[i]);
			glDeleteShader(shaders[i]);
		}

		glDeleteProgram(program);
	}

	void Shader::bind() {
		glUseProgram(program);
	}

	void Shader::update(const Transform& transform, const Camera& camera) {
		glm::mat4 MVP = camera.getViewProjection() * transform.getModel();
		glm::mat4 Normal = transform.getModel();

		glUniformMatrix4fv(uniforms[0], 1, GL_FALSE, &MVP[0][0]);
		//glUniformMatrix4fv(uniforms[1], 1, GL_FALSE, &Normal[0][0]);
		//glUniform3f(uniforms[2], 0.0f, 0.0f, 1.0f);
	}

	GLuint Shader::createShader(const std::string& text, GLenum shaderType) {
		GLuint shader = glCreateShader(shaderType);

		if(shader == 0)
			std::cerr << "Shader creation failed: " << std::endl;

		const GLchar* shaderSourceStrings[1];
		GLint shaderSourceStringLengths[1];

		shaderSourceStrings[0] = text.c_str();
		shaderSourceStringLengths[0] = text.length();

		glShaderSource(shader, 1 ,shaderSourceStrings, shaderSourceStringLengths);
		glCompileShader(shader);

		checkShaderError(shader, GL_COMPILE_STATUS, false, "Shader compilation failed: ");

		return shader;
	}

	std::string Shader::loadShader(const std::string& fileName) {
		std::ifstream file;
		file.open(fileName);

		std::string output;
		std::string line;

		if(file.is_open()) {
			while(file.good()) {
				getline(file, line);
				output.append(line + "\n");
			}
		} else
			std::cerr << "Unable open shader file: " << fileName << "'" << std::endl;

		return output;
	}

	void Shader::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage) {
		GLint success = 0;
		GLchar error[1024] = { 0 };

		if(isProgram)
			glGetProgramiv(shader, flag, &success);
		else
			glGetShaderiv(shader, flag, &success);

		if(success == GL_FALSE) {
			if(isProgram)
				glGetProgramInfoLog(shader, sizeof(error), NULL, error);
			else
				glGetShaderInfoLog(shader, sizeof(error), NULL, error);

			std::cerr << errorMessage << "'" << error << "'" << std::endl;
		}
	}
}
