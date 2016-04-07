#include <stdio.h>
#include <stdlib.h>
#include "milibreria.h"

/*******************************************************************
* Programa: Calculadora
*
* Objetivo:
*
*    Ingresar 2 operandos y calcular diferentes operaciones
*    contemplando casos de error.
*
* Version: 0.1 del 0 Abril de 2016
* Autor: Mauro Barroso
*
********************************************************************/


int main()
{
    float a;
    float b;
    int opcion;
    float auxResultado;  ///variable auxiliar para llamar a la funcion dependiendo de lo que ingrese el usuario
    int flagA=0;         ///variable "FlagA" para determinar el ingreso del dato
    int flagB=0;         ///variable "FlagB" para determinar el ingreso del dato


    do
        {

		menuOpciones();
		scanf("%d",&opcion);

		switch(opcion)
        {

        case 1:
            printf("Ingrese el primer operando: ");
            scanf("%f",&a);
            if(a<=0 || a>=0)
            {
                flagA=1; ///Si se ingresa algun numero, se le asigna 1 a esta variable
            }

            break;

        case 2:
            printf("Ingrese el segundo operando: ");
            scanf("%f",&b);
            if(b<=0 || b>=0)
            {
                flagB=1; ///Si se ingresa algun numero, se le asigna 1 a esta variable
            }

            break;

        case 3:
            if(flagA==1 && flagB==1) ///Si ambos flags estan en 1, quiere decir que ambos operandos se ingresaron.
            {
                auxResultado=suma(a,b);
                printf("\n La suma de %.2f + %.2f es igual a %.2f \n",a,b,auxResultado);

            }
            else ///Si no, se informa el error y seguido de un ENTER "retorna" al menu.
            {
                printf("Error, faltan operandos.\n");
            }

            break;

        case 4:
            if(flagA==1 && flagB==1)
            {
                auxResultado=resta(a,b);
                printf("\n La resta de %.2f - %.2f es igual a %.2f \n",a,b,auxResultado);
            }

            else
            {
                printf("Error, faltan operandos.\n");
            }

            break;

        case 5:
            if(flagA==1 && flagB==1)
            {
                auxResultado=producto(a,b);
                printf("\n El producto de %.2f * %.2f es igual a %.2f \n",a,b,auxResultado);
            }
            else
            {
                printf("Error, faltan operandos.\n");
            }

            break;

        case 6:
            if(b==0)
            {
                printf("ERROR. No se puede dividir por 0.\n");
            }
            else
            {
                if(flagA==1 && flagB==1)
                {
                    auxResultado=division(a,b);
                    printf("\n La division %.2f / %.2f es igual a %.2f \n",a,b,auxResultado);
                }

                else
                {
                    printf("Error, faltan operandos.\n");
                }
            }



            break;

        case 7:
            if(flagA==1)///Se verifica que el flagA este en 1 (operando cargado).
            {
                if(a>=0)///Se verifica que no sea un numero negativo.
                    {
                    auxResultado=factorial_numero(a);
                    printf("\n El factorial del numero %.2f es: %.2f \n", a, auxResultado);
                    }
                else
                {
                    printf("\n No existe el factorial de un numero negativo. \n");
                }
            }
            else
            {
                printf("Falta el primer operando.\n");
            }

            if(flagB==1)
            {

                if(b>=0)
                    {
                        auxResultado=factorial_numero(b);
                        printf("\n El factorial del numero %.2f es: %.2f \n", b, auxResultado);
                    }

                else
                    {
                        printf("\n No existe el factorial de un numero negativo. \n");
                    }
            }

            else
               {
                   printf("Falta el segundo operando.\n");
               }

            break;

        case 8:

            if(flagA==1 && flagB==1 )///En este caso necesitamos de los dos flags(dos operandos cargados)para realizar todas las operaciones juntas.
            {
                //SUMA
                auxResultado=suma(a,b);
                printf("\n 3) La suma de %.2f + %.2f es igual a %.2f \n",a,b,auxResultado);

                //RESTA
                auxResultado=resta(a,b);
                printf("\n 4) La resta de %.2f - %.2f es igual a %.2f \n",a,b,auxResultado);

                //MULTIPLICACION
                auxResultado=producto(a,b);
                printf("\n 5) El producto de %.2f * %.2f es igual a %.2f \n",a,b,auxResultado);

                //DIVISION

                        if(b==0)
                        {
                            printf("\n 4) No se pudo calcular la division. Se ingreso 0 como divisor. \n");
                        }

                        else
                        {
                            auxResultado=division(a,b);
                            printf("\n 6) La division %.2f / %.2f es igual a %.2f \n",a,b,auxResultado);
                        }


                //FACTORIAL


                        if(a>=0)
                        {
                            auxResultado=factorial_numero(a);
                            printf("\n 7) El factorial del numero %.2f es: %.2f \n", a, auxResultado);
                        }

                        else
                        {
                            printf("\n 7) No existe el factorial de un numero negativo. \n");
                        }

                        if(b>=0)
                        {
                            auxResultado=factorial_numero(b);
                            printf("\n    El factorial del numero %.2f es: %.2f \n", b, auxResultado);
                        }

                        else
                        {
                            printf("\n    No existe el factorial de un numero negativo. \n");
                        }


                        break;
                        case 9:
                            printf("\n                             chau...\n");
                            break;
                        }

                        else
                        {
                            printf("Error, faltan operandos.\n");
                        }

        }///FIN SWITCH
            system("pause");
            system("cls");

            if(flagA==1)///Si al menos un operando estแ cargado, se muestran en pantalla luego de limpiar.
            {
            printf("\n          อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ ");
            printf("\n               Primer OP: %.2f            Segundo OP: %.2f         ",a,b);
            }
        }///FIN DO
            while (opcion!=9);



            return 0;
}
