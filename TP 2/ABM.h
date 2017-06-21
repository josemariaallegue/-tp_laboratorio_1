typedef struct{
    char nombre[51];
    int edad;
    int dni;
    int estado;
}EPersona;

void establecerEstado(EPersona persona[], int largoCadena, int valor);
int buscarEspacioVacio(EPersona persona[], int largoCadena);
int buscarItemPorCodigo(EPersona persona[], int largoCadena, int valor);
void ordenarListar (EPersona persona[], int largoCadena);
void graficar (EPersona persona[], int largoCadena);
