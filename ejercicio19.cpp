#include <iostream>

struct Producto{

    int codigoProducto;
    float precioUnitario;

};

struct Pedido{
    int codigoProducto;
    int cantidadUnidades;

};

struct ProductoB{

    int codigoProducto;
    float totalFacturado;
    bool vendido;
};


using namespace std;

void crearArchivoDeProductos(FILE *archivoProducto, Producto vec[]){

    for(int i=0;i<20;i++){

        fwrite(&vec[i],sizeof(Producto),1,archivoProducto);

    }

    return;
}


void generarFactura(Pedido pedido, FILE *archivo, ProductoB vecProd[]){

    printf("Generando su factura... espere. \n");

    Producto producto;
    float importe;
    float precioUnitario;

    fread(&producto,sizeof(producto),1,archivo);
    while(!feof(archivo)){
        if(producto.codigoProducto==pedido.codigoProducto){
            importe=pedido.cantidadUnidades*producto.precioUnitario;
            precioUnitario=producto.precioUnitario;
        }
        fread(&producto,sizeof(producto),1,archivo);
    }

    fseek(archivo,0,SEEK_SET);

    vecProd[pedido.codigoProducto-1].totalFacturado+=importe;
    vecProd[pedido.codigoProducto-1].vendido=true;

    printf("Codigo de producto: %d \n",pedido.codigoProducto);
    printf("Cantidad de unidades pedidas: %d \n",pedido.cantidadUnidades);
    printf("Precio unitario: %f \n",precioUnitario);
    printf("Importe: %f \n", importe);
    printf("================================================================== \n");

}

void informarProductosNoVendidos(ProductoB prod[]){

    printf("Codigos de productos no vendidos\n");
    for(int i=0;i<20;i++){

        if(prod[i].vendido==false){
           printf("%d \n",prod[i].codigoProducto);
        }
    }
    return;
}

void crearArchivoFacturacion(ProductoB prod[],FILE *archivo){
    fprintf(archivo,"Listado de facturacion \n");
    fprintf(archivo,"CODIGO \t FACTURADO \n");

    for(int i=0;i<20;i++){

        fprintf(archivo,"%d \t %f \n",prod[i].codigoProducto,prod[i].totalFacturado);
    }
    return;
}


int main(){

    /*Producto productosDisponibles[20]={
    {1,100},
    {2,200},
    {3,300},
    {4,100},
    {5,150},
    {6,200},
    {7,300},
    {8,100},
    {9,50},
    {10,200},
    {11,130},
    {12,150},
    {13,200},
    {14,100},
    {15,400},
    {16,300},
    {17,150},
    {18,200},
    {19,300},
    {20,150}
    };
    */
    ProductoB productos[20]={
    {1,0,false},
    {2,0,false},
    {3,0,false},
    {4,0,false},
    {5,0,false},
    {6,0,false},
    {7,0,false},
    {8,0,false},
    {9,0,false},
    {10,0,false},
    {11,0,false},
    {12,0,false},
    {13,0,false},
    {14,0,false},
    {15,0,false},
    {16,0,false},
    {17,0,false},
    {18,0,false},
    {19,0,false},
    {20,0,false}
    };

    FILE *archivoProducto=fopen("productos.dat","rb");
    FILE *archivoFacturacion=fopen("facturacion.txt","wt");
    //crearArchivoDeProductos(archivoProducto,productosDisponibles);
    //fclose(archivoProducto);

    Pedido pedidoActual;

    printf("Ingrese codigo del producto que desea \n");
    scanf("%d",&pedidoActual.codigoProducto);

    while(pedidoActual.codigoProducto!=0){
        printf("Ingrese unidades que necesita del producto \n");
        scanf("%d",&pedidoActual.cantidadUnidades);

        generarFactura(pedidoActual,archivoProducto,productos);

        printf("Ingrese codigo del producto que desea \n");
        scanf("%d",&pedidoActual.codigoProducto);

        }


    informarProductosNoVendidos(productos);
    crearArchivoFacturacion(productos,archivoFacturacion);

    fclose(archivoProducto);
    fclose(archivoFacturacion);


    return 0;
}
