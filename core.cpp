#include "core.hpp"
#include "spin.hpp"
#include <iostream>
#include <fstream>  // lib de manipulação de arquivos

Core::Core(){}      // metodo sontrutor, vazio até o momento

/// @brief 
/// Essa classe processa a permutação de strings, recebe como parametros a quatidade de strings a calcular, assim como a 
/// o tamanho que cada string deve ter.
/// @return 
/// Retorna verdadeiro quando bem sucedido, e falso quando falha em criar/ acessar o arquivo de armazenamento da wordlist
bool Core::GenerateWordlist()
{    
    Spin spin = Spin();                                 // instancia um objeto de gira - sera usado nas casas para permutação
    WordlistFile.open("wordlist.txt");                  // cria e abre o arquivo "wordlist.txt" para gravação

    // simples verificação se houve sucesso na criação do arquivo
    if (!WordlistFile.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo.\n";
        return false;
    }

    // essas variáveis devem ser declaradas no header posteriormente
    int size = 6;
    int numberOfStrings = 6;

    // aqui é o nucleo de processamento do permutador
    for(int i =0; i < numberOfStrings; i++)             // cada linha do arquivo de wordlist
    {
        std::string string;                             // string que armazena os valores permitados
        std::string* ptrOutput = & string;              // ponteiro para manipulação dessa string por diferentes objetos

        for(int j=0; j < size; j++)                     // esse arqui deveria fazer a permutação de cada coluna, ou seja, cada caractere único
        {
            int counter = 0;                            // contador -  tenho que explorar mais filosoficamente o que ele conta
            int* ptrCounter = &counter;                 // ponteiro para manipular o contador em diferentes lugares do sistema
            spin.SpinSet(*ptrOutput, 2, *ptrCounter);   // chamada do metodo de giro da casa - pense nos peões do baú ou no funcionamento do tigrinho
        }

        WordlistFile << string << '\n';                 // concatena a string atual e quebra a linha
    }
    WordlistFile.close();                               // fecha o arquivo que estavamos trabalhando
    return true;                                        // retorna a função como verdadeira
}