#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMV 4


typedef struct{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
}eVacuna;


int mostrarVacunas(eVacuna vacunas[],int tamV);
int ordenarVacunas(eVacuna vacunas[],int tamV);
int reemplazarCaracteres(char cadena[],char car1,char car2);
float aplicarAumento (float precio);

int main()
{
    char cadena[]="aaaaa";
    eVacuna vacunas[TAMV]={{1,"Astrazeneca",'C',60},
                        {2,"Pfizer",'A',80},
                        {3,"Sputnik",'B',90},
                        {4,"Moderna",'A',70},};

    printf("Precio con aumento $%0.2f \n",aplicarAumento(10));
    printf("Cantidad: %d y la cadena quedo como %s: \n",reemplazarCaracteres(cadena,'a','e'),cadena);


    mostrarVacunas(vacunas,TAMV);
    ordenarVacunas(vacunas,TAMV);
    mostrarVacunas(vacunas,TAMV);

    return 0;
}


int mostrarVacunas(eVacuna vacunas[],int tamV){
    int todoOk = 0;
    if(vacunas && tamV > 0){
        printf("\nID\tNombre\t\t\tTipo\tEfectividad\n");
        for(int i=0;i<tamV;i++){
            printf("%d\t%-10s\t\t%c\t%0.2f\n",vacunas[i].id,vacunas[i].nombre,vacunas[i].tipo,vacunas[i].efectividad);
        }
        todoOk = 1;
    }
    return todoOk;
}

/*
3. Dada la siguiente estructura generar una función que permita ordenar un array de dicha estructura por tipo.
 Ante igualdad de tipo deberá ordenarse por efectividad creciente. Hardcodear datos y mostrarlos desde el main.

*/

int ordenarVacunas(eVacuna vacunas[],int tamV){
    int todoOk =0;
    eVacuna aux;
    if(vacunas && tamV>0){
        for(int i=0;i<tamV-1;i++){
            for(int j=i+1;j<tamV;j++){
                if ((vacunas[i].tipo > vacunas[j].tipo) || (vacunas[i].tipo == vacunas[i].tipo && vacunas[i].efectividad > vacunas[j].efectividad)){
                   aux = vacunas[i];
                   vacunas[i] = vacunas[j];
                   vacunas[j] = aux;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;

}

/*
2. Crear una función que se llame reemplazarCaracteres que reciba una cadena de caracteres como primer parámetro, un carácter
como segundo y otro carácter  como tercero,  la misma deberá reemplazar cada ocurrencia del segundo parámetro por el tercero y
devolver la cantidad de veces que se reemplazo ese carácter  en la cadena

*/

int reemplazarCaracteres(char cadena[],char car1,char car2){
    int cantidad = 0;
    if(cadena){
        for(int i=0;i<strlen(cadena);i++){
            if(cadena[i]==car1){
                cadena[i] = car2;
                cantidad++;
            }
        }
        cantidad;
    }
    return cantidad;
}

/*
1. Crear una función llamada aplicarAumento que reciba como parámetro el precio de un producto y devuelva el valor del producto
con un aumento del 5%. Realizar la llamada desde el main.

*/

float aplicarAumento (float precio){
    float precioNuevo = precio;
    if(precio > 0){
       precioNuevo = precio*1.05;
    }
    return precioNuevo;
}



