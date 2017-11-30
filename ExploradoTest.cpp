#include "Nodos.hpp"
#include <iostream>

//using namespace std;

int main()
{
	Nodo aux;
	int aux2[]= {1,2,3};
	vector a(aux2,3);
	aux.setExplorado(a,true);
	std::cout<<aux.getExplorado(a)<<std::endl;
}
