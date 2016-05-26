#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define MAX 10


/** \brief Inicializa todos los flags de estado en -1
 * \param movies representa a la estructura de peliculas
 * \return void
 *
 */

void inicializar(EMovies movies[])
{
    int i;

    for(i=0;i<MAX;i++)
    {
        movies[i].isEmpty=-1;
    }
}

/** \brief Llena la estructura de peliculas de forma iterativa respetando sus validaciones.
 *
 * \param movies representa la estructura de peliculas.
 * \param dato1 representa el primer mensaje que hace referencia al primer dato a cargar.
 * \param dato2 representa el segundo mensaje que hace referencia al segundo dato a cargar.
 * \param dato3 representa el tercer mensaje que hace referencia al tercer dato a cargar.
 * \param dato4 representa el cuarto mensaje que hace referencia al cuarto dato a cargar.
 * \param dato5 representa el quinto mensaje que hace referencia al quinto dato a cargar.
 * \param dato6 representa el quinto mensaje que hace referencia al sexto dato a cargar.
 * \param Error1 representa el mensaje de error correspondiente al dato1.
 * \param Error2 representa el mensaje de error correspondiente al dato2.
 * \param Error3 representa el mensaje de error correspondiente al dato3.
 * \param Error4 representa el mensaje de error correspondiente al dato4.
 * \param Error5 representa el mensaje de error correspondiente al dato5.
 * \param Error6 representa el mensaje de error correspondiente al dato6.
 * \return void
 *
 */

void addMovie(EMovies movies[],char dato1[],char dato2[],char dato3[],char dato4[],char dato5[],char dato6[],char Error1[],char Error2[],char Error3[],char Error4[],char Error5[],char Error6[])
{
    int i,auxBreak;
    char aux1[50];
    char aux2[50];
    int  aux3;
    char aux4[1000];
    float aux5;
    char aux6[256];

    auxBreak=0;

    for(i=0;i<MAX && auxBreak==0;i++)
    {
            if(movies[i].isEmpty==-1)
            {
                puts(dato1);        ///TITULO
                fflush(stdin);
                gets(aux1);
                strcpy(movies[i].titulo,aux1);
                fflush(stdin);
                //**********************************
                puts(dato2);        ///GENERO
                fflush(stdin);
                gets(aux2);
                if(validacionCadena(aux2)==1)
                {
                    system("cls");
                    puts(Error2);
                    fflush(stdin);
                    system("pause");
                    break;
                }
                strcpy(movies[i].Genero,aux2);
                fflush(stdin);
                //**********************************
                puts(dato3);        ///DURACION
                fflush(stdin);
                scanf("%d",&aux3);
                if(validacionNumerica(aux3,1,2,3)==1)
                   {
                    system("cls");
                    puts(Error3);
                    fflush(stdin);
                    system("pause");
                    break;
                   }
                movies[i].duracion=aux3;
                fflush(stdin);
                //**********************************
                puts(dato4);        ///DESCRIPCION
                fflush(stdin);
                gets(aux4);
                strcpy(movies[i].descripcion,aux4);
                fflush(stdin);
                //**********************************
                puts(dato5);        ///PUNTAJE
                scanf("%f",&aux5);
                movies[i].puntaje=aux5;
                fflush(stdin);
                //**********************************
                puts(dato6);        ///LINK IMAGEN
                fflush(stdin);
                gets(aux6);
                strcpy(movies[i].Link_imagen,aux6);
                fflush(stdin);
                //**********************************
                movies[i].isEmpty=0;
                //**********************************

                system("cls");
                printf("Pelicula agregada con exito.\n\n");
                system("pause");
                system("cls");
                auxBreak=1;
            }
    }
}

/** \brief modifica 5 datos de la estructura tomando un dato principal como referencia
 *
 * \param movies representa a la estructura de peliculas.
 * \param datoPrincipal representa el dato correspondiente a la pelicula que se desea modificar.
 * \param dato1 representa el primer mensaje que hace referencia al primer dato a cargar.
 * \param dato2 representa el segundo mensaje que hace referencia al segundo dato a cargar.
 * \param dato3 representa el tercer mensaje que hace referencia al tercer dato a cargar.
 * \param dato4 representa el cuarto mensaje que hace referencia al cuarto dato a cargar.
 * \param dato5 representa el quinto mensaje que hace referencia al quinto dato a cargar.
 * \return void
 *
 */

