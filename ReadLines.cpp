#include "ReadLines.h"

ReadLines::ReadLines()
{
	
}
std::string* ReadLines::gLines(unsigned int i)
{
	if(i<m_lines.size())
		return &m_lines[i];
	else
		return nullptr; //Se retorna nullptr si se excede el limite de la cantidad de lineas.
}
//La linea corresponde a una sola cadena de texto, para luego utilizarse para lo que sea necesario;
bool ReadLines::lineRead(std::string line)
{
	//Aca iria algun metodo de control
	if(line.size()!=0)
	{
		m_lines.push_back(line);
		return true;
	}else
	{
		return false;
	}
}
ReadLines::~ReadLines()
{
	
}
