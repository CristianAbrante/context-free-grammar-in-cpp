
// Prática 7: Computabilidad y algoritmia

#pragma once

// Inclusión de las diversas librerias necesarias.

#include <cstdio>
#include <set>
#include <iostream>

using namespace std;
    
/**	
    \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
    \date       Noviembre de 2016
    
    \details    Clase que representa a un alfabeto o conjunto de símbolos terminales.
    
*/
    
class Alphabet
{
    
    //ATRIBUTOS PÚBLICOS.
    public:
        
        /** Atributo que representa a un conjunto de símbolos. */
        set<char>   symbols;
    
    // MÉTODOS PÚBLICOS.
    public:
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details   Constructor por defecto de la clase.
            
        */
        
        Alphabet (void);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details   Destructor de la clase.
            
        */
        
        ~Alphabet(void);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details   Constructor al que se le pasa una string de símbolos.
            
            @param  userAlphabet String que contiene todos los símbolos del alfabeto.
            
        */
        
        Alphabet (string userAlphabet, bool& creatingFault);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details   Constructor de copia de la clase.
            
        */
        
        Alphabet (const Alphabet& newAlphabet);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Sobrecarga del operador << que muestra el alfabeto por un flujo de salida.
            
        */
        
        friend ostream& operator<< (ostream& os, const Alphabet& rhs);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Sobrecarga del operador == que compara si dos alfabetos son iguales.
            
        */
        
        bool operator== (const Alphabet& rhs) const;
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details   Método que devuelve el número de elementos del alfabeto.
            
            @return     Número de elementos del alfabeto.
            
        */
        
        int size (void) const;
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Método que limpia el alfabeto.
            
        */
        
        void clear (void);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details   Método que devuelve el número de elementos del alfabeto.
            
            @param     token Nuevo símbolo que se insertará al alfabeto.
            
        */
        
        void insert (const char& token);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Método que devuelve el símbolo que se encuentra en una posción determinada.
            
            @param      pos Posición del símbolo que se quiere comprobar.
            @return     Caracter del alfabeto que se encuentra en dicha posición.
            
        */
        
        char getSymbol (int pos) const;
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Método que determina si una cadena tiene todos los símbolos en el alfabeto.
            
            @param      languageString String que queremos comprobar.
            @return     TRUE si la cadena tiene todos sus símbolos en el alfabeto. FALSE en otro caso.
            
        */
        
        bool stringIsAMemberOfTheAlphabet (const string& languageString) const;
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Método que determina si un símbolo está en le alfabeto.
            
            @param      token   Símbolo que queremos comprobar si está en el alfabeto.
            @return     TRUE si está en el alfabeto. FALSE en otro caso.
            
        */
        
        bool symbolIsInTheAlphabet(const char& token) const;
        
        ostream& printCharacters (ostream& os, const char& initialCharacter) const;
        
        ostream& printCharacters (ostream& os) const;
        
    // MÉTODOS PRIVADOS.
    private:
        
        /** Método que crea el alfabeto. */
        void createAlphabet(string userAlphabet, bool& creatingFault);
        
        /** Método que devuelve si un token es un símbolo legal. */
        bool legal (const char& token) const;
};