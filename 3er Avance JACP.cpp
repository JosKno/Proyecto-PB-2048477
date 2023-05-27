#include <iostream>
#include <math.h> 
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>
#include <fstream>
#include <stdlib.h>
#include <locale.h>

using  namespace std;

struct tienda 
{
    string nombre, desc, gen, clas, con, status, carat;
    int numero, year;
    float coniva, imp, precio;
};
bool Repetido(int nump, int i);
bool fecha(int fe);
//bool Buscar(string tubatu, int i);
int w=0, b=0, alta;

tienda* Pro; 
void Alta();
void eliminar();
void listas();
void modificar();
void archivos();

int main()
{
    system("COLOR 0b");
    setlocale(LC_ALL, "");
    int opcion;
    if (b == 0) {
        printf(" \n\t * * * ÆRITH GAMING Systems * * * \n");
        printf("\t     |Tienda de videojuegos|  \n");
    }
        printf(" \n\t * * * MENÚ DE OPCIONES * * * \n");
        printf("1.-Alta de artículos \n");
        printf("2.-Modificación de artículos \n");
        printf("3.-Baja de artículos \n");
        printf("4.-Lista de artículos \n");
        printf("5.-Limpiar pantalla \n");
        printf("6.-Salir \n");
        printf("\nIngrese el número de la acción a realizar\n");
        scanf_s("%d", &opcion);

        switch (opcion)
        {
        case 1: //ALTA
            b = 1;
            Alta();
            return main();
            break;
        case 2://MODIFICACION
            if (w == 1) 
            {
                b = 1;
                modificar();
            }
            else {
                printf("\nAún no se realizan registros\n");
            }
            b = 1;
            return main();
            break;

        case 3://BAJA
            if (w == 1)
            {
                b = 1;
                eliminar();
            }
            else {
                printf("\nAún no se realizan registros\n");
            }
            return main();
            break;

        case 4://LISTA
            if (w == 1)
            {
                b = 1;
                listas();
            }
            else {
                printf("\nAún no se realizan registros\n");
            }
            return main();
            break;

        case 5://LIMPIAR
            system("cls");
            b = 0;
            return main();
            break;
        case 6://SALIR
            archivos();
            exit(1);
            break;
        default:
            printf("Opción inválida \n");
            return main();
            break;
        }
}

void Alta()
{
    printf("\n¿Cuántos registros desea dar de alta? \n");
    scanf_s("%d", &alta);
    while (alta <= 0) {
        printf("\nNúmero inválido\n");
        printf("\n¿Cuántos registros desea dar de alta? \n");
        scanf_s("%d", &alta);
    }
    Pro = new tienda[alta]; // uso de new para hacer el arreglo dinamico
    for (int i = 0; i < alta; i++)
    {
        int nump, fe;
        printf("\nREGISTRO #%d\n", i + 1);
        cin.ignore();//Necesario para el uso de string.
        printf("\nIngrese el número de item \n");
        scanf_s("%d", &nump);
        while (Repetido(nump, i)) {
            printf("El número esta repetido\n");
            printf("\nIngrese el número de ítem \n");
            scanf_s("%d", &nump);
        }
        Pro[i].numero = nump;
        cin.ignore();//Necesario para el uso de string.
        printf("Ingrese el nombre del artículo \n");
        getline(cin, Pro[i].nombre);
        printf("Ingrese el año de lanzamiento del artículo \n");
        scanf_s("%d", &fe);
        while (fecha(fe)) {
            printf("\nLa fecha no es válida\n");
            printf("\nIngrese el año de lanzamiento del artículo \n");
            scanf_s("%d", &fe);
        }
        Pro[i].year = fe;
        cin.ignore();
        printf("Ingrese la descripción del artículo \n");
        getline(cin, Pro[i].desc);
        printf("Ingrese las características del artículo \n");
        getline(cin, Pro[i].carat);
        printf("Ingrese el género \n");
        getline(cin, Pro[i].gen);
        printf("Ingrese la clasificación del artículo \n");
        getline(cin, Pro[i].clas);
        printf("Ingrese la consola \n");
        getline(cin, Pro[i].con);
        printf("Ingrese el precio del artículo \n");
        scanf_s("%f", &Pro[i].precio);

        Pro[i].imp = Pro[i].precio * 0.16;
        Pro[i].coniva = Pro[i].precio + Pro[i].imp;
    }
    w = 1;
    printf("\nRegistro exitoso\n\nRegresando al menú\n");
}

