#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "funciones.h"




/** \brief muestra el menu de opciones
 * \param limiteInf es valor minimo permitido
 * \param limiteSup es el valor maximo permitido
 * \return devuelve el valor ingresado
 */

int menu(int limiteInf, int limiteSup)
{
    int opcion = 0;
    printf("------------ MENU PRINCIPAL ------------");
    opcion =  recibeIntRango("\n1 - Agregar pelicula \n2 - Borrar pelicula \n3 - Generar pagina web \n4 - Salir\n", "\nNo ha ingresado un numero valido. Reingrese\n\n",limiteInf, limiteSup);
    return opcion;
}

/**
 * \brief genera la alta de la pelicula
 * \param no recibe parametros
 * \return no devuelve nada
 */

void altaMovie()
{
    Emovie movie;
    char seguir = 's';

    while(seguir == 's' || seguir == 'S')
    {
        if(cargarMovie(&movie) == 0)
        {
            guardarMovie(&movie);
        }

        seguir = recibeChar("\n\n¿Desea ingresar otra pelicula? s/n ");
        system("cls");
        printf("------------ MENU PRINCIPAL ------------");
        printf("\n1 - Agregar pelicula \n2 - Borrar pelicula \n3 - Generar pagina web \n4 - Salir\n", "\nNo ha ingresado un numero valido. Reingrese\n\n");
    }
}


/**
 * \brief pide datos y los carga a un puntero y verica que el id no se haya ingresado con anterioridad
 * \param *movie es el puntero donde se cargan los datos pedidos
 * \return 1 si ya fue ingresado con anterioridad el Id o 0 si la carga fue exitosa
 */

int cargarMovie(Emovie *movie)
{
    FILE *ARCH;
    Emovie *punteroMovie = (Emovie*)malloc(sizeof(Emovie));
    int auxiliarId;
    int flag = 0;

    ARCH = fopen("movies.dat","r+b");
    if(ARCH == NULL)
    {
        ARCH = fopen("movies.dat","w+b");

        if(ARCH == NULL)
        {
            printf("\nError al abrir el archivo");
        }
    }


    auxiliarId = recibeInt("\nIngrese el Id: ");

    while(!feof(ARCH))
    {
        while(fread(punteroMovie,sizeof(Emovie),1,ARCH)!=0)
        {
            if(auxiliarId == punteroMovie->id && punteroMovie->estado == 1)
            {
                printf("\nEl Id ingresado ya existe");
                flag = 1;
                break;
                return 1;
            }
        }
        break;
    }

    fclose(ARCH);
    free(punteroMovie);

    if(flag == 0)
    {
        movie->id = auxiliarId;

        printf("\nIngrese el titulo: ");
        fflush(stdin);
        gets(movie->titulo);

        printf("\nIngrese el genero: ");
        fflush(stdin);
        gets(movie->genero);

        printf("\nIngrese la descripcion: ");
        fflush(stdin);
        gets(movie->descripcion);

        movie->duracion = recibeFloat("\nIngrese la duracion: ");

        movie->puntaje = recibeIntRango("\nIngrese el puntaje: ", "\nNo ha ingresado un valor permitido. Reingrese ",0,10);

        printf("\nIngrese el link a la imagen: ");
        fflush(stdin);
        gets(movie->link);

        movie->estado = 1;
        return 0;
    }

}


/**
 * \brief guarda las peliculas dadas de alta en un archivo binario
 * \param *movie es el puntero donde se cargaron los datos
 * \return no devuelve nada
 *
 */

void guardarMovie(Emovie *movie)
{
    FILE *ARCH;

    ARCH = fopen("movies.dat","a+b");
    if(ARCH == NULL)
    {
        printf("\nError al abrir el archivo");
    }

    fwrite(movie,sizeof(Emovie),1,ARCH);

    fclose(ARCH);
}


/**
 * \brief da de baja a una pelicula
 * \param no recibe paramtros
 * \return no devuelve nada
 */

