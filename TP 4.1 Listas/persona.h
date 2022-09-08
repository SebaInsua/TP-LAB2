#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct
{
    char nombre[20];
    int edad;
} persona;

persona crearPersona();
int arregloPersona(persona arreglo[], int dim);
void mostrarPersona(persona dato);
void mostrarArregloPersona(persona arreglo[], int validos);

#endif // PERSONA_H_INCLUDED
