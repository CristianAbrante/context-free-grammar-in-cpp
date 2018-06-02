
// Práctica 6: Computabilidad y algoritmia.
// Cristian Abrante Dorta.

#include "./CFG/CFG.hpp"               // Inclusión de la clase State.
// #include "./CFG/CFG.cpp"
// #include "./Alphabet/Alphabet.hpp"
// #include "./Alphabet/Alphabet.cpp"
// #include "./Production/Production.hpp"
// #include "./Production/Production.cpp"

#include <cstdio>
#include <cstdlib>

int main (int argc, char* argv[])
{
    
    if (argc == 3)
    {
        string str(argv[1]);
        bool openingFault;
        
        ofstream out;
        out.open(argv[2]);
        
        CFG newGrammar(str, openingFault);
        
        if(!openingFault)
        {
            newGrammar.minimizeGrammar();
            cout << newGrammar;
        }
    }
}