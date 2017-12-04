#include <iostream>
#include "Arbol.h"
//#include "Nodos.hpp"
//#include "Vector.h"
//#include "Oraculo.hpp"

arbol::arbol()
{
	n=0;
    m=0;
}

arbol::arbol(int* marcado, int t, int p)
{
    //Hijos pendientes
    //Nodo* arr_hijos[n];

	//Transiciones
	n=t;

    //Lugares
    m=p;
    
    int* aux = new int[p];

    //Arreglo auxiliar para calcular el marcado maximo
    int arr_max[m] = {0};
    int unos[n];
    for (int i = 0; i < n; ++i)
    {
        unos[i]=1;
    }
    uno = new vector(unos,n);
    //std::cout <<"Vector uno: "; 
    //  imprimirVec(uno);

    pre = new vector[t];
    post = new vector[t];

    //Vector con marcado inicial
    marcadoI = new vector(marcado,p); 

    //Nodo Padre
    //raiz = new Nodo(t,marcadoI);
    

    
    //std::cout << "Aqui nodos";
    // Creación de arreglo de vectores PRE
    for (int i = 0; i < t; ++i)
    {
        std::cout << "Pre T " << i;
        for (int j = 0; j < p; ++j)
        {
            std::cin >> aux[j];
	    //getline(std::cin, aux[j]);
        }
        pre[i]=new vector(aux,p);
    }

    // Creación de arreglo de vectores POST
    for (int i = 0; i < t; ++i)
    {
        std::cout << "Post T " << i;
        for (int j = 0; j < p; ++j)
        {
            std::cin >> aux[j];
	    //getline(std::cin,aux[j]);
        }
        post[i]=new vector(aux,p);
    }

    //Obtener marcado maximo del arreglo pre
    for (int i = 0; i < m; ++i)
    {
        //arr_max[i] = pre[i].get(0);
        for (int j = 0; j < n; ++j)
        {
            if (pre[j].get(i)>arr_max[i])
            {
                arr_max[i] = pre[j].get(i) + 1;
            }
        }
    }


    //Vector con los valores maximos
    maximo = new vector(arr_max,m);

    //Obtiene el entero maximo de pre, el valor maximo que puede tener un place
    val_max=0;
    for (int i = 0; i < m; ++i)
    {
        if (arr_max[i] > val_max)
        {
            val_max=arr_max[i];
        }
    }



    direccion = new Oraculo(marcadoI,t, val_max);

    raiz = direccion->consulta(marcadoI, NULL, &repetido);
        //std::cout << "Bandera" << std::endl;
    //std::cout << "Marcado Maximo: " << val_max;
            //marcado2 = raiz->getMarcado();
            /*for (int k = 0; k < m; ++k)
            {
                std::cout << maximo.get(k);
            }*/
      //      std::cout << std::endl;

/*
    std::cout << "Marcado Maximo: " ;
            marcado2 = raiz->getMarcado();
            for (int k = 0; k < m; ++k)
            {
                std::cout << marcado2.get(k);
            }
            std::cout << std::endl;*/


    //int arr[m]={0};
    //marcado_aux = new vector(arr, m);
    vector marcado3;

    /*for (int i = 0; i < m; ++i)
    {
        std::cout<<"Marcado aux: " << marcado_aux.get(i);
    }
    std::cout<<std::endl;*/

/*
    std::cout << "Marcado inicial Nodo: " ;
            marcado3 = raiz->getMarcado();
            for (int k = 0; k < m; ++k)
            {
                std::cout << marcado3.get(k);
            }
            std::cout << std::endl;
*/
    check_t(raiz);

}

arbol::~arbol()
{
    
}

void arbol::check_t(Nodo* nodo){

    //Marcado tipo vector auxiliar
    marcado_aux = nodo->getMarcado();

    //arr_hijos = new Nodo[n];
/*
    std::cout << "Marcado inicial Nodo: " ;
    marcado3 = nodo->getMarcado();
    for (int k = 1; k < m; ++k)
        {
            std::cout << marcado3.get(k);
        }
    std::cout << std::endl;
*/  

    //int aux=1;

    //vector marcado =  nodo->getMarcado();
    for (int i = 0; i < n; ++i)
    {
        marcado_aux = nodo->getMarcado();
        if (pre[i]<=marcado_aux)
        {
            //std::cout << "T" << i <<": Activa" << std::endl;
            //Calcula el nuevo etiquetado al activarse la transición "i"
            marcado_aux -= pre[i];
            marcado_aux += post[i];
            //std::cout << "Marcado T" << i <<": " ;
            /*for (int k = 0; k < m; ++k)
            {
                std::cout << marcado_aux.get(k)<<",";
            }
            std::cout << std::endl;*/
            
            repetido = false;
            Nodo* hijo = direccion->consulta(marcado_aux,nodo,&repetido);
            
            //std::cout << "Hasta aqui" << std::endl;
            if (repetido)
            {
                nodo->setHijo(hijo,i);
                //std::cout << "T" << i <<": Repetido" << std::endl;
            }else{
                //arr_hijos[i] = hijo;
                hijo->setPadre(nodo);
                nodo->setHijo(hijo,i);
                //std::cout << "Hasta aqui2" << std::endl;
                //std::cout << "Padre e hijo relacionados " << i << std::endl ;
                
                check_t(hijo);
                
            }
        }
        
        //No se pudo activar la transición "i"
        else{
            //std::cout << "T" << i <<": No activa" << std::endl;

        }
        //prueba(arr_hijos);
        marcado_aux = nodo->getMarcado();
    }
}
/*
void arbol::prueba(Nodo* arr[]){
    for (int i = 0; i < n; ++i)
    {
    }
    //prueba();
}*/

