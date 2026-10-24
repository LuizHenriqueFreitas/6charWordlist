#include "core.hpp"
#include "spin.hpp"
#include <iostream>
#include <fstream>

Core::Core(){}

bool Core::GenerateWordlist()
{    
    Spin spin = Spin();
    WordlistFile.open("wordlist.txt");

    if (!WordlistFile.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo.\n";
        return false;
    }

    int size = 6;
    int numberOfStrings = 6;

    for(int i =0; i < numberOfStrings; i++)
    {
        std::string string;
        std::string* ptrOutput = & string;

        for(int j=0; j < size; j++)
        {
            int counter = 0;
            int* ptrCounter = &counter;
            spin.SpinSet(*ptrOutput, size, *ptrCounter);
        }

        WordlistFile << string << '\n';
    }
    WordlistFile.close();
    return true;
}