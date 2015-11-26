#ifndef SYSTEMPOPUP_H_
#define SYSTEMPOPUP_H_

#include <string>

#if defined(__linux__) || defined(__unix__)
	#include <X11/Xlib.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <vector>
	#include <iostream>
	#include <sstream>
#endif

namespace rlm {

    class SystemPopup {
    private:
        bool _isOpen;
    public:
        void Close();
		enum SystemPopupType {
			MESSAGE,
			WARNING,
			NONFATAL_ERROR,
			FATAL_ERROR,
		};
        SystemPopup();
        ~SystemPopup();
        void Create(const char* string, SystemPopupType type);
    };

	#if defined(__linux__) || defined(__unix__)
		class Button {
		private:
		public:
			void (SystemPopup::*action)();
			Button(const char* string, Display* display, Window window, GC gc, XFontStruct* font,
				    float x, float y, float width, float height, void (SystemPopup::*action)());
			~Button();
			float x, y, width, height;
		};
	#endif
}

#endif
