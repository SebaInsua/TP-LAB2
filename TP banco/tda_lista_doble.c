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
nodoDoble* crearNodoDoble       (Cliente aux);
nodoDoble* agregarAlPpioDoble   (nodoDoble*lista,nodoDoble*nuevo_nodo);
nodoDoble* agregarAlFinalDoble  (nodoDoble*lista,nodoDoble*nuevo_nodo);
nodoDoble* buscarUltimoDoble    (nodoDoble*lista);
nodoDoble* agregarOrdenDoble    (nodoDoble*lista,nodoDoble*nuevo_nodo);
nodoDoble* eliminarNodoDoble    (nodoDoble*lista,char nombre_borrar[]);
void mostrarNodo                (Cliente aux);
void mostrarListaDoble          (nodoDoble* lista);
///PROTOTIPADO TDA FILA
