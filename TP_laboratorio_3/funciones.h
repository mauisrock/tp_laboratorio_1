#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

 char titulo[256];
 char Genero[256];
 int duracion;
 char descripcion[1000];
 float puntaje;
 char Link_imagen[256];
 int isEmpty;

}EMovies;

int caseVerify(EMovies movies[]);
int validacionCadena(char cadena[]);
int validacionNumerica(int num,int limite,int limite1,int limite2);
int guardarEnArchivo(EMovies movies[]);
int cargarDesdeArchivo(EMovies movies[]);

void crearHTML(EMovies movies[]);
void inicializar(EMovies movies[]);
void addMovie(EMovies movies[],char dato1[],char dato2[],char dato3[],char dato4[],char dato5[],char dato6[],char Error1[],char Error2[],char Error3[],char Error4[],char Error5[],char Error6[]);
void modifyMovie(EMovies movies[],char datoPrincipal[],char dato1[],char dato2[],char dato3[],char dato4[],char dato5[],char error1[],char error2[]);
void deleteMovie(EMovies movies[],char dato[]);

#endif // FUNCIONES_H_INCLUDED
