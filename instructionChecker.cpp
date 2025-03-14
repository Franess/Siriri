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
int instructionChecker::checkKeywords(std::string s) const
{
	auto keyw_it = std::find(m_keywordsVec.begin(),m_keywordsVec.end(),s);
	if(keyw_it==m_keywordsVec.end())
	{
		return instructionError::ERROR_CODE;
	}
	return instructionError::SUCCESS_CODE;
}
int instructionChecker::checkInputFormat(std::string s,int chk_case)const
{
	switch(chk_case)
	{
	case 0:
		if(s.size()<=1) return instructionError::EMPTY_PARAM;
		break;
	case 1:
		if(s.size()>31) return instructionError::OVERSIZEPARAM_ERROR;
		break;
	case 2:
		if(s.find('-',0)==std::string::npos) return instructionError::MISSINGDASH_ERROR;
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
int instructionChecker::identifierChecker(std::string s, int chk_case) const
{
	switch(chk_case)
	{
	case 0:
		if(s.size()<=1) return instructionError::EMPTY_PARAM;
		break;
	case 1:
		if(s.size()>31) return instructionError::OVERSIZEPARAM_ERROR;
		break;
	case 2:
		if(s[0]<64 || (s[0]>90 && s[0]<97) || (s[0]>=123 && s[0]<128))
		{
			return instructionError::CHARACTER_ERROR;
		}else
		{
			return instructionError::SUCCESS_CODE;
		}
		break;
	default:
		break;
	}
	return instructionError::SUCCESS_CODE;
}
void instructionChecker::saveKeywords(std::vector<std::string> v_s)
{
	std::fstream f("listadoPalabrasClave.txt", std::ios::out|std::ios::trunc);
	if(!f.is_open()) throw std::runtime_error("No se puede abrir el siguiente archivo : listadoPalabrasClave.txt");
	for(std::string &x:m_keywordsVec)
	{
		f<<x<<std::endl;
	}
	f.close();
}
void instructionChecker::updateKeywords(std::string s)
{
	auto find_it = std::find(m_keywordsVec.begin(),m_keywordsVec.end(),s);
	if(find_it != m_keywordsVec.end())
	{
		m_keywordsVec.push_back(s);
	}
}
