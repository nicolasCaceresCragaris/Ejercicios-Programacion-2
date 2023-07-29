#include <iostream>

using namespace std;

int main()
{

    /*
    Declarar una variable que sea puntero a un número entero y luego ...
a) Imprimir por pantalla la dirección de memoria.
b) Imprimir su valor.
c) Asignar dinámicamente espacio en memoria.
d) Imprimir nuevamente su valor.
e) Imprimir el valor que se encuentra en el espacio asignado dinámicamente.
    */

    int valor=20;
    int *punteroEntero=&valor;


    printf("Direccion de valor 1:%p \n",&valor);
    printf("Direccion que almacena el puntero:%p \n",punteroEntero);
    printf("Direccion del puntero:%p \n",&punteroEntero);
    printf("Valor :%d \n",*punteroEntero);

    int valorDos=40;
    punteroEntero=&valorDos;
    printf("Direccion de valor 2:%p \n",&valorDos);
    printf("Direccion que almacena el puntero:%p \n",punteroEntero);
    printf("Direccion del puntero :%p \n",&punteroEntero);
    printf("Valor :%d \n",*punteroEntero);


    return 0;
}
