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


-- ============================================================================
--[[ o que deve acontecer aqui dentro (do spin) é que devemos iterar as possibilidades de todas as 
    casas, essa é a função do spin - para fazer isso pode ser que seja interessante fazer com que 
    o output seja na verdade um array que comporte cada char em um índice.
]]
-- ============================================================================


-- ============================================================================
--[[ seria interessante por exemplo, cria um array com o tamanho da string desejada, no caso pro 
    objetivo incial do projeto seria uma string de 6 caracteres, ou um array de 6 índices.
    Prescisamos fazer isso recursivo de modo que, ele busca sempre o ultimo indice do arrei e itera 
    ele por todas as opções possíveis, o recrusivo recebe o arranjo e itera o ultimo denovo, até 
    que o array fique vazio.

    
    essa função deveria funcionar como, programando em hopeNG: 
    
    dec spin : list num # list num -> list num;
    --- spin([], newlist) <- newlist;
    --- spin(list, newlist) <- spint(arranjo(list), newlist++[iterar(ultimo(list))]);
    
    
    explorando isso podemos perceber que temos algumas operações embutidas nesse pensamento, e ainda
    temos 1 problema primordial.

    
    Falando sobre as operações, para que a recursividade funcione prescisamos de funções para acessar
    o último e o arranjo do array que comporta o output, além disso é necessário uma função de iteração
    que faria o papel dos laços "for".

    
    O grande problema é que a cada iteração ele prescisa ser printado no arquivo, além disso será neces-
    sario um mecanismo que faça a iteração de maneira mais distribuida, por do modo como esta, funcionaria
    no começo, mas haveriam combinaçẽos perdidas no meio do caminho, como por exemplo, com 3 casas 4 opções
    por casa, de "a" até "d", aaa, aab, aac, isso funciona, mas não teriamos, bba ou mesmo bab seguindo essa
    lógica.

    
    Ou seja, é necssário um mecanismo que alem de iterar, intercale as iterações, e além disso, que 
    também print a cada iteração que acontece.
]]
-- ============================================================================


-- ============================================================================
--[[ Estive conversando um pouco com o GPT, a minha lógica tem ainda alguns problemas, provavelmente
    teremos de implementar algum intermediário entre o core e o spin, deixando o core para gerenciar
    a quebra de linhas entre strings, fazer um intermediador para gerir cada string e deixar o spin
    para cuidar de cada casa.
]]
-- ============================================================================


-- ############################################################################
-- ############################################################################
-- ############################################################################
--[[ Depois de conversar mais um pouco com o GPT eu consegui fazer a permutação acontecer corretamente,
    o que acontece é que o spin é apenas um seletor, para que possa ser acessado apartir do iterador de
    um laço "for" qualquer.

    Enquanto isso o word é uma função responável por gerenciar cada palavra, onde ele implementa aquela
    questão de 1 laço para cada caractere da string de output que está documentado lá no começo desse 
    mesmo arquivo.

    Word também faz o controle do limite de strings a serem gerados de acorcom o contador local comparado
    ao valor limite que posteriormente sera informado pelo usuário.
]]
-- ############################################################################
-- ############################################################################
-- ############################################################################


-- ============================================================================
--[[ Como próxima atividade podemos explorar como tonar a questão dos laços aninhados do word() algo 
    recursivo e automatizado para que o usuário possa escolher o tamanho de string desejado.
]]
-- ============================================================================


WordCounter = 0;                                -- inicia o contador que contrala o limite de strings a serem geradas
local saida = {}                                -- string standard/ default


-- abaixo o desenvolvimento da lógica da função de spin em lua, pela agilidade de teste e desenvolvimento
-- do algoritmo sem a necessidade de recompilar a cada alteração.
local function spin(option)                     -- recebemos apenas o indice a ser spinado
    local set = {'a', 'b', 'c', 'd'}            -- instanciando um charset local para testes

    return set[option]                          -- retorna a opção de acordo com a iteração externa a função
end


