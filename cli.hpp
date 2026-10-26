#ifndef __CLI_HPP
#define __CLI_HPP

#include <iostream>

class Cli {
private:
    int numberOfChars;
    int numberOfOptions;
    int numberOfStrings;

public:
    int stringCounter;
    
    Cli();

    //getters e setters
    int getNumberChar();
    void setNumberChar(int input);
    int getNumberOption();
    void setNumberOption(int input);
    int getNumberString();
    void setNumberString(int input);

    // facilitador de print no terminal
    void PrintLine(std::string line);

    // menu de opções no CLI
    void PrintMenu();

    // processamento do menu de informações
    void OptionsBackend(int option);
};

#endif