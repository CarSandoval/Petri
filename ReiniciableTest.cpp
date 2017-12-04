#include<iostream>
#include"Arbol.h"
//#include"Nodos.hpp"

//using namespace std;

int main()
{
	
	int t,p;
	int *marcado;

	std::cout<<"Numero de transiciones: ";
	std::cin>>t;
	std::cout<<"Numero de Lugares: ";
	std::cin>>p;
	std::cout<<"Marcado inicial: ";
	
	//pido memoria para el marcado inicial
	marcado = new int[p];
	for(int i=0;i<p;i++)
	{
		std::cin>>marcado[i];	
	}


	//creo el arbol
	arbol tree(marcado,t,p);

	//auxiliar para la respuesta de reiniciabilidad
	bool resp;

	std::cout<<"Es acotado:? ";
	if(tree.getAcotado())
	{
		std::cout<<"Si\n";
	}
	else
	{
		std::cout<<"No\n";
	}

	//calculo reiniciabilidad

	resp = tree.reiniciable();
	
	if(resp)
	{
		std::cout<<"Es reiniciable"<<std::endl;
	}
	else
	{
		std::cout<<"No es reiniciable"<<std::endl;
	}

	list::purge();
	resp = tree.vivacidad();
	
	if(resp)
	{
		std::cout<<"Es Viva"<<std::endl;
	}
	else
	{
		std::cout<<"No es Viva"<<std::endl;
	}
	
	//tree = new arbol(marcado,4,3);
	return 0;
}
