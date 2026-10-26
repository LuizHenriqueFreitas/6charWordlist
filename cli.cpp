#include "cli.hpp"
#include <iostream>

Cli::Cli(){};


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

//---------------------------------------------------------------------

// metodo para facilitar plotagem de texto no CLI
// talvez essa função seja movida para um escopo mais externo para que 
// possa ser reutilizada em outras funções fora deste arquivo aqui
void Cli::PrintLine(std::string line)
{
    std::cout << line << std::endl;
}

void Cli::PrintMenu()
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
    PrintLine("1 -> Quantidade de caracteres que suas palavras devem ter;");
    PrintLine("2 -> Quantidade de opcoes por caractere que devem ser permutados;");
    PrintLine("3 -> Quantidade limite de palavras que você deseja gerar;");
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

void Cli::OptionsBackend(int option)
{
//    int option = 0;

    while(option != 3)
    {
        PrintMenu();

/* --isso aqui tem que acontecer na main- option vem como parâmetro
        if(!(std::cin >> option))
        {
            PrintLine("*** Entrada Invalida! ***");
            std::cin.clear();
            std::cin.ignore(80, '\n');
            continue;
        }
*/

        switch (option)
        {
            case 1:
                // implementar função referente
                // Calcular tamanho de arquivo
                break;

                // provavelmente é importante adicionar uma função externa que possa ser importanda
                // tanto para o caso 1 quanto para o caso 2, já que ambos prescisam saber quantas
                // casas, quantas opções por casa e quantas strings serão geradas

            case 2:
                // implementar função referente
                // Criar o arquivo de fato
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