#include <stdio.h>

int main(){
    printf("Hola mundo\n");  // Esto es un comentario
    printf("usando el lenguaje C\n");

    int estaciones = 4;
    printf("La cantidad de estaciones es: ");
    printf("%d\n",estaciones);

    float pi = 3.14159;
    printf("El número pi es igual a: ");
    printf("%f\n",pi);
    
    printf("El número pi pero con otro formatter: ");
    printf("%d\n",pi);

    printf("El número pi pero con menos cifras: ");
    printf("%.2f\n",pi);

    char r = 'r';
    printf("Imprimiendo la letra: ");
    printf("%c\n",r);

    double miAltura = 1.82;
    printf("Mi altura es: ");
    printf("%lf\n",miAltura);

    float numeroDeAvogadro = 6.02e23;
    printf("El número de avogadro es: ");
    printf("%f\n",numeroDeAvogadro);

    printf("El tamaño de la variable miAltura en bytes es: ");
    printf("%zu\n", sizeof(miAltura));

    printf("El tamaño de la variable pi en bytes es: ");
    printf("%zu\n", sizeof(pi));

    // Tipos extendidos
    short int unaEdad = 35; // Ocupa 2 bytes, puede ir desde -32768 hasta 32767 y el formatter es %hd
    unsigned int puertosBienConocidos = 1024; // Ocupa 2 o 4 bytes; en el primer caso va desde 0 hasta 65535, y en el segundo va desde 0 hasta 4.294.967.295; el formatter es "%u"
    long int unDni = 40148913; // Ocupa 4 u 8 bytes; maneja números grandísimos; el foprmatter es %ld
    long long int otroDni = 56102831; // Ocupa 8 bytes; maneja números grandísimos; el formatter es %lld
    unsigned long int numero = 2871649; // Ocupa 4 u 8 bytes; maneja números grandísimos; el formatter es %lu
    unsigned long long int otroNumero = 85930129; // Ocupa 8 bytes; maneja números muy grandes; el formatter es %llu
    long double numeraso = 846181903.76; // Ocupa 8, 12 o 16 bytes; los valores dependen de la implementación, pero tiene más precisión qyue double; el formatter es %Lf 

    // Conversión
    float resultado = (float) 5 / 2;
    printf("El resultado de la división es: ");
    printf("%f\n",resultado);

    return 0;
}