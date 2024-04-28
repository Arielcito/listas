#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

typedef struct Nodo * NodoPtr;

NodoPtr crearNodo(int dato, NodoPtr siguiente);
void mostrarNodo(NodoPtr nodo);
void liberarNodo(NodoPtr nodo);

int getDatoNodo(NodoPtr nodo);
NodoPtr getSiguienteDatoNodo(NodoPtr nodo);

void setDatoNodo(NodoPtr nodo,int d);
void setSiguienteNodo(NodoPtr nodo,NodoPtr sig);
#endif // NODO_H_INCLUDED
