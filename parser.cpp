///THIS FILE CONTAINS THE DECLARATION OF SYMBOL TABLE CLASS.

/// METADATA      |    VALUE
///-----------------------------------
///PROGRAMMER     |   QOWIYYU ADELAJA
///DATE STARTED   |   12 JAN 2021
///TIME STARTED   |   12:26 AM

#include "parser.h"

InstructionField Parser::parse(const std::string& assemblyCode)
{
	bool foundEqual = false;		 bool foundSemicolon = false;
    const char ampersand = '@'; 	 const char equalSign = '='; 		const char semicolon = ';';
    const char squareBracket = '[';  const char parentheses = '(';	 	const char firstCharacter = assemblyCode[0];
	const unsigned secondCharacterPosition = 1;							const unsigned firstCharacterPosition = 0;
    unsigned equalPosition = 0;		 unsigned semicolonPosition = 0;	const unsigned lastCharacterPosition = assemblyCode.size() - 1;
    std::string symbol,address,destination,computation,jump;

    ///Parsing A-instruction
    if(firstCharacter == ampersand )
            address = getSubString(assemblyCode, secondCharacterPosition, lastCharacterPosition);
	///Parsing Variable
    else if(firstCharacter == squareBracket)
            symbol = getSubString(assemblyCode, secondCharacterPosition, lastCharacterPosition-1);
	///Parsing Label
    else if(firstCharacter == parentheses)
			symbol = getSubString(assemblyCode, secondCharacterPosition, lastCharacterPosition-1);
     ///Parsing C-instruction
    else{
        ///Searching for existence of semicolon or equal-to sign
		equalPosition = assemblyCode.find(equalSign);
            if(equalPosition != std::string::npos)
                foundEqual = true;

        semicolonPosition = assemblyCode.find(semicolon);
			if(semicolonPosition != std::string::npos)
				foundSemicolon = true;

        if(foundEqual == true && foundSemicolon == true){
                destination = getSubString(assemblyCode, firstCharacterPosition, equalPosition-1);
                computation = getSubString(assemblyCode, equalPosition+1, semicolonPosition-1);
                jump = getSubString(assemblyCode, semicolonPosition+1, lastCharacterPosition);
        }
        else if(foundSemicolon == true && foundEqual == false){
                computation = getSubString(assemblyCode, firstCharacterPosition, semicolonPosition-1);
                jump = getSubString(assemblyCode, semicolonPosition+1, lastCharacterPosition);
        }
    }

return InstructionField{symbol,address,destination,computation,jump};
}

std::string Parser::getSubString(const std::string& originalText, unsigned beginPosition, unsigned endPosition)
{
	std::string subString;

	for(unsigned i = beginPosition; i <= endPosition; ++i)
			subString += originalText[i];

return subString;
}
