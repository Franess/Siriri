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
		return instructionError::ERROR_CODE;
	}
	return instructionError::SUCCESS_CODE;
}
int instructionChecker::checkInputFormat(std::string s,int chk_case)
{
	switch(chk_case)
	{
	case 0:
		if(s.size()==0) return instructionError::EMPTY_PARAM;
		break;
	case 1:
		if(s.size()>32) return instructionError::OVERSIZEPARAM_ERROR;
		break;
	default:
		break;
	}
	return instructionError::SUCCESS_CODE;
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
