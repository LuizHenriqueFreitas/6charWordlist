#ifndef __WORD_HPP
#define __WORD_HPP

#include <iostream>
#include <fstream>
#include "charset.cpp"

class Word{
public:
    Word();
    void WordManager(std::ofstream&WordlistFile,    // pega o arquivo de texto "wordlist.txt" como referência para que possa ser editado
                        int slots,                  // quantidade de slots por casa
                        int options,                // quantidade de opções por slot
                        int position,               // posição da recursão
                        int limit,                  // limite de strings a serem geradas
                        int&wordCounter,            // referência do contador de strings do core.cpp
                        char(&output)[]             // referência da string permutada
    );
};

#endif