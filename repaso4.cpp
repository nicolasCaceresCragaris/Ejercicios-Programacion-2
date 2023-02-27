#include <iostream>
#include <string.h>

using namespace std;

struct Cliente{

    char nombre[41];
    char apellido[41];
    int legajo;
    char tramite;
};


int main(){

    Cliente cliente;
    Cliente primero;
    Cliente legajoMasBajo;
    int contador=0;
    int contVac=0;
    int contSal=0;
    int contMed=0;


    printf("Ingrese un nombre \n");
    scanf("%s",cliente.nombre);

    while(strcmp(cliente.nombre,"FIN")!=0){
        contador++;

        printf("Ingrese un apellido \n");
        scanf("%s",cliente.apellido);

        printf("Ingrese el legajo \n");
        scanf("%d",&cliente.legajo);

        printf("Ingrese el tipo de tramite S:salario V:vaciones: M:covertura medica \n");
        scanf(" %c",&cliente.tramite);


        if(contador==1){
            primero=cliente;
            legajoMasBajo=cliente;
        }
        if(contador>1 && legajoMasBajo.legajo>cliente.legajo){
            legajoMasBajo=cliente;
        }

        if(cliente.tramite=='V'){
            contVac++;
        }
         if(cliente.tramite=='M'){
            contMed++;

        }
        if(cliente.tramite=='S'){
            contSal++;
        }

        printf("Ingrese un nombre \n");
        scanf("%s",cliente.nombre);

    }

    printf("============================================ \n");

    printf("Primer persona en ser atendida: %s %s %d\n",primero.nombre,primero.apellido,primero.legajo);
    printf("Legajo mas bajo: %s %s %d\n",legajoMasBajo.nombre,legajoMasBajo.apellido,legajoMasBajo.legajo);
    printf("Cantidad atendida: %d \n",contador);
    printf("Segun tramite: \n");
    printf("Salario: %d \n",contSal);
    printf("Vacaciones: %d \n",contVac);
    printf("Covertura medica: %d \n",contMed);

    return 0;
}
