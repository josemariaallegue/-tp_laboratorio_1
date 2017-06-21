#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Funciones.h"
#include "ABM.h"
#define CANTIDADMAX 20

/**
 * \brief Inicializa el estado de todos los producto
 * \param persona es donde se inicializa el estado
 * \param largoCadena indica la longitud maxima
 * \param valor indica lo que vale el estado
 * \return nada al ser un void
 */

void establecerEstado(EPersona persona[], int largoCadena, int valor)
{
    int i;
    for(i=0; i < largoCadena; i++)
    {
        persona[i].estado = valor;
    }
}

/**
 * \brief busca si hay un espacio disponible para cargar un item
 * \param persona es donde se busca el espacio disponible
 * \param largoCadena indica la longitud maxima
 * \return devuelve la posicion donde hay un espacio disponible y si no lo hay devuelve -1
 */

int buscarEspacioVacio(EPersona persona[], int largoCadena)
{
    int i;

    for(i=0; i < largoCadena; i++)
    {
        if(persona[i].estado == 0)
        {
            return i;
        }
    }

    return -1;
}

/**
 * \brief busca un item de la structura
 * \param persona es donde se busca el item
 * \param largoCadena indica la longitud maxima
 * \param valor indica el item buscado
 * \return devuelve i si encuentra el item buscado (i = a la posicion del item) y -1 si no lo encuentra
 */

int buscarItemPorCodigo(EPersona persona[], int largocadena, int valor)
{
    int i;

    for(i=0; i < largocadena; i++)
    {
        if(persona[i].dni == valor && persona[i].estado == 1)
        {
            return i;
        }
    }

    return -1;
}

/**
 * \brief ordena y lista los datos de los beneficiarios
 * \param persona es de donde obtiene los datos
 * \param largoCadena indica la longitud maxima
 * \return nada al ser un void
 */

void ordenarListar(EPersona persona[], int largoCadena)
{
    int i;
    int j;
    EPersona auxiliarPersona;

    for(i=0; i < largoCadena - 1; i++)
    {
        if (persona[i].estado == 0)
        {
            continue;
        }

        for(j=i+1; j < largoCadena; j++)
        {
            if(persona[j].estado == 0)
            {
                continue;
            }

            if(strcmp(persona[i].nombre, persona[j].nombre) > 0)
            {
                auxiliarPersona = persona[j];
                persona[j] = persona[i];
                persona[i] = auxiliarPersona;
            }
        }
    }
    printf("\n|     Nombre     |     Edad     |     DNI     |");
    for(i=0; i < CANTIDADMAX; i++)
        {
            if(persona[i].estado != 0)
            {
                printf("\n| %14s | %12d | %11d |", persona[i].nombre,persona[i].edad, persona[i].dni);

            }
        }
}

/**
 * \brief Grafica a partir de 3 condiciones
 * \param persona es donde se verifican los datos para el grafico
 * \param largoCadena indica la longitud maxima
 * \return no devuelve nada al ser un void
 */

void graficar (EPersona persona[], int largoCadena)
{
    int i;
    int acumulador1 = 0;
    int acumulador2 = 0;
    int acumulador3 = 0;
    int flag = 0;
    int mayor = 0;

    for(i=0;i<largoCadena;i++)
    {
        if(persona[i].edad <= 18 && persona[i].estado == 1)
        {
            acumulador1 ++;
            continue;
        }
        if(persona[i].edad > 18 && persona[i].edad < 35 && persona[i].estado == 1)
        {
            acumulador2 ++;
            continue;
        }
        if(persona[i].edad >= 35 && persona[i].estado == 1)
        {
            acumulador3 ++;
            continue;

        }
    }


    if(acumulador1 >= acumulador2 && acumulador1 >= acumulador3)
    {
        mayor = acumulador1;
    }
    else if(acumulador2 >= acumulador1 && acumulador2 >= acumulador3)
    {
        mayor = acumulador2;
    }
    else
    {
        mayor = acumulador3;
    }
    for(i=mayor;i>0;i--)
    {

        if(i <= 10)
        {
            printf("\n%02d|", i);
        }
        else
        {
            printf("\n%02d|", i);
        }
        if(i <= acumulador1)
        {
            printf("  *");
        }
        if(i <= acumulador2)
        {
            flag =  1;
            printf("\t      *");
        }
        if(i <= acumulador3)
        {
            if(flag == 0)
            {
                printf("\t\t         *");
            }
            if(flag == 1)
            {
                printf("\t         *");
            }
        }
    }
    printf("\n--|<=18\t  >18 x < 35\t>=35\n");
}
