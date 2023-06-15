#include <iostream>
#include <stdlib.h>
#include <string.h>



struct Alumno{

    int legajo;
    int codigoMateria;
    char nombre[30];
};


using namespace std;


void crearArchivo(Alumno vecAlumnos[],int n,Alumno vecAlDia[]){

    FILE *archivoNuevo=fopen("alumnosInscriptos.dat","wb");
    FILE *archivoNuevoDos=fopen("alumnosDelDia.dat","wb");

    for(int i=0; i<n;i++){

        fwrite(&vecAlDia[i],sizeof(Alumno),1,archivoNuevoDos);
        fwrite(&vecAlumnos[i],sizeof(Alumno),1,archivoNuevo);

    }

    printf("Creacion de archivos exitosa \n");
    fclose(archivoNuevo);
    fclose(archivoNuevoDos);


    return;
}

void revisarArchivos(){

    Alumno alumnoLeido;

    FILE *archivoNuevo=fopen("alumnosInscriptos.dat","rb");

    printf("MOSTRANDO ARCHIVO DE ALUMNOS INSCRIPTOS \n");


    fread(&alumnoLeido,sizeof(Alumno),1,archivoNuevo);

    while(!feof(archivoNuevo)){


        printf("%d \t %d \t %s \n",alumnoLeido.codigoMateria,alumnoLeido.legajo,alumnoLeido.nombre);
        fread(&alumnoLeido,sizeof(Alumno),1,archivoNuevo);

    }

    fclose(archivoNuevo);


    FILE *archivoNuevoDos=fopen("alumnosDelDia.dat","rb");

    printf("MOSTRANDO ARCHIVO DE INSCRIPS DEL DIA \n");


    fread(&alumnoLeido,sizeof(Alumno),1,archivoNuevoDos);

    while(!feof(archivoNuevoDos)){


        printf("%d \t %d \t %s \n",alumnoLeido.codigoMateria,alumnoLeido.legajo,alumnoLeido.nombre);
        fread(&alumnoLeido,sizeof(Alumno),1,archivoNuevoDos);

    }


    fclose(archivoNuevoDos);


    return;
}

int main(){

    Alumno alumnosInscriptos[15]={
    {1000,1,"German Cano"},
    {1001,1,"Alan Ruiz"},
    {1002,1,"Paolo Sanz"},
    {1003,1,"Gabriel Silva"},
    {1004,2,"Hector Darwin"},
    {1005,2,"Hugo Ibarra"},
    {1006,3,"Gaston Salazar"},
    {1007,3,"Emanuel Noir"},
    {1008,3,"Tomas Aliens"},
    {1009,3,"Alejandro Pepe"},
    {1010,4,"Paris Hilton"},
    {1011,4,"Barak Obama"},
    {1012,4,"Tame Impala"},
    {1013,4,"El Doctor"},
    {1014,5,"William Wallace"}
    };


    Alumno inscriptosDia[15]={
    {2222,1,"Omar Varela"},
    {2111,1,"Alan Gomez"},
    {2333,1,"Marcelo Guti"},
    {2999,1,"Silvia Suller"},
    {2131,2,"Ricardo Bizzi"},
    {2391,2,"Pocho Nassuti"},
    {2193,3,"Igor Igores"},
    {2301,3,"Flor Florencia"},
    {2030,3,"Simon Unai"},
    {2303,3,"Juan Alvarez"},
    {2642,4,"Simon Perez"},
    {2959,4,"Paola Argento"},
    {2910,4,"India Iridica"},
    {2777,4,"Fanny Lafan"},
    {2311,5,"Lalo Landas"}
    };


    int opcion=0;

    printf("Ingrese 1 para reescribir los archivos iniciales \n");
    printf("Ingrese 2 para revisar los archivos iniciales \n");
    scanf("%d",&opcion);

    if(opcion==1){
        crearArchivo(alumnosInscriptos,15,inscriptosDia);
    }
    if(opcion==2){
        revisarArchivos();
    }


    FILE* archivoUno=fopen("alumnosInscriptos.dat","rb");
    FILE* archivoDos=fopen("alumnosDelDia.dat","rb");
    FILE* archivoFinal=fopen("alumnosActualizado.dat","wb+");

    Alumno alumnoUnoLeido;
    Alumno alumnoDosLeido;

    fread(&alumnoUnoLeido,sizeof(Alumno),1,archivoUno);
    fread(&alumnoDosLeido,sizeof(Alumno),1,archivoDos);

    while(!feof(archivoUno) && !feof(archivoDos)){

        if(alumnoUnoLeido.codigoMateria<=alumnoDosLeido.codigoMateria){

            fwrite(&alumnoUnoLeido,sizeof(Alumno),1,archivoFinal);
            fread(&alumnoUnoLeido,sizeof(Alumno),1,archivoUno);
        }
        if(alumnoDosLeido.codigoMateria<alumnoUnoLeido.codigoMateria){

            fwrite(&alumnoDosLeido,sizeof(Alumno),1,archivoFinal);
            fread(&alumnoDosLeido,sizeof(Alumno),1,archivoDos);
        }
    }

    if(feof(archivoDos)){
        while(!feof(archivoUno)){



            fwrite(&alumnoUnoLeido,sizeof(Alumno),1,archivoFinal);
            fread(&alumnoUnoLeido,sizeof(Alumno),1,archivoUno);

        }
    }

    if(feof(archivoUno)){
        while(!feof(archivoDos)){

            fwrite(&alumnoDosLeido,sizeof(Alumno),1,archivoFinal);
            fread(&alumnoDosLeido,sizeof(Alumno),1,archivoDos);

        }
    }

    fclose(archivoUno);
    fclose(archivoDos);

    //MOSTRAR EL ARCHIVO COMPLETO

    fseek(archivoFinal,0,SEEK_SET);

    fread(&alumnoUnoLeido,sizeof(Alumno),1,archivoFinal);
    while(!feof(archivoFinal)){
        printf("%d \t %d \t %s \n",alumnoUnoLeido.codigoMateria,alumnoUnoLeido.legajo,alumnoUnoLeido.nombre);
        fread(&alumnoUnoLeido,sizeof(Alumno),1,archivoFinal);
    }

    fclose(archivoFinal);
    printf("Fin del programa \n");

    return 0;
}
