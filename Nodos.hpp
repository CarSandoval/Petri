#include <stdlib.h>
#include "Vector.h"
#include <vector>
#include <map>

#ifndef NODO_HPP_INCLUDED
#define NODO_HPP_INCLUDED

#define MARCADO_CERO new vector()
#define VECTOR nodos_vector
#define BOOL nodos_bool


class _Nodos
{
public:
	vector nodos_vector;
	bool nodos_bool;
	void fill(vector vec0,bool bool0)
	{
		nodos_vector = vec0;
		nodos_bool = bool0;
	}
};

class Nodo
{
	bool mayorizado;
	bool ciclo;
	Nodo *padre;
	std::vector<Nodo*> hijos;
	vector disparos;
	vector marcado;
	
	void addNodosCreados(vector vec0, bool bool0);

	static std::vector<_Nodos> nodos_creados;
	//static std::map<vector*,bool> nodos_creados;//(first.begin(),first.end());
	static int nodos;
	static int max_disparo;
	static std::vector<_Nodos> init_nodos_creados();

public:
	
	Nodo();
	Nodo(vector marcado0);
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
	void setPadre(Nodo *padre0);
	Nodo *hijo(int disparo0);
	std::vector<Nodo*> getHijos();
	static bool existe();
	vector getMarcado();
	bool getExplorado(vector marcado0);
	void setExplorado(vector marcado0, bool ciclo0);
	void setHijo(Nodo* padre, int disparo);
	~Nodo();

};




#endif