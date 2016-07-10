#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movies.h"
#include "validaciones.h"

/** \brief Menu con las diferentes opciones
 *
 * \param  void
 * \param  void
 * \return void
 *
 */
void menu(void)
{
    printf("\n         ษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
    printf("\n         บ                    PELICULAS                      บ");
    printf("\n         ฬอออออออออออออออออออออออออออออออออออออออออออออออออออน");
    printf("\n         บ                                                   บ");
    printf("\n         บ  0)- Agregar pelicula    5)- Imprimir eliminadas  บ");
    printf("\n         บ                                                   บ");
    printf("\n         บ  1)- Borrar pelicula     6)- Crear sublista       บ");
    printf("\n         บ                                                   บ");
    printf("\n         บ  2)- Modificar pelicula  7)- Restaurar pelicula   บ");
    printf("\n         บ                                                   บ");
    printf("\n         บ  3)- Imprimir peliculas  8)- Salir y guardar      บ");
    printf("\n         บ                                                   บ");
    printf("\n         บ  4)- Crear pagina web                             บ");
    printf("\n         บ                                                   บ");
    printf("\n         บ                                                   บ");
    printf("\n         บ                                                   บ");
    printf("\n         ฬอออออออออออออออออออออออออออออออออออออออออออออออออออน");
    printf("\n         บ              Autor: Mauro Barroso                 บ");
    printf("\n         ศอออออออออออออออออออออออออออออออออออออออออออออออออออผ");
    printf("\n");
    printf("\n                        Elija una opcion: ");
}
/** \brief Retorna una nueva pelicula
 *
 * \param  titulo es el titulo a cargar en la esctructura.
 * \param  genero es el titulo a cargar en la esctructura.
 * \param  duracion es el titulo a cargar en la esctructura.
 * \param  descripcion es la descripcion a cargar en la esctructura.
 * \param  link_imagen es el link de la imagen a cargar en la esctructura.
 * \param  puntaje es el puntaje a cargar en la esctructura.
 * \return (NULL) si no se comple el condicional o un (EMovie) ya cargado
 */
EMovie* newMovie(char* titulo, char* genero,int duracion,char* descripcion,char* link_imagen,int puntaje)
{
    EMovie* returnAux = NULL;
    EMovie* pMovie = malloc(sizeof(EMovie));
    if(pMovie != NULL)
    {
        strcpy(pMovie->titulo,titulo);
        strcpy(pMovie->genero,genero);
        pMovie->duracion = duracion;
        strcpy(pMovie->descripcion,descripcion);
        strcpy(pMovie->link_imagen,link_imagen);
        pMovie->puntaje = puntaje;
        pMovie->isEmpty = 0;
        returnAux = pMovie;
    }
    return returnAux;
}
/** \brief Imprime por pantalla las peliculas desde la estructura.
 *
 * \param  print representa a la estructura EMovie.
 * \return void
 *
 */

void printMovie(EMovie* print)
{
    printf("*Titulo:       %s \n*Genero:       %s \n*Duracion      %d Min \n*Descripcion:  %s \n*Puntaje:      %d\n\n",print->titulo,print->genero,print->duracion,print->descripcion,print->puntaje);
}

/** \brief Imprime por pantalla las peliculas desde el Arraylist en conjunto con printMovie.
 *
 * \param  Array representa al arraylist creado.
 * \return void
 *
 */
void printArrayMovie(ArrayList* Array)
{
    char error[]="<!>Error. No hay peliculas cargadas.\n";
    if(al_isEmpty(Array)!=1)
    {
        int i=0;
        EMovie* Aux;
        for(i=0; i<Array->len(Array); i++)
        {
            Aux = Array->get(Array,i);
            printf("\n*P:%d)\n",i);
            printMovie(Aux);
        }
    }
    else
    {
        puts(error);
    }
}

/** \brief Permite el ingreso de los datos por teclado de la pelicula.
 *
 * \param  void
 * \return Emovie
 *
 */
EMovie* addMovie(void)
{
    EMovie* returnAux = NULL;
    EMovie* pMovie = malloc(sizeof(EMovie));
    //********************************************************
    char errorTitulo[]  = "<!>Error. Titulo incorrecto.\n";
    char errorGenero[]  = "<!>Error. Genero incorrecto.\n";
    char errorDuracion[]= "<!>Error. Duracion incorrecta\n";
    char errorPuntaje[] = "<!>Error. Puntaje fuera de los limites entre 1 y 10.\n";
    char errorAdd[]     = "<!>Error. La carga no pudo ser realizada.\n";
    //********************************************************
    char auxTitulo[50];
    char auxGenero[50];
    char auxDescripcion[1000];
    char auxLink_Imagen[256];
    int  auxPuntaje;
    int  auxDuracion;
    int  flag=0; //*Mientras "flag" permanezca en (0) la carga continua.

    if(pMovie != NULL)
    {
        //*****************************************************
        puts("*Ingrese titulo: ");          ///TITULO
        fflush(stdin);
        gets(auxTitulo);
        if(validarRangoCadena(auxTitulo,1,30)==-1)
        {
            flag=-1;
            system("cls");
            puts(errorTitulo);
            fflush(stdin);
            system("pause");
            system("cls");
        }
        fflush(stdin);
        //*****************************************************
        if(flag==0)
        {
            puts("*Ingrese genero: ");          ///GENERO
            fflush(stdin);
            gets(auxGenero);
            if(validarRangoCadena(auxGenero,1,16)==-1)
            {
                flag=-1;
                system("cls");
                puts(errorGenero);
                fflush(stdin);
                system("pause");
                system("cls");
            }
            fflush(stdin);
        }
        //*****************************************************
        if(flag==0)
        {
            puts("*Ingrese duracion en minutos: "); ///DURACION
            scanf("%d",&auxDuracion);
            if(validarRango(auxDuracion,1,300)==-1)
            {
                flag=-1;
                system("cls");
                puts(errorDuracion);
                fflush(stdin);
                system("pause");
                system("cls");
            }
            fflush(stdin);
        }
        //*****************************************************
        if(flag==0)
        {
            puts("*Ingrese descripcion: ");     ///DESCRIPCION
            fflush(stdin);
            gets(auxDescripcion);
            fflush(stdin);
        }
        //*****************************************************
        if(flag==0)
        {
            puts("*Ingrese puntaje: ");         ///PUNTAJE
            scanf("%d",&auxPuntaje);
            if(validarRango(auxPuntaje,1,10)==-1)
            {
                flag=-1;
                system("cls");
                puts(errorPuntaje);
                fflush(stdin);
                system("pause");
                system("cls");
            }
            fflush(stdin);
        }
        //*****************************************************
        if(flag==0)
        {
            puts("*Ingrese link de imagen: ");  ///LINK IMAGEN
            fflush(stdin);
            gets(auxLink_Imagen);
            fflush(stdin);
        }
        //******************************************************
        if(flag==0)
            returnAux=newMovie(auxTitulo,auxGenero,auxDuracion,auxDescripcion,auxLink_Imagen,auxPuntaje);
        //******************************************************
        if(flag==-1)
            puts(errorAdd);
        system("pause");
        //******************************************************
    }
    return returnAux;
}

/** \brief Elimina una pelicula de la lista y la retorna
 *
 * \param  Array representa al array creado.
 * \return (Emovie)
 *
 */
EMovie* deleteMovie(ArrayList* Array)
{
    EMovie* returnAux=NULL;
    EMovie* Aux;
    EMovie* Element;
    int i;
    int flag=-1;
    char auxChar[50];
    char error[]="<!>Error. No hay peliculas cargadas.\n";
    char errorBusqueda[]="<!>Error. La pelicula no se encuentra.\n";

    if(al_isEmpty(Array)!=1)
    {
        printf("Ingrese titulo:");
        fflush(stdin);
        gets(auxChar);

        for(i=0; i<Array->len(Array); i++)
        {
            Aux = Array->get(Array,i);
            if(strcmp(auxChar,Aux->titulo)==0)
            {
                flag=0;
                Element=al_pop(Array,i);
                printf("Pelicula eliminada: %s .\n",Element->titulo);
                returnAux=Element;
                system("pause");
            }
        }
        if(flag!=0)
        {
            puts(errorBusqueda);
            system("pause");
        }
    }
    else
    {
        puts(error);
        system("pause");
    }

    return returnAux;
}
/** \brief Hace el "add" al array de peliculas eliminadas
 *
 * \param  Element representa al elemento a agregar.
 * \return (Emovie)
 *
 */
EMovie* eliminadas(EMovie* Element)
{
    EMovie* returnAux = NULL;
    char auxTitulo[50];
    char auxGenero[50];
    char auxDescripcion[1000];
    char auxLink_Imagen[256];
    int auxPuntaje;
    int auxDuracion;

    if(Element != NULL)
    {
        strcpy(auxTitulo,Element->titulo);
        strcpy(auxGenero,Element->genero);
        auxDuracion=Element->duracion;
        strcpy(auxDescripcion,Element->descripcion);
        strcpy(auxLink_Imagen,Element->link_imagen);
        auxPuntaje=Element->puntaje;
        auxDuracion=Element->duracion;
        //*****************************************************
        returnAux=newMovie(auxTitulo,auxGenero,auxDuracion,auxDescripcion,auxLink_Imagen,auxPuntaje);
        //*****************************************************
    }
    return returnAux;
}
/** \brief Modifica las caracteristicas de cada pelicula haciendo una busqueda por titulo
 *
 * \param  Array representa al array creado.
 * \param  file_length representa al nombre del archivo que contiene el tama๑o del array
 * \return void
 *
 */
void ModifyMovie(ArrayList* Array,char* file_length)
{
    EMovie* Aux;
    //********************************************************
    char errorGenero[]  = "<!>Error. Genero incorrecto.\n";
    char errorDuracion[]= "<!>Error. Duracion incorrecta\n";
    char errorPuntaje[] = "<!>Error. Puntaje fuera de los limites entre 1 y 10.\n";
    char errorBusqueda[]= "<!>Error. La pelicula no se encuentra.\n";
    char error[]="<!>Error. No hay peliculas cargadas.\n";
    //********************************************************
    char auxTitulo[51];
    char aux3[1000];
    char aux5[700];
    char aux1[51];
    int  aux2;
    int  aux4;
    int  flag=0; //*Mientras "flag" permanezca en (0) la modificacion continua.
    int seEncuentra=-1;
    int opcion,i,tam;
    if(al_isEmpty(Array)!=1)
    {
        tam=lengthLoad(file_length);
        puts("*Ingrese el titulo: ");
        fflush(stdin);
        gets(auxTitulo);
        system("cls");
        for(i=0; i<tam; i++)
        {
            Aux = Array->get(Array,i);
            if(strcmp(Aux->titulo,auxTitulo)==0)
            {
                printf("               Se encontro la pelicula      " );
                printf("\n         ษออออออออออออออออออออออออออออออออป");
                printf("\n         บ      QUE DESEA MODIFICAR?:     บ");
                printf("\n         ฬออออออออออออออออออออออออออออออออน");
                printf("\n         บ                                บ");
                printf("\n         บ  1)- Genero       4)- Puntaje  บ");
                printf("\n         บ                                บ");
                printf("\n         บ  2)- Duracion     5)- Imagen   บ");
                printf("\n         บ                                บ");
                printf("\n         บ  3)- Descripcion  6)- Salir    บ");
                printf("\n         บ                                บ");
                printf("\n         ศออออออออออออออออออออออออออออออออผ");
                printf("\n");
                printf("\n                 Elija una opcion: ");
                scanf("%d",&opcion);
                seEncuentra=0;
                switch(opcion)
                {
                //**************************************************
                case 1:
                    system("cls");          ///GENERO
                    fflush(stdin);
                    printf("Ingrese su nuevo genero: ");
                    gets(aux1);
                    if(validarRangoCadena(aux1,1,16)!=0)
                    {
                        flag=-1;
                        system("cls");
                        puts(errorGenero);
                        fflush(stdin);
                        system("pause");
                    }
                    if(flag==0)
                    {
                        strcpy(Aux->genero,aux1);
                        printf("\nSu nuevo genero es: %s \n",aux1);
                        al_set(Array,i,Aux);
                        system("pause");
                    }
                    break;
                //**************************************************
                case 2:
                    system("cls");          ///DURACION
                    fflush(stdin);
                    printf("Ingrese su nueva duracion: ");
                    scanf("%d",&aux2);
                    if(validarRango(aux2,1,300)==-1)
                    {
                        flag=-1;
                        system("cls");
                        puts(errorDuracion);
                        fflush(stdin);
                        system("pause");
                        system("cls");
                    }
                    if(flag==0)
                    {
                        Aux->duracion=aux2;
                        printf("\nSu nueva duracion es de: %d minutos \n",aux2);
                        al_set(Array,i,Aux);
                        system("pause");
                    }
                    break;
                //**************************************************
                case 3:
                    system("cls");          ///DESCRIPCION
                    fflush(stdin);
                    printf("Ingrese su nueva descripcion: ");
                    gets(aux3);
                    strcpy(Aux->descripcion,aux3);
                    printf("\nSu nueva descripcion es: %s \n",aux3);
                    al_set(Array,i,Aux);
                    system("pause");
                    break;
                //**************************************************
                case 4:
                    system("cls");          ///PUNTAJE
                    fflush(stdin);
                    printf("Ingrese su nuevo puntaje: ");
                    scanf("%d",&aux4);
                    if(validarRango(aux4,1,10)==-1)
                    {
                        flag=-1;
                        system("cls");
                        puts(errorPuntaje);
                        fflush(stdin);
                        system("pause");
                        system("cls");
                    }
                    if(flag==0)
                    {
                        Aux->puntaje=aux4;
                        printf("\nSu nuevo puntaje es de: %d \n",aux2);
                        al_set(Array,i,Aux);
                        system("pause");
                    }

                    break;
                //**************************************************
                case 5:
                    system("cls");          ///LINK IMAGEN
                    fflush(stdin);
                    printf("Ingrese el link de la nueva imagen: ");
                    gets(aux5);
                    strcpy(Aux->link_imagen,aux5);
                    printf("\nImagen modificada con exito.\n");
                    al_set(Array,i,Aux);
                    system("pause");
                    break;
                //**************************************************
                case 6:
                    system("cls");
                    break;
                }
            }
        }
        if(seEncuentra!=0)
        {
            puts(errorBusqueda);
            system("pause");
        }
    }
    else
    {
        puts(error);
        system("pause");
    }
}

/** \brief Carga todas las peliculas desde un archivo binario
 *
 * \param  Array representa al array creado.
 * \param  file representa al nombre del binario
 * \param  file_length representa al nombre del archivo que contiene el tama๑o del array
 * \return 0 OK
 */
int load(ArrayList* Array,char* file,char* file_length)
{
    int returnAux = -1;
    int i,length;
    EMovie* Aux;
    FILE* f;
    f=fopen(file,"rb");

    length=lengthLoad(file_length);
    if(f!=NULL)
    {
        for(i=0; i<length; i++)
        {
            Aux=(EMovie*)malloc(sizeof(EMovie));
            fread(Aux,sizeof(EMovie),1,f);
            Array->add(Array,Aux);
        }
    }
    returnAux=0;
    fclose(f);
    return returnAux;
}

/** \brief Guarda todas las peliculas a un archivo binario
 *
 * \param  Array representa al array creado.
 * \param  file representa al nombre del binario
 * \param  file_length representa al nombre del archivo que contiene el tama๑o del array
 * \return 0 OK
 */
int save(ArrayList* Array,char* file,char* file_length)
{
    int returnAux = -1;
    int length,i;
    FILE* f;
    f=fopen(file,"r+b");
    if(f==NULL)
    {
        f=fopen(file,"w+b");
        if(f==NULL)
        {
            exit(1);
        }
    }
    length=Array->len(Array);
    for(i=0; i<length; i++)
    {
        fwrite(*((Array->pElements)+i),sizeof(EMovie),1,f);
    }
    lengthSave(length,file_length);
    returnAux=0;
    fclose(f);

    return returnAux;
}

/** \brief Guarda el tama๑o del array
 *
 * \param  length representa al size del array
 * \param  file_length representa al nombre del archivo que contiene el tama๑o del array
 * \return void
 */
void lengthSave(int length,char* file_length)
{
    FILE* f;

    f=fopen(file_length,"w+");
    if(f!=NULL)
    {
        fprintf(f,"%d",length);
    }
    fclose(f);
}
/** \brief Carga el tama๑o del array
 *
 * \param  file_length representa al nombre del archivo que contiene el tama๑o del array
 * \return void
 */
int lengthLoad(char* file_length)
{
    FILE* f;
    int length;

    f=fopen(file_length,"r+");
    if(f!=NULL)
    {
        fscanf(f,"%d",&length);
    }
    return length;
    fclose(f);
}

/** \brief Compara las peliculas por titulo permitiendo poder ordenarlas a futuro
 *
 * \param  pMovieA es el primer elemento a comparar
 * \param  pMovieB es el segundo elemento a comparar
 * \return 0
 */
int compareMovie(void* pMovieA,void* pMovieB)
{

    if(strcmp(((EMovie*)pMovieA)->titulo,((EMovie*)pMovieB)->titulo)>0)
    {
        return 1;
    }
    if(strcmp(((EMovie*)pMovieA)->titulo,((EMovie*)pMovieB)->titulo)<0)
    {
        return -1;
    }
    return 0;

}

/** \brief Crea una sublista desde la lista de peliculas.
 *
 * \param  Array representa al array creado.
 * \return void
 */
void sublista(ArrayList* Array)
{
    EMovie* Aux;
    ArrayList* subLista;
    int i;
    int from=0;
    int to=0;
    int flag_from=-1;
    int flag_to=-1;
    //***************************************************************
    char error[]= "<!>Error. No hay peliculas cargadas.\n";
    char cantidad[]= "<!>Error. No hay suficientes peliculas cargadas para crear la sublista.\n*Ingresar como minimo 3 peliculas.\n";
    char errorBusqueda[]= "<!>Error. Las peliculas no se encuentran, o no se ingresaron correctamente.\n";
    //***************************************************************
    char auxTituloF[51];
    char auxTituloT[51];
    if(al_isEmpty(Array)!=1)
    {
        if(Array->size>=3)
        {
            printf("Indique el titulo de las peliculas..\n");
            printf("Crear sublista desde: ");
            fflush(stdin);
            gets(auxTituloF);

            printf("Crear sublista hasta: ");
            fflush(stdin);
            gets(auxTituloT);

            for(i=0; i<Array->len(Array); i++)
            {
                Aux = Array->get(Array,i);
                if(strcmp(auxTituloF,Aux->titulo)==0)
                {
                    from=i;
                    flag_from=0;
                }
                if(strcmp(auxTituloT,Aux->titulo)==0)
                {
                    to=i;
                    flag_to=0;
                }
            }
            if(flag_to!=-1 && flag_from!=-1)
            {
                subLista=Array->subList(Array,from,to);
                printArrayMovie(subLista);
                fflush(stdin);
                system("pause");
            }
            else
            {
                puts(errorBusqueda);
                system("pause");
            }
        }
        else
        {
            puts(cantidad);
            system("pause");
        }
    }
    else
    {
        puts(error);
        system("pause");
    }
}

/** \brief Agrega un elemento ya eliminado en la lista de eliminados.
 *
 * \param  Array representa al array creado.
  * \param Array2 representa al array creado para contener los elementos eliminados.
 * \return void
 */
void agregarEliminado(ArrayList* Array, ArrayList* Array2)
{
    EMovie* Aux_array2=(EMovie*)malloc(sizeof(EMovie));
    EMovie* Aux_array1=(EMovie*)malloc(sizeof(EMovie));

    int i,j;
    int flag_array1=0;
    int flag_array2=0;
    char auxTitulo[51];

    //*************************************************************************
    char ElementoAgregado[]="La pelicula se volvio a agregar a la lista\n";
    char ElementoExistente[]="La pelicula ya existe en la lista.\n";
    char error[]= "<!>Error. No hay peliculas eliminadas para poder restaurar.\n";
    //*************************************************************************
    if(al_isEmpty(Array2)!=1)
    {
        printf("Ingrese el titulo de la pelicula: ");
        fflush(stdin);
        gets(auxTitulo);

        for(i=0; i<Array->len(Array); i++)
        {
            Aux_array1 = Array->get(Array,i);
            if(strcmp(auxTitulo,Aux_array1->titulo)==0)
            {
                flag_array1=Array->contains(Array,Aux_array1);
            }
        }
        for(j=0; j<Array2->len(Array2); j++)
        {
            Aux_array2 = Array->get(Array2,j);
            if(strcmp(auxTitulo,Aux_array2->titulo)==0)
            {
                flag_array2=Array2->contains(Array2,Aux_array2);
            }
            if(flag_array1==0 && flag_array2==1)
            {
                Array->push(Array,0,Aux_array2);
                Array2->remove(Array2,j);
                puts(ElementoAgregado);
                break;
            }
        }
        if(flag_array1==1 && flag_array2==1)
        {
            puts(ElementoExistente);
        }
    }
    else
    {
        puts(error);
    }
    flag_array1=0;
    flag_array2=0;
    system("pause");
}
/** \brief Crea un .HTML desde la lista de peliculas, permitiendo,si se quiere, poder ordenarlas (up) (down)
 *
 * \param  Array representa al array creado.
 * \param  file_length representa al nombre del archivo que contiene el tama๑o del array
 * \return void
 */
void crearHTML(ArrayList* Array,char* file_length)
{
    int i=0,length,opcion;
    char error[]="<!>Error. No hay peliculas cargadas.\n";
    EMovie* auxMovie;
    ArrayList* ArrayClone;

    if(al_isEmpty(Array)!=1)
    {
        FILE *f;
        f=fopen("index.html", "w");
        length=lengthLoad(file_length);
        ArrayClone = Array->clone(Array);
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            for(i=0; i<Array->len(ArrayClone); i++)
            {
                auxMovie = ArrayClone->get(ArrayClone,i);
            }
            printf("*1)Ordenar por titulo de forma acendente\n");
            printf("*0)Ordenar por titulo de forma descendente\n\n");
            printf("*Cualquier tecla para no ordenar\n");
            printf("\n    Elija una opcion: ");
            scanf("%d",&opcion);
            system("cls");
            if(opcion==0 || opcion==1)
                ArrayClone->sort(ArrayClone,compareMovie,opcion);
            if(opcion==0 || opcion==1)
                printf("*Se agregaron %d peliculas ordenadas por titulo a la web...\n\n",length);
            if(opcion!=0 && opcion!=1)
                printf("*Se agregaron %d peliculas a la web...\n\n",length);

            fprintf(f,"<!DOCTYPE html> <html lang='en'> <head> <meta charset='utf-8'> <meta http-equiv='X-UA-Compatible' content='IE=edge'> <meta name='viewport' content='width=device-width, initial-scale=1'> <title>Lista de peliculas</title> <link href='css/bootstrap.min.css' rel='stylesheet'> <link href='css/animate.css' rel='stylesheet'> <link href='css/custom.css' rel='stylesheet'> </head> <body><nav class='navbar navbar-inverse navbar-fixed-top' role='navigation'> <div class='container'> <div class='navbar-header'><button type='button'class='navbar-toggle' data-toggle='collapse' data-target='#bs-example-navbar-collapse-1'><span class='sr-only'>Toggle navigation</span><span class='icon-bar'></span> <span class='icon-bar'></span> <span class='icon-bar'></span></button><span class='navbar-brand glyphicon glyphicon-film animated in fadeIn'></span><a class='navbar-brand animated in fadeIn' href='#'>Listado de peliculas desde Arraylist</a></div><div class='collapse navbar-collapse' id='bs-example-navbar-collapse-1'> <ul class='nav navbar-nav'> <li><a class='animated in fadeIn' target='_blank' href='http://www.imdb.com/'>IMDb (Base de datos de peliculas)</a></ul></div></div></nav>  <div class='container'> <div class='row'>");

            for(i=0; i<ArrayClone->len(ArrayClone); i++)
            {
                auxMovie = ArrayClone->get(ArrayClone,i);
                ///<article>..pelicula..</article>
                fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-thumbnail img-size' src='%s' alt=''></a><h3><a class='white' href='#'>%s</a></h3><ul><li>Genero: %s</li><li>Puntaje: %d </li><li>Duracion: %d</li></ul><div class='custom'>%s</div></article>",auxMovie->link_imagen,auxMovie->titulo, auxMovie->genero, auxMovie->puntaje, auxMovie->duracion,auxMovie->descripcion);
            }
        }
        fprintf(f,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body> </html>");
        fclose(f);
        system("cls");
        printf("Pagina web creada con exito\n");
        system("pause");
    }
    else
    {
        puts(error);
        system("pause");
    }
}
