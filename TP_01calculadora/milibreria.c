#include <stdio.h>
#include <stdlib.h>


/** \brief Muestra el men� con sus respectivas opciones.
 *
 * \return No retorna ningun valor.
 *
 */

void menuOpciones()
{

        printf("\n         ���������������������������������������������������������������ͻ");
		printf("\n         �                       Calculadora                             �");
		printf("\n         ���������������������������������������������������������������͹");
		printf("\n         �                                                               �");
		printf("\n         �  1)- Ingrese el 1er operando(A=x)      6)- Division(A/B)      �");
		printf("\n         �                                                               �");
		printf("\n         �  2)- Ingrese el 2do operando(B=y)      7)- Factorial(A!)      �");
		printf("\n         �                                                               �");
		printf("\n         �  3)- Suma(A+B)                         8)- Calcular todas     �");
		printf("\n         �                                                               �");
		printf("\n         �  4)- Resta(A-B)                                               �");
		printf("\n         �                                                               �");
		printf("\n         �  5)- Multiplicacion(A*B)                                      �");
		printf("\n         �                                                9)Salir        �");
		printf("\n         ���������������������������������������������������������������ͼ");
		printf("\n");
		printf("\n                              Elija una opcion: ");

}

/** \brief Suma de ambos flotantes
 *
 * \param float a, indicando el primer operando
 *
 * \param float b, indicado al segundo operando
 *
 * \return retorna a + b
 *
 */

float suma(float a, float b)
{
    return a + b;

}

/** \brief Resta de ambos flotantes
 *
 * \param float a, indicando el primer operando
 *
 * \param float b, indicado al segundo operando
 *
 * \return retorna a - b
 *
 */


float resta(float a,float b)
{
    return a - b;
}

/** \brief Producto de ambos flotantes
 *
 * \param float a, indicando el primer operando
 *
 * \param float b, indicado al segundo operando
 *
 * \return retorna a * b
 *
 */

float producto(float a, float b)
{
    return a * b;
}


/** \brief Division de ambos flotantes
 *
 *
 * \param float a, indicando el primer operando
 *
 * \param float b, indicado al segundo operando
 *
 * \return retorna a / b
 *
 */

float division(float a,float b)
{
    return a / b;
}


/** \brief Calcula el factorial del float ingresado
 *
 * \param float a, indicando el primer operando
 *
 * \param float b, indicado al segundo operando
 *
 * \param int fact, variable a ser multiplicada por "i"
 *
 * \param int i, variable incluida en el for y que itera hasta que "i" sea menor o igual a "A"
 *
 * \return fact
 *
 */

float factorial_numero(float a,float b)
{
    int fact=1;
    int i;
    for(i=1;i<=a;i++)
    {
    fact=fact*i;
    }
    return(fact);
}
