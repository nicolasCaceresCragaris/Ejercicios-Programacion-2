#include <iostream>





using namespace std;


int longitudPalabra(const char *cadena){
    int longitud=0;

    while(*(cadena++)){

        longitud++;
    }

    return longitud;

};


int main()
{
    /*
    Dado una cadena, cuya longitud máxima es de 80 caracteres, y utilizando sólo sintaxis de
punteros, determinar si la cadena es o no un palíndromo. Ejemplo:
NEUQUEN → verdadero
CHUBUT → falso
    */

    char cadena[30];
    scanf("%s",cadena);


    int largo=0;
    int counter=0;
    bool esPalindromo=true;


    largo=longitudPalabra(cadena);


    //SI ES PALABRA CON CANTIDAD DE LETRAS PAR
    if(largo%2==0){

        while(counter<=largo/(2-1)){
            if((*(cadena+counter)) != (*(cadena+largo-counter-1))){

                esPalindromo=false;

            }
            counter++;

        }
    }
    if(largo%2!=0){

        while(counter<=largo/(2-1)){
            if((*(cadena+counter)) != (*(cadena+largo-counter-1))){

                esPalindromo=false;

            }
            counter++;

        }


    }

    if(esPalindromo==true){
        printf("La palabra es un palindromo de %d letras \n",largo);
    }
    if(esPalindromo==false){
        printf("La palabra no es un palindromo \n");
    }

    printf("FIN DEL PROGRAMA \n");


    return 0;

}
