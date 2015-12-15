/*
* util.h
*
*  Created on: 18 Nov 2015
*      @Author: Viktor Zoutman
*/

#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <glm/glm.hpp>
#include <vector>
#include <sstream>
#include "system_popup.h"

namespace rlm {

    inline void print(const char* string) {
        std::cout << "[RLM]: " << string << std::endl;
    }

    inline void print(std::string string) {
        std::cout << "[RLM]: " << string << std::endl;
    }

    inline void printerr(std::string string) {
        SystemPopup popup;
        popup.Create(string.c_str(), SystemPopup::NONFATAL_ERROR);
        std::cerr << "[RLM][ERROR]: " << string << std::endl;
    }

    inline void printerr(const char* string) {
        SystemPopup popup;
        popup.Create(string, SystemPopup::NONFATAL_ERROR);
        std::cerr << "[RLM][ERROR]: " << string << std::endl;
    }

    inline float random_float(int min, int max) {
        float random = ((float) rand()) / (float) max;
        float diff = max - min;
        float r = random * diff;
        return min + r;
    }

    inline std::vector<std::string> SplitString(std::string string, char seperator) {
        std::vector<std::string> arr;

        std::stringstream ssin(string);
        std::string segment;
        std::vector<std::string> seglist;

        while(std::getline(ssin, segment, seperator))
        {
           arr.push_back(segment);
        }

        return arr;
    }

    inline bool StringContains(std::string word, std::string sentence) {
        return sentence.find(word)
           != std::string::npos;
    }

    class IndexedModel
    {
    public:
        std::vector<glm::vec3> positions;
        std::vector<glm::vec2> texCoords;
        std::vector<glm::vec4> colors;
    };

}

#endif
