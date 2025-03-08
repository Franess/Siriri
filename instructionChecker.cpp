#include "instructionChecker.h"

instructionChecker::instructionChecker() {
	std::fstream f("listadoPalabrasClave.txt",std::ios::in);
	if(!f.is_open()) throw std::runtime_error("No se pudo abrir el archivo: ListadoPalabrasClave.txt");
	std::string aux_s;
	while(getline(f,aux_s))
	{
		m_keywordsVec.push_back(aux_s);
	}
	f.close();
}
int instructionChecker::checkKeywords(std::string s)
{
	auto keyw_it = std::find(m_keywordsVec.begin(),m_keywordsVec.end(),s);
	if(keyw_it==m_keywordsVec.end())
	{
		return 0;
	}
	return 1;
}
int instructionChecker::checkInputFormat(std::string s)
{
	return 1;
}
std::string* instructionChecker::gKeyword(int i)
{
	if(i<this->numofKeywords())
	{
		return &m_keywordsVec[i];
	}else
	{
		return nullptr;
	}
}
int instructionChecker::numofKeywords()const
{
	return m_keywordsVec.size();
}
