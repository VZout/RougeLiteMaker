/*
 * Texture.h
 *
 *  Created on: Apr 22, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL/glew.h>

namespace rlm {

	enum Filter {
		NEAREST,
		BILLIONAIR,
		LINEAR,
	};

	class Texture {
	private:
		GLuint texture;
	public:

		Texture(const char* fileName, const char* unique_name, Filter filter);
		Texture(const char* fileName, const char* unique_name);
		void InitTexture(const char* fileName, const char* unique_name, Filter filter);
		const char* unique_name;
		virtual ~Texture();

		void bind(unsigned int unit);
	};
}

#endif /* TEXTURE_H_ */
