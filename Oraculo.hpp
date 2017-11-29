#ifndef ORACULO_HPP_INCLUDED
#define ORACULO_HPP_INCLUDED

#include <map>
#include "vector.h"
#include "Nodos.hpp"
#define VECTOR nodos_vector
#define NODO nodos_nodo

class Oraculo
{
	bool acotado;
	
	class _Nodos
	{
	public:
		vector nodos_vector;
		Nodo *nodos_nodo;
	};
	std::vector<_Nodos> nodos;
	vector max;
	int max_disparos;
	bool exist(vector marcado0);

public:
	Oraculo(vector max0, int max_disparos0);
	~Oraculo();
	Nodo *consulta(vector marcado0, bool *repetido);
	bool getAcotado();
};

#endif