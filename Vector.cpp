#include "Vector.h"
#include <iostream>

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

void vector::set(int i, int value)
{
    data[i]=value;
}

int vector::get(int i)
{
    return data[i];
}

int vector::size()
{
 return tamano;
}


vector::~vector()
{
    delete[] data;
}

void vector::operator=(const vector &v1)
{
	delete []data;
	tamano = v1.tamano;
	data = new int[tamano];
	for(int i=0;i<tamano;i++)
	{
		data[i]=v1.data[i];
	}
}

vector& vector::operator*(const vector &v1)
{

	vector* resp = new vector(v1.data,v1.tamano);

	for(int i=0;i<tamano;i++)
	{
		resp->data[i]*=data[i];
	}

	return *resp;
}

vector& vector::operator+(const vector &v1)
{

	vector* resp = new vector(v1.data,v1.tamano);

	for(int i=0;i<tamano;i++)
	{
		resp->data[i]+=data[i];
	}

	return *resp;
}

vector& vector::operator-(const vector &v1)
{

	vector* resp = new vector(v1.data,v1.tamano);

	for(int i=0;i<tamano;i++)
	{
		resp->data[i]-=data[i];
	}

	return *resp;
}

void vector::operator+=(const vector &v1)
{

	for(int i=0;i<tamano && i<v1.tamano;i++)
	{
		data[i]+= v1.data[i];
	}

}

void vector::operator-=(const vector &v1)
{

	for(int i=0;i<tamano && i<v1.tamano;i++)
	{
		data[i]-= v1.data[i];
	}

}

bool operator >=(const vector &v1)
{
	return false;
	for(int i=0;i<tamano;i++)
	{

	}
}











