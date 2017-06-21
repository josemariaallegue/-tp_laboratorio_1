#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


/**
 * \brief Pide al usuario que ingrese un entero entre dos rangos
 * \param mensajeError es el mensaje que aparece si no se ingresa un valor entre
          los rangos
 * \param limiteInf es el valor minimo que se puede ingresar
 * \param limiteSup es el valor maximo que se puede ingresar
 * \return devuelve el entero ingresado
 */

int recibeInt(char mensajeError[], int limiteInf, int limiteSup)
{
    int auxiliar;
    scanf("%d", &auxiliar);
    while(auxiliar < limiteInf || auxiliar > limiteSup)
    {
        printf("%s", mensajeError);
        scanf("%d", &auxiliar);
    }
    return auxiliar;
}


/**
 * \brief Pide al usuario que ingrese un float entre dos rangos
 * \param mensajeError es el mensaje que aparece si no se ingresa un valor entre
          los rangos
 * \param limiteInf es el valor minimo que se puede ingresar
 * \return devuelve el float ingresado
 */

float recibeFloat()
{
    float auxiliar;
    scanf("%f", &auxiliar);
    return auxiliar;

}


/**
 * \brief Pide al usuario que ingrese un char entre dos rangos
 * \param mensajeError es el mensaje que aparece si no se ingresa un valor entre
          los rangos
 * \return devuelve el char ingresado
 */

char recibeChar(char mensaje[])
{
    char auxiliar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &auxiliar);
    return auxiliar;
}


/**
 * \brief realiza la suma entre dos valores
 * \param operando1 el primer elemento ingresado por el usuario
 * \param operando2 el segundo elemento ingresado por el usuario
 * \return devuelve el resultado de la suma entre los dos valores
 */

float suma(float operando1, float operando2)
{
    float auxiliar;
    auxiliar = operando1 + operando2;
    return auxiliar;
}


/**
 * \brief realiza la resta entre dos valores
 * \param operando1 el primer elemento ingresado por el usuario
 * \param operando2 el segundo elemento ingresado por el usuario
 * \return devuelve el resultado de la resta entre los dos valores
 */

float resta(float operando1, float operando2)
{
    float auxiliar;
    auxiliar = operando1 - operando2;
    return auxiliar;

}


/**
 * \brief realiza la division entre dos valores
 * \param operando1 el primer elemento ingresado por el usuario
 * \param operando2 el segundo elemento ingresado por el usuario
 * \return devuelve el resultado de la division entre los dos valores
           devuelve -1 si el segundo operando es igual a 0
 */

float division(float operando1, float operando2)
{   if(operando2 == 0)
    {
        return -1;
    }
    float auxiliar;
    auxiliar = operando1 / operando2;
    return auxiliar;
}


/**
 * \brief realiza la multiplicacion entre dos valores
 * \param operando1 el primer elemento ingresado por el usuario
 * \param operando2 el segundo elemento ingresado por el usuario
 * \return devuelve el resultado de la multiplicacion entre los dos valores
 */

float multiplicacion(float operando1, float operando2)
{
    float auxiliar;
    auxiliar = operando1 * operando2;
    return auxiliar;

}


/**
 * \brief realiza el factorial del primer operando ingresado
 * \param valor el primer elemento ingresado por el usuario
 * \return devuelve el resultado de la factorizacion si es posible realizar la operacion
           devuelve 0 si no es posible realizar la operacion
 */

float factorial(float valor)
{
    float i;
    i = valor - 1;
    if(valor >= 0)
    {
        while (i >0)
        {
            valor = valor * i;
            i --;
        }
        return valor;
    }

    else
    {
        return 0;
    }

}

