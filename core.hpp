#ifndef CORE_HPP
#define CORE_HPP

// esse é o nucleo de processamento de permutação, base do mecanismo deste sistema
#include <iostream>
#include <fstream>
#include "charset.cpp"

class Core 
{
private:
    std::ofstream WordlistFile;
public:
    Core();
    bool GenerateWordlist();
};

#endif