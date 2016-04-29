#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{

    char nombre[50];
    int edad;
    int dni;
    int estado;

}EPersona;
#endif // FUNCIONES_H_INCLUDED
void CalcularEdades(EPersona add[]);
void ordenarLista(EPersona add[]);
void vacio(EPersona add[]);
void addPerson(EPersona add[]);
void deletePerson(EPersona add[]);
void mostrarOrdenado(EPersona add[]);
void graficoEdad(int edad1,int edad2,int edad3);
int calcularMayor(int x,int y,int z);
int validacionEdad(int num,int limite, int limite2);
int validacionDNI(int num,int limite);
int esSoloLetras(char str[]);
