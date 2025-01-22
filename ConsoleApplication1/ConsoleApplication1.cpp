// Le code sélectionné est un programme C++ qui permet de créer des fichiers ou des répertoires, 
// et d'exécuter certaines commandes via une interface en ligne de commande. 
// Voici une explication détaillée des différentes parties du code :

#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>
#include <codecvt>
#include <sstream>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

// Fonction pour effacer l'écran de la console
void clearScreen() {
#ifdef _WIN32
    system("cls");
#endif
}

// Fonction principale du programme
int main()
{
    // Configurer la sortie standard pour utiliser l'encodage UTF-8
	SetConsoleOutputCP(CP_UTF8);

    std::string input;

    // Afficher un message de bienvenue
    std::wcout << L"  ____       _   _             ____ __  __ ____  \n";
    std::wcout << L" | __ )  ___| |_| |_ ___ _ __ / ___|  \\/  |  _ \\ \n";
    std::wcout << L" |  _ \\ / _ \\ __| __/ _ \\ '__| |   | |\\/| | | | |\n";
    std::wcout << L" | |_) |  __/ |_| ||  __/ |  | |___| |  | | |_| |\n";
    std::wcout << L" |____/ \\___|\\__|\\__\\___|_|   \\____|_|  |_|____/ \n";
    std::wcout << L"                                                \n";
    std::wcout << L"Type help for help \n";
    std::wcout << L"                                                \n";
    
    // Boucle principale pour lire les commandes de l'utilisateur
    while (true) {
        std::wcout << L"[>] ";
        std::getline(std::cin, input);

        if (input == "help") {
            std::wcout << L"Voici les commandes disponibles :" << std::endl;
            std::wcout << L"  exit    > Permet de quitter le programme" << std::endl;
            std::wcout << L"  clear   > Nettoie ton écran" << std::endl;
            std::wcout << L"  edit    > Ouvre le bloc-notes" << std::endl;
            std::wcout << L"  parrot  > Affiche un perroquet" << std::endl;
			std::wcout << L"  mkdir   > Crée un répertoire" << std::endl;
        }
        else if (input == "exit") {
            std::wcout << L"Au revoir!" << std::endl;
            break;
        }
        else if (input == "edit") {
            system("notpad");
        }
        else if (input == "clear") {
            clearScreen();
        }
        else if (input == "parrot") {
            system("curl parrot.live");
     }

        else if (input.rfind("mkdir ", 0) == 0) {
            std::string dir = input.substr(6);
            if (dir.empty()) {
                std::wcerr << L"Erreur: Aucun nom de répertoire spécifié." << std::endl;
            } else {
                std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
                std::wstring wdir = converter.from_bytes(dir);
                if (CreateDirectory(wdir.c_str(), NULL)) {
                    std::wcout << L"Répertoire créé à : " << wdir << std::endl;
                } else {
                    std::wcerr << L"Erreur lors de la création du répertoire." << std::endl;
                }
            }
        }

    }
    return EXIT_SUCCESS;
}