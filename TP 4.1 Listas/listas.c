#include "listas.h"

///INICIAR LISTA------------------------------------------------------------------------
nodo * inicLista()
{
    return NULL;
}

///CREAR NODO---------------------------------------------------------------------------
nodo * crearNodo(persona nuevaPersona)
{
    nodo * aux;

    aux= (nodo*)malloc(sizeof(nodo));

    aux->dato= nuevaPersona;
    aux->siguiente= NULL;

    return aux;
}

///CARGAR LISTA--------------------------------------------------------------------------
nodo * cargarListaPrincipio(nodo * lista)
{
    char op;
    persona nueva;

    do
    {
        nueva= crearPersona();
        lista= subprogramaAgregarPersonaEnListaPrincipio(lista, nueva);

        printf("\nPresione 's' para continuar con la carga (cualquier otra tecla para salir).\n\n");
        fflush(stdin);
        op= getch();
    }
    while(op=='s');
    return lista;
}

nodo * cargarListaFinal(nodo * lista)
{
    char op;
    persona nueva;

    do
    {
        nueva= crearPersona();
        lista= subprogramaAgregarPersonaEnListaFinal(lista, nueva);

        printf("\nPresione 's' para continuar con la carga.\n\n");
        fflush(stdin);
        op= getch();
    }
    while(op=='s');
    return lista;
}

nodo * cargarListaOrdenada(nodo * lista)
{
    char op;
    persona nueva;

    do
    {
        nueva= crearPersona();
        lista= subprogramaAgregarPersonaEnListaOrdenada(lista, nueva);

        printf("\nPresione 's' para continuar con la carga.\n\n");
        fflush(stdin);
        op= getch();
    }
    while(op=='s');
    return lista;
}

///MOSTRAR---------------------------------------------------------------------
void mostrarUnNodo(nodo * nuevo)
{
    mostrarPersona(nuevo->dato);
}

void recorrerYMostrar(nodo * lista)
{
    nodo * seg= lista;

    while(seg!=NULL)
    {
        mostrarUnNodo(seg);
        seg=seg->siguiente;
    }
}

persona verPrimerNodo(nodo * lista)
{
    persona rta;
    if(lista)
    {
        rta= lista->dato;
    }
    return rta;
}

///BUSCAR---------------------------------------------------------------------
nodo * buscarUltimoNodo(nodo * lista)
{
    nodo * seg;
    seg= lista;

    if(seg!=NULL)
    {
        while(seg->siguiente!=NULL)
        {
            seg=seg->siguiente;
        }
    }
    return seg;
}

//Busco nodo a traves de un char (nombre)
nodo * buscarNodo(nodo * lista, char nombre[])
{
    nodo * seg;
    seg= lista;

    while(seg!=NULL && strcmp(seg->dato.nombre, nombre)!=0)
    {
        seg=seg->siguiente;
    }
    return seg;
}

//Busco nodo a traves de un int (edad)
nodo * buscarNodoPorInt(nodo * lista, int num)
{
    nodo * seg;
    seg= lista;

    while(seg!=NULL && seg->dato.edad!=num)
    {
        seg=seg->siguiente;
    }
    return seg;
}

//Busco nodo si lo encuentra retorna 1, sino 0
int buscarNodoTrueOrFalse(nodo * lista, char nombre[])
{
    nodo * seg= lista;

    int flag=0;

    while(seg!=NULL && strcmp(seg->dato.nombre, nombre)!=0)
    {
        seg=seg->siguiente;
    }

    if(seg!=NULL)
    {
        flag=1;
    }
    return flag;
}

///BORRAR-------------------------------------------------------------------------
nodo * eliminarPrimerNodo(nodo * lista)
{
    nodo * seg= lista;

    if(seg!=NULL)
    {
        nodo * aux= lista;
        seg= lista->siguiente;
        free(aux);
    }

    return seg;
}

