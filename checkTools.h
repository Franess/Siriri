#ifndef CHECKTOOLS_H
#define CHECKTOOLS_H

#define  SUCCESS_CODE 1

#include <algorithm>
#include <string>
#include <vector>

//Funciones para el control de la instruccion o manipulacion de strings
int checkKeyWords(const std::vector<std::string> &line_vec); 
int lineSplitter(std::string s, std::vector<std::string> &v);
int rstrCheckline(std::string s);

#endif
