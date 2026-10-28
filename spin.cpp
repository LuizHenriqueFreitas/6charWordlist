#include "spin.hpp"
#include "charset.cpp"

Spin::Spin(){}              // metodo construtor - vazio até o momento

char Spin::SpinSet(int n){  // metodo que coleta valor do charset de acordo com o valor recebido
    return charset[n];
}
