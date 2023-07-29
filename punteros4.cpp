#include <iostream>
#include <string.h>


struct Persona{
    char nombre[30];
    int edad;
};


using namespace std;

void imprimir(Persona persona){

    printf("ENTRANDO EN LA FUNCION \n");

    printf("Nombre: %s\n",persona.nombre);
    printf("Edad: %d \n ",persona.edad);


    strcpy(persona.nombre,"Goku");
    persona.edad=20;

    printf("Nombre: %s\n",persona.nombre);
    printf("Edad: %d \n ",persona.edad);

    printf("SALIENDO DE LA FUNCION \n");

    return;
};


int main()
{

    /*
    Declarar un struct que defina una variable del tipo vector de caracteres, llamada nombre, y otra
que sea del tipo entero, llamada edad y ...
a) En la función main, asigne el valor “Kokumo” y “30” para nombre y edad respectivamente.
b) Luego, invoque una función que reciba el struct por parámetro y que imprima el valor de
ambas variables del struct.
c) Dentro de esa misma función, cambie los valores de las variables en cuestión y muestre
nuevamente sendos valores.
d) De regreso en el main, e inmediatamente después de la llamada a la función, imprima los
valores del struct; analice qué valores se imprimieron en pantalla.
    */

    Persona personaUno;

    strcpy(personaUno.nombre,"Kokumo");
    personaUno.edad=30;

    imprimir(personaUno);

    printf("Nombre: %s\n",personaUno.nombre);
    printf("Edad: %d \n ",personaUno.edad);

    return 0;

}

//RESPUESTA
/*
Al pasarlo justamente por parametro estoy enviando una copia del struct, no la direccion donde se almacenan los datos del main por eso no
se actualizan los cambios. Al pasarlo por referencia si cambia.
*/