bool Repetido(int nump, int i) {
    for (int x = 0; x < i; x++) {
        if (nump == Pro[x].numero) {
            return true;
        }
    }
    return false;
}

bool fecha(int fe) {
    if (fe < 1990 || fe>2024) {
        return true;
    }
    else {
        return false;
    }
}


void listas()
{
    int o1, o2,s=0;
    printf("\n¿Desea filtrar los artículos? 1.Si 2.No \n");
    scanf_s("%d", &o1);
    while (o1 != 1 && o1 != 2) {
        printf("Opción inválida \nIngrese una opción válida\n");
        printf("\n¿Desea filtrar los artículos? 1.Si 2.No \n");
        scanf_s("%d", &o1);
    }

    if (o1 == 1) {
        printf("\n¿Qué categoría desea filtrar? \n\n1.Clasificación 2.Género 3.Consola\n");
        scanf_s("%d", &o2);
        int r;
        string tubatu;
        switch (o2) {
        case 1:
            cin.ignore();//Necesario para el uso de string.
            printf("\nIngrese la clasificación que desea visualizar \n");
            getline(cin, tubatu);
            for (int i = 0; i < alta; i++) {
                r = tubatu.compare(Pro[i].clas);
                if (r == 0) {
                    s = 1;
                    int k;
                    k = i + 1;
                    if (Pro[i].status == "ELIMINADO")
                    {
                        printf("\nREGISTRO ELIMINADO %d \n", k);
                    }
                    else
                    {
                        printf("\nRegistro %d \n", k);
                        printf("Número de ítem: %d \n", Pro[i].numero);
                        printf("Nombre del artículo: %s \n", Pro[i].nombre.c_str());
                        printf("Año de lanzamiento del item: %d \n", Pro[i].year);
                        printf("Descripción del artículo: %s \n", Pro[i].desc.c_str());
                        printf("Características del artículo: %s \n", Pro[i].carat.c_str());
                        printf("Género: %s \n", Pro[i].gen.c_str());
                        printf("Clasificación: %s \n", Pro[i].clas.c_str());
                        printf("Consola: %s \n", Pro[i].con.c_str());
                        printf("Precio: %f \n", Pro[i].precio);
                        printf("Impuesto: %f \n", Pro[i].imp);
                        printf("Total: %f \n", Pro[i].coniva);
                    }
                }
            }
            if (s == 0) {
                printf("\nNo hay artículos registrados de esa clasificación\n\nRegresando al menú\n");
            }
            break;
            case 2:
                cin.ignore();//Necesario para el uso de string.
                printf("\nIngrese el género que desea visualizar \n");
                getline(cin, tubatu);
                for (int i = 0; i < alta; i++) {
                    r= tubatu.compare(Pro[i].gen);
                    if (r == 0) {
                        s = 1;
                        int k;
                        k = i + 1;
                        if (Pro[i].status == "ELIMINADO")
                        {
                            printf("\nREGISTRO ELIMINADO %d \n", k);
                        }
                        else
                        {
                            printf("\nRegistro %d \n", k);
                            printf("Número de ítem: %d \n", Pro[i].numero);
                            printf("Nombre del artículo: %s \n", Pro[i].nombre.c_str());
                            printf("Año de lanzamiento del ítem: %d \n", Pro[i].year);
                            printf("Descripción del artículo: %s \n", Pro[i].desc.c_str());
                            printf("Características del artículo: %s \n", Pro[i].carat.c_str());
                            printf("Género: %s \n", Pro[i].gen.c_str());
                            printf("Clasificación: %s \n", Pro[i].clas.c_str());
                            printf("Consola: %s \n", Pro[i].con.c_str());
                            printf("Precio: %f \n", Pro[i].precio);
                            printf("Impuesto: %f \n", Pro[i].imp);
                            printf("Total: %f \n", Pro[i].coniva);
                        }
                    }
                }
                if (s == 0) {
                    printf("\nNo hay artículos registrados de ese género\n\nRegresando al menú\n");
                }
            break;
            case 3:
            cin.ignore();//Necesario para el uso de string.
            printf("\nIngrese la consola que desea visualizar \n");
            getline(cin, tubatu);
            for (int i = 0; i < alta; i++) {
                r = tubatu.compare(Pro[i].con);
                if (r == 0) {
                    s = 1;
                    int k;
                    k = i + 1;
                    if (Pro[i].status == "ELIMINADO")
                    {
                        printf("\nREGISTRO ELIMINADO %d \n", k);
                    }
                    else
                    {
                        printf("\nRegistro %d \n", k);
                        printf("Número de ítem: %d \n", Pro[i].numero);
                        printf("Nombre del artículo: %s \n", Pro[i].nombre.c_str());
                        printf("Año de lanzamiento del ítem: %d \n", Pro[i].year);
                        printf("Descripción del artículo: %s \n", Pro[i].desc.c_str());
                        printf("Características del artículo: %s \n", Pro[i].carat.c_str());
                        printf("Género: %s \n", Pro[i].gen.c_str());
                        printf("Clasificación: %s \n", Pro[i].clas.c_str());
                        printf("Consola: %s \n", Pro[i].con.c_str());
                        printf("Precio: %f \n", Pro[i].precio);
                        printf("Impuesto: %f \n", Pro[i].imp);
                        printf("Total: %f \n", Pro[i].coniva);
                    }
                }
            }
            if (s == 0) {
                printf("\nNo hay artículos registrados de esa consola\n\nRegresando al menú\n");
            }
            break;
            default:
                printf("\nOpción inválida \n");
                return listas();
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
                printf("Número de ítem: %d \n", Pro[i].numero);
                printf("Nombre del artículo: %s \n", Pro[i].nombre.c_str());
                printf("Año de lanzamiento del ítem: %d \n", Pro[i].year);
                printf("Descripción del artículo: %s \n", Pro[i].desc.c_str());
                printf("Características del artículo: %s \n", Pro[i].carat.c_str());
                printf("Género: %s \n", Pro[i].gen.c_str());
                printf("Clasificación: %s \n", Pro[i].clas.c_str());
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
    printf("\nIngrese el registro a eliminar \n");
    scanf_s("%d", &j);
    while (j > alta || j <= 0) {
        printf("\nOpción inválida\n");
        printf("\nIngrese un numero de registro válido\n");
        printf("\nIngrese el registro a eliminar:\n");
        scanf_s("%d", &j);
    }
    j = j - 1;
    for (int i = j; i == j; i++)
    {
        printf("\nEliminando registro %d \n", j + 1);
        Pro[i].status = "ELIMINADO";
        printf("\nRegistro #%d eliminado correctamente\n\nRegresando al menú\n",j+1);
    }
}

void modificar()
{
    int j, opcion, op2, nump, fe;
    do
    {
        printf("\nIngrese el numero registro a modificar:\n");
        scanf_s("%d", &j);
        while (j > alta || j<=0) {
            printf("\nOpción inválida\n");
            printf("\nIngrese un número de registro válido\n");
            printf("\nIngrese el número registro a modificar:\n");
            scanf_s("%d", &j);
        }
        j = j - 1;// esto debido a que i inicia en 0

        for (int i = j; i == j; i++)
        {
            if ((Pro[i].status == "ELIMINADO"))
            {
                int k;
                k = i + 1;
                printf("\nREGISTRO ELIMINADO %d \n", k);
                printf("Ingrese un registro válido \n");
                op2 = 1;
            }
            else
            {
                op2 = 2;
            }
        }
    } while (op2 == 1);
    printf("\nIngrese que desea modificar:\n");
    printf("1.-Número del artículo \n");
    printf("2.-Nombre del artículo \n");
    printf("3.-Año de lanzamiento del artículo \n");
    printf("4.-Descripción del artículo \n");
    printf("5.-Características del artículo \n");
    printf("6.-Género del artículo  \n");
    printf("7.-Clasificación del artículo \n");
    printf("8.-Consola del artículo \n");
    printf("9.-Precio del artículo \n");
    scanf_s("%d", &opcion);

    switch (opcion)
    {
    case 1:
        for (int i = j; i == j; i++)
        {
            printf("\nIngrese el numero de ítem \n");
            scanf_s("%d", &nump);
            while (Repetido(nump, i)) {
                printf("El número esta repetido\n");
                printf("\nIngrese el número de item \n");
                scanf_s("%d", &nump);
            }
            Pro[i].numero = nump;
        }
        printf("\nModificación exitosa\n\nRegresando al menú\n");
        break;
    case 2:
        for (int i = j; i == j; i++)
        {
            cin.ignore();//Necesario para el uso de string.
            printf("\nIngrese el nombre del artículo \n");
            getline(cin, Pro[i].nombre);
            printf("\nModificación exitosa\n\nRegresando al menú\n");
        }
        break;
    case 3:
        for (int i = j; i == j; i++)
        {
            printf("\nIngrese el año de lanzamiento del artículo \n");
            scanf_s("%d", &fe);
            while (fecha(fe)) {
                printf("\nLa fecha no es válida\n");
                printf("\nIngrese el año de lanzamiento del artículo \n");
                scanf_s("%d", &fe);
            }
            Pro[i].year = fe;
        }
        printf("\nModificación exitosa\n\nRegresando al menú\n");
        break;
    case 4:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("\nIngrese la descripción del artículo \n");
            getline(cin, Pro[i].desc);
            printf("\nModificación exitosa\n\nRegresando al menú\n");
        }
        break;

    case 5:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("\nIngrese las características del artículo \n");
            getline(cin, Pro[i].carat);
            printf("\nModificación exitosa\n\nRegresando al menú\n");
        }
        break;
    case 6:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("\nIngrese el género \n");
            getline(cin, Pro[i].gen);
            printf("\nModificación exitosa\n\nRegresando al menú\n");
        }
        break;
    case 7:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("\nIngrese la clasificación del artículo \n");
            getline(cin, Pro[i].clas);
            printf("\nModificación exitosa\n\nRegresando al menú\n");
        }
        break;
    case 8:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("\nIngrese la consola \n");
            getline(cin, Pro[i].con);
            printf("\nModificación exitosa\n\nRegresando al menú\n");
        }
        break;
    case 9:
        for (int i = j; i == j; i++)
        {
            printf("\nIngrese el precio del articulo \n");
            scanf_s("%f", &Pro[i].precio);

            Pro[i].imp = Pro[i].precio * 0.16;
            Pro[i].coniva = Pro[i].precio + Pro[i].imp;
        }
        printf("\nModificación exitosa\n\nRegresando al menú\n");
        break;
    default:
        printf("\nOpción inválida \n");
        return modificar();
        break;
    }
} 

