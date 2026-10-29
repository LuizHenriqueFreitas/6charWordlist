### Estrutura
Este projeto foi desenvolvido visando Orientação a Objetos e desacoplamento de dependências no máximo possível.   
A estrutura de dependencias acontece na seguinte ordem:
> main > cli > core > word > spin > charset

---

### Classes e outros
0. **Main.cpp**  
Main.cpp é o arquivo que contem a função main() desse projeto, ou seja, é o que mantemo sistema em funcionamento.

1. **Cli.cpp**   
Controla todas as funções de I/O, todas as funções que printam 'telas' no terminal e também as funções auxiliares que 
foram desenvolvidas, como "PrintLine()s" e também "Wait()" e "GetIntInput()".

2. **Core.cpp**   
Implementa as funções de cálculo de tamanho e também o gerador/gravador de words na wordlist.

3. **Word.cpp**   
Implementa o permutador de caracteres, controla a geração de cada palavras individualmente.

4. **Spin.cpp**
Funciona como um seletor, recebe o índice desejado por referencia e devolve o valor informado com base do charset utilizado.

5. **Charset.cpp**   
Neste projeto, é responsável por guardar os caracteres que podem ser usados na geração de strings.

6. **Arqvuivos .hpp e .lua**   
- Os arquivos .hpp são usados nesse projeto para declarar as classes, seus métodos e atributos, enquanto sua lógica é sempre implementada num arquivo separado .cpp.

- O arquivo "logicThinking.lua" foi usado para o desenvolvimento da lógica de permutação, onde estão documentados todo o pensamento de desenvolvimento da lógica.
    > Lua foi escolhida para isso por ser uma linguagem interpretada e apresentar um ciclo de teste muito mais rápido sem a necessidade de recompilar a cada alteração.