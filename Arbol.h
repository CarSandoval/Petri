#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "Vector.h"
#include "Oraculo.hpp"
#include "Nodos.hpp"

class arbol
{
    private:
        vector marcado_aux;
        vector maximo;
        vector uno;
        
        bool repetido;
        int val_max;

        
    public:
        Oraculo* direccion;
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
        void check_t(Nodo* nodo);
        //void prueba(Nodo* arr[]);

	bool reiniciableAux(Nodo* aux);
	bool reiniciable();
    bool vivacidadAux(Nodo* nodo);
    bool vivacidad();
	bool getAcotado();
	static void imprimirVec(vector a);


};

#endif // ARBOL_H_INCLUDED
