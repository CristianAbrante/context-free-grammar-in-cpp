    // Prática 7: Computabilidad y algoritmia
    // Curso: Segundo
    // Alumno: Cristian Abrante Dorta

    // Definición de la clase CFG
    
#include "CFG.hpp"
    
    // MÉTODOS PÚBLICOS
    
    CFG:: CFG (void):
    terminalCharacters(),
    nonTerminalCharacters(),
    initialCharacter(),
    productions(){}
    
    CFG:: CFG (const string& CFGDefinition, bool& openingFault):
    terminalCharacters(),
    nonTerminalCharacters(),
    initialCharacter(),
    productions()
    {
        ifstream CFGStream;
        CFGStream.open(CFGDefinition);
        
        if (CFGStream.is_open())
        {
            createCFG(CFGStream, openingFault);
        }
        else openingFault = true;
    }
    
    void CFG:: clear (void)
    {
        terminalCharacters.clear();
        nonTerminalCharacters.clear();
        initialCharacter = 0;
        productions.clear();
    }
    
    ostream& operator<< (ostream& os, const CFG& rhs)
    {
        os << rhs.terminalCharacters.size()     << endl;
        rhs.terminalCharacters.printCharacters(os);
        os << endl;
        
        os << rhs.nonTerminalCharacters.size()  << endl;
        rhs.nonTerminalCharacters.printCharacters(os,rhs.initialCharacter);
        os << endl;
        
        int k=0;
        
        int numberOfProductions = rhs.getNumberOfProductions(rhs.initialCharacter);
        
        if (numberOfProductions!=0)
        {
            os << rhs.initialCharacter << " -> ";
                
            for (int j=0; j<rhs.productions.size(); j++)
            {
                if (rhs.getProduction(j).leftCharacter == rhs.initialCharacter)
                {
                    os << rhs.getProduction(j);
                    if (k!=(numberOfProductions-1)) os << " | ";
                    k++;
                }
            }
            
            os << endl;
        }
        
        for(int i=0; i<rhs.nonTerminalCharacters.size(); i++)
        {
            if (rhs.nonTerminalCharacters.getSymbol(i)!=rhs.initialCharacter)
            {
                int numberOfProductions = rhs.getNumberOfProductions(rhs.nonTerminalCharacters.getSymbol(i));
                
                if (numberOfProductions!=0)
                {
                    k=0;
                    os << rhs.nonTerminalCharacters.getSymbol(i) << " -> ";
                    
                    for (int j=0; j<rhs.productions.size(); j++)
                    {
                        if (rhs.getProduction(j).leftCharacter == rhs.nonTerminalCharacters.getSymbol(i))
                        {
                            os << rhs.getProduction(j);
                            if (k!=(numberOfProductions-1)) os << " | ";
                            k++;
                        }
                    }
                    os << endl;
                }
            }
        }
        
        return os;
    }
    
    void CFG:: minimizeGrammar (void)
    {
        eraseUselessProductions1();
        cout << *this << endl;
        eraseUselessProductions2();
    }
    
    // MÉTODOS PRIVADOS.
    
    istream& CFG:: createCFG (istream& is, bool& openingFault)
    {
        clear();
        
        int numberOfTerminalCharacters;
        int numberOfNonTerminalCharacters;
        Production tmpProduction;
        char tmpChar;
        
        is >> numberOfTerminalCharacters;
        
        for (int i=0; i<numberOfTerminalCharacters; i++)
        {
            is >> tmpChar;
            terminalCharacters.insert(tmpChar);
        }
        
        is >> numberOfNonTerminalCharacters;
        
        for (int i=0; i<numberOfNonTerminalCharacters; i++)
        {
            is >> tmpChar;
            if (i==0) initialCharacter = tmpChar;
            nonTerminalCharacters.insert(tmpChar);
        }
        
        is.ignore(1);
        
        for (int i=0; i<numberOfNonTerminalCharacters; i++)
        {
            char c[200];
            is.getline(c, 200);
            
            string tmpString(c);
            tmpString.erase(remove(tmpString.begin(),tmpString.end(),' '), tmpString.end());
            tmpString.erase(remove(tmpString.begin(),tmpString.end(),'-'), tmpString.end());
            tmpString.erase(remove(tmpString.begin(),tmpString.end(),'>'), tmpString.end());
            
            if (!tmpString.empty())
            {
                
                string  productionString;
                tmpChar = tmpString[0];
                
                
                    for (int i=1; i<tmpString.size(); i++)
                    {
                        if (tmpString[i]!='|')
                        {
                            productionString.push_back(tmpString[i]);
                        }
                        if ((tmpString[i]=='|')||(i==tmpString.size()-1))
                        {
                            
                            tmpProduction.updateProduction(tmpChar, productionString);
                            productions.insert(tmpProduction);
                            productionString.clear();
                        }
                    }
            }
        }
        
        
        return is;
    }
    
    int CFG:: getNumberOfProductions (const char& symbol) const
    {
        int size = 0;
        set<Production>::iterator it = productions.begin();
        
        for (;it!=productions.end(); it++)
        {
            if ((*it).leftCharacter == symbol) size++;
        }
        
        return size;
    }
    
    Production CFG:: getProduction (const int& pos) const
    {
        int i = 0;
        bool found = false;
        Production result;
        
        set<Production>::iterator it = productions.begin();
        
        while ((it!=productions.end())&&!found)
        {
            if (i==pos) 
            {
                result = (*it); found=true;
            }
            else { i++; it++;}
        }
        
        return result;
    }
    
    // Métodos que minimizan la gramática.
    
    void CFG:: eraseUselessProductions1 (void)
    {
        set<char>       finalNonTerminalCharacters;
        
        finalNonTerminalCharacters = productionsWhithATerminalString();
        int tmpSize = finalNonTerminalCharacters.size();
        
        do
        {
            tmpSize = finalNonTerminalCharacters.size();
            
            for (int i=0; i<productions.size(); i++)
            {
                string tmpString = getProduction(i).rightCharacters;
                
                if (allTerminalsAreIntheSet(finalNonTerminalCharacters, tmpString))
                {
                    finalNonTerminalCharacters.insert(getProduction(i).leftCharacter);
                }
                
            }
            
        }while(finalNonTerminalCharacters.size()!=tmpSize);
        
        set<char> difference;
        
        set_difference(nonTerminalCharacters.symbols.begin(), nonTerminalCharacters.symbols.end(), 
        finalNonTerminalCharacters.begin(), finalNonTerminalCharacters.end(),
        inserter(difference, difference.begin()));
        
        nonTerminalCharacters.symbols = finalNonTerminalCharacters;
        
        set<char>::iterator it = difference.begin();
        
        for(;it!=difference.end(); it++)
        {
            eraseProductionsWhithTheCharacater(*it);
        }
        
    }
    
    set<char> CFG:: productionsWhithATerminalString (void) const
    {
        set<char>   result;
        
        for (int i=0; i<productions.size(); i++)
        {
            string possibleTerminalString = getProduction(i).rightCharacters;
            
            bool areTerminalCharacters = true; int j = 0;
            
            while ((j<possibleTerminalString.size())&&areTerminalCharacters)
            {
                
                if (!terminalCharacters.symbolIsInTheAlphabet(possibleTerminalString[j]))
                    areTerminalCharacters = false;
                else j++;
                
            }
            
            if (areTerminalCharacters) result.insert( getProduction(i).leftCharacter);
            
        }
        
        return result;
    }
    
    bool CFG:: allTerminalsAreIntheSet (const set<char>& V, const string& charactersString) const
    {
        bool result = true; int i = 0;
        
        while ((i<charactersString.size())&&result)
        {
            if (nonTerminalCharacters.symbolIsInTheAlphabet(charactersString[i]))
            {
                
                set<char>::iterator it = V.find(charactersString[i]);
                
                if (it==V.end())
                {
                    if (*(V.end())!=charactersString[i]) result = false;
                    else {i++;}
                }
                else i++;
            }
            else i++;
        }
        
        return result;
    }
    
    void CFG:: eraseProductionsWhithTheCharacater (const char& symbol)
    {
        for (int i=0; i<productions.size(); i++)
        {
            
            string tmpString = getProduction(i).rightCharacters;
            int j = 0; bool found = false;
            
            while((j<tmpString.size())&&!found)
            {
                if (tmpString[j]==symbol)
                {
                    found = true;
                    
                    productions.erase(getProduction(i));
                    
                }
                else j++;
            }
        }
    }
    
    void CFG:: eraseUselessProductions2 (void)
    {
        set<char>   J;
        set<char>   newV;
        Alphabet    newTerminalCharacters;
        
        J.insert(initialCharacter);
        newV.insert(initialCharacter);
        
        while(!J.empty())
        {
            char A = *J.begin(); J.erase(A);
            
            for (int i=0; i<productions.size(); i++)
            {
                if(getProduction(i).leftCharacter == A)
                {
                    string tmpString = getProduction(i).rightCharacters;
                    
                    for (int j=0; j<tmpString.size(); j++)
                    {
                        if(terminalCharacters.symbolIsInTheAlphabet(tmpString[j]))
                        {
                            newTerminalCharacters.insert(tmpString[j]);
                        }
                        else
                        {
                            string str; str.push_back(tmpString[j]);
                            
                            if(!allTerminalsAreIntheSet(newV, str))
                            {
                                J.insert(tmpString[j]);
                                newV.insert(tmpString[j]);
                            }
                        }
                    }
                    
                }
            }
            
        }
        
        
        set<char> difference;
        
        set_difference(nonTerminalCharacters.symbols.begin(), nonTerminalCharacters.symbols.end(), 
        newV.begin(), newV.end(), inserter(difference, difference.begin()));
        
        nonTerminalCharacters.symbols = newV;
        
        set_difference(terminalCharacters.symbols.begin(), terminalCharacters.symbols.end(), 
        newTerminalCharacters.symbols.begin(), newTerminalCharacters.symbols.end(),
        inserter(difference, difference.begin()));
        
        terminalCharacters.symbols = newTerminalCharacters.symbols;
        
        set<char>::iterator it = difference.begin();
        
        for(;it!=difference.end(); it++)
        {
            eraseProductionsWhithTheCharacater(*it);
        }
    }