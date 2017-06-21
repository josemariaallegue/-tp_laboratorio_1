#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

void main (void)
{
    int opcion = 0;
    float operando1 = 0, operando2 = 0, resultado;

    while(opcion != 9)
    {
        system("cls");
        printf("-----------------Calculadora-----------------");

        printf("\n1 - Ingresar 1er operando (A=x) \n2 - Ingresar 2do operando (B=y) \n3 - Calcular la suma (A+B) \n4 - Calcular la resta (A-B) \n5 - Calcular la division (A/B) \n6 - Calcular la multiplicacion (A*B) \n7 - Calcular el factorial (A!) \n8 - Calcular todas las operaciones \n9 - Salir \n\n");
        printf("Opcion: ");
        opcion = recibeInt("\nDebe ingresar un numero entre 1 y 9. Reingrese: ",1,9);

        switch(opcion)
        {
        case 1:
            printf("\nIngrese el valor del primer operando: ");
            operando1 = recibeFloat();
            recibeChar("\nEnter para continuar");
            break;

        case 2:
            printf("\nIngrese el valor del segundo operando: ");
            operando2 = recibeFloat();
            recibeChar("\nEnter para continuar");
            break;

        case 3:
            resultado = suma(operando1, operando2);
            printf("\nEl resultado es: %.2f", resultado);
            recibeChar("\n\nEnter para continuar");
            break;

        case 4:
            resultado = resta(operando1, operando2);
            printf("\nEl resultado es: %.2f", resultado);
            recibeChar("\n\nEnter para continuar");
            break;

        case 5:
            resultado = division(operando1, operando2);
            if(operando2 == 0)
            {
                printf("\nNo se ha ingresado el valor del operando 2 o su valor es 0. No es posible realizar esta operacion");
            }
            else
            {
                printf("\nEl resultado es: %.2f", resultado);
            }
            recibeChar("\n\nEnter para continuar");
            break;

        case 6:
            resultado = multiplicacion(operando1, operando2);
            printf("\nEl resultado es: %.2f", resultado);
            recibeChar("\n\nEnter para continuar");
            break;

        case 7:
            resultado = factorial(operando1);
            if(resultado != 0)
            {
                printf("\nEl resultado es: %.0f", resultado);
            }
            else
            {
                printf("\nNo es posbible realizar esta operacion con el valor ingresado valor");
            }
            recibeChar("\n\nEnter para continuar");
            break;

        case 8:
            resultado = suma(operando1, operando2);
            printf("\nSuma: %.2f", resultado);
            resultado = resta(operando1, operando2);
            printf("\nResta: %.2f", resultado);
            resultado = division(operando1, operando2);
            if(operando2 == 0)
            {
                printf("\nDivision: no se ha ingresado el valor del operando 2 o su valor es 0. No es posible realizar esta operacion");
            }
            else
            {
                printf("\nDivision: %.2f", resultado);
            }
            resultado = multiplicacion(operando1, operando2);
            printf("\nMultiplicacion: %.2f", resultado);
            resultado = factorial(operando1);
            if(resultado != 0)
            {
                printf("\nFactorizacion: %.0f", resultado);
            }
            else
            {
                printf("\nFactoriazacion: no es posbible realizar esta operacion con el valor ingresado valor");
            }
            recibeChar("\n\nEnter para continuar");
            break;

        case 9:
            break;
        }
    }

}

