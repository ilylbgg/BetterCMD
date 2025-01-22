#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sys/sysinfo.h>

void printHeader() {
    std::cout << std::setw(10) << "PID"
              << std::setw(20) << "USER"
              << std::setw(10) << "CPU%"
              << std::setw(10) << "MEM%"
              << std::setw(10) << "TIME+"
              << std::setw(20) << "COMMAND" << std::endl;
}

void printProcessInfo() {
    // This is a placeholder for actual process information retrieval
    // In a real implementation, you would retrieve and display process information here
    std::cout << std::setw(10) << "1234"
              << std::setw(20) << "user"
              << std::setw(10) << "0.1"
              << std::setw(10) << "0.2"
              << std::setw(10) << "00:01:23"
              << std::setw(20) << "example_command" << std::endl;
}

void htop() {
    while (true) {
        std::system("clear");
        printHeader();
        printProcessInfo();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    htop();
    return 0;
}
