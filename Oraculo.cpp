#include "Oraculo.hpp"

Oraculo::Oraculo(vector max0)
{
	max = max0;
	acotado = true;
}

Nodo *Oraculo::consulta(vector marcado0, bool *repetido)
{
	*repetido = false;
	std::map<vector, Nodo*>::iterator i;
	for (i = nodos.begin(); i != nodos.end(); ++i)
	{
		if(marcado0 >= i->first)
		{
			acotado = false;
		}
	}
	if(marcado0 >= max)
	{
		vector aux = marcado0;
		for (i = nodos.begin(); i != nodos.end(); ++i)
		{
			if(i->first < aux && i->first > max)
			{
				aux = i->first;
			}
		}
		Nodo *nuevo = new Nodo(aux);
		return nuevo;
	}
	else
	{
		if(nodos.find(marcado0)!=nodos.end())
		{
			*repetido = true;
			return nodos[marcado0];
		}
		else
		{
			Nodo *nuevo = new Nodo(marcado0);
			nodos[marcado0] = nuevo;
			return nuevo;
		}
	}
}
