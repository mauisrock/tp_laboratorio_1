#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define MAX 20

/*******************************************************************
* Programa: Estructura de personas
*
* Objetivo:
*
*           Definir una estructura que represente una persona,
*           con los campos nombre, edad, dni y un flag de estado.
*           Mostrar en pantalla lista ordenada por nombre, y
*           estadistica con 3 rangos de edades.
*
*  Version: 0.1 del 28 Abril de 2016
*  Autor: Mauro Barroso
*
********************************************************************/

int main()
{

    char seguir='s';
    int opcion=0;
    EPersona add[MAX];

    vacio(add);
    while(seguir=='s')
    {
		printf("\n 1) Agregar persona                    ");
		printf("\n                                       ");
		printf("\n 2) Borrar persona                     ");
		printf("\n                                       ");
		printf("\n 3) Imprimir lista ordenada por nombre ");
		printf("\n                                       ");
		printf("\n 4) Imprimir grafico de edades         ");
		printf("\n                                       ");
		printf("\n 5) Salir            		             ");
		printf("\n\n");
        printf(" Elija una opcion (1-5): ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            system("cls");
            addPerson(add);
            system("cls");
                break;
            case 2:
            system("cls");
            ordenarLista(add);///* Se vuelven a mostrar la lista
            deletePerson(add);///* para que el usuario vea la posición a eliminar.
            system("cls");
                break;
            case 3:
            system("cls");
            ordenarLista(add);
                break;
            case 4:
            system("cls");
            CalcularEdades(add);
                break;
            case 5:
                seguir='n';
                break;
        }
    }
    return 0;
}
