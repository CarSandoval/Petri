#include <stdlib>
#include "Vector.h"

#ifndef NODO_HPP_INCLUDED
#define NODO_HPP_INCLUDED

#define MARCADO_CERO vector::vector();


class Nodo
{
	bool mayorizado;
	Nodo *padre;
	std::vector<Nodo> hijos;
	vector::vector marcado;
	static std::map<vector::vector,*Nodo> nodos_creados;
	static int nodos;

public:
	Nodo();
	Nodo(int size_p, vector::vector marcado_init);
	Nodo(Nodo *padre);
	void nuevo_hijo(vector::vector marcado_init);
	void mayorizar();
	bool mayorizado();
	~Nodo();

}



#endif