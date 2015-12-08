/*
 * Texture.cpp
 *
 *  Created on: Apr 22, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "texture.h"

#include <libpng12/png.h>
#include <stdlib.h>
#include <cassert>

#include "pngloader.h"

// TODO: Move png loader to a seperate class.

namespace rlm {
Texture::Texture(const char* fileName, const char* unique_name) {
	InitTexture(fileName, unique_name, NEAREST);
}

Texture::Texture(const char* fileName, const char* unique_name, Filter filter) {
	InitTexture(fileName, unique_name, filter);
}

Texture::~Texture() {
	glDeleteTextures(1, &texture);
}

void Texture::InitTexture(const char* fileName, const char* unique_name, Filter filter) {
	this->unique_name = unique_name;

	TextureData tdata = PNGLoader::loadPNG(fileName);

    // read the png into image_data through row_pointers
    png_read_image(tdata.getPNGPtr(), tdata.getRowPointers());

    // Generate the OpenGL texture object
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

	switch(filter) {
		case NEAREST:
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		break;
		case LINEAR:
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		break;
		case BILLIONAIR:
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		break;
		default:
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		break;
	}

    glTexImage2D(GL_TEXTURE_2D, 0, tdata.getFormat(), tdata.getWidth(), tdata.getHeight(),
				0, tdata.getFormat(), GL_UNSIGNED_BYTE, tdata.getTextureData());

    // clean up
    png_read_destroy(tdata.getPNGPtr(), tdata.getInfoPtr(), tdata.getEndInfo());
    free(tdata.getTextureData());
    free(tdata.getRowPointers());
    fclose(tdata.getFile());
}

void Texture::bind(unsigned int unit) {
	assert(unit >= 0 && unit <= 31);

	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, texture);
}
}