void archivos()
{
    ofstream archivo; //clase ifstream para leer archivos
    string nombrearchivo;
    int texto;
    string texto2;

    nombrearchivo = "aerithgaming_systems.txt";

    archivo.open(nombrearchivo.c_str(), ios::out);

    if (archivo.fail())
    {
        cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
        exit(1);
    }

    archivo << "\t" << "ÆRITH GAMING Systems" << "\n";
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
            archivo << texto2 << texto << "\n" << "\n";
        }
        else
        {
            texto = Pro[i].numero;
            archivo <<"\n"<< "NÚMERO:" << texto << "\n";
            texto2 = Pro[i].nombre;
            archivo << "NOMBRE: " << texto2 << "\n";
            texto = Pro[i].year;
            archivo << "AÑO: " << texto << "\n";
            texto2 = Pro[i].desc;
            archivo << "DESCRIPCIÓN: "<< texto2 << "\n";
            texto2 = Pro[i].carat;
            archivo << "CARACTERÍSTICAS: "<< texto2 << "\n";
            texto2 = Pro[i].gen;
            archivo << "GÉNERO: "<< texto2 << "\n";
            texto2 = Pro[i].clas;
            archivo << "CLASIFICACIÓN: "<< texto2 << "\n";
            texto2 = Pro[i].con;
            archivo <<"CONSOLA: "<<texto2 << "\n";
            texto = Pro[i].precio;
            archivo <<"PRECIO: "<< texto << "\n";
            texto = Pro[i].imp;
            archivo << "IMPUESTO: "<< texto << "\n";
            texto = Pro[i].coniva;
            archivo << "TOTAL: "<< texto << "\n" << "\n";
        }
    }


    archivo.close();
}