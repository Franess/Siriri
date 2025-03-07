#include "linesManip.h"
#include "auxTools.h"
#include <iostream>

using namespace std;

int main()
{
	linesManip l_m("nuevo_archivos.edc",false);
	vector<string> v;
	if(lineSplitter("RSTR_EU",v)==SUCCESS_CODE)
		for(string &x:v) cout<<x<<endl<<x.size()<<endl;
	else
		cout<<"Error en la instruccion"<<endl;
	
	return 0;
}
