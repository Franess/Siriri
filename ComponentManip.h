#ifndef COMPONENTMANIP_HS
#define COMPONENTMANIP_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>

struct Component
{
	std::string id_comp;
	std::vector<std::string> m_design;
};


class ComponentManip {
public:
	ComponentManip();
	Component* gComponent(unsigned int i);
	size_t numofcomponents()const;
	
private:
	std::vector<Component> m_comps; //Vector de Componentes
};

#endif

