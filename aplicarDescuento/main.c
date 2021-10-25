#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Lorenzo Cadenazzo primer parcial Programación 1
//1. Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto y devuelva valor del
//   producto con un descuento del 5%. Realizar la llamada desde el main.
//2. Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer parámetro y un
//   carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena
//3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array de dicha estructura por marca.
//   Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main.
//---------------------------------------------------------------------------------------------------------------------------------------------


typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}Notebook;


int contarCaracteres(char cadena[], char caracter);
int aplicarDescuento(int precioProd);
void ordenarNotebooks(Notebook vec[], int tam);

int main()
{

    Notebook notebooks[]={{1, "nucleos", "HP", 80000.76}, {2, "nucleos", "HP", 54000.99}, {3, "nucleos", "Acer", 42220.87}, {4, "nucleos", "Alienware", 12322.00}};

    int producto1 = 100;
    int precioConDesc;

    precioConDesc = aplicarDescuento(producto1);
    printf("%d\n", precioConDesc);

    char cadena[] = "cadena de caracteres";
    char caracter = 'c';
    int cantidadCaracteres;

    cantidadCaracteres = contarCaracteres(cadena, caracter);
    printf("La cantidad de veces que se repite es: %d\n", cantidadCaracteres);
    ordenarNotebooks(notebooks, 4);

}

int aplicarDescuento(int precioProd){
    int precioConDesc;
    if(precioProd > 0){
        precioConDesc = precioProd - (precioProd * 5 / 100) ;
    }
    return precioConDesc;
}

int contarCaracteres(char cadena[], char caracter){
    int tam;
    int contador = 0;

    if(cadena != NULL && caracter != '\0'){
        tam = strlen(cadena);
        for (int i = 0;i < tam ;i++ ){
            if(cadena[i] == caracter ){
                contador++;
            }
        }
    }

    return contador;
    ordenarNotebooks(notebooks, 4);

    void ordenarNotebooks(Notebook vec[], int tam)
{
    Notebook aux;
    for(int i=0; i < tam-1; i++)
    {
        for(int j=i+1 ;j < tam ;j++)
        {
            if(strcmp(vec[i].marca, vec[j].marca)>0)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }

            else if(strcmp(vec[i].marca, vec[j].marca)==0)
            {
                if(vec[i].precio>vec[j].precio)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }
    }
}
}
