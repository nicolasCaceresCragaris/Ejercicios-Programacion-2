#include <iostream>
#include <string.h>

#define LEGAJO_INICIAL 80001

using namespace std;

struct Alumno{

    char nombre[25];
    char apellido[25];
    int numeroLegajo;
    int codigoMateria;
    int dia;
    int mes;
    int anio;


};

int obtenerPosicion(int legajo);


int main()
{
    /*
    Alumno listadoAlumnos[20]={
    {"Carlos","Solari",81121,2,22,7,2023},
    {"Cesar","Agusto",83123,3,23,7,2023},
    {"Luis","Gonzales",94123,2,22,7,2023},
    {"Federico","Martinez",95212,1,21,7,2023},
    {"Nicolas","Caceres",80001,3,23,7,2023},
    {"Hernan","Crespo",94212,2,22,7,2023},
    {"Salomon","Rondon",85211,1,21,7,2023},
    {"Julio","Sosa",84123,3,23,7,2023},
    {"Facundo","Toranzo",89412,2,22,7,2023},
    {"Martin","Sicioli",93312,1,21,7,2023},
    {"Carlos","Arguello",81122,2,22,7,2023},
    {"Anibal","Fernandez",83124,3,23,7,2023},
    {"Luis","Castro",84124,2,22,7,2023},
    {"Salome","Indigo",95213,1,21,7,2023},
    {"Juan","Benitez",81332,3,23,7,2023},
    {"Marco","Polo",94215,2,22,7,2023},
    {"Gaston","Gaudio",85213,1,21,7,2023},
    {"German","Gimenez",94125,3,23,7,2023},
    {"Facundo","Colidio",109000,2,22,7,2023},
    {"Martin","Carabobo",93317,1,21,7,2023}
    };
*/

    FILE* archivoInscriptos=fopen("inscriptos.dat","rb");

/*
    for(int i=0;i<20;i++){
        fwrite(&listadoAlumnos[i],sizeof(Alumno),1,archivoInscriptos);
    }

*/


    FILE* archivoOrdenado=fopen("ordenados.dat","wb+");

    Alumno alumnoLeido;

    fread(&alumnoLeido,sizeof(Alumno),1,archivoInscriptos);

    while(!feof(archivoInscriptos))
    {

        fseek(archivoOrdenado,(sizeof(Alumno)*obtenerPosicion(alumnoLeido.numeroLegajo)),SEEK_SET);

        fwrite(&alumnoLeido,sizeof(Alumno),1,archivoOrdenado);
        fread(&alumnoLeido,sizeof(Alumno),1,archivoInscriptos);
    }


    fflush(archivoOrdenado);

    fseek(archivoOrdenado,0,SEEK_SET);


    fread(&alumnoLeido,sizeof(Alumno),1,archivoOrdenado);

    printf("LEGAJO \t NOMBRE \t APELLIDO \n");
    while(!feof(archivoOrdenado))
    {
        if(alumnoLeido.numeroLegajo!=0)
        {
        printf("%d \t %s \t %s \n",alumnoLeido.numeroLegajo,alumnoLeido.nombre,alumnoLeido.apellido);
        }
        fread(&alumnoLeido,sizeof(Alumno),1,archivoOrdenado);
    }

    fclose(archivoInscriptos);
    fclose(archivoOrdenado);


    return 0;
}


int obtenerPosicion(int legajo){

    return legajo-LEGAJO_INICIAL;
}
