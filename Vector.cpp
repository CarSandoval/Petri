#include "Vector.h"
#include <iostream>


//:::::::::constructores
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

vector::vector(int n, int tam)
{
	tamano = tam;
	data = new int[tamano];
	for(int i=0;i<tamano;i++)
	{
		data[i]=0;
	}
	data[n] = 1;
}


//:::::::set, Get and Size
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

//:::::::::::::descturctor
vector::~vector()
{
    //delete[] data;
}

//:::::::::::::operadores escenciales
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

void vector::operator=(vector* v1)
{
	delete []data;
	tamano = v1->tamano;
	//data = v1->data;
	data = new int[tamano];
	
	
	for(int i=0;i<tamano;i++)
	{
		data[i]=v1->data[i];
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


//::::::::::::::::operadores extras

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

///::::::::::::::condiciones de mayorizacion

bool vector::operator >=(const vector &v1)
{
	for(int i=0;i<tamano;i++)
	{
		if(data[i]<v1.data[i])
		{
			return false;
		}	
	}
	return true;
}

bool vector::operator >(const vector &v1)
{
	int contMI, contM;
	contMI = contM = 0;
	for(int i=0;i<tamano;i++)
	{
		if(data[i]>=v1.data[i])
		{
			contMI++;
		}
		if (data[i]>v1.data[i])
		{
			contM++;
		}
		/*
		if(data[i]<=v1.data[i])
		{
			return false;
		}
		*/	
	}
	if (contMI == tamano && contM>0)
	{
		return true;
	}else
	{
		return false;
	}
}

bool vector::operator <=(const vector &v1)
{
	for(int i=0;i<tamano;i++)
	{
		if(data[i]>v1.data[i])
		{
			return false;
		}	
	}
	return true;
}

bool vector::operator <(const vector &v1)
{
	int contMI, contM;
	contMI = contM = 0;
	for(int i=0;i<tamano;i++)
	{
		if(data[i]<=v1.data[i])
		{
			contMI++;
		}
		if (data[i]<v1.data[i])
		{
			contM++;
		}
		/*
		if(data[i]<=v1.data[i])
		{
			return false;
		}
		*/	
	}
	if (contMI == tamano && contM>0)
	{
		return true;
	}else
	{
		return false;
	}
}

bool vector::operator ==(const vector &v1)
{
	for(int i=0;i<tamano;i++)
	{
		if(data[i]!=v1.data[i])
		{
			return false;
		}	
	}
	return true;
}

//::::::::::::operadores agenos a la clase::::::::::::


bool operator >=(const vector &v0, const vector &v1)
{
	for(int i=0;i<v0.tamano;i++)
	{
		if(v0.data[i]<v1.data[i])
		{
			return false;
		}	
	}
	return true;
}

bool operator >(const vector &v0, const vector &v1)
{
	int contMI, contM;
	contMI = contM = 0;
	for(int i=0;i<v0.tamano;i++)
	{
		if(v0.data[i]>=v1.data[i])
		{
			contMI++;
		}
		if (v0.data[i]>v1.data[i])
		{
			contM++;
		}
		/*
		if(data[i]<=v1.data[i])
		{
			return false;
		}
		*/	
	}
	if (contMI == v0.tamano && contM>0)
	{
		return true;
	}else
	{
		return false;
	}
}

bool operator <=(const vector &v0, const vector &v1)
{
	for(int i=0;i<v0.tamano;i++)
	{
		if(v0.data[i]>v1.data[i])
		{
			return false;
		}	
	}
	return true;
}

bool operator <(const vector &v0, const vector &v1)
{
	int contMI, contM;
	contMI = contM = 0;
	for(int i=0;i<v0.tamano;i++)
	{
		if(v0.data[i]<=v1.data[i])
		{
			contMI++;
		}
		if (v0.data[i]<v1.data[i])
		{
			contM++;
		}
		/*
		if(data[i]<=v1.data[i])
		{
			return false;
		}
		*/	
	}
	if (contMI == v0.tamano && contM>0)
	{
		return true;
	}else
	{
		return false;
	}
}


bool operator ==(const vector &v0, const vector &v1)
{
	for(int i=0;i<v0.tamano;i++)
	{
		if(v0.data[i]!=v1.data[i])
		{
			return false;
		}	
	}
	return true;
}












