///THIS FILE CONTAINS THE DECLARATION OF SYMBOL TABLE CLASS.

/// METADATA      |    VALUE
///-----------------------------------
///PROGRAMMER     |   QOWIYYU ADELAJA
///DATE STARTED   |   12 JAN 2021
///TIME STARTED   |   12:19 AM

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#endif // PARSER_H_INCLUDED

#include<string>

///This structure holds the Assembly-Instruction Fields
struct InstructionField
{
    std::string symbol;
    std::string register_address;
    std::string destination;
    std::string computation;
    std::string jump;
};

class Parser
{
public:
    InstructionField parse(const std::string&);
private:
	std::string getSubString(const std::string&, unsigned, unsigned);
};
