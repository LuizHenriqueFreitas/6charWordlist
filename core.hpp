#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <fstream>

class Core 
{
private:
    /// @brief 
    /// Armazena o direcionamento ao arquivo .txt onde o sistema esta gravando os dados gerados em tempo real.
    std::ofstream WordlistFile;
public:
    /// @brief 
    /// Construtor Core. Não recebe parâmetros.
    Core();

    //======================================================================================
    // CALCULATORS
    //======================================================================================

    /// @brief 
    /// Faz o canlculo de quantos bytes é previsto que o arquivo final de wordlist deve pesar.
    /// Esse cálculo é feito com base no charset, composta apenas de caracteres da tabela ASCII.
    /// Só é usada dentro do sistema, é chamada para calcular, usuário não interage diretamente com essa função
    /// @param numberOfSlots 
    /// Informa o número de caracteres por palavra.
    /// @param numberOfOptions 
    /// Informa o número de opções por caractere.
    /// @param numberOfStrings 
    /// Informa a quantidade de strings que o usuário deseja gerar.
    /// @param type 
    /// Define se a função deve calcular o peso de um arquivo que gere todas as combinações possiveis (0)
    /// ou se o peso do arquivo com a quantidade de strings definida pelo usuário (1).
    /// @return 
    long int CalculateFileSize(int numberOfSlots, int numberOfOptions, int numberOfStrings, int type);

    
    //======================================================================================

    /// @brief 
    /// Converte o valor de bytes por extendo de acordo com as escalas de tamanho para armazenamento
    /// digital, cobrindo desde Bytes, KiloBytes ... até os ZettaBytes. A divisão é feita na base decimal
    /// e não binária pelas convenções já estabelecidas.
    /// @param FileSizebytes 
    /// Recebe o valor de bytes por extenso, recomendado usar a função calcFileSize para conseguir este dado.
    /// @return 
    /// Retorna uma string formatada com o valor final e sua unidade de medida.
    std::string ConvertFileBytes(long int FileSizebytes);
    

    //======================================================================================
    // GENERATORS
    //======================================================================================
    
    /// @brief 
    /// GenerateWordList cria o arquivo "wordlist.txt" e aloca ele para edição ao longo do programa.
    ///
    /// Essa clásse chama o gerenciador de strings e configura as variáveis de ambiente do gerador, como quantidade de strings,
    /// quantidade de casas, quantidade de opções.
    /// @return 
    /// Retorna verdadeiro quando bem sucedido, e falso quando falha em criar/ acessar o arquivo de armazenamento da wordlist
    bool GenerateWordlist(int numberOfSlots, int numberOfOptions, int numberOfStrings);        // gera o arquivo wordlit.txt de acordo com as configurações enviadas pelo usuario
};

#endif