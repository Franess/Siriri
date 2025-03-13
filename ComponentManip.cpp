#include "ComponentManip.h"

ComponentManip::ComponentManip() {
	std::fstream f("archivoComponentes.txt",std::ios::in);
	if(!f.is_open()) throw std::runtime_error("No se pudo abrir el archivo en cuestion: archivoComponentes.txt");
	std::string s;
	Component nn_comp;
	std::vector<std::string> aux_vec;
	int c = 0; //Contador
	while(std::getline(f,s))
	{
		if(std::find(s.begin(),s.end(),'/')!=s.end()) continue;
		if(s[0]=='#')
		{
			nn_comp.id_comp = s.substr(1,s.end()-std::next(s.begin()));
			continue;
		}
		aux_vec.push_back(s);
		++c;
		if(c>4)
		{
			c = 0;
			nn_comp.m_design = aux_vec;
			m_comps.push_back(nn_comp);
		}
		
	}
	
}
Component* ComponentManip::gComponent(unsigned int i)
{
	if(i<m_comps.size()) return &m_comps[i];
	else return nullptr;
}
