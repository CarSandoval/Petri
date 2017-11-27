#include <iostream>
#include "Vector.h"

using namespace std;

vector regresa()
{
	static vector resp = *(new vector(2,3));
	//static vector resp;
	//resp = new vector(2,3);
	return resp;
}

int main()
{
	vector a,b,c,d,e,f,g;
	int aux[] = {1,2,3};
	int aux2[] = {2,3,4};

	//prueba de igualdad
	a = new vector(aux,3);
	aux[0]=2; aux[1]=3; aux[2]=4;
	b = new vector(aux,2);

	cout<<a.get(0)<<","<<a.get(1)<<","<<a.get(2)<<endl;
	cout<<b.get(0)<<","<<b.get(1)<<","<<b.get(2)<<endl;

	//prueba de la suma y la igualdad
	cout<<"suma de vectores"<<endl;
	c = a+b;
	cout<<c.get(0)<<","<<c.get(1)<<","<<c.get(2)<<endl;

	//prueba de la diferencia y la igualdad
	cout<<"diferencia de vectores"<<endl;
	c = a-b;
	cout<<c.get(0)<<","<<c.get(1)<<","<<c.get(2)<<endl;

	//prueba del producto y la igualdad
	cout<<"producto de vectores"<<endl;
	c = a*b;
	cout<<c.get(0)<<","<<c.get(1)<<","<<c.get(2)<<endl;

	//prueba de la suma += y la igualdad
	cout<<"suma con a"<<endl;
	c += a;
	cout<<c.get(0)<<","<<c.get(1)<<","<<c.get(2)<<endl;

	//prueba de la diferencia -= y la igualdad
	cout<<"suma con a"<<endl;
	c -= a;
	cout<<c.get(0)<<","<<c.get(1)<<","<<c.get(2)<<endl;

	//pruebas de mayorizacion
	cout<<(a<b)<<endl;
	cout<<(a>b)<<endl;
	cout<<(a<=b)<<endl;
	cout<<(a>=b)<<endl;

	//impresiones de los vectores finales
	cout<<"vectores finales"<<endl;
	cout<<a.get(0)<<","<<a.get(1)<<","<<a.get(2)<<endl;
	cout<<b.get(0)<<","<<b.get(1)<<","<<b.get(2)<<endl;
	cout<<c.get(0)<<","<<c.get(1)<<","<<c.get(2)<<endl;


	//prueba de construccion de vector 1	
	
	d = new vector(1,3);
	cout<<d.get(0)<<","<<d.get(1)<<","<<d.get(2)<<endl;

	//prueba con arreglos
	cout<<"prueba con arreglos:::::::::"<<endl;
 	vector* listVec;
	listVec = new vector[2];
	listVec[0] = new vector(aux, 3);
	aux[0]=2; aux[1]=3; aux[2]=4;
	listVec[1] = new vector(aux,3);
	cout<<listVec[0].get(0)<<","<<listVec[0].get(1)<<","<<listVec[0].get(2)<<endl;
	cout<<listVec[1].get(0)<<","<<listVec[1].get(1)<<","<<listVec[1].get(2)<<endl;

	//copia de copia;
	cout<<"puebas extensivasl del igual"<<endl;
	int aux4[] = {3,4,5};
	int aux5[] = {6,7,8};
	b = new vector(aux4,3);
	b = new vector(aux5,3);
	b = regresa();
	cout<<b.get(0)<<","<<b.get(1)<<","<<b.get(2)<<endl;
	a = regresa();
	cout<<a.get(0)<<","<<a.get(1)<<","<<a.get(2)<<endl;
	e = regresa();
	cout<<e.get(0)<<","<<e.get(1)<<","<<e.get(2)<<endl;
	f = a;
	cout<<f.get(0)<<","<<f.get(1)<<","<<f.get(2)<<endl;
	return 0;
}
