#include<stdlib.h>
#include<stdio.h>


typedef struct Nodo{
    struct Nodo * anterior;
    int valor;
    struct Nodo * siguiente;
} nodo;

int agregarNodo(nodo **, int);
void imprimirLista(nodo *);
int agregarNodoAlPrincipio(nodo **, int);
void quitarNodoDelFinal(nodo *);

int main(){
    nodo * cabeza = NULL;

    agregarNodo(&cabeza, 1);
    agregarNodo(&cabeza, 2);
    agregarNodo(&cabeza, 3);
    agregarNodo(&cabeza, 4);
    agregarNodo(&cabeza, 5);
    agregarNodo(&cabeza, 6);
    agregarNodo(&cabeza, 7);
    agregarNodo(&cabeza, 8);
    agregarNodo(&cabeza, 9);
    agregarNodo(&cabeza, 10);

    imprimirLista(cabeza);
    
    agregarNodoAlPrincipio(&cabeza, -1);
    agregarNodoAlPrincipio(&cabeza, -2);
    agregarNodoAlPrincipio(&cabeza, -3);
    agregarNodoAlPrincipio(&cabeza, -4);
    agregarNodoAlPrincipio(&cabeza, -5);

    imprimirLista(cabeza);

    quitarNodoDelFinal(cabeza);
    quitarNodoDelFinal(cabeza);

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

  
    while(actual->siguiente != NULL){
        actual = actual->siguiente;
    }

    actual->siguiente = nuevoNodo;
    nuevoNodo->anterior = actual;
    return 0;

   // Este método funciona    
}

void imprimirLista(nodo * cabeza){
    nodo * actual = cabeza;

    while(actual != NULL){
        printf("%d\n",actual->valor);
        actual = actual->siguiente;
    }

    // Este método funciona
}

int agregarNodoAlPrincipio(nodo ** punteroACabeza, int valor){
    nodo * nuevoNodo = (nodo *)malloc(sizeof(** punteroACabeza));

    if(nuevoNodo == NULL){
        return -1;
    }

    nuevoNodo->anterior = NULL;
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = *punteroACabeza;
    
    * punteroACabeza = nuevoNodo;

    return 0;

    // Este método funciona
}

void quitarNodoDelFinal(nodo * cabeza){
    nodo * actual = cabeza;

    while(actual->siguiente->siguiente != NULL){
        actual = actual->siguiente;
    }

    free(actual->siguiente);

    actual->siguiente = NULL;

    // Este método funciona
}

