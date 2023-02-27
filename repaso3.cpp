#include <iostream>
#include <string.h>


using namespace std;


struct Usuario{

    char nombre[41];
    char apellido[41];
    int edad;

};

void cargarUsuarios(Usuario vec[]){

    for(int i=0; i<5;i++){

        printf("Ingrese el nombre \n");
        scanf("%s",vec[i].nombre);

        printf("Ingrese el apellido \n");
        scanf("%s",vec[i].apellido);

        printf("Ingrese la edad \n");
        scanf("%d",&vec[i].edad);
    }

    return;
}

void mostrarUsuarios(Usuario vec[]){

    printf("============================== \n");
    printf("Mostrando datos \n");

    for(int i=0; i<5;i++){

        printf("%s %s Edad:%d  \n",vec[i].nombre,vec[i].apellido,vec[i].edad);

    }

    return;

}

void ordenarPorEdad(Usuario vec[]){

    Usuario aux;

    for(int i=0;i<5-1;i++){
        for(int j=0;j<5-i-1;j++){
            if(vec[j].edad<vec[j+1].edad){
                aux=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=aux;

            }
        }
    }


    return;
}

int main()
{
    Usuario usuarios[5];

    cargarUsuarios(usuarios);
    mostrarUsuarios(usuarios);
    ordenarPorEdad(usuarios);
    mostrarUsuarios(usuarios);

    return 0;
}
