#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
    int valor;
    struct Nodo * proximo;
} nodo;

void imprimirLista(nodo *);
void agregarNodo(nodo *,int);

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

    nodo * actual = head;

    while(actual->proximo != NULL){
        actual = actual->proximo;
    }

    actual->proximo = nuevoNodo;

}