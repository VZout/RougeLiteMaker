#include "map.h"

namespace rlm {
    MapData::Map() {

    }

    MapData::~Map() {

    }

    void MapData::Load(const char* path) {
        print("Loading rlm map.");
        std::ifstream file(path);
        std::string str;

        if(!file) {
            printerr("Unable to open map file.");
        }

        while (std::getline(file, str)) {
            if(StringContains("MapWidth", str)) {
                map_width = atoi(SplitString(str, ',')[1].c_str());
                std::cout << "Map Width: " << map_width << std::endl;
            } else if(StringContains("MapHeight", str)) {
                map_height = atoi(SplitString(str, ',')[1].c_str());
                std::cout << "Map Height: " << map_height << std::endl;
            } else {
                print("Unparsed Data: " + str);
                print(SplitString(str, ',')[0]);

                unsigned int i = 0;

                std::vector<std::vector<int>> temp(map_width, std::vector<int>(map_height));
                map_matrix = temp;

                if(i < SplitString(str, ',').size()) {
                    for (unsigned int w = 0; w < map_width; w++) {
                        for (unsigned int h = 0; h < map_height; h++) {
                            map_matrix[w][h] = atoi(SplitString(str, ',')[i].c_str());
                            i++;
                        }
                    }
                }

                for(unsigned int i = 0; i < map_width; i++) {
                    for(unsigned int j = 0; j < map_height; j++) {
                        std::cout << "map:" << map_matrix[i][j] << std::endl;
                    }
                }
            }
        }
    }
}
