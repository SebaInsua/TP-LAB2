#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"

typedef struct _nodo
{
    persona dato;
    struct _nodo * siguiente;
} nodo;

nodo * inicLista();

nodo * crearNodo(persona nuevaPersona);

nodo * cargarListaPrincipio(nodo * lista);
nodo * cargarListaFinal(nodo * lista);
nodo * cargarListaOrdenada(nodo * lista);

void mostrarUnNodo(nodo * nuevo);
void recorrerYMostrar(nodo * lista);
persona verPrimerNodo(nodo * lista);

nodo * buscarUltimoNodo(nodo * lista);
nodo * eliminarUltimoNodo(nodo * lista);
nodo * buscarNodo(nodo * lista, char nombre[]);
nodo * buscarNodoPorInt(nodo * lista, int num); //Buscar nodo por edad
int buscarNodoTrueOrFalse(nodo * lista, char nombre[]); //Buscar nodo, retorna true o false

nodo * eliminarPrimerNodo(nodo * lista);
nodo * eliminarUltimoNodo(nodo * lista);
nodo * eliminarNodo(nodo * lista, char nombre[]);
nodo * eliminarNodoPorInt(nodo * lista, int num); //Eliminar nodo a partir de la edad
nodo * borrarTodaLaLista(nodo * lista);
nodo * desvincularPrimero(nodo ** lista);
nodo * borrarNodosSegunParametro(nodo * lista, int edadFiltro);

nodo * agregarNodoAlPrincipio(nodo * lista, nodo * nuevoNodo);
nodo * agregarNodoAlFinal(nodo * lista, nodo * nuevoNodo);
nodo * agregarNodoEnOrden(nodo * lista, nodo * nuevoNodo);
nodo * agregarNodoEnOrdenPorInt(nodo * lista, nodo * nuevoNodo); //Agregar en orden a traves de la edad
nodo * subprogramaAgregarPersonaEnListaPrincipio(nodo * lista, persona p);
nodo * subprogramaAgregarPersonaEnListaFinal(nodo * lista, persona p);
nodo * subprogramaAgregarPersonaEnListaOrdenada(nodo * lista, persona p);

int sumarIntNodos(nodo * lista);

nodo * subprogramaIngresarPersonaEnListaAlPrincipioArchivo(nodo * lista, persona p); //Agrego nodo al principio
nodo * subprogramaIngresarPersonaEnListaOrdenadaArchivo(nodo * lista, persona p); //Agrego nodo ordenado por nombre
nodo * cargarListaDesdeArchivo(nodo * lista, char arch[]);
nodo * cargarListaDesdeArchivoOrdenado(nodo * lista, char arch[]);

nodo * intercalarListas(nodo * A, nodo * B, nodo * nueva);
void subprogramaIntercalarListas(nodo * A, nodo * B, nodo * nueva);

void invertirLista(nodo ** lista);

///Recursividad-----------------------------------------------------------------------------------------------------------------
void mostrarListaRecursiva (nodo * lista);
void mostrarListaRecursivaInvertida(nodo * lista);
int sumaListaRecursiva (nodo * lista);
nodo* borrarNodoRecursivo (nodo* lista, int dato);
nodo* agregarEnOrdenRecursivo(nodo* lista, nodo* nuevo);
nodo* invertirListaRecursiva(nodo* lista);
void mostrarPosParRecursivo(nodo* lista);

#endif // LISTAS_H_INCLUDED
