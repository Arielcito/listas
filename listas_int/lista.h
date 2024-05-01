#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

typedef struct Lista * ListaPtr;

ListaPtr crearLista();

void setNodoLista(ListaPtr lista, NodoPtr primero);
NodoPtr getNodoLista(ListaPtr lista);

void insertarPrimero(ListaPtr lista, int dato);
void insertarUltimo(ListaPtr lista, int dato); //tarea
void insertarPosicion(ListaPtr lista, int dato, int posicion); //tarea


int obtenerPrimero(ListaPtr lista);
int obtenerUltimo(ListaPtr lista); //tarea
int obtenerPosicion(ListaPtr lista,int posicion); //tarea

int eliminarPrimero(ListaPtr lista);
int eliminarUltimo(ListaPtr lista); //tarea
int eliminarPosicion(ListaPtr lista, int posicion); //tarea

int obtenerTamanio(ListaPtr lista); //tarea

void ordenarLista(ListaPtr lista);//tarea
ListaPtr ordenarListaCopia(ListaPtr lista);//tarea
ListaPtr duplicarLista(ListaPtr lista);//tarea

int buscarElemento(ListaPtr lista, int datoBuscado);//tarea

void insertarEnOrden(ListaPtr lista, int dato);//tarea, si la lista está ordenada cada vez que
//se inserta se inserta en la posición que corresponda


void mostrarLista(ListaPtr lista);

void liberarLista(ListaPtr lista);


#endif // LISTA_H_INCLUDED
