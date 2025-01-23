#include "ls.h"
#include <iostream>
#include <filesystem>

void lsCmd() {
    for (const auto& entry : std::filesystem::directory_iterator(".")) {
        std::cout << entry.path().filename().string() << std::endl;
    }
}