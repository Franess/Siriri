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
	cout<<"Cantidad de palabras clave: "<<ichk.numofKeywords()<<"\n";
	cout<<"Cantidad de codigos: "<<instructionError::TOTAL_CODES<<"\n";
	vector<string> v;
	if(lineSplitter("RSTR_EU",v)==instructionError::SUCCESS_CODE)
		for(string &x:v) cout<<x<<endl<<x.size()<<endl;
	else
		cout<<"Error en la instruccion"<<endl;
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
	if(cmp.gComponent(0))
	{
		Component c = *cmp.gComponent(0);
		cout<<"Nombre : "<<c.id_comp<<endl;
		for(string &x:c.m_design) cout<<x<<endl;
	}
	
	return 0;
}
