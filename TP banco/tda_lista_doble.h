#ifndef TDA_LISTA_DOBLE_H_INCLUDED
#define TDA_LISTA_DOBLE_H_INCLUDED

typedef struct{
    char nombre_cajero[10];
    int numero_caja;
}Caja;
typedef struct{
    Cliente cliente;
    struct nodoDoble*anterior;
    struct nodoDoble*siguiente;
}nodoDoble;
typedef struct{
    Caja dato;
    nodoDoble*cabecera;
    nodoDoble*cola;
}Fila;

///PROTOTIPADO CAJA
Caja cargar_caja ();
void mostrar_caja(Caja aux);
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

#endif // TDA_LISTA_DOBLE_H_INCLUDED