-- essa função serve para gerenciamento de cada word sendo gerada
local function word(saida, casas, options, posicao, limite)
    if WordCounter >= limite then               -- verefica se atingiu o limite de linhas a gerar
        return
    
    elseif posicao > casas then                 -- verifica que todas as casas estão preenchidas, printa a word completa
        WordCounter = WordCounter + 1           -- adiciona 1 a contagem de linhas criadas
        print(table.concat(saida))              -- printa cada combinação possível     
        return                         
    end    

    for j=1, options do                                 -- laço de repetição por todas as opções
        saida[posicao] = spin(j)                        -- coloca opção em cada uma das posições
        word(saida, casas, options, posicao + 1, limite)-- chama recursivamente a proxima posição
    end
end


-- aqui será desenvolvida a lógica função core para fins de testes rápidos sem a necessidade de recompilar 
-- a cada alteração
local function core()
    local quantidadeLinhas = 2;                 -- define o limite de strings a imprimir
    local quantidadeCasas = 2;                  -- define a quantidade de casa que as strings vão ter - quantidade fixa, 
                                                -- 3 unidades é {aaa, aab}, NÃO {a, aa, aaa, aab}
    
    local quantidadeOpcoes = 4;                 -- quantidade de opções que serão iteradas no charset - segue a ordem 
                                                -- declarada no charset

    word(saida, quantidadeCasas, quantidadeOpcoes, 1, quantidadeLinhas)
end


-- ============================================================================
--[[ Verdade seja dita, eu cheguei perto de conseguir alcançar o algoritmo, mas acabei buscando auxílio
    do GPT para conseguir implementar a recursão. 

    A permutação com laços hardcoded foi alcançada apenas praticando e buscando uma solução, porém eu tive
    muita dificuldade na transmutação para a lógica recursiva dinâmica de processamento.

    Exeplo abaixo usando laços estáticos no código, versão para gerador de 2 casas:

    ----------------------------------------------------------------------------------------------
    //                                                                                          //
    for i=1, options, 1 do                      -- laço inicial
        saida[1] = spin(i)
        for j=1, options, 1 do                  -- cada casa a mais na string abre um novo laço for que itera por tudo

                                                -- Toda a sequencia de linhas abaixo deve estar presente no laço mais interno
            if(WordCounter > limite) then       -- verificador do limite de strings, deve estar presente no ultimo laço
                return                          --
            end                                 -- 
                                                --
            saida[2] = spin(j)                  -- iteração da casa
                                                --
            print(table.concat(saida))          -- printa cada combinação possível
            WordCounter = WordCounter + 1       -- incrementa o contator de strings geradas

        end
    end                                         -- a regra de saída do loop é: quando saida[x], onde x = casas, então é o ultimo laço
    //                                                                                          //
    ----------------------------------------------------------------------------------------------

    Ainda assim serão necessários alguns ajustes no código para comportar o contador de linhas e limite de
    linhas a serem geradas por exemplo
]]
-- ============================================================================


-- ============================================================================
--[[ No final das contas a função core apenas comporta as variáveis de configuração, enqaunto spin é só um 
    distribuidor controlado externamente, e a lógica de recursão fica dentro de word. principalemnte aqui no
    Lua com seus recursos mais limitados de passagem de ponteiro e etc.

    Acontece que a grande mudança no algoritmo, qual eu ainda não tenha solucionado, que a IA me passou, foi 
    a implementação de um contador de posição, para só printar cada pavra depois de correr ela toda recursivamente,
    além do posicionamento correto dos blocos de codigo pra tornar a permutação 100% funcional igual estava a 
    hardcoded - eu estava conseguindo roletar apenas 1 casa por vez, gerando algo como {a, b, c, d, ad, bd, cd, bd}
    ,onde as casas passadas travavam em "d" e as acas ainda não acessadas a esquerda ficavam em branco.

    Agora a lógica está concluida, foi usado um poco de IA sim, mas agora vamos passar isso para o C++ sem udo de IA.
]]
-- ============================================================================

core()