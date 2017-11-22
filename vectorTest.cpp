#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
	vector a,b,c;
	int aux[] = {1,2,3};
	int aux2[] = {2,3,4};

	//prueba de igualdad
	a = new vector(aux,3);
	b = new vector(aux2,3);

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
	

	//impresiones de los vectores finales
	cout<<"vectores finales"<<endl;
	cout<<a.get(0)<<","<<a.get(1)<<","<<a.get(2)<<endl;
	cout<<b.get(0)<<","<<b.get(1)<<","<<b.get(2)<<endl;
	cout<<c.get(0)<<","<<c.get(1)<<","<<c.get(2)<<endl;

	
	
		

 

	return 0;
}
