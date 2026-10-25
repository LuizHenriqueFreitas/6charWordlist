#include "spin.hpp"
#include "charset.cpp"

Spin::Spin(){}      // metodo construtor - vazio até o momento

/// @brief
/// Esse metodo funciona como um coletor, ele recebe o índice, que é processado
/// externamente, em outra função. Spinset usa o índice para selecionar um dado
/// diretamente do charset
char Spin::SpinSet(int n){
    return charset[n];
}
