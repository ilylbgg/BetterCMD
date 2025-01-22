#include <iostream>
#include <string>
#include "commandes/help/help.cpp"
#include "commandes/nano/nano.cpp"
#include "commandes/parrot/parrot.cpp"
#include <windows.h>

int main() {
    std::string input;

    std::cout << R"(
88""Yb 888888 888888 888888 888888 88""Yb  dP""b8 8b    d8 8888b.
88__dP 88__     88     88   88__   88__dP dP   `" 88b  d88  8I  Yb
88""Yb 88""     88     88   88""   88"Yb  Yb      88YbdP88  8I  dY
88oodP 888888   88     88   888888 88  Yb  YboodP 88 YY 88 8888Y"
)" << std::endl;




    while (true) {
        SetConsoleTitle("BetterCMD | by Axel | made with <3");
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