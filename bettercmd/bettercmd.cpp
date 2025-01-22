#include <iostream>
#include <string>
#include "commandes/help/help.cpp"
#include "commandes/nano/nano.cpp"
#include "commandes/parrot/parrot.cpp"

int main() {
    std::string input;

    while (true) {
        std::cout << R"(
███████████            █████     █████                         █████████  ██████   ██████ ██████████
░░███░░░░░███          ░░███     ░░███                         ███░░░░░███░░██████ ██████ ░░███░░░░███
 ░███    ░███  ██████  ███████   ███████    ██████  ████████  ███     ░░░  ░███░█████░███  ░███   ░░███
 ░██████████  ███░░███░░░███░   ░░░███░    ███░░███░░███░░███░███          ░███░░███ ░███  ░███    ░███
 ░███░░░░░███░███████   ░███      ░███    ░███████  ░███ ░░░ ░███          ░███ ░░░  ░███  ░███    ░███
 ░███    ░███░███░░░    ░███ ███  ░███ ███░███░░░   ░███     ░░███     ███ ░███      ░███  ░███    ███
 ███████████ ░░██████   ░░█████   ░░█████ ░░██████  █████     ░░█████████  █████     █████ ██████████
░░░░░░░░░░░   ░░░░░░     ░░░░░     ░░░░░   ░░░░░░  ░░░░░       ░░░░░░░░░  ░░░░░     ░░░░░ ░░░░░░░░░░

    )" << std::endl;

        std::cout << "BetterCMD > ";
        std::cin >> input;

        int command = -1;
        if (input == "help") command = 1;
        else if (input == "nano") command = 2;
        else if (input == "parrot") command = 3;
        else if (input == "exit") break;

        switch (command) {
            case 1:
                helpCmd();
            break;
            case 2:
                nanoCmd(input);
            break;
            case 3:
                parrotCmd();
            break;
            default:
                std::cout << "Commande inconnue. Essayez à nouveau.\n";
        }
    }
    return EXIT_SUCCESS;
}