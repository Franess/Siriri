#include "checkTools.h"
int checkKeyWords(const std::vector<std::string> &line_vec)
{
	
	return 0;
}
//Formato de la instruccion: P_CLAVE -VALOR NOMBRE
int lineSplitter(std::string s,std::vector<std::string> &aux_vec)
{
	aux_vec.clear();
	auto a_it = std::find(s.begin(),s.end(),' ');
	auto p_it = s.begin();
	while(a_it!=s.end())
	{
		if(*std::next(a_it) == ' ' || *std::prev(a_it) == ' ')
		{
			aux_vec.clear();
			return 2;
		}
		aux_vec.push_back(s.substr(p_it-s.begin(),a_it-p_it));
		p_it = a_it;
		a_it = std::find(std::next(p_it),s.end(),' ');
		std::advance(p_it,1);
	}
	std::string last_instr = s.substr(p_it-s.begin(),s.end()-p_it);
	if(last_instr.length()>0)
		aux_vec.push_back(last_instr);
	return 1;
}

int rstrCheckline(std::string s)
{
	return 0;
}
