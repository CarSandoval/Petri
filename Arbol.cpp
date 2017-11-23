#include <iostream>
#include "Arbol.h"
//#include "nodo.h"
#include "Vector.h"


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
    for (int i = 0; i < p; ++i)
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
        
    }

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
