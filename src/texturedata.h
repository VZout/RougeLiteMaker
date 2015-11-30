/*
 * TextureData.h
 *
 *  Created on: May 19, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef TEXTUREDATA_H_
#define TEXTUREDATA_H_

#include <GL/glew.h>
#include <libpng/png.h>
#include <libpng/pngconf.h>
#include <cstdio>

namespace rlm {
class TextureData {
private:
	GLuint texture;
	int width;
	int height;
	png_byte* textureData;
	png_byte** row_pointers;
	FILE* file;
	png_structp png_ptr;
	png_infop info_ptr;
	png_infop end_info;
	GLint format;
public:
	TextureData();
	virtual ~TextureData();

	void setTexture(GLuint texture);
	void setWidth(int width);
	void setHeight(int height);
	void setTextureData(png_byte* textureData);
	void setRowPointers(png_byte** row_pointers);
	void setFile(FILE* file);
	void setPNGPtr(png_structp png_ptr);
	void setInfoPtr(png_infop info_ptr);
	void setEndInfo(png_infop end_info);
	void setFormat(GLint format);

	GLuint getTexture();
	int getWidth();
	int getHeight();
	png_byte* getTextureData();
	png_byte** getRowPointers();
	FILE* getFile();
	png_structp getPNGPtr();
	png_infop getInfoPtr();
	png_infop getEndInfo();
	GLint getFormat();
};
}

#endif /* TEXTUREDATA_H_ */
