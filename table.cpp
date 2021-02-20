///THIS FILE CONTAINS THE IMPLEMENTATION OF THE SYMBOL TABLE CLASS.

/// METADATA      |    VALUE
///-----------------------------------
///PROGRAMMER     |   QOWIYYU ADELAJA
///DATE STARTED   |   4 JAN 2021
///TIME STARTED   |   2:54 AM


#include "table.h"
#include<fstream>
#include<vector>
#include<iostream>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;

template <typename nameType, typename valueType>
void Table<nameType, valueType>::readSymbolFile(const string& fileName)
{
    ifstream fileReader(fileName);
    nameType name;
    valueType value;
    const string fileFailureMessage = "file not opened\n";

    if(fileReader.is_open())
        while(!fileReader.eof()){
            fileReader>>name;
            fileReader>>value;
            symbolName.push_back(name);
            symbolValue.push_back(value);
        }
    else
        cout<<fileFailureMessage;

    fileReader.close();

return;
}


//Constructor Fills the Symbol-Table with predefined symbols
SymbolTable::SymbolTable()
{
   const string fileName = "tables\\symbol table.txt";
    readSymbolFile(fileName);
}

void SymbolTable::storeSymbol(string name, int value)
{
    symbolName.push_back(name);
    symbolValue.push_back(value);

return;
}

bool SymbolTable::checkSymbol(string name)
{
    const int tableSize = symbolName.size();
    const bool found = true;

    {
        for(int i = 0; i < tableSize; ++i)
            if(symbolName[i] == name)
                return found;

                return !found;
    }
}


ComputationTable::ComputationTable()
{
    string filename = "tables\\computation table.txt";

    readSymbolFile(filename);
}


JumpTable::JumpTable()
{
    string filename = "tables\\jump table.txt";

    readSymbolFile(filename);
}


DestinationTable::DestinationTable()
{
    string filename = "tables\\destination table.txt";

    readSymbolFile(filename);
}
