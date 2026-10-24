#include "spin.hpp"
#include "charset.cpp"

Spin::Spin(){}      // metodo construtor - vazio até o momento

/// @brief
/// metodo de giro, recebe como parâmetros string de processamento das permutas
/// assim como referente ao numero de caracteres das strings de saida e para
/// processamento do contador de permutagem
void Spin::SpinSet(std::string&output, int n, int &counter){
    /*
    toda a logica disso daqui vai ter que ser revisada e entendida, provavelmente refeita
    */
    if(counter == 0)
    {
        for(int i = 0; i < n; i++)
        {
            output += charset[counter];
        }
        counter++;
    } else if(counter > 0 && counter < n)
    {
        for(int i=0; i< n; i++)
        {
            if(i == n-1){
                output += charset[counter-1];
                SpinSet(output, n, counter);
            } else {
                output += charset[counter];
            }
        }
        counter++;
    }
}