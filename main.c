#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ABB.h"



//corre 3n+1 si es impart, n/2 si es par, devuelve las iteraciones necesarias para que el valor se encuentre en la lista binaria, lo cual significa que se ha llegado a un ciclo
int GetIteraciones(int n, FILE *f){
    //Declarar variables
    int iteraciones = 0;
    ArbolBinario *Arbol;

    //Inicial arbol binario
    Arbol = InicializarArbolBinario();


    //Se repite mientras el valor no exista en el arbol binario
    while (!ExisteValorArbolBinario(Arbol, n)){

        //Añadir el valor al arbol bianrio
        AddValorArbolBinario(Arbol, n);

        //Añadir otra iteración
        iteraciones++;

        //Get nuevo valor
        if(n%2)
            n=3*n+1;
        else
            n/=2;
    }

    fprintf(f, "%5i\t", n);


    //Liberar la memoria ocupada por el arbol binario
    EliminarArbolBinario(Arbol);

    //Devolver iteraciones
    return iteraciones;
}


int main() {
    //inicializar variables
    int i, end, aux;
    FILE *f;

    //preguntar por n.º inicial y cuantos segundos se quiere correr el programa
    printf("introduzca el n inicial y el n final: \n");
    scanf("%i %i", &i, &end);

    //abrir archivo
    f = fopen("resultados.txt", "w");
    fprintf(f ,"n\tn final\titeraciones\n");

    //ciclo principal
    for( ; i<=end ; i++){
        fprintf(f, "%5i\t", i);
        aux = GetIteraciones(i, f);
        printf("\t%5i\t%5i\n", i, aux);
        fprintf(f, "%5i\n", aux);
    }


    //cerrar archivo y proceso
    fclose(f);
    return 0;
}
