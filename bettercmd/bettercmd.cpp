#include <iostream>
#include <string>
#include "commandes/help/help.cpp"
#include "commandes/nano/nano.cpp"
#include "commandes/parrot/parrot.cpp"

int main() {
    std::string input;

    while (true) {
        std::cout << "Tapez une commande (hello, world, exit) : ";
        std::cin >> input;

        int command = -1;
        if (input == "help") command = 1;
        else if (input == "nano") command = 2;
        else if (input == "parrot") command = 3;
        else if (input == "exit") break;

        switch (command) {
            case 1:
                helpCmd();
            case 2:
                nanoCmd(input);
            case 3:
                parrotCmd();
            default:
                std::cout << "Commande inconnue. Essayez à nouveau.\n";
        }
    }
    return EXIT_SUCCESS;
}