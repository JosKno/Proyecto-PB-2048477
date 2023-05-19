#include <iostream>
#include <math.h> 
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>
#include <fstream>
#include <stdlib.h>
using  namespace std;

struct tienda 
{
    string nombre, desc, gen, clas, con, status, carat;
    int numero, year;
    float coniva, imp, precio;
};
bool Repetido(int nump, int i);
//bool Buscar(string tubatu, int i);
int contador, alta;

tienda* Pro; 
void Alta();
void eliminar();
void listas();
void modificar();
void archivos();

int main()
{
    system("COLOR 1F");
    int opcion;
        printf(" \n\t * * * %cRITH GAMES Systems * * * \n",146);
        printf(" \n\t * * * MENU DE OPCIONES * * * \n");
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
            Alta();
            return main();
            break;
        case 2://MODIFICACION
            modificar();
            return main();
            break;

        case 3://BAJA
            eliminar();
            return main();
            break;

        case 4://LISTA
            listas();
            return main();
            break;

        case 5://LIMPIAR
            system("cls");
            return main();
            break;
        case 6://SALIR
            archivos();
            exit(1);
            break;
        default:
            printf("Opcion invalida \n");
            return main();
            break;
        }
}

void Alta()
{
    printf("%cCuantos registros desea dar de alta? \n", 168);
    scanf_s("%d", &alta);
    Pro = new tienda[alta]; // uso de new para hacer el arreglo dinamico
    for (int i = 0; i < alta; i++)
    {
        int nump;
        cin.ignore();//Necesario para el uso de string.
        printf("\nIngrese el numero de item \n");
        scanf_s("%d", &nump);
        while (Repetido(nump, i)) {
            printf("El numero esta repetido\n");
            printf("\nIngrese el numero de item \n");
            scanf_s("%d", &nump);
        }
        Pro[i].numero = nump;
        cin.ignore();//Necesario para el uso de string.
        printf("Ingrese el nombre del articulo \n");
        getline(cin, Pro[i].nombre);
        printf("Ingrese el a%co de lanzamiento del articulo \n", 164);
        scanf_s("%d", &Pro[i].year);
        cin.ignore();
        printf("Ingrese la descripcion del articulo \n");
        getline(cin, Pro[i].desc);
        printf("Ingrese las caracteristicas del articulo \n");
        getline(cin, Pro[i].carat);
        printf("Ingrese el genero \n");
        getline(cin, Pro[i].gen);
        printf("Ingrese la clasificacion del articulo \n");
        getline(cin, Pro[i].clas);
        printf("Ingrese la consola \n");
        getline(cin, Pro[i].con);
        printf("Ingrese el precio del articulo \n");
        scanf_s("%f", &Pro[i].precio);

        Pro[i].imp = Pro[i].precio * 0.16;
        Pro[i].coniva = Pro[i].precio + Pro[i].imp;
    }
}

bool Repetido(int nump, int i) {
    for (int x = 0; x < i; x++) {
        if (nump == Pro[x].numero) {
            return true;
        }
    }
    return false;
}


