//
// Created by thomas on 9/23/23.
//

#include <sstream>
#include <vector>
#include <stdexcept>
#include "Controller.h"
#include "../views/ConsoleView.h"

void Controller::run() {
    Convertor convertor;
    std::string message = "Welcome to the Metrics/Imperials convertor. \n"
                          "Enter the value to be converted followed by its type\n"
                          "Enter quit to leave\n"
                          "Metrics units : km, hm, dam, m, dm, cm, mm, um, nm\n"
                          "Imperials units : mile, yard, feet, inche";
    while(true) {
        ConsoleView::clearConsole();
        ConsoleView::displayMessage(message);
        std::string input = ConsoleView::getUserInput();
        std::string res;
        std::vector<std::string> args;

        if(input == "quit") {
            break;
        }

        std::stringstream ss(input);
        bool valid = true;
        while (getline(ss, res, ' ')) {
            if(args.size() > 3) {
                ConsoleView::displayMessage("Too many arguments");
                valid = false;
                break;
            }
            args.push_back(res);
        }

        if(args.size() < 3) {
            ConsoleView::displayMessage("Invalid convertion, [valueToConvert] [defaultType] [expectedType]");
            continue;
        }

        if(valid) {
            double dvalue = std::atof(args[0].c_str());
            double result;
            try {
                result = convertor.convert(dvalue, args[1], args[2]);
            } catch(std::invalid_argument& e) {
                ConsoleView::displayMessage("Invalid type");
                continue;
            }
            ConsoleView::displayMessage("Result : " + std::to_string(result) + " " + args[2]);
        }

        ConsoleView::displayMessage("Press enter to continue");
        ConsoleView::getUserInput();
    }
}