#include <iostream>
#include "nano.h"

void nanoCmd(const std::string& filepath) {
    system(("notepad " + filepath).c_str());
    if (filepath.empty()) {
        system("notepad");
    }
}

