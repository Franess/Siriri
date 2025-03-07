#include "linesManip.h"
#include "auxTools.h"
 

linesManip::linesManip(std::string s, bool n_file):m_fileName(s)
{
	std::fstream f;
	if(n_file)
	{
		f.open(s,std::ios::out|std::ios::trunc);
	}else
	{
		f.open(s,std::ios::in);
		if(!f.is_open()) throw std::runtime_error("No se pudo abrir el archivo\t"+s);
	}
	f.close();
}
std::string* linesManip::gLines(unsigned int i)
{
	if(i<m_lines.size())
		return &m_lines[i];
	else 
		return nullptr; //Se retorna nullptr si se excede el limite de la cantidad de lineas.
}
//La linea corresponde a una sola cadena de texto, para luego utilizarse para lo que sea necesario;
bool linesManip::lineRead(std::string line)
{
	if(line.size()!=0)
	{
		m_lines.push_back(line);
		return true;
	}else
	{
		return false;
	}
}
int linesManip::numofLines()const
{
	return m_lines.size();
}
void linesManip::saveLines()
{
	std::fstream f(m_fileName,std::ios::out|std::ios::trunc);
	if(!f.is_open()) throw std::runtime_error("No se pudo abrir el archivo");
	for(std::string &x:m_lines) f<<x<<std::endl;
	f.close();
}
linesManip::~linesManip()
{
	
}
