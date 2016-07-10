#ifndef __MOVIES
#define __MOVIES
#include "arraylist.h"

typedef struct
{
    char titulo[51];
    char genero[51];
    int duracion;
    char descripcion[1000];
    char link_imagen[700];
    int puntaje;
    int isEmpty;

} EMovie;
#endif // __MOVIES

EMovie* addMovie(void);
EMovie* eliminadas(EMovie* Element);
EMovie* deleteMovie(ArrayList* Array);
EMovie* newMovie(char* titulo, char* genero,int duracion,char* descripcion,char* link_imagen,int puntaje);

void menu(void);
void printMovie(EMovie* p);
void sublista(ArrayList* Array);
void printArrayMovie(ArrayList* Array);
void lengthSave(int length,char* file_length);
void crearHTML(ArrayList* Array,char* file_length);
void ModifyMovie(ArrayList* Array,char* file_length);
void agregarEliminado(ArrayList* Array, ArrayList* Array2);

int testArray(void);
int lengthLoad(char* file_length);
int compareMovie(void* pMovieA,void* pMovieB);
int save(ArrayList* Array,char* file,char* file_length);
int load(ArrayList* Array,char* file,char* file_length);




