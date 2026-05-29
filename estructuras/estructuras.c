#include <stdio.h>

struct persona{
    int dni;
    char primerLetraApellido;
};

struct obra{
    int anioLanzamiento;
    char primeraLetraDelNombre;
};

struct personaje{
    char primeraLetraDelNombre;
    struct obra obra;
};

union otraPersona{
    int dni;
    char primeraLetraDelNombre;
};

int main(){

    struct persona p1;
    p1.dni = 32361730;
    p1.primerLetraApellido = 'A';

    printf("El DNI es: %d\n",p1.dni);
    printf("La primera letra del apellido es: %c\n",p1.primerLetraApellido);

    struct persona p2 = {40192886, 'F'};
    printf("El DNI es: %d\n",p2.dni);
    printf("La primera letra del apellido es: %c\n",p2.primerLetraApellido);

    struct persona p3 = p2;
    printf("El DNI es: %d\n",p2.dni);
    printf("La primera letra del apellido es: %c\n",p2.primerLetraApellido);

    struct obra o1 = {2006, 'F'};
    struct personaje per1 = {'B',o1};
    // per1.primeraLetraDelNombre = 'B';
    // per1.obra = o1;
    printf("Primera letra del nombre es: %c\n",per1.primeraLetraDelNombre);
    printf("El año de lanzamiento de su obra es: %d\n",per1.obra.anioLanzamiento);

    struct personaje *punteroPersonaje = &per1;
    punteroPersonaje->primeraLetraDelNombre = 'R';
    printf("Letra del personaje cambiada: %c\n", per1.primeraLetraDelNombre);

    union otraPersona p4;
    p4.dni = 59100271;
    p4.primeraLetraDelNombre = 'T';
    printf("Primera letra del nombre de la persona %c\n",p4.primeraLetraDelNombre);
    printf("DNI de la persona %d\n", p4.dni);
    printf("Tamaño de unión: %zu bytes\n",sizeof(p4));

    
    return 0;

}
