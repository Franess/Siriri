#include "instructionChecker.h"

instructionChecker::instructionChecker() {
	std::fstream f("listadoPalabrasClave.txt");
	if(!f.is_open()) throw std::runtime_error("No se pudo abrir el archivo: ListadoPalabrasClave.txt");
	
}
int instructionChecker::checkKeywords(std::string s)
{
	int chk_code;
	return chk_code;
}
int instructionChecker::checkInputFormat(std::string s)
{
	int chk_code;
	return chk_code;
}
