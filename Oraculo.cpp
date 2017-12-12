#include "Oraculo.hpp"
#include "Arbol.h"
#include <iostream>
#include <fstream>

std::string preDot(std::string str0)
{
	int pre = str0.find("\"[")+1;
	int post = str0.find("]\"");

	std::string str = str0.substr(pre,post-pre);
	return str;
}

std::string posDot(std::string str0)
{
	int pre = str0.rfind("\"[")+1;
	int post = str0.rfind("]\"");

	std::string str = str0.substr(pre,post-pre);
	return str;
}

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
	Nodo* aux_padre=padre;
	vector myr;
	bool mayor007 = false;
	vector marcado007;



	//******************************************************

	if(padre!=NULL)
	{
		while(aux_padre!=NULL)
		{
			if(marcado0 >= aux_padre->getMarcado())
			{
				mayor007=true;
				marcado007=aux_padre->getMarcado();
			}
			aux_padre=aux_padre->getPadre();
		}


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
					if(marcado0.get(j)>maximus && padre->getMarcado().get(j)>maximus)
					{
						std::cout<<"maximusssssss:   "<<maximus<<std::endl;
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
		if(mayor007)
		{
			vector omega;
			omega = marcado0.mayor(marcado007);
			lala->addMyr(omega);
		}
		return lala;
	}
	else
	{
		Nodo *nuevo = new Nodo(max_disparos,marcado0);
		_Nodos nodo_nuevo;
		nodo_nuevo.VECTOR = marcado0;
		nodo_nuevo.NODO = nuevo;
		nodos.push_back(nodo_nuevo);
		if(padre!=NULL && mayor007)
		{
			vector omega;
			omega = marcado0.mayor(marcado007);
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
	std::vector<_Nodos>::iterator i2;
	Nodo* aux;
	std::string myfile;
	//myfile+="digraph G {\n";
	for(i2=nodos.begin();i2!=nodos.end();i2++)
	{
			aux = i2->NODO;
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
				for(int i=0;i<vectorAux.size();i++)
				{
					if(0)//aux->getMyr().get(i) == 1)
					{
						myfile+="w ";
					}
					else
					{
						myfile+=vectorAux.get(i)+'0';
						myfile+=" ";
					}
				}
				//myfile+=vectorAux.get(vectorAux.size()-1)+'0';
				myfile+="]\"";

				//imprimo intermedio
				myfile+=" -> ";

				//imprimo marca hijo
				myfile+="\"[ ";				

				if(hijo->getPadre()!=NULL && hijo->getPadre()->getMarcado() == aux->getMarcado())
				{
					/*if(hijo->getMyr().zeros())
					{
						for(int i=0;i<vectorAux.size()-1;i++)
						{
							myfile[(i*2)+3]=vectorAux.get(i)+'0';
							//myfile+=" ";
						}
					}*/
					for(int i=0;i<vectorHijo.size();i++)
					{

						if(0)//hijo->getMyr().get(i) == 1 || aux->getMyr().get(i) == 1)
						{
							myfile+="w ";
						}
						else
						{
							myfile+=vectorHijo.get(i)+'0';
							myfile+=" ";
						}
					}
				}
				else
				{
					for(int i=0;i<vectorHijo.size();i++)
					{
						if(0)//hijo->getPadre()!=NULL&&(hijo->getPadre())->getMyr().get(i) == 1 || aux->getMyr().get(i) == 1)
						{
							myfile+="w ";
						}
						else
						{
							myfile+=vectorHijo.get(i)+'0';
							myfile+=" ";
						}
					}
				}
				//myfile+=vectorHijo.get(vectorHijo.size()-1)+'0';
				myfile+="]\"";
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
				str0--;
			}
			if(str+1==myfile0.end())
				break;
		}
	}

	while(myfile0.front()=="")
	{
		if(myfile0.front()=="")
		{
			myfile0.erase(myfile0.begin());
		}
	}

	std::vector<std::string>::iterator i;
	std::vector<std::string>::iterator j;
	//for (int k = 0; k < myfile0.size(); ++k)
	//{
		for (i=myfile0.begin() ; i!=myfile0.end(); ++i)
		{
			int tam = myfile0.size();
			int cont007 = 0;
			std::string pre_dot = preDot(*i);
			for (j=myfile0.begin() ; j!=myfile0.end(); ++j)
			{
				if(pre_dot!=posDot(*j))
				{
					cont007++;
				}
			}		
			if(cont007>=tam && pre_dot!=preDot(myfile0.front()))
			{
				myfile0.erase(i);
				i--;
			}

		}	
	//}


	//std::vector<std::string>::iterator i;
	//std::vector<std::string>::iterator j;
	//for (int k = 0; k < myfile0.size(); ++k)
	//{
	int iii;
	for (i=myfile0.begin(),iii=0 ; i!=myfile0.end(); ++i,iii++)
	{
		int tam = myfile0.size();
		int cont007 = 0;
		std::string pre_dot = preDot(*i);
		for (j=myfile0.begin() ; j!=i; ++j)
		{
			if(pre_dot!=posDot(*j))
			{
				cont007++;
			}
		}		
		if(cont007>=iii && pre_dot!=preDot(myfile0.front()))
		{
			myfile0.erase(i);
			i--;
			iii--;
		}

	}	
	//}


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
