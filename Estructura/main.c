#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "libros.h"
#define MAXCHAR 1000
#define LENGHT 250

#define READ_ONLY "r"
#define WRITE_ONLY "w"

void searchBook(FILE *fp, char **);
void deleteRow(FILE *fp, FILE *fp2);  // va a agregar una columna con unos al final de cada fila para identificar que libros hemos borrado


FILE * openingFile(char *filename){
    FILE *fp;
    fp = fopen(filename,"r+");  // r+ para leer y escribir en el archivo
    return fp;
}


int main(int argc, char *argv[] ) {
    char *first_row[9] = {"Titulo", "Autor", "Año", "Estante", "Sección", "Piso", "Edificio", "Sede", "\0"};
    FILE *fp = openingFile(argv[1]);
    if (fp == NULL) {
        perror("Opening file");
        return -1;
    }

    FILE *fp2 = openingFile(argv[2]);
    if (fp2 == NULL) {
        perror("Opening file");
        return -1;
    }


    int option;
    do
    {
        printf( "   1. Agregar libros\n");
        printf( "   2. Quitar libros\n");
        printf( "   3. Editar libros\n");  // cambiar sede, sección o piso
        printf( "   4. Buscar\n");
        printf( "   5. Salir.\n" );
        printf( "   Introduzca opción (1-5): \n");

        scanf("%d", &option);
        if (option == 2) {
            deleteRow(fp, fp2);
        }
        if (option == 4) {
            searchBook(fp, first_row);
        }


    } while ( option != 5 );

    fclose(fp);
    fclose(fp2);
    return 0;

}
void deleteRow(FILE *fp, FILE *fp2) {
    char title[LENGHT];
    char *row = malloc(sizeof(char) * MAXCHAR);
    char *token;
    char *rest;
    bool gate = false;

    printf("\nIngresa el título del libro que quieres eliminar: ");
    fpurge(stdin);  // para limpiar el buffer de entrada stdin
    fgets(title, LENGHT, stdin);
    strtok(title, "\n");

    while (feof(fp) != true) {
        //obtiene la linea siguiente
        fgets(row, MAXCHAR, fp);
        token = strtok(row, ",");
        rest = strtok(NULL, "\n");

        if (strcmp(token, title) != 0) {
            fprintf(fp2, "%s,%s", token, rest);
        }
        else gate = true;
    }
    free(row);
    if (gate == false) printf("No hemos encontrado el libro que quiere eliminar :(\n");
    else printf("Hemos encontrado y eliminado correctamente el libro!!\n");
}


void searchBook(FILE *fp, char **first_row) {
    char row[MAXCHAR];
    char *token;
    char title[LENGHT];
    int j = 0;
    int i;

    printf("\nIngresa el título del libro que quieres buscar:");
    fpurge(stdin);  // para limpiar el buffer de entrada stdin
    fgets(title, LENGHT, stdin);
    strtok(title, "\n");

    bool found = false;
    while (feof(fp) != true) {

        bool found2 = false;
        //obtiene la linea siguiente
        fgets(row, MAXCHAR, fp);
        token = strtok(row, ",");

        for (i = 0; i < 7; ++i) {
            if (i == 0) {
                if (strcmp(row, title) == 0) {
                    printf("Encontramos el libro!\n");
                    found = true;
                    found2 = true;
                }
            }
            if (found2 == true) {
                while (strcmp(first_row[j], "\0") != 0) {
                    printf("%s: %s\n", first_row[j], token);
                    token = strtok(NULL, ",");
                    j++;
                }
            }
        }
    }
    if (found == false) {
        printf("Lo sentimos, su libro no se ha encontrado.\n");
    }
}




