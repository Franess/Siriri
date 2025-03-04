#ifndef READLINES_H
#define READLINES_H

#include <iostream>
#include <vector>

class ReadLines {
public:
	ReadLines();
	std::string* gLines(unsigned int i); 
	[[nodiscard]] bool lineRead(std::string line); //Se puede utilizar ignorando el retorno
	~ReadLines();
private:
	std::vector<std::string> m_lines;
};

#endif

