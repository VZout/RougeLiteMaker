#include "system_popup.h"

#if defined(__WIN32__) || defined(__WIN64__)
	#include <windows.h>
#endif

namespace rlm {
    SystemPopup::SystemPopup() {

    }

    SystemPopup::~SystemPopup() {

	}

	void SystemPopup::Close() {
		_isOpen = false;
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
			_isOpen = true;

			//Split string into lines.
            std::string message = string;
			std::vector<std::string> lines;
			std::stringstream ss(message);
			std::string line;

			while(std::getline(ss, line, '\n')) {
			    std::cout << line << '\n';
				lines.push_back(line);
			}

			Display *display;
			Window window;
			XEvent event;
			XFontStruct* font;
			int s;
			std::vector<Button> buttons;

			/* open connection with the server */
			display = XOpenDisplay(NULL);
			if (display == NULL) {
				fprintf(stderr, "Cannot open display\n");
				exit(1);
			}

			s = DefaultScreen(display);

			/*Setup font shizzle*/
		    font = XLoadQueryFont (display, "fixed");
		    XSetFont (display, DefaultGC(display, s), font->fid);

			/*Get wanted display size.*/
			float line_length = 0;
			for(unsigned int i = 0; i < lines.size(); i++) {
				if(XTextWidth(font, lines[i].c_str(), strlen(lines[i].c_str())) > line_length) {
					//line_length = strlen(line[i]);
					line_length = XTextWidth(font, lines[i].c_str(), strlen(lines[i].c_str()));
				}
			}
			float margin = 10;
			float line_height = 13;
			float button_width = 80;
			float button_height = 30;
			float width = line_length + (margin * 2);
			float height = margin + (lines.size() * line_height) + (button_height + margin);

			/* create window */
			window = XCreateSimpleWindow(display, RootWindow(display, s), 10, 10, width, height, 1,
								   BlackPixel(display, s), WhitePixel(display, s));

			/* select kind of events we are  interested in */
			XSelectInput(display, window, ExposureMask | KeyPressMask | ButtonPressMask|ButtonReleaseMask);

			Atom WM_DELETE_WINDOW = XInternAtom(display, "WM_DELETE_WINDOW", False);
   			XSetWMProtocols(display, window, &WM_DELETE_WINDOW, 1);

			/* map (show) the window */
			XMapWindow(display, window);

			/* event loop */
			while (_isOpen) {
				XNextEvent(display, &event);

				/* draw or redraw the window */
				if (event.type == Expose) {
					for(unsigned int i = 0; i < lines.size(); i++) {
						XDrawString(display, window, DefaultGC(display, s),
									margin, margin * 1.5f + (line_height * i),
									lines[i].c_str(), strlen(lines[i].c_str()));
					}
				}
				buttons.push_back(Button("Ok", display, window, DefaultGC(display, s),
										font, margin, margin +
										(lines.size() * line_height), button_width,
										button_height, &SystemPopup::Close));
				buttons.push_back(Button("Quit", display, window, DefaultGC(display, s),
										font, width - button_width - margin, margin +
										(lines.size() * line_height), button_width,
										button_height, &SystemPopup::Close));

				/* exit on key press */
				if (event.type == KeyPress)
					break;

				else if(event.type == ButtonPress) {
					switch(event.xbutton.button){
				    case Button1:
						for(unsigned int i = 0; i < buttons.size(); i++) {
							if(event.xbutton.x > buttons[i].x &&
									event.xbutton.x < buttons[i].x + buttons[i].width &&
									event.xbutton.y > buttons[i].y &&
									event.xbutton.y < buttons[i].y + buttons[i].height) {
								(this->*buttons[i].action)();
								break;
							}
						}
				        break;
				    default:
				        break;
				    }
				}

				else if (event.type == ClientMessage)
					break;
			}

			/* close connection to server */
			XCloseDisplay(display);
        #endif
    }

	Button::Button(const char* string, Display* display,
					Window window, GC gc, XFontStruct* font, float x, float y,
					float width, float height, void (SystemPopup::*action)()) {

		XColor color;
		Colormap colormap;
		char grey[] = "#A6A6A6";
		char black[] = "#000000";

		colormap = DefaultColormap(display, 0);
		XParseColor(display, colormap, grey, &color);
		XAllocColor(display, colormap, &color);

		XSetForeground(display, gc, color.pixel);
		XFillRectangle(display, window, gc, x, y, width, height);

		colormap = DefaultColormap(display, 0);
		XParseColor(display, colormap, black, &color);
		XAllocColor(display, colormap, &color);

		XSetForeground(display, gc, color.pixel);
		float length = XTextWidth(font, string, strlen(string));
		XDrawString(display, window, gc, x + width / 2 - length / 2, y + 18, string, strlen(string));
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->action = action;
	}

	Button::~Button() {

	}

}
