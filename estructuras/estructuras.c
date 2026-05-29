#include <stdio.h>

struct persona{
    int dni;
    char primerLetraApellido;
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

    
    return 0;

}
