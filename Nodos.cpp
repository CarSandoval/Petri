#include "Nodos.hpp"

Nodo::Nodo()
{
	mayorizado = false;
	padre = NULL;
	marcado = MARCADO_CERO;
	nodos = 0;

}

Nodo::Nodo(int size_p, vector::vector marcado_init)
{
	mayorizado = false;
	padre = NULL;
	marcado = marcado_init;
	nodos = 1;
	nodos_creados[marcado_init] = this;

}

Nodo::Nodo(Nodo *padre0, vector::vector marcado0)
{
	mayorizado = false;
	padre = padre0;
	marcado = marcado0;
	nodos++;
	nodos_creados[marcado0] = this;
}



void Nodo::nuevo_hijo(vector::vector marcado_init)
{
	Nodo *nuevo_nodo = new Nodo(this, marcado_init);
	hijos.push_back(nuevo_nodo);
}

void Nodo::mayorizar()
{
	mayorizado = true;
}

bool Nodo::mayorizado()
{
	return mayorizado;
}