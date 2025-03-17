#include "linesManip.h"
#include "auxTools.h"
#include <iostream>
#include "instructionChecker.h"
#include "ComponentManip.h"

using namespace std;

int main()
{
	linesManip l_m("nuevo_archivo.edc",false);
	instructionChecker ichk;
	ComponentManip cmp;
	vector<string> v_s = cmp.gCompKeywords();
	vector<string> v;
	for(unsigned int i =0;i<cmp.numofcomponents();++i) ichk.updateKeywords(v_s[i]);
	if(ichk.checkKeywords("BATTERY")==instructionError::SUCCESS_CODE)
	{
		cout<<"Palabra valida\n\n\n";
	}else
	{
		cout<<"Palabra clave invalida\n\n\n";
	}
	for(int i=0;i<ichk.numofKeywords();i++) 
	{
		cout<<"palabra clave: "<<*ichk.gKeyword(i)<<"\n";
	}
	//Prueba metodo
	if(ichk.identifierChecker("HJÑAKSJDFK",2)==instructionError::SUCCESS_CODE)
		cout<<" valido\n";
	else
		cout<<"no es valido\n";
	
	//Como los metodos devuelven un elemento de un enum (un entero), cuando la cadena no tiene las caracteristicas que corresponden
	//podemos interpretar la suma de enteros como un error, si esta es diferente a la cantidad de cases del switch, se trata de una cadena 
	//invalida, en cambio si la suma es adecuada, la cadena es completamente valida (ver los fuentes de la clase)
	int x =0;
	for(int i=0;i<3;i++) 
	{
		x+=ichk.checkInputFormat("- ",i);
	}
	if(x!=3) cout<<"Instruccion no valida\n\n\n";
	else cout<<"Instruccion Valida\n\n\n";
	
	//Prueba carga de componentes
	for(unsigned int i=0;i<cmp.numofcomponents();i++)
	{
		Component c = *cmp.gComponent(i);
		cout<<"Nombre : "<<c.id_comp<<endl;
		for(string &x:c.m_design) cout<<x<<endl;
	}
	
	v = cmp.gCompDesign("RSTR_EU");
	cout<<"Correcto o no correcto: "<<v.size()<<endl;
//	ichk.saveKeywords();
	
	return 0;
}
