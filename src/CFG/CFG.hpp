// Prática 7: Computabilidad y algoritmia

#pragma once

#include "../Alphabet/Alphabet.hpp"
#include "../Production/Production.hpp"

// Inclusión de las diversas librerias necesarias.

#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>


using namespace std;
    
/**	
    \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
    \date       Noviembre de 2016
    
    \details    Clase que simula una gramática independiente del contexto.
    
*/
    
class CFG
{
    //ATRIBUTOS PRIVADOS
    private:
    
        /** Atributo que representa al conjunto de símbolos terminales. */
        Alphabet        terminalCharacters;
        /** Atributo que representa al conjunto de símbolos no terminales. */
        Alphabet        nonTerminalCharacters;
        /** Atributo que representa al símbolo de arranque. */
        char            initialCharacter;
        /** Atributo que representa al conjunto de producciones. */
        set<Production> productions;
        
    public:
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Constructor por defecto de la clase.
             
        */
        
        CFG (void);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Constructor con parámetros.
            
            @param      CFGDefinition   Fichero que contiene la definición de la gramática.
            @param      openingFault    Variable que determina si ha habido error al crear la gramática.
            @return     openingFault=TRUE si hay error openingFault=FALSE en otro caso.
             
        */
        
        CFG (const string& CFGDefinition, bool& openingFault);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Método que limpia la gramática.
             
        */
        
        void clear (void);
        
        friend ostream& operator<< (ostream& os, const CFG& rhs);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Método que minimiza la gramática.
            
        */
        
        void minimizeGrammar (void);
        
    // MÉTODOS PRIVADOS.
    private:
        
        /** Método que crea la Gramática desde una entrada */
        istream& createCFG (istream& is, bool& openingFault);
        
        /** Método que devuelve el número de producciones con un determinado símbolo. */
        int getNumberOfProductions (const char& symbol) const;
        
        /** Método que devuelve la parte izquierda de una producción
        dado un símbolo no terminal y una posición. */
        Production getProduction (const int& pos) const;
        
    // Métodos que minimizan la gramática.
        
        /** Eliminar las variables desde las que no se puede derivar una cadena
        del lenguaje universal y las producciones en las que aparezcan dichas variables. */
        void eraseUselessProductions1 (void);
        
        /** Método que devuelve todas las producciones que deriven una cadena de terminales. */
        set<char> productionsWhithATerminalString (void) const;
        
        /** Método que nos devuelve si todos los símbolos terminales estan en el conjunto V */
        bool allTerminalsAreIntheSet (const set<char>& V, const string& charactersString) const;
        
        /** Método que borra las producciones en las que aparezca un determinado símbolo. */
        void eraseProductionsWhithTheCharacater (const char& symbol);
        
        /** Eliminar todos los no terminales de V que no estén en V ′ y todos los terminales
        que no estén en el lenguaje universal. */
        void eraseUselessProductions2 (void);
        
};