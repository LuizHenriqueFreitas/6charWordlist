#include "core.hpp"
#include "word.hpp"
#include <iostream>
#include <fstream>  // lib de manipulação de arquivos

Core::Core(){}      // metodo sontrutor, vazio até o momento

/// @brief 
/// GenerateWordList cria o arquivo "wordlist.txt" e aloca ele para edição ao longo do programa.
///
/// Essa clásse chama o gerenciador de strings e configura as variáveis de ambiente do gerador, como quantidade de strings,
/// quantidade de casas, quantidade de opções.

/// @return 
/// Retorna verdadeiro quando bem sucedido, e falso quando falha em criar/ acessar o arquivo de armazenamento da wordlist
bool Core::GenerateWordlist()
{    
    Word word = Word();
    WordlistFile.open("wordlist.txt");                  // cria e abre o arquivo "wordlist.txt" para gravação

    // simples verificação se houve sucesso na criação do arquivo
    if (!WordlistFile.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo.\n";    // mensagem de erro em caso de falha ao criar ou abrir o arquivo .txt
        return false;
    }

    // essas variáveis devem ser declaradas no header posteriormente
    int numberOfSlots = 6;                              // numero de casas de cada string
    int numberOfOptions = 3;                            // numero de opções por casa
    int numberOfStrings = 6;                            // numero de strings geradas
    int stringCounter = 0;                              // contador de strings geradas
    char output[numberOfSlots];                         // string de output - renovado a cada string

    // chama o gerenciador de string da classe "word"
    word.WordManager(WordlistFile,                      // manda como referencia o ofstream do arquivo de texto que será editado
                    numberOfSlots-1,                    // manda a quantidade de casas por string | o -1 é necessário para ajustar o output correto
                    numberOfOptions,                    // numero de opções
                    0,                                  // posição começa em "0"
                    numberOfStrings,                    // numero de strings máximo
                    stringCounter,                      // contador de strings geradas
                    output                              // variavel que armazena output a cada string
    );
    
    WordlistFile.close();                               // fecha o arquivo que estavamos trabalhando
    return true;                                        // retorna a função como verdadeira
}