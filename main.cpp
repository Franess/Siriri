#include "ReadLines.h"
#include "checkTools.h"
#include <iostream>
using namespace std;

int main()
{
	vector<string> v = lineSplitter("RSTR_EU");
	if(!v.empty())
		for(string &x:v) cout<<x<<endl<<x.size()<<endl;
	return 0;
}
