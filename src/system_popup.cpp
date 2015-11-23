#include "system_popup.h"

namespace rlm {
    SystemPopup::SystemPopup() {

    }

    SystemPopup::~SystemPopup() {

    }

    void SystemPopup::Create(const char* string) {

        #if defined(__WIN32__) || defined(__WIN64__)
            //TODO windows based popup.
        #elif __linux__ || __unix__
            std::string str = string;
            std::string prompt = "/usr/bin/notify-send RLM \"" + str + "\" --icon=dialog-error";
            system(prompt.c_str());
        #endif
    }

}
