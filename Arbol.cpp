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
    vector vaux;

    pre = new vector();

    for (int i = 0; i < t; ++i)
    {
        std::cout << "Pre T " << i;
        for (int j = 0; j < p; ++j)
        {
            std::cin >> aux[j];
        }
        vaux= new vector(aux,p);
        pre = &vaux;
    }


    for (int i = 0; i < pre->size(); ++i)
    {
        std::cout << pre->size();
    }

	/*vector* pre;
    vector* post;

    post = new vector;
    pre = new vector;

    delete post;
    delete pre;*/
}

arbol::~arbol()
{
    
}
