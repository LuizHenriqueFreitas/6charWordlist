#include "word.hpp"
#include "spin.hpp"

Word::Word(){}          // metodo construtor - vazio até o momento


void Word::WordManager(std::ofstream&WordlistFile,      // pega o arquivo de texto "wordlist.txt" como referência para que possa ser editado
                        int slots,                      // quantidade de slots por casa
                        int options,                    // quantidade de opções por slot
                        int position,                   // posição da recursão
                        int limit,                      // limite de strings a serem geradas
                        int&wordCounter,                // referência do contador de strings do core.cpp
                        char(&output)[]                 // referência da string permutada
)
{
    Spin spin = Spin();                                 // instancia da classe spin

    if(wordCounter >= limit)                            // verifica se atingiu o limite de strings desejado
    {                                                   //
        return;                                         // termina caso passe do limite
    } 


    else if (position > slots)                          // verifica que todos os slots da string foram preenchidos
    {
        wordCounter += 1;                               // incrementa o contador de core.cpp
        WordlistFile << output << '\n';                 // concatena a string atual e quebra a linha
        return;                                         // termina a função
    }

    for(int i = 0; i < options; i++)                    // iteração por todas as opções
    {
        output[position] = spin.SpinSet(i);             // direciona a função spinSet para cada posição do output
                                                        // como isso roda num laço por todas as opções, somado a 
        WordManager(WordlistFile, slots, options,       // chamada de recursão da classe WordManager, é garantido 
                    position + 1, limit, wordCounter,   // que todas as casas serão roletadas, fazendo assim todas
                    output                              // as combinações possíveis.
        );
    }
}