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

NodoPtr getNodoLista(ListaPtr lista)
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
    }

    NodoPtr nuevo = crearNodo(dato,getSiguienteNodo(anterior));

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

    NodoPtr nodoEliminado = getNodoLista(lista);
    int datoEliminado = getDatoNodo(nodoEliminado);
    NodoPtr aux = getSiguienteNodo(getNodoLista(lista));
    setNodoLista(lista,aux);

    liberarNodo(nodoEliminado);

    return datoEliminado;
}

int eliminarUltimo(ListaPtr lista)
{
    if (lista == NULL)
    {
        return -1; // Lista vacía
    }

    NodoPtr actual = getNodoLista(lista);
    NodoPtr anterior = NULL;

    while (getSiguienteNodo(actual) != NULL)
    {
        anterior = actual;
        actual = getSiguienteNodo(actual);
    }

    int datoEliminado = getDatoNodo(actual);
    liberarNodo(actual);

    if (anterior == NULL)
    {
        lista = NULL; // Lista ahora vacía
    }
    else
    {
        setSiguienteNodo(anterior,NULL);
    }

    return datoEliminado;
}

int eliminarPosicion(ListaPtr lista, int posicion)
{
    if (lista == NULL || posicion < 1)
    {
        return -1; // Error: lista vacía o posición inválida
    }

    NodoPtr actual = getNodoLista(lista);
    NodoPtr anterior = NULL;
    int contadorPosicion = 1;

    while (actual != NULL && contadorPosicion < posicion)
    {
        anterior = actual;
        actual = getSiguienteNodo(actual);
        contadorPosicion++;
    }

    int datoEliminado = getDatoNodo(actual);
    if (anterior == NULL)
    {
        lista = getSiguienteNodo(actual); // Eliminar primer elemento
    }
    else
    {
        NodoPtr actualSig = getSiguienteNodo(actual);
        setSiguienteNodo(anterior,actualSig);
    }

    free(actual);

    return datoEliminado;
}

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

void ordenarLista(ListaPtr lista)
{
    NodoPtr actual = lista;
    NodoPtr anterior = NULL;

    while (actual != NULL)
    {
        NodoPtr minimo = actual;
        NodoPtr siguiente = getSiguienteNodo(actual);

        while (siguiente != NULL)
        {
            if (getDatoNodo(siguiente) < getDatoNodo(minimo))
            {
                minimo = siguiente;
            }
            siguiente = getSiguienteNodo(siguiente);
        }

        if (minimo != actual)
        {
            int temp = getDatoNodo(actual);
            setDatoNodo(actual,getDatoNodo(minimo));
            setDatoNodo(minimo,getDatoNodo(temp));

            if (anterior != NULL)
            {
                setSiguienteNodo(anterior,minimo);
            }
            else
            {
                lista = minimo; // Actualizar la cabeza de la lista si es necesario
            }

            anterior = minimo;
        }

        actual = getSiguienteNodo(actual);
    }
}



ListaPtr ordenarListaCopia(ListaPtr lista)
{
    ListaPtr listaCopia = crearLista();
    NodoPtr actual = lista;

    while (actual != NULL)
    {
        insertarEnOrden(listaCopia, getDatoNodo(actual));

        actual = getSiguienteNodo(actual);
    }

    return listaCopia;
}
ListaPtr duplicarLista(ListaPtr lista)
{
    ListaPtr listaDuplicada = crearLista();
    NodoPtr actual = lista;

    while (actual != NULL)
    {
        insertarPrimero(listaDuplicada, getDatoNodo(actual)); // Inserta al inicio para preservar orden
        actual = getSiguienteNodo(actual);
    }

    return listaDuplicada;
}

int buscarElemento(ListaPtr lista, int datoBuscado)
{
    int posicion = 1;
    NodoPtr actual = lista;

    while (actual != NULL && getDatoNodo(actual) <= datoBuscado)
    {
        if (getDatoNodo(actual) == datoBuscado)
        {
            return posicion;
        }
        posicion++;
        actual = getSiguienteNodo(actual);
    }

    return -1;
}

void insertarEnOrden(ListaPtr lista, int dato)
{
    NodoPtr nuevoNodo = crearNodo(dato, NULL);

    if (lista == NULL || getDatoNodo(lista) >= dato)
    {
        insertarPrimero(lista, dato); // Inserta al inicio si la lista está vacía o el dato es menor que el primero
        return;
    }

    NodoPtr actual = lista;
    NodoPtr anterior = NULL;

    while (actual != NULL && getDatoNodo(actual) < dato)
    {
        anterior = actual;
        actual = getSiguienteNodo(actual);
    }
    setSiguienteNodo(nuevoNodo,actual);
    if (anterior != NULL)
    {
        setSiguienteNodo(anterior,nuevoNodo);
    }
}


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
