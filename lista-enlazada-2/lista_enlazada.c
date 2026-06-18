#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Nodo{
    int valor;
    struct Nodo * proximo;
} nodo;

void imprimirLista(nodo *);
void agregarNodo(nodo *,int);
void agregarNodoAlPrincipio(nodo **, int);
// void agregarNodo2(nodo *, int);
void quitarNodoAlPrincipio(nodo **);
void quitarUltimoNodo(nodo *);
int quitarUnNodoPuntual(nodo **, int);


int main(){
    nodo * head = NULL;

    head = (nodo *) malloc(sizeof(* head));

    head->valor = 1; // Agregando el primer nodo
    head->proximo = NULL;

    head->proximo = (nodo *)malloc(sizeof(* head)); // asignando memoria para segundo nodo
    head->proximo->valor = 2; // estableciendo valor para segundo nodo
    head->proximo->proximo = NULL;

    head->proximo->proximo = (nodo *)malloc(sizeof(* head)); // asignando memoria para tercer nodo
    head->proximo->proximo->valor = 3; // estableciendo valor para tercer nodo
    head->proximo->proximo->proximo = NULL;
    
    imprimirLista(head);

    agregarNodo(head,4);
    agregarNodo(head,5);
    agregarNodo(head,6);
    imprimirLista(head);

    agregarNodoAlPrincipio(&head, -1);
    imprimirLista(head);

    //agregarNodo2(head, 5);
    //imprimirLista(head);

    quitarNodoAlPrincipio(&head);
    imprimirLista(head);

    quitarUltimoNodo(head);
    imprimirLista(head);

    quitarUnNodoPuntual(&head, 3);
    imprimirLista(head);
    
    return 0;
}

void imprimirLista(nodo * head){

    nodo * actual = head;
/*
    while(actual->proximo != NULL){
        printf("%d\n",actual->valor);
        actual = actual->proximo;
    }*/

    while(actual != NULL){
        printf("%d\n",actual->valor);
        actual = actual->proximo;
    }
}

void agregarNodo(nodo * head, int valor){
    nodo * nuevoNodo = (nodo *) malloc(sizeof(* head));
    nuevoNodo->valor = valor;
    nuevoNodo->proximo = NULL;

    nodo * actual = head;

    while(actual->proximo != NULL){
        actual = actual->proximo;
    }

    actual->proximo = nuevoNodo;

}

/*
void agregarNodo2(nodo * head, int valor){
    nodo nuevoNodo;
    nuevoNodo.valor = valor;
    nuevoNodo.proximo = NULL;
    
    nodo * actual = head;

    while(actual->proximo != NULL){
        actual = actual->proximo;
    }

    actual->proximo = &nuevoNodo;
}*/

void agregarNodoAlPrincipio(nodo ** punteroAHead, int valor){
    nodo * nuevoNodo = (nodo *)malloc(sizeof(** punteroAHead));
    nuevoNodo->valor = valor;

    nuevoNodo->proximo = * punteroAHead;
    * punteroAHead = nuevoNodo;

}

void quitarNodoAlPrincipio(nodo ** punteroAHead){
    nodo * temporal = (*punteroAHead)->proximo;
    free(* punteroAHead);

    * punteroAHead = temporal;
}

void quitarUltimoNodo(nodo * head){
    nodo ** actual = &head;

    while((*actual)->proximo->proximo != NULL){
        actual = &((*actual)->proximo);
    }

    free(*actual);
    * actual = NULL;
}

int quitarUnNodoPuntual(nodo ** punteroAHead, int valorDelNodo){ 
    nodo * segundoPuntero = (*punteroAHead)->proximo;
    bool valorPresente = false;

    if((*punteroAHead)->valor == valorDelNodo){
        free(*punteroAHead);
        *punteroAHead = segundoPuntero;
        return 0;
    }
    
    while(segundoPuntero->proximo != NULL){
/*
        if((*punteroAHead)->valor == valorDelNodo){
            valorPresente = true;
        }*/

        punteroAHead = &((*punteroAHead)->proximo);
        segundoPuntero = segundoPuntero->proximo;

        if((*punteroAHead)->valor == valorDelNodo){
            free(*punteroAHead);
            *punteroAHead = segundoPuntero;
            valorPresente = true;
            break;
        }
    }

    if(!valorPresente){
        printf("El nodo solicitado no se encuentra en la lista\n");
        return 1;
    }
    /*
    free(*punteroAHead);
    *punteroAHead = segundoPuntero;*/

    return 0;
}