### Gerador de Wordlist 

Wordlists são grandes arquivos txt com muitos, centenas de milhares de strings,   
 que podem ser usados em ferramentas de brute force para tentar quebrar siste-    
 mas de segurança.

Uma senha simples de 6 caracteres com letras maiúsculas e minúsculas, numerais   
e alguns cacteres especiais, podemos supor que cada uma das 6 posições possam    
permutar entre 80 opções, fazendo esse calculo, chega-se a conclusão final de    
que teremos um pouco mais de 262 bilhões de combinações, considerando que cada    
string teria então 6 bytes(supondo que as 80 opções todas estejam dentro da    
tabela ASCII) + 1 byte da quebra de linha, que é necessária para as ferramentas    
de brute force, podemos concluir então que um arquivo .txt para armazenar essa   
wordlist teria algo próximo a 2 Teras de tamanho (espaço que eu não tenho atu-   
almente no meu PC).

O objetivo deste projeto é programar um gerador eficiente de wordlist partindo     
dessa premissa de permutação, gravação e manipulação de arquivos, combinações e    
funções com recursividade de cauda visando maior desempenho nesse sistema.