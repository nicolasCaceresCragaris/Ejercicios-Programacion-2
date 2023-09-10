#include <iostream>
#include <string.h>


using namespace std;

struct Alumno{

    char nombre[25];
    char apellido[25];
    int numeroLegajo;
    int codigoMateria;
    int dia;
    int anio;
    int mes;

};



int main()
{

    FILE* archivoInscripciones=fopen("diafinales.dat","rb");
    


    Alumno alumnoLeido;

    
    printf("Ingrese nombre \n");
    scanf("%s",alumnoLeido.nombre);

    printf("Ingrese apellido \n");
    scanf("%s", alumnoLeido.apellido);
    

    

    while(strcmp(alumnoLeido.nombre,"NULL")!=0 && (strcmp(alumnoLeido.apellido,"NULL")!=0)){

        printf("Ingres legajo \n");
        scanf("%d",&alumnoLeido.numeroLegajo);

        printf("Ingrese codigo de materia \n");
        scanf("%d",&alumnoLeido.codigoMateria);

        printf("Ingrese dia del examen \n");
        scanf("%d",&alumnoLeido.dia);

        printf("Ingrese mes del examen \n");
        scanf("%d",&alumnoLeido.mes);

        printf("Ingrese anio del examen \n");
        scanf("%d",&alumnoLeido.anio);

        fwrite(&alumnoLeido,sizeof(Alumno),1,archivoInscripciones);

        printf("Ingrese nombre \n");
        scanf("%s",alumnoLeido.nombre);

        printf("Ingrese apellido \n");
        scanf("%s", alumnoLeido.apellido);


    }

    fclose(archivoInscripciones);
   



    return 0;
}
