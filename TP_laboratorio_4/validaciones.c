#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

/** \brief Valida el rango establecido entre minimo y maximo
 * \param  Numero numero a ser analizado
 * \param  Minimo a aplicar
 * \param  Maximo a aplicar
 * \return (0) si es correcto (-1) sino no lo es
 *
 */
int validarRango(int numero,int minimo,int maximo)
{
    int returnAux=-1;

    if (numero>=minimo && numero<=maximo)
    {
        returnAux=0;
    }

    return returnAux;
}

/** \brief Verifica una cadena entre valores establecidos
 *
 * \param  str es la cadena a analizar
 * \param  minimo es el minimo aceptado
 * \param  maximo es el maximo aceptado
 * \return (0) Si cumple con lo establecido, (-1) todo lo contrario
 *
 */
int validarRangoCadena(char str[],int minimo,int maximo)
{
    int returnAux= 0;
    int i;
    int contadorC=strlen(str);

    if(contadorC<maximo && contadorC>minimo)
    {
        for(i=0; i<contadorC; i++)
        {
            if((str[i] != ' ') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') && (str[i] != '.') && (str[i] != ',') && (str[i] <'0') && (str[i] >'9'))
            {
                returnAux= -1;
                break;
            }
        }
    }
    else
        returnAux= -1;

    return returnAux;
}

/** \brief Toma una cadena y valida que sea numerica
 * \param  str es el mensaje a ser mostrado
 * \return (Aux) si es numerico, (0) si no lo es.
 */

int validarCadenaNumerica(char str[])
{
    int returnAux;
    int aux;

    if(esNumerico(str)==1)
    {
        aux=atoi(str);
        returnAux=aux;
    }
    else
        returnAux=0;

    return returnAux;
}

/** \brief Verifica si el valor recibido contiene solo letras
 *  \param  str,array con la cadena a ser analizada
 *  \return (1) Si contiene solo letras o (0) si no contiene letras.
 *
 */
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}


/** \brief Verifica si el valor recibido contiene solo letras, espacios, puntos y comas
 *  \param  str,array con la cadena a ser analizada
 *  \return (1) Si contiene solo letras o (0) si no contiene letras.
 *
 */
int esSoloLetrasPlus(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] != '.') && (str[i] != ','))
            return 0;
        i++;
    }
    return 1;
}

/** \brief  Verifica si el valor recibido contiene solo letras y numeros
 *  \param  str Array con la cadena a ser analizada
 *  \return (1) Si contiene solo letras o (0) si no contiene letras.
 *
 */
int esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

/** \brief  Verifica si el valor recibido es numerico y si contiene dos puntos (:)
 *  \param  str,array con la cadena a ser analizada
 *  \return (1) si es numerico (0) sino lo es
 *
 */
int esNumericoHora(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] <'0' || str[i]>'9') && (str[i] != ':'))
            return 0;
        i++;
    }
    return 1;
}

/** \brief  Verifica si el valor recibido es numerico
 *  \param  str,array con la cadena a ser analizada
 *  \return (1) si es numerico (0) sino lo es
 *
 */

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] <'0' || str[i]>'9')
            return 0;
        i++;
    }
    return 1;
}
