#include <iostream>
#include <sstream>
#include "modules/help/help.cpp"
#include "modules/clear/clear.cpp"

void processCommand(const std::string& command) {
    if (command.empty()) {
        std::cout << "Commande vide. Rien à faire." << std::endl;
        return;
    }

    std::istringstream iss(command);
    std::string cmd, arg;
    iss >> cmd;
    std::getline(iss, arg);

    if (cmd == "help") {
        showHelp();
    } else if (cmd == "clear") {
        clearScreen();
    }

    else if (cmd == "exit") {
        std::cout << "Au revoir!" << std::endl;
        exit(0);
    } else {
        std::cout << "Commande inconnue : " << cmd << std::endl;
    }
}

int main() {
    std::string input;

    std::cout << "Bienvenue dans ton shell personnalisé !" << std::endl;

    while (true) {
        std::cout << "[>] ";
        std::getline(std::cin, input);
        processCommand(input);
    }
    return 0;
}
