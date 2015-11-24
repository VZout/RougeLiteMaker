#ifndef SYSTEMPOPUP_H_
#define SYSTEMPOPUP_H_

#include <string>

namespace rlm {
    class SystemPopup {
    public:
        SystemPopup();
        ~SystemPopup();
        void Create(const char* string);
    };
}

#endif
#ifndef SYSTEMPOPUP_H_
#define SYSTEMPOPUP_H_

#include <string>

namespace rlm {


    class SystemPopup {
    public:
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
}

#endif
