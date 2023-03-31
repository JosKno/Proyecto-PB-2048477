#include <iostream>
#include <math.h> 
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>
using  namespace std;

struct tienda 
{
    string nombre, desc, gen, clas, con;
    int numero;
    float coniva, imp, precio;
};

int main()
{
    tienda dat[3];
    int opcion;
    do {
        printf(" \n\t * **MENU DE OPCIONES * ** \n");
        printf("1.-Alta de articulos \n");
        printf("2.-Modificacion de articulos \n");
        printf("3.-Baja de articulos \n");
        printf("4.-Lista de articulos \n");
        printf("5.-Limpiar pantalla \n");
        printf("6.-Salir \n");
        scanf_s("%d", &opcion);

        switch (opcion)
        {
        case 1: //ALTA
            for (int i = 0; i < 3; i++)
            {
                cin.ignore();//Necesario para el uso de string.
                printf("\nIngrese el numero de item \n");
                scanf_s("%d", &dat[i].numero);
                cin.ignore();//Necesario para el uso de string.
                printf("Ingrese el nombre del articulo \n");
                getline(cin, dat[i].nombre);
                printf("Ingrese la descripcion del articulo \n");
                getline(cin, dat[i].desc);
                printf("Ingrese el genero \n");
                getline(cin, dat[i].gen);
                printf("Ingrese la clasificacion del articulo \n");
                getline(cin, dat[i].clas);
                printf("Ingrese la consola \n");
                getline(cin, dat[i].con);
                printf("Ingrese el precio del articulo \n");
                scanf_s("%f", &dat[i].precio);

                dat[i].imp = dat[i].precio * 0.16;
                dat[i].coniva = dat[i].precio + dat[i].imp;
            }

            break;
        case 2://MODIFICACION
            break;

        case 3://BAJA
            break;

        case 4://LISTA
            for (int i = 0; i < 3; i++)
            {
                printf("\nNumero de item: %d \n", dat[i].numero);
                printf("Nombre del articulo: %s \n", dat[i].nombre.c_str());
                printf("Genero: %s \n", dat[i].gen.c_str());
                printf("Clasificacion: %s \n", dat[i].clas.c_str());
                printf("Consola: %s \n", dat[i].con.c_str());
                printf("Precio: %f \n", dat[i].precio);
                printf("Impuesto: %f \n", dat[i].imp);
                printf("Total: %f \n", dat[i].coniva);
            }
            break;

        case 5://LIMPIAR
            system("cls");
            break;
        case 6://SALIR
            exit(1);
            break;
        default:
            printf("Opcion invalida \n");
            break;
        }
    } while (opcion != 6);
}