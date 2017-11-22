#include <stdlib>
#include "Vector.h"

#ifndef NODO_HPP_INCLUDED
#define NODO_HPP_INCLUDED

#define MARCADO_CERO vector::vector();


class Nodo
{
	bool mayorizado;
	Nodo *padre;
	std::vector<*Nodo> hijos;
	vector disparos;
	vector marcado;
	static std::map<vector,*Nodo> nodos_creados;
	static int nodos;
	static int max_disparo;

public:
	Nodo();
	Nodo(int max_disparo0, vector marcado_init);
	Nodo(Nodo *padre);
	bool nuevo_hijo(vector marcado_init, int disparo);
	void mayorizar();
	bool mayorizado();
	vector getDisparos();
	static int nodos();
	Nodo *padre();
	Nodo *hijo(vector marcado0);
	std::vector<*Nodo> hijos();
	static bool existe();
	vector marcado();
	~Nodo();

}



#endif