nodo * eliminarUltimoNodo(nodo * lista)
{
    nodo * seg;
    nodo * anterior;

    if(lista!=NULL)
    {
        if(lista->siguiente==NULL)
        {
            nodo * aux= lista;
            lista= lista->siguiente;
            free(aux);
        }
        else
        {
            anterior= lista;
            seg= lista->siguiente;

            while(seg->siguiente!=NULL)
            {
                anterior= seg;
                seg= seg->siguiente;
            }
            free(seg);
            anterior->siguiente= NULL;
        }
    }

    return lista;
}

nodo * eliminarNodo(nodo * lista, char nombre[])
{
    nodo * anterior;
    nodo * seg;

    if(lista!=NULL && strcmp(lista->dato.nombre, nombre)==0)
    {
        nodo * aux= lista;
        lista= lista->siguiente;
        free(aux);
    }
    else
    {
        seg= lista;
        while(seg!=NULL && strcmp(seg->dato.nombre, nombre)!=0)
        {
            anterior=seg;
            seg= seg->siguiente;
        }
        if(seg!=NULL)
        {
            anterior->siguiente= seg->siguiente;
            free(seg);
        }
    }
    return lista;
}

nodo * eliminarNodoPorInt(nodo * lista, int num)
{
    nodo * anterior;
    nodo * seg;

    if(lista!=NULL && lista->dato.edad==num)
    {
        nodo * aux;
        aux= lista;
        lista= lista->siguiente;
        free(aux);
    }
    else
    {
        seg= lista;
        while(seg!=NULL && seg->dato.edad!=num)
        {
            anterior=seg;
            seg= seg->siguiente;
        }
        if(seg!=NULL)
        {
            anterior->siguiente= seg->siguiente;
            free(seg);
        }
    }
    return lista;
}

nodo * borrarTodaLaLista(nodo * lista)
{
    nodo * seg;
    nodo * proximo;

    seg= lista;

    while(seg!=NULL)
    {
        proximo=seg->siguiente;
        free(seg);
        seg=proximo;
    }
    return seg;
}

//Desvinculo el primer nodo de la lista y hago que apunte a NULL
nodo * desvincularPrimero(nodo ** lista)
{
    nodo * primero=NULL;

    if(lista!=NULL)
    {
        primero=*lista;

        *lista=(*lista)->siguiente;

        primero->siguiente=NULL;
    }

    return primero;
}

//Borra un nodo segun un parametro que le paso
nodo * borrarNodosSegunParametro(nodo * lista, int edadFiltro)
{
    nodo * aux, * seg, * ante;
    if(lista)
    {
        while(lista!=NULL && lista->dato.edad<edadFiltro)
        {
            aux=lista;
            lista=lista->siguiente;
            free(aux);
        }

        ante=lista;
        seg=lista->siguiente;

        while(seg!=NULL)
        {
            if(seg->dato.edad<edadFiltro)
            {
                aux=seg;
                ante->siguiente=seg->siguiente;
                seg=seg->siguiente;
                free(aux);
            }
            else
            {
                ante=seg;
                seg=seg->siguiente;
            }
        }
    }
    return lista;
}

///AGREGAR----------------------------------------------------------------------
nodo * agregarNodoAlPrincipio(nodo * lista, nodo * nuevoNodo)
{
    if(lista==NULL)
    {
        lista= nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente=lista;
        lista= nuevoNodo;
    }
    return lista;
}

nodo * agregarNodoAlFinal(nodo * lista, nodo * nuevoNodo)
{
    if(lista==NULL)
    {
        lista= nuevoNodo;
    }
    else
    {
        nodo * ultimo= buscarUltimoNodo(lista);
        ultimo->siguiente= nuevoNodo;
    }
    return lista;
}

nodo * agregarNodoEnOrden(nodo * lista, nodo * nuevoNodo)
{
    if(lista==NULL)
    {
        lista= nuevoNodo;
    }
    else
    {
        if(strcmp(nuevoNodo->dato.nombre, lista->dato.nombre)<0)
        {
            lista= agregarNodoAlPrincipio(lista, nuevoNodo);
        }
        else
        {
            nodo * ante;
            nodo *seg;

            ante=lista;
            seg=lista->siguiente;
            while(seg!=NULL && strcmp(nuevoNodo->dato.nombre, seg->dato.nombre)>0)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            nuevoNodo->siguiente= seg;
            ante->siguiente=nuevoNodo;
        }
    }
    return lista;
}