//aux=1;
        /*
        for (int j = 0; j < m; ++j)
        {
            //Hay un valor en pre para el lugar "i"
            if (pre[i].get(j)>0)
            {
                //Encuentra el caso en el que no se puede activar alguna T
                if (pre[i].get(j)>marcado_aux.get(j))
                {
                    aux=0;
                    break;
                }
            }
        }*/
        //Verifica si se puede disparar la transición "i"
        /*if (aux==1)
        {

            std::cout << "T" << i <<": Activa" << std::endl;
            //Calcula el nuevo etiquetado al activarse la transición "i"
            marcado_aux -= pre[i];
            marcado_aux += post[i];
            std::cout << "Marcado T" << i <<": " ;
            for (int k = 0; k < m; ++k)
            {
                std::cout << marcado_aux.get(k);
            }
            std::cout << std::endl;
            std::cout << "Hasta aqui" << std::endl;
            Nodo* hijo = direccion->consulta(marcado_aux,&repetido);

            if (repetido)
            {
                nodo->setHijo(hijo,i);
                std::cout << "T" << i <<": Reetido" << std::endl;
                return;
            }else{

                hijo->setPadre(nodo);

                nodo->setHijo(hijo,i);
                std::cout << "Hasta aqui2" << std::endl;
                std::cout << "Padre e hijo relacionados " << i << std::endl ;
                marcado_aux = nodo->getMarcado();

                check_t(hijo);
            }
        }*/


/*
arbol::check_t(vector marcado){
    std::cout << std::endl << std::endl << "MARCADO Nuevo"<<std::endl ;
    int aux=1;
    //Marcado tipo vector auxiliar
    vector marcado_aux;
    //vector marcado =  nodo->getMarcado();
    for (int i = 0; i < n; ++i)
    {
        marcado_aux = marcado;
        aux=1;
        for (int j = 0; j < m; ++j)
        {
            //Hay un valor en pre para el lugar "i"
            if (pre[i].get(j)>0)
            {
                //Encuentra el caso en el que no se puede activar alguna T
                if (pre[i].get(j)>marcado_aux.get(j))
                {
                    aux=0;
                    break;
                }
            }
        }
        //Verifica si se puede disparar la transición "i"
        if (aux==1)
        {
            std::cout << "T" << i <<": Activa" << std::endl;
            //Calcula el nuevo etiquetado al activarse la transición "i"
            marcado_aux -= pre[i];
            marcado_aux += post[i];
            std::cout << "Marcado T" << i <<": " ;
            for (int k = 0; k < m; ++k)
            {
                std::cout << marcado_aux.get(k);
            }
            std::cout << std::endl;
            check_t(marcado_aux);
        }
        //No se pudo activar la transición "i"
        else{
            //std::cout << "T" << i <<": No activa" << std::endl;
        }
    }
}*/

bool arbol::getAcotado()
{
	return direccion->getAcotado();
}

bool arbol::reiniciableAux(Nodo* aux)
{
    int null_reini=0;
	//para saber si sigue siendo verdad
	static bool bandera = true;
	//std::cout<<"marcado: ";
	//imprimirVec(aux->getMarcado());
	//std::cout<<aux->getExplorado(aux->getMarcado());
	

	//para saber si sigo teniendo posibilidad de reiniciabilidad
	if(!bandera)
	{
		//return false;
	}

	for(int i=0;i<(this->n);i++)
	{
		//std::cout<<"Estoy en el ciclo "<<i<<"\n";
		//variable para hijo temporal		
		Nodo* hijo;		
		
		//marco explorado el nodo	
		aux->setExplorado(aux->getMarcado(),true);
		

		//si no tengo hijo i
		if((aux->getHijos())[i]==NULL)
		{
			continue;
		}
		
		//obtengo el hijo correspondiente y lo asigno a hijo
		hijo = (aux->getHijos())[i];
		
		//si mi hijo tiene solucion y lo sabe, yo tengo solucion
		if(hijo->getCiclo())
		{
			aux->setCiclo(true);
			//return bandera;
		}

        if (hijo->getMarcado()==raiz->getMarcado())
        {
            aux->setCiclo(true);
            raiz->setCiclo(true);
        }
		
		//si ya habia explorado a mi hijo
		if(aux->getExplorado(hijo->getMarcado()))
		{
			continue;
		}
		
		//sino, exploro a mi hijo
		if(reiniciableAux((aux->getHijos())[i]))
		{
			aux->setCiclo(true);
			//return bandera;			
		}
		
	}
    /*std::cout<<"Marcado Actual: ";
    imprimirVec(aux->getMarcado());
    std::cout << std::endl;
    std::cout << "Ciclico? :" << aux->getCiclo() <<std::endl;*/
	for(int i=0;i<this->n;i++)
	{
		//si no tengo hijo i
		if((aux->getHijos())[i]==NULL)
		{
            null_reini++;
			continue;
		}
		Nodo* hijo;
		//obtengo el hijo correspondiente y lo asigno a hijo
		hijo = (aux->getHijos())[i];
		if(hijo->getCiclo()==false)
		{
			bandera = false;
            /*std::cout<<"Retorno FALSO: ";
            imprimirVec(hijo->getMarcado());*/
			return false;
		}
		
	}
	//si no tengo posibilidades de vivacidad
	//bandera = false;
    if (null_reini == n)
    {
        return false;
    }
	return true;
}

