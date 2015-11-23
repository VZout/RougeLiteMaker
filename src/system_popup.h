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