nodo * agregarNodoEnOrdenPorInt(nodo * lista, nodo * nuevoNodo)
{
    if(lista==NULL)
    {
        lista= nuevoNodo;
    }
    else
    {
        if(nuevoNodo->dato.edad < lista->dato.edad)
        {
            lista= agregarNodoAlPrincipio(lista, nuevoNodo);
        }
        else
        {
            nodo * ante;
            nodo *seg;

            ante=lista;
            seg=lista->siguiente;
            while(seg!=NULL && nuevoNodo->dato.edad > seg->dato.edad)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            nuevoNodo->siguiente= seg;
            ante->siguiente=nuevoNodo;
        }
    }
    return lista;
}

nodo * subprogramaAgregarPersonaEnListaPrincipio(nodo * lista, persona p)
{
    lista= agregarNodoAlPrincipio(lista, crearNodo(p));

    return lista;
}

nodo * subprogramaAgregarPersonaEnListaFinal(nodo * lista, persona p)
{
    lista= agregarNodoAlFinal(lista, crearNodo(p));

    return lista;
}

nodo * subprogramaAgregarPersonaEnListaOrdenada(nodo * lista, persona p)
{
    lista= agregarNodoEnOrden(lista, crearNodo(p));

    return lista;
}

///SUMAR-------------------------------------------------------------------------
int sumarIntNodos(nodo * lista)
{
    int suma=0;
    nodo * seg;

    seg= lista;

    while(seg!=NULL)
    {
        suma= suma + seg->dato.edad;
        seg=seg->siguiente;
    }
    return suma;
}

///ARCHIVO-------------------------------------------------------------------------
//En esta funcion el profe quiere que la reutilicemos cambiando agregarNodo ya sea al principio / ordenado
nodo * subprogramaIngresarPersonaEnListaAlPrincipioArchivo(nodo * lista, persona p)
{
    int flag=0;

    nodo * nuevo= crearNodo(p);

    flag= buscarNodoTrueOrFalse(lista, p.nombre);

    if(flag==0)
        lista= agregarNodoAlPrincipio(lista, nuevo);

    return lista;
}

//Reutilizo la funcion anterior
nodo * subprogramaIngresarPersonaEnListaOrdenadaArchivo(nodo * lista, persona p)
{
    int flag=0;

    nodo * nuevo= crearNodo(p);

    flag= buscarNodoTrueOrFalse(lista, p.nombre);

    if(flag==0)
        lista= agregarNodoEnOrden(lista, nuevo);

    return lista;
}

//En este caso queda mas resumida la funcion, directamente para crear el nodo llamo la funcion crearNodo adentro de la funcion
//nodo * subprogramaIngresarPersonaEnLista(nodo * lista, persona p)
//{
//    lista= agregarNodoEnOrden(lista, crearNodo(p)));
//
//    return lista;
//}

