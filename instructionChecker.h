#ifndef INSTRUCTIONCHECKER_H
#define INSTRUCTIONCHECKER_H

#include <string>
#include <fstream>
#include <stdexcept>

class instructionChecker {
public:
	instructionChecker();
	int checkKeywords(std::string s);
	int checkInputFormat(std::string s);
private:
};

#endif

