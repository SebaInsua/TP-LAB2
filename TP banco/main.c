#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include "tda_lista_simple.h"

int main()
{
    nodo*lista;
    lista=inicLista();
    char file_name[]="Clientes.bin";
    ///cargaArchivo(file_name);
    mostrarArchivo(file_name);
    lista=archivoToLista(file_name,lista);
    mostrarLista(lista);
    lista=eliminarUnNodo(lista,"juan");
    mostrarLista(lista);


    return 0;
}
