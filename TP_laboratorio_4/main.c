#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movies.h"
#include "arraylist.h"

/*******************************************************************
* Programa: MOVIES ABM
*
* Objetivo: Realizar un programa que haga uso de
*           las funciones del arraylist.h.
*
*
*
*
* Version: 0.1 del 23 Junio de 2016
* Autor: Mauro Barroso
*
********************************************************************/

int main()
{
    ArrayList* AMovies = al_newArrayList();
    ArrayList* AMoviesD = al_newArrayList();
    EMovie* Element=malloc(sizeof(EMovie));

    //******************************
    char file_movie[20]="bin.dat";      //Binario peliculas
    char file_movieD[20]="binD.dat";    //Binario peliculas eliminadas
    //******************************
    char len[20]="len.txt";             //Tamaño del array peliculas
    char lenD[20]="lenD.txt";           //Tamaño del array peliculas eliminadas
    //******************************
    char opcion;
    char guardar;
    //******************************
    load(AMovies,file_movie,len);       //Cargo el array de peliculas
    load(AMoviesD,file_movieD,lenD);    //Cargo el array de peliculas eliminadas
    //******************************
    printf("Carga Completa...\n");
    system("pause");

    do
    {
        menu();
        opcion=getchar();

        switch(opcion)
        {
        case '0':
            al_add(AMovies,addMovie());
            break;
        case '1':
            Element=deleteMovie(AMovies);
            al_add(AMoviesD,eliminadas(Element));
            break;
        case '2':
            ModifyMovie(AMovies,len);
            break;
        case '3':
            printArrayMovie(AMovies);
            system("pause");
            break;
        case '4':
            crearHTML(AMovies,len);
            break;
        case '5':
            printArrayMovie(AMoviesD);
            system("pause");
            break;
        case '6':
            sublista(AMovies);
            break;
        case '7':
            agregarEliminado(AMovies,AMoviesD);
            break;
        case'8':
            fflush(stdin);
            printf("\nGuardar cambios S/N ?: ");
            guardar = tolower(getchar());
            if(guardar == 's')
            {
                save(AMovies,file_movie,len);
                save(AMoviesD,file_movieD,lenD);
                printf("\nSe guardo correctamente...\n");
                system("pause");
            }
            break;
        }
        fflush(stdin);
        system("cls");
    }
    while(opcion!='8');
    free(AMovies);
    free(AMoviesD);
    return 0;
}
