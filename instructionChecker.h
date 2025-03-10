#ifndef INSTRUCTIONCHECKER_H
#define INSTRUCTIONCHECKER_H

#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <algorithm>
//El enum TOTAL_CODES se utiliza para determinar la cantidad de codigos. la enumeracion comienza con el elemento "0"
//Por ej en bucle for(unsigned int i=0;i<instructionError::TOTAL_CODES;++i)
//Se ejecutara la cantidad de codigos existentes

enum instructionError
{
	ERROR_CODE,SUCCESS_CODE,EMPTY_PARAM,OVERSIZEPARAM_ERROR,TOTAL_CODES
};

class instructionChecker {
public:
	instructionChecker();
	int checkKeywords(std::string s);
	int checkInputFormat(std::string s,int chk_case);
	std::string* gKeyword(int i);
	int numofKeywords()const;
private:
	std::vector<std::string> m_keywordsVec;
};

#endif

