#include "Nodos.hpp"
#include <iostream>
//#include "Test.hpp"

std::map<vector*,bool> Nodo::init_nodos_creados()
{
	std::map<vector*,bool> aux;
	vector vec_aux;
	aux[&vec_aux] = false;
	return aux;
}

std::map<vector*,bool> Nodo::nodos_creados = init_nodos_creados();
int Nodo::nodos = 0;
int Nodo::max_disparo = 0;


Nodo::Nodo()
{
	mayorizado = false;
	padre = NULL;
	marcado = MARCADO_CERO;
	nodos = 0;
	max_disparo = 1;
	ciclo = false;

	 


}

Nodo::Nodo(vector marcado0)
{
	mayorizado = false;
	ciclo = false;
	padre = NULL;
	marcado = marcado0;
	nodos++;
	 nodos_creados[&marcado0] = false;

	 
}

Nodo::Nodo(int max_disparo0, vector marcado_init)
{

	//vector *disparos0;
	int ceros[max_disparo0] = {0};
	mayorizado = false;
	padre = NULL;
	ciclo = false;
	marcado = marcado_init;
	nodos = 1;
	 nodos_creados[&marcado_init] = false;

	disparos = new vector(ceros,max_disparo0);
	//disparos = *disparos0;
	hijos.resize(max_disparo0);
	for(int i=0;i<max_disparo0;i++)
		hijos.at(i)=NULL;

	 

}

Nodo::Nodo(Nodo *padre0, vector marcado0)
{
	mayorizado = false;
	ciclo = false;
	padre = padre0;
	marcado = marcado0;
	nodos++;
	 nodos_creados[&marcado0] = false;

	 
}

Nodo::~Nodo(){}

bool Nodo::nuevo_hijo(Nodo *nuevo_hijo0, int disparo)
{
	if(disparo<max_disparo)
	{
	    hijos[disparo] = nuevo_hijo0;
	    
	    return true;
	}
	else
	{
		
	    return false;
	}
}

void Nodo::setPadre(Nodo *padre0)
{
	this->padre = padre0;

	 
}

void Nodo::setCiclo(bool ciclo0)
{
	ciclo = ciclo0;

	 
}

bool Nodo::getCiclo()
{
	 

	return ciclo;
}

void Nodo::mayorizar()
{
	mayorizado = true;

	 
}

bool Nodo::getMayorizado()
{
	 

	return mayorizado;
}

vector Nodo::getDisparos()
{
	for(int i=0; i<disparos.size(); i++)
		hijos[i]==NULL ? disparos.set(i,0) : disparos.set(i,1);

	 

	return disparos;

}

int Nodo::getNodos()
{
	 

	return nodos;
}

Nodo *Nodo::getPadre()
{
	 

	return padre;
}

Nodo *Nodo::hijo(int disparo0)
{
	 

	return hijos[disparo0];
}

std::vector<Nodo*> Nodo::getHijos()
{
	 

	return hijos;
}

vector Nodo::getMarcado()
{
	 

	return marcado;
}

void Nodo::setExplorado(vector marcado0, bool ciclo0)
{
	 nodos_creados[&marcado0] = ciclo0;

	 
}

bool Nodo::getExplorado(vector marcado0)
{
	 

	return  nodos_creados[&marcado0];
}

void Nodo::setHijo(Nodo* n_padre, int disparo){
	hijos[disparo] = n_padre;
}