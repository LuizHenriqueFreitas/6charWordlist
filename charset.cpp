#pragma once
// aqui esta o charset de caracteres que serão permutados entre si

// foram escolhidos 80 caracteres, 26 letras do alfabeto, maiúsculas e 
// minúsculas + 10 numerais (de 0 a 9) e 14 carcteres especias (,!,@,#,$,%,¨,&,*,+,=,<,>,);  

const char charset[80] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '<', '>', '+', '=', '-', '/', '\'', '~' 
};