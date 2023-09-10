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
    FILE* archivoAnotados=fopen("anotados.dat","wb");

    int codigoMateria=0;
    int cantidadDeRegistros=0;
    int counter=0;

    //DETERMINO LA CANTIDAD DE REGISTROS QUE NECESITO ALMACENAR EN MI VECTOR
    fseek(archivoInscripciones,0,SEEK_END);
    cantidadDeRegistros=ftell(archivoInscripciones)/sizeof(Alumno);
    fseek(archivoInscripciones,0,SEEK_SET);


    Alumno registrosTotales[cantidadDeRegistros];

    printf("Ingrese un codigo de materia \n");
    scanf("%d",&codigoMateria);


    fread(&registrosTotales[counter],sizeof(Alumno),1,archivoInscripciones);

    while(!feof(archivoInscripciones)){
        counter++;
        fread(&registrosTotales[counter],sizeof(Alumno),1,archivoInscripciones);
    }

    for(int i=0; i<cantidadDeRegistros;i++){

        if(registrosTotales[i].codigoMateria==codigoMateria){

            fwrite(&registrosTotales[i],sizeof(Alumno),1,archivoAnotados);
        }

    }

    fclose(archivoAnotados);
    fclose(archivoInscripciones);


    return 0;
}
