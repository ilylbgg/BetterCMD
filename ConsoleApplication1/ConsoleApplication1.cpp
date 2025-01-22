#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>
#include <codecvt>
#include <sstream>

int tool;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#endif
}

int main()
{
    std::string input;

    std::cout << "  ____       _   _             ____ __  __ ____  \n";
    std::cout << " | __ )  ___| |_| |_ ___ _ __ / ___|  \\/  |  _ \\ \n";
    std::cout << " |  _ \\ / _ \\ __| __/ _ \\ '__| |   | |\\/| | | | |\n";
    std::cout << " | |_) |  __/ |_| ||  __/ |  | |___| |  | | |_| |\n";
    std::cout << " |____/ \\___|\\__|\\__\\___|_|   \\____|_|  |_|____/ \n";
    std::cout << "                                                \n";
    std::cout << "Type help for help \n";
    std::cout << "                                                \n";
	
    while (true) {
        std::cout << "[>] ";
        std::getline(std::cin, input);

        if (input == "help") {
            std::cout << "Voici les commandes disponibles :" << std::endl;
            std::cout << "  exit    > Permet de quitter le programme" << std::endl;
            std::cout << "  clear   > Nettoie ton écran" << std::endl;
        }
        else if (input == "exit") {
            std::cout << "Au revoir!" << std::endl;
            break;
        }
        else if (input == "edit") {
            system("notpad");
        }
        else if (input == "clear") {
            clearScreen();
        }
        else if (input == "parrot")
            system("curl parrot.live");
    }
    return EXIT_SUCCESS;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage