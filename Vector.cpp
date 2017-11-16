#include "Vector.h"

vector::vector()
{
    tamano = 0;
    data = NULL;
}

vector::vector(int* value, int n)
{
    tamano = n;
    data = new int[tamano];
    for(int i=0;i<tamano;i++)
    {
        data[i] = value[i];
    }
}

vector::set(int i, int value){}

int vector::size()
{
 return tamano;
}

vector::~vector()
{
    delete[] data;
}

vector




