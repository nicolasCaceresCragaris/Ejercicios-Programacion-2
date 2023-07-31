#include <iostream>
#include <stdlib.h>




using namespace std;


int contarLargo(const char *cadena){

    int longitud=0;

    while(*(cadena++)){
        longitud++;
    }
    return longitud;
}




int main()
{
    /*Dada una cadena, cuya longitud máxima es de 80 caracteres, y utilizando sólo sintaxis de
punteros, devolver la cadena inversa.
    */


    char cadena[80];
    char aux;
    char auxB;
    int longitud=0;
    int i=0;

    printf("Ingrese una cadena \n");
    scanf("%s",cadena);

    longitud=contarLargo(cadena);

    while(i<=(longitud/2)-1){
        aux=*(cadena+i);
        printf("%c \n",aux);
        auxB=*(cadena+longitud-i-1);
        printf("%c \n",auxB);
        *(cadena+i)=auxB;
        *(cadena+longitud-i-1)=aux;
        i++;
    }

    printf("%s \n",cadena);


    return 0;

}
