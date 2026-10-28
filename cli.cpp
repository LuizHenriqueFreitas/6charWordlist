#include "cli.hpp"
#include "core.hpp"
#include <iostream>

Cli::Cli(){};


//=========================================================================
// GETTERS E SETTERS
//=========================================================================

int Cli::getNumberChar() {
    return numberOfChars;
}

void Cli::setNumberChar(int input) {
    numberOfChars = input;
}

int Cli::getNumberOption() {
    return numberOfOptions;
}

void Cli::setNumberOption(int input) {
    numberOfOptions = input;
}

int Cli::getNumberString() {
    return numberOfStrings;
}

void Cli::setNumberString(int input) {
    numberOfStrings = input;
}


//=========================================================================
// UTILITÁRIOS DE I/O
//=========================================================================

// metodo para facilitar prints no terminal
void Cli::PrintLine(std::string line)
{
    std::cout << line << std::endl;
}

// variação para imprimir com uma variavel no meio do texto
void Cli::PrintLine(std::string line1, int var, std::string line2)
{
    std::cout << line1 << var << line2 << std::endl;
}

// variação para imprimir com duas variaveis no meio do texto
void Cli::PrintLine(std::string line1, int var1, std::string line2, int var2, std::string line3)
{
    std::cout << line1 << var1 << line2 << var2 << line3 << std::endl;
}


//-------------------------------------------------------------------------

// facilitador de input para numeros inteiros
int Cli::GetIntInput()
{
    int n;
    if(!(std::cin >> n))                            // loop de entrada de dados
    {
        PrintLine("*** Entrada Invalida! ***");     // bloqueia entradas inválidas
        
        std::cin.clear();                           // limpa buffer do teclado
        std::cin.ignore(80, '\n');
    }
    return n;                                       // retorna entrada do usuário
}


//=========================================================================
// MENUS / TELAS
//=========================================================================


void Cli::SetWordlistConfig()
{
    PrintLine("===================================================================================");
    PrintLine("Informe, COM NUMERO INTEIRO, o numero de caracteres que as palavras da lista.");
    setNumberChar(GetIntInput());
    PrintLine("  ");
    PrintLine("Agora a quantidade de opcoes para cada caractere, USE NUMEROS INTEIROS.");
    setNumberOption(GetIntInput());
    PrintLine("  ");
    PrintLine("Por fim, informe a quantidade de strings que deseja gerar, APENAS NUMEROS INTEIROS.");
    setNumberString(GetIntInput());
    PrintLine("  ");
    PrintLine("===================================================================================");
}


//=========================================================================


void Cli::WordlistFileCalcSize()
{
    /*
        implementar uma classe matematica - onde deveremos implementar o calculo matematico
        de char ^ option, depois tem que incluir o contador de tamanho da string e depois multiplicar
        pela quantidade de strings

        um lugar bom pra implementar isso é no core.cpp
    */
    int totalFileSize, limitedFileSize;
    
    //totalFileSize = chamar função de calculo;
    //limitedFileSize = mesma coisa, chama função que calcula;
    //interessante fazer uma função que converta bytes em bites, MBs, GBs e TBs

    PrintLine("===================================================================================");
    PrintLine("O arquivo wordlist e um arquivo .txt que contem uma lista de palavras, cada linha  ");
    PrintLine("possui apenas uma palavra.");
    PrintLine(" ");
    PrintLine("Esse tipo de mecanismo é usado para tentativas de forca bruta na quebra de senhas e");
    PrintLine("acessos em sistemas eletronicos.");
    PrintLine(" ");
    PrintLine("Num ambiente ideial, permutar todos os valores possiveis, casa por casa, gerando   ");
    PrintLine("todas as combinações possíveis, faria com que o arquivo contesse TODAS as senhas   ");
    PrintLine("existentes.");
    PrintLine(" ");
    PrintLine("Esse sistema contem apenas 80 caracteres diferentes, apresentados na tela principal");
    PrintLine(", todos da tabela ASCII. Um string de 6 caracteres + quebra de linha, teria 7 bytes");
    PrintLine("Portanto...");
    PrintLine("O arquivo com ", getNumberChar(), "caracteres e ", getNumberOption(), "opcoes.");
    PrintLine("Teria próximo de: ", limitedFileSize, ".");  // tem que encontrar uma forma de converter o tamanho de bytes pra Mb ou Gb, o que for necessario
                                                            // o sistema deve ser dinamico quanto ao tamanho e mostrar de acordo com o tamanho estimado
    PrintLine("Gerar todas as combinacoes possiveis para essa configuracao, geraria um arquivo com");
    PrintLine("aproximadamente: ", totalFileSize, ".");     // tem que encontrar uma forma de converter o tamanho de bytes pra Mb ou Gb, o que for necessario
                                                            // o sistema deve ser dinamico quanto ao tamanho e mostrar de acordo com o tamanho estimado
    PrintLine(" ");
    PrintLine("O calculo feito para saber o tamnho dos arquivos é: ");
    PrintLine("     |- Quantidade variações = nº de caracteres, elevado a quantidade de opções;");
    PrintLine("     |- Calcula o tamanho estimado de uma única string. Caracteres + quebra linha;");
    PrintLine("     |- Por fim, multiplica a quantidade de opções pelo peso de cada string.");
    PrintLine("===================================================================================");
}

