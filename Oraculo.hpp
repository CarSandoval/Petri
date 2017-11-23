#ifndef ORACULO_HPP_INCLUDED
#define ORACULO_HPP_INCLUDED

#include <map>
#include "vector.h"
#include "Nodos.hpp"

class Oraculo
{
	bool acotado;
	std::map<vector, Nodo*> nodos;
	vector max;

public:
	Oraculo(vector max0);
	~Oraculo();
	Nodo *consulta(vector marcado0);
}

#endif