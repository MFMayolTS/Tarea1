//
// Created by Justo Vargas on 15-03-22.
//
struct Personas {
    char  *titulo;
    char  *autor;
    int  anio;
    int  estante;
    char  *seccion;
    int  piso;
    char  *edificio;
    char *sede;
} ;

typedef struct Personas Persona;

extern int registryCount;

Persona* getPersonas(FILE *fp);

FILE * openFile(char *filename);
void closeFile(FILE *pFile);
