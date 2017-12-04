#include<iostream>
#include"Arbol.h"
#include"Nodos.hpp"

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
	bool resp, resp2;

	int no_nodos = Nodo::getNodos();
	std::cout<<"Es acotado?: ";
	if(tree.getAcotado())
	{
		std::cout<<"Si\n";
	}
	else
	{
		std::cout<<"No\n";
	}

	//calculo reiniciabilidad

	for (int i = 0; i < no_nodos; ++i)
	{
		list::purge();
		resp = tree.reiniciable();
		//std::cout<<"---------------------------"<<i<<"-----------------------------"<<std::endl;
	}
	resp = tree.direccion->findCiclo();
	
	


	for (int i = 0; i < no_nodos; ++i)
	{
		list::purge();
		resp2 = tree.vivacidad();
	}
	
	resp2 = tree.direccion->findVivo();

	std::cout<<"Esta viva?: ";
	if(resp2)
	{
		std::cout<<"Si"<<std::endl;
	}
	else
	{
		std::cout<<"No"<<std::endl;
	}
	
	std::cout<<"Es reiniciable?: ";
	if(resp)
	{
		std::cout<<"Si"<<std::endl;
	}
	else
	{
		std::cout<<"No"<<std::endl;
	}
	//tree = new arbol(marcado,4,3);
	return 0;
}