void modifyMovie(EMovies movies[],char datoPrincipal[],char dato1[],char dato2[],char dato3[],char dato4[],char dato5[],char error1[],char error2[])
{
    char auxPrincipal[50],aux1[50],aux3[1000],aux5[256];
    int i,aux2,opcion;
    float aux4;

    puts(datoPrincipal);
    fflush(stdin);
    gets(auxPrincipal);

    for(i=0;i<MAX;i++)
    {
        if(strcmp(movies[i].titulo,auxPrincipal)==0)
        {
            printf("             Se encontro la pelicula   " );
            printf("\n         ษอออออออออออออออออออออออออออป");
            printf("\n         บ    QUE DESEA MODIFICAR?:  บ");
            printf("\n         ฬอออออออออออออออออออออออออออน");
            printf("\n         บ                           บ");
            printf("\n         บ  1)- Genero               บ");
            printf("\n         บ                           บ");
            printf("\n         บ  2)- Duracion             บ");
            printf("\n         บ                           บ");
            printf("\n         บ  3)- Descripcion          บ");
            printf("\n         บ                           บ");
            printf("\n         บ  4)- Puntaje              บ");
            printf("\n         บ                           บ");
            printf("\n         บ  5)- Imagen               บ");
            printf("\n         บ                           บ");
            printf("\n         บ  6)- Salir                บ");
            printf("\n         บ                           บ");
            printf("\n         ศอออออออออออออออออออออออออออผ");
            printf("\n");
            printf("\n              Elija una opcion: ");
            scanf("%d",&opcion);

            switch(opcion)
            {
                //**************************************************
                case 1:
                    system("cls");          ///GENERO
                    fflush(stdin);
                    printf("Ingrese su nuevo %s: ",dato1);
                    gets(aux1);
                    if(validacionCadena(aux1)==1)
                    {
                        system("cls");
                        puts(error1);
                        fflush(stdin);
                        system("pause");
                        break;
                    }
                    for(i=0;i<MAX;i++)
                    {
                        if(strcmp(movies[i].titulo,auxPrincipal)==0)
                        {
                            strcpy(movies[i].Genero,aux1);
                        }
                    }
                    printf("\nSu nuevo %s es: %s \n",dato1,aux1);
                    break;
                //**************************************************
                case 2:
                    system("cls");          ///DURACION
                    fflush(stdin);
                    printf("Ingrese su nuevo %s: ",dato2);
                    scanf("%d",&aux2);
                    if(validacionNumerica(aux2,1,2,3)==1)
                    {
                        system("cls");
                        puts(error2);
                        fflush(stdin);
                        system("pause");
                        break;
                    }
                    for(i=0;i<MAX;i++)
                    {
                        if(strcmp(movies[i].titulo,auxPrincipal)==0)
                        {
                            movies[i].duracion=aux2;
                        }
                    }
                    printf("\nSu nueva %s es: %d \n",dato2,aux2);
                    break;
                //**************************************************
                case 3:
                    system("cls");          ///DESCRIPCION
                    fflush(stdin);
                    printf("Ingrese su nueva %s: \n",dato3);
                    gets(aux3);
                    for(i=0;i<MAX;i++)
                    {
                        if(strcmp(movies[i].titulo,auxPrincipal)==0)
                        {
                            strcpy(movies[i].descripcion,aux3);
                        }
                    }
                    printf("\nSu nuevo %s es: %s",dato3,aux3);
                    break;
                //**************************************************
                case 4:
                    system("cls");          ///PUNTAJE
                    fflush(stdin);
                    printf("Ingrese su nuevo %s: ",dato4);
                    scanf("%f",&aux4);
                    for(i=0;i<MAX;i++)
                    {
                        if(strcmp(movies[i].titulo,auxPrincipal)==0)
                        {
                            movies[i].puntaje=aux4;
                        }
                    }
                    printf("\nSu nuevo %s es: %.1f \n",dato4,aux4);
                    break;
                //**************************************************
                case 5:
                    system("cls");          ///LINK IMAGEN
                    fflush(stdin);
                    printf("Ingrese su nueva %s: ",dato5);
                    gets(aux5);
                    for(i=0;i<MAX;i++)
                    {
                        if(strcmp(movies[i].titulo,auxPrincipal)==0)
                        {
                            strcpy(movies[i].Link_imagen,aux5);
                        }
                    }
                    printf("\nSu nueva imagen ha sido cambiada. \n");
                    break;
                //**************************************************
                case 6:
                    system("cls");
                    break;
                }
        }
    }
}

/** \brief Elimina una pelicula usando un dato como referencia
 *
 * \param movies del representa la estructura de peliculas
 * \param dato es el dato a ser mostrado como referencia
 * \return void
 */

void deleteMovie(EMovies movies[],char dato[])
{
    int i;
    char auxChar[50];
    fflush(stdin);
    puts(dato);
    gets(auxChar);


    for(i=0;i<MAX;i++)
    {
        if(strcmp(movies[i].titulo,auxChar)==0 && movies[i].isEmpty==0)
        {
            movies[i].isEmpty=-1;
            system("cls");
            printf("Se elimino la pelicula con exito.\n");
            system("pause");
            system("cls");
            break;
        }
    }
}