bool arbol::reiniciable()
{
	//std::cout<<"Comence1\n";
	return reiniciableAux(raiz);
	//std::cout<<"fincalice1\n";
}

void arbol::imprimirVec(vector a)
{
	for(int i=0;i<a.size();i++)
	{
		std::cout<<a.get(i)<<",";
	}
	std::cout<<"\n";
}


bool arbol::vivacidadAux(Nodo* aux)
{
    int null_cont=0;
    //para saber si sigue siendo verdad
    static bool bandera = true;
    //std::cout<<"marcado: ";
    //imprimirVec(aux->getMarcado());
    //std::cout<<aux->getExploradoVivo(aux->getMarcado())<<std::endl;

    //std::cout<<"marcado diparos papa: ";
    //imprimirVec(aux->getDisparos());
    //std::cout<<aux->getExploradoVivo(aux->getMarcado())<<std::endl;
    

    //para saber si sigo teniendo posibilidad de reiniciabilidad
    if(!bandera)
    {
        //return false;
    }

    for(int i=0;i<(this->n);i++)
    {
        //std::cout<<"Estoy en el ciclo "<<i<<"\n";
        //variable para hijo temporal       
        Nodo* hijo;     
        
        //marco explorado el nodo   
        aux->setExploradoVivo(aux->getMarcado(),true);
        

        //si no tengo hijo i
        if((aux->getHijos())[i]==NULL)
        {
            continue;
        }
        
        //obtengo el hijo correspondiente y lo asigno a hijo
        hijo = (aux->getHijos())[i];

        //std::cout<<"marcado hijo  "<<i<<": ";
        //imprimirVec(hijo->getDisparos());
        aux->setDisparos(aux->getDisparos() + hijo->getDisparos());

        //std::cout<<"marcado suma  "<<i<<": ";
        //imprimirVec(aux->getDisparos());
        //si mi hijo tiene solucion y lo sabe, yo tengo solucion
        if(hijo->getVivo())
        {
            //std::cout << "Entre 1" << std::endl;
            aux->setVivo(true);
            //return bandera;
        }
        if (aux->getDisparos()>=uno)
        {
            aux->setVivo(true);
        }
        
        //std::cout << "Lista de vivacidad: " << std::endl;
        //list::imprimir();
        //si ya habia explorado a mi hijo
        if(aux->getExploradoVivo(hijo->getMarcado()))
        {
            //std::cout << "Entre 2" << std::endl;
            continue;
        }
        
        //sino, exploro a mi hijo
        if(vivacidadAux((aux->getHijos())[i]))
        {
            //std::cout << "Entre 3" << std::endl;
            hijo->setVivo(true);
            aux->setVivo(true);
            //return bandera;           
        }
        aux->setDisparos(aux->getDisparos() + hijo->getDisparos());
        if (aux->getDisparos()>=uno)
        {
            aux->setVivo(true);
        }
        
    }
    for(int i=0;i<this->n;i++)
    {
        //si no tengo hijo i
        if((aux->getHijos())[i]==NULL)
        {
            null_cont++;
            continue;
        }
        Nodo* hijo;
        //obtengo el hijo correspondiente y lo asigno a hijo
        hijo = (aux->getHijos())[i];
        /*std::cout << "Marcado :";
        imprimirVec(hijo->getMarcado());
        imprimirVec(hijo->getDisparos());
        imprimirVec(uno);
        std::cout << "Vivo? :" <<hijo->getVivo() << std::endl;*/
        if(hijo->getVivo()==false)
        {
            /*std::cout<<"Marcado FALSO: ";
            imprimirVec(hijo->getMarcado());*/
            bandera = false;
            return false;
        }
        
    }
    if (null_cont == n)
    {
        //std::cout<<"Marcado no vivo: ";
        //imprimirVec(aux->getMarcado());
        return false;
    }
    //si no tengo posibilidades de vivacidad
    //bandera = false;
    return true;
}

bool arbol::vivacidad()
{
    //std::cout<<"Vivacidad inicio\n";
    return vivacidadAux(raiz);
    //std::cout<<"Vivacidad final\n";
}
