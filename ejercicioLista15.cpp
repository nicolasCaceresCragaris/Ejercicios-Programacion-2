#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Alumno{
    char nombre[15];
    char apellido[15];
    int legajo;
    int division;
};

struct Nodo{
    Alumno dato;
    Nodo *siguiente;

};

void crearLista(Nodo **lista){
    printf("Lista creada exitosamente\n");
    lista=NULL;
    return;
}

/*
Nodo *insertInFront(Nodo **lista,int dato){

    Nodo *nodo=(Nodo*)(malloc(sizeof(Nodo)));
    nodo->dato=dato;
    nodo->siguiente=NULL;

    nodo->siguiente=*lista;
    *lista=nodo;
    printf("Insertado en el frente \n");
    return nodo;
}
*/
int countNodos(Nodo*lista){
    int counter=0;
    while(lista!=NULL){
        counter++;
        lista=lista->siguiente;
    }
   return counter;
}


void printList(Nodo*lista){

    int div=lista->dato.division;

    while(lista!=NULL){

                if(div!=lista->dato.division){
                    printf("---------------------------\n");
                    div=lista->dato.division;
                }

                printf("%s %s %d %d \n",lista->dato.nombre,lista->dato.apellido,lista->dato.legajo,lista->dato.division);
                lista=lista->siguiente;


    }


    return;
}

void clearList(Nodo **lista){

    Nodo *aux=NULL;
    while(*lista!=NULL){
        aux=*lista;
        *lista=(*lista)->siguiente;
        free(aux);
    }
    return;
}

FILE* abrir(const char* name,const char* mode){

    FILE* archivo=fopen(name,mode);

    if(archivo==NULL){
        printf("El archivo no se pudo abrir \n");
        exit(EXIT_FAILURE);
    }

    return archivo;
}

void leer(Alumno &alumno,FILE* archivo){
    fread(&alumno,sizeof(Alumno),1,archivo);
}

Nodo *insertarOrdenado(Nodo** lista,Alumno alumno){

    Nodo* nodoAux=(Nodo*)(malloc(sizeof(Nodo)));

    nodoAux->dato=alumno;
    nodoAux->siguiente=NULL;

    Nodo *listaAuxiliar=*lista;
    Nodo *nodoAnterior=NULL;

    while(listaAuxiliar!=NULL && alumno.division>listaAuxiliar->dato.division){

        nodoAnterior=listaAuxiliar;
        listaAuxiliar=listaAuxiliar->siguiente;
    }

    if(nodoAnterior==NULL){

        *lista=nodoAux;
    }
    else{
        nodoAnterior->siguiente=nodoAux;
    }

    nodoAux->siguiente=listaAuxiliar;

    return nodoAux;

}


int main()
{

    Nodo *lista;
    crearLista(&lista);

    Alumno alumnoLeido;

    FILE* archivoAlumnos=abrir("alumnos.dat","rb");

    leer(alumnoLeido,archivoAlumnos);

    while(!feof(archivoAlumnos)){


        insertarOrdenado(&lista,alumnoLeido);

        leer(alumnoLeido,archivoAlumnos);
    }

    printList(lista);
    clearList(&lista);

    return 0;
}