nodo * cargarListaDesdeArchivo(nodo * lista, char arch[])
{
    persona p;

    FILE * puntero;
    puntero= fopen(arch, "rb");

    if(puntero!=NULL)
    {
        while(fread(&p, sizeof(persona), 1, puntero)>0)
        {
            lista=subprogramaIngresarPersonaEnListaAlPrincipioArchivo(lista, p);
        }
    }
    else
    {
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
    return lista;
}

nodo * cargarListaDesdeArchivoOrdenado(nodo * lista, char arch[])
{
    persona p;

    FILE * puntero;
    puntero= fopen(arch, "rb");

    if(puntero!=NULL)
    {
        while(fread(&p, sizeof(persona), 1, puntero)>0)
        {
            lista=subprogramaIngresarPersonaEnListaOrdenadaArchivo(lista, p);
        }
    }
    else
    {
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
    return lista;
}

///INTERCALAR LISTAS-----------------------------------------------------------------------------
nodo * intercalarListas(nodo * A, nodo * B, nodo * nueva)
{
    nodo * aux;

    while(A!=NULL && B!=NULL)
    {
        if(strcmp(A->dato.nombre, B->dato.nombre)<0)
        {
            aux= A;
            A=A->siguiente;
        }
        else
        {
            aux= B;
            B=B->siguiente;
        }
        aux->siguiente= NULL;
        nueva= agregarNodoAlFinal(nueva, aux);
    }

    if(A!=NULL)
    {
        nueva= agregarNodoAlFinal(nueva, A);
    }

    else
    {
        nueva= agregarNodoAlFinal(nueva, B);
    }

    return nueva;
}

void subprogramaIntercalarListas(nodo * A, nodo * B, nodo * nueva)
{
    printf("Cargar lista A:\n\n");
    A=cargarListaOrdenada(A);

    printf("Cargar lista B:\n\n");
    B=cargarListaOrdenada(B);

    printf("Lista A:\n");
    recorrerYMostrar(A);

    printf("Lista B:\n");
    recorrerYMostrar(B);

    nueva= intercalarListas(A, B, nueva);

    A= inicLista();
    B= inicLista();

    printf("Lista nueva:\n");
    recorrerYMostrar(nueva);
}

///INVERTIR LISTAS---------------------------------------------------------------------------------------
void invertirLista(nodo ** lista)
{
    nodo * aux;
    nodo * nueva= inicLista();

    while(*lista!=NULL)
    {
        aux= desvincularPrimero(*&lista);
        nueva=agregarNodoAlPrincipio(nueva, aux);
    }
    *lista= nueva;
}

///-----------------------------------------------------------------------------------------------------
///RECURSIVIDAD-----------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------------
void mostrarListaRecursiva (nodo * lista)
{
    if(lista!=NULL)
    {
        mostrarUnNodo(lista);
        mostrarListaRecursiva(lista->siguiente);
    }
}

void mostrarListaRecursivaInvertida(nodo * lista)
{
    if(lista!=NULL)
    {
        mostrarListaRecursiva(lista->siguiente);
        mostrarUnNodo(lista);
    }
}

int sumaListaRecursiva (nodo * lista)
{
    int suma=0;
    if(lista!=NULL)
    {
        suma=lista->dato.edad + sumaListaRecursiva(lista->siguiente);
    }
    return suma;
}

nodo* borrarNodoRecursivo (nodo* lista, int dato)
{
    if(lista)
    {
        if(lista->dato.edad==dato)
        {
            nodo* aux=lista;
            lista=lista->siguiente;
            free(aux);
        }
        else
        {
            lista->siguiente=borrarNodoRecursivo(lista->siguiente,dato);
        }
    }
    return lista;
}

nodo* agregarEnOrdenRecursivo(nodo* lista, nodo* nuevo)
{
    if(!lista)
    {
        lista=nuevo;
    }
    else
    {
        if(nuevo->dato.edad<lista->dato.edad)
        {
            nuevo->siguiente=lista;
            lista=nuevo;
        }
        else
        {
            lista->siguiente=agregarEnOrdenRecursivo(lista->siguiente,nuevo);
        }
    }
    return lista;
}

nodo* invertirListaRecursiva(nodo* lista)
{
    nodo* aux;
    if(lista)
    {
        aux=lista;
        lista=lista->siguiente;
        aux->siguiente=NULL;
        lista=agregarNodoAlFinal(invertirListaRecursiva(lista),aux);
    }
    return lista;
}

void mostrarPosParRecursivo(nodo* lista)
{
    nodo* aux=lista;
    if(aux!=NULL)
    {
        aux=aux->siguiente;

        if(aux!=NULL)
        {
            mostrarPersona(aux->dato);
            mostrarPosParRecursivo(aux->siguiente);
        }
    }
}


