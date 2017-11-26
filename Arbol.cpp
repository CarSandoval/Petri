#include <iostream>
#include "Arbol.h"
#include "Nodos.hpp"
//#include "Vector.h"
//#include "Oraculo.h"

arbol::arbol()
{
	n=0;
    m=0;
}

arbol::arbol(int* marcado, int t, int p)
{
	//Transiciones
	n=t;

    //Lugares
    m=p;
    int* aux = new int[p];
    pre = new vector[t];
    post = new vector[t];

    //Vector con marcado inicial
    marcadoI = new vector(marcado,p); 

    //Nodo Padre
    std::cout << "Aqui nodos";
    raiz = new Nodo(t,marcadoI);
    std::cout << "Aqui nodos";
    // Creación de arreglo de vectores PRE
    for (int i = 0; i < t; ++i)
    {
        std::cout << "Pre T " << i;
        for (int j = 0; j < p; ++j)
        {
            std::cin >> aux[j];
        }
        pre[i]=new vector(aux,p);
    }

    // Creación de arreglo de vectores POST
    for (int i = 0; i < t; ++i)
    {
        std::cout << "Post T " << i;
        for (int j = 0; j < p; ++j)
        {
            std::cin >> aux[j];
        }
        post[i]=new vector(aux,p);
    }

    check_t(raiz);
    //check_t(marcadoI);


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

    //delete pre;
    //delete post;
}

arbol::~arbol()
{
    
}

arbol::check_t(Nodo* nodo){
    int aux=1;
    //Marcado tipo vector auxiliar
    vector marcado_aux;
    //vector marcado =  nodo->getMarcado();
    for (int i = 0; i < n; ++i)
    {
        marcado_aux = nodo->getMarcado();
        aux=1;
        for (int j = 0; j < m; ++j)
        {
            //Hay un valor en pre para el lugar "i"
            if (pre[i].get(j)>0)
            {
                //Encuentra el caso en el que no se puede activar alguna T
                //if (pre[i].get(j)>marcado.get(j))
                if (pre[i].get(j)>marcado_aux.get(j))
                {
                    aux=0;
                    break;
                }
            }
        }
        //Verifica si se puede disparar la transición "i"
        if (aux==1)
        {
            std::cout << "T" << i <<": Activa" << std::endl;
            //Calcula el nuevo etiquetado al activarse la transición "i"
            marcado_aux -= pre[i];
            marcado_aux += post[i];
            std::cout << "Marcado T" << i <<": " ;
            for (int k = 0; k < m; ++k)
            {
                std::cout << marcado_aux.get(k);
            }
            std::cout << std::endl;
        }
        //No se pudo activar la transición "i"
        else{
            std::cout << "T" << i <<": No activa" << std::endl;
        }
    }
}


/*
arbol::check_t(vector marcado){
    std::cout << std::endl << std::endl << "MARCADO Nuevo"<<std::endl ;
    int aux=1;
    //Marcado tipo vector auxiliar
    vector marcado_aux;
    //vector marcado =  nodo->getMarcado();
    for (int i = 0; i < n; ++i)
    {
        marcado_aux = marcado;
        aux=1;
        for (int j = 0; j < m; ++j)
        {
            //Hay un valor en pre para el lugar "i"
            if (pre[i].get(j)>0)
            {
                //Encuentra el caso en el que no se puede activar alguna T
                if (pre[i].get(j)>marcado_aux.get(j))
                {
                    aux=0;
                    break;
                }
            }
        }
        //Verifica si se puede disparar la transición "i"
        if (aux==1)
        {
            std::cout << "T" << i <<": Activa" << std::endl;
            //Calcula el nuevo etiquetado al activarse la transición "i"
            marcado_aux -= pre[i];
            marcado_aux += post[i];
            std::cout << "Marcado T" << i <<": " ;
            for (int k = 0; k < m; ++k)
            {
                std::cout << marcado_aux.get(k);
            }
            std::cout << std::endl;
            check_t(marcado_aux);
        }
        //No se pudo activar la transición "i"
        else{
            //std::cout << "T" << i <<": No activa" << std::endl;
        }
    }
}*/