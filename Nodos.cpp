#include "Nodos.hpp"

Nodo::Nodo()
{
	mayorizado = false;
	padre = NULL;
	marcado = MARCADO_CERO;
	nodos = 0;

}

Nodo::Nodo(int size_p, vector marcado_init)
{
	mayorizado = false;
	padre = NULL;
	marcado = marcado_init;
	nodos = 1;
	nodos_creados[marcado_init] = this;

}

Nodo::Nodo(Nodo *padre0, vector marcado0)
{
	mayorizado = false;
	padre = padre0;
	marcado = marcado0;
	nodos++;
	nodos_creados[marcado0] = this;
}



bool Nodo::nuevo_hijo(vector marcado_init)
{
	Nodo *nuevo_nodo = new Nodo(this, marcado_init);
	!existe ? hijos[nuevo_nodo.marcado] = nuevo_nodo : return false;
	return true;
}

void Nodo::mayorizar()
{
	mayorizado = true;
}

bool Nodo::mayorizado()
{
	return mayorizado;
}

static int Nodo::nodos()
{
	return nodos;
}

Nodo *Nodo::padre()
{
	return padre;
}

Nodo *Nodo::hijo(vector marcado0)
{
	return hijos[marcado]
}

std::map<vector, *Nodo> Nodo::hijo()
{
	return hijos;
}

bool Nodo::existe()
{
	return hijos.find(marcado)!=hijos.end();
}

vector Nodo::marcado()
{
	return marcado;
}