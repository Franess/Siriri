#ifndef INSTRUCTIONCHECKER_H
#define INSTRUCTIONCHECKER_H

#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

enum instructionError
{
	ERROR_CODE,SUCCESS_CODE
};

class instructionChecker {
public:
	instructionChecker();
	int checkKeywords(std::string s);
	int checkInputFormat(std::string s);
	std::string* gKeyword(int i);
	int numofKeywords()const;
private:
	std::vector<std::string> m_keywordsVec;
};

#endif

