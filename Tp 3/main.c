#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "lib.h"


void main ()
{
    //variables
    int opcion = 0;


    while(opcion != 4)
    {
        system("cls");

        opcion = menu(1,4);

        switch(opcion)
        {
        case 1:
            altaMovie();
            break;

        case 2:
            bajaMovie();
            break;

        case 3:
            crearMovie();
            break;

        case 4:
            break;

        }
    }
}
