#include "Pila.h"

///INICIAR PILA
void inicpila(nodo ** pila)
{
    (*pila)= inicLista();
}

///APILAR
void apilar(nodo ** pila, persona dato)
{
    nodo * aux= crearNodo(dato);
    (*pila)= agregarNodoAlPrincipio((*pila), aux);
}

///MOSTRAR
void mostrar(nodo ** pila)
{
    nodo * seg= (*pila);
    printf("\nTope--------------------------------------------\n\n");
    while(seg!=NULL)
    {
        printf("Nombre: %s\n", seg->dato.nombre);
        printf("Edad: %d\n\n", seg->dato.edad);
        seg=seg->siguiente;
    }
    printf("\nBase--------------------------------------------\n\n");
}

///LEER
void leer(nodo ** pila)
{
    (*pila)=cargarListaPrincipio(*pila);
}

///APILAR
persona tope (nodo ** pila)
{
    persona aux;
    aux= verPrimerNodo(*pila);
    return aux;
}

///PILA VACIA
int pilavacia(nodo ** pila)
{
    return *pila==NULL;
}

///DESAPILAR
persona desapilar(nodo ** pila)
{
    nodo * aux= desvincularPrimero(*&pila);

    return aux->dato;
}


///Otras funciones de Pilas
/*void intercalar(P_Pila p1,P_Pila p2,P_Pila p3)
{
       while (!pilavacia(p1) && !pilavacia(p2))
       {
               if(tope(p1)<tope(p2))
               {
                       apilar(p3, desapilar(p1));
               }
               else
               {
                       apilar(p3, desapilar(p2));
               }
       }
       if(!pilavacia(p1))
       {
               while(!pilavacia(p1))
               {
                       apilar(p3, desapilar(p1));
               }
       }
       else
  {
               while(!pilavacia(p2))
               {
                       apilar(p3, desapilar(p2));
               }
       }
}

void mover_pila(P_Pila p1, P_Pila p2)
{
    while(!pilavacia(p1)){
        apilar(p2,desapilar(p1));
    }
}

void copiar_pila(P_Pila p1, P_Pila p2, P_Pila p3)
{
    while(!pilavacia(p1)){
        apilar(p3,tope(p1));
        apilar(p2,desapilar(p1));
    }
    while(!pilavacia(p3)){
        apilar(p1,desapilar(p3));
    }
}

int suma_pila(P_Pila p1, P_Pila p2, int *suma)
{
    *suma=0;
    while(!pilavacia(p1)){
        *suma=*suma+tope(p1);
        apilar(p2,desapilar(p1));
    }
    mover_pila(p2,p1);
    return 0;
}

int cuenta_pila(P_Pila p1, P_Pila p2, int *cont)
{
    while(!pilavacia(p1)){
        *cont++;
        apilar(p2,desapilar(p1));
    }
    mover_pila(p2,p1);
    return 0;
}

void ordenar_pila(P_Pila p1, P_Pila p2, P_Pila p3)
{
    while(!pilavacia(p1)){
        apilar(p3,desapilar(p1));

        while(!pilavacia(p1)){
            if(tope(p1)<=tope(p3)){
                apilar(p2,desapilar(p3));
                apilar(p3,desapilar(p1));
            }
            else{
                apilar(p2,desapilar(p1));
            }
        }
        mover_pila(p2,p1);
    }
}*/
