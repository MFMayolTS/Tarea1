#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "Personas.h"
#define MAXCHAR 1010
enum OPTIONS {BUSCAR = 1, ELIMINAR = 2, MOSTRAR = 3, SALIR = 4};

void mostrarPersonas(Persona *personas);
void buscarPersona(Persona *pPersonas);
void eliminarPersona(Persona *personas);
void salir(Persona *pPersonas);
void showMenu(Persona *personas);

void salir(Persona *pPersonas);

char *toLowerCase(char *name);

int main(int argc, char *argv[] ){

    //Abro el archivo
    FILE *fp = openFile(argv[1]);
    //Defino la estructura que usare para guardar los contenidos en memoria
    Persona *personas;
    //paso el contenido del file a un array de personas
    personas = getPersonas(fp);
    //cierro el archivo.
    closeFile(fp);
    //Cargo la estructura
    showMenu(personas);
    return 0;

}

void showTitles(){
    printf("Ingrese la opción \n");
    printf("1. - Buscar Persona \n");
    printf("2. - Borrar Persona \n");
    printf("3. - Mostrar Personas \n");
    printf("4. - Salir \n");
}
void showMenu(Persona *personas){
    int option = 0;
    showTitles();
    scanf("%d", &option);
    //esto hace que el menu vuelva a mostrarse hasta que me ingrese una opcion valida
    while (option <= 0 || option >= 5) {
        printf("Opcion Invalida! \n");
        showTitles();
        scanf("%d", &option);
    } ;


    //Solo salgo con una opcion valida

    switch (option) {
        case BUSCAR:
            buscarPersona(personas);
            break;
        case ELIMINAR:
            eliminarPersona(personas);
            break;
        case MOSTRAR:
            mostrarPersonas(personas);
            break;
        case SALIR:
            salir(personas);
            break;
    }

}

void salir(Persona *pPersonas) {
    printf("Gracias por usar el programa \n");
}

void buscarPersona(Persona *personas) {
    char name[50];
    printf("Ingrese el nombre o parte del nombre del titulo a buscar \n");
    scanf("%s", &name);
    //Hago una busqueda linea
    int i = 0;
    int encontre = 0;
    while (i<registryCount && encontre == 0){
        char *nameConverted = toLowerCase(personas[i].titulo);
        char *nameToLook = toLowerCase(name);
        char *ret = strstr(nameConverted, nameToLook);
        if(ret){
            encontre = 1;
        } else {
            i++;
        }
    }
    //verifico que sali por que encontre
    if (encontre == 1){
        printf("El libro Existe, estos son los datos \n");
        printf("%s,%s. \n", personas[i].titulo, personas[i].autor);
    } else {
        printf("La libro no existe!");
    }

}

char *toLowerCase(char *name) {
    char *converted =  (char*)malloc( strlen(name) * sizeof(char));
    strcpy(converted,name);
    for(int i = 0; converted[i]; i++){
        converted[i] = tolower(converted[i]);
    }
    return converted;
}

void eliminarPersona(Persona *personas) {
    char titu[100];
    printf("dame el titulo de la wea");

    scanf("%s",titu);

    for(int i = 0; i < MAXCHAR; i++){
        if(titu == personas[i].titulo){
            for (i = 0; i <  MAXCHAR - 1; i++)
            {
                personas[i] = personas[i + 1];


            }
        }
    }


}

void mostrarPersonas(Persona *personas) {

    //accedo a la cantidad de registro que lei
    for (int i = 0; i < registryCount; ++i) {
        //puedo solo imprimir su mail por ejemplo
        printf("%s,%s. \n", personas[i].titulo, personas[i].autor);
    }

}

