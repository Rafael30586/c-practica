#include<stdio.h>
#include<stdlib.h>

int main(){

    int *estudiantes;
    int cantidadEstudiantes = 12;
    estudiantes = calloc(cantidadEstudiantes, sizeof(*estudiantes));

    /*for(int i = 0; i < 12; i++){
        estudiantes[i] = 0;
    }*/

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

    return 0;
}