/** \brief Guarda la informacion en un binario, si no existe lo crea, para mantener la informacion de la estructura.
 *
 * \param  movies representa la estructura de peliculas
 * \return 1 si fopen es NULL, 0 si se guardo.
 *
 */

int guardarEnArchivo(EMovies movies[])
{

	FILE *f;

		f=fopen("bin.dat","wb");
		if(f == NULL)
		{
			return 1;
		}

	fwrite(movies,sizeof(EMovies),MAX,f);

	fclose(f);

	return 0;
}

/** \brief Carga un archivo .BIN para mantener la informacion de las estructura.
 *
 * \param  movies del representa la estructura de peliculas
 * \return 1 si no se pudo cargar, 0 si se pudo leer.
 *
 */

int cargarDesdeArchivo(EMovies movies[])
{
	int flag = 0;
	FILE *f;

	f=fopen("bin.dat", "rb");
	if(f==NULL)
	{
		f= fopen("bin.dat", "wb");
		if(f==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag ==0)
	{
	fread(movies,sizeof(EMovies),MAX,f);
    }

	fclose(f);
	return 0;

}

/** \brief Crea un archivo .HTML para visualizar la lista de peliculas.
 *
 * \param  movies representa la estructura de peliculas
 * \return void
 *
 */

void crearHTML(EMovies movies[])
{
     int i;
     FILE *f;
     f=fopen("index.html", "w");

     if(f == NULL)
     {
          printf("No se pudo abrir el archivo\n");
     }
     else
     {
         fprintf(f,"<!DOCTYPE html> <html lang='en'> <head> <meta charset='utf-8'> <meta http-equiv='X-UA-Compatible' content='IE=edge'> <meta name='viewport' content='width=device-width, initial-scale=1'> <title>Lista peliculas</title> <link href='css/bootstrap.min.css' rel='stylesheet'> <link href='css/animate.css' rel='stylesheet'> <link href='css/custom.css' rel='stylesheet'> </head> <body><nav class='navbar navbar-inverse navbar-fixed-top' role='navigation'> <div class='container'> <div class='navbar-header'><button type='button'class='navbar-toggle' data-toggle='collapse' data-target='#bs-example-navbar-collapse-1'><span class='sr-only'>Toggle navigation</span><span class='icon-bar'></span> <span class='icon-bar'></span> <span class='icon-bar'></span></button><span class='navbar-brand glyphicon glyphicon-film animated in fadeIn'></span><a class='navbar-brand animated in fadeIn' href='#'>Listado de peliculas</a></div><div class='collapse navbar-collapse' id='bs-example-navbar-collapse-1'> <ul class='nav navbar-nav'> <li><a class='animated in fadeIn' target='_blank' href='http://www.imdb.com/'>IMDb (Base de datos de peliculas)</a></ul></div></div></nav>  <div class='container'> <div class='row'>");

         for(i=0; i<MAX; i++)
         {
                  if(movies[i].isEmpty==0)
                  {
                    ///<article>..pelicula..</article>
                    fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-thumbnail img-size' src='%s' alt=''></a><h3><a class='white' href='#'>%s</a></h3><ul><li>Genero: %s</li><li>Puntaje: %.1f </li><li>Duracion: %d</li></ul><div class='custom'>%s</div></article>",movies[i].Link_imagen,movies[i].titulo, movies[i].Genero, movies[i].puntaje, movies[i].duracion,movies[i].descripcion);
                  }
         }

         fprintf(f,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body> </html>");
     }

      fclose(f);
      printf("Pagina web creada con exito\n");
      system("pause");
      system("cls");
}

/** \brief Validacion por cantidad de digitos del numero ingresado.
 *
 * \param  num es el numero a analizar.
 * \param  limite es la cantidad de digitos permitida
 * \return 0 si el limite es el planteado o 1 si es erroneo.
 *
 */

int validacionNumerica(int num,int limite,int limite1,int limite2)
{
    int contador=1;
    while(num/10>0)
    {
        num=num/10;
        contador++;
    }
    if(contador==limite || contador==limite1 || contador==limite2)
    {
        return 0;
    }

    else
    {
        return 1;
    }
}

/** \brief Valida si es solo cadena
 *
 * \param  cadena es la cadena a ser analizada
 * \return 0 si es solo letras o 1 si distinto de letras
 *
 */

int validacionCadena(char cadena[])
{
    int i=0,j,retorno=0;

    j=strlen(cadena);

    while(i<j && retorno==0)
    {
        if(isalpha(cadena[i])!=0)
        {
            i++;
        }
        else
        {
            retorno=1;
        }

    }
    return retorno;
}
