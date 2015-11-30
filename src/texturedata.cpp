/*
 * TextureData.cpp
 *
 *  Created on: May 19, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "texturedata.h"
#include <GLFW/glfw3.h>

namespace rlm {

TextureData::TextureData() {
	//TODO Might want to uncomment this.
	//texture  = NULL;
	//width = NULL;
	//height = NULL;
	//textureData = NULL;
	//row_pointers = NULL;
	//file = NULL;
	//png_ptr = NULL;
	//info_ptr = NULL;
	//end_info = NULL;
	//format = NULL;
}

TextureData::~TextureData() {

}

void TextureData::setTexture(GLuint texture) {
	this->texture = texture;
}

void TextureData::setWidth(int width) {
	this->width = width;
}

void TextureData::setHeight(int height) {
	this->height = height;
}

void TextureData::setTextureData(png_byte* textureData) {
	this->textureData = textureData;
}

void TextureData::setRowPointers(png_byte** row_pointers) {
	this->row_pointers = row_pointers;
}


void TextureData::setFile(FILE* file) {
	this->file = file;
}


void TextureData::setPNGPtr(png_structp png_ptr) {
	this->png_ptr = png_ptr;
}


void TextureData::setInfoPtr(png_infop info_ptr) {
	this->info_ptr = info_ptr;
}


void TextureData::setEndInfo(png_infop end_info) {
	this->end_info = end_info;
}

void TextureData::setFormat(GLint format) {
	this->format = format;
}

GLuint TextureData::getTexture() {
	return texture;
}

int TextureData::getWidth() {
	return width;
}

int TextureData::getHeight() {
	return height;
}

png_byte* TextureData::getTextureData() {
	return textureData;
}

png_byte** TextureData::getRowPointers() {
	return row_pointers;
}

FILE* TextureData::getFile() {
	return file;
}

png_structp TextureData::getPNGPtr() {
	return png_ptr;
}

png_infop TextureData::getInfoPtr() {
	return info_ptr;
}

png_infop TextureData::getEndInfo() {
	return end_info;
}

GLint TextureData::getFormat() {
	return format;
}

}
