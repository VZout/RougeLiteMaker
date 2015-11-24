#include "system_popup.h"

#if defined(__WIN32__) || defined(__WIN64__)
	#include <windows.h>
#endif

namespace rlm {
    SystemPopup::SystemPopup() {

    }

    SystemPopup::~SystemPopup() {

    }

    void SystemPopup::Create(const char* string, SystemPopupType type) {

        #if defined(__WIN32__) || defined(__WIN64__)

			switch(type) {
			case WARNING:
	    		MessageBox(0, "A problem has occured", "Rouge Lite Maker", MB_OK | MB_ICONWARNING);
				break;

			case MESSAGE:
	    		MessageBox(0, "A problem has occured.", "Rouge Lite Maker", MB_OK | MB_ICONINFORMATION);
				break;

			case NONFATAL_ERROR:
	    		MessageBox(0, "A problem has occured.\n\nWould you like to quit?", "Rouge Lite Maker", MB_YESNO | MB_ICONERROR);
				break;

			case FATAL_ERROR:
	    		MessageBox(0, "A problem has occured.\n\nWould you like to quit?", "Rouge Lite Maker", MB_YESNO | MB_ICONERROR);
				break;

			}
        #elif __linux__ || __unix__
            std::string str = string;
            std::string prompt = "/usr/bin/notify-send RLM \"" + str + "\" --icon=dialog-error";
            system(prompt.c_str());
        #endif
    }

}
