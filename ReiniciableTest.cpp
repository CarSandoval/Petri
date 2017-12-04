#include<iostream>
#include"Arbol.h"
#include"Nodos.hpp"
#include <fstream>
#include <sstream>

//using namespace std;

int main()
{
	
	std::ifstream file;
	file.open("test.txt");
	int t,p;
	int *marcado;
	int aux = 1;
	int *pre_pos;
	vector* pre;
    vector* post;

    std::string line, marcadoI;
	while(!file.eof()){
		getline(file, line);
		if (aux == 1)
		{
			std::istringstream iss(line);
			if (!(iss >> t >> p)) { break; }
		}else if (aux == 2)
		{
			marcadoI = line;
		}
		else if(aux <= (t + 2)){

		}
		else if (aux <= ((t*2) + 2))
		{
			
		}
		aux++;
	}

	file.close();
	std::cout<<"Numero de transiciones: " << t << std::endl;
	//std::cin>>t;
	std::cout<<"Numero de Lugares: " << p << std::endl;

	std::cout<<"Marcado Inicial: ";
	//pido memoria para el marcado inicial
	marcado = new int[p];
	
	std::istringstream iss(marcadoI);

	for(int i=0;i<p;i++)
	{
		iss >> marcado[i];	
	}

	pre = new vector[t];
    post = new vector[t];

	
	file.open("test.txt");
	aux = 1;	
	pre_pos = new int[p];

	int i=0;
	int k = 0;

	while(!file.eof()){	
		getline(file, line);

		//Obtiene el pre
		if(aux <= (t + 2) && aux > 2){

			std::istringstream iss(line);
			for(int j=0;j<p;j++)
			{
				iss >> pre_pos[j];	
			}
			pre[i] = new vector(pre_pos,p);
			i++;
		}
		else if (aux <= ((t*2) + 2) && aux > 2)			// Obtiene matriz post
		{
			std::istringstream iss(line);

			for(int j=0;j<p;j++)
			{
				iss >> pre_pos[j];	
			}
			post[k] = new vector(pre_pos,p);
			k++;
		}
		aux++;
	}

	file.close();



	//creo el arbol
	arbol tree(marcado,t,p,pre,post);

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
