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
#include "system_popup.h"

namespace rlm {;

    inline void print(const char* string) {
        std::cout << "[RLM]: " << string << std::endl;
    }

    inline void printerr(const char* string) {
        SystemPopup popup;
        popup.Create(string);
        std::cerr << "[RLM][ERROR]: " << string << std::endl;
    }

    inline float random_float(int min, int max) {
        float random = ((float) rand()) / (float) RAND_MAX;
        float diff = max - min;
        float r = random * diff;
        return min + r;
    }

}

#endif
