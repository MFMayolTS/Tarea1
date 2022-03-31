#include <math.h>
#include <stdio.h>

// librería strings tiene herramientas para separar palabras por comas //

void find_book(FILE* csvPointer);

int main(int argc, char *argv[]) {

    // extraer información del archivo csv //
    FILE *csvPointer = fopen(argv[1], "r");
    if (csvPointer == NULL) {
        perror("Opening file");
        return -1;
    }



    int n, option;

    do
    {
        printf( "\n   1. Agregar libros");
        printf( "\n   2. Quitar libros");
        printf( "\n   3. Editar libros");  // cambiar sede, sección o piso
        printf( "\n   4. Buscar");
        printf( "\n   5. Salir." );
        printf( "\n\n   Introduzca opción (1-5): ");

        scanf( "%d", &option );

    } while ( option != 5 );

    return 0;

    fclose(csvPointer);
}

//void find_book(FILE csvPointer) {
//    char first_row[1000];
//    fgets(first_row, sizeof(first_row), csvPointer);
//    printf("%s", first_row);
//}