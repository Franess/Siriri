#include "ComponentManip.h"

bool compare_id(std::string &id, Component &c)
{
	if(c.id_comp == id) return true;
	else return false;
}

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
			aux_vec.clear();
			m_comps.push_back(nn_comp);
		}
		
	}
	
}
Component* ComponentManip::gComponent(unsigned int i)
{
	if(i<numofcomponents()) return &m_comps[i];
	else return nullptr;
}
size_t ComponentManip::numofcomponents()const
{
	return m_comps.size();
}
std::vector<std::string> ComponentManip::gCompDesign(std::string idd)const
{
	std::vector<std::string> aux_vec;
	Component* cp_ptr = nullptr;
	for(Component x:m_comps)
	{
		if(x.id_comp==idd)
		{
			cp_ptr = &x;
		}
	}
	if(cp_ptr)
	{
		return (*cp_ptr).m_design;
	}else
	{
		return aux_vec; /*La idea el que si no se encuentra el componente con su diseño
		se retorne un vector vacio, o vector de longitud 0*/
	}
}
std::vector<std::string> ComponentManip::gCompKeywords()
{
	std::vector<std::string> aux_vec;
	for(Component &x:m_comps)
	{
		aux_vec.push_back(x.id_comp);
	}
	return aux_vec;
}
