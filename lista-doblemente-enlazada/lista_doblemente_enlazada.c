#include<stdlib.h>
#include<stdio.h>


typedef struct Nodo{
    struct Nodo * anterior;
    int valor;
    struct Nodo * siguiente;
} nodo;

int agregarNodo(nodo **, int);
void imprimirLista(nodo *);

int main(){
    nodo * cabeza = NULL;

    agregarNodo(&cabeza, 1);
    agregarNodo(&cabeza, 2);
    agregarNodo(&cabeza, 3);
    agregarNodo(&cabeza, 4);
    agregarNodo(&cabeza, 5);

/*    
    cabeza = (nodo *)malloc(sizeof(*cabeza));
    cabeza->valor = 1;

    cabeza->anterior = NULL;
    cabeza->siguiente = (nodo *)malloc(sizeof(*cabeza));
    cabeza->siguiente->valor = 2;
    cabeza->siguiente->anterior = cabeza;
*/    
    imprimirLista(cabeza);

    return 0;
}

int agregarNodo(nodo ** cabeza, int valor){
    nodo * actual = *cabeza; 
    nodo * nuevoNodo = (nodo *)malloc(sizeof(*cabeza)); 
    nuevoNodo->valor = valor;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;
    
    if(nuevoNodo == NULL){
        return -1;
    }

    if((*cabeza) == NULL){ 
        *cabeza = nuevoNodo; 
        (*cabeza)->siguiente = NULL; 
        (*cabeza)->anterior = NULL; 
        return 0;
    }

    /*
    if(cabeza->siguiente == NULL){
        cabeza->siguiente = nuevoNodo;
        return 0;
    }*/

    // A partir de acá parece estar el problema
    while(actual->siguiente != NULL){
        actual = actual->siguiente;
    }

    actual->siguiente = nuevoNodo;
    nuevoNodo->anterior = actual;
    return 0;

    // Corregir este método
}

void imprimirLista(nodo * cabeza){
    nodo * actual = cabeza;

    while(actual != NULL){
        printf("%d\n",actual->valor);
        actual = actual->siguiente;
    }

    // Este método funciona
}

