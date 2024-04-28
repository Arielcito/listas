#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main()
{
    ListaPtr lista = crearLista();

    insertarPrimero(lista, 4);
    insertarPrimero(lista, 11);
    insertarPrimero(lista, 21);
    insertarPrimero(lista, 23);
    insertarPrimero(lista, 34);
    mostrarLista(lista);

    printf("Insertar Ultimo");
    insertarUltimo(lista,10);
    mostrarLista(lista);

    printf("Insertar 10 en posicion 4");
    insertarPosicion(lista,10,4);
    mostrarLista(lista);

    printf("\nObtener primero\n");
    int primero = obtenerPrimero(lista);
    printf("%d",primero);

    printf("\nObtener ultimo\n");
    int ultimo = obtenerUltimo(lista);
    printf("%d",ultimo);

    printf("\nObtener dato en posicion 2\n");
    int dato = obtenerPosicion(lista,2);
    printf("%d",dato);

    return 0;
}
