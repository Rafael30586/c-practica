#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *next;
} node_t;

void print_list(node_t *);
void push(node_t *, int);
void pushAtTheBeginning(node_t **, int);
int pop(node_t **);

int main(){
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t)); 

    if(head == NULL){
        return 1;
    }

    // head es un puntero que apunta al primer nodo de la lista

    head->val = 1; // Estableciendo valor de la cabeza
    head->next = NULL;

    // printf("Probando: %d\n",head->val); // retorna 1
    // printf("Probando: %p\n",&head); // retorna la dirección de memoria de la variable
    // printf("Probando: %p\n",head); // retorna la dirección de memoria a la que apunta

    head->next = (node_t *) malloc(sizeof(node_t)); // Añadiendo otro elemento a la lista
    head->next->val = 2;
    head->next->next = NULL;

    head->next->next = (node_t *) malloc(sizeof(node_t)); // Añadiendo otro elemento
    head->next->next->val = 3;
    head->next->next->next = NULL;

    print_list(head);

    push(head, 4);
    print_list(head);
/*
    node_t ** punteroAHead = &head; // Creando puntero a head para pasar como argumento a la función
    pushAtTheBeginning(punteroAHead, 1782);
    print_list(head);*/

    pushAtTheBeginning(&head, 729); // Pasamos la dirección en memoria de head
    print_list(head);

    pop(&head);
    print_list(head);
    
    return 0;
}

void print_list(node_t * head){ // Función para imprimir los valores de los nodos
    node_t * current = head;

    while(current != NULL){
        printf("%d\n", current->val);
        current = current->next;
    }

    printf("Fin de la lista\n");
}

void push(node_t * head, int val){ // Función para insertar un nodo al final de la lista

    node_t * current = head;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;

}

void pushAtTheBeginning(node_t ** punteroAHead, int val){ // Función para insertar un nodo al principio de la lista
    // Se pasa la dirección de memoria de head como argumento
    node_t * new_node = (node_t *) malloc (sizeof(node_t)); // Asignando memoria para el nuevo nodo

    new_node->val = val; // estableciendo el valor para el nuevo nodo
    new_node->next = *punteroAHead; // el nuevo nodo apunta a lo que era, anteriormente, el head
    *punteroAHead = new_node; // el nuevo head es ahora el nuevo nodo
}


int pop(node_t ** direccionDeHead){
    int retval = -1;
    node_t * next_node = NULL; 

    if(*direccionDeHead == NULL){
        return -1;
    }

    next_node = (*direccionDeHead)->next;
    retval = (*direccionDeHead)->val;
    free(*direccionDeHead);
    *direccionDeHead = next_node;

    return retval;
}
