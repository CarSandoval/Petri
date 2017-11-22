#include "Nodos.hpp"

Nodo::Nodo()
{
	mayorizado = false;
	padre = NULL;
	marcado = MARCADO_CERO;
	nodos = 0;
	max_disparo = 1;

}

Nodo::Nodo(int max_disparo0, vector marcado_init)
{
	int ceros[max_disparo0] = {0};
	mayorizado = false;
	padre = NULL;
	marcado = marcado_init;
	nodos = 1;
	nodos_creados[marcado_init] = this;
	disparos = new vector(ceros,max_disparo0);
	for(int i=0;i<max_disparo0;i++)
		hijos[i]=NULL;

}

Nodo::Nodo(Nodo *padre0, vector marcado0)
{
	mayorizado = false;
	padre = padre0;
	marcado = marcado0;
	nodos++;
	nodos_creados[marcado0] = this;
}

bool Nodo::nuevo_hijo(Nodo *nuevo_hijo0, int disparo)
{
	disparo<max_disparo ? hijos[disparo] = nuevo_nodo :return false;
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

vector Nodo::getDisparos()
{
	for(int i=0; i<disparos.size(); i++)
		hijos[i]==NULL ? disparos.set(i,0) : disparos.set(i,1);
	return disparos;

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
	return hijos[marcado0]
}

std::vector<*Nodo> Nodo::hijo()
{
	return hijos;
}

vector Nodo::marcado()
{
	return marcado;
}