void listas()
{
    int o1, o2;
    printf("%cDesea filtrar los articulos? 1.Si 2.No \n",168);
    scanf_s("%d", &o1);
    while (o1 != 1 && o1 != 2) {
        printf("Opcion invalida \nIngrese una opcion valida\n");
        printf("Desea filtrar los articulos? 1.Si 2.No \n");
        scanf_s("%d", &o1);
    }

    if (o1 == 1) {
        printf("%cQue categoria desea filtrar? \n1.Clasificacion 2.Genero 3.Consola\n",168);
        scanf_s("%d", &o2);
        int r;
        string tubatu;
        switch (o2) {
        case 1:
            cin.ignore();//Necesario para el uso de string.
            printf("Ingrese la clasificacion que desea visualizar \n");
            getline(cin, tubatu);
            for (int i = 0; i < alta; i++) {
                r = tubatu.compare(Pro[i].clas);
                if (r == 0) {
                    int k;
                    k = i + 1;
                    if (Pro[i].status == "ELIMINADO")
                    {
                        printf("\nREGISTRO ELIMINADO %d \n", k);
                    }
                    else
                    {
                        printf("\nRegistro %d \n", k);
                        printf("Numero de item: %d \n", Pro[i].numero);
                        printf("Nombre del articulo: %s \n", Pro[i].nombre.c_str());
                        printf("A%co de lanzamiento del item: %d \n", 164, Pro[i].year);
                        printf("Descripcion del articulo: %s \n", Pro[i].desc.c_str());
                        printf("Caracteristicas del articulo: %s \n", Pro[i].carat.c_str());
                        printf("Genero: %s \n", Pro[i].gen.c_str());
                        printf("Clasificacion: %s \n", Pro[i].clas.c_str());
                        printf("Consola: %s \n", Pro[i].con.c_str());
                        printf("Precio: %f \n", Pro[i].precio);
                        printf("Impuesto: %f \n", Pro[i].imp);
                        printf("Total: %f \n", Pro[i].coniva);
                    }
                }
            }
            break;
            case 2:
                cin.ignore();//Necesario para el uso de string.
                printf("Ingrese el genero que desea visualizar \n");
                getline(cin, tubatu);
                for (int i = 0; i < alta; i++) {
                    r= tubatu.compare(Pro[i].gen);
                    if (r == 0) {
                        int k;
                        k = i + 1;
                        if (Pro[i].status == "ELIMINADO")
                        {
                            printf("\nREGISTRO ELIMINADO %d \n", k);
                        }
                        else
                        {
                            printf("\nRegistro %d \n", k);
                            printf("Numero de item: %d \n", Pro[i].numero);
                            printf("Nombre del articulo: %s \n", Pro[i].nombre.c_str());
                            printf("A%co de lanzamiento del item: %d \n", 164, Pro[i].year);
                            printf("Descripcion del articulo: %s \n", Pro[i].desc.c_str());
                            printf("Caracteristicas del articulo: %s \n", Pro[i].carat.c_str());
                            printf("Genero: %s \n", Pro[i].gen.c_str());
                            printf("Clasificacion: %s \n", Pro[i].clas.c_str());
                            printf("Consola: %s \n", Pro[i].con.c_str());
                            printf("Precio: %f \n", Pro[i].precio);
                            printf("Impuesto: %f \n", Pro[i].imp);
                            printf("Total: %f \n", Pro[i].coniva);
                        }
                    }
                }
            break;
            case 3:
            cin.ignore();//Necesario para el uso de string.
            printf("Ingrese la consola que desea visualizar \n");
            getline(cin, tubatu);
            for (int i = 0; i < alta; i++) {
                r = tubatu.compare(Pro[i].con);
                if (r == 0) {
                    int k;
                    k = i + 1;
                    if (Pro[i].status == "ELIMINADO")
                    {
                        printf("\nREGISTRO ELIMINADO %d \n", k);
                    }
                    else
                    {
                        printf("\nRegistro %d \n", k);
                        printf("Numero de item: %d \n", Pro[i].numero);
                        printf("Nombre del articulo: %s \n", Pro[i].nombre.c_str());
                        printf("A%co de lanzamiento del item: %d \n", 164, Pro[i].year);
                        printf("Descripcion del articulo: %s \n", Pro[i].desc.c_str());
                        printf("Caracteristicas del articulo: %s \n", Pro[i].carat.c_str());
                        printf("Genero: %s \n", Pro[i].gen.c_str());
                        printf("Clasificacion: %s \n", Pro[i].clas.c_str());
                        printf("Consola: %s \n", Pro[i].con.c_str());
                        printf("Precio: %f \n", Pro[i].precio);
                        printf("Impuesto: %f \n", Pro[i].imp);
                        printf("Total: %f \n", Pro[i].coniva);
                    }
                }
            }
            break;
            default:
                printf("Opcion invalida \n");
                break;
        }
    }

    if (o1 == 2) {
        for (int i = 0; i < alta; i++)
        {
            int k;
            k = i + 1;
            if (Pro[i].status == "ELIMINADO")
            {
                printf("\nREGISTRO ELIMINADO %d \n", k);
            }
            else
            {
                printf("\nRegistro %d \n", k);
                printf("Numero de item: %d \n", Pro[i].numero);
                printf("Nombre del articulo: %s \n", Pro[i].nombre.c_str());
                printf("A%co de lanzamiento del item: %d \n", 164, Pro[i].year);
                printf("Descripcion del articulo: %s \n", Pro[i].desc.c_str());
                printf("Caracteristicas del articulo: %s \n", Pro[i].carat.c_str());
                printf("Genero: %s \n", Pro[i].gen.c_str());
                printf("Clasificacion: %s \n", Pro[i].clas.c_str());
                printf("Consola: %s \n", Pro[i].con.c_str());
                printf("Precio: %f \n", Pro[i].precio);
                printf("Impuesto: %f \n", Pro[i].imp);
                printf("Total: %f \n", Pro[i].coniva);
            }
        }
    }
}

void eliminar()
{
    int j;
    printf("Ingrese el  registro a eliminar \n");
    scanf_s("%d", &j);
    j = j - 1;
    for (int i = j; i == j; i++)
    {
        printf("Eliminando registro %d \n", j + 1);
        Pro[i].status = "ELIMINADO";
    }
}

