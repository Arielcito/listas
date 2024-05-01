#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main()
{
    ListaPtr lista = crearLista();

    insertarPrimero(lista, 11);
    insertarPrimero(lista, 23);
    insertarPrimero(lista, 4);
    insertarPrimero(lista, 21);
    insertarPrimero(lista, 34);
    mostrarLista(lista);

    printf("Insertar primero");
    insertarPrimero(lista,10);
    mostrarLista(lista);

    printf("Insertar Ultimo");
    insertarUltimo(lista,10);
    mostrarLista(lista);

    printf("Insertar 10 en posicion 2");
    insertarPosicion(lista,10,2);
    mostrarLista(lista);

    printf("\n\nObtener primero\n");
    int primero = obtenerPrimero(lista);
    printf("%d",primero);

    printf("\n\nObtener ultimo\n");
    int ultimo = obtenerUltimo(lista);
    printf("%d",ultimo);

    printf("\n\nObtener dato en posicion 2\n");
    int dato = obtenerPosicion(lista,2);
    printf("%d",dato);

    printf("\n\nEliminar primero\n");
    int datoEliminado = eliminarPrimero(lista);
    printf("%d",&datoEliminado);
    mostrarLista(lista);

    printf("\n\nEliminar Ultimo\n");
    int datoEliminadoUltimo = eliminarUltimo(lista);
    printf("%d",datoEliminadoUltimo);
    mostrarLista(lista);

    printf("\n\nEliminar posicion 2\n");
    int eliminadoPosicion = eliminarPosicion(lista,2);
    printf("%d",eliminadoPosicion);
    mostrarLista(lista);

    printf("\n\nOrdenar lista \n");
    ordenarLista(lista);
    mostrarLista(lista);

    return 0;
}
