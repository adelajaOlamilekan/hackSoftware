///THIS FILE CONTAINS THE DECLARATION OF SYMBOL TABLE CLASS.

/// METADATA      |    VALUE
///-----------------------------------
///PROGRAMMER     |   QOWIYYU ADELAJA
///DATE STARTED   |   4 JAN 2021
///TIME STARTED   |   2:54 AM

#ifndef SYMBOLTABLE_H_INCLUDED
#define SYMBOLTABLE_H_INCLUDED
#endif // SYMBOLTABLE_H_INCLUDED

#include<string>
#include<vector>

template <typename nameType, typename valueType>
class Table
{
protected:
	void readSymbolFile(const std::string&);
	std::vector<nameType>symbolName;
    std::vector<valueType>symbolValue;
public:
    valueType getSymbolValue(nameType);
};

template <typename nameType, typename valueType>
valueType Table<nameType, valueType>::getSymbolValue(nameType name)
{
    const int tableSize = symbolName.size();

    for(int i = 0; i < tableSize; ++i)
        if(symbolName[i] == name)
            return symbolValue[i];
}

class SymbolTable : public Table<std::string, int>
{
public:
    SymbolTable();
    void storeSymbol(std::string, int);
	bool checkSymbol(std::string);
};

class ComputationTable : public Table<std::string, std::string>
{
public:
    ComputationTable();
};

class JumpTable : public Table<std::string, std::string>
{
public:
    JumpTable();
};

class DestinationTable : public Table<std::string, std::string>
{
public:
    DestinationTable();
};
