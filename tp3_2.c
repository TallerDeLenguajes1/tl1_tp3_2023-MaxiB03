#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define fil 5
#define col 12

int main(){ 

    srand(time(NULL));

    int matriz[fil][col];
    int max=0, min=50000, anio, mes, anio2, mes2;

    for (int i=0; i<fil; i++)
    {
        for (int j=0; j<col; j++)
        {
            matriz[i][j]=10000+rand()%40001;
            printf("%6d", matriz[i][j]);

            if(matriz[i][j] >= max){
                max = matriz[i][j];
                anio=i;
                mes=j;
            }
            if(matriz[i][j] <= min){
                min = matriz[i][j];
                anio2=i;
                mes2=j;
            }
        }
        printf("\n");
    }

    printf("El valor Maximo es %d, en el anio %d y mes %d \n", max, anio+1, mes+1);
    printf("El valor Minimo es %d, en el anio %d y mes %d", min, anio2+1, mes2+1);
    
    return 0;
}