#include "Oraculo.hpp"
#include "Arbol.h"
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
	vector myr;



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
				//myr = marcado0.mayor(padre->getMarcado());
				//padre->addMyr(myr);
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
		Nodo* lala;
		*repetido = true;
		lala = find(marcado0);
		vector omega;
		omega = marcado0.mayor(padre->getMarcado());
		lala->addMyr(omega);
		return lala;
	}
	else
	{
		Nodo *nuevo = new Nodo(max_disparos,marcado0);
		_Nodos nodo_nuevo;
		nodo_nuevo.VECTOR = marcado0;
		nodo_nuevo.NODO = nuevo;
		nodos.push_back(nodo_nuevo);
		if(padre!=NULL)
		{
			vector omega;
			omega = marcado0.mayor(padre->getMarcado());
			nuevo->addMyr(omega);
		}
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
	std::vector<std::string> myfile0;
	myfile0.resize(Nodo::getNodos());
	std::ofstream myfileout;
	int fn = 0;
	//myfile.open ("grafoin");
	myfileout.open("grafo.dot");
	//para todo lo demas
	std::vector<_Nodos>::iterator i;
	Nodo* aux;
	std::string myfile;
	//myfile+="digraph G {\n";
	for(i=nodos.begin();i!=nodos.end();i++)
	{
			aux = i->NODO;
			vector vectorAux, vectorHijo;
			Nodo* hijo;
			vectorAux = aux->getMarcado();
			int omega[vectorAux.size()] = {0};
			/*for (int w = 0; w < Nodo::getNodos(); ++w)
			{
				Nodo* current_aux;
				current_aux = aux->getPadre();
				vector marcado1;
				vector marcado2;
				std::cout<<"MArcado actual:\t";
				arbol::imprimirVec(vectorAux);
				while(current_aux != NULL)
				{
					marcado1 = aux->getMarcado();
					marcado2 = current_aux->getMarcado();
					std::cout<<"MArcado checado:\t";
					arbol::imprimirVec(marcado2);
					if(marcado1 >= marcado2)
					{
						std::cout<<"MArcado mayorixads:\t";
						arbol::imprimirVec(marcado2);
						for (int i = 0; i < marcado1.size(); ++i)
						{
							if(marcado1.get(i) > marcado2.get(i))
								omega[i] = 1;
						}
						vector auxaxu(omega,marcado1.size());
						arbol::imprimirVec(auxaxu);
						break;
					}
					current_aux = current_aux->getPadre();
				}
			}*/

			for(int i=0;i<max_disparos;i++)
			{
				
				if((aux->getHijos())[i]==NULL)
				{
					continue;
				}
				hijo = (aux->getHijos())[i];
				vectorHijo = hijo->getMarcado();

				
				//imrpimo Cabecera				
				myfile+="\"[ ";				
				
				//imprimo marcado papa
				for(int i=0;i<vectorAux.size()-1;i++)
				{
					if(aux->getMyr().get(i) == 1)
					{
						myfile+="w ";
					}
					else
					{
						myfile+=vectorAux.get(i)+'0';
						myfile+=" ";
					}
				}
				myfile+=vectorAux.get(vectorAux.size()-1)+'0';
				myfile+=" ]\"";

				//imprimo intermedio
				myfile+=" -> ";

				//imprimo marca hijo
				myfile+="\"[ ";				

				for(int i=0;i<vectorHijo.size()-1;i++)
				{
					if(hijo->getMyr().get(i) == 1 || aux->getMyr().get(i) == 1)
					{
						myfile+="w ";
					}
					else
					{
						myfile+=vectorHijo.get(i)+'0';
						myfile+=" ";
					}
				}
				myfile+=vectorHijo.get(vectorHijo.size()-1)+'0';
				myfile+=" ]\"";
				myfile+=" [label=\"t";
				myfile+=(i+'0')+1;
				myfile+="\"]";
				myfile+=";\n";
				myfile0.push_back(myfile);
				myfile.clear();
			}
		
	}
	std::vector<std::string>::iterator str;
	std::vector<std::string>::iterator str0;
	for(str=myfile0.begin();str!=myfile0.end();++str)
	{
		for(str0=str+1;str0!=myfile0.end();++str0)
		{
			if(str->compare(*str0) == 0)
			{
				myfile0.erase(str0);
			}
			if(str+1==myfile0.end())
				break;
		}
	}
	myfile="digraph G {\n";
	for(str=myfile0.begin();str!=myfile0.end();++str)
	{
		myfile+=*str;
	}
	myfile+="}\n";
	std::cout<<myfile;
	myfileout<<myfile.data();
	myfileout.close();
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
