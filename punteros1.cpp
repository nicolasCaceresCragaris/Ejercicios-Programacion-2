#include <iostream>

using namespace std;

int main()
{

    /*
    Declarar una variable entera, un vector de caracteres de diez posiciones y una variable con
    soporte de decimales y ...
    a) Asignarle valores.
    b) Imprimir el valor de cada una.
    c) Imprimir la dirección de memoria de cada una.
    */

    int variableEntera=0;
    char vec[10]={'H','O','L','A','M','U','N','D','O','\0'};
    float variableFlotante=0;

    variableEntera=20;
    variableFlotante=13.13;

    printf("Direccion variable entera:%p \n", &variableEntera);

    printf("Direccion variable flotante:%p \n", &variableFlotante);

    printf("Direcciones del vector \n");
    for(int i=0;i<10;i++){
        printf("Pos %d Direccion %p \n",i,&vec+i);
    }



    return 0;
}
