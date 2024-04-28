#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct Lista
{
    NodoPtr primero;
};

ListaPtr crearLista()
{

    ListaPtr lista = malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;
};

int getNodoLista(ListaPtr lista)
{
    return lista->primero;
}

void setNodoLista(ListaPtr lista, NodoPtr primero)
{
    lista->primero = primero;
}

void insertarPrimero(ListaPtr lista, int dato)
{
    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);

    lista->primero = nuevoNodo;

};


void insertarUltimo(ListaPtr lista, int dato)
{
    NodoPtr actual = getNodoLista(lista);

    while (getSiguienteNodo(actual)!=NULL)
    {
        actual = getSiguienteNodo(actual);
    }
    NodoPtr ultimo = crearNodo(dato,NULL);
    setSiguienteNodo(actual,ultimo);
}

void insertarPosicion(ListaPtr lista, int dato, int posicion)
{
    if (posicion < 0 || posicion > obtenerTamanio(lista))
    {
        return;
    }

    if (posicion == 0)
    {
        insertarPrimero(lista, dato);
        return;
    }

    NodoPtr anterior = getNodoLista(lista);
    for (int i = 0; i < posicion - 1; i++)
    {
        anterior = getSiguienteNodo(anterior);
        mostrarNodo(anterior);
    }

    NodoPtr nuevo = crearNodo(dato,getSiguienteNodo(anterior));
    printf("%d",getDatoNodo(nuevo));
    setSiguienteNodo(anterior,nuevo);
}


int obtenerPrimero(ListaPtr lista)
{
    return getDatoNodo(getNodoLista(lista));
}

int obtenerUltimo(ListaPtr lista)
{
    NodoPtr actual = getNodoLista(lista);

    while (getSiguienteNodo(actual)!=NULL)
    {
        actual = getSiguienteNodo(actual);
    }
    getDatoNodo(actual);
}
int obtenerPosicion(ListaPtr lista,int posicion)
{
    NodoPtr actual = getNodoLista(lista);
    for (int i = 0; i < posicion - 1; i++)
    {
        actual = getSiguienteNodo(actual);
    }
    getDatoNodo(actual);

}

int eliminarPrimero(ListaPtr lista)
{
    int eliminarUltimo(ListaPtr *lista)
    {
        if ((*lista)->primero == NULL)
        {
            return -1; // Error: lista vacía
        }

        NodoPtr anterior = NULL;
        NodoPtr actual = (*lista)->primero;
        while (actual->siguiente != NULL)
        {
            anterior = actual;
            actual = actual->siguiente;
        }

        // Liberamos la memoria del último nodo
        free(actual);

        // Actualizamos el puntero `primero` de la lista para que apunte al penúltimo nodo
        if (anterior == NULL)
        {
            (*lista)->primero = NULL; // Lista queda vacía
        }
        else
        {
            anterior->siguiente = NULL;
        }

        return 0; // Exito
    }
}
int eliminarUltimo(ListaPtr lista); //tarea
int eliminarposicicon(ListaPtr lista); //tarea

int obtenerTamanio(ListaPtr lista)
{
    int posicion = 0;
    NodoPtr actual = getNodoLista(lista);
    while (actual!=NULL)
    {
        posicion++;
        actual = getSiguienteNodo(actual);
    }
    return posicion;
}

void ordenarLista(ListaPtr lista);//tarea
ListaPtr ordenarListaCopia(ListaPtr lista);//tarea
ListaPtr duplicarLista(ListaPtr lista);//tarea

int buscarElemento(ListaPtr lista, int datoBuscado);//tarea

void insertarEnOrden(ListaPtr lista, int dato);//tarea, si la lista está ordenada cada vez que
//se inserta se inserta en la posición que corresponda


void mostrarLista(ListaPtr lista)
{

    printf("\nLISTA\n");
    NodoPtr actual = lista->primero;

    while (actual!=NULL)
    {

        mostrarNodo(actual);
        actual = getSiguienteNodo(actual);
    }
    printf("\n\n");
};

void liberarLista(ListaPtr lista)
{

    NodoPtr actual = lista->primero;

    while (actual!=NULL)
    {

        free(actual);
        actual = getSiguienteNodo(actual);
    };
}
