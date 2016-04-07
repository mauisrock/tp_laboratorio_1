#include <stdio.h>
#include <stdlib.h>


/** \brief Muestra el men๚ con sus respectivas opciones.
 *
 * \return No retorna ningun valor.
 *
 */

void menuOpciones()
{

        printf("\n         ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
		printf("\n         บ                       Calculadora                             บ");
		printf("\n         ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน");
		printf("\n         บ                                                               บ");
		printf("\n         บ  1)- Ingrese el 1er operando(A=x)      6)- Division(A/B)      บ");
		printf("\n         บ                                                               บ");
		printf("\n         บ  2)- Ingrese el 2do operando(B=y)      7)- Factorial(A!)      บ");
		printf("\n         บ                                                               บ");
		printf("\n         บ  3)- Suma(A+B)                         8)- Calcular todas     บ");
		printf("\n         บ                                                               บ");
		printf("\n         บ  4)- Resta(A-B)                                               บ");
		printf("\n         บ                                                               บ");
		printf("\n         บ  5)- Multiplicacion(A*B)                                      บ");
		printf("\n         บ                                                9)Salir        บ");
		printf("\n         ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
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
