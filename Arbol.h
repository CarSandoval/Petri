#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "Vector.h"
#include "Nodos.hpp"

class arbol
{
    private:
        //int* data;
        //int tamano;
        
    public:
        //nodo raiz;
        int n;
        vector* pre, post;
        
        arbol();
        arbol(int* marcado, int t, int p);
        //void set(int i);
        //void get(int i);
        //int size();
        ~arbol();

};

#endif // ARBOL_H_INCLUDED