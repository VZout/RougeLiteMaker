/*
 * PNGLoader.h
 *
 *  Created on: May 19, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef PNGLOADER_H_
#define PNGLOADER_H_

#include <string>
#include "texturedata.h"

namespace rlm {
class PNGLoader {
public:
	static TextureData loadPNG(const char* fileName);
};
}

#endif
