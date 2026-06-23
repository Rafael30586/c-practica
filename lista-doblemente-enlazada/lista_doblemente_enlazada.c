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
void quitarNodoDelPrincipio(nodo **);
void imprimirListaAlreves(nodo *);

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

    quitarNodoDelPrincipio(&cabeza);
    quitarNodoDelPrincipio(&cabeza);
    quitarNodoDelPrincipio(&cabeza);

    imprimirLista(cabeza);

    imprimirListaAlreves(cabeza);

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

   // Esta función funciona    
}

void imprimirLista(nodo * cabeza){
    nodo * actual = cabeza;

    while(actual != NULL){
        printf("%d\n",actual->valor);
        actual = actual->siguiente;
    }

    // Esta función funciona
}

int agregarNodoAlPrincipio(nodo ** punteroACabeza, int valor){
    nodo * nuevoNodo = (nodo *)malloc(sizeof(** punteroACabeza));
    
    if(nuevoNodo == NULL){
        return -1;
    }


    (* punteroACabeza)->anterior = nuevoNodo;

    nuevoNodo->anterior = NULL;
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = *punteroACabeza;
    
    * punteroACabeza = nuevoNodo;

    return 0;

    // Esta función funciona
}

void quitarNodoDelFinal(nodo * cabeza){
    nodo * actual = cabeza;

    while(actual->siguiente->siguiente != NULL){
        actual = actual->siguiente;
    }

    free(actual->siguiente);

    actual->siguiente = NULL;

    // Esta función funciona
}

void quitarNodoDelPrincipio(nodo ** punteroACabeza){
    nodo * punteroTemporal = (*punteroACabeza)->siguiente;
    free(*punteroACabeza);
    *punteroACabeza = punteroTemporal;

    // Esta función funciona
}

void imprimirListaAlreves(nodo * cabeza){
    nodo * actual = cabeza;

    while(actual->siguiente != NULL){
        actual = actual->siguiente;
    }

    while(actual != NULL){
        printf("%d\n", actual->valor);
        actual = actual->anterior;
    }

    // Esta FUNCIÓN FUNCIONA

}


