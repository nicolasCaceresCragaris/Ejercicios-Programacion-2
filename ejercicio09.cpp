
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

int main()
{
    //CONTENIDO DEL ARCHIVO INSCRIPTOS
    Alumno vecAlumnosUno[10]={
    {"Carlos","Solari",1121,2,22,7,2023},
    {"Cesar","Agusto",3123,3,23,7,2023},
    {"Luis","Gonzales",4123,2,22,7,2023},
    {"Federico","Martinez",5212,1,21,7,2023},
    {"Nicolas","Caceres",1331,3,23,7,2023},
    {"Hernan","Crespo",4212,2,22,7,2023},
    {"Salomon","Rondon",5211,1,21,7,2023},
    {"Julio","Sosa",4123,3,23,7,2023},
    {"Facundo","Toranzo",9412,2,22,7,2023},
    {"Martin","Sicioli",3312,1,21,7,2023}
    };
    //CONTENIDO DEL ARCHIVO INSCRIPTOS EN EL DIA
    Alumno vecAlumnoDos[10]={
    {"Juan","Casares",5512,1,21,7,2023},
    {"Matias","Vega",5211,2,22,7,2023},
    {"Mateo","Lopez",0323,3,23,7,2023},
    {"Leonardo","Dicaprio",2913,4,24,7,2023},
    {"Ismael","Prego",4921,2,22,7,2023},
    {"Juan","Dominguez",3201,3,23,7,2023},
    {"Benito","Massimo",5021,4,24,7,2023},
    {"Luis","Miguel",3021,2,22,7,2023},
    {"Carlos","Cuccitini",4912,3,23,7,2023},
    {"Pedro","Lopez",4923,1,21,7,2023}
    };

    int opcion=0;


    //PARA GENERAR ARCHIVOS
    printf("Si desea generar archivos oprima 1 \n");
    scanf("%d",&opcion);
    if(opcion==1)
    {

        FILE* archivoInscriptos=fopen("inscriptos.dat","wb");
        FILE* archivoInscriptosDelDia=fopen("diaInscriptos.dat","wb");

        for(int i=0;i<10;i++){
            fwrite(&vecAlumnosUno[i],sizeof(Alumno),1,archivoInscriptos);
            fwrite(&vecAlumnoDos[i],sizeof(Alumno),1,archivoInscriptosDelDia);
        }
        printf("Archivos creados exitosamente \n");
        fclose(archivoInscriptos);
        fclose(archivoInscriptosDelDia);
    }

    //ABRO EL ARCHIVO EN ESCRITURA
    FILE* archivoInscriptos=fopen("inscriptos.dat","ab");
    //ABRO ESTE ARCHIVO EN LECTURA
    FILE* archivoInscriptosDelDia=fopen("diaInscriptos.dat","rb");

    //BUFFER DE ALUMNO
    Alumno alumnoLeido;

    fread(&alumnoLeido,sizeof(Alumno),1,archivoInscriptosDelDia);

    while(!feof(archivoInscriptosDelDia)){

        //AGREGO AL FINAL DEL ARCHIVO DE INSCRIPTOS LOS INSCRIPTOS DEL DIA
        fwrite(&alumnoLeido,sizeof(Alumno),1,archivoInscriptos);
        //LEO OTRO REGISTRO
        fread(&alumnoLeido,sizeof(Alumno),1,archivoInscriptosDelDia);
    }

    fclose(archivoInscriptos);
    fclose(archivoInscriptosDelDia);

    //MOSTRAR EL ARCHIVO INSCRIPTOS RESULTANTE

    FILE*archivoInscripto=fopen("inscriptos.dat","rb");

    fread(&alumnoLeido,sizeof(Alumno),1,archivoInscripto);
    printf("NOMBRE APELLIDO \t LEGAJO \t CODIGO \t FECHA\n");
    while(!feof(archivoInscripto)){

        printf("%s %s \t\t %d \t\t %d \t %d/%d/%d\n",alumnoLeido.nombre,alumnoLeido.apellido,
               alumnoLeido.numeroLegajo,alumnoLeido.codigoMateria,alumnoLeido.dia,alumnoLeido.mes,alumnoLeido.anio);
        fread(&alumnoLeido,sizeof(Alumno),1,archivoInscripto);
    }

    fclose(archivoInscripto);

    return 0;
}
