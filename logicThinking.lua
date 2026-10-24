--[[ este script foi criado para explorar a lógica de funcionamento do spin de maneira 
    mais rápida e prática sem ter que ficar recompilando o c++.

    Uso de IAs reduzido apenas a comentarios sobre o codigo desenvolvido para buscar 
    erros óbvios que eu deixe passar, mas a lógica de funcionamento deve ser desenvolvida 
    organicamente.

    Abaixo a listagem do funcionamento desse mecanismo, para tentar ajudar a entender
    o que deve ser feito e como faremos.
]]


-- ============================================================================
--[[ a função spin deve roletar verticalmente uma casa, ou seja, imagine uma caça niquel,
    daqueles que tem 3 rolos e o apostador ganha caso todos parem no mesmo simbolo. 
    🎰 <- tipo esse emoji.

    Essa função simula o funcionamento de 1 rolo individual.
    ou seja, a função deve receber N como o parametro que diz quantas opções tem no rolo.
    também deve receber a string que armazena os valores, onde vai concatenar o resultado.

    Importante pontual que esse "rolo" é o charset, N dita até qual índice do charset será 
    usado na permutação, atigindo o limite máximo de 80, que é o tamanho final do charset
    nesse sistema.
]]
-- ============================================================================


-- ============================================================================
--[[ para fins de entendimento do problema, vamos descrever tambem o funcionamento do CORE
    
    A função de core gerencia a criação de strings manipulando outras funções como a spin.
    Uma vez que a função spin apenas "gira o rolo" de cada casa, o core fica responsável
    pelo gerenciamento de:
        - 1 quantidade de strings e quebras de linha; 
        - 2 quantidade de casas da string;
    para gerenciar isso é usado um sistema 2 for loops, um dentro do outro, sendo que o externo
    é referente a linha que esta sendo permutada e o interno é referente as casas da string.

    ou seja, num exemplo onde queremos gerar 3 strings de 2 casas que permutem entre 4 opções,
    o laço externo seria (i < 3), o interno (i < 2) e o controne dentro de spin seria de charset[0 até 3]
]]
-- ============================================================================


-- ============================================================================
--[[ meu GRANDE PROBLEMA com o desenvolvimento desse algoritmo é que:
    
    o objetivo é que seja feita uma combinação teóricamente simples, ou seja, no exemplo dado acima,
    com 2 casas e 4 opções por casa, o resultado deveria ser algo como: aa, ab, ac, ad, ba, [...], dd.
    Porém, estou com dificuldade para entender como fazer isso.

    repare que a ordem é { aa, ab, ac } - NÃO { aa, ab, bb, bc }, pois essa segunda opção deixaria muitas
    combinações perdidas no meio do caminho.

    Ou seja, é necessário fazer alguma outra combinação de laços, onde o laço mais externo é o caractere
    mais a esquerda na string, enquanto o laço mais interno é o caractere mais a direita, ou seja, cada casa
    prescisa ter seu proprio laço dentro do laço do caractere anterior.

    A lógica para cobrir nosso exemplo de 2 casas seria algo como: 
        - Laço da primeira casa, iterando de 1 em 1, até o máximo de opções disponíveis (4), porém, cada 
        iteração desse laço tem dentro dela mais 4 iterações de outro laço com as mesmas configurações.
    Se fossem 3 casas haveria mais um laço igual acontecendo 4 vezes dentro do segundo laço.

    Tem como colocar recursividade nisso? provavelmente, afinal é o mesmo laço, e funções recursivas substituem
    laços em situações como essa. Agora, onde isso acontece? no core ou no spin? talvez o spin devesse girar todos 
    os rolos recursivamente, não apenas 1, pode ser esse o gargalo.
]]
-- ============================================================================


-- aqui será desenvolvida a lógica função core para fins de testes rápidos sem a necessidade de recompilar 
-- a cada alteração
local function Core()
    local quantidadeLinhas = 8;
    local quantidadeCasas = 2;
    local quantidadeOpcoes = 4;

    for i=1, quantidadeLinhas, 1 do
        local output = ""

        for j=1, quantidadeCasas, 1 do
            spin(output, quantidadeOpcoes)
        end

        print(output .. "\n")
        output = ""
    end
end

-- abaixo o desenvolvimento da lógica da função de spin
local function spin(output, options)
    local set = {'a', 'b', 'c', 'd'}
    
    for
end

-- tenho que pensar melhor nessa lógica, o projeto não esta printando nada na tela
