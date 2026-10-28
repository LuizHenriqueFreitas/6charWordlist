// necessário documentar todo esse arquivo corretamente

#ifndef __CLI_HPP
#define __CLI_HPP

#include "core.hpp"
#include <iostream>

class Cli {
private:
    /// @brief 
    /// armazena a quantidade de characteres por string que usuario deseja
    int numberOfChars;

    /// @brief 
    /// armazena a quantidade de opções por caractere que o usuario deseja
    int numberOfOptions;

    /// @brief 
    /// armazena a quantidade de strings a ser geradas que o usuario deseja
    int numberOfStrings;

public:
    /// @brief 
    /// armazena um objeto Core para realizar as operaçẽos de cálculos e geração do arquivo
    Core engine;

    /// @brief 
    /// armazena o contador de strings geradas para fazer o controle de acordo com o limite desejado
    int stringCounter;
 
    /// @brief 
    /// metodo construtor, não apresenta parâmetros
    Cli();


    //============================================================
    // GETTERS E SETTERS
    //============================================================
    
    /// @brief 
    /// Busca o número de caracteres por string informado previamente pelo usuário.
    /// @return 
    /// Retorna um valor inteiro referente a quantidade de caracteres por string.
    int getNumberChar();

    /// @brief 
    /// Adiciona um valor inteiro referente a quantidade de caracteres por string.
    /// @param input
    /// Recebe um valor inteiro que sera armazenado como quantidade de caracteres por string.
    void setNumberChar(int input);

    /// @brief 
    /// Busca o número de opções por caractere informado previamente pelo usuário.
    /// @return 
    /// Retorna um valor inteiro referente a quantidade de opções por caractere.
    int getNumberOption();
    
    /// @brief 
    /// Adiciona um valor inteiro referente a quantidade de opções por caracteres.
    /// @param input 
    /// Recebe um valor inteiro que sera armazenado como quantidade de opções por caractere.
    void setNumberOption(int input);
    
    /// @brief 
    /// Busca o número de strings limite a serem geradas informado previamente pelo usuário.
    /// @return 
    /// Retorna um valor inteiro referente a quantidade limite de strings que devem ser geradas.
    int getNumberString();
    
    /// @brief 
    /// Adiciona um valor inteiro referente a quantidade de strings que devem ser gerados.
    /// @param input 
    /// Recebe um valor inteiro que sera armazenado como quantidade de strings que devem ser geradas.
    void setNumberString(int input);


    //============================================================
    // FUNÇÕES UTILITÁRIAS
    //============================================================

    // facilitador de print no terminal
    // PrintLine() foi desenvolvida para facilitar o print do C++ nesse projeto
    // suas 4 variações foram desenvolvidas de acordo com a demanda deste projeto
    // não suprem todas as necessidades existentes de uma função print completa.
    
    /// @brief 
    /// Printa 1 linha no terminal e quebra linha.
    /// @param line 
    /// Recebe uma string qualquer
    void PrintLine(std::string line);

    /// @brief 
    /// Printa 1 linha no terminal e quebra linha. Essa variação concatena 3 strings na mesma linha.
    /// @param line1 
    /// recebe uma string qualquer
    /// @param line2 
    /// recebe uma string qualquer
    /// @param line3 
    /// recebe uma string qualquer
    void PrintLine(std::string line1, std::string line2, std::string line3);

    /// @brief 
    /// Printa 1 linha no terminal e quebra linha. Essa variação concatena 1 variável inteira entre 2 strings na mesma linha.
    /// @param line1 
    /// Recebe uma string qualquer
    /// @param var 
    /// Recebe qualquer valor inteiro
    /// @param line2 
    /// Recebe uma string qualquer
    void PrintLine(std::string line1, int var, std::string line2);

    /// @brief 
    /// Printa 1 linha no terminal e quebra linha. Essa variação concatena interacaladamente, 
    /// 3 strings e 2 variáveis inteiras na mesma linha.
    /// @param line1 
    /// Recebe uma string qualquer
    /// @param var1
    /// Recebe qualquer valor inteiro
    /// @param line2 
    /// Recebe uma string qualquer
    /// @param var2
    /// Recebe qualquer valor inteiro
    /// @param line3
    /// Recebe uma string qualquer
    void PrintLine(std::string line1, int var1, std::string line2, int var2, std::string line3);

    /// @brief 
    /// Printa 1 linha no terminal e quebra linha. Essa variação concatena interacaladamente, 
    /// 4 strings e 3 variáveis inteiras na mesma linha.
    /// @param line1 
    /// Recebe uma string qualquer
    /// @param var1
    /// Recebe qualquer valor inteiro
    /// @param line2 
    /// Recebe uma string qualquer
    /// @param var2
    /// Recebe qualquer valor inteiro
    /// @param line3
    /// Recebe uma string qualquer
    /// @param var3 
    /// Recebe qualquer valor inteiro
    /// @param line4 
    /// Recebe uma string qualquer
    void PrintLine(std::string line1, int var1, std::string line2, int var2, std::string line3, int var3, std::string line4);

    //------------------------------------------------------------

    /// @brief 
    /// Captura a entrada do usuário para valores inteiros
    /// @return 
    /// Retorna um valor inteiro qualquer
    int GetIntInput();                                  // facilita a entrada de dados do tipo "int


    /// @brief 
    /// Pausa o fluxo do programa para que o usuário possa ler o terminal, ao receber um input permite o programa continuar.
    void Wait();

    //============================================================
    // MENUS E TELAS
    //============================================================

    // recebe os valores do usuario - gerencia os inputs

    /// @brief 
    /// recebe os valores de entrada do usuário e envia para ser usado nas funções
    /// de calculo de tamanho e geração da wordlist
    void SetWordlistConfig();       
    
    /// @brief 
    /// deve printar na tela informções de como o cálculo acontece, 
    /// e tambem calcular qual será o tamanho estimado da wordlis de acordo com 
    /// as configurações da wordlist.
    void WordlistFileCalcSize();

    /// @brief
    /// Desenha o menu principal de opções no CLI
    void PrintMainMenu();

    /// @brief
    /// Processamento do menu principal
    void MainMenuOptionsBackend();
};

#endif