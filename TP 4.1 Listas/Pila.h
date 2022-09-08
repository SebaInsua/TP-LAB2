#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <malloc.h>
#include "persona.h"
#include "listas.h"

void inicpila(nodo ** pila);
void apilar(nodo ** pila, persona dato);
void mostrar(nodo ** pila);
void leer(nodo ** pila);
persona tope (nodo ** pila);
int pilavacia(nodo ** pila);
persona desapilar(nodo ** pila);

#endif // PILA_H_INCLUDED
