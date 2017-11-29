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
	std::map<vector*, Nodo*>::iterator i;
	for (i = nodos.begin(); i != nodos.end(); ++i)
	{
		if(marcado0 >= *(i->first))
		{
			acotado = false;
		}
	}
	if(marcado0 >= max)
	{
		vector aux = marcado0;
		for (i = nodos.begin(); i != nodos.end(); ++i)
		{
			if(*(i->first) < aux && *(i->first) > max)
			{
				aux = *(i->first);
			}
		}
		if(exist(aux))
		{
			*repetido = true;
			return nodos[&aux];
		}
		else
		{
			Nodo *nuevo = new Nodo(max_disparos,aux);
			nodos[&aux] = nuevo;
			return nuevo;
		}
	}
	else
	{
		if(exist(marcado0))
		{
			*repetido = true;
			return nodos[&marcado0];
		}
		else
		{
			Nodo *nuevo = new Nodo(max_disparos,marcado0);
			nodos[&marcado0] = nuevo;
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
	std::map<vector*, Nodo*>::iterator i;

	for(i=nodos.begin();i!=nodos.end();i++)
	{
		if(*(i->first)==marcado0)
		{
			return true;
		}
	}
	return false;
}