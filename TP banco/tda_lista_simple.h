#ifndef TDA_LISTA_SIMPLE_H_INCLUDED
#define TDA_LISTA_SIMPLE_H_INCLUDED

typedef struct
{
    char nombre[20];
    int tipo;
    int cantFacturas;
}Cliente;

typedef struct
{
    Cliente user;
    struct nodo* siguiente;
}nodo;
/// PROTOTIPADO CLIENTE
Cliente cargaCliente ();
void mostrarCliente(Cliente aux);

/// PEOTOTIPADO TDA_LISTA_SIMPLE --------
nodo* inicLista ();
nodo* crearNodo(Cliente aux);
nodo* agregarAlPpio(nodo*lista,nodo*nuevoNodo);
nodo* agregarAlFinal(nodo*lista,nodo*nuevoNodo);
nodo* insertarEnOrden(nodo*lista,nodo*nuevoNodo);
nodo* eliminarUnNodo(nodo*lista,char nombre[]);
void mostrarNodo(Cliente aux);
void mostrarLista(nodo*lista);

/// PROTOTIPADO ARCHIVO

void cargaArchivo (char fileName[]);
void mostrarArchivo (char fileName[]);
nodo* archivoToLista (char fileName[],nodo* lista);
void listaToArchivo (char fileName[],nodo*lista);

#endif // TDA_LISTA_SIMPLE_H_INCLUDED
