    // Prática 7: Computabilidad y algoritmia
    // Curso: Segundo
    // Alumno: Cristian Abrante Dorta

    // Implementación de la clase Production
    
#include "Production.hpp"
    
    // MÉTODOS PÚBLICOS
    
    Production:: Production (void):
    leftCharacter(),
    rightCharacters(){}
    
    Production:: Production (const char& newLeftCharacter, const string& newRightCharacters):
    rightCharacters(rightCharacters)
    {
        leftCharacter = newLeftCharacter;
    }
    
    void Production:: updateProduction (const char& newLeftCharacter, const string& newRightCharacters)
    {
        leftCharacter = newLeftCharacter;
        rightCharacters = newRightCharacters;
    }
    
    bool Production:: operator== (const Production& rhs) const
    {
        if((leftCharacter==rhs.leftCharacter)&&(rightCharacters==rhs.rightCharacters)) return true;
        else return false;
    }
    
    bool Production:: operator< (const Production& rhs) const
    {
        if (leftCharacter!=rhs.leftCharacter)
        {
            if(leftCharacter<rhs.leftCharacter) return true;
            else return false;
        }
        else
        {
            if(rightCharacters<rhs.rightCharacters) return true;
            else return false;
        }
    }
    
    ostream& operator<< (ostream& os, const Production& rhs)
    {
        os << rhs.rightCharacters;
        return os;
    }
    
    Production& Production:: operator= (const Production& rhs)
    {
        this->leftCharacter = rhs.leftCharacter;
        this->rightCharacters = rhs.rightCharacters;
        
        return *this;
    }