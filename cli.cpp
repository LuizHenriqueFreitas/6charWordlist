#include "cli.hpp"
#include "core.hpp"
#include <cmath>
#include <iostream>

Cli::Cli(){};

//=========================================================================


//getters e setters
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

// metodo para facilitar plotagem de texto no CLI
// talvez essa função seja movida para um escopo mais externo para que 
// possa ser reutilizada em outras funções fora deste arquivo aqui
void Cli::PrintLine(std::string line)
{
    std::cout << line << std::endl;
}

// facilitador de input para numeros inteiros
int Cli::GetIntInput()
{
    int n;
    if(!(std::cin >> n))
    {
        PrintLine("*** Entrada Invalida! ***");
        std::cin.clear();
        std::cin.ignore(80, '\n');
    }
    return n;
}

//=========================================================================


void Cli::PrintMainMenu()
{
    PrintLine("===================================================================================");
    PrintLine("Este sistema e capaz de gerar wordlists usando base de permutacao simples.");
    PrintLine("  ");
    PrintLine("o sistema usa sistemas de recursão para gerar todas as possibildiades de combinacao");
    PrintLine("usando como possiveis caracteres:");
    PrintLine("    ->> Todas as 26 letras do alfabeto, maiusculas e minusculas.");
    PrintLine("    ->> Numerais de 0 a 9");
    PrintLine("    ->> uma selecao de 14 caracteres especiais, como !@#$%&*+- e outros");
    PrintLine("    ||> esses caracteres acontecem em ordem determinada fixa, assim como descrito");
    PrintLine("    ||> totalizando (neste sistema), o maximo de 80 possiveis opcoes por caractere");
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


    */
    int totalFileSize, limitedFileSize;
    
    //totalFileSize = chamar função de calculo;
    //limitedFileSize = mesma coisa, chama função que calcula;

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
    std::cout << "O arquivo com " << getNumberChar() << "caracteres e " << getNumberOption() << "opcoes.";
    std::cout << "Teria próximo de: " << limitedFileSize;   // tem que encontrar uma forma de converter o tamanho de bytes pra Mb ou Gb, o que for necessario
                                                            // o sistema deve ser dinamico quanto ao tamanho e mostrar de acordo com o tamanho estimado
    PrintLine("Gerar todas as combinacoes possiveis para essa configuracao, geraria um arquivo com");
    std::cout << "aproximadamente: " << limitedFileSize;    // tem que encontrar uma forma de converter o tamanho de bytes pra Mb ou Gb, o que for necessario
                                                            // o sistema deve ser dinamico quanto ao tamanho e mostrar de acordo com o tamanho estimado
    PrintLine(" ");
    PrintLine("===================================================================================");
}


/*
    aqui deve-se ser implementadas as funções de Setconfigs e a de printar os textos
    referentes ao tamanho estimado do arquivo para que os usuarios tenham noção de quanto
    espaço de armazenamento é necesário para gerar o arquivo.
*/

//=========================================================================


void Cli::MainMenuOptionsBackend(int option)
{
//    int option = 0;

    while(option != 3)
    {
        Core engine = Core();

        PrintMainMenu();
     
        option = GetIntInput();         // aloca o input do usuário usando a função facilitadora

        switch (option)
        {
            case 1:
                SetWordlistConfig();
                WordlistFileCalcSize(); 
                break;

            case 2:
                SetWordlistConfig();
                engine.GenerateWordlist(getNumberChar(), 
                                        getNumberOption(), 
                                        getNumberString()
                );
                break;
            
            case 3:
                PrintLine("Encerrando programa...\n");
                break;
            
            default:
                PrintLine("Opcao Inexistente.\n");
                break;
        }
    }
}