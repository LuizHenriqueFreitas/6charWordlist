## Gerador de Wordlist 

Wordlists são grandes arquivos txt com muitos, centenas de milhares de strings, 
que podem ser usados em ferramentas de brute force para tentar quebrar sistemas 
de segurança.

Uma senha simples de 6 caracteres com letras maiúsculas e minúsculas, numerais 
e alguns cacteres especiais, podemos supor que cada uma das 6 posições possam 
permutar entre 80 opções, fazendo esse calculo, chega-se a conclusão final de 
que teremos um pouco mais de 262 bilhões de combinações, considerando que cada 
string teria então 6 bytes(supondo que as 80 opções todas estejam dentro da 
tabela ASCII) + 1 byte da quebra de linha, que é necessária para as ferramentas 
de brute force, podemos concluir então que um arquivo .txt para armazenar essa 
wordlist teria algo próximo a 2 Teras de tamanho (espaço que eu não tenho atualmente 
no meu PC).

O objetivo deste projeto é programar um gerador eficiente de wordlist partindo 
dessa premissa de permutação, gravação e manipulação de arquivos, combinações e 
funções com recursividade de cauda visando maior desempenho nesse sistema.

---

### Linguagens usadas
A ideia é usar C++ pra praticar a linguagem e gerar um binário fechado, o que 
não faz diferença nenhuma do ponto de vista de proteção do código até porque 
ele está público no github.

Lua foi adotada para desenvolvimento da lógica da permutação, uma vez que o C++ 
exige ser recompilado a cada alteração, poupando muito tempo de desenvolvimento 
visto a velocidade de testar e validar os scripts em lua.

---

### Documentação do projeto
Todos os scritps foram o mais comentados e documentados o possível. De acordo com os 
padrões de cada linguagem e a necessidade de cada arquivo para essa documentação.   

Caso queira entender melhor a estrutura do projeto, visite o arquivo "Architecture.md".

- **Lógica - Lua**   

Talvez fosse melhor deixar o texto documental do desenvolvimento da lógica 
em outro arquivo, como um txt, não no arquivo script.lua que foi usado pra desenvolver 
a lógica, porém decidi manter assim já que esse é apenas um projeto de estudo, assim 
é possivel entender o processo real de desenvolvimento do projetinho.

- **Sistema - C++**  

Todos os scripts do C++ foram projetados visando desacoplamento, arquivos separados de cabeçaho e 
implementação. Tudo está comentado, tanto para descrever o que as coisas fazem como também 
porque foram construídos como estão.

---

### Como Rodar

O sistema apresenta uma interface de terminal (CLI) em português, você pode usar o programa de maneira 
intuitiva usando apenas comandos com números inteiros, tanto para navegar entre opções como para informar 
valores de entrada. 

##### Compilar

Para compilar um executável em seu computador é necessário um compilador, como **gcc** ou **g++**, e usar a linha de comando 
na raiz do projeto, incluindo todos os arquivos .cpp, como o exemplo abaixo:  
- Windows:  
    
    g++ -Wall -Wextra -g main.cpp core.cpp word.cpp spin.cpp charset.cpp cli.cpp -o output.exe
- Linux:   
    g++ -Wall -Wextra -g main.cpp core.cpp word.cpp spin.cpp cli.cpp -o output/main

> Onde ***"output"*** será o nome do executável.

---

### Porque fazer um projeto como esse?

- **Meu Contexto**   
Esse projeto foi muito interessante para mim por alguns motivos. Para dar mais contexto, hoje quando estou fazendo as ultimas alterações nele, fazem 3 anos que estudo programação, e esse foi o primeiro projeto que fiz sozinho e que tem algum nivel relevante de complexidade.

- **Versionamento em Git**   
Não vou ocupar seu tempo com minha história no desenvolvimento de software, mas esse projeto foi uma das minhas primeiras vezes utilizando versionamento em git de maneira mais adequada - antiormente eu dava 1 commit muito espaçado do outro, sempre com "add ." em vez de adicionar apenas o que tem relação com alguma coisa e etc.

- **Estruturação com classes**   
Esse projeto foi importante para essa questão de começar a versionar melhor, também pela questão de estruturação de classes e funções, acredito que ainda desse pra melhorar mais, como colocando as funções auxiliares de PrintLine e GetInput em uma outra classe separada, porem, pelo escopo pequeno do projeto resolvi deixar assim mesmo.

- **Exercício lógico**   
E por fim, o exercício de tentar criar do zero o algoritmo de permutação combinatória, segundo o chat GPT esse algoritmo é tecnicamente chamado de: "**Algoritmo de Geração de Produto Cartesiano por Recursão**".  

    Como pode ser visto no arquivo de pensamento lógico em lua, uma parte do algoritmo foi solucionada organicamente sem recorrer a sites ou soluções prontas, conforme foram se passando alguns dias tentando chegar em alguma solução eu fui pedindo mais ajuda a LLMs como GTP, até que eu pedi para que ele indicasse o que tinha de ser feito, depois de uns 3 dias tentando diferentes alternativas.   

- **Uso de IA**  
Embora tenha existido assistencia de IA, como acabo de informar acima, assim como no arquivo .lua é descrito isso, essa foi vista como uma medida adequada, afinal esse projeto foi desenvolvido em cerca de 6 dias, ficar semanas travado tentando criar um algoritmo que já existe seria um exercicio intenressante, porem considero que seria bem menos proveitoso. Visto isso optei por tentar um tempo, mas não ficar preso a isso quando passe a se tornar um fardo.

    Além disso a IA só foi usada nesse momento de desenvolvimento da lógica de permutação para apontar erros e sugestões do que fazer para solucionar o problema.
