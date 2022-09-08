#include "persona.h"

persona crearPersona()
{
    persona nueva;

    printf("-----------------------\n");
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nueva.nombre);
    printf("Ingrese edad: ");
    scanf("%d", &nueva.edad);
    printf("-----------------------\n");

    return nueva;
}

int arregloPersona(persona arreglo[], int dim)
{
    int i=0;
    char op='s';
    persona nueva;

    do
    {
        nueva=crearPersona();
        arreglo[i]= nueva;
        i++;
        printf("\nPresione 's' para continuar con la carga.\n\n");
        fflush(stdin);
        op= getch();

    }
    while(i<dim && op=='s');

    return i;
}

void mostrarPersona(persona dato)
{
    printf("-----------------------\n");
    printf("Nombre: %s \n", dato.nombre);
    printf("Edad: %d \n", dato.edad);
    printf("-----------------------\n");
}

void mostrarArregloPersona(persona arreglo[], int validos)
{
    int i=0;

    while(i<validos)
    {
        mostrarPersona(arreglo[i]);
        i++;
    }
}
