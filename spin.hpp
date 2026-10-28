#ifndef SPIN_HPP
#define SPIN_HPP

class Spin
{
public:
    /// @brief 
    /// Construtor Spin, metodo vazio.
    Spin();

    /// @brief
    /// Esse metodo funciona como um coletor, ele recebe o índice, que é processado
    /// externamente, em outra função. Spinset usa o índice para selecionar um dado
    /// diretamente do charset.
    /// @param n
    /// recebe um valor inteiro, que será usado como índice no charset para buscar 
    /// um character
    char SpinSet(int n);
};

#endif