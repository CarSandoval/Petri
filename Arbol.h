#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "Vector.h"

#include "Nodos.hpp"

class arbol
{
    private:
        
    public:
        Nodo* raiz;
        int n,m;
        vector* pre;
        vector* post;
        vector marcadoI;
        vector max;
        
        arbol();
        arbol(int* marcado, int t, int p);
        //void set(int i);
        //void get(int i);
        //int size();
        ~arbol();
        //check_t(vector marcado);
        check_t(Nodo* nodo);

};

#endif // ARBOL_H_INCLUDED