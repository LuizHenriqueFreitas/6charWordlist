// necessário documentar todo esse arquivo corretamente

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

    // facilita a entrada de dados do tipo "int
    int GetIntInput();

    // menu de opções no CLI
    void PrintMainMenu();

    // recebe os valores do usuario - gerencia os inputs
    void SetWordlistConfig();       // recebe os valores de entrada do usuário e envia para ser usado nas funções
                                    // de calculo de tamanho e geração da wordlist

    // tela do calculo de tamanho
    void WordlistFileCalcSize();    // essa função deve printar na tela informções de como o calculo acontece, 
                                    // e tambem calcular qual será o tamanho estimado da wordlis de acordo com 
                                    // as configurações da wordlist

    // processamento do menu de informações
    void MainMenuOptionsBackend(int option);
};

#endif