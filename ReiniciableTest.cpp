#include<iostream>
#include"Arbol.h"

using namespace std;

int main()
{
	
	int marcado[] = {1,0,0};
	arbol tree(marcado,4,3);
	bool resp;

	resp = tree.reiniciable();
	if(resp)
	{
		cout<<"es reiniciable"<<endl;
	}
	else
	{
		cout<<"no es reiniciable"<<endl;
	}
	//tree = new arbol(marcado,4,3);
	return 0;
}
