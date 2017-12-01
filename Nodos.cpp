#include "Nodos.hpp"
#include <iostream>
//#include "Test.hpp"

list *Nodo::init_nodos_creados()
{

	list *aux;
	vector vec_aux;
	_Nodos aux_nodo;
	aux_nodo.VECTOR = vec_aux;
	aux_nodo.BOOL = false;
	aux->push_back(aux_nodo);
	return aux;
}

list *Nodo::nodos_creados = Nodo::init_nodos_creados();

int Nodo::nodos = 0;
int Nodo::max_disparo = 0;
list *list::last = NULL;


_Nodos::_Nodos()
{
	error = false;
}


void _Nodos::fill(vector vec0,bool bool0)
{
	nodos_vector = vec0;
	nodos_bool = bool0;
}

void _Nodos::operator =(const _Nodos &v1)
{
	VECTOR = v1.VECTOR;
	BOOL = v1.BOOL;
	error = v1.error;
}


list::list()
{
	_Nodos nodo;
	_value = nodo;
	_list = NULL; 
	//last = this;
}

list::list(_Nodos _value0)
{
	_value = _value0;
	_list = NULL;
	//last = this;
}

void list::push_back(_Nodos _value0)
{
	_Nodos aux;
	aux = find_inside(_value0.VECTOR);
	if(!aux.error)
	{
		std::cout<<"000000000000DEBUG00000000000000000"<<std::endl;
		aux.BOOL = _value0.BOOL;
	}
	else
	{
		list *_list0 = new list(_value0);
		_list0->_list = last;
		last = _list0;
	}
}

_Nodos list::find(int i0)
{
	list *current_list;
	current_list = last;
	_Nodos aux;
	_Nodos err;
	int i=0;
	while(current_list!=NULL)
	{
		if(i==i0)
		{
			aux = current_list->_value;
			return aux;
		}
		i++;
		current_list = current_list->_list;
	}
	//return NULL;
	std::cout<<"ERROR: list::find_inside(int)... Instance _Nodos (NOT FOUND)"<<std::endl;
	err.error = true;
	return err;

}

_Nodos list::find_inside(vector value20)
{
	list *current_list;
	current_list = last;
	last==NULL ? std::cout<<"NULL\n":std::cout<<"NO NULL\n";
	_Nodos aux;
	_Nodos err;
	while(current_list!=NULL)
	{

		if(value20==current_list->_value.VECTOR)
		{
			aux = current_list->_value;
			
			return aux;
		}
		current_list = current_list->_list;
	}
	//return NULL;
	std::cout<<"ERROR: list::find_inside(vector)... Instance _Nodos (NOT FOUND)"<<std::endl;
	err.error = true;
	return err;
}


void Nodo::addNodosCreados(vector vec0, bool bool0)
{
	_Nodos nodos_creados0;
	nodos_creados0.fill(vec0,bool0);
	nodos_creados->push_back(nodos_creados0);
}


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
	addNodosCreados(marcado0,false);

	 
}

Nodo::Nodo(int max_disparo0, vector marcado_init)
{

	//vector *disparos0;
	int ceros[max_disparo0] = {0};
	mayorizado = false;
	padre = NULL;
	ciclo = false;
	marcado = marcado_init;
	nodos += 1;
	addNodosCreados(marcado_init,false);

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
	addNodosCreados(marcado0,false);

	 
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
	addNodosCreados(marcado0,ciclo0);
	 
}

bool Nodo::getExplorado(vector marcado0)
{
	_Nodos aux;
	aux = nodos_creados->find_inside(marcado0);
	
	return aux.BOOL;
}

void Nodo::setHijo(Nodo* n_padre, int disparo)
{
	hijos[disparo] = n_padre;
}