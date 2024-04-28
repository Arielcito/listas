#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
struct Nodo {
    int dato;
    struct Nodo * siguiente;
};

NodoPtr crearNodo(int dato, NodoPtr siguiente){
    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;

};

void mostrarNodo(NodoPtr nodo){
    printf("{ %d }", getDatoNodo(nodo));
};


void liberarNodo(NodoPtr nodo){
    free(nodo);
};

int getDatoNodo(NodoPtr nodo){
    return nodo->dato;
}

NodoPtr getSiguienteNodo(NodoPtr nodo){
    return nodo->siguiente;
}

void setDatoNodo(NodoPtr nodo,int d){
    nodo->dato = d;
}
void setSiguienteNodo(NodoPtr nodo,NodoPtr sig){
    nodo->siguiente = sig;
}
