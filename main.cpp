#include "linesManip.h"
#include "auxTools.h"
#include <iostream>
#include "instructionChecker.h"

#include <cstdio>
using namespace std;

int main()
{
	linesManip l_m("nuevo_archivo.edc",false);
	instructionChecker ichk;
	cout<<"Cantidad de palabras clave: "<<ichk.numofKeywords()<<"\n";
	vector<string> v;
	if(lineSplitter("RSTR_EU",v)==SUCCESS_CODE)
		for(string &x:v) cout<<x<<endl<<x.size()<<endl;
	else
		cout<<"Error en la instruccion"<<endl;
	for(int i=0;i<ichk.numofKeywords();i++) 
	{
		cout<<"palabra clave: "<<*ichk.gKeyword(i)<<"\n";
	}
	//Prueba metodo
	if(ichk.checkKeywords("RSTR_EU"))
		cout<<"El metodo es valido\n";
	else
		cout<<"El metodo no es valido\n";
	return 0;
}
