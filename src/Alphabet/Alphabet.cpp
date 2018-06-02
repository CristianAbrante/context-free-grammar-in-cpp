
    // Prática 7: Computabilidad y algoritmia
    // Curso: Segundo
    // Alumno: Cristian Abrante Dorta

    // Definición de la clase Alphabet

#include "Alphabet.hpp"
    
    // MÉTODOS PÚBLICOS.
    
    Alphabet:: Alphabet (void):
    symbols(){}
    
    Alphabet:: ~Alphabet (void)
    {
        clear();
    }
    
    Alphabet:: Alphabet (string userAlphabet, bool& creatingFault)
    {
        createAlphabet(userAlphabet, creatingFault);
    }
    
    Alphabet:: Alphabet (const Alphabet& newAlphabet)
    {
        symbols = newAlphabet.symbols;
    }
    
    ostream& operator<< (ostream& os, const Alphabet& rhs)
    {
        
        for (int i=0; i<rhs.size(); i++)
        {
            if (rhs.getSymbol(i)!='~')
                os << rhs.getSymbol(i);
            if (i!=(rhs.size()-1)) os << ", ";
        }
        
        os << "}";
        
        return os;
    }
    
    bool Alphabet:: operator== (const Alphabet& rhs) const
    {
        if (size()==rhs.size())
        {
            bool equal = true; int i=0;
            
            while ((i<size())&&equal)
            {
                if(getSymbol(i)!=rhs.getSymbol(i)) equal = false;
                else i++;
            }
            
            return equal;
        }
        else return false;
    }
    
    int Alphabet:: size (void) const
    {
        return symbols.size();
    }
    
    void Alphabet:: clear(void)
    {
        symbols.clear();
    }
    
    void Alphabet:: insert (const char& token)
    {
        if (legal(token))
            symbols.insert(token);
    }
    
    char Alphabet:: getSymbol (int pos) const
    {
        if (pos < size())
        {
            int i = 0; 
            char result;
            bool found = false;
            set<char>:: iterator it = symbols.begin();
            
            while ((it!=symbols.end()) && !found)
            {
                if (pos == i) {result = *it; found = true;}
                else { it++; i++; }
            }
            
            return result;
        }
        else
        {
            return -1;
        }
    }
    
    bool Alphabet:: stringIsAMemberOfTheAlphabet (const string& languageString) const
    {
        
        if (languageString == "~") return true;
        
        bool correct = true; int i=0;
        
        while ((i<languageString.size())&&correct)
        {
            if (!symbolIsInTheAlphabet(languageString[i])) correct = false;
            else i++;
        }
        
        return correct;
    }
    
    bool Alphabet:: symbolIsInTheAlphabet(const char& token) const
    {
        
        bool found = false; int i=0;
        
        while ((i<size())&&!found)
        {
            if (getSymbol(i) == token) found = true;
            else i++;
        }
        
        return found;
        
    }
    
    ostream& Alphabet:: printCharacters (ostream& os, const char& initialCharacter) const
    {
        os << initialCharacter << " ";
        for (int i=0; i<size(); i++)
        {
            if (getSymbol(i)!=initialCharacter)
            {
                os << getSymbol(i);
                if(i!=size()-1) os << " ";
            }
        }
        
        return os;
    }
    
    ostream& Alphabet:: printCharacters (ostream& os) const
    {
        for (int i=0; i<size(); i++)
        {
            os << getSymbol(i);
            if(i!=size()-1) os << " ";
        }
        
        return os;
    }
    
    // MÉTODOS PRIVADOS.
    
    void Alphabet:: createAlphabet(string userAlphabet, bool& creatingFault)
    {
        clear();
        
        creatingFault = false;
        int i = 0;
        
        while ((i<userAlphabet.size())&&!creatingFault)
        {
            if (legal(userAlphabet[i])) { symbols.insert(userAlphabet[i]); i++; }
            else creatingFault = true;
        }
    }
    
    bool Alphabet:: legal (const char& token) const
    {
        return ((token!='~')&&(token!='{')&&(token!='}')&&(token!=' ')&&(token!=','));
    }
    
