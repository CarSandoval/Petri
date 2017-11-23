#include <stdlib.h>
#include "Vector.h"
#include <vector>
#include <map>

#ifndef NODO_HPP_INCLUDED
#define NODO_HPP_INCLUDED

#define MARCADO_CERO new vector();


class Nodo
{
	bool mayorizado;
	bool ciclo;
	Nodo *padre;
	std::vector<Nodo*> hijos;
	vector disparos;
	vector marcado;
	static std::map<vector,Nodo*> nodos_creados;
	static int nodos;
	static int max_disparo;

public:
	Nodo();
	Nodo(int max_disparo0, vector marcado_init);
	Nodo(Nodo *padre, vector marcado0);
	bool nuevo_hijo(Nodo *nuevo_hijo0, int disparo);
	void setCiclo(bool ciclo0);
	bool getCiclo();
	void mayorizar();
	bool getMayorizado();
	vector getDisparos();
	static int getNodos();
	Nodo *getPadre();
	Nodo *hijo(int disparo0);
	std::vector<Nodo*> getHijos();
	static bool existe();
	vector getMarcado();
	~Nodo();

};



#endif