void modificar()
{
    int j, opcion, op2, nump;
    do
    {
        printf("\nIngrese el numero registro a modificar:\n");
        scanf_s("%d", &j);
        j = j - 1; // esto debido a que i inicia en 0

        for (int i = j; i == j; i++)
        {
            if ((Pro[i].status == "ELIMINADO"))
            {
                int k;
                k = i + 1;
                printf("\nREGISTRO ELIMINADO %d \n", k);
                printf("Ingrese un registro valido \n");
                op2 = 1;
            }
            else
            {
                op2 = 2;
            }
        }
    } while (op2 == 1);
    printf("Ingrese que desea modificar:\n");
    printf("1.-Numero del articulo \n");
    printf("2.-Nombre del articulo \n");
    printf("3.-A%co de lanzamiento del articulo \n", 164);
    printf("4.-Descripcion del articulo \n");
    printf("5.-Caracteristicas del articulo \n");
    printf("6.-Genero del articulo  \n");
    printf("7.-Clasificacion del articulo \n");
    printf("8.-Consola del articulo \n");
    printf("9.-Precio del articulo \n");
    scanf_s("%d", &opcion);

    switch (opcion)
    {
    case 1:
        for (int i = j; i == j; i++)
        {
            printf("\nIngrese el numero de item \n");
            scanf_s("%d", &nump);
            while (Repetido(nump, i)) {
                printf("El numero esta repetido\n");
                printf("\nIngrese el numero de item \n");
                scanf_s("%d", &nump);
            }
            Pro[i].numero = nump;
        }
        break;
    case 2:
        for (int i = j; i == j; i++)
        {
            cin.ignore();//Necesario para el uso de string.
            printf("Ingrese el nombre del articulo \n");
            getline(cin, Pro[i].nombre);
        }
        break;
    case 3:
        for (int i = j; i == j; i++)
        {
            printf("Ingrese el a%co de lanzamiento del articulo \n", 164);
            scanf_s("%d", &Pro[i].year);
        }
        break;
    case 4:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("Ingrese la descripcion del articulo \n");
            getline(cin, Pro[i].desc);
        }
        break;

    case 5:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("Ingrese las caracteristicas del articulo \n");
            getline(cin, Pro[i].carat);
        }
        break;
    case 6:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("Ingrese el genero \n");
            getline(cin, Pro[i].gen);
        }
        break;
    case 7:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("Ingrese la clasificacion del articulo \n");
            getline(cin, Pro[i].clas);
        }
        break;
    case 8:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("Ingrese la consola \n");
            getline(cin, Pro[i].con);
        }
        break;
    case 9:
        for (int i = j; i == j; i++)
        {
            printf("Ingrese el precio del articulo \n");
            scanf_s("%f", &Pro[i].precio);

            Pro[i].imp = Pro[i].precio * 0.16;
            Pro[i].coniva = Pro[i].precio + Pro[i].imp;
        }
        break;
    default:
        printf("Opcion invalida \n");
        break;
    }
} 

void archivos()
{
    ofstream archivo; //clase ifstream para leer archivos
    string nombrearchivo;
    int texto;
    string texto2;

    nombrearchivo = "aerithgames_systems.txt";

    archivo.open(nombrearchivo.c_str(), ios::out);

    if (archivo.fail())
    {
        cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
        exit(1);
    }

    archivo << "\t" << "ÆRITH GAMES Systems" << "\n";
    /*archivo << "NUMERO" << "\t" << "\t";
    archivo << "NOMBRE" << "\t" << "\t";
    archivo << "AÑO" << "\t" << "\t";
    archivo << "DESCRIPCION" << "\t" << "\t";
    archivo << "CARACTERISTICAS" << "\t" << "\t";
    archivo << "GENERO" << "\t" << "\t";
    archivo << "CLASIFICACION" << "\t" << "\t";
    archivo << "CONSOLA" << "\t" << "\t";
    archivo << "PRECIO" << "\t" << "\t";
    archivo << "IMPUESTO" << "\t" << "\t";
    archivo << "TOTAL" << "\n";*/

    for (int i = 0; i < alta; i++)
    {
        if (Pro[i].status == "ELIMINADO")
        {
            texto2 = "REGISTRO ELIMINADO ";
            texto = i+1;
            archivo << texto2 << texto << "\n";
        }
        else
        {
            texto = Pro[i].numero;
            archivo <<"\n"<< "NUMERO:" << texto << "\n";
            texto2 = Pro[i].nombre;
            archivo << "NOMBRE: " << texto2 << "\n";
            texto = Pro[i].year;
            archivo << "AÑO: " << texto << "\n";
            texto2 = Pro[i].desc;
            archivo << "DESCRIPCIÓN: "<< texto2 << "\n";
            texto2 = Pro[i].carat;
            archivo << "CARACTERÍSTICAS: "<< texto2 << "\n";
            texto2 = Pro[i].gen;
            archivo << "GENERO: "<< texto2 << "\n";
            texto2 = Pro[i].clas;
            archivo << "CLASIFICACIÓN: "<< texto2 << "\n";
            texto2 = Pro[i].con;
            archivo <<"CONSOLA: "<<texto2 << "\n";
            texto = Pro[i].precio;
            archivo <<"PRECIO: "<< texto << "\n";
            texto = Pro[i].imp;
            archivo << "IMPUESTO: "<< texto << "\n";
            texto = Pro[i].coniva;
            archivo << "TOTAL: "<< texto << "\n";
        }
    }


    archivo.close();
}