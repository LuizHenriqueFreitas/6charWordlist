#ifndef __WORD_HPP
#define __WORD_HPP

#include <iostream>
#include <fstream>

class Word{
public:
    /// @brief 
    /// Construtor do Word(). Não recebe parâmetros
    Word();

    /// @brief 
    /// Wordlist é a função que contrala a construção de string por string, do começo ao final
    /// todos os parâmetros de configuração são recebidos externamente. 
    ///
    /// Wordlist verifica o limit de strings que devem ser geradas, construi as strings com 
    /// recursividade, também valida que a string só será salva quando todas as casas de cada 
    /// string seja completamente preenchida.
    ///
    /// Sempre que uma string é completa, ela é então gravada no arquivo de "wordlist.txt" e 
    /// depois disso a variável 'output' é limpa e reescrita com a próxima string.
    /// @param WordlistFile 
    /// WordlistFile recebe por referência o arquivo de texto abeto anteriormente, para que
    /// possa ser editado dentro de WordManager, conforme as strings são geradas.
    /// @param slots 
    /// slots é relacionado a quantidade de slots por string, a quantidade de caracteres que
    /// a string deve ter, considerando que não serão geradas strings menores que a quantidade
    /// informada neste parâmetro. Todas as strings geradas terão esse tamanho fixo.
    /// @param options 
    /// options é referente a quantidade de opções que devem ser permutadas para cada um dos
    /// espaços de caractere das strings geradas.
    /// Nesse código isso acontece na mesma ordem do charset.cpp, ou seja, options = 4, permutaria
    /// entre {a, b, c, d}.
    /// @param position 
    /// essa é uma variavel que não deve ser mexida, seu valor inicial tem que ser "1" para funcionamento
    /// correto da função. ele é o iterador entre índices do output de acordo com a recursão.
    /// @param limit 
    /// esse parametro serve como controle do limite de strings a serem geradas, em cada chamada
    /// da recursão ele é comparado com o contador para verificar se foi atingido.
    /// @param wordCounter 
    /// referencia do contador externo instanciado em core.cpp. Essa variável faz o controle da 
    /// quantidade de strings geradas.
    /// @param output 
    /// esse arrays de caracteres comporta cada string durante sua construção, ao final é inserido
    /// no arquivo de texto e depois é sobrescrita pela próxima string.
    void WordManager(std::ofstream&WordlistFile,    
                        int slots,                  
                        int options,                
                        int position,               
                        int limit,                  
                        int&wordCounter,            
                        char(&output)[]             
    );
};

#endif