#include "Oraculo.hpp"

Oraculo::Oraculo(vector max0, int max_disparos0)
{
	max = max0;
	acotado = true;
	max_disparos = max_disparos0;
}

Nodo *Oraculo::consulta(vector marcado0, bool *repetido)
{
	*repetido = false;
	std::vector<_Nodos>::iterator i;
	for (i = nodos.begin(); i != nodos.end(); ++i)
	{
		if(marcado0 >= i->VECTOR)
		{
			acotado = false;
		}
	}
	if(marcado0 >= max)
	{
		vector aux = marcado0;
		for (i = nodos.begin(); i != nodos.end(); ++i)
		{
			if(i->VECTOR < aux && i->VECTOR > max)
			{
				aux = i->VECTOR;
			}
		}
		if(exist(aux))
		{
			*repetido = true;
			return find(aux);
		}
		else
		{
			Nodo *nuevo = new Nodo(max_disparos,aux);
			_Nodos nodo_nuevo;
			nodo_nuevo.VECTOR = aux;
			nodo_nuevo.NODO = nuevo;
			nodos.push_back(nodo_nuevo);
			return nuevo;
		}
	}
	else
	{
		if(exist(marcado0))
		{
			*repetido = true;
			return find(marcado0);
		}
		else
		{
			Nodo *nuevo = new Nodo(max_disparos,marcado0);
			_Nodos nodo_nuevo;
			nodo_nuevo.VECTOR = marcado0;
			nodo_nuevo.NODO = nuevo;
			nodos.push_back(nodo_nuevo);
			return nuevo;
		}
	}
}


bool Oraculo::getAcotado()
{
	return acotado;
}

bool Oraculo::exist(vector marcado0)
{
	std::vector<_Nodos>::iterator i;

	for(i=nodos.begin();i!=nodos.end();i++)
	{
		if(i->VECTOR==marcado0)
		{
			return true;
		}
	}
	return false;
}

Nodo* Oraculo:find(vector marcado0)
{
	std::vector<_Nodos>::iterator i;

	for(i=nodos.begin();i!=nodos.end();i++)
	{
		if(i->VECTOR==marcado0)
		{
			return i->NODO;
		}
	}
	return NULL;
}