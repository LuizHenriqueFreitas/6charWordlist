#include "spin.hpp"
#include "charset.cpp"

Spin::Spin(){}

void Spin::SpinSet(std::string&output, int n, int &counter){
    
    if(counter == 0)
    {
        for(int i = 0; i < n; i++)
        {
            output += charset[counter];
        }
        counter++;
    } else if(counter > 0 && counter < n)
    {
        for(int i=0; i< n; i++)
        {
            if(i == n-1){
                output += charset[counter-1];
                SpinSet(output, n, counter);
            } else {
                output += charset[counter];
            }
        }
        counter++;
    }
}