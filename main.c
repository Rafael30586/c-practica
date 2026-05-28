#include <stdio.h>
#include <stdbool.h>

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

    // Constantes
    const int constante = 13;

    // Booleanos

    bool verdadero = true;
    printf("¿Es verdadero?: ");
    printf("%d\n",verdadero);

    // Condicionales if else

    if(pi > 3.0){
        printf("pi es mayor\n");
    }else{
        printf("pi es menor\n");
    }

    // Switch

    switch(estaciones){
        case 1: printf("Es una sola estación\n");break;
        case 2: printf("Son dos estaciones\n");break;
        case 3: printf("Son tres estaciones\n");break;
        case 4: printf("Son cuatro estaciones\n");break;
        default: printf("Son muchas estaciones\n    ");break;
    }

    // Bucle while

    int contador = 10;
    while(contador > 3){
        printf("Hola\n");
        contador-=2;
    }

    // Bucle for

    for(int i=0;i<5;i++){
        printf("Vuelta: ");
        printf("%d\n",i);
    }

    // Arrays

    int numeros[] = {45,10,48,92,55,60};

    int tamanioDelArray = (sizeof(numeros)/sizeof(numeros[0]));

    printf("El tamaño del array es: ");
    printf("%d\n",tamanioDelArray);

    // Strings, en C los strings son arrays de char 

    char saludo[] = "Hola mundo";
    printf("%s\n",saludo);

    char personaje[] = {'k','i','r','b','y','\0'};
    printf("%s\n",personaje);

    // Entrada del usuario
    int edad;
    printf("¿Cuantos años tenés?\n");
    scanf("%d",&edad);
    printf("Así que tenés ");
    printf("%d",edad);
    printf(" años, eh\n");

    // Direcciones de memoria
    printf("La dirección de memoria de estacione;s es:");
    printf("%p\n",&estaciones);
    printf("La dirección de memoria de pi es:");
    printf("%p\n",&pi);
    printf("La dirección de memoria de personaje[2] es:");
    printf("%p\n",&personaje[2]);
    printf("La dirección de memoria de personaje[3] es:");
    printf("%p\n",&personaje[3]);

    // Punteros

    int puntaje = 10;
    int *ptr = &puntaje;
    printf("La dirección de memoria del puntaje es: ");
    printf("%p\n",ptr);
    printf("El valor al que apunta el puntero ptr es: ");
    printf("%d\n",*ptr);
    printf("Imprimiendo la dirección de memoria del puntero: ");
    printf("%p\n",&ptr);
    
    printf("Imprimiendo el array: ");
    printf("%p\n",numeros);
    printf("Dirección de memoria del primer elemento del array: ");
    printf("%p\n",&numeros[0]);

    int *puntero = numeros;
    printf("Puntero a números: ");
    printf("%d\n",*puntero);
    puntero = puntero + 2;
    printf("Puntero a números después de suma: ");
    printf("%d\n",*puntero);

    int *puntero1 = &numeros[1];
    int *puntero2 = &numeros[4];
    printf("Distancia entre puntero1 y puntero2: ");
    printf("%d\n",puntero2 - puntero1);

    int diasDeLaSemana = 7;
    int *puntero3 = &diasDeLaSemana;
    int **puntero4 = &puntero3;
    printf("Días de la semana: %d\n", diasDeLaSemana);
    printf("Puntero3: %p\n",puntero3);
    printf("Puntero4: %p\n",puntero4);
    printf("Adonde apunta puntero4: %d\n",**puntero4);

    return 0;
}