//=========================================================================


// printa o menu pricipal do sistema
void Cli::PrintMainMenu()
{
    PrintLine("===================================================================================");
    PrintLine("Este sistema e capaz de gerar wordlists usando base de permutacao simples.");
    PrintLine("  ");
    PrintLine("o sistema usa sistemas de recursão para gerar todas as possibildiades de combinacao");
    PrintLine("usando como possiveis caracteres:");
    PrintLine("    ->> Todas as 26 letras do alfabeto, maiusculas e minusculas.");
    PrintLine("    ->> Numerais de 0 a 9");
    PrintLine("    ->> uma selecao de 22 caracteres especiais, como !@#$%&*+- e outros");
    PrintLine("    ||> esses caracteres acontecem em ordem determinada fixa, assim como descrito");
    PrintLine("    ||> totalizando (neste sistema), o maximo de 84 possiveis opcoes por caractere");
    PrintLine("  ");
    PrintLine("-----------------------------------------------------------------------------------");
    PrintLine("  ");
    PrintLine("Com esse sistema você pode escolher:");
    PrintLine("I  -> Quantidade de caracteres que suas palavras devem ter;");
    PrintLine("II -> Quantidade de opcoes por caractere que devem ser permutados;");
    PrintLine("III-> Quantidade limite de palavras que você deseja gerar;");
    PrintLine("  ");
    PrintLine("-----------------------------------------------------------------------------------");
    PrintLine("  ");
    PrintLine("Escolha entre:");
    PrintLine(" 1. | Calcular tamanho estimado do arquivo.");
    PrintLine(" 2. | Gerar wordlist.");
    PrintLine(" 3. | Fechar sistema.");
    PrintLine("  ");
    PrintLine("===================================================================================");
}

//=========================================================================


void Cli::MainMenuOptionsBackend()
{
    int option = 0;                         // variavel local de controle

    while(option != 3)                      // enquanto a opçao selecionada NÂO for = 3
    {
        Core engine = Core();               // instancia um objeto Core

        PrintMainMenu();                    // printa o menu principal no terminal
     
        option = GetIntInput();             // aloca o input do usuário usando a função facilitadora

        switch (option)                     // troca de acordo com a opção escolhida pelo usuário
        {
            case 1:                         // opção 1
                                            //
                SetWordlistConfig();        // seta variáveis de controle da lista
                WordlistFileCalcSize();     // printa a tela sobre tamanho estimado do arquivo
                break;

            case 2:                                         // opção 2
                                                            // 
                SetWordlistConfig();                        // seta variáveis de controle da lista
                engine.GenerateWordlist(getNumberChar(),    // chama o gerador de worflist do Core
                                        getNumberOption(),  // envia como parametros o numero de 
                                        getNumberString()   // caracteres, opções e strings limite
                );
                break;
            
            case 3:                                         // opção 3
                PrintLine("Encerrando programa...\n");      // printa mensagem ao usuário para avisar que o programa foi encerrado
                break;
            
            default:                                        // qualquer outro valor
                PrintLine("Opcao Inexistente.\n");          // avisa o usuario que o input foi uma opção inválida
                break;
        }
    }
}