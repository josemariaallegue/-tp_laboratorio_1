#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Funciones.h"
#include "ABM.h"
#define CANTIDADMAX 20

void main()
{

EPersona persona [CANTIDADMAX];
int opcion = 0;
int auxiliarIndice;
char auxiliarEdad [51];
char auxiliarDNI [51];
int auxiliarIntDNI;

establecerEstado(persona,CANTIDADMAX,0);

while(opcion != 5)
{
    system("cls");

    printf("---------------------ABM---------------------");
    opcion =  recibeIntRango("\n1 - Alta \n2 - Baja \n3 - Ordenar y listar \n4 - Imprimir grafico \n5 - Salir\n\nOpcion: ", "\nNo ha ingresado una opcion valida. Reingrese", 1, 5);

    switch(opcion)
    {
        case 1:
        auxiliarIndice = buscarEspacioVacio(persona, CANTIDADMAX);
        if(auxiliarIndice == -1)
        {
            printf("\nNo hay mas espacios vacios");
            break;
        }
        while(!recibeStringLetras("\nIngrese el nombre: ", persona[auxiliarIndice].nombre))
        {
            printf("\nEl nombre debe estar compuesto solo por letras\n");
        }

        while(!recibeStringNumeros("\nIngrese la edad: ", auxiliarEdad))
        {
            printf("\nLa edad solo puede contener numeros\n");
        }
        persona[auxiliarIndice].edad = atoi(auxiliarEdad);

        while(!recibeStringNumeros("\nIngrese el DNI: ", auxiliarDNI))
        {
            printf("\nEl DNI solo puede contener numeros\n");
        }
        auxiliarIntDNI = atoi(auxiliarDNI);
        if(buscarItemPorCodigo(persona, CANTIDADMAX,auxiliarIntDNI) != -1)
        {
            printf("\nYa existe una persona con este DNI cargado\n");
            recibeChar("\nEnter para continuar");
            break;
        }
        persona[auxiliarIndice].dni = auxiliarIntDNI;
        persona[auxiliarIndice].estado = 1;
        recibeChar("\nEnter para continuar");
        break;

        case 2:
        while(!recibeStringNumeros("\nIngrese el DNI de la persona que quiere dar de baja: ", auxiliarDNI))
        {
            printf("\nEl DNI solo puede contener numeros\n");

        }
        auxiliarIntDNI = atoi(auxiliarDNI);
        auxiliarIndice = buscarItemPorCodigo(persona, CANTIDADMAX, auxiliarIntDNI);

        if(auxiliarIndice == -1)
        {
            printf("\nNo se encuentra a una persona dada de alta con ese codigo\n");
            recibeChar("\nEnter para continuar");
            break;

        }
        printf("\nLa persona con DNI %d ha sido dada de baja\n", persona[auxiliarIndice].dni);
        persona[auxiliarIndice].estado = 0;
        recibeChar("\nEnter para continuar");
        break;

        case 3:
        ordenarListar(persona, CANTIDADMAX);
        recibeChar("\n\nEnter para continuar");
        break;

        case 4:
        graficar(persona, CANTIDADMAX);
        recibeChar("\nEnter para continuar");
        break;

        case 5:
        break;

    }
}
}