void bajaMovie()
{
    FILE *ARCH;
    Emovie movie;
    Emovie *punteroMovie = (Emovie*)malloc(sizeof(Emovie));
    int auxiliarId;
    int flag = 0;
    int contador = 0;

    ARCH = fopen("movies.dat","r+b");
    if(ARCH == NULL)
    {
        printf("\nError al abrir el archivo");
    }

    auxiliarId = recibeInt("\nIngrese el Id que desea dar de baja: ");

    while(!feof(ARCH))
    {
        while(fread(punteroMovie,sizeof(Emovie),1,ARCH)!=0)
        {
            movie = *punteroMovie;

            if(auxiliarId == punteroMovie->id && punteroMovie->estado == 1)
            {
                movie.estado = 0;
                rewind(ARCH);
                fseek(ARCH,sizeof(Emovie)*contador,SEEK_SET);
                fwrite(&movie,sizeof(Emovie),1,ARCH);
                printf("\nSe ha dado de baja correctamente");
                flag = 1;
                break;
            }

            contador++;
        }
        break;
    }

    if(flag == 0)
    {
        printf("\nEl Id buscado no pudo ser encontrado");
    }

    fclose(ARCH);
    free(punteroMovie);

    recibeChar("\n\nEnter para continuar");
}


/**
 * \brief lista las peliculas que estas dadas de alta en el archivo binario
 * \param no recibe parametros
 * \return no devuelve nada
 */

void listar()
{
    FILE *ARCH;
    Emovie *punteroMovie = (Emovie*)malloc(sizeof(Emovie));

    ARCH = fopen("movies.dat","rb+");
    if(ARCH == NULL)
    {
        printf("\nError al abrir el archivo");
    }

    while(!feof(ARCH))
    {
        while(fread(punteroMovie,sizeof(Emovie),1,ARCH)!=0)
        {

            printf("\nTitulo: %s\nId: %d\nDescripcion: %s\nEstado: %d\nPuntaje: %.02f",punteroMovie->titulo,punteroMovie->id,punteroMovie->descripcion, punteroMovie->estado,punteroMovie->puntaje);
            //printf("\nTitulo: %s\nId: %d\nDescripcion: %s\nEstado: %d",movie.titulo,movie.id,movie.descripcion, movie.estado);

        }
    }
    fclose(ARCH);
    free(punteroMovie);

    recibeChar("");
}


/**
 * \brief crea un archivo html con las peliculas dadas de alta
 * \param no recibe parametros
 * \return no devuelve nada
 */

