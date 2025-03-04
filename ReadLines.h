#ifndef READLINES_H
#define READLINES_H

#include <iostream>
#include <vector>

class ReadLines {
public:
	ReadLines();
	std::string* gLines(unsigned int i); 
	void lineRead(std::string line);
	~ReadLines();
private:
	std::vector<std::string> m_lines;
};

#endif

