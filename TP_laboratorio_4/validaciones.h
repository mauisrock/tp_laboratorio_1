#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

int esNumerico(char str[]);
int esSoloLetras(char str[]);
int esNumericoHora(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetrasPlus(char str[]);
int validarCadenaNumerica(char str[]);
int validarRango(int numero,int minimo,int maximo);
int validarRangoCadena(char str[],int minimo,int maximo);

#endif // VALIDACIONES_H_INCLUDED
