#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20

typedef struct{

    char nombre[50];
    int edad;
    int dni;
    int estado;

}EPersona;

int calcularMayor(int x,int y,int z);
int validacionEdad(int num,int limite, int limite2);
int validacionDNI(int num,int limite);
int esSoloLetras(char str[]);

/** \brief Pone en -1 (vacio) todos los flags de estado de la estructura creada.
 *
 * \param flag recibe un vector de estructuras de tipo Epersona
 * \return No retorna nada.
 *
 */

void vacio(EPersona flag[])
{
    int i;
    for(i=0;i<MAX;i++)
    {
        flag[i].estado=-1;
    }
}

/** \brief Carga de forma iterativa la estructura respetando sus validaciones.
 *
 * \param  add recibe un vector de estructuras de tipo Epersona
 * \return No retorna nada.
 *
 */

void addPerson(EPersona add[])
{
    int i,aux;
    aux=0;

    for(i=0;i<MAX && aux==0;i++)
    {
        if(add[i].estado==-1)
        {
            printf("\nIngrese Nombre: ");
            fflush(stdin);
            gets(add[i].nombre);
            while(esSoloLetras(add[i].nombre)==0)
            {
                system("cls");
                printf("\nError, ingrese el Nombre : ");
                fflush(stdin);
                gets(add[i].nombre);
            }

            printf("\nIngrese Edad: ");
            scanf("%d",&add[i].edad);
            while(validacionEdad(add[i].edad,2,1)==1)
            {
                system("cls");
                printf("\nError, ingrese la Edad(1-99) :");
                scanf("%d",&add[i].edad);
                fflush(stdin);
            }

            printf("\nIngrese DNI: ");
            scanf("%d",&add[i].dni);
            while(validacionDNI(add[i].dni,8)==1)
            {
                system("cls");
                printf("\nError, ingrese el DNI(8 digitos) :");
                scanf("%d",&add[i].dni);
                fflush(stdin);
            }
            add[i].estado=0;
            aux=1;
        }
    }
}

/** \brief Validacion por cantidad de digitos del numero ingresado.
 *
 * \param  num es el numero a analizar.
 * \param  limite es la cantidad de digitos permitidos.
 * \param  limite2 es un limite adicional para las edades de una cifra.
 * \return 0 si el limite es el planteado o 1 si es erroneo.
 *
 */

int validacionEdad(int num,int limite,int limite2)
{

    int contador=1;
    while(num/10>0)
    {
        num=num/10;
        contador++;
    }
    if(contador==limite || contador==limite2)
    {
        return 0;
    }

    else
    {
        return 1;
    }
}

/** \brief Validacion por cantidad de digitos del numero ingresado.
 *
 * \param  num es el numero a analizar.
 * \param  limite es la cantidad de digitos permitida
 * \return 0 si el limite es el planteado o 1 si es erroneo.
 *
 */
int validacionDNI(int num,int limite)
{
    int contador=1;
    while(num/10>0)
    {
        num=num/10;
        contador++;
    }
    if(contador==limite)
    {
        return 0;
    }

    else
    {
        return 1;
    }
}

/** \brief Verifica si el valor ingresado contiene solo letras
 *
 * \param  str es el array con el string a ser analizado
 * \param  limite es la cantidad de digitos permitidos.
 * \return 1 si contiene solo ' ' y letras y 0 si contiene ademas de letras.
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

/** \brief Elimina personas de la lista indicando la posicion de la misma.
 *
 * \param  del recibe un vector de estructuras de tipo Epersona
 * \return No retorna nada.
 *
 */
void deletePerson(EPersona del[])
{
    int i,position;
    printf("\nIngrese la posicion(P) de la persona (1-20): ");
    scanf("%d",&position);

    for(i=0;i<=position;i++)
    {
        del[position].estado=-1;
    }
}

/** \brief Lista por pantalla la informacion ingresada ordenada por nombre.
 *
 * \param  list recibe un vector de estructuras de tipo Epersona
 * \return No retorna nada.
 *
 */
void ordenarLista(EPersona list[])
{
    int i,j;
    EPersona auxiliar;

    for(i=0; i < MAX - 1; i++)
    {
        if(list[i].estado == -1)
        {
            continue;
        }
            for(j=i+1; j < MAX; j++)
            {
                if(list[j].estado == -1)
                {
                    continue;
                }
                if(strcmp(list[i].nombre,list[j].nombre) > 0)
                {
                    auxiliar = list[j];
                    list[j] = list[i];
                    list[i] = auxiliar;
                }
            }///end for "j"
    }///end for "i"
    for(i=0;i < MAX; i++)///Muestra
    {
        if(list[i].estado == 0)
        {
            printf("\nP)%d |   %s     |   %d   |    %d     \n",i,list[i].nombre,list[i].edad,list[i].dni);
            printf("------------------------------------------\n");
        }
    }

}

/** \brief Grafica una estadistica entre 3 rangos de edades.
 *
 * \param  edad1 recibe un entero que determina el primer rango.
 * \param  edad2 recibe un entero que determina el segundo rango.
 * \param  edad3 recibe un entero que determina el tercer rango.
 * \return No retorna nada.
 *
 */
void graficoEdad(int edad1, int edad2, int edad3)
{
    int i,j;
    int mayor= calcularMayor(edad1,edad2,edad3);
    int vector[]={edad1,edad2,edad3};
    char matriz[mayor][3];
    for(j=0;j<mayor;j++)
    {
        for(i=0;i<3;i++)
        {
            if(vector[i]>j)
            {
                matriz[j][i]='*';
            }
            else
            {
                matriz[j][i]=' ';
            }
        }
    }
    for(j=mayor-1;j>=0;j--)
    {
        printf("  %c     %c     %c \n",matriz[j][0],matriz[j][1],matriz[j][2]);
    }
        printf("----------------\n");
        printf("<18   19-35  >35\n");
}

/** \brief Calcula el rango de edades para mostrarlas con graficoEdad
 *
 * \param  rank recibe un vector de estructuras de tipo Epersona
 * \return No retorna nada.
 *
 */
void CalcularEdades(EPersona rank[])
{
    int i;
    int rango1=0;
    int rango2=0;
    int rango3=0;

    for(i=0;i<=MAX && rank[i].estado==0;i++)
    {
                fflush(stdin);
                if(rank[i].edad<18)
                {
                    rango1++;
                }

                if(rank[i].edad>18 && rank[i].edad<=35)
                {
                    rango2++;
                }

                if(rank[i].edad>35)
                {
                    rango3++;
                }
    }
        graficoEdad(rango1,rango2,rango3);
}

/** \brief Recibe 3 enteros y calcula el mayor de todos
 *
 * \param  int x,y,z son los enteros a evaluar.
 * \return retorna el mayor.
 *
 */
int calcularMayor(int x,int y,int z)
{
    int mayor;
    if(x>y&&x>z)
    {
        mayor=x;
    }
    else
    {
        if(y>x&& y>=z)
        {
            mayor=y;
        }
        else
        {
            mayor=z;
        }
    }
    return mayor;
}

