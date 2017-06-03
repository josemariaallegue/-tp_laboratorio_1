typedef struct
{
    int id;
    char titulo[101];
    char genero[61];
    float duracion;
    char descripcion[1001];
    float puntaje;
    char link[1001];
    int estado;
} Emovie;

int menu(int limiteInf, int limiteSup);
void altaMovie();
int cargarMovie(Emovie *movie);
void guardarMovie(Emovie *movie);
void bajaMovie();
void crearMovie();
void listar();

