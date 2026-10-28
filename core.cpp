#include "core.hpp"
#include "word.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdint>
#include <fstream>  // lib de manipulação de arquivos

Core::Core(){}      // metodo sontrutor, vazio até o momento

//======================================================================================
// CALCULATORS
//======================================================================================

// optei por fazer apenas uma função de calculo com um parâmetro de controle "type", para evitar
// ficar repetendi código, uma vez que as 2 teriam que calcular o string size

std::uint64_t Core::CalculateFileSize(int numberOfSlots, int numberOfOptions, int numberOfStrings, int type)
{
    int stringSize = numberOfSlots + 1;
    std::uint64_t bytesSize;
    if (type == 0)
    {
        std::uint64_t variations = pow(numberOfOptions, numberOfSlots);
        bytesSize = variations * stringSize;

        return bytesSize;
    }
    else if (type == 1)
    {
        bytesSize = numberOfStrings * stringSize;
        return bytesSize;
    } 
    else
    {
        return -1;
    }
}


//======================================================================================

std::string Core::ConvertFileBytes(long int fileSizeBytes)
{
    int size = 0;

    const char* units[] = {
        "B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB"
    };

    while(fileSizeBytes >= 1000.0 && size < 6)
    {
        fileSizeBytes /= 1000.0;
        size++;
    }

    std::ostringstream result;
    result << std::fixed << std::setprecision(2)
            << fileSizeBytes << "" << size[units];

    return result.str();
}

//======================================================================================
// GENERATORS
//======================================================================================

// essa função faz a geração e controle de permutação do arquivo wordlist.txt

bool Core::GenerateWordlist(int numberOfSlots, int numberOfOptions, int numberOfStrings)
{    
    Word word = Word();
    WordlistFile.open("wordlist.txt");                  // cria e abre o arquivo "wordlist.txt" para gravação

    // simples verificação se houve sucesso na criação do arquivo
    if (!WordlistFile.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo.\n";    // mensagem de erro em caso de falha ao criar ou abrir o arquivo .txt
        return false;
    }

    // variáveis internas de controle
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