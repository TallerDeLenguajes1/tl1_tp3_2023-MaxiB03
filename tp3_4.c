#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define tama 50

char *tiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct 
{
    int ProductoID;
    int cantidad;
    char *TipoProducto;
    float PrecioUnitario;
}typedef Producto;

struct 
{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
}typedef Cliente;

void cargar(Cliente *pcliente, int cant);
void mostrar(Cliente *pcliente, int cant);

int main() {

    srand(time(NULL));
    int cant;
    Cliente *pcliente;

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cant);

    pcliente=malloc(sizeof(Cliente)*cant);

    cargar(pcliente, cant);
    mostrar(pcliente, cant);


    return 0;
}

//Funcion para cargar los clientes

void cargar(Cliente *pcliente, int cant){

    char buff[tama];
    int aux;

    for (int i=0; i<cant; i++)
    {
        printf("\n------ Datos a Cargar del Cliente [%d] ------\n", i+1);

        pcliente->ClienteID =i+1;
        printf("Cliente ID: %d\n", pcliente->ClienteID);

        fflush(stdin);
        printf("Ingrese el Nombre: ");
        gets(buff);

        pcliente->NombreCliente=malloc(sizeof(char)*(strlen(buff)+1));
        strcpy(pcliente->NombreCliente, buff);

        pcliente->CantidadProductosAPedir=1+rand()%5;
        printf("Cantidad de productos a pedir: %d\n", pcliente->CantidadProductosAPedir);

        pcliente->Productos=malloc(sizeof(Producto)*pcliente->CantidadProductosAPedir);
        for (int j=0; j<pcliente->CantidadProductosAPedir; j++)
        {
            pcliente->Productos[j].ProductoID=j+1;
            pcliente->Productos[j].cantidad=1+rand()%10;
            pcliente->Productos[j].TipoProducto=tiposProductos[aux=1+rand()%5];
            pcliente->Productos[j].PrecioUnitario=10+rand()%91;
        }
        
        pcliente++;
    }
}

//Funcion para Mostrar los clientes

void mostrar(Cliente *pcliente, int cant) {

    float costoTotal=0;

    for (int i=0; i<cant; i++)
    {
        printf("\n------ Datos del Cliente Nro[%d] ------\n", i+1);

        printf("Cliente ID: %d\n", pcliente->ClienteID);
        printf("Nombre: %s\n", pcliente->NombreCliente);
        printf("Cantidad de productos pedidos: %d\n", pcliente->CantidadProductosAPedir);

        for (int j=0; j<pcliente->CantidadProductosAPedir; j++)
        {
            printf("\n-----Prodructo Nro %d-----\n", j+1);
            printf("Producto ID: %d\n", pcliente->Productos[j].ProductoID);
            printf("Cantidad: %d\n", pcliente->Productos[j].cantidad);
            printf("Tipo de Producto: %s\n", pcliente->Productos[j].TipoProducto);
            printf("Precio Unitario: %.2f\n", pcliente->Productos[j].PrecioUnitario);
            printf("Costo por Producto: %.2f\n", (pcliente->Productos[j].cantidad*pcliente->Productos[j].PrecioUnitario));

            costoTotal=costoTotal+(pcliente->Productos[j].cantidad*pcliente->Productos[j].PrecioUnitario);
        }

        printf("\nCosto Total del Cliente: %.2f\n", costoTotal);
        
        pcliente++;
    }
    

}