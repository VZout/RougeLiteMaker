#ifndef MAP_H_
#define MAP_H_

#include <fstream>
#include <stdio.h>
#include <string>
#include "util.h"
#include <sstream>
#include <iostream>

namespace rlm {
    class MapData {
    protected:
        std::vector<std::vector<int>> map_matrix;
        unsigned int map_width, map_height;
    public:
        Map();
        ~Map();
        void Load(const char* path);
    };

    class TileMap {
    public:
        TileMap();
        ~TileMap();
    }
}

#endif
