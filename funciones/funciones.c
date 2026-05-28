#include <stdio.h>

void saludar();
void saludar2();
void saludar3();
int sumar(int, int);


int restarleALaSuma(int, int, int, int (int,int));

int main(){

    saludar();

    int suma;
    suma = sumar(3,7);
    printf("El resultado de la suma es %d\n",suma);

    int (*puntero) (int, int);
    puntero = sumar;
    suma = puntero(34,91);
    printf("El resultado de la suma es: %d\n",suma);

    int sumaRestada = restarleALaSuma(23,56,12,sumar);
    printf("La suma restada es: %d\n",sumaRestada);

    void (*saludos[3])() = {saludar, saludar2, saludar3};

    for(int i=0; i<3; i++){
        saludos[i]();
    }

    return 0;
}

void saludar(){
    printf("Hola\n");
}

void saludar2(){
    printf("Buen día\n");
}

void saludar3(){
    printf("Chau\n");
}

int sumar(int x, int y){
    return x + y;
}

int restarleALaSuma(int x, int y ,int a, int (*funcion) (int,int)){
    int suma2 = funcion(x,y);
    return suma2 - a;
}


