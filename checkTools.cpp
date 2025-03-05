#include "checkTools.h"
bool checkKeyWords(const std::vector<std::string> &v)
{
	
	return false;
}
//Formato de la instruccion: P_CLAVE -VALOR NOMBRE
std::vector<std::string> lineSplitter(std::string s)
{
	std::vector<std::string> aux_vec;
	auto it_spaces = std::remove(s.begin(),s.end(),' ');
	s.erase(it_spaces-s.begin(),s.end()-it_spaces);
	auto a_it = std::find(s.begin(),s.end(),'-');
	auto p_it = s.begin();
	while(a_it!=s.end())
	{
		aux_vec.push_back(s.substr(std::next(p_it)-s.begin(),std::prev(a_it)-p_it));
		p_it = a_it;
		a_it = std::find(std::next(p_it),s.end(),'-');
	}
	aux_vec.push_back(s.substr(std::next(p_it)-s.begin(),s.end()-p_it));
	return aux_vec;
}
