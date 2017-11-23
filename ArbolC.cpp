#include <iostream>
#include "ArbolC.h"
//#include "Nodo.h"
#include "Vector.h"
//#include "Oraculo.h"

bool arbol::reiniciableAux(Nodo* aux)
{
	//para saber si sigue siendo verdad
	static bool bandera = true;

	//para saber si sigo teniendo posibilidad de reiniciabilidad
	if(!bandera)
	{
		return false;
	}

	for(int i=0;i<(this->n);i++)
	{
		//variable para hijo temporal		
		Nodo* hijo;		
		
		//marco explorado el nodo	
		aux->setExplorado(aux->getMarcado(),true);
		

		//si no tengo hijo i
		if((aux->getHijos())[i]==NULL)
		{
			continue;
		}

		//obtengo el hijo correspondiente y lo asigno a hijo
		hijo = (aux->getHijos())[i];

		//si mi hijo tiene solucion y lo sabe, yo tengo solucion
		if(hijo->getCiclo() || hijo->getMarcado()==raiz->getMarcado())
		{
			aux->setCiclo(true);
			return true;
		}

		//si ya habia explorado a mi hijo
		if(aux->getExplorado(hijo->getMarcado()))
		{
			continue;
		}

		//sino exploro a mi hijo
		if(reiniciableAux((aux->getHijos())[i]))
		{
			aux->setCiclo(true);
			return true;			
		}
		
	}
	//si no tengo posibilidades de vivacidad
	bandera = false;
	return false;
}

bool arbol::reiniciable()
{
	reiniciableAux(raiz);
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

arbol::arbol()
{
	n=0;
}

arbol::arbol(int* marcado, int t, int p)
{
	
	n=t;
    int* aux = new int[p];
    vector v1;
    vector v2;
    pre = new vector[t];
    post = new vector[t];

    //Vector con marcado inicial
    marcadoI = new vector(marcado,p);

    //Nodo Padre
    raiz = new Nodo(t,marcadoI);

    // Creación de arreglo de vectores PRE
    for (int i = 0; i < t; ++i)
    {
        std::cout << "Pre T " << i;
        for (int j = 0; j < p; ++j)
        {
            std::cin >> aux[j];
        }
        v1=new vector(aux,p);
        pre[i]=v1;
    }

    // Creación de arreglo de vectores POST
    for (int i = 0; i < t; ++i)
    {
        std::cout << "Post T " << i;
        for (int j = 0; j < p; ++j)
        {
            std::cin >> aux[j];
        }
        v2=new vector(aux,p);
        post[i]=v2;
    }


    //std::cout << "Size: "<< pre->size()<< std::endl;
    /*for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < t; ++j)
        {
           std::cout << pre[j].get(i); 
        }
        std::cout  << std::endl;
        
    }

    std::cout << std::endl;
    for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < t; ++j)
        {
           std::cout << post[j].get(i); 
        }
        std::cout  << std::endl;
        
    }*/


	/*vector* pre;
    vector* post;

    post = new vector;
    pre = new vector;

    delete post;
    */
    //delete pre;
    //delete post;
}

arbol::~arbol()
{
    
}
