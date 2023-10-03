#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define MAX_CURSOS 20
#define MAX_ALUMNOS 40


using namespace std;


struct Cursos{

    int codigo;
    int totalAlumnos;
};

struct Alumno{
    int codigoCurso;
    int legajo;
    float nota;
};

struct Contador{

    int total;
    int aprobados;
    int desaprobados;

};

FILE* abrir(const char* name, const char* mode);

int main()
{

    FILE* archivoCursos=abrir("cursos.dat","rb");
    FILE* archivoAlumnos=abrir("alumnos.dat","rb");

    int contador[10]={0,0,0,0,0,0,0,0,0,0};
    int nota=0;
    float porcentajeAprobado=0;
    float porcentajeDesaprobado=0;


    Contador aprobados[20]={0};

    Alumno alumnoLeido;

    fread(&alumnoLeido,sizeof(Alumno),1,archivoAlumnos);

    while(!feof(archivoAlumnos)){

        nota=alumnoLeido.nota;
        contador[nota-1]++;

        aprobados[alumnoLeido.codigoCurso-1].total++;

        if(alumnoLeido.nota>=7){
            aprobados[alumnoLeido.codigoCurso-1].aprobados++;
        }
        if(alumnoLeido.nota<=6){
            aprobados[alumnoLeido.codigoCurso-1].desaprobados++;
        }

        fread(&alumnoLeido,sizeof(Alumno),1,archivoAlumnos);
    }

    printf("CODIGO\t APROBADOS \t  DESAPROBADOS \t TOTAL\n");
    for(int i=0;i<MAX_CURSOS;i++){

        porcentajeAprobado=(aprobados[i].aprobados*100)/aprobados[i].total;
        porcentajeDesaprobado=(aprobados[i].desaprobados*100)/aprobados[i].total;

        printf("%d\t %f \t %f \t %d \n",i+1,porcentajeAprobado,porcentajeDesaprobado,aprobados[i].total);

    }

    fclose(archivoCursos);
    fclose(archivoAlumnos);

    return 0;
}


FILE* abrir(const char* name, const char* mode){

    FILE* archivo=fopen(name,mode);

    if(archivo==NULL){
        printf("Error al abrir\n");
        exit(EXIT_FAILURE);
    }
    return archivo;
};
