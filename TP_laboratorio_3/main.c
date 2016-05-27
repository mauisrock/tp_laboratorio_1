#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define MAX 10

/*******************************************************************
* Programa: ABM Peliculas
*
* Objetivo:
*
*    Cargar las estructuras a un archivo binario, realizar ABM de
*    peliculas y listarlas en una pagina web.
*
* Version: 0.1 del 23 Mayo de 2016
* Autor: Mauro Barroso
*
********************************************************************/

int main()
{
    char datoMenu[50]="Pelicula";
    char opcion;

    EMovies movies[MAX];
    inicializar(movies);

	char guardar;


	if(cargarDesdeArchivo(movies))
	{
		printf("No se pudo abrir el fichero");
	}
	else
	{
		printf("Las estructuras se cargaron con exito!\n\n");
	}
	system("pause");
	system("cls");

    do
    {
		printf("\n         ษอออออออออออออออออออออออออออป");
		printf("\n         บ         PELICULAS         บ");
		printf("\n         ฬอออออออออออออออออออออออออออน");
		printf("\n         บ                           บ");
		printf("\n         บ  1)- Agregar pelicula     บ");
		printf("\n         บ                           บ");
		printf("\n         บ  2)- Borrar pelicula      บ");
		printf("\n         บ                           บ");
		printf("\n         บ  3)- Modificar pelicula   บ");
		printf("\n         บ                           บ");
		printf("\n         บ  4)- Generar pagina web   บ");
		printf("\n         บ                           บ");
		printf("\n         บ  5)- Salir                บ");
		printf("\n         บ                           บ");
		printf("\n         ฬอออออออออออออออออออออออออออน");
		printf("\n         บ   Autor: Mauro Barroso    บ");
		printf("\n         ศอออออออออออออออออออออออออออผ");
		printf("\n");
		printf("\n              Elija una opcion: ");
        opcion=getchar();

        switch(opcion)
        {
                case '1':
                    system("cls");
                        addMovie(movies,"Ingrese el titulo: ","Ingrese el genero: ","Ingrese la duracion expresada en minutos: ","Ingrese la descripcion: ","Ingrese el puntaje: ","Inserte el link de la imagen: ","Titulo incorrecto - No se cargaron los datos.\n","Error ,usar solamente letras para indicar el genero - No se cargaron los datos.\n","Error. Solo minutos expresados en 1, 2 o 3 cifras numericas.","Descripcion incorrecta - No se cargaron los datos.","Error, solo puntaje del 1 al 10 - No se cargaron los datos.","Link de imagen incorrecto - No se cargaron los datos.");
                    break;

                case '2':
                    system("cls");
                    if(caseVerify(movies)==0)
                        deleteMovie(movies,"Ingrese el titulo de la pelicula: ");
                    else
                        printf("No hay %s registradas.\n",datoMenu);
                        system("pause");
                    break;

                case '3':
                    system("cls");
                    if(caseVerify(movies)==0)
                        modifyMovie(movies,"Ingrese el titulo de la pelicula: ","Genero","Duracion","Descripcion","Puntaje","Imagen","Error ,usar solamente letras para indicar el genero - No se cargaron los datos.\n","Error. Solo minutos expresados en 1, 2 o 3 cifras numericas.\n");
                    else
                        printf("No hay %s registradas.\n",datoMenu);
                        system("pause");
                    break;

                case '4':
                    system("cls");
                    if(caseVerify(movies)==0)
                        crearHTML(movies);
                    else
                        printf("No hay %s registradas.\n",datoMenu);
                        system("pause");
                    break;

                case '5':
                    fflush(stdin);
                    printf("\nGuardar cambios S/N ?: ");
                    guardar = tolower(getchar());

                    if(guardar == 's')
                    {
                        if(guardarEnArchivo(movies))
                        {
                            printf("\nNo se pudo abrir el fichero\n");
                        }
                        else
                        {
                            printf("\nSe guardo la informacion con exito\n");
                            system("pause");
                        }
                    }
                    break;
        }
        system("cls");
    }   while(opcion!='5');
        return 0;
}
