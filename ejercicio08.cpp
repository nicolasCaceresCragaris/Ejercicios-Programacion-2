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
    FILE* archivoListado=fopen("listado.txt","wt");

    Alumno leido;

    fread(&leido,sizeof(Alumno),1,archivoInscripciones);

    while(!feof(archivoInscripciones)){

        fprintf(archivoListado,"%s %s %d %d\n",leido.nombre,leido.apellido,leido.numeroLegajo,leido.codigoMateria);

        fread(&leido,sizeof(Alumno),1,archivoInscripciones);

    }

    fclose(archivoInscripciones);
    fclose(archivoListado);
    return 0;
}
