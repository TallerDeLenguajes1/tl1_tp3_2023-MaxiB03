#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

    char *v[5];
    char buffer[100];
    int tama;

    for (int i=0; i<5; i++)
    {
        printf("Ingrese el nombre %d: ", i+1);
        gets(buffer);

        tama=strlen(buffer);
        v[i]=malloc(sizeof(char)*tama);
        strcpy(v[i], buffer);
    }

    printf("\n-----Listado de Nombres-----\n");

    for (int i=0; i<5; i++)
    {
        printf("Nombre %d: ", i+1);
        puts(v[i]);
    }
    
    for (int i=0; i<5; i++)
    {
        free(v[i]);
    }
    
    return 0;
}