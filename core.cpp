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

// optei por fazer apenas uma função de calculo com um parâmetro de controle "total", para evitar
// ficar repetendi código, uma vez que as 2 teriam que calcular o string size, true calcula total, false calcula com base na quantidade de strings desejadas.

std::uint64_t Core::CalculateFileSize(int numberOfSlots, int numberOfOptions, int numberOfStrings, bool total)
{
    int stringSize = numberOfSlots + 1;                     // calcula o tamnho de uma string individual + quebra de linha
    std::uint64_t bytesSize;                                // instancia a variável que vai armazenar o tamanho em bytes
    
    // calcula o tamanho total com todas as variações possíveis
    if (total)  
    {
        std::uint64_t variations = pow(numberOfOptions, numberOfSlots); // calcula a quantidade de variações possíveis 
                                                                        // <Numero de opções> elevado ao <Numero de caracteres> por palavras da lista
        bytesSize = variations * stringSize;                // multiplica o peso de 1 string pela quantidade de variações possíveis

        return bytesSize;                                   // retorna o peso esperado em bytes - posteriormente sera formatado de acordo com seu nível de grandeza
    }
    // calcula o tamanho do arquivo gerando apenas a quantidade de strings desejada
    else                                   
    {
        bytesSize = numberOfStrings * stringSize;           // multiplica a quantidade de strings desejada pelo peso de 1 string
        return bytesSize;                                   // retorna o peso esperado em bytes - posteriormente sera formatado de acordo com seu nível de grandeza
    } 
}


//======================================================================================

// projetado para formatar o tamanho em bytes de acordo com sua ordem de grandeza para melhor visualização

std::string Core::ConvertFileBytes(long int fileSizeBytes)
{
    int size = 0;                                           // variável local facilitar operação e selecionar a unidade correta

    const char* units[] = {                                 // lista de unidade/nomeclaturas em ordem de grandeza crescente
        "B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB"
    };

    // detecta em que nivel de grandeza está
    while(fileSizeBytes >= 1000.0 && size < 6)
    {
        fileSizeBytes /= 1000.0;                        // sobe 1 nivel de grandeza
        size++;                                         // ajusta o seletor de unidade
    }

    // formata saída
    std::ostringstream result;
    result << std::fixed << std::setprecision(2) << fileSizeBytes << "" << size[units];

    return result.str();                                // returna string formatada com tamanho correto e unidade de medida
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