#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include "tda_lista_simple.h"

/// PROTOTIPADO CLIENTE
Cliente cargaCliente (){
    Cliente aux;

    printf("------------CARGA CLIENTE--------\n");
    printf("Nombre: \n");
    fflush(stdin);
    scanf("%s",&aux.nombre);
    printf("Tipo: \n");
    printf("1-regular, 2-jubilado, 3-gestante,4-empresario \n");
    scanf("%d",&aux.tipo);
    printf("Cantidad de facturas: \n");
    scanf("%d",&aux.cantFacturas);
    return aux;
}
void mostrarCliente(Cliente aux){
    printf("Nombre: %s \n",aux.nombre);
    printf("Tipo: %d \n",aux.tipo);
    printf("Cantidad de facturas: %d \n",aux.cantFacturas);
}
/// PROTOTIPADO ARCHIVO
void cargaArchivo (char fileName[]){
    FILE*archivo=fopen(fileName,"ab");
    Cliente aux;
    char ctrl='s';
    if(archivo){
            do{
                aux=cargaCliente();
                fwrite(&aux,sizeof(Cliente),1,archivo);
                printf("Desea cargar mas clientes al archivo? s|n \n");
                fflush(stdin);
                scanf("%c",&ctrl);
            }while (ctrl=='s'|| ctrl=='S');
        fclose(archivo);
    }
}
void mostrarArchivo (char fileName[]){
    FILE*archivo=fopen(fileName,"rb");
    Cliente aux;
    if(archivo){
            printf("----------MUESTRA ARCHIVO----------\n");
            while(fread(&aux,sizeof(Cliente),1,archivo)>0){
                mostrarCliente(aux);
            }
        fclose(archivo);
    }
}
nodo* archivoToLista (char fileName[],nodo* lista){
    FILE*archivo=fopen(fileName,"rb");
    Cliente aux;
    nodo*nuevoNodo;
    if(archivo){
            while(fread(&aux,sizeof(Cliente),1,archivo)>0){
                nuevoNodo=crearNodo(aux);
                lista=insertarEnOrden(lista,nuevoNodo);
            }
        fclose(archivo);
    }
    return lista;
}
void listaToArchivo (char fileName[],nodo*lista);
/// FUNCIONES TDA_LISTAS_SIMPLES
nodo* inicLista ()
{
    return NULL;
}

nodo* crearNodo(Cliente aux)
{
    nodo* nuevoNodo = (nodo*) malloc (sizeof(nodo));
    nuevoNodo ->user = aux;
    nuevoNodo ->siguiente = NULL;
    return nuevoNodo;
}

nodo* agregarAlPpio(nodo*lista,nodo*nuevoNodo)
{
    if (lista)
    {
        nuevoNodo->siguiente = lista;
    }
    lista = nuevoNodo;
    return lista;
}

nodo* agregarAlFinal(nodo*lista,nodo*nuevoNodo)
{
    if (lista)
    {
        nodo* aux = lista;
        while (aux->siguiente)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevoNodo;
    }else{
        lista=nuevoNodo;
    }
    return lista;
}

nodo* insertarEnOrden(nodo*lista,nodo*nuevoNodo)
{
    if (lista)
    {
        nodo * aux = lista;
        if (strcmp(aux->user.nombre,nuevoNodo->user.nombre)>0)
        {
            lista = agregarAlPpio(lista,nuevoNodo);
        }else
        {
            nodo * ante = lista;
            nodo * seg = lista->siguiente;

            while (seg && (strcmp(seg->user.nombre,nuevoNodo->user.nombre)<0))
            {
                ante = seg;
                seg = seg ->siguiente;
            }
            ante->siguiente = nuevoNodo;
            nuevoNodo->siguiente = seg;
        }
    }else
    {
        lista = nuevoNodo;
    }
    return lista;
}

nodo* eliminarUnNodo(nodo*lista,char nombre[])
{
    if (lista)
    {
        nodo* aux = lista;
        if (strcmp(aux->user.nombre,nombre)==0)
        {
            nodo* aBorrar = lista;
            lista = lista->siguiente;
            free(aBorrar);
        }else
        {
            nodo* ante = lista;
            nodo * seg = lista ->siguiente;

            while (seg && (strcmp(seg->user.nombre,nombre)!=0))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}

void mostrarNodo(Cliente aux)
{
    mostrarCliente(aux);
}

void mostrarLista(nodo*lista)
{
    if (lista)
    {
        nodo* aux = lista;
        printf("--------------MUESTRA LISTA-----------\n");
        while (aux)
        {
            mostrarNodo(aux->user);
            aux = aux->siguiente;
        }
    }
}