void crearMovie()
{
    FILE *ARCH;
    FILE *HTML;
    Emovie movie;
    Emovie *punteroMovie = (Emovie*)malloc(sizeof(Emovie));
    int flag = 0;

    ARCH = fopen("movies.dat","r+b");
    if(ARCH == NULL)
    {
        printf("\nError al abrir el archivo");
    }

    HTML = fopen("movies.html","w+");
    if(HTML == NULL)
    {
        printf("\nError al abrir el archivo");
    }

    //auxiliarId = recibeInt("\nIngrese el Id de la pelicula que desea crear: ");

    while(!feof(ARCH))
    {
        while(fread(punteroMovie,sizeof(Emovie),1,ARCH)!=0)
        {
            movie = *punteroMovie;

            //printf("\nTitulo: %s\nId: %d\nDescripcion: %s\nEstado: %d",punteroMovie->titulo,punteroMovie->id,punteroMovie->descripcion, punteroMovie->estado);
            //printf("\nTitulo: %s\nId: %d\nDescripcion: %s\nEstado: %d",movie.titulo,movie.id,movie.descripcion, movie.estado);

            if(punteroMovie->estado == 1)
            {
                fprintf(HTML,"<!DOCTYPE html>\n");
                fprintf(HTML,"<!-- Template by Quackit.com -->\n");
                fprintf(HTML,"<html lang='en'>\n");
                fprintf(HTML,"<head>");
                fprintf(HTML,"    <meta charset='utf-8'>\n");
                fprintf(HTML,"    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
                fprintf(HTML,"    <meta name='viewport' content='width=device-width, initial-scale=1'>\n");
                fprintf(HTML,"    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n");
                fprintf(HTML,"    <title>Lista peliculas</title>\n");
                fprintf(HTML,"    <!-- Bootstrap Core CSS -->\n");
                fprintf(HTML,"    <link href='css/bootstrap.min.css' rel='stylesheet'>\n");
                fprintf(HTML,"    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n");
                fprintf(HTML,"    <link href='css/custom.css' rel='stylesheet'>\n");
                fprintf(HTML,"    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n");
                fprintf(HTML,"    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n");
                fprintf(HTML,"    <!--[if lt IE 9]>\n");
                fprintf(HTML,"        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n");
                fprintf(HTML,"        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n");
                fprintf(HTML,"    <![endif]-->\n");
                fprintf(HTML,"</head>\n");
                fprintf(HTML,"<body>\n");
                fprintf(HTML,"    <div class='container'>\n");
                fprintf(HTML,"        <div class='row'>\n\n\n");

                fprintf(HTML,"            <article class='col-md-4 article-intro'>\n");
                fprintf(HTML,"                <a href='#'>\n");
                fprintf(HTML,"                    <img class='img-responsive img-rounded' src='");
                fprintf(HTML,"%s",movie.link);
                fprintf(HTML,"' alt=''>\n");
                fprintf(HTML,"                </a>\n");
                fprintf(HTML,"                <h3>\n");
                fprintf(HTML,"                    <a href='#'>");
                fprintf(HTML,"%s",movie.titulo);
                fprintf(HTML,"</a>\n");
                fprintf(HTML,"                </h3>\n");
                fprintf(HTML,"				<ul>\n");
                fprintf(HTML,"					<li>");
                fprintf(HTML,"Genero: %s",movie.genero);
                fprintf(HTML,"</li>\n");
                fprintf(HTML,"					<li>");
                fprintf(HTML,"Puntaje: %.02f",movie.puntaje);
                fprintf(HTML,"</li>\n");
                fprintf(HTML,"					<li>");
                fprintf(HTML,"Duracion: %.02f min",movie.duracion);
                fprintf(HTML,"</li>\n");
                fprintf(HTML,"				</ul>\n");
                fprintf(HTML,"                <p>");
                fprintf(HTML,"%s",movie.descripcion);
                fprintf(HTML,"</p>\n");
                fprintf(HTML,"            </article>\n\n\n\n\n");

                fprintf(HTML,"        </div>");
                fprintf(HTML,"        <!-- /.row -->");
                fprintf(HTML,"    </div>");
                fprintf(HTML,"    <!-- /.container -->");
                fprintf(HTML,"    <!-- jQuery -->");
                fprintf(HTML,"    <script src='js/jquery-1.11.3.min.js'></script>");
                fprintf(HTML,"    <!-- Bootstrap Core JavaScript -->");
                fprintf(HTML,"    <script src='js/bootstrap.min.js'></script>");
                fprintf(HTML,"	<!-- IE10 viewport bug workaround -->");
                fprintf(HTML,"	<script src='js/ie10-viewport-bug-workaround.js'></script>");
                fprintf(HTML,"	<!-- Placeholder Images -->");
                fprintf(HTML,"	<script src='js/holder.min.js'></script>");
                fprintf(HTML,"</body>");
                fprintf(HTML,"</html>");

                flag = 1;
            }

        }
        break;
    }

    if(flag == 0)
    {
        printf("\nNo se ha dado de alta ninguna pelicula");
    }

    fclose(ARCH);
    fclose(HTML);
    free(punteroMovie);

    printf("\nSe ha creado con exito la pagina web");
    recibeChar("\n\nEnter para continuar");
}
