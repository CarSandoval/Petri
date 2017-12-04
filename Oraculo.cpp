#include "Oraculo.hpp"

#include <iostream>
#include <fstream>

Oraculo::Oraculo(vector max0, int max_disparos0, int maximus0)
{
	max = max0;
	acotado = true;
	max_disparos = max_disparos0;
	maximus = maximus0;
}

Nodo *Oraculo::consulta(vector marcado0, Nodo* padre, bool *repetido)
{
	*repetido = false;
	std::vector<_Nodos>::iterator i;
	Nodo* aux_padre;



	//******************************************************

	if(padre!=NULL)
	{
		while(!(padre->getMarcado() == max))
		{
			if(marcado0 >= padre->getMarcado())
			{

				if(marcado0 > padre->getMarcado())
				{
					acotado = false;
				}
				for(int j=0;j<marcado0.size();j++)
				{
					if(marcado0.get(j)>maximus)
					{
						*repetido = true;
						return padre;
					}
				}
			}
			padre = padre->getPadre();
		}
	}
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
	return padre;	
	//*********************************************************



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

Nodo* Oraculo::find(vector marcado0)
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

bool Oraculo::findCiclo()
{
	std::vector<_Nodos>::iterator i;
	Nodo* aux;
	for(i=nodos.begin();i!=nodos.end();i++)
	{
			aux = i->NODO;
			if(!aux->getCiclo())
			{
				return false;
			}
	}
	return true;
}

void Oraculo::doGraph()
{
	//para imprimir
	std::ofstream myfile;
	myfile.open ("grafo.dot");
	//para todo lo demas
	std::vector<_Nodos>::iterator i;
	Nodo* aux;
	myfile<<"digraph G {\n";
	for(i=nodos.begin();i!=nodos.end();i++)
	{
			aux = i->NODO;
			vector vectorAux, vectorHijo;
			Nodo* hijo;
			vectorAux = aux->getMarcado();
			for(int i=0;i<max_disparos;i++)
			{
				
				if((aux->getHijos())[i]==NULL)
				{
					continue;
				}
				hijo = (aux->getHijos())[i];
				vectorHijo = hijo->getMarcado();
				
				//imrpimo Cabecera				
				myfile<<"marcado_";				
				
				//imprimo marcado papa
				for(int i=0;i<vectorAux.size()-1;i++)
				{
					myfile<<vectorAux.get(i)<<"_";
				}
				myfile<<vectorAux.get(vectorAux.size()-1)<<"";

				//imprimo intermedio
				myfile<<" -> ";

				//imprimo marca hijo
				myfile<<"marcado_";				
				for(int i=0;i<vectorHijo.size()-1;i++)
				{
					myfile<<vectorHijo.get(i)<<"_";
				}
				myfile<<vectorHijo.get(vectorHijo.size()-1)<<"";
				myfile<<";\n";

			}
		
	}
	myfile<<"}\n";
	myfile.close();
	system("dot -Tpng grafo.dot -o grafo.png");
	system("nohup display grafo.png &" );
}

bool Oraculo::findVivo()
{
	std::vector<_Nodos>::iterator i;
	Nodo* aux;
	for(i=nodos.begin();i!=nodos.end();i++)
	{
			aux = i->NODO;
			if(!aux->getVivo())
			{
				return false;
			}
	}
	return true;
}
