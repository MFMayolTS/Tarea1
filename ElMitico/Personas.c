//
// Created by Justo Vargas on 15-03-22.
//
#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include <stdlib.h>
#include "Personas.h"

#define MAXCHAR 1000
#define READ_ONLY "r"
#define WRITE "w+"


int registryCount = 0;

FILE * openFile(char *filename){
    FILE *fp;
    fp = fopen(filename,READ_ONLY);
    return fp;
}

void closeFile(FILE *fp){
    fclose(fp);
}

Persona *getPersonas(FILE *fp) {
    //genero un array dinamico de personas
    Persona *personas = (Persona*) malloc(5000*sizeof(Persona));;

    char row[MAXCHAR];
    char *token;
    int cont = 0;
    //saco la primer linea
    fgets(row, MAXCHAR, fp);
    while (!feof(fp)){
        if (!feof(fp)){
            //obtiene la linea siguiente
            fgets(row, MAXCHAR, fp);
            token = strtok(row, ",");
            //print id first
            Persona  *persona = (Persona *) malloc(sizeof(Persona));;
            //convierto el id en entero
            int anio = atoi(token);
            int estante_numero = atoi(token);
            int piso = atoi(token);

            //lo paso a la persona


            persona->titulo = (char*)malloc( strlen(token) * sizeof(char));
            strcpy( persona->titulo, token);
            token = strtok(NULL, ",");

            persona->autor = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( persona->autor, token);
            token = strtok(NULL, ",");

            persona->anio = anio;
            token = strtok(NULL, ",");

            persona->estante = estante_numero;
            token = strtok(NULL, ",");

            persona->seccion = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( persona->seccion, token);
            token = strtok(NULL, ",");

            persona->piso = piso;
            token = strtok(NULL, ",");

            persona->edificio = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( persona->edificio, token);
            token = strtok(NULL, ",");

            persona->sede = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( persona->sede, token);
            token = strtok(NULL, ",");


            personas[cont] = *persona;
            cont++;
        }
    }
    //guardo la cantidad de registros que lei
    registryCount = cont;
    return personas;
}



