#include <iostream>
#include <math.h> 
#include <conio.h> 
#include <stdio.h>
using  namespace std;

int main()
{

    char nombre [40], desc [128], gen[40], clas[40], con[40];
    int numero, precio, opcion,desicion;

    cout << endl;
    cout << "\t ***MENU DE OPCIONES***" << endl; 
    cout << "1.-Alta de articulos" << endl;
    cout << "2.-Modificacion de articulos" << endl;
    cout << "3.-Baja de articulos" << endl;
    cout << "4.-Lista de articulos" << endl;
    cout << "5.-Limpiar pantalla" << endl;
    cout << "6.-Salir" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1: //ALTA
        
        cout << "\nIngrese el numero de item" << endl;
        cin >> numero;
        cin.get();//Pausa para ejecutar el código
        cout << "Ingrese el nombre del articulo" << endl;
        cin.getline(nombre, 40);//Getline es usado para leer espacios en blanco
        cout << "Ingrese la descripcion del articulo" << endl;
        cin.getline(desc, 128);
        cout << "Ingrese el genero" << endl;
        cin.getline(gen, 40);
        cout << "Ingrese la clasificacion del articulo" << endl;
        cin.getline(clas, 40);
        cout << "Ingrese la consola" << endl;
        cin.getline(con, 40);
        cout << "Ingrese el precio del articulo" << endl;
        cin >> numero;

        cout <<endl<< "Desea dar de alta otro articulo?"<<endl<<"1. si  2. no" << endl;
        cin >> desicion;
        if (desicion == 1)
        {
            //system("pause");
            return main();
        }
        break;
    case 2://MODIFICACION
        break;

    case 3://BAJA
        break;

    case 4://LISTA
        break;

    case 5://LIMPIAR
        system("cls"); 
        return main();
        break;
    case 6://SALIR
        exit(1); 
        break;
    default:
        cout << "Opcion invalida" << endl;
        return main();
        break;
    }
}