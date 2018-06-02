// Prática 7: Computabilidad y algoritmia

#pragma once

// Inclusión de las diversas librerias necesarias.

#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
    
/**	
    \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
    \date       Noviembre de 2016
    
    \details    Clase que simula una producción.
    
*/
    
class Production
{
    
    // ATRIBUTOS PÚBLICOS.
    public:
        
        /** Atributo que representa el símbolo de la izquierda de la producción. */
        char        leftCharacter;
        string      rightCharacters;
        
    // MÉTODOS PÚBLICOS.
    public:
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Constructor por defecto de la clase.
             
        */
        
        Production (void);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Constructor con parámetros.
            
            @param      leftCharacter       Símbolo no terminal de la producción
            @param      rightCharacters     Conjunto de símbolos de la producción.
             
        */
        
        Production (const char& newLeftCharacter, const string& newRightCharacters);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Método que actualiza la producción.
             
        */
        
        void updateProduction (const char& newLeftCharacter, const string& newRightCharacters);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Sobrecarga del operador == que permite comparar la igualdad entre dos producciones.
             
        */
        
        bool operator== (const Production& rhs) const;
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Sobrecarga del operador < que permite comparar si una producción es menor que otra.
             
        */
        
        bool operator< (const Production& rhs) const;
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Sobrecarga del operador << que permite enviar la producción a través de un flujo.
            
            @param      os  flujo a traves del cual se quiere enviar la gramática.
             
        */
        
        friend ostream& operator<< (ostream& os, const Production& rhs);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Sobrecarga del operador = que permite igualar dos producciones.
            
            @param      os  flujo a traves del cual se quiere enviar la gramática.
             
        */
        
        Production& operator= (const Production& rhs);
};