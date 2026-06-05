#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Coche{
    char marca[20];
    int anio;
};

int main(){

    int *estudiantes;
    int cantidadEstudiantes = 12;
    estudiantes = calloc(cantidadEstudiantes, sizeof(*estudiantes));

    estudiantes[1] = 20;
    estudiantes[3] = 45;

    for(int i = 0; i < 12; i++){
        printf("Estudiante número: %d\n",estudiantes[i]);
    }

    int *estudiantes2 = realloc(estudiantes, 20);
    // printf("%d",estudiantes2[18]);

    for(int i = 0;i < 20; i++){
        printf("Número de estudiante (parte 2): %d\n",estudiantes2[i]);
    }

    free(estudiantes);
    free(estudiantes2);

    struct Coche *ptr = (struct Coche*) malloc(sizeof(struct Coche)); // Asignación de memoria para una estructura de Coche

    if(ptr == NULL){ // Revisando si la asignación ha sido exitosa
        printf("La asignación de memoria falló \n");
        return 1;
    }

    strcpy(ptr->marca, "Honda"); // Estableciendo valores
    ptr->anio = 2022;

    printf("Marca: %s\n", ptr->marca); // Impresión de valores
    printf("Año: %d\n", ptr->anio); // Por alguna razón estos valores no se están imprimiendo

    free(ptr);

    return 0;
}
