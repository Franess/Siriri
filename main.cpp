#include "linesManip.h"
#include "auxTools.h"
#include <iostream>
#include "instructionChecker.h"

using namespace std;

int main()
{
	linesManip l_m("nuevo_archivo.edc",false);
	instructionChecker ichk;
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
	if(ichk.checkKeywords("RSTR_EU")!=instructionError::SUCCESS_CODE)
		cout<<"El metodo es valido\n";
	else
		cout<<"El metodo no es valido\n";
	
	if(ichk.checkInputFormat("a",1)!=instructionError::SUCCESS_CODE) 
		cout<<"Sobredimension\n";
	else
		cout<<"Dimension correcta\n";
	return 0;
}
