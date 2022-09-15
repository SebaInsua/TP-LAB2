#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include "tda_lista_doble.h"
#include "tda_lista_simple.h"

///PROTOTIPADO CAJA
Caja cargar_caja (){
    Caja aux;
    printf('-------------CARGA CAJA-------------\n');
    printf("Nombre cajero: \n");
    fflush(stdin);
    scanf("%s",&aux.nombre_cajero);
    printf("Numero de caja: \n");
    scanf("%d",&aux.numero_caja);
    return aux;
}
void mostrar_caja(Caja aux){
    printf("CAJA: \n");
    printf("Nombre cajero: %s\n",aux.nombre_cajero);
    printf("Numero de caja: \n",aux.numero_caja);
}
///PROTOTIPADO TDA lista-doble
nodoDoble* crearNodoDoble       (Cliente aux){
    nodoDoble*nuevo_nodo=(nodoDoble*) malloc (sizeof(nodoDoble));
    nuevo_nodo->cliente=aux;
    nuevo_nodo->anterior=NULL;
    nuevo_nodo->siguiente=NULL;
    return nuevo_nodo;
}
nodoDoble* agregarAlPpioDoble   (nodoDoble*lista,nodoDoble*nuevo_nodo){
    if(lista){
        nuevo_nodo->siguiente=lista;
        if(lista->siguiente){
            lista->anterior=lista;
        }
    }
    lista=nuevo_nodo;
    return lista;
}
nodoDoble* agregarAlFinalDoble  (nodoDoble*lista,nodoDoble*nuevo_nodo){
    if(lista){
        nodoDoble*ultimo=buscarUltimoDoble(lista);
        ultimo->siguiente=nuevo_nodo;
        nuevo_nodo->anterior=ultimo;
    }else{
        lista=nuevo_nodo;
    }
    return lista;
}
nodoDoble* buscarUltimoDoble    (nodoDoble*lista){
    if(lista){
       nodoDoble*ultimo=lista;
       while(ultimo){
        ultimo=ultimo->siguiente;
       }
    }
    return ultimo;
}
nodoDoble* agregarOrdenDoble    (nodoDoble*lista,nodoDoble*nuevo_nodo){
    if(lista){
        nodoDoble*aux=lista;
        if(strcmpi(aux->cliente.nombre,nuevo_nodo->cliente.nombre)>0){
            lista=agregarAlPpioDoble(lista,nuevo_nodo);
        }else{
            nodoDoble*ante=lista;
            nodoDoble*seg=lista->siguiente;
            while(seg && strcmpi(aux->cliente.nombre,nuevo_nodo->cliente.nombre)<0){
                ante=seg;
                seg=seg->siguiente;
            }
            if(seg){
                ante->siguiente=nuevo_nodo;
                nuevo_nodo->siguiente=seg;
                nuevo_nodo->anterior=ante;
                seg->anterior=nuevo_nodo;
            }else{
                lista=agregarAlFinal(lista,nuevo_nodo);
            }
        }
    }else{
        lista=nuevo_nodo;
    }
    return lista;
}
nodoDoble* eliminarNodoDoble    (nodoDoble*lista,char nombre_borrar[]){
    if(lista){
        if(strcmpi(aux->cliente.nombre,nombre_borrar)==0){
            nodoDoble*aBorrar=lista;
            lista=lista->siguiente;
            if(lista->siguiente){
                    nodoDoble*aux=lista->siguiente;
                aux->anterior=lista;
            }
            free(aBorrar);
        }else{
            nodoDoble*ante=lista;
            nodoDoble*seg=lista->siguiente;
            while(seg && strcmpi(aux->cliente.nombre,nombre_borrar)!=0 ){
                ante=seg;
                seg=seg->siguiente;
            }
            if(seg){
                ante->siguiente=seg->siguiente;
                nodoDoble*aux=seg->siguiente;
                aux->anterior=ante;
                free(seg);
            }else{
                printf("El dato a borrar no esta en la lista\n");
            }
        }
    }
    return lista;
}
void mostrarNodo                (Cliente aux){
    mostrarCliente(aux);
}
void mostrarListaDoble          (nodoDoble* lista){
    if(lista){
        nodoDoble*aux;
        while(aux){
            mostrarNodo(aux);
            aux=aux->siguiente;
        }
    }
}
///PROTOTIPADO TDA FILA
