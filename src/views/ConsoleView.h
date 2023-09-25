//
// Created by thomas on 9/23/23.
//

#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include <iostream>

class ConsoleView {
public:
    static void displayMessage(const std::string& message);
    static std::string getUserInput();
    static void clearConsole();
};


#endif
