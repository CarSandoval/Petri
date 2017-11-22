#include <stdlib>
#include "Vector.h"

#ifndef NODO_HPP_INCLUDED
#define NODO_HPP_INCLUDED

#define MARCADO_CERO vector::vector();


class Nodo
{
	bool mayorizado;
	Nodo *padre;
	std::map<vector,*Nodo> hijos;
	vector marcado;
	static std::map<vector,*Nodo> nodos_creados;
	static int nodos;

public:
	Nodo();
	Nodo(int size_p, vector marcado_init);
	Nodo(Nodo *padre);
	bool nuevo_hijo(vector marcado_init);
	void mayorizar();
	bool mayorizado();
	static int nodos();
	Nodo *padre();
	Nodo *hijo(vector marcado0);
	std::map<vector, *Nodo> map; hijos();
	static bool existe();
	vector marcado();
	~Nodo();

}



#endif