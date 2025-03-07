#ifndef LINESMANIP_H
#define LINESMANIP_H

#include <stdexcept>
#include <fstream>
#include <iostream>
#include <vector>

class linesManip {
public:
	linesManip() = default;
	linesManip(std::string s,bool n_file);
	std::string* gLines(unsigned int i); 
	[[nodiscard]] bool lineRead(std::string line); //Se puede utilizar ignorando el retorno
	void saveLines();
	int numofLines()const;
	~linesManip();
private:
	std::vector<std::string> m_lines;
	std::string m_fileName;
};

#endif

