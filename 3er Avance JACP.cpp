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
        printf(" \n\t * * * �RITH GAMING Systems * * * \n");
        printf("\t     |Tienda de videojuegos|  \n");
    }
        printf(" \n\t * * * MEN� DE OPCIONES * * * \n");
        printf("1.-Alta de art�culos \n");
        printf("2.-Modificaci�n de art�culos \n");
        printf("3.-Baja de art�culos \n");
        printf("4.-Lista de art�culos \n");
        printf("5.-Limpiar pantalla \n");
        printf("6.-Salir \n");
        printf("\nIngrese el n�mero de la acci�n a realizar\n");
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
                printf("\nA�n no se realizan registros\n");
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
                printf("\nA�n no se realizan registros\n");
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
                printf("\nA�n no se realizan registros\n");
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
            printf("Opci�n inv�lida \n");
            return main();
            break;
        }
}

void Alta()
{
    printf("\n�Cu�ntos registros desea dar de alta? \n");
    scanf_s("%d", &alta);
    while (alta <= 0) {
        printf("\nN�mero inv�lido\n");
        printf("\n�Cu�ntos registros desea dar de alta? \n");
        scanf_s("%d", &alta);
    }
    Pro = new tienda[alta]; // uso de new para hacer el arreglo dinamico
    for (int i = 0; i < alta; i++)
    {
        int nump, fe;
        printf("\nREGISTRO #%d\n", i + 1);
        cin.ignore();//Necesario para el uso de string.
        printf("\nIngrese el n�mero de item \n");
        scanf_s("%d", &nump);
        while (Repetido(nump, i)) {
            printf("El n�mero esta repetido\n");
            printf("\nIngrese el n�mero de �tem \n");
            scanf_s("%d", &nump);
        }
        Pro[i].numero = nump;
        cin.ignore();//Necesario para el uso de string.
        printf("Ingrese el nombre del art�culo \n");
        getline(cin, Pro[i].nombre);
        printf("Ingrese el a�o de lanzamiento del art�culo \n");
        scanf_s("%d", &fe);
        while (fecha(fe)) {
            printf("\nLa fecha no es v�lida\n");
            printf("\nIngrese el a�o de lanzamiento del art�culo \n");
            scanf_s("%d", &fe);
        }
        Pro[i].year = fe;
        cin.ignore();
        printf("Ingrese la descripci�n del art�culo \n");
        getline(cin, Pro[i].desc);
        printf("Ingrese las caracter�sticas del art�culo \n");
        getline(cin, Pro[i].carat);
        printf("Ingrese el g�nero \n");
        getline(cin, Pro[i].gen);
        printf("Ingrese la clasificaci�n del art�culo \n");
        getline(cin, Pro[i].clas);
        printf("Ingrese la consola \n");
        getline(cin, Pro[i].con);
        printf("Ingrese el precio del art�culo \n");
        scanf_s("%f", &Pro[i].precio);

        Pro[i].imp = Pro[i].precio * 0.16;
        Pro[i].coniva = Pro[i].precio + Pro[i].imp;
    }
    w = 1;
    printf("\nRegistro exitoso\n\nRegresando al men�\n");
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
    printf("\n�Desea filtrar los art�culos? 1.Si 2.No \n");
    scanf_s("%d", &o1);
    while (o1 != 1 && o1 != 2) {
        printf("Opci�n inv�lida \nIngrese una opci�n v�lida\n");
        printf("\n�Desea filtrar los art�culos? 1.Si 2.No \n");
        scanf_s("%d", &o1);
    }

    if (o1 == 1) {
        printf("\n�Qu� categor�a desea filtrar? \n\n1.Clasificaci�n 2.G�nero 3.Consola\n");
        scanf_s("%d", &o2);
        int r;
        string tubatu;
        switch (o2) {
        case 1:
            cin.ignore();//Necesario para el uso de string.
            printf("\nIngrese la clasificaci�n que desea visualizar \n");
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
                        printf("N�mero de �tem: %d \n", Pro[i].numero);
                        printf("Nombre del art�culo: %s \n", Pro[i].nombre.c_str());
                        printf("A�o de lanzamiento del item: %d \n", Pro[i].year);
                        printf("Descripci�n del art�culo: %s \n", Pro[i].desc.c_str());
                        printf("Caracter�sticas del art�culo: %s \n", Pro[i].carat.c_str());
                        printf("G�nero: %s \n", Pro[i].gen.c_str());
                        printf("Clasificaci�n: %s \n", Pro[i].clas.c_str());
                        printf("Consola: %s \n", Pro[i].con.c_str());
                        printf("Precio: %f \n", Pro[i].precio);
                        printf("Impuesto: %f \n", Pro[i].imp);
                        printf("Total: %f \n", Pro[i].coniva);
                    }
                }
            }
            if (s == 0) {
                printf("\nNo hay art�culos registrados de esa clasificaci�n\n\nRegresando al men�\n");
            }
            break;
            case 2:
                cin.ignore();//Necesario para el uso de string.
                printf("\nIngrese el g�nero que desea visualizar \n");
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
                            printf("N�mero de �tem: %d \n", Pro[i].numero);
                            printf("Nombre del art�culo: %s \n", Pro[i].nombre.c_str());
                            printf("A�o de lanzamiento del �tem: %d \n", Pro[i].year);
                            printf("Descripci�n del art�culo: %s \n", Pro[i].desc.c_str());
                            printf("Caracter�sticas del art�culo: %s \n", Pro[i].carat.c_str());
                            printf("G�nero: %s \n", Pro[i].gen.c_str());
                            printf("Clasificaci�n: %s \n", Pro[i].clas.c_str());
                            printf("Consola: %s \n", Pro[i].con.c_str());
                            printf("Precio: %f \n", Pro[i].precio);
                            printf("Impuesto: %f \n", Pro[i].imp);
                            printf("Total: %f \n", Pro[i].coniva);
                        }
                    }
                }
                if (s == 0) {
                    printf("\nNo hay art�culos registrados de ese g�nero\n\nRegresando al men�\n");
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
                        printf("N�mero de �tem: %d \n", Pro[i].numero);
                        printf("Nombre del art�culo: %s \n", Pro[i].nombre.c_str());
                        printf("A�o de lanzamiento del �tem: %d \n", Pro[i].year);
                        printf("Descripci�n del art�culo: %s \n", Pro[i].desc.c_str());
                        printf("Caracter�sticas del art�culo: %s \n", Pro[i].carat.c_str());
                        printf("G�nero: %s \n", Pro[i].gen.c_str());
                        printf("Clasificaci�n: %s \n", Pro[i].clas.c_str());
                        printf("Consola: %s \n", Pro[i].con.c_str());
                        printf("Precio: %f \n", Pro[i].precio);
                        printf("Impuesto: %f \n", Pro[i].imp);
                        printf("Total: %f \n", Pro[i].coniva);
                    }
                }
            }
            if (s == 0) {
                printf("\nNo hay art�culos registrados de esa consola\n\nRegresando al men�\n");
            }
            break;
            default:
                printf("\nOpci�n inv�lida \n");
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
                printf("N�mero de �tem: %d \n", Pro[i].numero);
                printf("Nombre del art�culo: %s \n", Pro[i].nombre.c_str());
                printf("A�o de lanzamiento del �tem: %d \n", Pro[i].year);
                printf("Descripci�n del art�culo: %s \n", Pro[i].desc.c_str());
                printf("Caracter�sticas del art�culo: %s \n", Pro[i].carat.c_str());
                printf("G�nero: %s \n", Pro[i].gen.c_str());
                printf("Clasificaci�n: %s \n", Pro[i].clas.c_str());
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
        printf("\nOpci�n inv�lida\n");
        printf("\nIngrese un numero de registro v�lido\n");
        printf("\nIngrese el registro a eliminar:\n");
        scanf_s("%d", &j);
    }
    j = j - 1;
    for (int i = j; i == j; i++)
    {
        printf("\nEliminando registro %d \n", j + 1);
        Pro[i].status = "ELIMINADO";
        printf("\nRegistro #%d eliminado correctamente\n\nRegresando al men�\n",j+1);
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
            printf("\nOpci�n inv�lida\n");
            printf("\nIngrese un n�mero de registro v�lido\n");
            printf("\nIngrese el n�mero registro a modificar:\n");
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
                printf("Ingrese un registro v�lido \n");
                op2 = 1;
            }
            else
            {
                op2 = 2;
            }
        }
    } while (op2 == 1);
    printf("\nIngrese que desea modificar:\n");
    printf("1.-N�mero del art�culo \n");
    printf("2.-Nombre del art�culo \n");
    printf("3.-A�o de lanzamiento del art�culo \n");
    printf("4.-Descripci�n del art�culo \n");
    printf("5.-Caracter�sticas del art�culo \n");
    printf("6.-G�nero del art�culo  \n");
    printf("7.-Clasificaci�n del art�culo \n");
    printf("8.-Consola del art�culo \n");
    printf("9.-Precio del art�culo \n");
    scanf_s("%d", &opcion);

    switch (opcion)
    {
    case 1:
        for (int i = j; i == j; i++)
        {
            printf("\nIngrese el numero de �tem \n");
            scanf_s("%d", &nump);
            while (Repetido(nump, i)) {
                printf("El n�mero esta repetido\n");
                printf("\nIngrese el n�mero de item \n");
                scanf_s("%d", &nump);
            }
            Pro[i].numero = nump;
        }
        printf("\nModificaci�n exitosa\n\nRegresando al men�\n");
        break;
    case 2:
        for (int i = j; i == j; i++)
        {
            cin.ignore();//Necesario para el uso de string.
            printf("\nIngrese el nombre del art�culo \n");
            getline(cin, Pro[i].nombre);
            printf("\nModificaci�n exitosa\n\nRegresando al men�\n");
        }
        break;
    case 3:
        for (int i = j; i == j; i++)
        {
            printf("\nIngrese el a�o de lanzamiento del art�culo \n");
            scanf_s("%d", &fe);
            while (fecha(fe)) {
                printf("\nLa fecha no es v�lida\n");
                printf("\nIngrese el a�o de lanzamiento del art�culo \n");
                scanf_s("%d", &fe);
            }
            Pro[i].year = fe;
        }
        printf("\nModificaci�n exitosa\n\nRegresando al men�\n");
        break;
    case 4:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("\nIngrese la descripci�n del art�culo \n");
            getline(cin, Pro[i].desc);
            printf("\nModificaci�n exitosa\n\nRegresando al men�\n");
        }
        break;

    case 5:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("\nIngrese las caracter�sticas del art�culo \n");
            getline(cin, Pro[i].carat);
            printf("\nModificaci�n exitosa\n\nRegresando al men�\n");
        }
        break;
    case 6:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("\nIngrese el g�nero \n");
            getline(cin, Pro[i].gen);
            printf("\nModificaci�n exitosa\n\nRegresando al men�\n");
        }
        break;
    case 7:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("\nIngrese la clasificaci�n del art�culo \n");
            getline(cin, Pro[i].clas);
            printf("\nModificaci�n exitosa\n\nRegresando al men�\n");
        }
        break;
    case 8:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("\nIngrese la consola \n");
            getline(cin, Pro[i].con);
            printf("\nModificaci�n exitosa\n\nRegresando al men�\n");
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
        printf("\nModificaci�n exitosa\n\nRegresando al men�\n");
        break;
    default:
        printf("\nOpci�n inv�lida \n");
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

    archivo << "\t" << "�RITH GAMING Systems" << "\n";
    /*archivo << "NUMERO" << "\t" << "\t";
    archivo << "NOMBRE" << "\t" << "\t";
    archivo << "A�O" << "\t" << "\t";
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
            archivo <<"\n"<< "N�MERO:" << texto << "\n";
            texto2 = Pro[i].nombre;
            archivo << "NOMBRE: " << texto2 << "\n";
            texto = Pro[i].year;
            archivo << "A�O: " << texto << "\n";
            texto2 = Pro[i].desc;
            archivo << "DESCRIPCI�N: "<< texto2 << "\n";
            texto2 = Pro[i].carat;
            archivo << "CARACTER�STICAS: "<< texto2 << "\n";
            texto2 = Pro[i].gen;
            archivo << "G�NERO: "<< texto2 << "\n";
            texto2 = Pro[i].clas;
            archivo << "CLASIFICACI�N: "<< texto2 << "\n";
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