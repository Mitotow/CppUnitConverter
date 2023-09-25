//
// Created by thomas on 9/23/23.
//

#include <string.h>
#include "ConsoleView.h"

void ConsoleView::displayMessage(const std::string &message) {
    std::cout << message << std::endl;
}

std::string ConsoleView::getUserInput() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void ConsoleView::clearConsole() {
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
        //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
    #elif defined (__APPLE__)
        system("clear");
    #endif
}
