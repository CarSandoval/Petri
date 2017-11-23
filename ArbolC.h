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
        Nodo* raiz;
        int n;
        vector* pre;
        vector* post;
        vector marcadoI;
        
        arbol();
        arbol(int* marcado, int t, int p);
        //void set(int i);
        //void get(int i);
        //int size();
        ~arbol();

	bool reiniciableAux(Nodo* aux);
	bool reiniciable();

};

#endif // ARBOL_H_INCLUDED
