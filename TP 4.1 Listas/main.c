#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listas.h"
#include "Pila.h"

const char ESC=27;
const int dim= 20;

int menu();
void cargarUnaPersonaEnArchivo(char arch[]);

int main()
{
    int ejercicio=0;
    int flag=0;
    char op;
    char nombre[20];

    nodo * lista;
    nodo * lista2;
    nodo * nueva;

    lista=inicLista();
    lista2=inicLista();
    nueva= inicLista();

    char archPersona[]="Persona.bin";
    char archPersonaPunto2[]="PersonaPunto2.bin";

    persona arreglo[dim];
    int validos=0;

     do
    {
        system("cls");
        ejercicio= menu();
        switch(ejercicio)
        {
            case 1:
                system("cls");
                printf("EJERCICIO 1.\n\n");
                cargarUnaPersonaEnArchivo(archPersona);
                lista=cargarListaDesdeArchivo(lista, archPersona);
                printf("Lista cargada:\n\n");
                recorrerYMostrar(lista);
                system("pause");
                break;

            case 2:
                system("cls");
                printf("EJERCICIO 2.\n\n");
                cargarUnaPersonaEnArchivo(archPersonaPunto2);
                lista2=cargarListaDesdeArchivoOrdenado(lista2, archPersonaPunto2);
                printf("Lista cargada y ordenada:\n\n");
                recorrerYMostrar(lista2);
                system("pause");
                break;

            case 3:
                system("cls");
                printf("EJERCICIO 3.\n\n");
                printf("Nombre de la persona que desea buscar en la lista: ");
                fflush(stdin);
                gets(nombre);

                flag= buscarNodoTrueOrFalse(lista, nombre);
                if(flag==1)
                {
                    printf("\nEl nodo se encuentra en la lista.\n\n");
                }
                else
                {
                    printf("\nEl nodo NO se encuentra en la lista.\n\n");
                }

                system("pause");
                break;

            case 4:
                system("cls");
                printf("EJERCICIO 4.\n\n");
//                ASI SE HARIA SI NO ESTUVIARA LA FUNCION SUBPROGRAMAINTERCALAR
//                printf("Primera lista:\n\n");
//                lista= cargarListaOrdenada(lista);
//                printf("\nSegunda lista:\n");
//                lista2= cargarListaOrdenada(lista2);
//                system("cls");
//                printf("Primera lista:\n");
//                recorrerYMostrar(lista);
//                printf("\nSegunda lista:\n");
//                recorrerYMostrar(lista2);
//
//                printf("\n\nLista nueva:\n");
//                nueva=intercalarListas(lista, lista2, nueva);
//                recorrerYMostrar(nueva);

                subprogramaIntercalarListas(lista, lista2, nueva);


                system("pause");
                break;

            case 5:
                system("cls");
                printf("EJERCICIO 5.\n\n");
                persona num1={"quka",23};
                persona num2={"gaston",25};
                persona num3={"sabri",22};
                persona aux;

                nodo * Pers1;

                inicpila(&Pers1);

                apilar(&Pers1,num1);
                apilar(&Pers1,num2);
                apilar(&Pers1,num3);

                leer(&Pers1);

                if(!pilavacia(&Pers1))
                    mostrar(&Pers1);

                aux=tope(&Pers1);

                mostrarPersona(aux);

                num1= desapilar(&Pers1);

                printf("\nPersona eliminada:\n");
                mostrarPersona(num1);

                mostrar(&Pers1);

                system("pause");
                break;

            case 6:
                system("cls");
                printf("EJERCICIO 6.\n\n");
                lista= cargarListaPrincipio(lista);
                printf("Lista:\n");
                recorrerYMostrar(lista);

                invertirLista(&lista);
                printf("Lista invertida:\n");
                recorrerYMostrar(lista);

                system("pause");
                break;

            case 7:
                system("cls");
                printf("EJERCICIO 7.\n\n");

                nodo * Pila1;
                nodo * Pila2;
                inicpila(&Pila1);
                inicpila(&Pila2);

                persona pers;

                leer(&Pila1);

                while(!pilavacia(&Pila1))
                {
                    pers=desapilar(&Pila1);

                    if((pers.edad%2)==0)
                    {
                        nueva=subprogramaAgregarPersonaEnListaFinal(nueva,pers);
                    }
                    apilar(&Pila2,pers);
                }
                recorrerYMostrar(nueva);

                while (!pilavacia(&Pila2))
                {

                    apilar(&Pila1,desapilar(&Pila2));
                }
                mostrar(&Pila1);
                break;

            case 8:
                system("cls");
                printf("EJERCICIO 8.\n\n");
                nueva=borrarNodosSegunParametro(nueva,10);
                recorrerYMostrar(nueva);
                break;

            default:
                printf("\nEl ejercicio ingresado no existe por favor ingrese el numero nuevamente");
                break;
        }
        printf("\nESC para salir.\n");
        fflush(stdin);
        op=getch();
    }
    while(op!=ESC);

    return 0;
}

///MENU
int menu()
{
    int punto;

    printf("PRACTICO N 4: LISTAS SIMPLEMENTE ENLAZADAS.\n\n");

    printf("1. Hacer un programa que lea de un archivo datos y los inserte en una lista.\n");
    printf("2. Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada.\n");
    printf("3. Hacer una funcion que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada.\n");
    printf("4. Hacer una funcion que intercale en orden los elementos de dos listas ordenadas generando una nueva lista. Se deben redireccionar los punteros, no se deben crear nuevos nodos ..\n");
    printf("5. Codificar el TDA Pila con las funciones necesarias, implementada con una lista enlazada (Similar al ejercicio hecho con arreglo).\n");
    printf("6. Invertir los elementos de una lista redireccionando solamente los punteros.\n");
    printf("7. Utilizando el TDA Pila creado en el punto 5, cargar la pila con numeros enteros.\n");
    printf("8. Borrar nodo segun parametros.\n");

    printf("\nIngrese el ejercicio que desea resolver: ");
    scanf("%d", &punto);

    return (punto);
}

///Ejercicio 1
void cargarUnaPersonaEnArchivo(char arch[])
{
    persona p;

    char op;

    FILE *puntero;
    puntero= fopen(arch, "ab");

    if(puntero!=NULL){
        do
        {
            printf("Cargar una persona:\n");
            printf("Nombre: ");
            fflush(stdin);
            gets(p.nombre);
            printf("Edad: ");
            scanf("%d", &p.edad);

            fwrite(&p, sizeof(persona), 1, puntero);

            printf("\nESC para salir de la carga.\n\n");
            fflush(stdin);
            op=getch();
        }
        while(op!=ESC);
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
}

